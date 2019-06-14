#pragma once
#include "SFML/Graphics.hpp"
#define Max_Num 7

class Menu
{
    private:
        int selectedIndex;
        sf::Font font;
        sf::Font fnt;
        sf::Text menu[Max_Num];
        //sf::Text inst[Max_Num];
    public:
        Menu(float width, float height);
        ~Menu();

        void draw(sf::RenderWindow & window);
        void instru(sf::RenderWindow & window);
        void moveUp();
        void moveDown();

        int GetPressedItem() {return selectedIndex;}

};
