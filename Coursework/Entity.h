#pragma once

#include <iostream>
#include "Model.h"

const float DEG_TO_RADIAN = 0.017453293f;


	class Entity {
		private:
			std::string type;
			glm::vec3 pos, scale, rotation;
			glm::vec3 maskPos, maskSize;
			rt3d::materialStruct material;
			Model *model, *mask;
			float speed;
			bool drawMask;

		public:
			// Default Constructor
			Entity() {}
			Entity( std::string type, glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation, rt3d::materialStruct material )
				: type(type), pos(pos), scale(scale), maskSize(scale), rotation(rotation),
				  maskPos( glm::vec3( 0.0f, 0.0f, 0.0f ) ),
				  speed(0), material(material), drawMask(false) {}

			// Move the object based on the inputted x, y and z
			void translate( float x, float y, float z ) { pos.x+=x; pos.y+=y; pos.z+=z; }
			void translate( glm::vec3 pos ) { this->pos += pos; }

			// Set the scale of the object
			void setScale( glm::vec3 scale ) { this->scale = scale; }

			// Rotate the object
			void rotate( float xrotation, float yrotation, float zrotation ) { rotation.x = xrotation; rotation.y = yrotation; rotation.z = zrotation; }
			void rotate( glm::vec3 rotation ) { this->rotation += rotation; }

			// Set the position of the object's mask
			void setMaskPosition( float x, float y, float z ) { maskPos.x = x; maskPos.y = y; maskPos.z = z; }
			void setMaskPosition( glm::vec3 maskPos ) { this->maskPos = maskPos; }

			void moveForward() { translate( glm::vec3( speed*sin( DEG_TO_RADIAN*(getZRotation()+90) ), 0.0f, speed*cos( DEG_TO_RADIAN*(getZRotation()+90) ) ) ); }
			void moveBack() { translate( glm::vec3( speed*sin( DEG_TO_RADIAN*(getZRotation()+270) ), 0.0f, speed*cos( DEG_TO_RADIAN*(getZRotation()+270) ) ) ); }
			void moveRight() { translate( glm::vec3( speed*sin( DEG_TO_RADIAN*(getZRotation()) ), 0.0f, speed*cos( DEG_TO_RADIAN*(getZRotation()) ) ) ); }
			void moveLeft() { translate( glm::vec3( speed*sin( DEG_TO_RADIAN*(getZRotation()+180) ), 0.0f, speed*cos( DEG_TO_RADIAN*(getZRotation()+180) ) ) ); }

			void setDrawMask( bool drawMask) { this->drawMask = drawMask; }

			// Set the size of the collision mask
			// ( This will usually be the same size as the scale, with the exception of some characters )
			void setMaskSize( glm::vec3 maskSize ) { this->maskSize = maskSize; }

			// Set the material of the object
			void setMaterial( rt3d::materialStruct material ) { this->material = material; }

			void setSpeed( float speed ) { this->speed = speed; }
			float getSpeed() { return speed; }

			// Create the model
			void createModel( int type, char* modelName, const char* texture );

			// Render the model
			void render(GameContext *gameContext);

			// Get Positions
			glm::vec3 getPos() { return pos; }
			float getXPos() { return pos.x; }
			float getYPos() { return pos.y; }
			float getZPos() { return pos.z; }

			// Get scale
			glm::vec3 getScale() { return scale; }
			float getXScale() { return scale.x; }
			float getYScale() { return scale.y; }
			float getZScale() { return scale.z; }

			// Get rotation
			glm::vec3 getRotation() { return rotation; }
			float getXRotation() { return rotation.x; }
			float getYRotation() { return rotation.y; }
			float getZRotation() { return rotation.z; }

			// Get the mask coordinates
			glm::vec3 getMaskPos() { return maskPos; }
			float getXMaskPos() { return maskPos.x; }
			float getYMaskPos() { return maskPos.y; }
			float getZMaskPos() { return maskPos.z; }

			// Get the mask size
			glm::vec3 getMaskSize() { return maskSize; }
			float getXMaskSize() { return maskSize.x; }
			float getYMaskSize() { return maskSize.y; }
			float getZMaskSize() { return maskSize.z; }

			// Collision detection
			bool collision( Entity* o );
			bool upCollision( Entity* o );
			bool downCollision( Entity* o );
			bool leftCollision( Entity* o );
			bool rightCollision( Entity* o );

			// Delete the object
			~Entity() { std::cout << '\n' << "Deleting Entity"; }
	};