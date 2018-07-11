#pragma once

#ifndef ChangeForm_h
#define ChangeForm_h

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "SpecialAbilities.h"

using namespace CocosDenshion;
using namespace cocos2d;

class ChangeForm
{
public:
	static void mutationRhino(Sprite* smoke);
	static void mutationTurtle(Sprite* smoke);
	static void mutationHawk(Sprite* smoke);
	static void mutationElephant(Sprite* smoke);
	static void mutationFish(Sprite* smoke);

	static void SmokeTimer(Sprite* smoke);
};
#endif