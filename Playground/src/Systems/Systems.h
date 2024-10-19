#pragma once

#include <Apollo.h>
#include "../Components/Components.h"

class SMovement : public Apollo::ECS::System
{
public:
	void update(Apollo::ECS::Entities& entities) override;
};

class SCollision : public Apollo::ECS::System
{
public:
	void update(Apollo::ECS::Entities& entities) override;

private:
	static void boundryCheck(Apollo::ECS::Entity e);
	static void updateColliders(Apollo::ECS::Entity e);
};