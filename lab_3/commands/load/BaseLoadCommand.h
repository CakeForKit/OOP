#pragma once
#include "BaseCommand.h"

class BaseLoadCommand : public BaseCommand {
    public:
        BaseLoadCommand() = default;
        virtual ~BaseLoadCommand() = 0;
        IdDirectorCreator GetDirectorId();
        IdReaderCreator GetReaderId();
    
    protected:
        IdReaderCreator _reader_id;
        IdDirectorCreator _director_id;
};