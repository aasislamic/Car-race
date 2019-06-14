#pragma once
#include<SFML/Graphics.hpp>
class Car
{
private:
	sf::ConvexShape topview;
	sf::Texture texture;
public:

	Car();

	void Draw(sf::RenderWindow & ,int x1, int y1, int w1, int x2, int y2, int w2);

	void Draw(sf::RenderWindow & w, int i, int x1, int y1, int w1, int x2, int y2, int w2);

};
