#pragma once
#pragma once

#include <SDL\SDL.h>

// The timer class
	class Timer {
		private:
			// The clock time when the timer started
			int startTicks;

			// The FPS
			int frameRate;

			// Gets the timer's time
			// Essentialy returns the current time minus the start time
			int getTicks() { return SDL_GetTicks() - startTicks; }

		public:
			// Empty Constructor
			Timer( int frameRate )
				: frameRate( frameRate ) {}

			// Destructor
			~Timer() { }

			// Returns the frame rate
			int getFrameRate() { return frameRate; }

			// Used to start the clock counting
			// Should be called at the start of the loop
			// And saves the current clock time
			void start() { startTicks = SDL_GetTicks(); }

			// Should be called at the end of the loop
			// This calls SDL_Delay()
			// To limit the FPS based on the Frame Rate
			void end() { if ( getTicks() < 1000 / frameRate ) SDL_Delay( ( 1000 / frameRate ) - getTicks() ); }
	};