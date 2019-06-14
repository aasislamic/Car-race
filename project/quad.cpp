#include "quad.h"

Quad::Quad()
{

}

Quad::Quad(int x1, int y1, int w1, int x2, int y2, int w2)
{
	shape.setPointCount(4);
	shape.setPoint(0, sf::Vector2f(x1 - w1, y1));
	shape.setPoint(1, sf::Vector2f(x2 - w2, y2));
	shape.setPoint(2, sf::Vector2f(x2 + w2, y2));
	shape.setPoint(3, sf::Vector2f(x1 + w1, y1));

}
void Quad::Draw(sf::RenderWindow& w,sf::Color c)
{
	shape.setFillColor(c);

	w.draw(shape);
}

void Quad::Draww(sf::RenderWindow& w)
{
	sf::Texture tex;
	tex.loadFromFile("images/start.png");
	shape.setTexture(&tex);
	w.draw(shape);

}
