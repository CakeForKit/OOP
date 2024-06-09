#pragma once
#include "BaseDirector.h"
#include "BaseCarcasModelBuilder.h"


class BaseCarcasModelDirector : public BaseDirector {
    public: 
        BaseCarcasModelDirector(std::shared_ptr<BaseCarcasModelReader> reader);
        
        virtual ~BaseCarcasModelDirector() = 0;
        
        virtual std::shared_ptr<Object> Get();

    protected:
        virtual void Create();

        std::shared_ptr<BaseCarcasModelBuilder> _builder;

};