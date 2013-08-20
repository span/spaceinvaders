/**
 * Defines some simple sprite properties such as x, y, width and height. Used as base
 * for most other objects that are placed on screen.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

class Sprite {
	private:
		void init();
	
	public:

		/**
		 * Constructor that initiates the properties to default values of 0
		 */
		Sprite();
		int x, y, width, height;
		int getWidth();
		int getHeight();
};

#endif SPRITE_HPP_