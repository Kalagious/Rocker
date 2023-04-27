#pragma once
#include "general.h"

namespace Rocker
{
	class Logger
	{
	private:
		Logger() { LogMethod = DefaultLoggingMethod; enabled = true; }
		bool enabled;

		static void (*LogMethod)(std::string);
		static void DefaultLoggingMethod(std::string _logData) { printf(_logData.c_str()); }
		static Logger* loggerInstance;
		static Logger* CreateLogger();

	public:
		static bool Log(std::string _logData);
		static void SetLogMethod(void (*logMethodPtr)(std::string)) { CreateLogger(); LogMethod = logMethodPtr; }
		void SetEnabled(bool _enabled);
	};
}