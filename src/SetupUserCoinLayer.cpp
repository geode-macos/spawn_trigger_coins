#include "SetupUserCoinLayer.hpp"

SetupUserCoinLayer* SetupUserCoinLayer::create(EffectGameObject *coin, cocos2d::CCArray *coinsArray) {
    auto ret = new SetupUserCoinLayer();
    if (ret->init(coin, coinsArray)) {
        ret->autorelease();
        return ret;
    }
    
    delete ret;
    return nullptr;
}

bool SetupUserCoinLayer::init(EffectGameObject *coin, cocos2d::CCArray *coinsArray) {
    if (!SetupTriggerPopup::init(coin, coinsArray, 300.f, 170.f, 1))
        return false;

    auto director = cocos2d::CCDirector::get();
    auto winSize = director->getWinSize();

    SetupTriggerPopup::preSetup();
    SetupTriggerPopup::addTitle("Setup User Coin");
    SetupTriggerPopup::addCloseButton("OK");
    SetupTriggerPopup::addHelpButton("Help", "Target ID will be spawn triggered when collected.", 1.f);

    SetupTriggerPopup::createValueControlAdvanced(51, "Target ID:", winSize * .5f, .8f, true, InputValueType::Int, 10, true, .0f, 9999.f, 0, 0, GJInputStyle::GoldLabel, 0, false);

    SetupTriggerPopup::postSetup();

    return true;
}