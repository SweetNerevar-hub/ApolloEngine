#pragma once

#include <Apollo.h>

class SMovement : public Apollo::ECS::System
{
public:
	void update(Apollo::ECS::Entities& entities) override;
};