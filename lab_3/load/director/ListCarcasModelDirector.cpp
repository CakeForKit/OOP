#include "ListCarcasModelDirector.h"
#include "ListCarcasModelBuilder.h"

ListCarcasModelDirector::ListCarcasModelDirector(std::shared_ptr<BaseCarcasModelReader> reader)
: BaseCarcasModelDirector(reader) {
    _builder = std::make_shared<ListCarcasModelBuilder>(reader);
}