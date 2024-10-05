#pragma once

#include "pch.h"

namespace Apollo::Utils
{
	class APOLLO_API Math
	{
	public:
		// Returns a random number between the min and max values
		static int randomRange(int min, int max);
		// Returns a random number between the min and max values
		static float randomRange(float min, float max);
	};
}