#pragma once
#include <vector>
#include <memory>
#include "../Component/Component.h"
#include "../Constants.h"

enum EntityType {
	ENTITY_TYPE_NONE = 0,
	ENTITY_TYPE_GUI_ITEM,
	ENTITY_TYPE_PLAYER,
	ENTITY_TYPE_ENEMY
};

class Entity {
	public:
		EntityType type;
		bool addComponent(std::shared_ptr<Component> c);
		int hasComponent(ComponentType type);
		std::shared_ptr<Component> getComponent(int index);
		Entity();
	private:
		int compNum;
		std::vector<std::shared_ptr<Component>> components;
};