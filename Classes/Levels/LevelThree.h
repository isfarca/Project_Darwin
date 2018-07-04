#pragma once

#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "cocos2d.h"
#include "../Outsourcing/ScreenShake.h"
#include "../Outsourcing/Definitions.h"
#include "../Scenes/Load.h"
#include "../Scenes/LevelSelection.h"

using namespace cocos2d;

class LevelThree : public Scene
{
public:
	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(LevelThree);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToLoadScene(float delta);
	void GoToLevelSelectionScene(float delta);
};

#endif