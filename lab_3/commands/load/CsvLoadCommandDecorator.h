#pragma once
#include "BaseLoadCommandDecorator.h"

class CsvLoadCommandDecorator : public BaseLoadCommandDecorator {
    public:
        virtual ~CsvLoadCommandDecorator() = default;
        CsvLoadCommandDecorator() = delete;
        CsvLoadCommandDecorator(BaseLoadCommand &command, const char *filename);
        virtual void Execute();
    protected:
        const char *_filename;
};