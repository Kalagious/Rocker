#include "application.h"


namespace Rocker
{
	Application* Application::GetApplication() // Create a function to return the instance of a 
	{
		if (!applicationInstance)
			applicationInstance = new Application();

		return applicationInstance;
	}



}