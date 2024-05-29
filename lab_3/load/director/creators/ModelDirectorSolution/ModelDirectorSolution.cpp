#include "ModelDirectorSolution.h"

ModelDirectorSolution::ModelDirectorSolution(initializer_list<pair<IdModelDirectorCreator, CreatorPtr>> list)
{
    for (auto&& elem : list)
        this->registrate(elem.first, elem.second);
}

bool ModelDirectorSolution::registrate(IdModelDirectorCreator id, CreatorPtr createfun)
{
    return callbacks.insert(CallBackMap::value_type(id, createfun)).second;
}

unique_ptr<BaseModelDirectorCreator> ModelDirectorSolution::create(IdModelDirectorCreator id)
{
    CallBackMap::const_iterator it = callbacks.find(id);

    return it != callbacks.end() ? unique_ptr<BaseModelDirectorCreator>(it->second()) : nullptr;
}

shared_ptr<ModelDirectorSolution> make_solution_director(
    initializer_list<pair<IdModelDirectorCreator, ModelDirectorSolution::CreatorPtr>> list
)
{
    return shared_ptr<ModelDirectorSolution>(new ModelDirectorSolution(list));
}

shared_ptr<ModelDirectorSolution> make_full_solution_director()
{
    return make_solution_director({ {IdModelDirectorCreator::DOTS_LINKS, ModelDirectorCreatorMaker::createModelDirectorCreator<CarcasModelDirectorOfDotsLinks>} });
                            //  {IdModelDirectorCreator::CSV, ModelDirectorCreatorMaker::createModelDirectorCreator<ModelDirectorCsv>}
}