#include "SpecialAbilities.h"
#include "Health.h"

int turtleCooldown, turtleDuration;
bool turtleActive;

void SpecialAbilities::Initiation()
{
	//turtle
	turtleCooldown = 0;
	turtleDuration = 0;
	turtleActive = false;
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
		turtleActive = true;
		Health::InvulnerableStart();
		log("hole up");
	}
}

void SpecialAbilities::HawkAbility()
{
	log("fly");
}

void SpecialAbilities::ElephantAbility()
{
	log("stomp");
}

void SpecialAbilities::FishAbility()
{
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
	//
}