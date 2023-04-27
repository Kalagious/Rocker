#pragma once
#include "framework.h"
#include <vector>
#include <iostream>
#include <string>
#include <Windows.h>

namespace Rocker
{
	struct ModuleHandle
	{
		std::string name;
		HMODULE	handle;
	};
}