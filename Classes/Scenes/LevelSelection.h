#pragma once

#ifndef LEVELSELECTION_H
#define LEVELSELECTION_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "MainMenu.h"
#include "GeneSelection.h"

USING_NS_CC;
using namespace cocos2d;
using namespace std;

class LevelSelection : public Scene
{
public:
	// Create the prolog scene.
	static Scene* createScene();

	int selectedLevel = 0;

	// Levels
	MenuItemImage *levelOneButton;
	MenuItemImage *levelTwoButton;
	MenuItemImage *levelThreeButton;
	MenuItemImage *levelFourButton;

	MenuItemImage *goToMainMenuButton;
	MenuItemImage *goToGeneSelectionButton;
	// Implement the create function.
	CREATE_FUNC(LevelSelection);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToMainMenuScene(Ref *pSender);
	void GoToGeneSelectionScene(Ref *pSender);

	void StartLevelOne(Ref *pSender);
	void StartLevelTwo(Ref *pSender);
	void StartLevelThree(Ref *pSender);
	void StartLevelFour(Ref *pSender);

};

#endif