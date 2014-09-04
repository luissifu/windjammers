#pragma once
#include <vector>
#include "../Component/Components.h"

const int MAX_COMPONENTS = 10;

const enum EntityType {
	ENTITY_TYPE_NONE = 0,
	ENTITY_TYPE_GUI_ITEM,
	ENTITY_TYPE_PLAYER,
	ENTITY_TYPE_ENEMY
};

class Entity {
	public:
		EntityType type;
		bool addComponent(Component* c);
		int hasComponent(ComponentType type);
		Component* getComponent(int index);
		Entity();
	private:
		int compNum;
		std::vector<Component*> components;
};