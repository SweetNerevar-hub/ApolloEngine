#include "pch.h"
#include "Window.h"

namespace Apollo
{
	Window::Window(int width, int height, const std::string& title, int frameCap, bool fullscreen)
	{
		s_width = width;
		s_height = height;
		s_title = title;
		s_frameCap = frameCap;
		s_isFullscreen = fullscreen;
		create();
	}

	void Window::create()
	{
		auto style = (s_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);

		if (s_window == nullptr)
		{
			s_window = new sf::RenderWindow(sf::VideoMode(s_width, s_height), s_title, style);
			s_window->setVerticalSyncEnabled(s_useVSync);

			if (!s_useVSync)
			{
				s_window->setFramerateLimit(s_frameCap);
			}

			return;
		}
		
		s_window->create(sf::VideoMode(s_width, s_height), s_title, style);
		s_window->setVerticalSyncEnabled(s_useVSync);

		if (!s_useVSync)
		{
			s_window->setFramerateLimit(s_frameCap);
		}
	}

	sf::RenderWindow* Window::window()
	{
		return s_window;
	}

	const sf::Vector2i Window::getWindowSize()
	{
		return { s_width, s_height };
	}

	const void Window::setWindowSize(int newWidth, int newHeight)
	{
		s_width = newWidth;
		s_height = newHeight;
		create();
	}

	const void Window::toggleFullscreen()
	{
		s_isFullscreen = !s_isFullscreen;
		create();
	}

	const void Window::useVSync(bool enableVSync)
	{
		if (s_useVSync == enableVSync)
			return;

		s_useVSync = enableVSync;
		create();
	}

	const void Window::close()
	{
		s_window->close();
	}
}