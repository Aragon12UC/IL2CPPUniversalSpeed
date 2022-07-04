// Omega172's Bad AllocConsole Singleton Wrapper
#pragma once

#include <Windows.h>
#include <iostream>

class Console
{
private:
	FILE* stdoutDummy = nullptr;
	FILE* stdinDummy = nullptr;
	BOOL allocated = FALSE;
	bool initalized = false;
	bool visible = true;
	void initalize();
	Console() {};

public:
	static Console& instance(bool visibility);
	BOOL alloc();
	BOOL free();
	void setVisibility(bool visibility);
	void toggleVisibility();
	bool getVisibility() { return this->visible; };
	void setTitle(std::string title) { SetConsoleTitle(title.c_str()); };
};
