#include "stdafx.h"
#include "Background.h"

Background::Background(const char* filename) : Sprite() {
	LoadBitmapFromFile(filename, bitmap);
}

void Background::update() {
	y += 1;
	if(y > WindowHeight) {
		y = 0;
	}
}

void Background::draw() {
	DrawBitmap(bitmap, x, y);
	DrawBitmap(bitmap, x, y - WindowHeight);
}
