#include "stdafx.h"
#include "Level.h"

Level::Level() {}

Level::~Level() {
	delete background;
	delete player;
	delete armada;
	delete scoreboard;
}

bool Level::init() {
	// TODO move file loading from constructor to 'loadBitmap' method in sprite and return result
	background = new Background("images/background.bmp");
	player = new Player("images/player.bmp");
	armada = new Armada();
	scoreboard = new Scoreboard();
	return true;
}

void Level::reset() {
	player->explode();
	armada->explode();
	scoreboard->reset();
}

void Level::update(bool left, bool right, bool space) {
	background->update();
	player->update(left, right, space);
	armada->update();

	if(player->hit(armada)) {
		scoreboard->updatePlayerScore();
	}

	if(armada->hit(player)) {
		scoreboard->updateAlienScore();
	}
}

void Level::draw() {
	background->draw();
	player->draw();
	armada->draw();
	scoreboard->draw();
}
