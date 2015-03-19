#include "BackgroundLayer.h"
#include "TollgateScene.h"
BackgroundLayer::BackgroundLayer()
{
}
BackgroundLayer::~BackgroundLayer()
{
}
bool BackgroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}


	Size visibleSize = Director::getInstance()->getVisibleSize();
	m_bg1 = Sprite::createWithSpriteFrameName("background.jpg");
	m_bg1->setPosition(Vect(visibleSize.width/2,visibleSize.height/2));
	addChild(m_bg1);
	m_bg2 = Sprite::createWithSpriteFrameName("background.jpg");
	m_bg2->setPosition(Vect(visibleSize.width / 2, -visibleSize.height / 2));
	addChild(m_bg2);

	auto border = Sprite::createWithSpriteFrameName("border.png");
}