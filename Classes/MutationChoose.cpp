#include "MutationChoose.h"
#include <string>

USING_NS_CC;

using namespace std;

Scene* MutationChoose::createScene() {

	string mutationOnePng = "mutationpng/CloseNormal.png";
	string mutationOnePngSelected = "mutationpng/CloseSelected.png";
	
	/*
	mutationTwoPng = "MutationPng/ClosedNormal.png";
	mutationTwoPngSelected = "MutationPng/ClosedSelected";

	mutationThreePng = "MutationPng/ClosedNormal.png";
	mutationThreePngSelected = "MutationPng/ClosedSelected";

	mutationFourPng = "MutationPng/ClosedNormal.png";
	mutationFourPngSelected = "MutationPng/ClosedSelected";

	mutationFivePng = "MutationPng/ClosedNormal.png";
	mutationFivePngSelected = "MutationPng/ClosedSelected";

	mutationSixPng = "MutationPng/ClosedNormal.png";
	mutationSixPngSelected = "MutationPng/ClosedSelected";

	mutationSevenPng = "MutationPng/ClosedNormal.png";
	mutationSevenPngSelected = "MutationPng/ClosedSelected";

	mutationEightPng = "MutationPng/ClosedNormal.png";
	mutationEightPngSelected = "MutationPng/ClosedSelected";

	mutationNinePng = "MutationPng/ClosedNormal.png";
	mutationNinePngSelected = "MutationPng/ClosedSelected";

	mutationTenPng = "MutationPng/ClosedNormal.png";
	mutationTenPngSelected = "MutationPng/ClosedSelected";

	mutationElevenPng = "MutationPng/ClosedNormal.png";
	mutationElevenPngSelected = "MutationPng/ClosedSelected";

	mutationTwelvePng = "MutationPng/ClosedNormal.png";
	mutationTwelvePngSelected = "MutationPng/ClosedSelected";
	*/

	return MutationChoose::create();
}

bool MutationChoose::init() {
	if (!Scene::init()) {
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	mutationOneBtn = MenuItemImage::create("menu/exit-game.png", "menu/exit-game-selected.png", CC_CALLBACK_1(MutationChoose::mutationOne, this));

	/*
	mutationTwoBtn = MenuItemImage::create(mutationTwoPng, mutationTwoPngSelected, CC_CALLBACK_1(MutationChoose::mutationTwo, this));
	mutationThreeBtn = MenuItemImage::create(mutationThreePng, mutationThreePngSelected, CC_CALLBACK_1(MutationChoose::mutationThree, this));
	mutationFourBtn = MenuItemImage::create(mutationFourPng, mutationFourPngSelected, CC_CALLBACK_1(MutationChoose::mutationFour, this));
	mutationFiveBtn = MenuItemImage::create(mutationFivePng, mutationFivePngSelected, CC_CALLBACK_1(MutationChoose::mutationFive, this));
	mutationSixBtn = MenuItemImage::create(mutationSixPng, mutationSixPngSelected, CC_CALLBACK_1(MutationChoose::mutationSix, this));
	mutationSevenBtn = MenuItemImage::create(mutationSevenPng, mutationSevenPngSelected, CC_CALLBACK_1(MutationChoose::mutationSeven, this));
	mutationEightBtn = MenuItemImage::create(mutationEightPng, mutationEightPngSelected, CC_CALLBACK_1(MutationChoose::mutationEight, this));
	mutationNineBtn = MenuItemImage::create(mutationNinePng, mutationNinePngSelected, CC_CALLBACK_1(MutationChoose::mutationNine, this));
	mutationTenBtn = MenuItemImage::create(mutationTenPng, mutationTenPngSelected, CC_CALLBACK_1(MutationChoose::mutationTen, this));
	mutationElevenBtn = MenuItemImage::create(mutationElevenPng, mutationElevenPngSelected, CC_CALLBACK_1(MutationChoose::mutationEleven, this));
	mutationTwelveBtn = MenuItemImage::create(mutationTwelvePng, mutationTwelvePngSelected, CC_CALLBACK_1(MutationChoose::mutationTwelve, this));
	*/

	//testingText = Label::createWithTTF(specialOne, 24);

	

	auto menu = Menu::create(mutationOneBtn, nullptr);
	menu->setPosition(Point::ZERO);

	mutationOneBtn->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	 this->addChild(menu);
	return true;
}




void MutationChoose::exitGame(Ref *pSender) {
	Director::getInstance()->end();
	}


void MutationChoose::mutationOne(Ref *pSender) {	
	MutationChoose::mutationOneInt = 1;	
	ChosenMutation(1);
	cocos2d::log("%d", specialOne);
	cocos2d::log("%d", specialTwo);
	cocos2d::log("%d", specialThree);
	/*cocos2d::log(MutationChoose::specialTwo);
	cocos2d::log(MutationChoose::specialThree);*/
}

void MutationChoose::mutationTwo(Ref* pSender) {
	MutationChoose::mutationTwoInt = 2;
	ChosenMutation(2);
}

void MutationChoose::mutationThree(Ref* pSender) {
	MutationChoose::mutationThreeInt = 3;
	ChosenMutation(3);
}

void MutationChoose::mutationFour(Ref* pSender) {
	MutationChoose::mutationFourInt = 4;
	ChosenMutation(4);
}

void MutationChoose::mutationFive(Ref* pSender) {
	MutationChoose::mutationFiveInt = 5;
	ChosenMutation(5);
}

void MutationChoose::mutationSix(Ref* pSender) {
	MutationChoose::mutationSixInt = 6;
	ChosenMutation(6);
}

void MutationChoose::mutationSeven(Ref* pSender) {
	MutationChoose::mutationSevenInt = 7;
	ChosenMutation(7);
}

void MutationChoose::mutationEight(Ref* pSender) {
	MutationChoose::mutationEightInt = 8;
	ChosenMutation(8);
}

void MutationChoose::mutationNine(Ref* pSender) {
	MutationChoose::mutationNineInt = 9;
	ChosenMutation(9);
}

void MutationChoose::mutationTen(Ref* pSender) {
	MutationChoose::mutationTenInt = 10;
	ChosenMutation(10);
}

void MutationChoose::mutationEleven(Ref* pSender) {
	MutationChoose::mutationElevenInt = 11;
	ChosenMutation(11);
}

void MutationChoose::mutationTwelve(Ref* pSender) {
	MutationChoose::mutationTwelveInt = 12;
	ChosenMutation(12);
}
void MutationChoose::ChosenMutation(int mutationKind) {

	if (specialOne == 0)
	{
		// erster mutations slot
		specialOne = mutationKind;
	}
	else if (specialTwo == 0)
	{
		// zweiter mutationsslot
		specialTwo = mutationKind;
	}
	else if (specialThree == 0)
	{
		// dritter mutationsslot
		specialThree = mutationKind;
	}
	else {
		return;
	}
}
