#include "Menu.h"

Menu::Menu(float width, float height) {
	if (!font.loadFromFile("Chopsic.otf")) {

	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Green);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 9, height / (Max_Num + 1) * 0.5));
	menu[0].scale(1.5, 2);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Score");
	menu[1].setPosition(sf::Vector2f(width / 9, height / (Max_Num + 1) * 1.5));
	menu[1].scale(1.5, 2);

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Settings");
	menu[2].setPosition(sf::Vector2f(width / 9, height / (Max_Num + 1) * 2.5));
	menu[2].scale(1.5, 2);

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(width / 9, height / (Max_Num + 1) * 3.5));
	menu[3].scale(1.5, 2);

	Selected = 0;

}

Menu::~Menu() {


}
void Menu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < Max_Num; i++) {
		window.draw(menu[i]);
	}

}

void Menu::MoveUp() {

	if (Selected > 0) {
		menu[Selected].setFillColor(sf::Color::White);
		Selected--;
		menu[Selected].setFillColor(sf::Color::Green);
	}
	else if (Selected == 0) {
		menu[Selected].setFillColor(sf::Color::White);
		Selected = 3;
		menu[Selected].setFillColor(sf::Color::Green);
	}
}
void Menu::MoveDown() {
	if (Selected < 3)
	{
		menu[Selected].setFillColor(sf::Color::White);
		Selected++;
		menu[Selected].setFillColor(sf::Color::Green);
	}
	else if (Selected == 3) {
		menu[Selected].setFillColor(sf::Color::White);
		Selected = 0;
		menu[Selected].setFillColor(sf::Color::Green);
	}
}

