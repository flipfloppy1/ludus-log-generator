#pragma once

#include <iostream>
#include <string>

namespace LLG // Ludus Log Generator!!1!11!
{
	static std::string prevLog = "";
	static int logRepeats = 0;
	enum class LogType
	{
		UI,
		RENDERER,
		PHYSICS,
		SERVER,
		BEHAVIOUR,
		OPENGL,
		JSON,
		AUDIO
	};
	inline const char* GetType(LogType type)
	{
		switch (type)
		{
		case LogType::UI:
			return "UI";
		case LogType::RENDERER:
			return "Renderer";
		case LogType::PHYSICS:
			return "Physics";
		case LogType::SERVER:
			return "Server";
		case LogType::BEHAVIOUR:
			return "Behaviour";
		case LogType::OPENGL:
			return "OpenGL";
		case LogType::JSON:
			return "JSON";
		case LogType::AUDIO:
			return "AUDIO";
		}

		return "Type Undefined";
	};

	enum class LogSeverity
	{
		INFO,
		WARNING,
		MINOR_ERROR,
		MAJOR_ERROR,
		FATAL_ERROR
	};
	inline const char* GetSeverity(LogSeverity severity)
	{
		switch (severity)
		{
		case LogSeverity::INFO:
			return "Info";
		case LogSeverity::WARNING:
			return "Warning";
		case LogSeverity::MINOR_ERROR:
			return "Minor Error";
		case LogSeverity::MAJOR_ERROR:
			return "Major Error";
		case LogSeverity::FATAL_ERROR:
			return "FATAL Error";
		}

		return "Severity Undefined";
	};
	void inline Log(LogType type, LogSeverity severity, const char* message)
	{
		if (prevLog == message)
		{
			logRepeats++;
			std::cout << "LLG " << GetSeverity(LogSeverity::INFO) << "|" << GetType(type) << ": \"" << "Message repeating..." << logRepeats << "\"\r";
			return;
		}
		prevLog = message;
		if (logRepeats != 0)
		{
			std::cout << "LLG " << GetSeverity(LogSeverity::INFO) << "| Message repeated " << logRepeats << " times.\n";
		}
		logRepeats = 0;
		std::cout << "LLG " << GetSeverity(severity) << "|" << GetType(type) << ": \"" << message << "\"\n";
	};
};