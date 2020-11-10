#pragma once

#include <PotatoEngine/Core/Application.h>


class Editor;

class PotatoApp final : public potato::Application
{
	public:

		// Inherit constructors
		using potato::Application::Application;

		void init() final;

	private:

		void updateImpl() final;

		Editor* m_editor;
};