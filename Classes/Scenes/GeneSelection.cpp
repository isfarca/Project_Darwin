#include "GeneSelection.h"
#include <string>	

USING_NS_CC;

using namespace std;

// Create the prolog scene.
Scene* GeneSelection::createScene()
{

	return GeneSelection::create();
}

// Initializing.
bool GeneSelection::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	mutationOnePng = "Png/Mutation/mutation1.png";
	mutationOnePngSelected = "Png/Mutation/mutation1Selected.png";

	mutationTwoPng = "Png/Mutation/mutation2.png";
	mutationTwoPngSelected = "Png/Mutation/mutation2Selected.png";

	mutationThreePng = "Png/Mutation/mutation3.png";
	mutationThreePngSelected = "Png/Mutation/mutation3Selected.png";

	mutationFourPng = "Png/Mutation/mutation4.png";
	mutationFourPngSelected = "Png/Mutation/mutation4Selected.png";

	mutationFivePng = "Png/Mutation/mutation5.png";
	mutationFivePngSelected = "Png/Mutation/mutation5Selected.png";


	reset = "Png/Mutation/reset.png";
	resetSelected = "Png/Mutation/resetSelected";
	

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	mutationOneBtn = MenuItemImage::create(mutationOnePng, mutationOnePngSelected, CC_CALLBACK_1(GeneSelection::mutationOne, this));
	mutationTwoBtn = MenuItemImage::create(mutationTwoPng, mutationTwoPngSelected, CC_CALLBACK_1(GeneSelection::mutationTwo, this));
	mutationThreeBtn = MenuItemImage::create(mutationThreePng, mutationThreePngSelected, CC_CALLBACK_1(GeneSelection::mutationThree, this));
	mutationFourBtn = MenuItemImage::create(mutationFourPng, mutationFourPngSelected, CC_CALLBACK_1(GeneSelection::mutationFour, this));
	mutationFiveBtn = MenuItemImage::create(mutationFivePng, mutationFivePngSelected, CC_CALLBACK_1(GeneSelection::mutationFive, this));

	resetSelectedMutationBtn = MenuItemImage::create(reset, resetSelected, CC_CALLBACK_1(GeneSelection::ResetSelectedMutation, this));




	auto menu = Menu::create(mutationOneBtn, mutationTwoBtn, mutationThreeBtn, mutationFourBtn, mutationFiveBtn,resetSelectedMutationBtn, nullptr);
	menu->setPosition(Point::ZERO);

	mutationOneBtn->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	mutationTwoBtn->setPosition(visibleSize.width / 2, visibleSize.height / 2+50);
	mutationThreeBtn->setPosition(visibleSize.width / 2, visibleSize.height / 2+100);
	mutationFourBtn->setPosition(visibleSize.width / 2, visibleSize.height / 2+150);
	mutationFiveBtn->setPosition(visibleSize.width / 2, visibleSize.height / 2+200);

	resetSelectedMutationBtn->setPosition(visibleSize.width / 2 + 250, visibleSize.height / 2 - 200);
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
	ChosenMutation(1, mutationOnePng);
	cocos2d::log("%d", specialOne);
	cocos2d::log("%d", specialTwo);
	cocos2d::log("%d", specialThree);

	cocos2d::log("%s", chosenMutationPngFirst.c_str());
	cocos2d::log("%s", chosenMutationPngSecond.c_str());
	cocos2d::log("%s", chosenMutationPngThird.c_str());

}

void GeneSelection::mutationTwo(Ref* pSender) {
	GeneSelection::mutationTwoInt = 2;
	ChosenMutation(2, mutationTwoPng);
	cocos2d::log("%d", specialOne);
	cocos2d::log("%d", specialTwo);
	cocos2d::log("%d", specialThree);

	cocos2d::log("%s", chosenMutationPngFirst.c_str());
	cocos2d::log("%s", chosenMutationPngSecond.c_str());
	cocos2d::log("%s", chosenMutationPngThird.c_str());
}

void GeneSelection::mutationThree(Ref* pSender) {
	GeneSelection::mutationThreeInt = 3;
	ChosenMutation(3, mutationThreePng);
	cocos2d::log("%d", specialOne);
	cocos2d::log("%d", specialTwo);
	cocos2d::log("%d", specialThree);

	cocos2d::log("%s", chosenMutationPngFirst.c_str());
	cocos2d::log("%s", chosenMutationPngSecond.c_str());
	cocos2d::log("%s", chosenMutationPngThird.c_str());
}

void GeneSelection::mutationFour(Ref* pSender) {
	GeneSelection::mutationFourInt = 4;
	ChosenMutation(4, mutationFourPng);
	cocos2d::log("%d", specialOne);
	cocos2d::log("%d", specialTwo);
	cocos2d::log("%d", specialThree);

	cocos2d::log("%s", chosenMutationPngFirst.c_str());
	cocos2d::log("%s", chosenMutationPngSecond.c_str());
	cocos2d::log("%s", chosenMutationPngThird.c_str());
}

void GeneSelection::mutationFive(Ref* pSender) {
	GeneSelection::mutationFiveInt = 5;

	ChosenMutation(5, mutationFivePng);

	cocos2d::log("%d", specialOne);
	cocos2d::log("%d", specialTwo);
	cocos2d::log("%d", specialThree);

	cocos2d::log("%s", chosenMutationPngFirst.c_str());
	cocos2d::log("%s", chosenMutationPngSecond.c_str());
	cocos2d::log("%s", chosenMutationPngThird.c_str());
}

void GeneSelection::ResetSelectedMutation(Ref* pSender)
{
	specialOne = 0;
	specialTwo = 0;
	specialThree = 0;
	chosenMutationPngFirst = "";
	chosenMutationPngSecond = "";
	chosenMutationPngThird = "";
}

void GeneSelection::ChosenMutation(int mutationKind, string mutationPng) {

	if (specialOne == 0)
	{
		// erster mutations slot
		specialOne = mutationKind;
		chosenMutationPngFirst = mutationPng;
	}
	else if (specialTwo == 0)
	{
		// zweiter mutationsslot
		specialTwo = mutationKind;
		chosenMutationPngSecond = mutationPng;
	}
	else if (specialThree == 0)
	{
		// dritter mutationsslot
		specialThree = mutationKind;
		chosenMutationPngThird = mutationPng;
	}
	else {
		return;
	}
}