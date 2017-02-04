#pragma once

#include <SDL\SDL.h>
#include <iostream>

	class UserInput {
		private:
			// If key is held
			bool letter[26];
			bool num[10];
			bool arrowKeys[4];
			bool controlKeys[6];

			// If key is pressed
			bool pressed_letter[26];
			bool pressed_num[10];
			bool pressed_arrowKeys[4];
			bool pressed_controlKeys[6];

			// The cross for the window
			bool windowCross;

			// Register's SDL events
			SDL_Event sdlEvent;

			// For testing whether key is held
			void test_letters();
			void test_arrowKeys();
			void test_controlKeys();
			void test_numberKeys();

			// For testing whether a key is pressed
			void testPressed_letters();
			void testPressed_arrowKeys();
			void testPressed_controlKeys();
			void testPressed_numberKeys();

		public:
			// The constructor
			UserInput(){ }

			// The destructor
			~UserInput() { std::cout << std::endl << "Deleting: User Input Class"; }

			// For testing keyboard input
			// Tests whether every key has been pressed or held down
			void test();

			// Returns true if the cross has been pressed on the window
			bool cross() { return windowCross; }

			// Arrow Keys

			bool arrowUp() { return arrowKeys[0]; }
			bool arrowRight() { return arrowKeys[1]; }
			bool arrowDown() { return arrowKeys[2]; }
			bool arrowLeft() { return arrowKeys[3]; }
			
			bool pressed_arrowUp() { return pressed_arrowKeys[0]; }
			bool pressed_arrowRight() { return pressed_arrowKeys[1]; }
			bool pressed_arrowDown() { return pressed_arrowKeys[2]; }
			bool pressed_arrowLeft() { return pressed_arrowKeys[3]; }

			// Control Keys

			bool spacebar() { return controlKeys[0]; }
			bool escape() { return controlKeys[1]; }
			bool returnKey() { return controlKeys[2]; }
			bool backSpace() { return controlKeys[3]; }
			bool ctrl() { return controlKeys[4]; }
			bool shift() { return controlKeys[5]; }

			bool pressed_spacebar() { return pressed_controlKeys[0]; }
			bool pressed_escape() { return pressed_controlKeys[1]; }
			bool pressed_returnKey() { return pressed_controlKeys[2]; }
			bool pressed_backSpace() { return pressed_controlKeys[3]; }
			bool pressed_ctrl() { return pressed_controlKeys[4]; }
			bool pressed_shift() { return controlKeys[5]; }

			// Numbers

			bool zero() { return num[0]; }
			bool one() { return num[1]; }
			bool two() { return num[2]; }
			bool three() { return num[3]; }
			bool four() { return num[4]; }
			bool five() { return num[5]; }
			bool six() { return num[6]; }
			bool seven() { return num[7]; }
			bool eight() { return num[8]; }
			bool nine() { return num[9]; }

			bool pressed_zero() { return pressed_num[0]; }
			bool pressed_one() { return pressed_num[1]; }
			bool pressed_two() { return pressed_num[2]; }
			bool pressed_three() { return pressed_num[3]; }
			bool pressed_four() { return pressed_num[4]; }
			bool pressed_five() { return pressed_num[5]; }
			bool pressed_six() { return pressed_num[6]; }
			bool pressed_seven() { return pressed_num[7]; }
			bool pressed_eight() { return pressed_num[8]; }
			bool pressed_nine() { return pressed_num[9]; }

			// Letters

			bool a() { return letter[0]; }
			bool b() { return letter[1]; }
			bool c() { return letter[2]; }
			bool d() { return letter[3]; }
			bool e() { return letter[4]; }
			bool f() { return letter[5]; }
			bool g() { return letter[6]; }
			bool h() { return letter[7]; }
			bool i() { return letter[8]; }
			bool j() { return letter[9]; }
			bool k() { return letter[10]; }
			bool l() { return letter[11]; }
			bool m() { return letter[12]; }
			bool n() { return letter[13]; }
			bool o() { return letter[14]; }
			bool p() { return letter[15]; }
			bool q() { return letter[16]; }
			bool r() { return letter[17]; }
			bool s() { return letter[18]; }
			bool t() { return letter[19]; }
			bool u() { return letter[20]; }
			bool v() { return letter[21]; }
			bool w() { return letter[22]; }
			bool x() { return letter[23]; }
			bool y() { return letter[24]; }
			bool z() { return letter[25]; }

			bool pressed_a() { return pressed_letter[0]; }
			bool pressed_b() { return pressed_letter[1]; }
			bool pressed_c() { return pressed_letter[2]; }
			bool pressed_d() { return pressed_letter[3]; }
			bool pressed_e() { return pressed_letter[4]; }
			bool pressed_f() { return pressed_letter[5]; }
			bool pressed_g() { return pressed_letter[6]; }
			bool pressed_h() { return pressed_letter[7]; }
			bool pressed_i() { return pressed_letter[8]; }
			bool pressed_j() { return pressed_letter[9]; }
			bool pressed_k() { return pressed_letter[10]; }
			bool pressed_l() { return pressed_letter[11]; }
			bool pressed_m() { return pressed_letter[12]; }
			bool pressed_n() { return pressed_letter[13]; }
			bool pressed_o() { return pressed_letter[14]; }
			bool pressed_p() { return pressed_letter[15]; }
			bool pressed_q() { return pressed_letter[16]; }
			bool pressed_r() { return pressed_letter[17]; }
			bool pressed_s() { return pressed_letter[18]; }
			bool pressed_t() { return pressed_letter[19]; }
			bool pressed_u() { return pressed_letter[20]; }
			bool pressed_v() { return pressed_letter[21]; }
			bool pressed_w() { return pressed_letter[22]; }
			bool pressed_x() { return pressed_letter[23]; }
			bool pressed_y() { return pressed_letter[24]; }
			bool pressed_z() { return pressed_letter[25]; }
	};