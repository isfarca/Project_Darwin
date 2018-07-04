#include "Health.h"

bool shielded;
int hp;
Size visibleSize;
Vec2 origin;
Sprite * hearts, *ironhearts, *heartParent;

//called from GameScene (atm: IngameButtons)
void Health::InitialHealth(Scene* scene)
{
	//initial values
	shielded = false;
	hp = 3;
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//create parent for heartse
	heartParent = Sprite::create("Heart.png");
	scene->addChild(heartParent);

	for (int i = 1; i < hp + 1; i++)
	{
		hearts = Sprite::create("Heart.png");
		hearts->setPosition(visibleSize.width * i / 15 + origin.x, visibleSize.height * 14 / 15 + origin.y);
		heartParent->addChild(hearts, 0);
	}
}

//called from 'SpecialAbilities' script, when turtle-power is activated
void Health::InvulnerableStart()
{
	shielded = true;
	//delete heart-sprites
	heartParent->removeAllChildren();
	//draw ironheart-sprites
	for (int i = 1; i < hp + 1; i++)
	{
		ironhearts = Sprite::create("IronHeart.png");
		ironhearts->setPosition(visibleSize.width * i / 15 + origin.x, visibleSize.height * 14 / 15 + origin.y);
		heartParent->addChild(ironhearts, 0);
	}
}

//called from 'SpecialAbilities' script, when turtle-power ends
void Health::InvulnerableEnd()
{
	shielded = false;
	//delete heart-sprites
	heartParent->removeAllChildren();
	//draw ironheart-sprites
	for (int i = 1; i < hp + 1; i++)
	{
		hearts = Sprite::create("Heart.png");
		hearts->setPosition(visibleSize.width * i / 15 + origin.x, visibleSize.height * 14 / 15 + origin.y);
		heartParent->addChild(hearts, 0);
	}
}

void Health::TakeDamage()
{
	if (shielded == false)
	{
		//play damageSound


		hp--;
		//delete current heart-sprites
		heartParent->removeAllChildren();
		//is the player dead?
		if (hp <= 0)
		{
			Health::GameOver();
		}
		else
		{
			//draw new heart-sprites
			for (int i = 1; i < hp + 1; i++)
			{
				hearts = Sprite::create("Heart.png");
				hearts->setPosition(visibleSize.width * i / 15 + origin.x, visibleSize.height * 14 / 15 + origin.y);
				heartParent->addChild(hearts, 0);
			}
		}
	}
	else
	{
		//play blockSound
	}
}

void Health::GameOver()
{
	//lade Fethis GameOverLoadingScene.

	log("you are dead");
}