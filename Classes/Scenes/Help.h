#pragma once

#ifndef HELP_H
#define HELP_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "MainMenu.h"

using namespace cocos2d;

class Help : public Scene
{
public:
	// Create the help scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(Help);

	// Initializing.
	virtual bool init();

	///// ADDED

	bool onTouchBegan(Touch *touch, Event * event);

	

	///// ADDED END

private:
	// Scene handlings.
	void GoToMainMenuScene(float delta);
};

#endif