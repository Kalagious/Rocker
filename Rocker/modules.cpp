#include "application.h"


namespace Rocker
{
	void Application::AddModule(std::string moduleName)
	{
		for (Application::ModuleHandle module : Application::modules)
		{
			if (module.name == moduleName)
				return;
		}
		modules.push_back(ModuleHandle{ moduleName, GetModuleHandle(moduleName.c_str()) });
	}


	HMODULE Application::GetModule(std::string moduleName)
	{
		for (Application::ModuleHandle module : Application::modules)
		{
			if (module.name == moduleName)
				return module.handle;
		}
		return nullptr;
	}



}