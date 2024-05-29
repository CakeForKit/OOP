#include "ReaderSolution.h"

ReaderSolution::ReaderSolution(initializer_list<pair<IdReaderCreator, CreatorPtr>> list)
{
    for (auto&& elem : list)
        this->registrate(elem.first, elem.second);
}

bool ReaderSolution::registrate(IdReaderCreator id, CreatorPtr createfun)
{
    return callbacks.insert(CallBackMap::value_type(id, createfun)).second;
}

unique_ptr<BaseReaderCreator> ReaderSolution::create(IdReaderCreator id)
{
    CallBackMap::const_iterator it = callbacks.find(id);

    return it != callbacks.end() ? unique_ptr<BaseReaderCreator>(it->second()) : nullptr;
}

shared_ptr<ReaderSolution> make_solution(
    initializer_list<pair<IdReaderCreator, ReaderSolution::CreatorPtr>> list
)
{
    return shared_ptr<ReaderSolution>(new ReaderSolution(list));
}

shared_ptr<ReaderSolution> make_full_solution()
{
    return make_solution({ {IdReaderCreator::TXT, ReaderCreatorMaker::createReaderCreator<ReaderTxt>}, 
                            {IdReaderCreator::CSV, ReaderCreatorMaker::createReaderCreator<ReaderCsv>} });
}