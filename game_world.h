
#pragma once

class GameObject;
#include "game_object_container.h"

class GameWorld
{
private:
	static constexpr int CONTAINER_CAPACITY{ 400 };
	GameObjectContainer m_container{ CONTAINER_CAPACITY };

public:
	void Register(GameObject* game_object);
	void Update(float delta_time);
	void Draw() const;
	GameObjectContainer GetGameObjects(Circle) const;
};
