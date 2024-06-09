#pragma once
#include "BaseReader.h"
#include "BaseReaderCreator.h"
#include <map>

enum class IdReaderCreator
{
    TXT = 0,
    CSV = 1
};

class ReaderSolution {
    public:
        ReaderSolution();
        ReaderSolution(std::initializer_list<std::pair<IdReaderCreator, std::shared_ptr<BaseReaderCreator>>> list);

        void Register(IdReaderCreator index, std::shared_ptr<BaseReaderCreator> creator);
        bool Check(IdReaderCreator index);
        std::shared_ptr<BaseReaderCreator> Create(IdReaderCreator index);

        ~ReaderSolution();

    private:
        std::map<IdReaderCreator, std::shared_ptr<BaseReaderCreator>> _creators;

};