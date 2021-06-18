// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   audioManager.cpp
//  Description :   Loads and plays audio as a singleton.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <iostream>
 // Local Includes 
 // This Include 
#include "audioManager.h"
 // Static Variables 
audioManager* audioManager::sm_Instance = 0;
 // Static Function Prototypes 
 // Implementation 
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
		// Delete sound
		if ((*it).second.sound != nullptr)
		{
			delete (*it).second.sound;
			(*it).second.sound = nullptr;
		}
		// Delete buffer
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

/***********************
* Initialise: Initialises sounds.
* @author: William de Beer
********************/
void audioManager::Initialise()
{
	m_Music = new sf::Music();
	m_Music->setLoop(true);
	m_Music->setVolume(30.0f);

	// Initialise sounds
	CreateSound("RoombaCollision", "Collision.wav");				//This is for when the roombas collide
	CreateSound("NitroStart", "NitroStart.wav");					//This is for when the nitro starts
	CreateSound("NitroEnd", "NitroEnd.wav");						//This is for when the nitro ends
	CreateSound("RoombaDeath", "Death.wav");						//This is for when the roomba dies
	CreateSound("BatteryPickup", "Pickup.wav");						//This is for when you pickup a powerup
	CreateSound("ButtonPress", "Switch_Button.wav");				//This is for when a button is pressed
	CreateSound("ButtonChange", "Selected_Button.wav");				//This is for when a button is changed
	CreateSound("Explosion", "Explosion.wav");						//This is for when the leaking battery explodes
}

/***********************
* PlaySound: Plays the sound with the key passed in.
* @author: William de Beer
* @parameter: Key of sound to be played
********************/
void audioManager::PlaySound(std::string _key)
{
	std::map<std::string, sound>::iterator it = m_Sounds.find(_key);
	if (it != m_Sounds.end()) // Check if sound exists in map
	{
		it->second.sound->play(); // Play sound
	}
	else
	{
		std::cout << "Cannot find audio named '" << _key << "'.\n";
	}
}

/***********************
* SetMusic: Set music to be played based on filename.
* @author: William de Beer
* @parameter: File name
********************/
void audioManager::SetMusic(std::string _fileName)
{
	// Create file location string from name
	std::string fileLocation = "Assets/Audio/Music/" + _fileName;
	if (!m_Music->openFromFile(fileLocation))
	{
		std::cout << "Failed to open music at location: '" << fileLocation << "'.\n";
	}
}

/***********************
* CreateSound: Initialise a sound and add it to the map.
* @author: William de Beer
* @parameter: Map key, file name
********************/
void audioManager::CreateSound(std::string _key, std::string _fileName)
{
	if (m_Sounds.find(_key) != m_Sounds.end()) // Check if sound already exists in map.
	{
		std::cout << "Audio already exists under key named '" << _key << "'.\n";
		return;
	}

	std::pair<std::string, sound> newSound;
	newSound.first = _key; // Set key
	newSound.second.buffer = new sf::SoundBuffer(); // Create sound buffer
	std::string fileLocation = "Assets/Audio/SoundEffect/" + _fileName;
	if (!newSound.second.buffer->loadFromFile(fileLocation)) // Attempt to load sound into buffer
	{
		// If could not load sound into buffer, delete buffer and return
		std::cout << "Failed to load sound at location: '" << fileLocation << "'.\n";
		delete newSound.second.buffer;
		newSound.second.buffer = 0;
		return;
	}
	newSound.second.sound = new sf::Sound(); // Create sound
	newSound.second.sound->setBuffer(*(newSound.second.buffer)); // Set buffer to sound
	m_Sounds.insert(newSound); // Put pair into map
}