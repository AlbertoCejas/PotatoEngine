#pragma once

#include <string>

#include <PotatoEngine/Export.h>
#include <PotatoEngine/Util/Assert.h>

namespace potato
{
	class POTATOENGINE_EXPORT Plugin
	{
	public:

		Plugin(const char* name, int priority);
		virtual ~Plugin() = default;

		const char* getName() const { return m_name.c_str(); }
		int getPriority() const { return m_priority; }

		void setName(const char* name) { m_name = name; }

		virtual void update() = 0;

	private:

		std::string m_name;
		const int8_t m_priority;
	};
}