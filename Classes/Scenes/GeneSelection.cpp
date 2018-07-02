#include "GeneSelection.h"
#include <string>	

USING_NS_CC;

using namespace std;

// Create the prolog scene.
Scene* GeneSelection::createScene()
{

	string mutationOnePng = "mutationpng/CloseNormal.png";
	string mutationOnePngSelected = "mutationpng/CloseSelected.png";

	string mutationTwoPng = "";
	string mutationTwoPngSelected = "";

	string mutationThreePng = "";
	string mutationThreePngSelected = "";

	string mutationFourPng = "";
	string mutationFourPngSelected = "";

	string mutationFivePng = "";
	string mutationFivePngSelected = "";

	string mutationSixPng = "";
	string mutationSixPngSelected = "";

	string mutationSevenPng = "";
	string mutationSevenPngSelected = "";

	string mutationEightPng = "";
	string mutationEightPngSelected = "";

	string mutationNinePng = "";
	string mutationNinePmgSelected = "";

	string mutationTenPng = "";
	string mutationTenPngSelected = "";

	string mutationElevenPng = "";
	string mutationElevenPngSelected = "";

	string mutationTwelvePng = "";
	string mutationTwelvePngSelected = "";


	
	return GeneSelection::create();
}

// Initializing.
bool GeneSelection::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	mutationOneBtn = MenuItemImage::create("menu/exit-game.png", "menu/exit-game-selected.png", CC_CALLBACK_1(GeneSelection::mutationOne, this));

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

// Scene handlings
void GeneSelection::GoToMainMenuScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void GeneSelection::GoToLevelScene(float delta)
{
	// Declare variables.
	Scene* scene = Level::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}





void GeneSelection::mutationOne(Ref *pSender) {
	GeneSelection::mutationOneInt = 1;
	ChosenMutation(1);
	cocos2d::log("%d", specialOne);
	cocos2d::log("%d", specialTwo);
	cocos2d::log("%d", specialThree);
	
	
}

void GeneSelection::mutationTwo(Ref* pSender) {
	GeneSelection::mutationTwoInt = 2;
	ChosenMutation(2);
}

void GeneSelection::mutationThree(Ref* pSender) {
	GeneSelection::mutationThreeInt = 3;
	ChosenMutation(3);
}

void GeneSelection::mutationFour(Ref* pSender) {
	GeneSelection::mutationFourInt = 4;
	ChosenMutation(4);
}

void GeneSelection::mutationFive(Ref* pSender) {
	GeneSelection::mutationFiveInt = 5;
	ChosenMutation(5);
}

void GeneSelection::mutationSix(Ref* pSender) {
	GeneSelection::mutationSixInt = 6;
	ChosenMutation(6);
}

void GeneSelection::mutationSeven(Ref* pSender) {
	GeneSelection::mutationSevenInt = 7;
	ChosenMutation(7);
}

void GeneSelection::mutationEight(Ref* pSender) {
	GeneSelection::mutationEightInt = 8;
	ChosenMutation(8);
}

void GeneSelection::mutationNine(Ref* pSender) {
	GeneSelection::mutationNineInt = 9;
	ChosenMutation(9);
}

void GeneSelection::mutationTen(Ref* pSender) {
	GeneSelection::mutationTenInt = 10;
	ChosenMutation(10);
}

void GeneSelection::mutationEleven(Ref* pSender) {
	GeneSelection::mutationElevenInt = 11;
	ChosenMutation(11);
}

void GeneSelection::mutationTwelve(Ref* pSender) {
	GeneSelection::mutationTwelveInt = 12;
	ChosenMutation(12);
}
void GeneSelection::ChosenMutation(int mutationKind) {

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