#pragma once

#include <memory>

#include "BaseManager.h"
#include "ObjectScene.h"

class LoadManager : BaseManager
{
public:
    LoadManager() = default;
    LoadManager(const LoadManager &manager) = delete;
    LoadManager &operator = (const LoadManager &manager) = delete;

    ~LoadManager() = default;

    std::shared_ptr<ObjectScene> load(std::string &name);
    void setModerator(std::shared_ptr<BaseLoadModerator> moderator);

private:
    std::shared_ptr<BaseLoadModerator> _moderator;
};