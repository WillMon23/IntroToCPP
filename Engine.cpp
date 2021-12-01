#include "Engine.h"
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
/// <summary>
/// Idarates once at start 
/// meant to initalize 
/// </summary>
void Engine::start()
{
}
/// <summary>
/// Updatese once per frame 
/// </summary>
void Engine::update()
{
}

void Engine::draw()
{
}

void Engine::end()
{
}
