#include "UserInput.h"

// Tests whether a key is currently pressed or not
void UserInput::test() {
	// Show that the window hasn't been pressed yet
	windowCross = false;

	// Set all the key-presses to false
	for (int i=0; i<4; i++)
		pressed_arrowKeys[i] = false;
	for (int i=0; i<6; i++)
		pressed_controlKeys[i] = false;
	for (int i=0; i<26; i++)
		pressed_letter[i] = false;
	for (int i=0; i<10; i++)
		pressed_num[i] = false;
	
	while ( SDL_PollEvent(&sdlEvent) ) {
		if (sdlEvent.type == SDL_QUIT)
			windowCross = true;

		// Test whether keys are held
		test_letters();
		test_arrowKeys();
		test_controlKeys();
		test_numberKeys();

		// Test whether keys are pressed or not
		testPressed_letters();
		testPressed_arrowKeys();
		testPressed_controlKeys();
		testPressed_numberKeys();
	}
}

//=======================================================================================
// To test whether a key is pressed or not
//=======================================================================================

void UserInput::test_letters() {
	// Keydown
	if (sdlEvent.type == SDL_KEYDOWN) {
		switch( sdlEvent.key.keysym.sym ) {
			case 'a': case 'A':
				letter[0] = true;
				break;
			case 'b': case 'B':
				letter[1] = true;
				break;
			case 'c': case 'C':
				letter[2] = true;
				break;
			case 'd': case 'D':
				letter[3] = true;
				break;
			case 'e': case 'E':
				letter[4] = true;
				break;
			case 'f': case 'F':
				letter[5] = true;
				break;
			case 'g': case 'G':
				letter[6] = true;
				break;
			case 'h': case 'H':
				letter[7] = true;
				break;
			case 'i': case 'I':
				letter[8] = true;
				break;
			case 'j': case 'J':
				letter[9] = true;
				break;
			case 'k': case 'K':
				letter[10] = true;
				break;
			case 'l': case 'L':
				letter[11] = true;
				break;
			case 'm': case 'M':
				letter[12] = true;
				break;
			case 'n': case 'N':
				letter[13] = true;
				break;
			case 'o': case 'O':
				letter[14] = true;
				break;
			case 'p': case 'P':
				letter[15] = true;
				break;
			case 'q': case 'Q':
				letter[16] = true;
				break;
			case 'r': case 'R':
				letter[17] = true;
				break;
			case 's': case 'S':
				letter[18] = true;
				break;
			case 't': case 'T':
				letter[19] = true;
				break;
			case 'u': case 'U':
				letter[20] = true;
				break;
			case 'v': case 'V':
				letter[21] = true;
				break;
			case 'w': case 'W':
				letter[22] = true;
				break;
			case 'x': case 'X':
				letter[23] = true;
				break;
			case 'y': case 'Y':
				letter[24] = true;
				break;
			case 'z': case 'Z':
				letter[25] = true;
				break;
			default:
				break;
		}
	}
	// Key Released
	if (sdlEvent.type == SDL_KEYUP) {
		switch( sdlEvent.key.keysym.sym ) {
			case 'a': case 'A':
				letter[0] = false;
				break;
			case 'b': case 'B':
				letter[1] = false;
				break;
			case 'c': case 'C':
				letter[2] = false;
				break;
			case 'd': case 'D':
				letter[3] = false;
				break;
			case 'e': case 'E':
				letter[4] = false;
				break;
			case 'f': case 'F':
				letter[5] = false;
				break;
			case 'g': case 'G':
				letter[6] = false;
				break;
			case 'h': case 'H':
				letter[7] = false;
				break;
			case 'i': case 'I':
				letter[8] = false;
				break;
			case 'j': case 'J':
				letter[9] = false;
				break;
			case 'k': case 'K':
				letter[10] = false;
				break;
			case 'l': case 'L':
				letter[11] = false;
				break;
			case 'm': case 'M':
				letter[12] = false;
				break;
			case 'n': case 'N':
				letter[13] = false;
				break;
			case 'o': case 'O':
				letter[14] = false;
				break;
			case 'p': case 'P':
				letter[15] = false;
				break;
			case 'q': case 'Q':
				letter[16] = false;
				break;
			case 'r': case 'R':
				letter[17] = false;
				break;
			case 's': case 'S':
				letter[18] = false;
				break;
			case 't': case 'T':
				letter[19] = false;
				break;
			case 'u': case 'U':
				letter[20] = false;
				break;
			case 'v': case 'V':
				letter[21] = false;
				break;
			case 'w': case 'W':
				letter[22] = false;
				break;
			case 'x': case 'X':
				letter[23] = false;
				break;
			case 'y': case 'Y':
				letter[24] = false;
				break;
			case 'z': case 'Z':
				letter[25] = false;
				break;
			default:
				break;
		}
	}
}

void UserInput::test_arrowKeys() {
	// Keydown
	if (sdlEvent.type == SDL_KEYDOWN) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_UP:
				arrowKeys[0] = true;
				break;
			case SDLK_RIGHT:
				arrowKeys[1] = true;
				break;
			case SDLK_DOWN:
				arrowKeys[2] = true;
				break;
			case SDLK_LEFT:
				arrowKeys[3] = true;
				break;
		}
	}
	// Key released
	if (sdlEvent.type == SDL_KEYUP) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_UP:
				arrowKeys[0] = false;
				break;
			case SDLK_RIGHT:
				arrowKeys[1] = false;
				break;
			case SDLK_DOWN:
				arrowKeys[2] = false;
				break;
			case SDLK_LEFT:
				arrowKeys[3] = false;
				break;
		}
	}
}

void UserInput::test_controlKeys() {
	if (sdlEvent.type == SDL_KEYDOWN) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_SPACE:
				controlKeys[0] = true;
				break;
			case SDLK_ESCAPE:
				controlKeys[1] = true;
				break;
			case SDLK_RETURN:
				controlKeys[2] = true;
				break;
			case SDLK_BACKSPACE:
				controlKeys[3] = true;
				break;
			case SDLK_RCTRL: case SDLK_LCTRL:
				controlKeys[4] = true;
				break;
			case SDLK_RSHIFT: case SDLK_LSHIFT:
				controlKeys[5] = true;
				break;
		}
	}
	if (sdlEvent.type == SDL_KEYUP) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_SPACE:
				controlKeys[0] = false;
				break;
			case SDLK_ESCAPE:
				controlKeys[1] = false;
				break;
			case SDLK_RETURN:
				controlKeys[2] = false;
				break;
			case SDLK_BACKSPACE:
				controlKeys[3] = false;
				break;
			case SDLK_RCTRL: case SDLK_LCTRL:
				controlKeys[4] = false;
				break;
			case SDLK_RSHIFT: case SDLK_LSHIFT:
				controlKeys[5] = false;
				break;

		}
	}
}

void UserInput::test_numberKeys() {
	if (sdlEvent.type == SDL_KEYDOWN) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_0:
				num[0] = true;
				break;
			case SDLK_1:
				num[1] = true;
				break;
			case SDLK_2:
				num[2] = true;
				break;
			case SDLK_3:
				num[3] = true;
				break;
			case SDLK_4:
				num[4] = true;
				break;
			case SDLK_5:
				num[5] = true;
				break;
			case SDLK_6:
				num[6] = true;
				break;
			case SDLK_7:
				num[7] = true;
				break;
			case SDLK_8:
				num[8] = true;
				break;
			case SDLK_9:
				num[9] = true;
				break;
		}
	}

	if (sdlEvent.type == SDL_KEYUP) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_0:
				num[0] = false;
				break;
			case SDLK_1:
				num[1] = false;
				break;
			case SDLK_2:
				num[2] = false;
				break;
			case SDLK_3:
				num[3] = false;
				break;
			case SDLK_4:
				num[4] = false;
				break;
			case SDLK_5:
				num[5] = false;
				break;
			case SDLK_6:
				num[6] = false;
				break;
			case SDLK_7:
				num[7] = false;
				break;
			case SDLK_8:
				num[8] = false;
				break;
			case SDLK_9:
				num[9] = false;
				break;
		}
	}
}

//====================================================================================================================================
// Used to test when a key is just pressed
//====================================================================================================================================

void UserInput::testPressed_letters() {
	static bool previous_letter[26];

	// Keydown
	if (sdlEvent.type == SDL_KEYDOWN) {
		switch( sdlEvent.key.keysym.sym ) {
			case 'a': case 'A':
				if (previous_letter[0] == false)
					pressed_letter[0] = true;
				previous_letter[0] = true;
				break;
			case 'b': case 'B':
				if (previous_letter[1] == false)
					pressed_letter[1] = true;
				previous_letter[1] = true;
				break;
			case 'c': case 'C':
				if (previous_letter[2] == false)
					pressed_letter[2] = true;
				previous_letter[2] = true;
				break;
			case 'd': case 'D':
				if (previous_letter[3] == false)
					pressed_letter[3] = true;
				previous_letter[3] = true;
				break;
			case 'e': case 'E':
				if (previous_letter[4] == false)
					pressed_letter[4] = true;
				previous_letter[4] = true;
				break;
			case 'f': case 'F':
				if (previous_letter[5] == false)
					pressed_letter[5] = true;
				previous_letter[5] = true;
				break;
			case 'g': case 'G':
				if (previous_letter[6] == false)
					pressed_letter[6] = true;
				previous_letter[6] = true;
				break;
			case 'h': case 'H':
				if (previous_letter[7] == false)
					pressed_letter[7] = true;
				previous_letter[7] = true;
				break;
			case 'i': case 'I':
				if (previous_letter[8] == false)
					pressed_letter[8] = true;
				previous_letter[8] = true;
				break;
			case 'j': case 'J':
				if (previous_letter[9] == false)
					pressed_letter[9] = true;
				previous_letter[9] = true;
				break;
			case 'k': case 'K':
				if (previous_letter[10] == false)
					pressed_letter[10] = true;
				previous_letter[10] = true;
				break;
			case 'l': case 'L':
				if (previous_letter[11] == false)
					pressed_letter[11] = true;
				previous_letter[11] = true;
				break;
			case 'm': case 'M':
				if (previous_letter[12] == false)
					pressed_letter[12] = true;
				previous_letter[12] = true;
				break;
			case 'n': case 'N':
				if (previous_letter[13] == false)
					pressed_letter[13] = true;
				previous_letter[13] = true;
				break;
			case 'o': case 'O':
				if (previous_letter[14] == false)
					pressed_letter[14] = true;
				previous_letter[14] = true;
				break;
			case 'p': case 'P':
				if (previous_letter[15] == false)
					pressed_letter[15] = true;
				previous_letter[15] = true;
				break;
			case 'q': case 'Q':
				if (previous_letter[16] == false)
					pressed_letter[16] = true;
				previous_letter[16] = true;
				break;
			case 'r': case 'R':
				if (previous_letter[17] == false)
					pressed_letter[17] = true;
				previous_letter[17] = true;
				break;
			case 's': case 'S':
				if (previous_letter[18] == false)
					pressed_letter[18] = true;
				previous_letter[18] = true;
				break;
			case 't': case 'T':
				if (previous_letter[19] == false)
					pressed_letter[19] = true;
				previous_letter[19] = true;
				break;
			case 'u': case 'U':
				if (previous_letter[20] == false)
					pressed_letter[20] = true;
				previous_letter[20] = true;
				break;
			case 'v': case 'V':
				if (previous_letter[21] == false)
					pressed_letter[21] = true;
				previous_letter[21] = true;
				break;
			case 'w': case 'W':
				if (previous_letter[22] == false)
					pressed_letter[22] = true;
				previous_letter[22] = true;
				break;
			case 'x': case 'X':
				if (previous_letter[23] == false)
					pressed_letter[23] = true;
				previous_letter[23] = true;
				break;
			case 'y': case 'Y':
				if (previous_letter[24] == false)
					pressed_letter[24] = true;
				previous_letter[24] = true;
				break;
			case 'z': case 'Z':
				if (previous_letter[25] == false)
					pressed_letter[25] = true;
				previous_letter[25] = true;
				break;
			default:
				break;
		}
	}
	// Key Released
	if (sdlEvent.type == SDL_KEYUP) {
		switch( sdlEvent.key.keysym.sym ) {
			case 'a': case 'A':
				previous_letter[0] = false;
				break;
			case 'b': case 'B':
				previous_letter[1] = false;
				break;
			case 'c': case 'C':
				previous_letter[2] = false;
				break;
			case 'd': case 'D':
				previous_letter[3] = false;
				break;
			case 'e': case 'E':
				previous_letter[4] = false;
				break;
			case 'f': case 'F':
				previous_letter[5] = false;
				break;
			case 'g': case 'G':
				previous_letter[6] = false;
				break;
			case 'h': case 'H':
				previous_letter[7] = false;
				break;
			case 'i': case 'I':
				previous_letter[8] = false;
				break;
			case 'j': case 'J':
				previous_letter[9] = false;
				break;
			case 'k': case 'K':
				previous_letter[10] = false;
				break;
			case 'l': case 'L':
				previous_letter[11] = false;
				break;
			case 'm': case 'M':
				previous_letter[12] = false;
				break;
			case 'n': case 'N':
				previous_letter[13] = false;
				break;
			case 'o': case 'O':
				previous_letter[14] = false;
				break;
			case 'p': case 'P':
				previous_letter[15] = false;
				break;
			case 'q': case 'Q':
				previous_letter[16] = false;
				break;
			case 'r': case 'R':
				previous_letter[17] = false;
				break;
			case 's': case 'S':
				previous_letter[18] = false;
				break;
			case 't': case 'T':
				previous_letter[19] = false;
				break;
			case 'u': case 'U':
				previous_letter[20] = false;
				break;
			case 'v': case 'V':
				previous_letter[21] = false;
				break;
			case 'w': case 'W':
				previous_letter[22] = false;
				break;
			case 'x': case 'X':
				previous_letter[23] = false;
				break;
			case 'y': case 'Y':
				previous_letter[24] = false;
				break;
			case 'z': case 'Z':
				previous_letter[25] = false;
				break;
			default:
				break;
		}
	}
}

void UserInput::testPressed_arrowKeys() {
	// This is what the arrow keys were the last frame, and is used to work out if the key has just been pressed or not
	static bool previous_arrowKeys[4];

	// Key pressed
	if (sdlEvent.type == SDL_KEYDOWN) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_UP:
				if (previous_arrowKeys[0] == false)
					pressed_arrowKeys[0] = true;
				previous_arrowKeys[0] = true;
				break;
			case SDLK_RIGHT:
				if (previous_arrowKeys[1] == false)
					pressed_arrowKeys[1] = true;
				previous_arrowKeys[1] = true;
				break;
			case SDLK_DOWN:
				if (previous_arrowKeys[2] == false)
					pressed_arrowKeys[2] = true;
				previous_arrowKeys[2] = true;
				break;
			case SDLK_LEFT:
				if (previous_arrowKeys[3] == false)
					pressed_arrowKeys[3] = true;
				previous_arrowKeys[3] = true;
		}
	}
	
	// Key released
	if (sdlEvent.type == SDL_KEYUP) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_UP:
				previous_arrowKeys[0] = false;
				break;
			case SDLK_RIGHT:
				previous_arrowKeys[1] = false;
				break;
			case SDLK_DOWN:
				previous_arrowKeys[2] = false;
				break;
			case SDLK_LEFT:
				previous_arrowKeys[3] = false;
				break;
		}
	}
}

void UserInput::testPressed_controlKeys() {
	// Used to store the state of the control keys in the last frame (pressed or not pressed)
	static bool previous_controlKeys[6];
	
	// Key pressed
	if (sdlEvent.type == SDL_KEYDOWN) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_SPACE:
				if (previous_controlKeys[0] == false)
					pressed_controlKeys[0] = true;
				previous_controlKeys[0] = true;
				break;
			case SDLK_ESCAPE:
				if (previous_controlKeys[1] == false)
					pressed_controlKeys[1] = true;
				previous_controlKeys[1] = true;
				break;
			case SDLK_RETURN:
				if (previous_controlKeys[2] == false)
					pressed_controlKeys[2] = true;
				previous_controlKeys[2] = true;
				break;
			case SDLK_BACKSPACE:
				if (previous_controlKeys[3] == false)
					pressed_controlKeys[3] = true;
				previous_controlKeys[3] = true;
				break;
			case SDLK_RCTRL: case SDLK_LCTRL:
				if ( previous_controlKeys[4] == false )
					pressed_controlKeys[4] = true;
				previous_controlKeys[4] = true;
				break;
			case SDLK_RSHIFT: case SDLK_LSHIFT:
				if ( previous_controlKeys[5] == false )
					pressed_controlKeys[5] = true;
				previous_controlKeys[5] = true;
				break;
		}
	}

	// Key released
	if (sdlEvent.type == SDL_KEYUP) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_SPACE:
				previous_controlKeys[0] = false;
				break;
			case SDLK_ESCAPE:
				previous_controlKeys[1] = false;
				break;
			case SDLK_RETURN:
				previous_controlKeys[2] = false;
				break;
			case SDLK_BACKSPACE:
				previous_controlKeys[3] = false;
				break;
			case SDLK_RCTRL: case SDLK_LCTRL:
				previous_controlKeys[4] = false;
				break;
			case SDLK_RSHIFT: case SDLK_LSHIFT:
				previous_controlKeys[5];
				break;
		}
	}
}

void UserInput::testPressed_numberKeys() {
	static bool previous_num[10];
	
	// Key pressed
	if (sdlEvent.type == SDL_KEYDOWN) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_0:
				if (previous_num[0] == false)
					pressed_num[0] = true;
				previous_num[0] = true;
				break;
			case SDLK_1:
				if (previous_num[1] == false)
					pressed_num[1] = true;
				previous_num[1] = true;
				break;
			case SDLK_2:
				if (previous_num[2] == false)
					pressed_num[2] = true;
				previous_num[2] = true;
				break;
			case SDLK_3:
				if (previous_num[3] == false)
					pressed_num[3] = true;
				previous_num[3] = true;
				break;
			case SDLK_4:
				if (previous_num[4] == false)
					pressed_num[4] = true;
				previous_num[4] = true;
				break;
			case SDLK_5:
				if (previous_num[5] == false)
					pressed_num[5] = true;
				previous_num[5] = true;
				break;
			case SDLK_6:
				if (previous_num[6] == false)
					pressed_num[6] = true;
				previous_num[6] = true;
				break;
			case SDLK_7:
				if (previous_num[7] == false)
					pressed_num[7] = true;
				previous_num[7] = true;
				break;
			case SDLK_8:
				if (previous_num[8] == false)
					pressed_num[8] = true;
				previous_num[8] = true;
				break;
			case SDLK_9:
				if (previous_num[9] == false)
					pressed_num[9] = true;
				previous_num[9] = true;
				break;
		}
	}

	// Key released
	if (sdlEvent.type == SDL_KEYUP) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_0:
				previous_num[0] = false;
				break;
			case SDLK_1:
				previous_num[1] = false;
				break;
			case SDLK_2:
				previous_num[2] = false;
				break;
			case SDLK_3:
				previous_num[3] = false;
				break;
			case SDLK_4:
				previous_num[4] = false;
				break;
			case SDLK_5:
				previous_num[5] = false;
				break;
			case SDLK_6:
				previous_num[6] = false;
				break;
			case SDLK_7:
				previous_num[7] = false;
				break;
			case SDLK_8:
				previous_num[8] = false;
				break;
			case SDLK_9:
				previous_num[9] = false;
				break;
		}
	}
}