#pragma once
#include "cocos2d.h"
USING_NS_CC;
class TollgateScene : public Layer
{
public:
	~TollgateScene();
	static Scene* scene();
	CREATE_FUNC(TollgateScene);
	virtual bool init();
	virtual void onExit() override;
};

