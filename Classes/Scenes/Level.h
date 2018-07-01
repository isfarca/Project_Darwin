#pragma once

#ifndef LEVEL_H
#define LEVEL_H

#include "cocos2d.h"
#include "../Levels/One.h"
#include "../Levels/Two.h"
#include "../Levels/Three.h"
#include "../Levels/Four.h"
#include "../Outsourcing/Definitions.h"
#include "LevelSelection.h"

using namespace cocos2d;

class Level : public Scene
{
public:
	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(Level);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void RefreshLevelScene(float delta);
	void GoToLevelSelectionScene(float delta);
};

#endif