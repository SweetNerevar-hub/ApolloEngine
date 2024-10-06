#include "pch.h"
#include "SceneManager.h"

namespace Apollo::Scene
{
	void SceneManager::addScene(std::unique_ptr<Scene> newScene, bool isReplacing)
	{
		m_isReplacing = isReplacing;
		m_newScene = std::move(newScene);

		if (m_isReplacing)
		{
			m_scenes.pop();
		}

		else
		{
			m_scenes.top()->pause();
		}

		m_scenes.push(std::move(m_newScene));
		m_newScene->start();
	}

	void SceneManager::removeScene()
	{
		if (m_scenes.size() == 1)
		{
			// Can't remove the base scene
			return;
		}

		m_scenes.pop();
		m_scenes.top()->resume();
	}

	const std::unique_ptr<Scene>& SceneManager::getActiveScene() const
	{
		return m_scenes.top();
	}
}