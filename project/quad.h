#pragma once
#include<SFML/Graphics.hpp>
class Quad
{
protected:
	sf::ConvexShape shape;

public:

	Quad();

	Quad(int x1, int y1, int w1, int x2, int y2, int w2);

	void Draw(sf::RenderWindow&, sf::Color);
	void Draww(sf::RenderWindow&);

};
