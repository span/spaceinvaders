/**
 * This is the super class for the lasers. This class extends Sprite to get some basic
 * positional attributes and then adds some custom ones such as radius for collision
 * detection.
 *
 * The class keeps a vector of Vector's that contains x, y and speed for each laser
 * 'bullet'. It handles collisions and placement of laser shots.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef LASER_HPP_
#define LASER_HPP_

#include "Ship.h"
#include "Vector.h"

class Alien;

class Laser : public Sprite {
	private :
		bool armed;
		int reloadTime, width, height, radius;

		bool circleCollision(int x, int y, Ship* sprite);
		void reload();

	protected:

		/**
		 * A vector of laser positions and speeds in the form of Vector
		 */
		std::vector<Vector> bullets;

	public:

		/**
		 * Default constructor that sets the width, height and armed properties.
		 */
		Laser();

		/**
		 * Default destructor that cleans the vector with bullets.
		 */
		~Laser();

		/**
		 * Checks to see if the laser has hit any aliens in a vector of aliens.
		 *
		 * @return true if an alien is hit, the alien is also exploded if hit
		 */
		bool hit(std::vector<Alien*> aliens);

		/**
		 * Checks to see if the laser has hit a ship in a vector of aliens.
		 *
		 * @return true if an alien is hit, the alien is also exploded if hit
		 */
		bool hit(Ship* sprite);

		/**
		 * Adds a new bullet with x, y and speed paramaters in a new Vector.
		 */
		void shoot(int x, int y, int dy);

		/**
		 * Moves the bullets on the screen before drawing.
		 */
		void update();
};

#endif LASER_HPP_
