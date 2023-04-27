#pragma once
#include "general.h"

namespace Rocker
{
	class Logger
	{
	private:
		Logger() { LogMethod = DefaultLoggingMethod; ErrorMethod = DefaultErrorMethod;  enabled = true; }
		bool enabled;

		static void (*LogMethod)(std::string);
		static void (*ErrorMethod)(std::string);

		static void DefaultLoggingMethod(std::string _logData) { printf((" [*] "+_logData).c_str()); }
		static void DefaultErrorMethod(std::string _logData) { printf((" [!] " + _logData).c_str()); }

		static Logger* loggerInstance;
		static Logger* CreateLogger();

	public:
		static bool Log(std::string _logData);
		static bool Error(std::string _logData);

		static void SetLogMethod(void (*logMethodPtr)(std::string)) { CreateLogger(); LogMethod = logMethodPtr; }
		static void SetErrorMethod(void (*logMethodPtr)(std::string)) { CreateLogger(); LogMethod = logMethodPtr; }

		void SetEnabled(bool _enabled);
	};
}