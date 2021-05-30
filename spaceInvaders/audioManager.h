#ifndef __AUDIO_MANAGER_H__
#define __AUDIO_MANAGER_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   audioManager.h
//  Description :   Loads and plays audio as a singleton.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <map>
#include <SFML/Audio.hpp>
 // Local Includes 
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

struct sound 
{
	sf::SoundBuffer* buffer;
	sf::Sound* sound;
};

class audioManager
{
public:
	~audioManager();

	static audioManager& GetInstance();
	static void RemoveInstance();

	void PlaySound(std::string _key);
	void SetMusic(std::string _fileName);
	sf::Music* GetMusic() { return m_Music; };
private:
	audioManager() { m_Music = 0; };
	void Initialise();
	void CreateSound(std::string _key, std::string _fileName);

	static audioManager* sm_Instance;
	std::map<std::string, sound> m_Sounds;
	sf::Music* m_Music;
};

#endif