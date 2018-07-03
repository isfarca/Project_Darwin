#include "IngameButtons.h"

Scene* IngameButtons::createScene()
{

	return IngameButtons::create();
};


bool IngameButtons::init() {
	if (!Scene::init()) 
	{
		return false;
	}

	//create health and hearts
	Health::InitialHealth(this);
	SpecialAbilities::Initiation();

	//start update
	this->scheduleUpdate();

	//testwerte -> später löschen
	mutationButtonPicture1_1 = "CloseNormal.png";
	mutationButtonPicture1_2 = "CloseSelected.png";
	mutationButtonEffect1 = 2;
	mutationButtonPicture2_1 = "CloseNormal.png";
	mutationButtonPicture2_2 = "CloseSelected.png";
	mutationButtonEffect2 = 3;
	mutationButtonPicture3_1 = "CloseNormal.png";
	mutationButtonPicture3_2 = "CloseSelected.png";
	mutationButtonEffect3 = 5;

	abilityPicture1 = "CloseNormal.png";
	abilityPicture2 = "CloseSelected.png";

	//später müssen mutationbuttoneffects auf die strings von robin gesetzt werden


	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//create the 3 mutationButtons
	mutationButton1 = MenuItemImage::create(mutationButtonPicture1_1, mutationButtonPicture1_2, CC_CALLBACK_1(IngameButtons::Transmitter1, this));
	mutationButton2 = MenuItemImage::create(mutationButtonPicture2_1, mutationButtonPicture2_2, CC_CALLBACK_1(IngameButtons::Transmitter2, this));
	mutationButton3 = MenuItemImage::create(mutationButtonPicture3_1, mutationButtonPicture3_2, CC_CALLBACK_1(IngameButtons::Transmitter3, this));

	specialAbilityButton = MenuItemImage::create(abilityPicture1, abilityPicture2, CC_CALLBACK_1(IngameButtons::UseAbility, this));


	auto menu = Menu::create(mutationButton1, mutationButton2, mutationButton3, specialAbilityButton, nullptr);
	menu->setPosition(Point::ZERO);
	mutationButton1->setPosition(visibleSize.width * 3 / 10 + origin.x, origin.y + 20);
	mutationButton2->setPosition(visibleSize.width * 4 / 10 + origin.x, origin.y + 20);
	mutationButton3->setPosition(visibleSize.width * 5 / 10 + origin.x, origin.y + 20);
	specialAbilityButton->setPosition(visibleSize.width * 6 / 10 + origin.x, origin.y + 20);
	this->addChild(menu);
	return true;
}

//the 4 transimitters
void IngameButtons::Transmitter1(Ref *pSender)
{
	IngameButtons::ChangeMutation(mutationButtonEffect1);
}

void IngameButtons::Transmitter2(Ref *pSender)
{
	IngameButtons::ChangeMutation(mutationButtonEffect2);
}

void IngameButtons::Transmitter3(Ref *pSender)
{
	IngameButtons::ChangeMutation(mutationButtonEffect3);
}

void IngameButtons::ChangeMutation(int effect) {

	//save current form for ability
	currentForm = effect;
	//different effect depending on the mutation
	//call mutation-function
	switch (currentForm)
	{
	case 1:
		PlaceholderEffect::mutationRhino();
		break;
	case 2:
		PlaceholderEffect::mutationTurtle();
		break;
	case 3:
		PlaceholderEffect::mutationHawk();
		break;
	case 4:
		PlaceholderEffect::mutationElephant();
		break;
	case 5:
		PlaceholderEffect::mutationFish();
		break;
	default:
		log("mutation does not exist");
		break;
	}
}

void IngameButtons::UseAbility(Ref *pSender)
{
	switch (currentForm)
	{
	case 1:
		SpecialAbilities::RhinoAbility();
		break;
	case 2:
		SpecialAbilities::TurtleAbility();
		break;
	case 3:
		SpecialAbilities::HawkAbility();
		break;
	case 4:
		SpecialAbilities::ElephantAbility();
		break;
	case 5:
		SpecialAbilities::FishAbility();
		break;
	default:
		log("invalid mutation for ability");
		break;
	}
}

void IngameButtons::update(float delta) 
{ 
	//call 'FakeUpdate' for 'SpecialAbilities'
	SpecialAbilities::TimingHandler();
}
