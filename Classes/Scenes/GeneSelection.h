#pragma once

#ifndef GENESELECTION_H
#define GENESELECTION_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "MainMenu.h"
#include "Load.h"

using namespace cocos2d;
using namespace std;

class GeneSelection : public Scene
{
public:
	// Declare variables.
	Label* testingText;

	// Verfügbare Fähigkeiten
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

	string specialOnePng;
	string specialTwoPng;
	string specialThreePng;

	// Ausgewählte Fähigkeiten
	int specialOne = 0;
	int specialTwo = 0;
	int specialThree = 0;

	string chosenMutationPngFirst, chosenMutationPngSecond, chosenMutationPngThird;

	MenuItemImage* mutationOneBtn;
	MenuItemImage* mutationTwoBtn;
	MenuItemImage* mutationThreeBtn;
	MenuItemImage* mutationFourBtn;
	MenuItemImage* mutationFiveBtn;

	MenuItemImage* resetSelectedMutationBtn;

	Sprite* firstGeneSprite;
	Sprite* secondGeneSprite;
	Sprite* thirdGeneSprite;

	MenuItemImage* disabledTest;

	// Create the gene selection scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(GeneSelection);

	// Initializing.
	virtual bool init();

	void update(float) override;

	// Mutation handlings.
	void mutationOne(Ref* pSender);
	void mutationTwo(Ref* pSender);
	void mutationThree(Ref* pSender);
	void mutationFour(Ref* pSender);
	void mutationFive(Ref* pSender);

	void ResetSelectedMutation(Ref *pSender);

	void ChosenMutation(int mutationKind, string mutationPng/***DELETED**, string specialPngSelected*/);

private:
	// Scene handlings.
	void GoToMainMenuScene(float delta);
	void GoToLoadScene(float delta);
};

#endif