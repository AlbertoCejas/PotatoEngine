#pragma once

#include <queue>

#include <PotatoEngine/Core/Plugin.h>

namespace potato
{
	class POTATOENGINE_EXPORT Engine
	{
	public:

		// ...

	private:

		std::priority_queue<Plugin> m_plugins;
	};
}