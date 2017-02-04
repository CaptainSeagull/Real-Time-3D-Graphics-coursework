
#include "Entity.h"

	class City {
		private:
			std::vector <Entity*>  buildings;


		public:
			City() { }
			~City() { }

			void loadBuilding( rt3d::materialStruct defaultMat, glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation );
			void render( GameContext *gameContext );

			bool collision( Entity* o );

			bool upCollision( Entity* o );
			bool downCollision( Entity* o );
			bool leftCollision( Entity* o );
			bool rightCollision( Entity* o );
	};

/*
#pragma once
#include "Entity.h"
#include "BoundingBox.h"
#include <fstream>
#include <GLM\glm.hpp>

	class City {
		private:
			std::vector <Entity*> *buildings;
		public:
			City(void);
			bool loadCity(const char * filename);
			bool loadCity(std::fstream &stream);
			bool loadBuilding(const char * filename);
			bool loadBuilding(std::fstream &stream);
			void render(GLuint shaderProgram, glm::mat4 viewMat);
			bool collisionDetected(const BoundingBox &box);
			~City() { }
	};
*/

