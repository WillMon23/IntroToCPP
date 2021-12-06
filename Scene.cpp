#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	delete[] m_actors;
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
	//Increase the sctor count
	m_actorCount++;
	//Creats a temp pointer array to resize the actor array 
	Actor** temPtr = new Actor*[m_actorCount];

	//for every size of actor Count
	for (int i = 0; i < m_actorCount; i++)
		//set temp in that index to be that actor in the index of m_actors
		temPtr[i] = m_actors[i];
	
	//in the largest index of tempPtr set it to be the actor being passed in
	temPtr[m_actorCount - 1] = actor;
	//Set the m_actors to be temPtr with te edited size
	m_actors = temPtr;

	//Deletes the allocated memory set for tempPtr
	delete[] temPtr;
}

/// <summary>
/// Meant to remove actors from the actor array
/// </summary>
/// <param name="actor"></param>
/// <returns></returns>
bool Scene::removeActor(Actor* actor)
{
	//Keep tabs on wither there was a actor removed or not
	bool removed = true;
	//if actor count is equal to zero or less
	if (m_actorCount <= 0)
		//Returns false
		return false;
	//Creats a temporay array of actor ptrs to exchange with the new 
	Actor** tempPtr = new Actor * [m_actorCount - 1];
	// current state of temp index 
	int j = 0;

	//For every index until it meets the size of actor xount 
	for (int i = 0; i < m_actorCount; i++)
	{	//if j is greater then i
		if (j > i)
			//Just continue
			continue;
		//if the actor at this index does not equal to the actor
		if (m_actors[i] != actor)
		{
			//add that actor to the current index of tempPtr
			tempPtr[j] = m_actors[i];
			//Incrament j
			j++;
		}
		//else
		else
			//Set Removed to true
			removed = true;
	}
	//If removed 
	if (removed)
	{
		//Reduce the actor count by 1
		m_actorCount--;
		//Set tempPtr to be the new actor array
		m_actors = tempPtr;
	}
	//Delete the temp pointer 
	delete[] tempPtr;
	//returns wither it was removed from the array or not
	return removed;
}

/// <summary>
/// Update once at the start of the Run
/// </summary>
void Scene::start()
{
	for (int i = 0; i < m_actorCount; i++)
		m_actors[i]->start();
}

/// <summary>
/// Updates once per frame
/// </summary>
void Scene::update()
{
	for (int i = 0; i < m_actorCount; i++)
		m_actors[i]->update();
}

/// <summary>
/// Draws to the scene once per frame
/// </summary>
void Scene::draw()
{
	for (int i = 0; i < m_actorCount; i++)
		m_actors[i]->draw();
}

/// <summary>
/// Updates once after Update has ended  
/// </summary>
void Scene::end()
{
	for (int i = 0; i < m_actorCount; i++)
		m_actors[i]->end();
}
