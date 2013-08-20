#include "stdafx.h"
#include "Ship.h"

char* Ship::explosionFiles[] = {
	"images/ship-explosion/0.bmp",
	"images/ship-explosion/1.bmp",
	"images/ship-explosion/2.bmp",
	"images/ship-explosion/3.bmp",
	"images/ship-explosion/4.bmp"
};

std::vector<Bitmap> Ship::explosionBitmaps;

Ship::Ship() : Sprite() {
	init();
}

Ship::~Ship() {
	for(int i = 0; i < explosionBitmaps.size(); i++) {
		FreeBitmap(Ship::explosionBitmaps.at(i));
	}
	std::vector<Bitmap>().swap(explosionBitmaps);
}

void Ship::init() {
	if(Ship::explosionBitmaps.size() == 0) {
		loadExplosionBitmaps();
	}
	exploding = false;
	dx = 0;
	dy = 0;
}

void Ship::loadExplosionBitmaps() {
	for(int i = 0; i < 5; i++) {
		Bitmap bm;
		LoadBitmapFromFile(Ship::explosionFiles[i], bm);
		Ship::explosionBitmaps.push_back(bm);
	}
}

void Ship::explode() {
	PlaySound(TEXT("sounds/explosion.wav"), NULL, SND_FILENAME | SND_ASYNC);
	initialTick = GetTickCount64();
	explosionFrame = 0;
	exploding = true;
	dx = 0;
	dy = 2;
}

bool Ship::isExploding() {
	return exploding;
}

void Ship::updateExplosion() {
	if((GetTickCount64() - initialTick) > 200) {
		if(explosionFrame < (explosionBitmaps.size() - 1)) { // TODO Check this signed/unsiged mismatch
			explosionFrame += 1;
		}
	}
}

void Ship::drawExplosion() {
	DrawBitmap(Ship::explosionBitmaps[explosionFrame], x, y);
}

bool Ship::timeToDie() {
	return (GetTickCount64() - initialTick) > 2000 && explosionFrame == (Ship::explosionBitmaps.size() - 1);
}
