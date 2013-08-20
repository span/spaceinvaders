#include "stdafx.h"
#include "Laser.h"

Laser::Laser() {
	armed = true;
	width = height = 2;
	radius = width / 2;
}

Laser::~Laser() {
	bullets.clear();
	std::vector<Vector>().swap(bullets);
}

void Laser::shoot(int x, int y, int dy) {
	if(armed) {
		bullets.push_back(Vector(x, y, dy));
		reload();
	}
}

void Laser::reload() {
	armed = false;
	reloadTime = time(0);
}

bool Laser::hit(std::vector<Alien*> aliens) {
	bool hit = false;
	std::vector<Alien*>::iterator alien = aliens.begin();
	while(alien != aliens.end()) {
		if(Laser::hit((*alien))) {
			hit = true;
			break;
		} else {
			++alien;
		}
	}
	return hit;
}

bool Laser::hit(Ship* ship) {
	bool hit = false;
	if(!ship->isExploding()) {
		std::vector<Vector>::iterator bullet = bullets.begin();
		while(bullet != bullets.end()) {
			if(circleCollision(bullet->x, bullet->y, ship)) {
				ship->explode();
				hit = true;
				bullet = bullets.erase(bullet); // TODO cleanup needed?
				break;
			} else {
				++bullet;
			}
		}
	}
	return hit;
}

bool Laser::circleCollision(int x, int y, Ship* ship) {
	int xDist = (x + radius) - (ship->x + ship->radius);
	int yDist = (y + radius) - (ship->y + ship->radius);
	int radii = radius + ship->radius;
	return ((xDist * xDist)  + (yDist * yDist)) < (radii * radii);
}

void Laser::update() {
	std::vector<Vector>::iterator bullet = bullets.begin();
	while(bullet != bullets.end()) {
		if(bullet->y < 0 || bullet->y > WindowHeight) {
			// TODO check if cleanup is needed?
			bullet = bullets.erase(bullet);
		} else {
			bullet->y += bullet->dy;
			++bullet;
		}
	}

	if(!armed && difftime(time(0), reloadTime) >= 1) {
		armed = true;
	}
}
