#pragma once

#include "Scene.h"

namespace Apollo::Scene
{
	class SceneManager
	{
	public:
		SceneManager(SceneManager const&) = delete;
		SceneManager& operator= (SceneManager const) = delete;
		static SceneManager& sceneManager()
		{
			return Instance();
		}

		// Add a scene and open it
		// \param newScene: The new scene you wish to open
		// \param isReplacing: Whether not this new scene closes the current scene
		void addScene(std::unique_ptr<Scene> newScene, bool isReplacing);

		// Close current scene
		void removeScene();

		// Returns a reference to the current scene
		const std::unique_ptr<Scene>& getActiveScene() const;

	private:
		std::stack<std::unique_ptr<Scene>> m_scenes;
		std::unique_ptr<Scene> m_newScene;
		bool m_isReplacing = false;


		SceneManager();
		static SceneManager& Instance()
		{
			static SceneManager instance;
			return instance;
		}
	};
}