#include "Logger.h"
#include "windows.h"

int g_verbosity;

Logger * Logger::_instance = NULL;

Logger * Logger::instance()
{
	if (!_instance) 
	{
		_instance = new Logger();
	}
	return _instance;
}

void Logger::logString(std::string message)
{
	std::fstream file("log.txt", std::ios::out | std::ios::app);
	file << message << "\n";
	file.close();
}

int Logger::DebugPrintF(const char * format, ...)
{
	va_list argList;
	va_start(argList, format);

	int charsWritten = VDebugPrintF(format, argList);

	va_end(argList);

	return charsWritten;
}

int Logger::VerboseDebugPrintF(int verbosity, const char * format, ...)
{
	if (g_verbosity < verbosity)
		return 0;

	va_list argList;
	va_start(argList, format);

	int charsWritten = VDebugPrintF(format, argList);

	va_end(argList);

	return charsWritten;
}

void Logger::WriteToFile(const std::string & buffer)
{
	FILE *logFile = NULL;

	fopen_s(&logFile, "error.log", "a+");

	if (!logFile)
		return;

	fprintf_s(logFile, buffer.c_str());
	fclose(logFile);
}

int Logger::VDebugPrintF(const char * format, va_list arglist)
{
	const unsigned int MAX_CHARS = 1024;
	static char s_buffer[MAX_CHARS];

	int charsWritten = vsnprintf(s_buffer, MAX_CHARS, format, arglist);

	OutputDebugStringA(s_buffer);

	return charsWritten;
}
