#include<SFML/Graphics.hpp>
#include<iostream>
#include<dos.h>
#include<Windows.h>
#include"Collision.h"
#include<string>
void Score(string name, int scoreval, int selector);
void menu();
using namespace std;
using namespace sf;
void level3(int lvl2score, int lvl12losecount,string name) {
	string Name = name;
	RenderWindow window(VideoMode(1200, 780), "FROGGER!", Style::Close);
	Texture frog, water, stone, road, start, finish, finish2, car1, car2, car3, car4, car5, car6, car7, car8, car9, car10, turtle, root, scorebarbg, heartshape,insect;
	water.loadFromFile("water.jpg");
	Collision::CreateTextureAndBitmask(frog, "frog.png");
	stone.loadFromFile("stone.jfif");
	road.loadFromFile("road.jpg");
	start.loadFromFile("start.png");
	scorebarbg.loadFromFile("scorebarbg.jpg");
	heartshape.loadFromFile("heart.png");
	Collision::CreateTextureAndBitmask(finish, "finish.jpg");
	Collision::CreateTextureAndBitmask(finish2, "finish2.jpg");
	Collision::CreateTextureAndBitmask(car1, "car1.jpg");
	Collision::CreateTextureAndBitmask(car2, "car2.jpg");
	Collision::CreateTextureAndBitmask(car3, "car3.jpg");
	Collision::CreateTextureAndBitmask(car4, "car4.jpg");
	Collision::CreateTextureAndBitmask(car5, "car5.png");
	Collision::CreateTextureAndBitmask(car6, "car6.jpg");
	Collision::CreateTextureAndBitmask(car7, "car7.jpg");
	Collision::CreateTextureAndBitmask(car8, "car8.jpg");
	Collision::CreateTextureAndBitmask(car9, "car9.jpg");
	Collision::CreateTextureAndBitmask(car10, "car10.jpg");
	Collision::CreateTextureAndBitmask(turtle, "turtle.png");
	Collision::CreateTextureAndBitmask(root, "root.png");
	Collision::CreateTextureAndBitmask(insect, "insect1.png");
	Sprite frogbg, waterbg, stonebg, roadbg, startbg, finishbg, finish2bg, car1bg, car2bg, car3bg, car4bg, car5bg, car6bg, car7bg, car8bg, car9bg, car10bg;
	Sprite turtle1bg, turtle2bg, turtle3bg, turtle4bg, turtle5bg, turtle6bg, root1bg, root2bg, root3bg, root4bg, root5bg, root6bg, root7bg, root8bg, root9bg, root10bg, root11bg, root12bg, root13bg;
	Sprite scorebar_bg, heart, heart2, heart3,insectbg;
	frogbg.setTexture(frog);
	waterbg.setTexture(water);
	stonebg.setTexture(stone);
	roadbg.setTexture(road);
	startbg.setTexture(start);
	finishbg.setTexture(finish);
	finish2bg.setTexture(finish2);
	car1bg.setTexture(car1);
	car2bg.setTexture(car2);
	car3bg.setTexture(car3);
	car4bg.setTexture(car4);
	car5bg.setTexture(car5);
	car6bg.setTexture(car6);
	car7bg.setTexture(car7);
	car8bg.setTexture(car8);
	car9bg.setTexture(car9);
	car10bg.setTexture(car10);
	turtle1bg.setTexture(turtle);
	turtle2bg.setTexture(turtle);
	turtle3bg.setTexture(turtle);
	turtle4bg.setTexture(turtle);
	turtle5bg.setTexture(turtle);
	turtle6bg.setTexture(turtle);
	root1bg.setTexture(root);
	root2bg.setTexture(root);
	root3bg.setTexture(root);
	root4bg.setTexture(root);
	root5bg.setTexture(root);
	root6bg.setTexture(root);
	root7bg.setTexture(root);
	root8bg.setTexture(root);
	root9bg.setTexture(root);
	root10bg.setTexture(root);
	root11bg.setTexture(root);
	root12bg.setTexture(root);
	root13bg.setTexture(root);
	heart.setTexture(heartshape);
	heart2.setTexture(heartshape);
	heart3.setTexture(heartshape);
	scorebar_bg.setTexture(scorebarbg);
	insectbg.setTexture(insect);
	Font scorefont;
	scorefont.loadFromFile("Chopsic.otf");
	Text scoretext, leveltext, scorenumber, gameovertext, firstround, pressenter,pressenter_GAMEOVER;
	scoretext.setFont(scorefont);
	scoretext.setString("Score :");
	leveltext.setFont(scorefont);
	leveltext.setString("ROUND 3 ");
	gameovertext.setFont(scorefont);
	gameovertext.setString(" GAME OVER!! ");
	gameovertext.scale(3.5, 4);
	gameovertext.setPosition(190, 200);
	firstround.setFont(scorefont);
	firstround.setString(" WINNER!!");
	firstround.scale(4, 4);
	firstround.setPosition(260, 200);
	pressenter.setFont(scorefont);
	pressenter.setString("PRESS  ENTER  TO  RETURN  TO  MAIN  MENU");
	pressenter.scale(0.5, 1);
	pressenter.setPosition(420, 350);
	pressenter_GAMEOVER.setFont(scorefont);
	pressenter_GAMEOVER.setString("PRESS  ENTER  TO  RETURN  TO  MAIN  MENU");
	pressenter_GAMEOVER.scale(0.5, 1);
	pressenter_GAMEOVER.setPosition(420, 350);
	int background[20][13];
	int countcar = 1200, countcar2 = 600, countcar3 = 0, countcar4 = 360, countcar5 = 780, countcar6 = 240, countcar7 = 660, countcar8 = 1080, countcar9 = 300, countcar10 = 900;
	int turtlecount = 1200, turtlecount2 = 600, turtlecount3 = 1140, turtlecount4 = 1080, turtlecount5 = 660, turtlecount6 = 720, rootcount = 0, rootcount2 = 600, rootcount3 = 600;
	int rootcount4 = 60, rootcount5 = 120, rootcount6 = 660, rootcount7 = 720, rootcount8 = 660, rootcount9 = 720, rootcount10 = 780, rootcount11 = 840, rootcount12 = 900, rootcount13 = 960;
	int i = 0, losecount = lvl12losecount, score = lvl2score, pixelcountUP = 0, pixelcountDOWN = 0, winner = 0;;
	string score_number = to_string(score);
	scorenumber.setFont(scorefont);
	scorenumber.setString(score_number);
	scorenumber.setFillColor(Color::Green);
	frogbg.setOrigin(30, 30);
	turtle1bg.setOrigin(30, 30);
	turtle2bg.setOrigin(30, 30);
	turtle3bg.setOrigin(30, 30);
	turtle4bg.setOrigin(30, 30);
	turtle5bg.setOrigin(30, 30);
	turtle6bg.setOrigin(30, 30);
	insectbg.setOrigin(30, 30);
	frogbg.setPosition((9 * 60) + 30, (9 * 60) + 30);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case::Event::Closed:
				window.close();
				break;
				//TO CHANGE THE FROG'S ANGLE, TO SUIT THE DIRECTION IT'S MOVING TO
			case::Event::EventType::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
					if (losecount != 3)
						frogbg.setRotation(0);
					else if (!winner)
						frogbg.setRotation(0);
				}
				else if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
					if (losecount != 3)
						frogbg.setRotation(180);
					else if (!winner)
						frogbg.setRotation(180);
				}
				else  if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
					if (losecount != 3)
						frogbg.setRotation(-90);
					else if (!winner)
						frogbg.setRotation(-90);
				}
				else if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
					if (losecount != 3)
						frogbg.setRotation(90);
					else if (!winner)
						frogbg.setRotation(90);
				}
				break;

			}

		}


		//SIZE OF TEXTURE
		window.clear();
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 1; j++)
				background[i][j] = 0;
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 1; j < 4; j++)
				background[i][j] = 1;
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 4; j < 5; j++)
				background[i][j] = 2;
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 5; j < 9; j++) {
				background[i][j] = 3;
			}
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 9; j < 10; j++)
				background[i][j] = 4;
		}
		//SIZE OF SCORE BAR
		for (int i = 0; i < 20; i++) {
			for (int j = 10; j < 13; j++)
				background[i][j] = 5;
		}

		//DRAW AND SET POSITION OF TEXTURE
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 13; j++) {

				if (background[i][j] == 0 && i % 2 != 0) {
					finishbg.setPosition(i * 60, j * 60);
					window.draw(finishbg);
				}
				if (background[i][j] == 0 && i % 2 == 0) {
					finish2bg.setPosition(i * 60, j * 60);
					window.draw(finish2bg);
				}
				if (background[i][j] == 1) {
					waterbg.setPosition(i * 60, j * 60);
					window.draw(waterbg);
				}
				if (background[i][j] == 2) {
					stonebg.setPosition(i * 60, j * 60);
					window.draw(stonebg);
				}
				if (background[i][j] == 3) {
					roadbg.setPosition(i * 60, j * 60);
					window.draw(roadbg);
				}
				if (background[i][j] == 4) {
					startbg.setPosition(i * 60, j * 60);
					window.draw(startbg);
				}
				if (background[i][j] == 5) {
					scorebar_bg.setPosition(i * 60, j * 60);
					window.draw(scorebar_bg);
				}
			}
		}
		//SCORE BAR TEXT
		scoretext.setPosition(100, 660);
		window.draw(scoretext);
		leveltext.setPosition(500, 600);
		window.draw(leveltext);
		scorenumber.setPosition(250, 660);
		window.draw(scorenumber);
		//HEART SHAPE
		heart.setPosition(1000, 660);
		window.draw(heart);
		heart2.setPosition(940, 660);
		window.draw(heart2);
		heart3.setPosition(880, 660);
		window.draw(heart3);
		//MOVING CARS
		if (countcar >= 0) {
			car1bg.setPosition(countcar, 300);
			window.draw(car1bg);
			countcar -= 2;
		}
		if (countcar < 0) {
			countcar = 1200;
		}
		if (countcar2 >= 0) {
			car2bg.setPosition(countcar2, 300);
			window.draw(car2bg);
			countcar2 -= 2;
		}
		if (countcar2 < 0) {
			countcar2 = 1200;
		}
		if (countcar3 >= 0) {
			car3bg.setPosition(countcar3, 360);
			window.draw(car3bg);
			countcar3 += 2;
		}
		if (countcar3 > 1200) {
			countcar3 = 0;
		}
		if (countcar4 >= 0) {
			car4bg.setPosition(countcar4, 360);
			window.draw(car4bg);
			countcar4 += 2;
		}
		if (countcar4 > 1200) {
			countcar4 = 0;
		}
		if (countcar5 >= 0) {
			car5bg.setPosition(countcar5, 360);
			window.draw(car5bg);
			countcar5 += 2;
		}
		if (countcar5 > 1200) {
			countcar5 = 0;
		}
		if (countcar6 >= 0) {
			car6bg.setPosition(countcar6, 420);
			window.draw(car6bg);
			countcar6 -= 2;
		}
		if (countcar6 < 0) {
			countcar6 = 1200;
		}
		if (countcar7 >= 0) {
			car7bg.setPosition(countcar7, 420);
			window.draw(car7bg);
			countcar7 -= 2;
		}
		if (countcar7 < 0) {
			countcar7 = 1200;
		}
		if (countcar8 >= 0) {
			car8bg.setPosition(countcar8, 420);
			window.draw(car8bg);
			countcar8 -= 2;
		}
		if (countcar8 < 0) {
			countcar8 = 1200;
		}
		if (countcar9 >= 0) {
			car9bg.setPosition(countcar9, 480);
			window.draw(car9bg);
			countcar9 += 2;
		}
		if (countcar9 > 1200) {
			countcar9 = 0;
		}
		if (countcar10 >= 0) {
			car10bg.setPosition(countcar10, 480);
			window.draw(car10bg);
			countcar10 += 2;
		}
		if (countcar10 > 1200) {
			countcar10 = 0;
		}
		//MOVING TURTLES
		//FIRST THREE TURTLES
		if (turtlecount >= 0) {
			turtle1bg.setPosition(turtlecount, 210);
			window.draw(turtle1bg);
			turtlecount -= 2;
		}
		if (turtlecount < 0) {
			turtlecount = 1200;
		}
		if (turtlecount3 >= 0) {
			turtle2bg.setPosition(turtlecount3, 210);
			window.draw(turtle2bg);
			turtlecount3 -= 2;
		}
		if (turtlecount3 < 0) {
			turtlecount3 = 1200;
		}
		if (turtlecount4 >= 0) {
			turtle3bg.setPosition(turtlecount4, 210);
			window.draw(turtle3bg);
			turtlecount4 -= 2;
		}
		if (turtlecount4 < 0) {
			turtlecount4 = 1200;
		}
		//SECONDE THREE TURTLES
		if (turtlecount2 >= 0) {
			turtle4bg.setPosition(turtlecount2, 210);
			window.draw(turtle4bg);
			turtlecount2 -= 2;
		}
		if (turtlecount2 < 0) {
			turtlecount2 = 1200;
		}
		if (turtlecount5 >= 0) {
			turtle5bg.setPosition(turtlecount5, 210);
			window.draw(turtle5bg);
			turtlecount5 -= 2;
		}
		if (turtlecount5 < 0) {
			turtlecount5 = 1200;
		}
		if (turtlecount6 >= 0) {
			turtle6bg.setPosition(turtlecount6, 210);
			window.draw(turtle6bg);
			turtlecount6 -= 2;
		}
		if (turtlecount6 < 0) {
			turtlecount6 = 1200;
		}
		//MOVING ROOTS RIGHT
		if (rootcount >= 0) {
			root1bg.setPosition(rootcount, 120);
			window.draw(root1bg);
			rootcount += 2;
		}
		if (rootcount > 1200) {
			rootcount = 0;
		}
		if (rootcount4 >= 0) {
			root2bg.setPosition(rootcount4, 120);
			window.draw(root2bg);
			rootcount4 += 2;
		}
		if (rootcount4 > 1200) {
			rootcount4 = 0;
		}
		if (rootcount5 >= 0) {
			root3bg.setPosition(rootcount5, 120);
			window.draw(root3bg);
			rootcount5 += 2;
		}
		if (rootcount5 > 1200) {
			rootcount5 = 0;
		}
		//SECONDE ROOT
		if (rootcount2 >= 0) {
			root4bg.setPosition(rootcount2, 120);
			window.draw(root4bg);
			rootcount2 += 2;
		}
		if (rootcount2 > 1200) {
			rootcount2 = 0;
		}
		if (rootcount6 >= 0) {
			root5bg.setPosition(rootcount6, 120);
			window.draw(root5bg);
			rootcount6 += 2;
		}
		if (rootcount6 > 1200) {
			rootcount6 = 0;
		}
		if (rootcount7 >= 0) {
			root6bg.setPosition(rootcount7, 120);
			window.draw(root6bg);
			rootcount7 += 2;
		}
		if (rootcount7 > 1200) {
			rootcount7 = 0;
		}
		//MOVING ROOTS LEFT
		//FIRST ROOT || LONG ROOT 
		if (rootcount3 >= 0) {
			root7bg.setPosition(rootcount3, 60);
			window.draw(root7bg);
			rootcount3 -= 2;
		}
		if (rootcount3 < 0) {
			rootcount3 = 1200;
		}
		if (rootcount8 >= 0) {
			root8bg.setPosition(rootcount8, 60);
			window.draw(root8bg);
			rootcount8 -= 2;
		}
		if (rootcount8 < 0) {
			rootcount8 = 1200;
		}
		if (rootcount9 >= 0) {
			root9bg.setPosition(rootcount9, 60);
			window.draw(root9bg);
			rootcount9 -= 2;
		}
		if (rootcount9 < 0) {
			rootcount9 = 1200;
		}
		if (rootcount10 >= 0) {
			root10bg.setPosition(rootcount10, 60);
			window.draw(root10bg);
			rootcount10 -= 2;
		}
		if (rootcount10 < 0) {
			rootcount10 = 1200;
		}
		if (rootcount11 >= 0) {
			root11bg.setPosition(rootcount11, 60);
			window.draw(root11bg);
			rootcount11 -= 2;
		}
		if (rootcount11 < 0) {
			rootcount11 = 1200;
		}
		if (rootcount12 >= 0) {
			root12bg.setPosition(rootcount12, 60);
			window.draw(root12bg);
			rootcount12 -= 2;
		}
		if (rootcount12 < 0) {
			rootcount12 = 1200;
		}
		if (rootcount13 >= 0) {
			root13bg.setPosition(rootcount13, 60);
			window.draw(root13bg);
			rootcount13 -= 2;
		}
		if (rootcount13 < 0) {
			rootcount13 = 1200;
		}
		//TO MOVE THE FROG
		int y;
		if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
			if (losecount == 3)
				frogbg.setPosition(570, 570);
			else
				frogbg.move(-1.5f, 0);
			window.draw(frogbg);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
			if (losecount == 3)
				frogbg.setPosition(570, 570);
			else
				frogbg.move(1.5f, 0);
			window.draw(frogbg);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
			if (losecount == 3)
				frogbg.setPosition(570, 570);
			else if (winner) {
				score = score;
				score_number = to_string(score);
				scorenumber.setString(score_number);
			}
			else {
				pixelcountUP++;
				frogbg.move(0, -1.5f);
				window.draw(frogbg);
				y = frogbg.getPosition().y;
				if (pixelcountUP == 2) {
					if (y >= 540 && y <= 600) {
						score = score;
						score_number = to_string(score);
						scorenumber.setString(score_number);
					}
					else {
						score++;
						score_number = to_string(score);
						scorenumber.setString(score_number);
					}
					pixelcountUP = 0;
				}
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
			if (losecount == 3)
				frogbg.setPosition(570, 570);
			else if (winner) {
				score = score;
				score_number = to_string(score);
				scorenumber.setString(score_number);
			}
			else {
				pixelcountDOWN++;
				frogbg.move(0, 1.5f);
				window.draw(frogbg);
				y = frogbg.getPosition().y;
				if (pixelcountDOWN == 2) {
					if (y >= 540 && y <= 600) {
						score = score;
						score_number = to_string(score);
						scorenumber.setString(score_number);
					}
					else {
						score--;
						score_number = to_string(score);
						scorenumber.setString(score_number);
					}
					pixelcountDOWN = 0;
				}
			}
		}
		//DRAWING INSECT
			insectbg.setPosition(90, 30);
			window.draw(insectbg);
			insectbg.setPosition(210, 30);
			window.draw(insectbg);
			insectbg.setPosition(450, 30);
			window.draw(insectbg);
			insectbg.setPosition(570, 30);
			window.draw(insectbg);
			insectbg.setPosition(810, 30);
			window.draw(insectbg);
			insectbg.setPosition(1050, 30);
			window.draw(insectbg);
			insectbg.setPosition(1170, 30);
			window.draw(insectbg);
		//ATTACH THE FROG TO THE TURTLE

		if (Collision::PixelPerfectTest(frogbg, turtle1bg)) {
			frogbg.move(-2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, turtle2bg)) {
			frogbg.move(-2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, turtle3bg)) {
			frogbg.move(-2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, turtle4bg)) {
			frogbg.move(-2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, turtle5bg)) {
			frogbg.move(-2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, turtle6bg)) {
			frogbg.move(-2, 0);
		}
		//ATTACH FROG TO THE TREE LOGS
		else if (Collision::PixelPerfectTest(frogbg, root1bg)) {
			frogbg.move(2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root2bg)) {
			frogbg.move(2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root3bg)) {
			frogbg.move(2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root4bg)) {
			frogbg.move(2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root5bg)) {
			frogbg.move(2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root6bg)) {
			frogbg.move(2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root7bg)) {
			frogbg.move(-2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root8bg)) {
			frogbg.move(-2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root9bg)) {
			frogbg.move(-2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root10bg)) {
			frogbg.move(-2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root11bg)) {
			frogbg.move(-2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root12bg)) {
			frogbg.move(-2, 0);
		}
		else if (Collision::PixelPerfectTest(frogbg, root13bg)) {
			frogbg.move(-2, 0);
		}
		//WARNING: THERE'S WATER GAPS AT THE END, WATCH OUT ;) 
		else if (frogbg.getPosition().y < 60) {
			int x = frogbg.getPosition().x;
			 if (x > 300 && x < 360) {
				 for (i; i < 1; i++) {
					 score += 50;
					 score += (3 - losecount) * 400;
				 }
				score_number = to_string(score);
				scorenumber.setString(score_number);
				frogbg.setPosition(330, 30);
				window.draw(firstround);
				window.draw(pressenter);
				winner = 1;
				if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
					window.close();
					Score(Name, score, 0);
				}
			}
			else if (x > 660 && x < 720) {
				 for (i; i < 1; i++) {
					 score += 50;
					 score += (3 - losecount) * 400;
				 }
				score_number = to_string(score);
				scorenumber.setString(score_number);
				frogbg.setPosition(690, 30);
				window.draw(firstround);
				window.draw(pressenter);
				winner = 1;
				if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
					window.close();
					Score(Name, score, 0);
				}
			}
			else if (x > 900 && x < 960) {
				 for (i; i < 1; i++) {
					 score += 50;
					 score += (3 - losecount) * 400;
				 }
				score_number = to_string(score);
				scorenumber.setString(score_number);
				frogbg.setPosition(930, 30);
				window.draw(firstround);
				window.draw(pressenter);
				winner = 1;
				if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
					window.close();
					Score(Name, score, 0);
				}
			}
			else {
				losecount++;
				frogbg.setPosition(570, 570);
				score_number = to_string(score);
				scorenumber.setString(score_number);
			}
		}
		//WARNING: DON'T TRY TO SWIM, U'LL DIE
		else if (frogbg.getPosition().y <= 250 && frogbg.getPosition().y > 90) {
			losecount++;
			frogbg.setPosition(570, 570);
			score_number = to_string(score);
			scorenumber.setString(score_number);
		}

		//WARNING: DON'T ENTER THE SCORE AREA, OR ANY OTHER PROHEBITED AREAS

		if (frogbg.getPosition().y > 570) {
			frogbg.setPosition(frogbg.getPosition().x, 570);
		}
		if (frogbg.getPosition().x < 30) {
			frogbg.setPosition(30, frogbg.getPosition().y);
		}
		if (frogbg.getPosition().x > 1170) {
			frogbg.setPosition(1170, frogbg.getPosition().y);
		}

		//COLLISION
		//WE MAY ADJUST THE BODY OF THE IF LATER ON

		if (Collision::PixelPerfectTest(car1bg, frogbg)) {
			losecount++;
			pixelcountUP = 0;
			frogbg.setPosition(570, 570);
			score_number = to_string(score);
			scorenumber.setString(score_number);
		}
		if (Collision::PixelPerfectTest(car2bg, frogbg)) {
			losecount++;
			pixelcountUP = 0;
			frogbg.setPosition(570, 570);
			score_number = to_string(score);
			scorenumber.setString(score_number);
		}
		if (Collision::PixelPerfectTest(car3bg, frogbg)) {
			losecount++;
			pixelcountUP = 0;
			frogbg.setPosition(570, 570);
			score_number = to_string(score);
			scorenumber.setString(score_number);
		}
		if (Collision::PixelPerfectTest(car4bg, frogbg)) {
			losecount++;
			pixelcountUP = 0;
			frogbg.setPosition(570, 570);
			score_number = to_string(score);
			scorenumber.setString(score_number);
		}
		if (Collision::PixelPerfectTest(car5bg, frogbg)) {
			losecount++;
			pixelcountUP = 0;
			frogbg.setPosition(570, 570);
			score_number = to_string(score);
			scorenumber.setString(score_number);
		}
		if (Collision::PixelPerfectTest(car6bg, frogbg)) {
			losecount++;
			pixelcountUP = 0;
			frogbg.setPosition(570, 570);
			score_number = to_string(score);
			scorenumber.setString(score_number);
		}
		if (Collision::PixelPerfectTest(car7bg, frogbg)) {
			losecount++;
			pixelcountUP = 0;
			frogbg.setPosition(570, 570);
			score_number = to_string(score);
			scorenumber.setString(score_number);
		}
		if (Collision::PixelPerfectTest(car8bg, frogbg)) {
			losecount++;
			pixelcountUP = 0;
			frogbg.setPosition(570, 570);
			score_number = to_string(score);
			scorenumber.setString(score_number);
		}
		if (Collision::PixelPerfectTest(car9bg, frogbg)) {
			losecount++;
			pixelcountUP = 0;
			frogbg.setPosition(570, 570);
			score_number = to_string(score);
			scorenumber.setString(score_number);
		}
		if (Collision::PixelPerfectTest(car10bg, frogbg)) {
			losecount++;
			pixelcountUP = 0;
			frogbg.setPosition(570, 570);
			score_number = to_string(score);
			scorenumber.setString(score_number);
		}
		//GAME OVER
		if (losecount == 1) {
			heart.setColor(Color::Black);
		}
		else if (losecount == 2) {
			heart.setColor(Color::Black);

			heart2.setColor(Color::Black);
		}
		else if (losecount == 3) {
			heart3.setColor(Color::Black);
			window.draw(gameovertext);
			window.draw(pressenter_GAMEOVER);
			if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
				window.close();
				Score(Name, score, 0);
			}
		}
		window.draw(frogbg);
		Sleep(7);
		window.display();
	}


}