#pragma once
#include "Scene.h"
#include "Engine.h"
#include <iostream>
class StartScene :
    public Scene
{
public:
    void draw() override;
    void update() override;

private:
    char m_userInput;

};

