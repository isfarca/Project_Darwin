#pragma once

#ifndef LOAD_H
#define LOAD_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "Level.h"

using namespace cocos2d;

class Load : public Scene
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
	// Create the loading scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(Load);

	// Initializing.
	virtual bool init();

	// Calling per frame for loading.
	void UpdateProgress(float delta);

	// Touch events.
	virtual bool onTouchBegan(Touch*, Event*);

private:
	// Scene handlings
	void GoToLevelScene(float delta);
};

#endif