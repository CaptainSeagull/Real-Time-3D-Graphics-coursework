#include "PlayState.h"
#include "MaterialLoader.h"

void PlayState::init() {

	rt3d::materialStruct defaultMat = MaterialLoader::loadMaterial("Materials/DefaultMat.txt");
	rt3d::materialStruct transparentMat = MaterialLoader::loadMaterial("Materials/TransparentMat.txt");

	// The light
	rt3d::lightStruct light0 = {
		{0.2f, 0.2f, 0.2f, 1.0f},		// Ambient
		{0.8f, 0.8f, 0.8f, 1.0f},		// Diffuse
		{0.8f, 0.8f, 0.8f, 1.0f},		// Specular
		{0.0f, 10.0f, 0.0f, 1.0f}		// Position
	};
	
	// Initialise our 3rd person camera
	camera = nullptr;
	camera = new ThirdPersonCamera();

	// Test the camera was created properly
	if ( camera == nullptr )
		rt3d::exitFatalError( "Camera Failed To Initialize" );
	else
		std::cout << '\n' << "Camera Successfully Initialized";

	//Setup the sound manager and begin playing music.
	sound = new SoundManager();
	//sound->playMusic();

	// Setup the camera
	camera->setRadius(7);
	inclination = (float)M_PI/2.0f;
	azimuth = (float)M_PI;

	//Setup the skybox
	skybox = new Skybox();
	skybox->loadBackTexture("Textures/Skybox/back.jpg");
	skybox->loadFrontTexture("Textures/Skybox/front.jpg");
	skybox->loadLeftTexture("Textures/Skybox/left.jpg");
	skybox->loadRightTexture("Textures/Skybox/right.jpg");
	skybox->loadTopTexture("Textures/Skybox/top.jpg");

	// Create Yoshi
	character = new Entity	(
								"Player",
								glm::vec3( 0.0f, 1.0f, -4.0f ),
								glm::vec3( 0.05f, 0.05f, 0.05f ),
								glm::vec3( -90.0f, 0.0f, 0.0f ),
								defaultMat
							);
	character->setMaskPosition( glm::vec3( -1.0f, -1.0f, -1.0f ) );
	character->setMaskSize( glm::vec3( 2.0f, 2.0f, 2.0f ) );
	character->createModel( ModelType::MD2, "Models/yoshi.md2", "Textures/oyoshi.bmp" );
	character->setSpeed( 0.1f );

	// Base
	base = new Entity	(
							"Ground",
							glm::vec3( 0.0f, -0.5f, -4.0f ),
							glm::vec3( 20.0f, 0.1f, 20.0f ),
							glm::vec3( 1.0f ),
							defaultMat
						);
	base->createModel( ModelType::OBJ, "Models/cube.obj", "Textures/studdedmetal.bmp" );

	//Create the City
	city = new City();
	city->loadBuilding( defaultMat, glm::vec3( 5.0f, -0.5f, 10.0f ), glm::vec3( 2.0f, 10.0f, 2.0f ), glm::vec3( 1.0f ) );
	city->loadBuilding( defaultMat, glm::vec3( 15.0f, -0.5f, 11.0f ), glm::vec3( 6.0f, 10.0f, 4.0f ), glm::vec3( 1.0f ) );

	// Create the light
	lightPos = glm::vec4( 0.0f, 10.0f, 0.0f, 1.0f );
	rt3d::setLight( gameContext->defaultShaderProgram, light0);

	//Instantiate view matrix
	gameContext->viewMatrix = glm::mat4(1.0f);
	//Set up projection matrix
	gameContext->projectionMatrix = glm::perspective( 60.0f, 800.0f/600.0f, 1.0f, 50.0f);
}

void PlayState::run() {
	// How fast the character can move
	const float movementSpeed = 0.1f;

	UserInput * userInput = gameContext->userInput;

	gameContext->viewMatrix = camera->getViewMat(character->getPos());
	
	if ( userInput->arrowUp() == true )
		if ( city->upCollision( character ) == false )
			character->moveForward();
	if ( userInput->arrowDown() == true )
		if ( city->downCollision( character ) == false )
			character->moveBack();
	if ( userInput->arrowLeft() == true )
		if ( city->leftCollision( character ) == false )
			character->moveLeft();
	if ( userInput->arrowRight() == true )
		if ( city->rightCollision( character ) == false )
			character->moveRight();

	// Kyle's translation code
	//glm::vec4 translation = glm::vec4(0.0f);
	//if( userInput->a() == true ) translation.x += movementSpeed;
	//if( userInput->d() == true ) translation.x -= movementSpeed;
	//if( userInput->w() == true ) translation.z += movementSpeed;
	//if( userInput->s() == true ) translation.z -= movementSpeed;
	//translation = viewMat * translation;
	//character->translate(glm::vec3(translation));

	// Rotate Yoshi left and right
	// Also rotates the camera with Yoshi
	if ( userInput->z() == true ) {
		character->rotate( glm::vec3( 0.0f, 0.0f, 1.0f ) );
		inclination -= (float) M_PI/180.0f;
	}
	if ( userInput->x() == true ) {
		character->rotate( glm::vec3( 0.0f, 0.0f, -1.0f ) );
		inclination += (float) M_PI/180.0f;
	}

	// Set the camera
	camera->setAzimuth(azimuth);
	camera->setInclination(inclination);
}

void PlayState::render( ) {
	rt3d::setUniformMatrix4fv(gameContext->defaultShaderProgram, "projection", glm::value_ptr(gameContext->projectionMatrix) );

	skybox->render(gameContext);

	glm::vec4 lightPosMat = gameContext->viewMatrix * lightPos;
	rt3d::setLightPos(gameContext->defaultShaderProgram, glm::value_ptr(lightPosMat));


	character->render(gameContext);

	base->render(gameContext);

	city->render(gameContext);
}