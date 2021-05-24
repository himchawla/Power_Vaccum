#include "audioManager.h"
#include <iostream>
audioManager* audioManager::sm_Instance = 0;
audioManager::~audioManager()
{
	if (m_Music != nullptr)
	{
		delete m_Music;
		m_Music = 0;
	}

	std::map<std::string, sound>::iterator it = m_Sounds.begin();
	while (it != m_Sounds.end())
	{
		if ((*it).second.sound != nullptr)
		{
			delete (*it).second.sound;
			(*it).second.sound = nullptr;
		}
		if ((*it).second.buffer != nullptr)
		{
			delete (*it).second.buffer;
			(*it).second.buffer = nullptr;
		}
		it = m_Sounds.erase((it));
	}
}
/***********************
* GetInstance: Returns instance of audioManager.
* @author: William de Beer
* @return: audioManager instance
********************/
audioManager& audioManager::GetInstance()
{
	if (sm_Instance == 0)
	{
		sm_Instance = new audioManager();
		sm_Instance->Initialise();
	}
	return *sm_Instance;
}

/***********************
* RemoveInstance: Deletes current instance of audioManager.
* @author: William de Beer
********************/
void audioManager::RemoveInstance()
{
	if (sm_Instance != 0)
	{
		delete sm_Instance;
		sm_Instance = 0;
	}
}

void audioManager::Initialise()
{
	m_Music = new sf::Music();
	CreateSound("RoombaCollision", "RoombaCollision.wav");
}

void audioManager::PlaySound(std::string _key)
{
	std::map<std::string, sound>::iterator it = m_Sounds.find(_key);
	if (it != m_Sounds.end())
	{
		it->second.sound->play();
	}
	else
	{
		std::cout << "Cannot find audio named '" << _key << "'.\n";
	}
}

void audioManager::SetMusic(std::string _fileName)
{
	std::string fileLocation = "Assets/Audio/Music/" + _fileName;
	if (!m_Music->openFromFile(fileLocation))
	{
		std::cout << "Failed to open music at location: '" << fileLocation << "'.\n";
	}
}

void audioManager::CreateSound(std::string _key, std::string _fileName)
{
	if (m_Sounds.find(_key) != m_Sounds.end())
	{
		std::cout << "Audio already exists under key named '" << _key << "'.\n";
		return;
	}

	std::pair<std::string, sound> newSound;
	newSound.first = _key;
	newSound.second.buffer = new sf::SoundBuffer();
	std::string fileLocation = "Assets/Audio/SoundEffect/" + _fileName;
	if (!newSound.second.buffer->loadFromFile(fileLocation))
	{
		std::cout << "Failed to load sound at location: '" << fileLocation << "'.\n";
		delete newSound.second.buffer;
		newSound.second.buffer = 0;
		return;
	}
	newSound.second.sound = new sf::Sound();
	newSound.second.sound->setBuffer(*(newSound.second.buffer));
	m_Sounds.insert(newSound);
}


