#pragma once
#include "Actor.h"
#include "Entity.h"
class SimulationManager :
    public Actor
{
public:
    SimulationManager();
    ~SimulationManager();

    void start() override;
    void update() override;

private:
    Entity* m_entities;
    Entity* m_currentFighter1;
    Entity* m_currentFighter2;

    int m_currentFigterIndex;
    int m_entityCounter;
};

