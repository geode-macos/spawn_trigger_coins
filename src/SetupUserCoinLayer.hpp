#pragma once

#include <Geode/Geode.hpp>

class SetupUserCoinLayer : public SetupTriggerPopup {
public:
    static SetupUserCoinLayer* create(EffectGameObject* coin, cocos2d::CCArray* coinsArray);
    bool init(EffectGameObject* coin, cocos2d::CCArray* coinsArray);
};