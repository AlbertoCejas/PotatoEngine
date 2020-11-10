#pragma once

#include <PotatoEngine/Collections/SortedVector.h>
#include <PotatoEngine/Core/Plugin.h>
#include <PotatoEngine/Export.h>

namespace potato
{
	class Plugin;

	struct POTATOENGINE_EXPORT PluginPriorityComparator
	{
		bool operator() (const Plugin* const lhs, const Plugin* const rhs) const
		{
			return lhs->getPriority() < rhs->getPriority();
		}
	};

	class POTATOENGINE_EXPORT Engine
	{
	public:

		void init() {}
		void shutdown() {}

		void update();

		void addPlugin(Plugin& plugin);
		void removePlugin(Plugin& plugin);

	private:

		SortedVector<Plugin*, PluginPriorityComparator> m_plugins;
	};
}