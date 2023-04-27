#pragma once
#include "general.h"
namespace Rocker
{
	class Feature
	{
	private:
		bool enabled;
		bool registeredEnabled;
		std::string name;
		std::vector<ModuleHandle*> modules;
		void* SHAREDDATA;

	public:
		void SetEnabled(bool _enabled) { enabled = _enabled; }
		void SetName(std::string _name) { name = _name; }
		std::string GetName() { return name; }
		bool IsActive() { return enabled; }

		void RegisterModule(ModuleHandle* _module);
		void RegisterSharedData(void* _SHAREDDATA) { SHAREDDATA = _SHAREDDATA; };
		bool SetDefaultModule(ModuleHandle* _module);
		bool SetDefaultModule(std::string _moduleName);

		HMODULE DefaultModule();
		void ActivateEdge();

		virtual void ActivateFeature() {};
		virtual void OnActivate() {};
		virtual void OnDeactivate() {};
		virtual void OnUpdate() {};
		virtual void OnDetatch() {};
	};
}