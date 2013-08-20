#include "stdafx.h"
#include "Scoreboard.h"


Scoreboard::Scoreboard() {
	playerScore = 0;
	alienScore = 0;
	scoreChanged = true;
}

void Scoreboard::updatePlayerScore() {
	playerScore += 1;
	scoreChanged = true;
}

void Scoreboard::updateAlienScore() {
	alienScore += 1;
	scoreChanged = true;
}

void Scoreboard::draw() {
	if(scoreChanged) {
		scoreStringStream.str(std::string());
		scoreStringStream << "Player: " << playerScore << "   " << "Alien: " << alienScore;
	}
	DrawString(scoreStringStream.str().c_str(), 10, 10, RGB(255, 255, 255));
}

void Scoreboard::reset() {
	alienScore = 0;
	playerScore = 0;
	scoreChanged = true;
}
