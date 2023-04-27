#include "application.h"


namespace Rocker
{
	void Application::AddModule(std::string moduleName) // Add a new module handle to the list
	{
		for (ModuleHandle* module : modules)
		{
			if (module->name == moduleName)
				return;
		}
		modules.push_back(new ModuleHandle{ moduleName, GetModuleHandle(moduleName.c_str()) });
		Logger::Log("Added New Module [" + moduleName + "]\n");
	}


	HMODULE Application::GetModule(std::string moduleName) // Check if a module handle is valid in the list and return it if it is
	{
		for (ModuleHandle* module : modules)
		{
			if (module->name == moduleName)
				return module->handle;
		}
		return nullptr;
	}



}