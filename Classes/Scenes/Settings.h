#pragma once

#ifndef SETTINGS_H
#define SETTINGS_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "Help.h"
#include "Prolog.h"
#include "MainMenu.h"

using namespace cocos2d;

class Settings : public Scene
{
public:
	// Create the settings scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(Settings);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToHelpScene(float delta);
	void GoToPrologScene(float delta);
	void GoToMainMenuScene(float delta);
};

#endif