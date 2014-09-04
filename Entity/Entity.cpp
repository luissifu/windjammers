#include "Entity.h"

Entity::Entity() {
	type = ENTITY_TYPE_NONE;
	compNum = 0;
}

bool Entity::addComponent(std::shared_ptr<Component> c) {
	if (compNum == MAX_COMPONENTS)
	{
		return false;
	}

	components.push_back(c);
	compNum++;

	return true;
}

std::shared_ptr<Component> Entity::getComponent(int index) {
	return components[index];
}

int Entity::hasComponent(ComponentType type) {
	for (int i = 0; i < compNum; i++)
	{
		if (components[i]->type == type)
			return i;
	}
	return -1;
}