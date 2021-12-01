#pragma once
#include "Entity.h"
class Engine
{
public:
	void run();

	static bool getApplicationShouldClose() { return m_applicationShouldCLose; }
	static void setApplicationShouldClose(bool value) { m_applicationShouldCLose = value; }

private:
	void start();
	void update();
	void draw();
	void end();

private:
	static bool m_applicationShouldCLose;
	Entity m_enities[];
	int m_entityCount;
};
