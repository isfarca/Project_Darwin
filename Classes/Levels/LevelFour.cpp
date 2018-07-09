#include "LevelFour.h"

// Create the prolog scene.
Scene* LevelFour::createScene()
{
	return LevelTwo::create();
}

// Initializing.
bool LevelFour::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	return true;
}

// Scene handlings
void LevelFour::GoToLoadScene(float delta)
{
	// Declare variables.
	Scene* scene = Load::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelFour::GoToLevelSelectionScene(float delta)
{
	// Declare variables.
	Scene* scene = LevelSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}