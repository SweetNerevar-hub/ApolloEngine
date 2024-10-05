#include "pch.h"
#include "Math.h"

namespace Apollo::Utils
{
	int Math::randomRange(int min, int max)
	{
		if (min >= max)
		{
			std::cout << "Math: min param was greater than or equal to the max param!" << std::endl;
			return 0;
		}

		return min + rand() % (max - min + 1);
	}

	float Math::randomRange(float min, float max)
	{
		if (min >= max)
		{
			std::cout << "Math: min param was greater than or equal to the max param!" << std::endl;
			return 0.f;
		}

		float r = static_cast<float>(rand()) / RAND_MAX;
		return min + r * (max - min);
	}
}