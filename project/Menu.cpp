#include "Menu.h"


Menu::Menu(float width, float height)
{

    if (!font.loadFromFile("fonts/arial.ttf"))
	{
		// handle error
	}

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setPosition(sf::Vector2f(width/2 + 200, height / (Max_Num +1)*0.8));
    menu[0].setString("PLAY");

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setPosition(sf::Vector2f(width/2 + 200,height / (Max_Num +1)*1.6));
    menu[1].setString("INSTRUCTIONS");

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setPosition(sf::Vector2f(width/2 + 200, height / (Max_Num +1)*2.4));
    menu[2].setString("HIGH SCORE");

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setPosition(sf::Vector2f(width/2+ 200, height / (Max_Num +1)*3.2));
    menu[3].setString("EXIT");

    selectedIndex=0;
}
Menu::~Menu()
{}

void Menu::draw(sf::RenderWindow &window)
{
    sf::Texture textu;
if (!textu.loadFromFile("images/bgg.png"))
{

}
sf::Sprite background(textu);

window.draw(background);
//window.draw(recangle);
//window.display();
	//window.draw(sbgr)
    for(int i=0;i<4;i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::moveUp()
{
    if (selectedIndex - 1 >=0)
    {
        menu[selectedIndex].setColor(sf::Color::White);
        selectedIndex--;
        menu[selectedIndex].setColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if (selectedIndex + 1 < Max_Num)
    {
        menu[selectedIndex].setColor(sf::Color::White);
        selectedIndex++;
        menu[selectedIndex].setColor(sf::Color::Red);
    }
}
void Menu::instru(sf::RenderWindow &window)
{
       sf::Texture tex;
if (!tex.loadFromFile("images/bggg.jpg"))
{

}
sf::Sprite backgr(tex);

        if(!fnt.loadFromFile("fonts/ks.otf"))
    {

    }
    menu[4].setFont(fnt);
    menu[4].setColor(sf::Color::Blue);
    menu[4].setPosition(sf::Vector2f( 40, 50));
    menu[4].setString("This is the instructions to the game!!! \n A simple racing game in which the player rides the car on the given \n track escaping the obstacles. \n \n \n \n \n \n PREPARED BY: \n \t Aakapla Aryal \n \t Aashish Lamichhane \n \t Abhishek Thapa ");

    menu[5].setFont(fnt);
    menu[5].setColor(sf::Color::Green);
    menu[5].setPosition(sf::Vector2f( 40, 600));
    menu[5].setString("BACK");


window.draw(backgr);
    window.draw(menu[4]);
    window.draw(menu[5]);

}
