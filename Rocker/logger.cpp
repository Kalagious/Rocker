#include "logger.h"


namespace Rocker
{
	bool Logger::Log(std::string _logData)
	{
		if (CreateLogger()->enabled)
		{
			CreateLogger()->LogMethod(_logData);
			return true;
		}
		else
			return false;
	}

	bool Logger::Error(std::string _logData)
	{
		if (CreateLogger()->enabled)
		{
			CreateLogger()->ErrorMethod(_logData);
			return true;
		}
		else
			return false;
	}

	Logger* Logger::CreateLogger()
	{
		if (!loggerInstance)
		{
			loggerInstance = new Logger();
		}

		return loggerInstance;
	}

	void Logger::SetEnabled(bool _enabled)
	{
		enabled = _enabled;
	}
}