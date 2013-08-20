#include "stdafx.h"
#include "BlueLaser.h"

Bitmap BlueLaser::bitmap;

BlueLaser::BlueLaser() : Laser() {
	LoadBitmapFromFile("images/bullet_blue.bmp", BlueLaser::bitmap);
}

BlueLaser::~BlueLaser() {
	FreeBitmap(BlueLaser::bitmap);
}

void BlueLaser::draw() {
	std::vector<Vector>::iterator bullet = bullets.begin();
	while(bullet != bullets.end()) {
		DrawBitmap(BlueLaser::bitmap, bullet->x, bullet->y);
		++bullet;
	}
}
