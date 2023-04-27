#include "application.h"


namespace Rocker
{
	Application* Application::GetApplication() // Create a function to return the instance of a 
	{
		if (!applicationInstance)
			applicationInstance = new Application();
		return applicationInstance;
	}

	void Application::SetConsole(bool _enabled)
	{
		if (_enabled && !consoleEnabled)
		{
			AllocConsole();
			freopen_s(&f, "CONOUT$", "w", stdout);
			consoleEnabled = true;
		}
		else if (!_enabled && consoleEnabled)
		{
			FreeConsole();
			consoleEnabled = false;
		}
	}

	void Application::Attach(void (*_preRun)())
	{
		Logger::Log("Starting\n");
		SHAREDDATA = nullptr;
		modules.clear();
		features.clear();
		consoleEnabled = false;
		_preRun();
		Logger::Log("Attached Application\n");
		alive = true;
	}

	void Application::Start()
	{
		while (alive)
			Update();
		Detatch();
	}

	void Application::Detatch()
	{
		Logger::Log("Stopping\n");
		for (Feature* feature : features)
		{
			feature->OnDetatch();
			delete(feature);
		}

		for (ModuleHandle* module : modules)
			delete(module);

		Logger::Log("Detatched Application\n");
	}

	void Application::Update()
	{
		for (Feature* feature : features)
		{
			feature->ActivateFeature();
			feature->ActivateEdge();
			feature->OnUpdate();
		}
	}
	
	bool Application::RegisterFeature(Feature* _feature)
	{
		for (Feature* feature : features)
		{
			if (feature == _feature)
			{
				Logger::Log("Feature " + _feature->GetName() + " Already Registered\n");
				return true;
			}
		}

		if (!SHAREDDATA)
		{
			Logger::Error("SHAREDDATA Has Not Been Created Yet, Unable to Register Features\n");
			return false;
		}

		_feature->RegisterSharedData(SHAREDDATA);
		features.push_back(_feature);
		return true;
	}
}