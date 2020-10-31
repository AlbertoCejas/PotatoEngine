#include <PotatoEngine/Core/Engine.h>


namespace potato
{
	void Engine::addPlugin(Plugin& plugin)
	{
		m_plugins.push(&plugin);
	}

	void Engine::removePlugin(Plugin& plugin)
	{
		m_plugins.erase(&plugin);
	}
}