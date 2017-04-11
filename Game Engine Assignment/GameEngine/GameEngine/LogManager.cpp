#include "LogManager.h"
#include "windows.h"
#include <iostream>

int g_verbosity;

LogManager * LogManager::_instance = nullptr;

LogManager * LogManager::instance()
{
	if (!_instance) 
	{
		_instance = new LogManager();
	}
	return _instance;
}

//std::fstream operator<<(const std::fstream& lhs, const std::string& cs);

void LogManager::logString(std::string message)
{
	std::fstream file("log.txt", std::ios::out | std::ios::app);
	//file << message << "\n";
	file.close();
}

int LogManager::DebugPrintF(const char * format, ...)
{
	va_list argList;
	va_start(argList, format);

	int charsWritten = VDebugPrintF(format, argList);

	va_end(argList);

	return charsWritten;
}

int LogManager::VerboseDebugPrintF(int verbosity, const char * format, ...)
{
	if (g_verbosity < verbosity)
		return 0;

	va_list argList;
	va_start(argList, format);

	int charsWritten = VDebugPrintF(format, argList);

	va_end(argList);

	return charsWritten;
}

void LogManager::WriteToFile(const std::string & buffer)
{
	FILE *logFile = nullptr;

	fopen_s(&logFile, "error.log", "a+");

	if (!logFile)
		return;

	fprintf_s(logFile, buffer.c_str());
	fclose(logFile);
}

int LogManager::VDebugPrintF(const char * format, va_list arglist)
{
	const unsigned int MAX_CHARS = 1024;
	static char s_buffer[MAX_CHARS];

	int charsWritten = vsnprintf(s_buffer, MAX_CHARS, format, arglist);

	OutputDebugStringA(s_buffer);

	return charsWritten;
}
