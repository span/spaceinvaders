/**
 * The armada class keeps track of all the alien ships that are attacking. It is
 * possible to add and hit ships in the armada.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef ARMADA_HPP_
#define ARMADA_HPP_

#include "Alien.h"
#include "Vector.h"

class Armada {
	private:

		int maxShips, lastAdded, addDelay;
		std::vector<Alien*> aliens;

		void randomiseNewShip();
		bool timeToAdd();
		int calculateAddDelay();

	public:

		/**
		 * Default constructor that adds an initial alien and sets the max number of ships
		 * and add-delay.
		 */
		Armada();

		/**
		 *	Default destructor that deletes all ships
		 */
		~Armada();

		/**
		 * Adds a new alien to the armada.
		 */
		void add();

		/**
		 * Makes a hit test to see if any of the ships in the armada has hit the player.
		 * @return bool true if hit
		 */
		bool hit(Ship* player);

		/**
		 * Explodes all ships in the armada.
		 */
		void explode();

		/**
		 * Updates the alien ships positions.
		 */
		void update();
		
		/**
		 * Draws the armada
		 */
		void draw();

		/**
		 * Fetches the alien ships
		 * @return a vector of Alien pointers
		 */
		std::vector<Alien*> getAliens();
};

#endif ARMADA_HPP_
