/**
 * This class handles printing to the scoreboard. It can update the player
 * and alien score and creates a string out of the two that is then drawn
 * to the back buffer.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */

#ifndef SCOREBOARD_HPP_
#define SCOREBOARD_HPP_

class Scoreboard {
	private:
		int alienScore, playerScore;
		bool scoreChanged;
		std::stringstream scoreStringStream;
	public:
		Scoreboard();
		void updatePlayerScore();
		void updateAlienScore();
		void draw();
		void reset();
};

#endif SCOREBOARD_HPP_
