#pragma once

#include <Apollo.h>

class SCollision : public Apollo::ECS::System
{
public:
	void update(Apollo::ECS::Entities& entities) override;

private:
	static void updateColliders(Apollo::ECS::Entity e);
};