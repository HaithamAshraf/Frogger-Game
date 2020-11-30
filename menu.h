#pragma once
#include "SFML/Graphics.hpp"
#define Max_Num 4
class Menu
{
public:
	Menu(float width, float height);
	~Menu();
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetP() { return Selected; };

public:
	int Selected;
	sf::Font font;
	sf::Text menu[Max_Num];

};



