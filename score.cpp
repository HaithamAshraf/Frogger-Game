#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <sstream>
#include<dos.h>
#include<Windows.h>

void menu();

using namespace std;
using namespace sf;


string Zero = "0";
list<int> scores;
stack<int> maxscores;
stack<string> maxnames;
int game = 0;

//Each array element contains the name and this player's score
struct Player {
	string name = "Player";
	int score = 000000;
}player[1000];

//To put Zeros before score.
int countnum(int num) {
	int count = 0;
	while (num != 0) {
		count++;
		num /= 10;
	}
	return count;
}

//forward declaration
void loadfiles();
void SortingScores();
void DisplayScores();
void savefiles();
//Recieves the last player name and score thwn displaying score menu
void recievescore(string tempname, int tempscore) {
	loadfiles();
	player[game].name = tempname;
	player[game].score = tempscore;
	game++;
	SortingScores();
	DisplayScores();

}

//displaying score menu
void DisplayScoreMenu() {
	loadfiles();
	SortingScores();
	DisplayScores();

}



//load saved scores and game number
void loadfiles() {
	ifstream readgame;
	readgame.open("GameLog.txt");
	if (readgame.fail()) {
		cout << "ERROR LOADING FILES!";
		exit(1);
	}
	readgame >> game;
	readgame.close();


	int temp = 0;
	ifstream readnames;
	readnames.open("NameLog.txt");
	if (readnames.fail()) {
		cout << "ERROR LOADING FILES!";
		exit(1);
	}
	while (!readnames.eof()) {
		getline(readnames, player[temp].name);
		temp++;
	}
	readnames.close();
	temp = 0;
	string tempst;
	ifstream readscores;
	readscores.open("ScoreLog.txt");
	if (readscores.fail()) {
		cout << "ERROR LOADING FILES!";
		exit(1);
	}
	while (!readscores.eof()) {
		getline(readscores, tempst);
		istringstream(tempst) >> player[temp].score;
		temp++;
	}
	readscores.close();
}

//save scores after every game
void savefiles() {
	ofstream getgame;
	getgame.open("GameLog.txt");
	getgame << game;
	getgame.close();

	ofstream insertN;
	insertN.open("NameLog.txt");
	for (int i = 0; i < game; i++) {
		insertN << player[i].name << endl;
	}
	insertN.close();

	ofstream insertS;
	insertS.open("ScoreLog.txt");
	for (int i = 0; i < game; i++) {
		insertS << player[i].score << endl;
	}
	insertS.close();

}

//Sort scores from highest to lowest then passing it to a stack
void SortingScores() {
	//Clearing Stacks
	while (!maxscores.empty())
		maxscores.pop();
	while (!maxnames.empty())
		maxnames.pop();

	scores.clear();
	for (int i = 0; i < game; i++) {
		scores.push_back(player[i].score);
	}

	list<int> temp = scores;
	temp.sort();

	while (!temp.empty()) {
		maxscores.push(temp.front());
		int	cnt = 0;
		for (list<int>::iterator it = scores.begin(); it != scores.end(); ++it) {
			if (*it == maxscores.top()) {
				maxnames.push(player[cnt].name);
				temp.pop_front();
				break;
			}
			cnt++;
		}
	}
	savefiles();
}

//Display latest 5 scores then highest 5 scores
void DisplayScores() {
	Texture background;
	background.loadFromFile("Froggerblur.png");
	Sprite backgroundbg;
	backgroundbg.setTexture(background);
	RenderWindow window(VideoMode(1200, 780), "SCORE");
	window.draw(backgroundbg);
	float y = 120;
	Font font;
	font.loadFromFile("Chopsic.otf");
	string goback = "PRESS ENTER TO GET BACK TO MAIN MENU";
	string playername = "";
	string playerscore = "";
	int cnt;
	int tmp = game - 1;
	Text press(goback, font, 30); press.setPosition(220, 680);
	window.draw(press);
	Text latest("LATEST SCORES", font, 40); latest.setPosition(420, 30);
	window.draw(latest);
	latest.setString("Player Name"); latest.setPosition(100, 80); latest.setCharacterSize(25);
	window.draw(latest);
	latest.setString("Score"); latest.setPosition(940, 80);
	window.draw(latest);

	Text name(playername, font, 20);
	Text score(playerscore, font, 20);

	if (game > 5) {

		for (int i = tmp; i > tmp - 5; i--) {
			playerscore.clear();
			cnt = countnum(player[i].score);
			playername = player[i].name;
			name.setString(playername);
			name.setPosition(100, y);
			window.draw(name);
			while (cnt < 5)
			{
				playerscore += Zero;
				cnt++;
			}
			playerscore += (to_string(player[i].score));
			Text score(playerscore, font, 20);
			score.setPosition(946, y);
			window.draw(score);
			y += 27;
		}
	}
	else {
		while (tmp >= 0) {
			playerscore.clear();
			cnt = countnum(player[tmp].score);
			playername = player[tmp].name;
			name.setString(playername);
			name.setPosition(100, y);
			window.draw(name);
			while (cnt < 5)
			{
				playerscore += Zero;
				cnt++;
			}
			playerscore += (to_string(player[tmp].score));
			Text score(playerscore, font, 20);
			score.setPosition(946, y);
			window.draw(score);
			y += 27;
			tmp--;
		}
		Text player("Player", font, 20);
		for (int i = 0; i < 5 - game; i++) {
			player.setString("Player");
			player.setPosition(100, y);
			window.draw(player);
			player.setString("00000"); player.setPosition(946, y);
			window.draw(player);
			y += 27;
		}
	}

	y += 35;
	Text highest("HIGHEST SCORES!", font, 40); highest.setPosition(400, y);
	window.draw(highest);
	highest.setString("Player Name"); highest.setPosition(100, y + 50); highest.setCharacterSize(25);
	window.draw(highest);
	highest.setString("Score"); highest.setPosition(940, y + 50);
	window.draw(highest);
	y += 90;
	if (maxscores.size() > 5) {
		for (int i = 0; i < 5; i++) {
			playerscore.clear();
			cnt = countnum(maxscores.top());
			playername = maxnames.top();
			name.setString(playername);
			name.setPosition(100, y);
			window.draw(name);
			maxnames.pop();
			while (cnt < 5)
			{
				playerscore += Zero;
				cnt++;
			}
			playerscore += (to_string(maxscores.top()));
			Text score(playerscore, font, 20);
			score.setPosition(946, y);
			window.draw(score);
			maxscores.pop();
			y += 27;
		}
	}
	else {
		while (!maxscores.empty()) {
			playerscore.clear();
			cnt = countnum(maxscores.top());
			playername = maxnames.top();
			name.setString(playername);
			name.setPosition(100, y);
			window.draw(name);
			maxnames.pop();
			while (cnt < 5)
			{
				playerscore += Zero;
				cnt++;
			}
			playerscore += (to_string(maxscores.top()));
			Text score(playerscore, font, 20);
			score.setPosition(946, y);
			window.draw(score);
			maxscores.pop();
			y += 27;
		}
		Text player("Player", font, 20);
		for (int i = 0; i < 5 - game; i++) {
			player.setString("Player");
			player.setPosition(100, y);
			window.draw(player);
			player.setString("00000"); player.setPosition(946, y);
			window.draw(player);
			y += 27;
		}
	}
	window.display();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case::Event::Closed:
				window.close();
				break;
			case::Event::EventType::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
					window.close();
					menu();
				}
					
			}
		}
	}
}


void Score(string name,int scoreval, int selector) {

	string Name = name;
	int Scoreval = scoreval;
	if (selector == 0)
		recievescore(Name, Scoreval);
	else if (selector == 1)
		DisplayScoreMenu();


	
}

