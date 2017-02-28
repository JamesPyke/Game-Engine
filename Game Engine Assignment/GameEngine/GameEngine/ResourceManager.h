#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <map>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

private: 
	ResourceManager(const ResourceManager&);

public: 
	const sf::Texture& getTexture(const std::string& filename);
	const sf::SoundBuffer& getAudio(const std::string& filename);
	sf::Music& getMusic(const std::string& filename);

	void deleteSound(const std::string& filename);
	void deleteSound(const sf::SoundBuffer& sound);
	void deleteTexture(const sf::Texture& texture);
	void deleteTexture(const std::string & filename);

	void addResourceDirectory(const std::string& directory);
	void removeResourceDirectory(const std::string& directory);

private:
	std::map<std::string, sf::Texture> textureFile;
	std::map<std::string, sf::SoundBuffer> soundFile;
	std::map<std::string, std::unique_ptr<sf::Music>> musicFile;

	std::vector<std::string> resourceDirectories;
};

