#include "FileSystem.h"

#include <fstream>
#include <sstream>
#include <SDL.h>
#include <filesystem>

namespace nc
{
	void SetFilePath(const std::string& pathname)
	{
		std::filesystem::current_path(pathname);
	}

	std::string GetFilePath()
	{
		return std::filesystem::current_path().string();
	}

	bool ReadFileToString(const std::string& filename, std::string& filestring)
	{
		std::ifstream fileStream(filename, std::ios::in);
		if (!fileStream.is_open())
		{
			SDL_Log("Error: Failed to open file: %s", filename.c_str());
			return false;
		}

		std::stringstream stream;
		//<use rdbuf() on file stream to read file into string stream>
		stream << fileStream.rdbuf();

		//<use stream str() method to return stream string>
		filestring = stream.str();

		fileStream.close();

		return true;
	}

}
