/**
 * This class extends the Laser class and loads a custom bitmap as a red laser.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef REDLASER_HPP_
#define REDLASER_HPP_

#include "Laser.h"

class RedLaser : public Laser {
	private:
	
		/**
		 * Bitmap that holds the index of the resource
		 */
		static Bitmap bitmap;

	public:

		/**
		 * Default constructor that initiates the laser and loads the red laser bitmap.
		 */
		RedLaser();

		/**
		 * Default destructor that frees the bitmap.
		 */
		~RedLaser();

		/**
		 * Draws the bitmap to the buffer
		 */
		void draw();
};

#endif REDLASER_HPP_
