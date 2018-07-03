#pragma once
#ifndef IngameButtons_h
#define IngameButtons_h
#include "cocos2d.h"
#include "SpecialAbilities.h"
//später durch fethis mutationen-header ersetzen
#include "PlaceholderEffect.h"
//später robins header includen, um auf seine int-variablen, welche dann die mutationbuttoneffects ersetzen zuzugreifen

#include <string>
#include "Health.h"
using namespace cocos2d;
using namespace std;

class IngameButtons : public cocos2d::Scene
{
public:
	//---------------------------------------
	static Scene* createScene();
	void update(float delta);
	//---------------------------------------

	Label* menuLabel;
	virtual bool init();

	Sprite* sprite;


	MenuItemImage *mutationButton1;
	MenuItemImage *mutationButton2;
	MenuItemImage *mutationButton3;
	MenuItemImage *specialAbilityButton;

	//because it seems there is no way to hand ovre values with callback
	void Transmitter1(Ref * pSender);
	void Transmitter2(Ref * pSender);
	void Transmitter3(Ref * pSender);
	void UseAbility(Ref * pSender);
	void ChangeMutation(int effect);


	//variables for mutationButton-picture-loading
	string mutationButtonPicture1_1, mutationButtonPicture1_2, mutationButtonPicture2_1, mutationButtonPicture2_2, mutationButtonPicture3_1, mutationButtonPicture3_2;
	string abilityPicture1, abilityPicture2;
		
	//variables for the mutationButton-effect
	int mutationButtonEffect1, mutationButtonEffect2, mutationButtonEffect3;

	//save the current form fpr selecting special abilty
	int currentForm;

	CREATE_FUNC(IngameButtons);
};
#endif