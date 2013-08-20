#include "stdafx.h"
#include "Armada.h"


Armada::Armada() {
	aliens.push_back(new Alien("images/alien.bmp"));
	maxShips = 2;
	lastAdded = time(0);
	addDelay = calculateAddDelay();
}


Armada::~Armada() {
	for(int i = 0; i < aliens.size(); ++i) {
		delete aliens[i];
	}
}

void Armada::add() {
	aliens.push_back(new Alien());
	lastAdded = time(0);
	addDelay = calculateAddDelay();
}

bool Armada::hit(Ship* player) {
	bool hit = false;
	std::vector<Alien*>::iterator alien = aliens.begin();
	while(alien != aliens.end()) {
		if((*alien)->laser->hit(player)) {
			hit = true;
		} else {
			++alien;
		}
	}
	return hit;
}

void Armada::explode() {
	std::vector<Alien*>::iterator alien = aliens.begin();
	while(alien != aliens.end()) {
		(*alien)->explode();
		++alien;
	}
}

void Armada::update() {
	
	if(timeToAdd() && (aliens.size() < maxShips)) {
 		add();
	}

	std::vector<Alien*>::iterator alien = aliens.begin();
	while(alien != aliens.end()) {
		(*alien)->update();
		++alien;
	}
}

bool Armada::timeToAdd() {
	return difftime(time(0), lastAdded) >= addDelay;
}

int Armada::calculateAddDelay() {
	return (rand() % 7) + 3;;
}

void Armada::draw() {
	std::vector<Alien*>::iterator alien = aliens.begin();
	while(alien != aliens.end()) {
		(*alien)->draw();
		++alien;
	}
}

std::vector<Alien*> Armada::getAliens() {
	return aliens;
}
