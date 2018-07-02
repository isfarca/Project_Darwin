#pragma once

#ifndef MutationChoose_h
#define MutationChoose_h
#include "cocos2d.h"
#include <string>
using namespace std;


class MutationChoose : cocos2d::Scene 
{
	

public:

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


	static cocos2d::Scene* createScene();
	cocos2d::Label* menuLabel;
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

	cocos2d::MenuItemImage *debugMutationBtn;
	

	// Verfügbare Fähigkeiten
	int mutationOneInt, mutationTwoInt, mutationThreeInt, mutationFourInt,mutationFiveInt, mutationSixInt, mutationSevenInt, mutationEightInt, mutationNineInt, mutationTenInt, mutationElevenInt, mutationTwelveInt;
	
	// Ausgewählte Fähigkeiten
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
	
	void exitGame(Ref *pSender);

	void debugMutation(Ref *pSender);

	void ChosenMutation(int mutationKind);

	CREATE_FUNC(MutationChoose);
};

#endif