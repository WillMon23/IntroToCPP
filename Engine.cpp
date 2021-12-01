#include "Engine.h"

bool Engine::m_applicationShouldClose = false;
Engine::Engine()
{
	m_applicationShouldClose = false;
	m_entityCount = 0;
	m_currentFighterIndex = 0;
}

void Engine::run()
{
	start();

	while (!getApplicationShouldClose())
	{
		update();
		draw();
	}

	end();
}

/// <summary>
/// Idarates once at start 
/// meant to initalize 
/// </summary>
void Engine::start()
{
	Entity wompus = Entity('W', 130002000, 5780002, -15000);
	Entity redactedLittleSkeleton = Entity('r', 4400000 - 44000, 45500 - 40, 0);
	Entity unclephil = Entity('U', 1, 0, 6900055);

	m_enities[0] = wompus;
	m_enities[1] = redactedLittleSkeleton;
	m_enities[2] = unclephil;

	m_currentFighter1 = m_enities[0];
	m_currentFighter2 = m_enities[1];
	m_currentFighterIndex = 2;
}
/// <summary>
/// Updates once per frame 
/// </summary>
void Engine::update()
{

	if (m_currentFighter1.getHealth() <= 0)
	{
		m_currentFighter1 = m_enities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}
	else if (m_currentFighter2.getHealth() <= 0)
	{
		m_currentFighter2 = m_enities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}

	m_currentFighter1.attack(m_currentFighter2);
	m_currentFighter2.attack(m_currentFighter1);

	if(m_currentFighterIndex >= size(m_enities)
}

/// <summary>
/// Draws to the screen once per frame 
/// </summary>
void Engine::draw()
{
}

void Engine::end()
{
}
