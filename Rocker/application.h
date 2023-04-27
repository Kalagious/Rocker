#pragma once
#include "general.h"
#include "feature.h"
#include "logger.h"

namespace Rocker
{
	class Application
	{

	// ------------------------- SINGLETON --------------------------------
	protected:
		Application() {}
		static Application* applicationInstance;

	public:
		Application(Application& other) = delete;
		void operator=(const Application&) = delete;
		Application* GetApplication();


	// ------------------------- MODULES ---------------------------------
	private:
		std::vector <ModuleHandle> modules;

	public:
		void AddModule(std::string _moduleName);
		HMODULE GetModule(std::string _moduleName);



	// ------------------------- CONSOLE ---------------------------------
	private:
		FILE* f;
		bool consoleEnabled;

	public:
		void SetConsole(bool _enabled);

	
	// ------------------------- FEATURES ---------------------------------
	private:
		std::vector<Feature*> features;

	public:
		void RegisterFeature(Feature* _feature);


	// ------------------------- VISUALS ---------------------------------
	private:
		
	public:

	
	// ------------------------- GENERAL ---------------------------------
	private:


	public:
		void Attach();
		void Detatch();
		void Update();

	};
}