#pragma once

#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "cocos2d.h"
#include "../Outsourcing/ScreenShake.h"
#include "../Outsourcing/Definitions.h"
#include "../Scenes/Load.h"
#include "../Scenes/LevelSelection.h"

using namespace cocos2d;

class LevelTwo : public Scene
{
public:
	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(LevelTwo);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToLoadScene(float delta);
	void GoToLevelSelectionScene(float delta);
};

#endif