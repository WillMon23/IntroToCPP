#pragma once
#include "Entity.h"
class Engine
{
public:
	Engine();
	void run();

	static bool getApplicationShouldClose() { return m_applicationShouldClose; }
	static void setApplicationShouldClose(bool value) { m_applicationShouldClose = value; }

private:
	void start();
	void update();
	void draw();
	void end();

private:
	static bool m_applicationShouldClose;
	Entity m_enities[3];
	Entity* m_currentFighter1;
	Entity* m_currentFighter2;

	int m_currentFighterIndex;
	int m_entityCount;

};
