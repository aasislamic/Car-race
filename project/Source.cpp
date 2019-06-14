
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include"line.h"
#include"car.h"
#include "Menu.h"
#include <iomanip>
#include"quad.cpp"
#include "line.cpp"
#include "car.cpp"
#include <sstream>
int width = 1024;
int height = 768;
int roadW = 2000;
int segL = 500; //segment length
float camD = 0.84; //camera depth
bool gameover = false;
int game()
{
	sf::Texture t[50];
	sf::Sprite object[50];
	sf::Text text;
	sf::Font font;
	sf::Text text1;
	if (!font.loadFromFile("fonts/arial.ttf")) {
		std::cout << "Failed to Load font" << std::endl;
	}
	text.setFont(font);
	text.setCharacterSize(30);
	text.setColor(sf::Color::Red);
	text.setPosition(50, 20);
	for (int i = 1; i <= 7; i++)
	{
		t[i].loadFromFile("images/"+std::to_string(i) + ".png");
		t[i].setSmooth(true);
		object[i].setTexture(t[i]);
	}
	sf::RenderWindow win(sf::VideoMode(width, height), "car race");
	win.setFramerateLimit(60);

	sf::Texture bg;
	bg.loadFromFile("images/bg.png");
	bg.setRepeated(true);
	sf::Sprite sBackground(bg);
	sBackground.setTextureRect(sf::IntRect(0, 0, 5000, 411));
	sBackground.setPosition(-2000, 0);

	std::vector<Line> lines;
	//Menu menu(300, 400);
	sf::Clock clock;
	float laptime = 0.0f;
	bool start = false;
	for (int i = 0; i<1600; i++)
	{

		//menu.run(win);
		clock.restart();

		Line line;
		line.z = i * segL;

		if (i > 30 && i < 700) {
			line.curve = 0.5;
		}
		if (i>1100) line.curve = -0.7;

		if (i<500 && i % 20 == 0) { line.spriteX = -1.8; line.sprite = object[5]; }
		if (i % 17 == 0) { line.spriteX = 2.0; line.sprite = object[6]; }
		//if (i<500 && i % 17 == 0) { line.spriteX = -2.0; line.sprite = object[6]; }
		if (i>300 && i % 20 == 0) { line.spriteX = -0.7; line.sprite = object[4]; }
		if (i % 35 == 0) { line.spriteX = 0.5; line.sprite = object[1]; }
		if (i % 230 == 0) { line.spriteX = 0.5; line.sprite = object[7]; }
		if (i % 65 == 0) { line.spriteX = -1.0; line.sprite = object[2]; }

		if (i>750) line.y = sin(i / 30.0) * 1500;

		lines.push_back(line);
	}


	int N = lines.size();
	float playerX = 0;
	int pos = 0;
	int H = 1500;
	float oldTime = 0.0f;


	text1.setFont(font);
	text1.setCharacterSize(30);
	text1.setColor(sf::Color::Black);
	text1.setPosition(500, 30);

	std::stringstream ss1;
	ss1 << "Laptime: " << std::endl;

	/*sf::Music music;
	music.openFromFile("tune.ogg");
	music.play();*/

	while (win.isOpen())
	{
		if (gameover)
		{
			//music.stop();
			win.close();
		}
		sf::Event e;
		while (win.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				win.close();
		}

		int speed = 0;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) playerX += 0.1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) playerX -= 0.1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { speed = segL * 5; start = true; };
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) speed = -segL;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) speed *= 3;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) H += 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) H -= 100;
		pos += speed;
		while (pos >= N * segL) pos %= N;
		while (pos < 0) pos += N * segL;
		win.clear();
		win.draw(sBackground);
		int startPos = pos / segL;
		int camH = lines[startPos].y + H;
		if (speed>0) sBackground.move(-lines[startPos].curve * 2, 0);
		if (speed<0) sBackground.move(lines[startPos].curve * 2, 0);

		int maxy = height;
		float x = 0, dx = 0;

		///////draw road////////
		Car c; int i = 0;

		for (int n = startPos; n<startPos + 300; n++)
		{
			if (playerX < -0.9 || playerX >= 1.0)
			{
				std::cout << " gameover" << std::endl;
				//text.setString(ss1.str());
				//win.draw(text);
				gameover = true;


			}
			Line &l = lines[n%N];
			l.Project(playerX*roadW - x, camH, pos - (n >= N ? N * segL : 0));
			x += dx;
			dx += l.curve;
			l.clip = maxy;

			if (l.Y >= maxy) continue;

			maxy = l.Y;

			sf::Color grass_color = (n / 3) % 2 ? sf::Color(16, 200, 16) : sf::Color(0, 154, 0);
			sf::Color rumble_color = (n / 3) % 2 ? sf::Color(255, 255, 255) : sf::Color(0, 0, 0);
			sf::Color road_color = (n / 3) % 2 ? sf::Color(107, 107, 107) : sf::Color(105, 105, 105);

			Line p = lines[(n - 1) % N]; //previous line
			Quad grass(0, p.Y, width, 0, l.Y, width);
			Quad rumble(p.X, p.Y, p.W*1.2, l.X, l.Y, l.W*1.2);
			Quad road(p.X, p.Y, p.W, l.X, l.Y, l.W);

			grass.Draw(win, grass_color);
			rumble.Draw(win, rumble_color);
			road.Draw(win, road_color);
			if (n == 18)
			{
				road.Draww(win);
			}
			if (n % 80 == 0)
			{
				c.Draw(win, i, p.X, p.Y, l.W*0.2, l.X, l.Y, l.W*0.2);
				i++;
				if (i > 5) i = 0;
			}

		}
		Car car;
		car.Draw(win, 512, 700, 80, 512, 590, 50);
		////////draw objects////////
		for (int n = startPos + 300; n>startPos; n--)
			lines[n%N].drawSprite(win);

		if (start)
			laptime += clock.getElapsedTime().asSeconds() - oldTime;
		oldTime = clock.getElapsedTime().asSeconds();
		std::stringstream ss;
		ss << "Laptime: " << std::setprecision(2) << laptime << std::endl;
		text.setString(ss.str());
		win.draw(text);
		win.display();


	}
	if (gameover)
	{

		sf::RenderWindow abc(sf::VideoMode(500, 500), "game over");
		sf::Font font2;
		sf::Text text2;
		if (!font2.loadFromFile("fonts/arial.ttf")) {
			std::cout << "Failed to Load font" << std::endl;
		}
		text2.setFont(font2);
		text2.setCharacterSize(30);
		text2.setColor(sf::Color::White);
		text2.setPosition(500, 10);

		std::stringstream ss2;
		ss2 << "Oops !! car crashed " << std::endl;
		while (abc.isOpen())
		{
			sf::Event e1;
			while (abc.pollEvent(e1))
			{
				if (e1.type == sf::Event::Closed)
					abc.close();
			}
			abc.draw(text2);
			abc.display();
		}

	}

	return 0;
}


