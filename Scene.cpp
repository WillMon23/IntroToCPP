#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

bool Scene::getStarted()
{
	return false;
}

void Scene::addActor(Actor* actor)
{ 
	m_actorCount++;
	Actor** temoPtr = new Actor*[m_actorCount];
	
	for (int i = 0; i < m_actorCount; i++)
		temoPtr[i] = m_actors[i];
	temoPtr[m_actorCount - 1] = actor;
	m_actors = temoPtr;
	

	delete[] temoPtr;
}

bool Scene::removeActor(Actor* actor)
{
	if (m_actorCount <= 0)
		return false;

	Actor** tempPtr = new Actor * [m_actorCount];

	int j = 0;

	for (int i = 0; i < m_actorCount)
		return true;
}

void Scene::start()
{
}

void Scene::update()
{
}

void Scene::draw()
{
}

void Scene::end()
{
}
