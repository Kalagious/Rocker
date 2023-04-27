#pragma once
#include "pch.h"

namespace Rocker
{
	class Application
	{

	// ------------------------- Singleton --------------------------------
	protected:
		Application() {}
		static Application* applicationInstance;

	public:
		Application(Application& other) = delete;
		void operator=(const Application&) = delete;
		Application* GetApplication();


	// ------------------------- MODULES ---------------------------------
	private:
		struct ModuleHandle
		{
			std::string name;
			HMODULE	handle;
		};

		std::vector <ModuleHandle> modules;
	public:
		void AddModule(std::string moduleName);
		HMODULE GetModule(std::string moduleName);

	};
}