#include "Help.h"

// Create the help scene.
Scene* Help::createScene()
{
	return Help::create();
}

// Initializing.
bool Help::init()
{
	// When the scene doesn't init, then stop the init process.
	if (!Scene::init())
		return false;

	///// ADDED

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Help::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	///// ADDED END

	return true;
}

// Scene handlings
void Help::GoToMainMenuScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

///// ADDED

bool Help::onTouchBegan(Touch *touch, Event * event)
{
	// Declare variables.
	Scene* scene = Settings::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

	return true;
}

///// ADDED END