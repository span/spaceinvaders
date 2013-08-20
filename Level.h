/**
 * This class contains the basic level components such as background, player,
 * the aliens armada and the scoreboard. It handles the dispatching of update and
 * draw methods to these classes and updates scoreboard if a ship has been hit.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef LEVEL_HPP_
#define LEVEL_HPP_
#include "Background.h"
#include "Player.h"
#include "Armada.h"
#include "Scoreboard.h"

class Level {
	private:

		Background* background;
		Player* player;
		Armada* armada;
		Scoreboard* scoreboard;

	public:

		/**
		 * Default empty constructor
		 */
		Level();

		/**
		 * Destructor that deletes the pointer members of the class.
		 */
		~Level();

		/**
		 * Tries to initiate the level and returns true if successful.
		 *
		 * @return true if successful
		 */
		bool init();

		/**
		 * Forwards update calls to its members to update the buffer.
		 */
		void update(bool left, bool right, bool space);

		/**
		 * Forwards draw calls to its members to draw to the buffer
		 */
		void draw();

		/**
		 * Resets the members of the level so that it can't start again
		 */
		void reset();
};

#endif Level_HPP_
