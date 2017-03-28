#include "ResourceManager.h"
#include <iostream>
#include <map>


ResourceManager::ResourceManager() : textureFile(), soundFile(), musicFile(), resourceDirectories()
{
}


ResourceManager::~ResourceManager()
{
	textureFile.clear();
	soundFile.clear();
	musicFile.clear();
	resourceDirectories.clear();
}

ResourceManager::ResourceManager(const ResourceManager&)
{
}


//Checks to see if an Texture has already been loaded or if the Texture is im the correct directory, if so will throw an error. Else will load the Texture.

const sf::Texture & ResourceManager::getTexture(const std::string & filename)
{
	// Check whether the Texture alredy exists
	for (std::map<std::string, sf::Texture>::const_iterator it = textureFile.begin(); it != textureFile.end(); ++it)
	{
		if (filename == it->first) 
		{
			//Send error if Texture exists
			//std::cout << "DEBUG_MESSAGE: using existing texture.\n";
			return it->second;
		}
	}
	//Create object of Texture to load
	sf::Texture texture;
	//Search the projects main directory
	if (texture.loadFromFile(filename))
	{
		//Push loaded Texture onto image array
		textureFile[filename] = texture;
		printf("DEBUG_MESSAGE: %s loading texture.\n", filename.c_str());
		return textureFile[filename];
	}
	//If the textureFile isn't found then search all registered directories 
	for (auto it = resourceDirectories.begin(); it != resourceDirectories.end(); ++it) 
	{
		if (texture.loadFromFile((*it) + filename))
		{
			textureFile[filename] = texture;
			printf("DEBUG_MESSAGE: %s loading texture.", filename.c_str());
			return textureFile[filename];
		}
	}
	//Else, if Texture doens't load then error a failed image 
	printf("LOAD_ERROR: Texture was not found.\n");
	textureFile[filename] = texture;
	return textureFile[filename];
}

const sf::SoundBuffer & ResourceManager::getAudio(const std::string & filename)
{
	for (std::map<std::string, sf::SoundBuffer>::const_iterator it = soundFile.begin(); it != soundFile.end(); ++it)
	{
		if (filename == it->first)
		{
			//Send error if file is already loaded
			printf("DEBUG_MESSAGE: using existing audio file.\n");
			return it->second;
		}
	}
	//create object of soundbuffer to load into
	sf::SoundBuffer audio;
	//search main directory for file
	if(audio.loadFromFile(filename))
	{
		soundFile[filename] = audio;
		printf("DEBUG_MESSAGE: %s loading audio file.\n", filename.c_str());
		return soundFile[filename];
	}
	//Check additional directories for file if main directory doesn't have it
	for (auto it = resourceDirectories.begin(); it != resourceDirectories.end(); ++it)
	{
		if (audio.loadFromFile((*it) + filename))
		{
			soundFile[filename] = audio;
			printf("DEBUG_MESSAGE: %s loading audio file.\n", filename.c_str());
		}
	}
	//If file doesn't exist then Error
	printf("LOAD_ERROR: Audio file was not found.\n");
	soundFile[filename] = audio;
	return soundFile[filename];
}

sf::Music& ResourceManager::getMusic(const std::string & filename)
{
	for (std::map<std::string, std::unique_ptr<sf::Music>>::const_iterator it = musicFile.begin(); it != musicFile.end(); ++it)
	{
		if (filename == it->first)
		{
			//Send error if file is already loaded
			printf("DEBUG_MESSAGE: using existing music file.\n");
			return *it->second;
		}
	}
	//create object of music to load into
	std::unique_ptr<sf::Music> audio(new sf::Music());
	//search main directory for file
	if (audio->openFromFile(filename))
	{
		musicFile.emplace(filename, std::move(audio));
		//musicFile[filename] = std::move(audio);
		printf("DEBUG_MESSAGE: %s loading music file.\n", filename.c_str());
		return *musicFile.at(filename);
	}
	//Check additional directories for file if main directory doesn't have it
	for (auto it = resourceDirectories.begin(); it != resourceDirectories.end(); ++it)
	{
		if (audio->openFromFile((*it) + filename))
		{
			musicFile.emplace(filename, std::move(audio));
		//	musicFile.insert(filename, std::move(audio));
			printf("DEBUG_MESSAGE: %s loading music file.\n", filename.c_str());
		}
	}
	//If file doesn't exist then Error
	printf("LOAD_ERROR: Music file was not found.\n");
	musicFile[filename] = std::move(audio);
	return *musicFile.at(filename);
}

//Delete the sound using the filename
void ResourceManager::deleteSound(const std::string & filename)
{
	std::map<std::string, sf::SoundBuffer>::const_iterator it = soundFile.find(filename);
	if (it != soundFile.end())
	{
		soundFile.erase(it);
	}
}
//Delete the sound using the sf::soundBuffer address 
void ResourceManager::deleteSound(const sf::SoundBuffer & sound)
{
	for (std::map<std::string, sf::SoundBuffer>::const_iterator it = soundFile.begin(); it != soundFile.end(); ++it)
	{
		//compare the adresses
		if (&sound == &it->second)
		{
			soundFile.erase(it);
			return;
		}
	}
}

//Will delete an Texture based on sf::Texture address
void ResourceManager::deleteTexture(const sf::Texture & texture)
{
	for (std::map<std::string, sf::Texture>::const_iterator it = textureFile.begin(); it != textureFile.end(); ++it)
	{
		//compare the adresses
		if (&texture == &it->second)
		{
			textureFile.erase(it);
			return;
		}
	}
}
//Will delete an Texture based on string name
void ResourceManager::deleteTexture(const std::string & filename)
{
	std::map<std::string, sf::Texture>::const_iterator it = textureFile.find(filename);
	if (it != textureFile.end()) 
	{
		textureFile.erase(it);
	}
}
//Adds ability to add a directory for textureFile/media 
void ResourceManager::addResourceDirectory(const std::string & directory)
{
	//check whether the path to the directory exists
	for (std::vector<std::string>::const_iterator it = resourceDirectories.begin(); it != resourceDirectories.end(); ++it) 
	{
		//the path exists so we don't add a new path
		if (directory == (*it)) 
		{
			return;
		}
	}
	//the path is free and doesn not exists so create the directory
	resourceDirectories.push_back(directory);
}
//Adds ability to remove an unwanted directory
void ResourceManager::removeResourceDirectory(const std::string & directory)
{
	for (std::vector<std::string>::const_iterator it = resourceDirectories.begin(); it != resourceDirectories.end();) 
	{
		if (directory == (*it)) 
		{
			it = resourceDirectories.erase(it);
		}
		else 
		{
			++it;
		}
	}
}
