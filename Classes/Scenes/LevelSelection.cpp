#include "LevelSelection.h"

// Create the prolog scene.
Scene* LevelSelection::createScene()
{
	return LevelSelection::create();
}

// Initializing.
bool LevelSelection::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	return true;
}

// Scene handlings
void LevelSelection::GoToMainMenuScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelSelection::GoToGeneSelectionScene(float delta)
{
	// Declare variables.
	Scene* scene = GeneSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}