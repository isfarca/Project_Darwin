#include "Health.h"

// Declare variables.
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

	//create parent for hearts
	heartParent = Sprite::create("CloseSelected.png");
	scene->addChild(heartParent);

	for (int i = 1; i < hp + 1; i++)
	{
		hearts = Sprite::create("Heart.png");
		hearts->setPosition(-(visibleSize.width / 2) + (i + 1) * 40 + origin.x, visibleSize.height * 29 / 40 + origin.y);
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
		ironhearts->setPosition(-(visibleSize.width / 2) + (i + 1) * 40 + origin.x, visibleSize.height * 29 / 40 + origin.y);
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
		hearts->setPosition(-(visibleSize.width / 2) + (i + 1) * 40 + origin.x, visibleSize.height * 29 / 40 + origin.y);
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
				hearts->setPosition(-(visibleSize.width / 2) + (i + 1) * 40 + origin.x, visibleSize.height * 29 / 40 + origin.y);
				heartParent->addChild(hearts, 0);
			}
		}
	}
	else
	{
		//play blockSound
	}
}

void Health::MoveHearts(float xPosition, float yPosition)
{
	heartParent->setPosition(xPosition, yPosition);
}

void Health::GameOver()
{
	//lade Fethis GameOverLoadingScene.

	log("you are dead");
}