#include "feature.h"
#include "logger.h"

namespace Rocker
{
	void Feature::ActivateEdge()
	{
		if (enabled && !registeredEnabled)
			OnActivate();

		if (!enabled && registeredEnabled)
			OnDeactivate();

		registeredEnabled = enabled;
	}

	void Feature::RegisterModule(ModuleHandle* _module)
	{
		for (ModuleHandle* module : modules)
		{
			if (_module == module)
				return;
		}

		modules.push_back(_module);
	}

	HMODULE Feature::DefaultModule()
	{
		if (modules.at(0))
			return modules.at(0)->handle;
		Logger::Log("No Default Module Was Set for " + name + " but One Was Asked for\n");
		return nullptr;
	}

	bool Feature::SetDefaultModule(ModuleHandle* _module)
	{
		bool exists = false;
		for (ModuleHandle* module : modules)
		{
			if (_module == module)
				exists = true;
		}

		if (!exists)
		{
			Logger::Error("Failed to Set Default Module for " + name + " as the Module Was Not Registered With the Feature\n");
			return false;
		}

		if (modules.at(0) != _module)
		{
			ModuleHandle* tmpModuleHandle = modules.at(0);
			modules.at(0) = _module;

			for (ModuleHandle* module : modules)
			{
				if (module == _module)
				{
					module = tmpModuleHandle;
					return true;
				}
			}
		}
		return true;
	}

	bool Feature::SetDefaultModule(std::string _moduleName)
	{
		bool exists = false;
		for (ModuleHandle* module : modules)
		{
			if (_moduleName == module->name)
				exists = true;
		}

		if (!exists)
		{
			Logger::Error("Failed to Set Default Module for " + name + " as the Module was not registered with the feature\n");
			return false;
		}

		if (modules.at(0)->name != _moduleName)
		{
			ModuleHandle* tmpModuleHandle = modules.at(0);

			for (ModuleHandle* module : modules)
			{
				if (module->name == _moduleName)
				{
					modules.at(0) = module;
					module = tmpModuleHandle;
					return true;
				}
			}
		}
		return true;
	}
}