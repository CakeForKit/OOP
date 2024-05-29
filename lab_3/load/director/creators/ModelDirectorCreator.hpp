#pragma once

#include "ModelDirectorCreator.h"

// template <Derivative<BaseDirector> TModelDirector>
// requires NotAbstract<TModelDirector> && DefaultConstructible<TModelDirector>
// class ModelDirectorCreator : public BaseModelDirectorCreator
// {
// protected:
//     shared_ptr<BaseDirector> create() override
//     {
//         return make_shared<TModelDirector>();
//     }
// };

template <typename TBase, typename T, typename... Args>
requires NotAbstract<T> && Derivative<T, TBase> && Constructible<T, Args...>
std::shared_ptr<TBase> ModelDirectorCreator<TBase, T, Args...>::create(Args&&... args) {
    return std::make_shared<T>(args...);
}




// using ListBoneModelDirectorCreator = DirectorCreator<BaseBoneModelDirector, ListBoneModelDirector, std::shared_ptr<BoneModelReader>>;
// using MatrixBoneModelDirectorCreator = DirectorCreator<BaseBoneModelDirector, MatrixBoneModelDirector, std::shared_ptr<BoneModelReader>>;
