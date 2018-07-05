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

	// available  mutations
	int mutationOneInt, mutationTwoInt, mutationThreeInt, mutationFourInt, mutationFiveInt, mutationSixInt, mutationSevenInt, mutationEightInt, mutationNineInt, mutationTenInt, mutationElevenInt, mutationTwelveInt;

	// reference for mutation pngs

	string mutationOnePng;
	string mutationOnePngSelected;
	string mutationOnePngBlocked;

	string mutationTwoPng;
	string mutationTwoPngSelected;
	string mutationTwoPngBlocked;

	string mutationThreePng;
	string mutationThreePngSelected;
	string mutationThreePngBlocked;

	string mutationFourPng;
	string mutationFourPngSelected;
	string mutationFourPngBlocked;

	string mutationFivePng;
	string mutationFivePngSelected;
	string mutationFivePngBlocked;

	string reset;
	string resetSelected;

	string specialOnePng;
	string specialTwoPng;
	string specialThreePng;

	// reference for start png
	string startPng;
	string startPngSelected;

	string characterWithMutationOne;
	string characterWithMutationTwo;
	string characterWithMutationThree;
	string characterWithMutationFour;
	string characterWithMutationFive;

	string characterWithMutationClear;

	string currentCharacter;

	// chosen mutations
	int specialOne = 0;
	int specialTwo = 0;
	int specialThree = 0;

	// png reference for chosen mutations
	string chosenMutationPngFirst, chosenMutationPngSecond, chosenMutationPngThird, chosenMutationPngFirstSelected, chosenMutationPngSecondSelected, chosenMutationPngThirdSelected;

	// mutation button reference
	MenuItemImage* mutationOneBtn;
	MenuItemImage* mutationTwoBtn;
	MenuItemImage* mutationThreeBtn;
	MenuItemImage* mutationFourBtn;
	MenuItemImage* mutationFiveBtn;

	// reset mutations that are selected button reference
	MenuItemImage* resetSelectedMutationBtn;

	// start button reference
	MenuItemImage* startGameBtn;

	// sprite reference for selected genes
	Sprite* firstGeneSprite;
	Sprite* secondGeneSprite;
	Sprite* thirdGeneSprite;

	Sprite* ChosenCharacterMutation;

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
	void startGame(Ref* pSender);

	void ResetSelectedMutation(Ref *pSender);

	void ChosenMutation(int mutationKind, string mutationPng/***DELETED**, string specialPngSelected*/);

private:
	// Scene handlings.
	void GoToMainMenuScene(float delta);
	void GoToLoadScene(float delta);
};

#endif