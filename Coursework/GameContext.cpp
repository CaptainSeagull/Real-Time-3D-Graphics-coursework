#include "GameContext.h"
#include "PlayState.h"
#include "Timer.h"
#include "rt3d.h"
#include <iostream>
#include <GLM\gtc\type_ptr.hpp>

void GameContext::init() {
	// Create the window
	hWindow = nullptr;
	hWindow = setupRC(glContext); // Create window and render context 

	// Test window was created properly
	if ( hWindow == nullptr ) {
		std::cout << '\n' << "Error: Window Failed To Be Created";
		std::cout << '\n' << "Press Return to Quit";
		std::cin.get();
		exit(1);
	
	} else
		std::cout << '\n' << "Successfully Created: Window";


	// Required on Windows *only* init GLEW to access OpenGL beyond 1.1
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	// Test if glewInit() failed
	// If it did, something is seriously wrong
	if ( GLEW_OK != err ) {
		std::cout << "glewInit failed, aborting." << std::endl;
		std::cout << std::endl << "Press Return to Quit";
		std::cin.get();
		exit (1);
	
	} else {

		std::cout << '\n' << "Glew Successfully Initialized";
		std::cout << '\n' << glGetString(GL_VERSION) << std::endl;
	}

	// Enable OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	

	// Initialize the Phong shader
	skyboxShaderProgram = rt3d::initShaders("Shaders/textured.vert", "Shaders/textured.frag");
	defaultShaderProgram = rt3d::initShaders("Shaders/phong-tex.vert", "Shaders/phong-tex.frag");

	play = new PlayState(this);
	play->init();
	currentState = play;
}

// Set up rendering context
SDL_Window *GameContext::setupRC( SDL_GLContext &context ) {

	SDL_Window *window;

	// Intialize SDL
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
        rt3d::exitFatalError( "Unable to initialize SDL" ); 
	else
		std::cout << "SDL Successfully Initialized";
	 
    // Request an OpenGL 3.0 context.
    // Not able to use SDL to choose profile (yet), should default to core profile on 3.2 or later
	// If you request a context not supported by your drivers, no OpenGL context will be created
	
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE ); 

	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );  // double buffering on
	SDL_GL_SetAttribute( SDL_GL_MULTISAMPLEBUFFERS, 1 );
	SDL_GL_SetAttribute( SDL_GL_MULTISAMPLESAMPLES, 4 ); // Turn on x4 multisampling anti-aliasing (MSAA)

	SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 ); // 8 bit alpha buffering
 
    // Create a window
    window = SDL_CreateWindow	(	"RT3D Assessment",
									SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
									800, 600,
									SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
								);

	// Test the window was created properly
	if ( !window )
        rt3d::exitFatalError("Unable to create window");
 
    context = SDL_GL_CreateContext(window); // Create opengl context and attach to window
    SDL_GL_SetSwapInterval(1);				// Set swap buffers to sync with monitor's vertical refresh rate
	return window;
}

void GameContext::run() {
	// Set running to true
	bool running = true;

	// Create the timer class
	Timer* timer = nullptr;
	timer = new Timer( 60 );

	// Test the timer class was created properly
	if ( timer == nullptr )
		rt3d::exitFatalError( "Timer Class Failed To Be Created" );

	// Initialize the timer class
	std::cout << '\n' << "Timer Class Successfully Created. Frame Rate Set To: " << timer->getFrameRate() << " FPS";

	// Create the User Input class
	userInput = nullptr;
	userInput = new UserInput();

	if ( userInput == nullptr )
		rt3d::exitFatalError( "User Input Failed To Be Created" );
	else
		std::cout << '\n' << "User Input Class Initialized";

	std::cout << '\n' << "Entering Main Game Loop";
	// The main program loop
	while (running)	{
		timer->start();
			
			userInput->test();

			//update( userInput );
			currentState->run();
			render();

			if ( ( userInput->escape() == true ) || ( userInput->cross() == true ) )
				running = false;

		timer->end();
	}
	
	// Delete the timer and user input class after use
	delete play;
	delete timer;
	delete userInput;
}



void GameContext::render() {
	// clear the screen
	glClearColor(0.5f,0.5f,0.5f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	currentState->render();

	/*
	glm::vec4 lightPosMat = viewMat * lightPos;
	rt3d::setLightPos(shaderProgram, glm::value_ptr(lightPosMat));
	
	base->render(shaderProgram, viewMat);

	character->render(shaderProgram, viewMat);
	*/

    SDL_GL_SwapWindow(hWindow); // swap buffers
}

void GameContext::switchShader(GLuint shaderHandle)
{
	glUseProgram(shaderHandle);
	rt3d::setUniformMatrix4fv(shaderHandle, "projection", glm::value_ptr(projectionMatrix));
}

GameContext::~GameContext() {
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(hWindow);
    SDL_Quit();
}