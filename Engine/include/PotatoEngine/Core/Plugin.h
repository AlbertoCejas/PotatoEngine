#pragma once

#include <string>

#include <PotatoEngine/Util/Assert.h>

namespace potato
{
	class Plugin
	{
	public:

		Plugin(const char* name, int priority) :
			m_name(name),
			m_priority(priority) 
		{
			POTATO_ASSERT_MSG(name != nullptr, "Plugin name is nullptr");
			POTATO_ASSERT_MSG(priority >= 0, "Priority must be a positive number");
		}

		POTATO_EXPORT const char* getName() const { return m_name.c_str(); }
		POTATO_EXPORT int getPriority() const { return m_priority; }

		POTATO_EXPORT void setName(const char* name) { m_name = name; }

	private:

		std::string m_name;
		int8_t m_priority;
	};
}