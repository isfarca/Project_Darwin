#pragma once

#ifndef LEVELONE_H
#define LEVELONE_H

#include <string>
#include "cocos2d.h"
#include "../Outsourcing/ScreenShake.h"
#include "../Outsourcing/Definitions.h"
#include "../Scenes/Load.h"
#include "../Scenes/LevelSelection.h"
#include "../Outsourcing/SpecialAbilities.h"
//später durch fethis mutationen-header ersetzen
#include "../Outsourcing/PlaceholderEffect.h"
//später robins header includen, um auf seine int-variablen, welche dann die mutationbuttoneffects ersetzen zuzugreifen
#include "../Outsourcing/Health.h"

using namespace cocos2d;

class LevelOne : public Scene
{
private:
	// Constants.
	const float PLAYERSPEED = 200;

private:
	#pragma region Fethi Isfarca
	// ****************************************** Fethi Isfarca ******************************************

	// Declare variables.
	Camera * camera;
	float cameraEndPositionX, cameraShakePositionX;
	Vec2 cameraPosition;
	float cameraSpeed = PLAYERSPEED / 4;
	Sprite* helloWorldSprite;
	Vec2 helloWorldSpritePosition;
	float tick = PLAYERSPEED;
	Size visibleSize;
	Vec2 origin;
	EventListenerTouchOneByOne* eventListenerTouchOneByOne;
	bool isTouched = false, moveLeft = false, moveRight = false, moveDown = false, jump = false;
	float initialTouchPosition[2] =
	{
		0,
		0
	};
	float currentTouchPosition[2];
	JumpTo* jumpTo;

	// ***************************************************************************************************
	#pragma endregion

	#pragma region Alexander Sinzig
	// ****************************************** Alexander Sinzig ******************************************

	// Declare variables.
	Label* menuLabel;
	Sprite* sprite;

	//variables for mutationButton-picture-loading
	string mutationButtonPicture1_1, mutationButtonPicture1_2, mutationButtonPicture2_1, mutationButtonPicture2_2, mutationButtonPicture3_1, mutationButtonPicture3_2;
	string abilityPicture1, abilityPicture2;

	//variables for the mutationButton-effect
	int mutationButtonEffect1, mutationButtonEffect2, mutationButtonEffect3;

	//save the current form fpr selecting special abilty
	int currentForm;

	MenuItemImage *mutationButton1;
	MenuItemImage *mutationButton2;
	MenuItemImage *mutationButton3;
	MenuItemImage *specialAbilityButton;

	// ***************************************************************************************************
	#pragma endregion

public:
	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(LevelOne);

	// Initializing.
	virtual bool init();

	// Calling per frame.
	void update(float delta);

	// Touch events.
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	void onTouchCancelled(Touch* touch, Event* event);

	#pragma region Alexander Sinzig
	// ****************************************** Alexander Sinzig ******************************************

	//because it seems there is no way to hand over values with callback
	void Transmitter1(Ref * pSender);
	void Transmitter2(Ref * pSender);
	void Transmitter3(Ref * pSender);
	void UseAbility(Ref * pSender);
	void ChangeMutation(int effect);

	// ***************************************************************************************************
	#pragma endregion

private:
	#pragma region Fethi Isfarca
	// Shake the screen.
	void ShakeScreen();
	#pragma endregion

	// Scene handlings.
	void GoToLoadScene(float delta);
	void GoToLevelSelectionScene(float delta);



};

#endif