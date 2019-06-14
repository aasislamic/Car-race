#pragma once
#include<SFML/Graphics.hpp>
class Line
{
private:


public:

	float X, Y, W; //screen coord

	sf::Sprite sprite;

	sf::RectangleShape rect;

	float curve, spriteX, clip, scale;

	float x, y, z; //3d center of line

	Line();


	void Project(int camX, int camY, int camZ);


	void drawSprite(sf::RenderWindow &app);

};
