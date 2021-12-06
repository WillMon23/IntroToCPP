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

Scene* Engine::getCurrentScene()
{
	return nullptr;
}

void Engine::setCurrentScene(int index)
{
	m_scenes[index];
}

/// <summary>
/// Idarates once at start 
/// meant to initalize 
/// </summary>
void Engine::start()
{
	

	for (int i = 0; i < m_sceneCount; i++)
		m_scenes[i]->start();

}
/// <summary>
/// Updates once per frame 
/// </summary>
void Engine::update()
{

	
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
