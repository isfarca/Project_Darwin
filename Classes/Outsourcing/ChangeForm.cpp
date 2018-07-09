#include "ChangeForm.h"

#define HAWK_MUTATION_SFX "Bruellen.wav"
#define RHINO_MUTATION_SFX "Bruellen.wav"
#define ELEPHANT_MUTATION_SFX "Bruellen.wav"
#define FISH_MUTATION_SFX "Bruellen.wav"
#define TURTLE_MUTATION_SFX "Bruellen.wav"

//mutation 1
void ChangeForm::mutationHawk()
{
	//smoke-sprite

	//hawk-sound
	SimpleAudioEngine::getInstance()->playEffect(HAWK_MUTATION_SFX);
	log("Hawk");
}

//mutation 2
void ChangeForm::mutationRhino()
{
	//smoke-sprite

	//rhino-sound
	SimpleAudioEngine::getInstance()->playEffect(RHINO_MUTATION_SFX);
	log("Rhino");
}

//mutation 3
void ChangeForm::mutationElephant()
{
	//smoke-sprite

	//elephant-sound
	SimpleAudioEngine::getInstance()->playEffect(ELEPHANT_MUTATION_SFX);
	log("Elephant");
}

//mutation 4
void ChangeForm::mutationFish()
{
	//smoke-sprite

	//fish-sound
	SimpleAudioEngine::getInstance()->playEffect(FISH_MUTATION_SFX);
	log("Fish");
}

//mutation 5
void ChangeForm::mutationTurtle()
{
	//smoke-sprite

	//turtle-sound
	SimpleAudioEngine::getInstance()->playEffect(TURTLE_MUTATION_SFX);
	log("Turtle");
}