#pragma once
#include <memory>
#include "../Entity/Entity.h"

const enum SystemType {
	SYSTEM_TYPE_NONE = 0,
	SYSTEM_TYPE_INPUT,
	SYSTEM_TYPE_ANIMATION,
	SYSTEM_TYPE_COLLISION,
	SYSTEM_TYPE_MOVEMENT,
	SYSTEM_TYPE_PHYSIC
};

class System {
	public:
		SystemType type;
		virtual void update(const std::vector<std::shared_ptr<Entity>>& entities);
		System();
};