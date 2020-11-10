#include <PotatoEngine/Core/Plugin.h>

#include <PotatoEngine/Util/Assert.h>

namespace potato
{
	Plugin::Plugin(const char* name, int priority) :
		m_name(name),
		m_priority(priority)
	{
		POTATO_ASSERT_MSG(name != nullptr, "Plugin name is nullptr");
		POTATO_ASSERT_MSG(priority >= 0, "Priority must be a positive number");
	}
}