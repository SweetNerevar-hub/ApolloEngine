#pragma once

namespace Apollo
{
	class Global
	{
	public:
		static Global& Instance()
		{
			static Global instance;
			return instance;
		}

		size_t maxEntities;

	private:
		Global() = default;
		Global(const Global&) = delete;
		Global& operator=(const Global&) = delete;
	};
}