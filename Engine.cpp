#include "Engine.h"
#include <iostream>

bool Engine::m_applicationShouldClose = false;

Engine::Engine()
{
	m_applicationShouldClose = false;
	m_sceneCount = 0;

}

Engine::~Engine()
{

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

void Engine::addScene(Scene* scene)
{
	Scene** temPtr = new Scene * [m_sceneCount + 1];
	if (m_sceneCount != 0)
	{
		for (int i = 0; i < m_sceneCount; i++)
			temPtr[i] = m_scenes[i];
	}
	temPtr[m_sceneCount] = scene;
	
	m_sceneCount++;
	m_scenes = temPtr;
}

/// <summary>
/// Idarates once at start 
/// meant to initalize 
/// </summary>
void Engine::start()
{
	Entity wompus = Entity('W', 3, 2, 1);
	Entity redacte = Entity('r', 1, 2, 3);
	Entity unclephil = Entity('U', 3, 1, 2);

	m_enities[0] = wompus;
	m_enities[1] = redacte;
	m_enities[2] = unclephil;
	m_entityCount = 3;

	Entity* entityPtrs[5];
	Entity** enetities = new Entity*[5];

	m_currentFighter1 = &m_enities[0];
	m_currentFighter2 = &m_enities[1];
	m_currentFighterIndex = 2;

	for (int i = 0; i < m_sceneCount; i++)
		m_scenes[i]->start();

}
/// <summary>
/// Updates once per frame 
/// </summary>
void Engine::update()
{

	if (m_currentFighter1->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_currentFighter1 = &m_enities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}

	if (m_currentFighter2->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_currentFighter2 = &m_enities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}

	if (m_currentFighter1->getHealth() <= 0 || m_currentFighter2->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		m_applicationShouldClose = true;
		return;
	}

		m_currentFighter1->attack(m_currentFighter2);
		m_currentFighter2->attack(m_currentFighter1);
}

/// <summary>
/// Draws to the screen once per frame 
/// </summary>
void Engine::draw()
{
	m_currentFighter1->printStats();
	m_currentFighter2->printStats();
	system("pause");
	system("cls");
}

void Engine::end()
{
	
}
