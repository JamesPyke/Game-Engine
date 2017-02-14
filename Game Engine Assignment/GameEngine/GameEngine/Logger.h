#pragma once
#include <string>
#include <fstream>

int extern g_verbosity;

class Logger
{
public:
	
	enum Verbosity
	{ Error,Warning,Info };

	static Logger *instance();

public:
	void logString(std::string message);
	int DebugPrintF(const char *format, ...);
	int VerboseDebugPrintF(int verbosity, const char* format, ...);
	void WriteToFile(const std::string &buffer);

	

private:
	int VDebugPrintF(const char* format, va_list arglist);

	static Logger *_instance;

};

