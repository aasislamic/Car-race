#include"line.h"
#include<SFML/Graphics.hpp>
Line::Line()
{
	spriteX = curve = x = y = z = 0;
}

void Line::Project(int camX, int camY, int camZ)
{
	scale = 0.84f / (z - camZ);  //camD
	X = (1 + scale * (x - camX)) * 1024 / 2;   //width
	Y = (1 - scale * (y - camY)) * 768/ 2;  //height
	W = scale * 2000 * 1024 / 2;   // roadW   width
}

void Line::drawSprite(sf::RenderWindow &app)
{
	sf::Sprite s = sprite;
	int w = s.getTextureRect().width;
	int h = s.getTextureRect().height;

	float destX = X + scale * spriteX * 1024 / 2;  //width
	float destY = Y +4;
	float destW = w * W / 266;
	float destH = h * W / 266;

	destX += destW * spriteX; //offsetX
	destY += destH * (-1);    //offsetY

	float clipH = destY + destH - clip;
	if (clipH<0) clipH = 0;

	if (clipH >= destH) return;
	s.setTextureRect(sf::IntRect(0, 0, w, h - h * clipH / destH));
	s.setScale(destW / w, destH / h);
	s.setPosition(destX, destY);
	app.draw(s);
}
