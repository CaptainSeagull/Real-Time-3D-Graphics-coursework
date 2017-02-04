#pragma once
#include "AbstractState.h"
#include "Skybox.h"
#include "Entity.h"
#include "SoundManager.h"
#include "ThirdPersonCamera.h"
#include "City.h"

	class PlayState: public AbstractState {
		private:
			rt3d::lightStruct light0;

			glm::vec4 lightPos;

			Skybox * skybox;
			Entity *character, *base;
			City *city;

			SoundManager * sound;
			ThirdPersonCamera *camera;
			float azimuth, inclination;

			GameContext *gameContext;

		public:
			PlayState(GameContext * gameContext) : AbstractState(gameContext), gameContext(gameContext) { }
			~PlayState() { }

			void init();

			void run();
			void render();
	};