#include "stdafx.h"
#include "Alien.h"

Bitmap Alien::bitmap;

Alien::Alien() {
	init();
}

Alien::Alien(const char* filename) {
	LoadBitmapFromFile(filename, Alien::bitmap);
	init();
}

Alien::~Alien() {
	FreeBitmap(Alien::bitmap);
	delete laser;
}

void Alien::init() {
	laser = new RedLaser();
	laserSpeed = 2;
	lastShot = time(0);
	shotDelay = (rand() % 3);
	width = height = 50;
	radius = width / 2;
	y = -height;
	attacking = false;
}

void Alien::attack() {
	attacking = true;
	srand(time(NULL));
	x = (rand() % (WindowWidth - width));
	setNextTarget();
	dy = 2;
}

void Alien::die() {
	exploding = false;
	attacking = false;
	y = -height;
}

void Alien::setNextTarget() {
	nextX = (rand() % (WindowWidth - width));
	if(nextX < x) {
		dx = -2;
	} else if(nextX > x) {
		dx = 2;
	} else {
		setNextTarget();
	}
}

void Alien::update() {
	if(exploding) {
		updateExplosion();
		if(timeToDie()) {
			die();
		}
	} else {
		if(!attacking) {
			attack();
		} else if (timeToShoot()){
			shoot();
		}

		if(targetReached()) {
			shoot();
			setNextTarget();
		}
	}
	
	move();
	laser->update();
}

void Alien::move() {
	if(enteringStage() || exploding) {
		y += dy;	
	}
	x += dx;
}

void Alien::draw() {
	DrawBitmap(Alien::bitmap, x, y);
	if(isExploding()) {
		drawExplosion();
	}
	laser->draw();
}

void Alien::shoot() {
	laser->shoot((x + (width / 2)), (y + height), laserSpeed);
	lastShot = time(0);
	shotDelay = (rand() % 3);
}

bool Alien::timeToShoot() {
	return difftime(time(0), lastShot) >= shotDelay;
}

bool Alien::enteringStage() {
	return y < 10;
}

bool Alien::targetReached() {
	return x >= (nextX - 5) && x <= (nextX + 5);
}
