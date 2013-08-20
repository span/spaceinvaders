#include "stdafx.h"
#include "RedLaser.h"


Bitmap RedLaser::bitmap;

RedLaser::RedLaser() : Laser() {
	LoadBitmapFromFile("images/bullet_red.bmp", RedLaser::bitmap);
}

RedLaser::~RedLaser() {
	FreeBitmap(RedLaser::bitmap);
}

void RedLaser::draw() {
	std::vector<Vector>::iterator bullet = bullets.begin();
	while(bullet != bullets.end()) {
		DrawBitmap(RedLaser::bitmap, bullet->x, bullet->y);
		++bullet;
	}
}
