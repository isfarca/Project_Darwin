#include "Prolog.h"

// Create the prolog scene.
Scene* Prolog::createScene()
{
	return Prolog::create();
}

// Initializing.
bool Prolog::init()
{
	// When the scene doesn't init, then stop the init process.
	if (!Scene::init())
		return false;

	///// ADDED

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Prolog::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	///// ADDED END

	return true;
}

// Scene handlings.
void Prolog::GoToMainMenuScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

///// ADDED

bool Prolog::onTouchBegan(Touch *touch, Event * event)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

	return true;
}

///// ADDED END