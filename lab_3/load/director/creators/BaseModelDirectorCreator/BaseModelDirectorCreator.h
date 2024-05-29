#pragma once

#include <memory>
#include "BaseDirector.h"

using namespace std;

// class BaseModelDirectorCreator
// {
// public:
//     virtual ~BaseModelDirectorCreator() = default;
//     shared_ptr<BaseDirector> getModelDirector();    // идиома невиртуального интерфейса пример 11.01.03

// protected:
//     virtual shared_ptr<BaseDirector> create() = 0;

// private:
//     shared_ptr<BaseDirector> director{ nullptr };
// };


class BaseModelDirectorCreator {
    public:
        virtual ~BaseModelDirectorCreator() = default;
};


template <typename Director, typename... Args>
class BaseModelDirectorTemplate : public BaseModelDirector {
    public:
        virtual ~BaseModelDirectorTemplate() = default;

        virtual shared_ptr<Director> Create(Args&&... args) = 0;

};

// using BoneModelDirectorCreator_t = BaseModelDirectorTemplate<BaseBoneModelDirector, std::shared_ptr<BoneModelReader>>;