#pragma once

#include <PotatoEngine/Collections/SortedVector.h>
#include <PotatoEngine/Core/Plugin.h>

namespace potato
{
	class Plugin;

	struct PluginPriorityComparator
	{
		bool operator() (const Plugin* lhs, const Plugin* rhs) const
		{
			return lhs->getPriority() < rhs->getPriority();
		}
	};

	class POTATOENGINE_EXPORT Engine
	{
	public:

		void init() {}
		void cleanup() {}

		void addPlugin(Plugin& plugin);
		void removePlugin(Plugin& plugin);

	private:

		SortedVector<Plugin*, PluginPriorityComparator> m_plugins;
	};
}