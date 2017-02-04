// Based loosly on the first triangle OpenGL tutorial
// http://www.opengl.org/wiki/Tutorial:_OpenGL_3.1_The_First_Triangle_%28C%2B%2B/Win%29
// This program will render two triangles
// Most of the OpenGL code for dealing with buffer objects, etc has been moved to a 
// utility library, to make creation and display of mesh objects as simple as possible

// Windows specific: Uncomment the following line to open a console window for debug output
#if _DEBUG
#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

#include "GameContext.h"
#include "rt3d.h"

int main(int argc, char *argv[]) {
	// Create the game class
	GameContext* gameContext = nullptr;
	gameContext = new GameContext();

	if ( gameContext == nullptr )
		rt3d::exitFatalError( "Game Context Failed To Be Created Properly" );

	gameContext->init();
	gameContext->run();
	delete gameContext;
	
	return 0;
}