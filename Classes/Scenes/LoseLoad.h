#pragma once

#ifndef LOSELOAD_H
#define LOSELOAD_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "LevelManager.h"

using namespace cocos2d;

class LoseLoad : public Scene
{
private:
	// Declare variables.
	char sentence[4];
	size_t sentenceLength;
	int randomIndex;
	__String* currentSentence;
	EventListenerTouchOneByOne* eventListenerTouchOneByOne;
	int counter = 0;
	Size visibleSize;
	Vec2 origin;
	Label* labelLoadingProcess;
	Label* darwinInfoLabel;

public:
	// Create the lose load scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(LoseLoad);

	// Initializing.
	virtual bool init();

	// Calling per frame for loading.
	void UpdateProgress(float delta);

	// Touch events.
	virtual bool onTouchBegan(Touch*, Event*);

private:
	// Scene handlings
	void GoToLevelManagerScene(float delta);
};

#endif