#include "Scene.h"


Scene::Scene()
{
	m_actorCount = 0;
	m_actors = ActorArray();
}

Scene::~Scene()
{

}

bool Scene::getStarted()
{
	return false;
}

/// <summary>
/// Meant to add actor to the private Actors Array
/// increase the actor count
/// </summary>
/// <param name="actor"></param>
void Scene::addActor(Actor* actor)
{ 
	m_actors.addActor(actor);
}

/// <summary>
/// Meant to remove actors from the actor array
/// </summary>
/// <param name="actor"></param>
/// <returns></returns>
bool Scene::removeActor(Actor* actor)
{
	return m_actors.removeActor(actor);
}

/// <summary>
/// Update once at the start of the Run
/// </summary>
void Scene::start()
{
	m_started = true;
	for (int i = 0; i < m_actors.getLength(); i++)
		m_actors[i]->start();
}

/// <summary>
/// Updates once per frame
/// </summary>
void Scene::update()
{
	for (int i = 0; i < m_actors.getLength(); i++)
	{
		if (m_actors.getActor(i)->getStarted());
			m_actors.getActor(i)->start();
		m_actors.getActor(i)->update();
	}
}

/// <summary>
/// Draws to the scene once per frame
/// </summary>
void Scene::draw()
{
	for (int i = 0; i < m_actors.getLength(); i++)
		m_actors[i]->draw();
}

/// <summary>
/// Updates once after Update has ended  
/// </summary>
void Scene::end()
{
	for (int i = 0; i < m_actors.getLength(); i++)
		m_actors[i]->end();
}
