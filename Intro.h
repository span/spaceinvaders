/**
 * This class displays the intro to the game. It contains some text that is displayed
 * in order to give the player some backstory. Once the player hits 'space' the game
 * state is changed in the calling class and the intro is finished.
 *
 * @Author: Daniel Kvist
 * @OS: Windows 8
 * @Date: 2013-08-19
 *
 */
#ifndef INTRO_HPP_
#define INTRO_HPP_

#include <string>

enum State;

class Intro {
	private:

		int currentString, textDelay, textX, textY;
		time_t lastText;
		std::vector<std::string> strings;

	public:

		/**
		 * Default constructor that sets up the text vector and some initial measurements
		 * so that the text is drawn at the proper place on the screen.
		 */
		Intro();

		/**
		 * Default destructor that cleans up the vector of strings.
		 */
		~Intro();

		/**
		 * Updates the text that is to be displayed and if space is true the state
		 * will change to 'game'.
		 *
		 * @param space if space has been pressed
		 * @param state the state to change
		 */
		void update(bool space, State* state);

		/**
		 * Draws the text to the screen
		 */
		void draw();

		/**
		 * Checks to see if the time for one string has elapse and it is time to show
		 * the next one.
		 *
		 * @return true if time to change
		 */
		bool timeToChangeString();
};

#endif INTRO_HPP_
