#pragma once

#include <string>

#include <PotatoEngine/Core/Engine.h>
#include <PotatoEngine/Export.h>

namespace potato
{
	class POTATOENGINE_EXPORT Application
	{
	public:

		explicit Application(const char* name);
		virtual ~Application() = default;

		virtual void init();
		void update();
		virtual void shutdown();

		bool isShuttingDown() const { return m_shutdown; }

	protected:

		virtual void updateImpl() = 0;

		const std::string m_name;
		Engine m_engine;
		bool m_shutdown;
	};
}