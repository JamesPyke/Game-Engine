#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <map>

class ResourceManager
{
public:
	/**
	 * \brief Constructor of resource manager 
	 */
	ResourceManager();
	/**
	 * \brief deconstructor of resource manager
	 */
	~ResourceManager();

private: 

	ResourceManager(const ResourceManager&);

public: 
	/**
	 * \brief Pull a texture file
	 * \param filename filename 
	 * \return Returns texture
	 */
	const sf::Texture& getTexture(const std::string& filename);
	/**
	 * \brief Pull an audio file
	 * \param filename filename 
	 * \return Returns audio file
	 */
	const sf::SoundBuffer& getAudio(const std::string& filename);
	/**
	 * \brief Pull a music file
	 * \param filename filename 
	 * \return Returns music file
	 */
	sf::Music& getMusic(const std::string& filename);

	/**
	 * \brief Delete a loaded sound based on the name of the file
	 * \param filename filename 
	 */
	void deleteSound(const std::string& filename);
	/**
	 * \brief Delete a loaded sound based on the address of the file
	 * \param sound sound 
	 */
	void deleteSound(const sf::SoundBuffer& sound);
	/**
	 * \brief Delete a texture based on the address of the texture file
	 * \param texture texture 
	 */
	void deleteTexture(const sf::Texture& texture);
	/**
	 * \brief Delete a texture based on the file name
	 * \param filename filename 
	 */
	void deleteTexture(const std::string & filename);

	/**
	 * \brief Add a new directory for the external files
	 * \param directory directory 
	 */
	void addResourceDirectory(const std::string& directory);
	/**
	 * \brief Delete a user generated directory
	 * \param directory directory 
	 */
	void removeResourceDirectory(const std::string& directory);

private:
	/**
	 * \brief Create a map of textures
	 */
	std::map<std::string, sf::Texture> textureFile;
	/**
	 * \brief Create a map of sound files
	 */
	std::map<std::string, sf::SoundBuffer> soundFile;
	/**
	 * \brief Create a map of music files
	 */
	std::map<std::string, std::unique_ptr<sf::Music>> musicFile;

	/**
	 * \brief Create a vector string to store the names of the resource directories
	 */
	std::vector<std::string> resourceDirectories;
};

