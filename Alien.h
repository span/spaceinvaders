/**
 * The Alien class extends the Ship class to make use of the same explosion that
 * ships share. The Alien class also calculates a position to which it should travel
 * randomly. The alien also shoots	lasers using the Laser class at random intervals.	
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef ALIEN_HPP_
#define ALIEN_HPP_

#include "RedLaser.h"
#include "Ship.h"

class Alien : public Ship {
	private:

		int nextX, laserSpeed, shotDelay;
		bool attacking;
		time_t lastShot;

		bool targetReached();
		bool timeToShoot();
		bool enteringStage();
		
		void shoot();
		void move();
		void init();

	protected:

		/**
		 * Static variable that is shared between all alien instances that references the space ship image.
		 */
		static Bitmap bitmap;

	public:
		/**
		 * Default construtor that does not load a bitmap.
		 */
		Alien();

		/**
		 * Construtor that does load a bitmap to the static class wide variable.
		 */
		Alien(const char* filename);

		/**
		 * Default destructor that  unloads the bitmap and deletes the laser.
		 */
		~Alien();

		/**
		 * The aliens use red laser so we need an instance to be able to shoot
		 */
		RedLaser* laser;

		/**
		 * Sets the next target for the alien, is called when the previous target was reached.
		 */
		void setNextTarget();

		/**
		 * Updates the alien position and other properties before drawing.
		 */
		void update();

		/**
		 * Draws the alien and its laser
		 */
		void draw();

		/**
		 *	Moves the alien from a hidden position on the screen to the fighting position
		 */
		void attack();

		/**
		 * Resets the alien to a hidden position when the ship has exploded.
		 */
		void die();
};

#endif ALIEN_HPP_