/**
 * This is a class that contains the common components for any ship (Alien, Player) that
 * is displayed on screen. It contains the explosion bitmaps that are the same and also
 * some Sprite and size properties.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef SHIP_HPP_
#define SHIP_HPP_

#include "Sprite.h"

class Ship : public Sprite {
	private:
		void loadExplosionBitmaps();
		void init();
	protected:
		static char* explosionFiles[];
		static std::vector<Bitmap> explosionBitmaps;

		int explosionFrame;
		bool exploding;

		DWORD initialTick;

		void updateExplosion();
		bool timeToDie();
	public:

		// Some position and speed properties
		int center, radius, dx, dy;

		/**
		 * Constructor that sets the inital properties and loads the bitmaps if not
		 * already loaded.
		 */
		Ship();

		/**
		 * Destructor that frees the bitmaps the class had loaded.
		 */
		~Ship();
		
		/**
		 * Draws an explosion frame if the ship is exploding
		 */
		void drawExplosion();

		/**
		 * Sets the ship to explode and then die.
		 */
		void explode();

		/**
		 * Checks if the ship is exploding or not.
		 *
		 * @return true if exploding
		 */
		bool isExploding();
};

#endif SHIP_HPP_