#pragma once
#include <fstream>

int extern g_verbosity;

class LogManager
{
public:
	
	/**
	 * \brief Generates an enumerator of varied warning levels
	 */
	enum Verbosity
	{ Error,Warning,Info };

	/**
	 * \brief Create a new instance of the logger class
	 * \return Returns the new instance
	 */
	static LogManager *instance();
	/**
	 * \brief Create a log string to file
	 * \param message message 
	 */
	static void logString(std::string message);
	/**
	 * \brief Create a debug string to print to console
	 * \param format format 
	 * \param additional parameters  
	 * \return Returns the debug string
	 */
	int DebugPrintF(const char *format, ...);
	/**
	 * \brief Create a debug string using the variable warning levels
	 * \param verbosity verbosity 
	 * \param format format 
	 * \param additional parameters 
	 * \return Returns the debug string with warning level
	 */
	int VerboseDebugPrintF(int verbosity, const char* format, ...);
	/**
	 * \brief Write a debug string to a text file
	 * \param buffer buffer 
	 */
	static void WriteToFile(const std::string &buffer);

private:
	/**
	 * \brief Create a debug string using the variable warning levels
	 * \param format format 
	 * \param arglist arguement list 
	 * \return Returns the debug string with warning level
	 */
	static int VDebugPrintF(const char* format, va_list arglist);

	static LogManager *_instance;

};

