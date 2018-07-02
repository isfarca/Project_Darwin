#pragma once

#ifndef GENESELECTION_H
#define GENESELECTION_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "MainMenu.h"
#include "Level.h"

using namespace cocos2d;
using namespace std;

class GeneSelection : public Scene
{

public:
	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.

	cocos2d::Label * testingText;
	// Mutation Image Reference
	/*
	static string mutationOnePng, mutationOnePngSelected;
	static string mutationTwoPng, mutationTwoPngSelected;
	static string mutationThreePng, mutationThreePngSelected;
	static string mutationFourPng, mutationFourPngSelected;
	static string mutationFivePng, mutationFivePngSelected;
	static string mutationSixPng, mutationSixPngSelected;
	static string mutationSevenPng, mutationSevenPngSelected;
	static string mutationEightPng, mutationEightPngSelected;
	static string mutationNinePng, mutationNinePngSelected;
	static string mutationTenPng, mutationTenPngSelected;
	static string mutationElevenPng, mutationElevenPngSelected;
	static string mutationTwelvePng, mutationTwelvePngSelected;
	*/
	// Verf�gbare F�higkeiten
	int mutationOneInt, mutationTwoInt, mutationThreeInt, mutationFourInt, mutationFiveInt, mutationSixInt, mutationSevenInt, mutationEightInt, mutationNineInt, mutationTenInt, mutationElevenInt, mutationTwelveInt;

	// Ausgew�hlte F�higkeiten
	int specialOne = 0;
	int specialTwo = 0;
	int specialThree = 0;

	void mutationOne(Ref *pSender);
	void mutationTwo(Ref *pSender);
	void mutationThree(Ref *pSender);
	void mutationFour(Ref *pSender);
	void mutationFive(Ref *pSender);
	void mutationSix(Ref *pSender);
	void mutationSeven(Ref *pSender);
	void mutationEight(Ref *pSender);
	void mutationNine(Ref *pSender);
	void mutationTen(Ref *pSender);
	void mutationEleven(Ref *pSender);
	void mutationTwelve(Ref *pSender);


	// Initializing.
	virtual bool init();

	cocos2d::MenuItemImage *mutationOneBtn;
	cocos2d::MenuItemImage *mutationTwoBtn;
	cocos2d::MenuItemImage *mutationThreeBtn;
	cocos2d::MenuItemImage *mutationFourBtn;
	cocos2d::MenuItemImage *mutationFiveBtn;
	cocos2d::MenuItemImage *mutationSixBtn;
	cocos2d::MenuItemImage *mutationSevenBtn;
	cocos2d::MenuItemImage *mutationEightBtn;
	cocos2d::MenuItemImage *mutationNineBtn;
	cocos2d::MenuItemImage *mutationTenBtn;
	cocos2d::MenuItemImage *mutationElevenBtn;
	cocos2d::MenuItemImage *mutationTwelveBtn;

	void ChosenMutation(int mutationKind);
	CREATE_FUNC(GeneSelection);

private:
	// Scene handlings.
	void GoToMainMenuScene(float delta);
	void GoToLevelScene(float delta);
};

#endif