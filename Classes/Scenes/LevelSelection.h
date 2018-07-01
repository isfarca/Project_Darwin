#pragma once

#ifndef LEVELSELECTION_H
#define LEVELSELECTION_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "MainMenu.h"
#include "GeneSelection.h"

using namespace cocos2d;

class LevelSelection : public Scene
{
public:
	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(LevelSelection);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToMainMenuScene(float delta);
	void GoToGeneSelectionScene(float delta);
};

#endif