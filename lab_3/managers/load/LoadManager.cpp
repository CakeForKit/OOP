#include "LoadManager.h"

// #include <QDebug>

std::shared_ptr<BaseObject> LoadManager::load(std::string &name)
{
    return _moderator->load(name);
}

void LoadManager::setModerator(std::shared_ptr<BaseLoadModerator> moderator)
{
    _moderator = moderator;
}


