#pragma once

#include <PotatoEngine/Core/Engine.h>

namespace potato
{
	class POTATOENGINE_EXPORT Application
	{
	public:

		virtual void init();
		virtual void update() {}
		virtual void exit() {}
		virtual void exitNow() {}

	protected:

		Engine m_engine;
	};
}