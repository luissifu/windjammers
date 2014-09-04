#pragma once

const enum ComponentType {
	COMPONENT_TYPE_NONE = 0,
	COMPONENT_TYPE_INPUT,
	COMPONENT_TYPE_ANIMATION,
	COMPONENT_TYPE_COLLISION,
	COMPONENT_TYPE_MOVEMENT,
	COMPONENT_TYPE_PHYSIC
};

class Component {
	public:
		ComponentType type;
		Component();
};