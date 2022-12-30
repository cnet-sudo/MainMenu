#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SFML/Graphics.hpp>
#include<map>

class AssetManager
{
public:
	AssetManager();

	static sf::Texture& GetTexture(std::string const& filename);

private:

	std::map<std::string, sf::Texture> m_Textures;

	// AssetManager является одноэлементным, поэтому одновременно можно работать с одним элементом
	//sInstacne содержит статический указатель на единственный экземпляр диспетчера
	static AssetManager* sInstance;
};

#endif