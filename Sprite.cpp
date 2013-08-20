#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite() {
	init();
}

void Sprite::init() {
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

int Sprite::getWidth() {
	return width;
}

int Sprite::getHeight() {
	return height;
}
