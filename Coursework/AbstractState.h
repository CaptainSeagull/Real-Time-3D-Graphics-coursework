#pragma once
#include "GameContext.h"

	class AbstractState {
		public:
			AbstractState(GameContext *gameContext) { }
			virtual ~AbstractState() { }

			virtual void init() = 0;
			virtual void run() = 0;
			virtual void render() = 0;
	};

