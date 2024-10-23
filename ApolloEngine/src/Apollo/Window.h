#pragma once

namespace Apollo
{
	class APOLLO_API Window
	{
	public:
		sf::RenderWindow* window();
		const void setWindowSize(int newWidth, int newHeight);
		const void close();

		static const sf::Vector2i getWindowSize();
		static const void toggleFullscreen();
		static const void useVSync(bool enableVSync);

		Window(int height, int width, const std::string& title, int frameCap, bool fullscreen);

	private:
		inline static sf::RenderWindow* s_window = nullptr;
		inline static std::string s_title;
		inline static int s_frameCap;
		inline static int s_width;
		inline static int s_height;
		inline static bool s_isFullscreen = false;
		inline static bool s_useVSync = false;

		static void create();
	};
}