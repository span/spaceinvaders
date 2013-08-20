/**
 * The corresponding cpp file for this header contains the WinAPI's main and
 * process functions. This file loads the graphical library and sets up the
 * basic message handling that is required.
 *
 * It also contains the main game loop.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef SPACEINVADERS_HPP_
#define SPACEINVADERS_HPP_

#include "Intro.h"
#include "Resource.h"
#include "Level.h"

const int WindowWidth = 640;
const int WindowHeight = 293;

enum State {
	intro,
	game
};

#endif SPACEINVADERS_HPP_