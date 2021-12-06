#include "SimulationManager.h"

SimulationManager::~SimulationManager()
{
	delete m_currentFighter1;
	delete m_currentFighter2;
}

void SimulationManager::start()
{
	Entity* wompus = new Entity('W', 3, 2, 1);
	Entity* redacte = new Entity('r', 1, 2, 3);
	Entity* unclephil = new Entity('U', 3, 1, 2);

	m_entities[0] = wompus;
	m_entities[1] = redacte;
	m_entities[2] = unclephil;
	m_entityCounter = 3;

	Entity* entityPtrs[5];
	Entity** enetities = new Entity * [5];

	m_currentFighter1 = m_entities[0];
	m_currentFighter2 = m_entities[1];
	m_currentFigterIndex = 2;
}

void SimulationManager::update()
{
	if (m_currentFighter1->getHealth() <= 0 && m_currentFigterIndex < m_entityCounter)
	{
		m_currentFighter1 = m_entities[m_currentFigterIndex];
		m_currentFigterIndex++;
	}

	if (m_currentFighter2->getHealth() <= 0 && m_currentFigterIndex < m_entityCounter)
	{
		m_currentFighter2 = m_entities[m_currentFigterIndex];
		m_currentFigterIndex++;
	}

	if (m_currentFighter1->getHealth() <= 0 || m_currentFighter2->getHealth() <= 0 && m_currentFigterIndex < m_entityCounter)
	{
		Engine::getApplicationShouldClose();
		return;
	}

	m_currentFighter1->attack(m_currentFighter2);
	m_currentFighter2->attack(m_currentFighter1);
}
