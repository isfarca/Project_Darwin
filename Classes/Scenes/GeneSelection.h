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

	// Verf�gbare F�higkeiten
	int mutationOneInt, mutationTwoInt, mutationThreeInt, mutationFourInt, mutationFiveInt, mutationSixInt, mutationSevenInt, mutationEightInt, mutationNineInt, mutationTenInt, mutationElevenInt, mutationTwelveInt;

	string mutationOnePng;
	string mutationOnePngSelected;

	string mutationTwoPng;
	string mutationTwoPngSelected;

	string mutationThreePng;
	string mutationThreePngSelected;

	string mutationFourPng;
	string mutationFourPngSelected;

	string mutationFivePng;
	string mutationFivePngSelected;

	string reset;
	string resetSelected;

	// Ausgew�hlte F�higkeiten
	int specialOne = 0;
	int specialTwo = 0;
	int specialThree = 0;
	
	string chosenMutationPngFirst, chosenMutationPngSecond, chosenMutationPngThird;



	void mutationOne(Ref *pSender);
	void mutationTwo(Ref *pSender);
	void mutationThree(Ref *pSender);
	void mutationFour(Ref *pSender);
	void mutationFive(Ref *pSender);

	void ResetSelectedMutation(Ref *pSender);

	// Initializing.
	virtual bool init();

	cocos2d::MenuItemImage *mutationOneBtn;
	cocos2d::MenuItemImage *mutationTwoBtn;
	cocos2d::MenuItemImage *mutationThreeBtn;
	cocos2d::MenuItemImage *mutationFourBtn;
	cocos2d::MenuItemImage *mutationFiveBtn;

	cocos2d::MenuItemImage *resetSelectedMutationBtn;


	void ChosenMutation(int mutationKind, string mutationPng);
	
	CREATE_FUNC(GeneSelection);

private:
	// Scene handlings.
	void GoToMainMenuScene(float delta);
	void GoToLevelScene(float delta);
};

#endif