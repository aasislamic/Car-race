#include"car.h"
#include <SFML/Graphics.hpp>
#include<iostream>

Car::Car()
{

	topview.setPointCount(4);



	//std::cout << texture.getSize().x << "   " << texture.getSize().y << std::endl;
}

void Car::Draw(sf::RenderWindow& w, int x1, int y1, int w1, int x2, int y2, int w2)
{
	topview.setPoint(0, sf::Vector2f(x1 - w1, y1));
	topview.setPoint(1, sf::Vector2f(x2 - w1, y2));
	topview.setPoint(2, sf::Vector2f(x2 + w1, y2));
	topview.setPoint(3, sf::Vector2f(x1 + w1, y1));
	texture.loadFromFile("images/sprite.png");
	topview.setTextureRect(sf::IntRect(1380, 955, 100, 60));
	topview.setTexture(&texture);

	w.draw(topview);

}
void Car::Draw(sf::RenderWindow& w, int i,int x1, int y1, int w1, int x2, int y2, int w2)
{

	topview.setPoint(0, sf::Vector2f(x1 - w1, y1));
	topview.setPoint(1, sf::Vector2f(x2 - w1, y2));
	topview.setPoint(2, sf::Vector2f(x2 + w1, y2));
	topview.setPoint(3, sf::Vector2f(x1 + w1, y1));
	texture.loadFromFile("images/RacingCars_F1.png");
	topview.setTextureRect(sf::IntRect((i%3)*188, (i/3)*225, 188, 225));
	//std::cout<<texture.getSize().x<<"   "<<texture.getSize().y<<std::endl;
	topview.setTexture(&texture);
	w.draw(topview);

}


