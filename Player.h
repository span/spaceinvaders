/**
 * This class handles the player actionss. It also loads a bitmap that represents the player
 * on screen. The player can be updated, drawn and die. There is also a hit test method which
 * checks if the player has killed an alien with its Laser.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "BlueLaser.h"
#include "Ship.h"

class Armada;

class Player : public Ship {
	private:
		
		int speed, laserSpeed;
		Bitmap bitmap;

		void setInitialPosition();

	public:

		/**
		 * Constructor that sets the initial position of the player and loads
		 * the bitmap.
		 */
		Player(const char* filename);

		/**
		 * Destructor that frees the bitmap and deletes the laser.
		 */
		~Player();

		/**
		 * Laser that the player can use to shoot at aliens,
		 */
		BlueLaser* laser;

		/**
		 * Resets the players position after he/she has been killed.
		 */
		void die();

		/**
		 * Performs a hit test on the alien with the laser.
		 *
		 * @return true if alien is hit
		 */
		bool hit(Armada* armada);

		/**
		 * Updates the player's position according to the controls.
		 */
		void update(bool left, bool right, bool space);

		/**
		 * Draws the player to the buffer with the current position and status.
		 */
		void draw();
};

#endif PLAYER_HPP_