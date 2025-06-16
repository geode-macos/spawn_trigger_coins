#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

#include "SetupUserCoinLayer.hpp"

struct CoinEditorUI : geode::Modify<CoinEditorUI, EditorUI> {
    bool editButtonUsable() {
        if (checkUserCoin()) return true;
        else return EditorUI::editButtonUsable();
    }

    void editObject(CCObject* p0) {
        
        if (checkUserCoin()) {
            auto ui = SetupUserCoinLayer::create(static_cast<EffectGameObject*>(m_selectedObject), m_selectedObjects);
            ui->show();

            return;
        }

        EditorUI::editObject(p0);
    }

    bool checkUserCoin() {
        if (!m_selectedObject) {
            if (m_selectedObjects->count() == 0)
                return false;

            geode::cocos::CCArrayExt<GameObject*> selectedObjs = m_selectedObjects;
            for (auto* obj : selectedObjs) {
                if (obj->m_objectID != 1329)
                    return false;
            }

            return true;
        } else {
            if (m_selectedObject->m_objectID == 1329)
                return true;
        }

        return false;
    }
};