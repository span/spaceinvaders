/**
 * This class extends the Laser class and loads a custom bitmap as a blue laser.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef BLUELASER_HPP_
#define BLUELASER_HPP_

#include "Laser.h"

class BlueLaser : public Laser {
	private:

		/**
		 * Bitmap that holds the index of the resource
		 */
		static Bitmap bitmap;

	public:

		/**
		 * Default constructor that initiates the laser and loads the blue laser bitmap.
		 */
		BlueLaser();


		/**
		 * Default destructor that frees the bitmap.
		 */
		~BlueLaser();

		/**
		 * Draws the bitmap to the buffer
		 */
		void draw();
};

#endif BLUELASER_HPP_
