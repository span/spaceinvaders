#include "stdafx.h"
#include "Player.h"

Player::Player(const char* filename) : Ship() {
	LoadBitmapFromFile(filename, bitmap);
	laser = new BlueLaser();
	width = height = 60;
	radius = width / 2;
	laserSpeed = -2;
	setInitialPosition();
}

Player::~Player() {
	FreeBitmap(bitmap);
	delete laser;
}

void Player::setInitialPosition() {
	x = (WindowWidth / 2) - (width / 2);
	y = WindowHeight - height - radius;
	dx = 3;
	dy = 2;
}

void Player::die() {
	exploding = false;
	//bitmap = shipBitmap;
	setInitialPosition();
}

bool Player::hit(Armada* armada) {
	return laser->hit(armada->getAliens());
}

void Player::update(bool left, bool right, bool space) {
	if(exploding) {
		updateExplosion();
		if(timeToDie()) {
			die();
		}
		y += dy;
	} else {
		if(left) {
			x = (x - dx) < 0 ? 0 : (x - dx);
		} 
	
		if (right) {
			x = (x + dx) > (WindowWidth - width) ? (WindowWidth - width) : (x + dx);
		}

		if(space) {
			PlaySound(TEXT("sounds/laser.wav"), NULL,  SND_FILENAME | SND_NOSTOP | SND_ASYNC);
			laser->shoot(x, y, laserSpeed);
		}	
	}
	laser->update();
}

void Player::draw() {
	DrawBitmap(bitmap, x, y);
	if(isExploding()) {
		drawExplosion();
	}
	laser->draw();
}