#include "SpecialAbilities.h"
#include "Health.h"

// Declare variables.
int turtleCooldown, turtleDuration, hawkCooldown, hawkDuration;
bool turtleActive, hawkActive, fishActive;

void SpecialAbilities::Initiation()
{
	//turtle
	turtleCooldown = 0;
	turtleDuration = 0;
	turtleActive = false;

	//hawk
	hawkCooldown = 0;
	hawkDuration = 0;
	hawkActive = 0;

	//Fish
	fishActive = 0;
}

void SpecialAbilities::RhinoAbility()
{
	log("charge");
}

void SpecialAbilities::TurtleAbility()
{
	if (turtleCooldown <= 0)
	{
		//equals 4 seconds
		turtleDuration = 240;
		//equels 12 seconds
		turtleCooldown = 720;
		turtleActive = true;
		Health::InvulnerableStart();
		log("hole up");
	}
}

void SpecialAbilities::HawkAbility()
{
	if (hawkCooldown <= 0)
	{
		//equals 5 seconds
		hawkDuration = 300;
		//equals 15 seconds
		hawkCooldown = 900;
		hawkActive = true;
		//call function to set new values for jump and gravity in scene-script
		//jumpInMidAir + Jump (duration, offsetY, extremaY) + Falling (duration, offsetY, extremaY) 
		//LevelOne::JumpValues(true, 1.5, 200, 0, 2.0, -200, 0);
		log("fly");
	}
}

void SpecialAbilities::ElephantAbility()
{
	log("stomp");
}

void SpecialAbilities::FishAbility()
{
	//check golbal bool and if ability is inactive
	/*if (LevelOne::UnderWater && fishActive == false)
	{
		fishActive = true;
		//call function to set new values for jump and gravity in scene-script
		//jumpInMidAir + Jump (duration, offsetY, extremaY) + Falling (duration, offsetY, extremaY) 
		LevelOne::JumpValues(true, 1.5, 200, 0, 2.0, -200, 0);
	}
	//deactivate if already active
	else if (LevelOne::UnderWater && fishActive == true)
	{
		fishActive = false;
		//call function to restore default values for jump and gravity in scene-script
		//jumpInMidAir + Jump (duration, offsetY, extremaY) + Falling (duration, offsetY, extremaY
		LevelOne::JumpValues(false, 1.0, 0, 300, 1.0, -200, 0);
	}*/
	log("swim");
}

//to manage cooldowns and durations
void SpecialAbilities::TimingHandler()
{
	//cooldowns
	if (turtleCooldown > 0)
	{
		turtleCooldown--;
	}

	//durations
	//turtle
	if (turtleDuration > 0)
	{
		turtleDuration--;
	}
	else if (turtleActive == true)
	{
		turtleActive = false;
		Health::InvulnerableEnd();
		log("return to normal health");
	}
	//hawk
	if (hawkDuration > 0)
	{
		hawkDuration--;
	}
	else if (hawkActive == true)
	{
		hawkActive = false;
		//call function to restore default values for jump and gravity in scene-script
		//jumpInMidAir + Jump (duration, offsetY, extremaY) + Falling (duration, offsetY, extremaY)  
		//extrema: Größe des Bogens
		//offset: Höhenunterschied am Ende 
		//LevelOne::JumpValues(false, 1.0, 0, 300, 1.0, -200, 0);
	}

	//fish
	/*if (!LevelOne::UnderWater && fishActive == true)
	{
		fishActive = false;
		//call function to restore default values for jump and gravity in scene-script
		//jumpInMidAir + Jump (duration, offsetY, extremaY) + Falling (duration, offsetY, extremaY
		//LevelOne::JumpValues(false, 1.0, 0, 300, 1.0, -200, 0);
	}*/
}