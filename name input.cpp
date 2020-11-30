#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;
void level1(string);
void NameInput()
{
	RenderWindow window(VideoMode(650, 450), "Enter Name");
	RectangleShape textbox;
	textbox.setSize(Vector2f(500, 80));
	textbox.setPosition(90, 200);
	textbox.setFillColor(Color::White);
	Font font;
	font.loadFromFile("Chopsic.otf");
	Text text, Playertext, entertext;
	Playertext.setPosition(100, 220);
	Playertext.setFillColor(Color::Black);
	Playertext.setFont(font);
	entertext.setPosition(130, 350);
	entertext.setFillColor(Color::White);
	entertext.setFont(font);
	entertext.setString("press Rshift to start");
	Texture background;
	background.loadFromFile("froggerblur2.png");
	Sprite bg;
	bg.setTexture(background);
	text.setString("enter your name");
	text.setFont(font);
	text.setFillColor(Color::Green);
	text.setPosition(170, 75);
	text.scale(1, 2);
	String Playerinput;
	string name;
	int countchar = 0, stop = 1;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::TextEntered) {
				if (event.text.unicode == '\b') {
					if (countchar != 0) {
						Playerinput.erase(Playerinput.getSize() - 1, 1);
						Playertext.setString(Playerinput);
						countchar--;
					}
					if (countchar <= 19) {
						stop = 1;
					}
				}

				else if (event.text.unicode < 128 && stop) {
					if (countchar == 19) {
						stop = 0;
					}
					else {
						Playerinput += event.text.unicode;
						Playertext.setString(Playerinput);
						countchar++;
					}
				}
			}
			name = Playerinput;
			if (event.key.code == Keyboard::RShift) {
				window.close();
				level1(name);
			}
		}
		window.clear();
		window.draw(bg);
		window.draw(textbox);
		window.draw(text);
		window.draw(entertext);
		window.draw(Playertext);
		window.display();
	}
	
}
