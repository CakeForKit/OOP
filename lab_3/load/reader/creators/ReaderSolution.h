#pragma once

#include <map>
#include "BaseReaderCreator.h"
#include "ReaderCreatorMaker.h"
#include "ReaderTxt.h"
#include "ReaderCsv.h"

enum class IdReaderCreator
{
    TXT = 0,
    CSV = 1
};

class ReaderSolution
{
public:
    using CreatorPtr = unique_ptr<BaseReaderCreator>(&)();
    using CallBackMap = map<IdReaderCreator, CreatorPtr>;

public:
    ReaderSolution() = default;
    ReaderSolution(initializer_list<pair<IdReaderCreator, CreatorPtr>> list);

    bool registrate(IdReaderCreator id, CreatorPtr createfun);
    bool check(IdReaderCreator id) 
    { 
        return callbacks.erase(id) == 1; 
    }

    unique_ptr<BaseReaderCreator> create(IdReaderCreator id);

private:
    CallBackMap callbacks;
};

shared_ptr<ReaderSolution> make_solution(
    initializer_list<pair<IdReaderCreator, ReaderSolution::CreatorPtr>> list);

shared_ptr<ReaderSolution> make_full_solution();
