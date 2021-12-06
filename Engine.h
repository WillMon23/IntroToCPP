#pragma once
#include "Entity.h"
#include "Scene.h"
class Engine
{
public:
	Engine();
	~Engine();
	void run();

	static bool getApplicationShouldClose() { return m_applicationShouldClose; }
	static void setApplicationShouldClose(bool value) { m_applicationShouldClose = value; }

	static void addScene(Scene* scene);
	static bool removeScene(Scene* scene);
	static Scene* getCurrentScene();
	static void setCurrentScene(int index);

private:
	void start();
	void update();
	void draw();
	void end();

private:
	static bool m_applicationShouldClose;

	Scene** m_scenes;
	int m_sceneCount;
};
