// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   timer.cpp
//  Description :   Timer class used for measuring intervals.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <iostream>
 // Local Includes 
 // This Include 
#include "timer.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

/***********************
* timer: Constructor used for non-random timers.
* @author: William de Beer
* @parameter: Clock starting time, Clock ending time.
********************/
timer::timer(float _startTime, float _endTime)
{
    m_bIsRandom = false;
    m_fMinRange = 0;
    m_fMaxRange = 0;

    m_fCurrentTime = _startTime;
    m_fStartTime = _startTime;
    m_fEndTime = _endTime;

    m_bCountDown = (_startTime > _endTime);
}

/***********************
* timer: Constructor used for random timers.
* @author: William de Beer
* @parameter: Range of timer, boolean indicating if it should be a countdown or not.
********************/
timer::timer(float _from, float _to, bool _isCountDown)
{
    m_bIsRandom = true;

    if (_from < _to)
    {
        m_fMinRange = _from;
        m_fMaxRange = _to;
    }
    else
    {
        m_fMinRange = _to;
        m_fMaxRange = _from;
    }

    ResetTimer();
}

timer::~timer(){}

/***********************
* Update: Increment/decrement timer.
* @author: William de Beer
* @parameter: Delta time.
********************/
void timer::Update(float _dT)
{
    if (m_bCountDown)
    {
        m_fCurrentTime -= _dT;
    }
    else
    {
        m_fCurrentTime += _dT;
    }
}

/***********************
* ResetTimer: Resets the timer and, if the timer is random it will make new time.
* @author: William de Beer
* @return: Time before being reset.
********************/
float timer::ResetTimer()
{
    if (m_bIsRandom)
    {
		m_fStartTime = 0;
		m_fEndTime = 0;
        if (m_bCountDown)
            m_fStartTime = float(rand()) / float((RAND_MAX)) * m_fMaxRange + m_fMinRange;
        if (!m_bCountDown)
            m_fEndTime = float(rand()) / float((RAND_MAX)) * m_fMaxRange + m_fMinRange;
    }
    float finalTime = m_fCurrentTime;
    m_fCurrentTime = m_fStartTime;

    return finalTime;
}

/***********************
* GetTime: Obtain current time of timer.
* @author: William de Beer
* @return: Float time.
********************/
float timer::GetTime()
{
    return m_fCurrentTime;
}

/***********************
* IsFinished: Returns if time has surpassed end time.
* @author: William de Beer
* @return: Boolean
********************/
bool timer::IsFinished()
{
    return (m_bCountDown && m_fEndTime > m_fCurrentTime) 
        || (!m_bCountDown && m_fEndTime < m_fCurrentTime);
}
