#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "Menu.cpp"
#include "Source.cpp"
#include<iostream>

int main()
{
    sf::RenderWindow window (sf::VideoMode(1024,768),"ULTIMATE RACING");
    Menu menu (window.getSize().x , window.getSize().y);

        sf::Time delayTime;

    while(window.isOpen())
    {
        sf::Event event;
        window.clear();


        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Up:
                            window.clear();
                            menu.moveUp();
                            break;
                        case sf::Keyboard::Down:
					        menu.moveDown();
					        break;
                        case sf::Keyboard::Return:
                            switch(menu.GetPressedItem())
                            {
                                case 0:
                                        game();
                                        break;
					            case 1:
                                        delayTime = sf::seconds(0.1);
                                        sf::sleep(delayTime);
                                        menu.instru(window);
                                        window.display();

                                        delayTime = sf::seconds(3);
                                        sf::sleep(delayTime);
                                        menu.draw(window);
                                        window.display();


                                        window.clear();
                                       break;

                                case 2:
                                     window.clear();
                                    break;

					            case 3:
						            window.close();
						            break;
                            }
                            break;
                    }
                    break;
			    case sf::Event::Closed:
				window.close();

				break;
            }
        }

        menu.draw(window);
        window.display();
    }
    window.clear();

}
