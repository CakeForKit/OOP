#include "DirectorSolution.h"

DirectorSolution::DirectorSolution(initializer_list<pair<IdModelDirectorCreator, CreatorPtr>> list)
{
    for (auto&& elem : list)
        this->registrate(elem.first, elem.second);
}

bool DirectorSolution::registrate(IdModelDirectorCreator id, CreatorPtr createfun)
{
    return callbacks.insert(CallBackMap::value_type(id, createfun)).second;
}

unique_ptr<BaseModelDirectorCreator> DirectorSolution::create(IdModelDirectorCreator id)
{
    CallBackMap::const_iterator it = callbacks.find(id);

    return it != callbacks.end() ? unique_ptr<BaseModelDirectorCreator>(it->second()) : nullptr;
}

shared_ptr<DirectorSolution> make_solution_director(
    initializer_list<pair<IdModelDirectorCreator, DirectorSolution::CreatorPtr>> list
)
{
    return shared_ptr<DirectorSolution>(new DirectorSolution(list));
}

shared_ptr<DirectorSolution> make_full_solution_director()
{
    return make_solution_director({ {IdModelDirectorCreator::DOTS_LINKS, ModelDirectorCreatorMaker::createModelDirectorCreator<CarcasModelDirectorOfDotsLinks>} });
                            //  {IdModelDirectorCreator::CSV, ModelDirectorCreatorMaker::createModelDirectorCreator<ModelDirectorCsv>}
}