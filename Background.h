/**
 * The background class keeps a reference to a background bitmap that is drawn twice
 * on each tick on y-values that make them seem like a single one.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef BACKGROUND_HPP_
#define BACKGROUND_HPP_
#include "Sprite.h"

class Background : public Sprite {
	private:

		Bitmap bitmap;

	public:

		/**
		 * Creates a new background instance with the image loaded from the path in the parameter
		 */
		Background(const char* filename);

		/**
		 * Updates the background position.
		 */
		void update();

		/**
		 * Draws the background
		 */
		void draw();
};

#endif BACKGROUND_HPP_