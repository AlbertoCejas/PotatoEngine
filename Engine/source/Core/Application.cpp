#include <PotatoEngine/Core/Application.h>

#include <PotatoEngine/Util/Assert.h>

namespace potato
{
	Application::Application(const char* name) :
		m_name(name),
		m_shutdown(false)
	{
		POTATO_ASSERT_MSG(name != nullptr, "Application name is nullptr");
	}

	void Application::init()
	{
		m_engine.init();
	}

	void Application::update()
	{
		m_engine.update();
		updateImpl();
	}

	void Application::shutdown()
	{
		m_shutdown = true;
		m_engine.shutdown();
	}
}