#pragma once
#include "BaseDirectorCreator.h"
#include "BaseCarcasModelDirector.h"
#include "ListCarcasModelDirector.h"
#include "MatrixCarcasModelDirector.h"
#include "concept.h"
#include <memory>




template <typename DirectorBase, typename DirectorProd, typename... Args>
requires NotAbstract<DirectorProd> && Derivative<DirectorProd, DirectorBase> && Constructible<DirectorProd, Args...>
class DirectorCreator : public BaseDirectorCreatorTemplate<DirectorBase, Args...> {
    public:
        virtual ~DirectorCreator() = default;
        virtual std::shared_ptr<DirectorBase> Create(Args&&... args);
};



using ListCarcasModelDirectorCreator = DirectorCreator<BaseCarcasModelDirector, ListCarcasModelDirector, std::shared_ptr<BaseCarcasModelReader>>;
using MatrixCarcasModelDirectorCreator = DirectorCreator<BaseCarcasModelDirector, MatrixCarcasModelDirector, std::shared_ptr<BaseCarcasModelReader>>;

#include "DirectorCreator.hpp"