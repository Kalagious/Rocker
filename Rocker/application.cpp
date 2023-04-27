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

	void Application::Attach()
	{
		modules.clear();
		features.clear();
		consoleEnabled = false;
		Logger::Log(" [*] Attached Application\n");
	}

	void Application::Detatch()
	{

		Logger::Log(" [*] Detatched Application\n");
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
}