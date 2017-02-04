#include "City.h"
#include "rt3d.h"

void City::loadBuilding( rt3d::materialStruct defaultMat, glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation ) {
	// Block
	buildings.push_back( new Entity		(
											"Block",
											glm::vec3( pos ),
											glm::vec3( scale ),
											glm::vec3( rotation ),
											defaultMat
										)
						);
	//buildings.back()->setDrawMask( true );
	buildings.back()->createModel( ModelType::OBJ, "Models/cube.obj", "Textures/studdedmetal.bmp" );
}

void City::render( GameContext *gameContext ) {
	for ( unsigned int i=0; i<buildings.size(); i++ )
		buildings.at(i)->render( gameContext );
}

bool City::collision( Entity* o ) {
	for ( int i=0; i<buildings.size(); i++ )
		if ( buildings[i]->collision( o ) == true )
			return true;

	return false;
}

bool City::upCollision( Entity* o ) {
	for ( int i=0; i<buildings.size(); i++ )
		if ( o->upCollision( buildings[i] ) == true )
			return true;

	return false;
}
bool City::downCollision( Entity* o ) {
	for ( int i=0; i<buildings.size(); i++ )
		if ( o->downCollision( buildings[i] ) == true )
			return true;

	return false;
}
bool City::leftCollision( Entity* o ) {
	for ( int i=0; i<buildings.size(); i++ )
		if ( o->leftCollision( buildings[i] ) == true )
			return true;

	return false;
}
bool City::rightCollision( Entity* o ) {
	for ( int i=0; i<buildings.size(); i++ )
		if ( o->rightCollision( buildings[i] ) == true )
			return true;

	return false;
}

/*
#include "City.h"
#include "Utils.h"
#include "MaterialLoader.h"

using namespace std;

City::City() {
	buildings = new vector<Entity*>();
}

bool City::loadCity(const char * filename) {
	fstream stream (filename);

	if( !stream.is_open() ) {
		std::cout << '\n' << "City Error: " << "File Not Opened";
		return false;
	}

	while( !stream.eof() ) {
		// Check if the line is a comment
		char peek = stream.peek();
		if( peek != '#' && peek != '\n' && peek != ' ' && peek != '\r' && peek != -1 ) {
			// Load a building if it is not a comment
			loadBuilding(stream);

		} else {
			// Ignore line if it is a comment
			string temp;
			getline(stream, temp);
		}
	}

	return true;
}

bool City::loadCity(fstream &stream) {
	return true;
}

bool City::loadBuilding(const char * filename) {
	return true;
}

bool City::loadBuilding(fstream &stream) {
	bool endOfBuilding = false;
	Entity *newModel = new Entity(); // Create the model which will be added to the vector of buildings.
	string line;
	
	// Will keep going through the stream until the building has been loaded. 
	while( !endOfBuilding ) {
		getline(stream, line); //Get the current line of the file. 
		
		// If the line isn't a comment.
		if( line[0] != '#' ) {
			string word = line.substr( 0, line.find_first_of(' ') ); // Get a substring of the line, everything before the first occurence of a space

			// If the substring is going to be a directory of the file to be loaded.
			if( word.compare("file") == 0 ) {
				string file = line.substr(line.find_first_of(' ') + 1);
				//newModel->init(ModelType::OBJ, file.c_str());

			// if the substring is a list of numbers describing the position
			} else if( word.compare("pos") == 0 ) {
				string vertices = line.substr(line.find_first_of(' ') + 1);
				glm::vec3 position = Utils::stringToVector(vertices);
				newModel->setPos( position );
			

			// if the substring is a list of numbers describing the scale.
			} else if(word.compare("scale") == 0) {
				string vertices = line.substr(line.find_first_of(' ') + 1);
				glm::vec3 scale = Utils::stringToVector(vertices);
				newModel->setScale(scale);


			// if the substring is a list of numbers describing the rotation.
			} else if(word.compare("rotation") == 0) {
				string vertices = line.substr(line.find_first_of(' ') + 1);
				glm::vec3 rotation = Utils::stringToVector(vertices);
				newModel->rotate(rotation);
			

			//if the substring is directory of a material file.
			//} else if(word.compare("material") == 0) {
			//	string material = line.substr(line.find_first_of(' ') + 1);
			//	newModel->setMaterial(MaterialLoader::loadMaterial(material.c_str()));
			
			//if the substring is a directory to a texture file.
			} else if ( word.compare("texture") == 0 ) {
				string texture = line.substr( line.find_first_of(' ') + 1 );
				//newModel->createModel( rt3d::loadBitmap(texture.c_str()) );
				newModel->createModel( ModelType::OBJ, "Models/cube.obj", "Textures/studdedmetal.bmp" );
			
			//if the substring is the end of the building
			} else if( word.compare("end") == 0 ) {
				buildings->push_back(newModel);
				endOfBuilding = true;
			}
		}
	}

	return true;
}

void City::render(GLuint shaderProgram, glm::mat4 viewMat) {
	for ( unsigned int i=0; i<buildings->size(); i++ )
		buildings->at(i)->render( shaderProgram, viewMat );
}

bool City::collisionDetected(const BoundingBox &box) {
	return false;
}
*/