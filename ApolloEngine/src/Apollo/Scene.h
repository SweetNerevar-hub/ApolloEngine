#pragma once

namespace Apollo::Scene
{
	class Scene
	{
	public:
		virtual ~Scene() = default;

		virtual void start() = 0;
		virtual void handleEvents() = 0;
		virtual void update() = 0;
		virtual void render() = 0;

		virtual void pause() = 0;
		virtual void resume() = 0;
	};
}