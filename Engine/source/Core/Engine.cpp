#include <PotatoEngine/Core/Engine.h>


namespace potato
{
	void Engine::update()
	{
		for (Plugin* plugin : m_plugins)
		{
			plugin->update();
		}
	}

	void Engine::addPlugin(Plugin& plugin)
	{
		m_plugins.push(&plugin);
	}

	void Engine::removePlugin(Plugin& plugin)
	{
		m_plugins.erase(&plugin);
	}
}