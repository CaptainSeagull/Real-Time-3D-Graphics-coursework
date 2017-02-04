#include "Entity.h"

void Entity::createModel( int type, char *modelName, const char* texture ) {
	// Create character mesh
	model = new Model ( glm::vec3( pos.x, pos.y, pos.y ), glm::vec3( this->scale.x, this->scale.y, this->scale.z ), glm::vec3( rotation.x, rotation.y, rotation.z ) );
	model->init( type, modelName );
	model->setTexture( rt3d::loadBitmap( texture ) );
	model->setMaterial( material );

	// Create mask
	if ( drawMask == true ) {
		mask = new Model ( glm::vec3( pos.x+maskPos.x, pos.y+maskPos.y, pos.z+maskPos.z ), glm::vec3( this->maskSize.x, this->maskSize.y, this->maskSize.z ), glm::vec3( 0.0f, 0.0f, 0.0f ) );
		mask->init( ModelType::OBJ, "Models/cube.obj" );
		mask->setTexture( rt3d::loadBitmap( "Textures/black.bmp" ) );
		mask->setMaterial( material );
	}
}

void Entity::render(GameContext *gameContext) {
	model->setPos( pos );
	model->setRotate( rotation );
	model->render(gameContext);

	if ( drawMask == true ) {
		mask->setPos( pos+maskPos );
		mask->render(gameContext);
	}
}

bool Entity::collision( Entity* o ) {
	float x1, y1, z1, x2, y2, z2;

	x1 = pos.x + maskPos.x;// + nextX;
	y1 = pos.y + maskPos.y;// + nextY;
	z1 = pos.z + maskPos.z;// + nextZ;

	x2 = o->getXPos() + o->getXMaskPos();
	y2 = o->getYPos() + o->getYMaskPos();
	z2 = o->getZPos() + o->getZMaskPos();

	if ( ( x1 - o->getXScale() <= x2) && ( x1 >= x2 - o->getXScale() ) )
		if ( ( y1 - o->getYScale() <= y2) && ( y1 >= y2 - o->getYScale() ) )
			if ( ( z1 - o->getZScale() <= z2) && ( z1 >= z2 - o->getZScale() ) )
				return true;
		
	return false;
}

bool Entity::upCollision( Entity* o ) {
	float nextX, nextY, nextZ;
	float x1, y1, z1, x2, y2, z2;

	// Get this entity's coordinates
	nextX = speed*sin( 0.017453293f*(rotation.z+90) );
	nextY = 0.0f;
	nextZ = speed*cos( 0.017453293f*(rotation.z+90) );
	
	x1 = pos.x + maskPos.x + nextX;
	y1 = pos.y + maskPos.y + nextY;
	z1 = pos.z + maskPos.z + nextZ;

	// Get the paramater entities coordinates
	nextX = o->getSpeed()*sin( 0.017453293f*(o->getZRotation()+90) );
	nextY = 0.0f;
	nextZ = o->getSpeed()*cos( 0.017453293f*(o->getZRotation()+90) );

	x2 = o->getXPos() + o->getXMaskPos();
	y2 = o->getYPos() + o->getYMaskPos();
	z2 = o->getZPos() + o->getZMaskPos();

	// Test a collision between them
	if ( ( x1 - o->getXScale() <= x2) && ( x1 >= x2 - o->getXScale() ) )
		if ( ( y1 - o->getYScale() <= y2) && ( y1 >= y2 - o->getYScale() ) )
			if ( ( z1 - o->getZScale() <= z2) && ( z1 >= z2 - o->getZScale() ) )
				return true;
		
	return false;
}
bool Entity::downCollision( Entity* o ) {
	float nextX, nextY, nextZ;
	float x1, y1, z1, x2, y2, z2;

	// Get this entity's coordinates
	nextX = speed*sin( 0.017453293f*(rotation.z-90) );
	nextY = 0.0f;
	nextZ = speed*cos( 0.017453293f*(rotation.z-90) );
	
	x1 = pos.x + maskPos.x + nextX;
	y1 = pos.y + maskPos.y + nextY;
	z1 = pos.z + maskPos.z + nextZ;

	// Get the paramater entities coordinates
	nextX = o->getSpeed()*sin( 0.017453293f*(o->getZRotation()-90) );
	nextY = 0.0f;
	nextZ = o->getSpeed()*cos( 0.017453293f*(o->getZRotation()-90) );

	x2 = o->getXPos() + o->getXMaskPos();
	y2 = o->getYPos() + o->getYMaskPos();
	z2 = o->getZPos() + o->getZMaskPos();

	// Test a collision between them
	if ( ( x1 - o->getXScale() <= x2) && ( x1 >= x2 - o->getXScale() ) )
		if ( ( y1 - o->getYScale() <= y2) && ( y1 >= y2 - o->getYScale() ) )
			if ( ( z1 - o->getZScale() <= z2) && ( z1 >= z2 - o->getZScale() ) )
				return true;
		
	return false;
}
bool Entity::leftCollision( Entity* o ) {
	float nextX, nextY, nextZ;
	float x1, y1, z1, x2, y2, z2;

	// Get this entity's coordinates
	nextX = speed*sin( 0.017453293f*(rotation.z+180) );
	nextY = 0.0f;
	nextZ = speed*cos( 0.017453293f*(rotation.z+180) );
	
	x1 = pos.x + maskPos.x + nextX;
	y1 = pos.y + maskPos.y + nextY;
	z1 = pos.z + maskPos.z + nextZ;

	// Get the paramater entities coordinates
	nextX = o->getSpeed()*sin( 0.017453293f*(o->getZRotation()+1800) );
	nextY = 0.0f;
	nextZ = o->getSpeed()*cos( 0.017453293f*(o->getZRotation()+180) );

	x2 = o->getXPos() + o->getXMaskPos();
	y2 = o->getYPos() + o->getYMaskPos();
	z2 = o->getZPos() + o->getZMaskPos();

	// Test a collision between them
	if ( ( x1 - o->getXScale() <= x2) && ( x1 >= x2 - o->getXScale() ) )
		if ( ( y1 - o->getYScale() <= y2) && ( y1 >= y2 - o->getYScale() ) )
			if ( ( z1 - o->getZScale() <= z2) && ( z1 >= z2 - o->getZScale() ) )
				return true;
		
	return false;
}
bool Entity::rightCollision( Entity* o ) {
	float nextX, nextY, nextZ;
	float x1, y1, z1, x2, y2, z2;

	// Get this entity's coordinates
	nextX = speed*sin( 0.017453293f*(rotation.z) );
	nextY = 0.0f;
	nextZ = speed*cos( 0.017453293f*(rotation.z) );
	
	x1 = pos.x + maskPos.x + nextX;
	y1 = pos.y + maskPos.y + nextY;
	z1 = pos.z + maskPos.z + nextZ;

	// Get the paramater entities coordinates
	nextX = o->getSpeed()*sin( 0.017453293f*(o->getZRotation()) );
	nextY = 0.0f;
	nextZ = o->getSpeed()*cos( 0.017453293f*(o->getZRotation()) );

	x2 = o->getXPos() + o->getXMaskPos();
	y2 = o->getYPos() + o->getYMaskPos();
	z2 = o->getZPos() + o->getZMaskPos();

	// Test a collision between them
	if ( ( x1 - o->getXScale() <= x2) && ( x1 >= x2 - o->getXScale() ) )
		if ( ( y1 - o->getYScale() <= y2) && ( y1 >= y2 - o->getYScale() ) )
			if ( ( z1 - o->getZScale() <= z2) && ( z1 >= z2 - o->getZScale() ) )
				return true;
		
	return false;
}