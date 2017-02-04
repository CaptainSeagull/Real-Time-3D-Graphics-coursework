#pragma once

#include "UserInput.h"
#include <SDL\SDL.h>
#include <GL\glew.h>
#include <GLM\glm.hpp>

// Used to convert degrees to radians when
//const float DEG_TO_RADIAN = 0.017453293f;
	class AbstractState;

	class GameContext {
		private:
			SDL_Window *hWindow;		// Window handle
			SDL_GLContext glContext;	// OpenGL context handle
			

			AbstractState* currentState;
			AbstractState* play;


			// Private methods

			SDL_Window *setupRC(SDL_GLContext &context);

			// Render the game
			void render();

		public:
			GLuint defaultShaderProgram, skyboxShaderProgram;
			UserInput *userInput;
			glm::mat4 viewMatrix, projectionMatrix;

			GameContext() { }
			void init();

			void switchShader(GLuint shaderHandle);

			~GameContext();

			void run();

	};