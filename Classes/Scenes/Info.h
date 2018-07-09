#pragma once

#ifndef INFO_H
#define INFO_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "Credits.h"
#include "MainMenu.h"

using namespace cocos2d;

class Info : public Scene
{
public:
	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(Info);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToCreditsScene(float delta);
	void GoToMainMenuScene(float delta);
};

#endif