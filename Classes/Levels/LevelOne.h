#pragma once

#ifndef LEVELONE_H
#define LEVELONE_H

#include <string>
#include "cocos2d.h"
#include "../Outsourcing/ScreenShake.h"
#include "../Outsourcing/Definitions.h"
#include "../Scenes/LoseLoad.h"
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
	#pragma region Fethi Isfarca
	// ****************************************** Fethi Isfarca ******************************************
	// Declare variables.
	float playerSpeed = 200;
	Camera* camera;
	float cameraEndPositionX, cameraShakePositionX;
	Vec2 cameraPosition;
	float cameraSpeed = playerSpeed / 4;
	Sprite* mapSprite;
	Sprite* greyBoxSprite;
	Sprite* playerSprite;
	Size playerSpriteSize;
	PhysicsBody* playerPhysicsBody;
	Vec2 playerSpritePosition;
	float tick = playerSpeed;
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
	string abilityPicture1, abilityPicture2;

	float cameraX;
	float cameraY;

	//save the current form fpr selecting special abilty
	int currentForm;

	MenuItemImage *mutationButton1;
	MenuItemImage *mutationButton2;
	MenuItemImage *mutationButton3;
	MenuItemImage *specialAbilityButton;

	// ***************************************************************************************************
	#pragma endregion

public:
	#pragma region Scene
	// Create the level one scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(LevelOne);
	#pragma endregion

	#pragma region Cocos2d-x messages
	// Initializing.
	virtual bool init();

	// Calling per frame.
	void update(float delta);
	#pragma endregion

	#pragma region Touch events
	// Touch events.
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	void onTouchCancelled(Touch* touch, Event* event);
	#pragma endregion	

	#pragma region Alexander Sinzig
	// ****************************************** Alexander Sinzig ******************************************

	//because it seems there is no way to hand over values with callback
	void Transmitter1(Ref* pSender);
	void Transmitter2(Ref* pSender);
	void Transmitter3(Ref* pSender);
	void UseAbility(Ref* pSender);
	void ChangeMutation(int effect);

	static void JumpValues(bool midAirJump, float jumpDuration, int jumpOffset, int jumpExtremum, float fallDuration, int fallOffset, int fallExtremum);
	static void ChargeMode(bool enabled, float speedMulitplyer);
	static void TrampleMode(bool enabled, float speedMulitplyer);
	static void ButtonValues(int slot, int chosenSpecialAbility, string chosenPic, string chosenPicSelected);

	// ***************************************************************************************************
	#pragma endregion

private:
	#pragma region Fethi Isfarca
	// Shake the screen.
	void ShakeScreen();

	// Player collision with boxes.
	void PlayerCollisionBox(Sprite* playerSprite, Sprite* boxSprite);
	#pragma endregion

	#pragma region Scene handlings
	// Scene handlings.
	void GoToLoseLoadScene(float delta);
	void GoToLevelSelectionScene(float delta);
	#pragma endregion
};

#endif