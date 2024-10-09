#include "GameEvents.h"

using namespace Apollo::Event;
using namespace Apollo::ECS;

void OnPlayerCollision::process()
{
	if (m_other.getTag() == "Enemy")
	{
		// Call relevant system methods
	}

	else if (m_other.has<CVelocity>())
	{
		// Call relevant system methods
	}
}