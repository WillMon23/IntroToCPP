#pragma once
#include "Actor.h"
#include "ActorArray.h"
class Scene
{
public:
	Scene();
	~Scene();
	bool getStarted();
	void addActor(Actor* actor);
	bool removeActor(Actor* actor);

	virtual void start();
	virtual void update();
	virtual void draw();
	virtual void end();

private:
	ActorArray m_actors;
	bool m_started;
	int m_actorCount;

};
