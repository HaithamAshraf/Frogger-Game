#include<SFML/Graphics.hpp>
#include<iostream>
#include<dos.h>
#include<Windows.h>
#include"Collision.h"
#include<string>
#include "menu.h"
void NameInput();
void Score(string name, int scoreval, int selector);
using namespace std;
using namespace sf;
void menu() {
	Texture wallpaper;
	wallpaper.loadFromFile("Frogger.png");
	Sprite wallpaperbg;
	wallpaperbg.setTexture(wallpaper);
	//wallpaperbg.setOrigin(600, 390);

	RenderWindow window(VideoMode(1200, 780), "Main Menu");
	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen()) {

		Event event;

		while (window.pollEvent(event)) {

			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed: {
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.MoveUp();
					break;
				case Keyboard::Down:
					menu.MoveDown();
					break;
				case Keyboard::Return:
					switch (menu.GetP())
					{
					case 0:
						window.close();
						NameInput();
						break;

					case 1:
						window.close();
						Score(" ", 0, 1);
						break;
					case 2:
						cout << "Settings button has been pressed" << std::endl;
						break;

					case 3:
						window.close();
						break;
					}
					break;
				}
				/*case Event::MouseButtonPressed:
					switch (event.mouseButton.button)
					{
					case Mouse::Button::Left:

						switch (menu.GetP())
						{
						case 0:
							level1();
							break;

						case 1:
							cout << "High Score button has been pressed" << std::endl;
							break;
						case 2:
							cout << "Settings button has been pressed" << std::endl;
							break;

						case 3:
							window.close();
							break;
						}
					default:
						break;
					}
				}*/
			default:
				break;
			}
			}


			window.clear();
			window.draw(wallpaperbg);
			menu.draw(window);
			window.display();
		}

	}
}