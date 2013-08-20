#include "stdafx.h"
#include "Intro.h"

Intro::Intro() {
	lastText = time(0);
	textDelay = 4;
	currentString = 0;
	strings.push_back("For years you have lived in peace...alone.");
	strings.push_back("Little could you know, you have been watched!");
	strings.push_back("Prepare your ships and lasers, because here comes....");
	strings.push_back("SPACE INVADERS!");
	textX = (WindowWidth / 2) - (strings.at(currentString).length() * 3); // 3 being half of the width of each character (approx.)
	textY = (WindowHeight / 2) - 50;
}

Intro::~Intro() {
	std::vector<std::string>().swap(strings);
}

void Intro::update(bool space, State* state) {
	if(space) {
		*state = State::game;
	} else if(timeToChangeString() && currentString < (strings.size() - 1)) {
		currentString += 1;
		textX = (WindowWidth / 2) - (strings.at(currentString).length() * 3); // 3 being half of the width of each character (approx.)
		lastText = time(0);
	}
}

void Intro::draw() {
	DrawString(strings.at(currentString).c_str(), textX, textY, RGB(255, 255, 255));
}

bool Intro::timeToChangeString() {
	return difftime(time(0), lastText) >= textDelay;
}
