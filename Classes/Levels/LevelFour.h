#pragma once

#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include "cocos2d.h"
#include "../Outsourcing/ScreenShake.h"
#include "../Outsourcing/Definitions.h"
#include "../Scenes/LoseLoad.h"
#include "../Scenes/LevelSelection.h"

using namespace cocos2d;

class LevelFour : public Scene
{
public:
	// Create the level four scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(LevelFour);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToLoseLoadScene(float delta);
	void GoToLevelSelectionScene(float delta);
};

#endif