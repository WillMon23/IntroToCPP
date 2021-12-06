#pragma once
#include "Scene.h"
#include "SimulationManager.h"
#include "StartScene.h"
class FightScene :
    public Scene
{
public:
    void start() override;
};

