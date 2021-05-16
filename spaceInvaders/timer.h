#ifndef __TIMER_H__
#define __TIMER_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   timer.h
//  Description :   Timer class used for measuring intervals.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
class timer
{
public:
	timer(float _startTime, float _endTime);
	timer(float _from, float _to, bool _isCountDown);
	~timer();

	void Update(float _dT);
	float ResetTimer();
	float GetTime();
	bool IsFinished();
private:
	bool m_bIsRandom;
	float m_fCurrentTime;

	float m_fMinRange;
	float m_fMaxRange;

	float m_fStartTime;
	float m_fEndTime;

	bool m_bCountDown;
};

#endif