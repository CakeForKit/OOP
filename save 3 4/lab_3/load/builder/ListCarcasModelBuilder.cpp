#include "ListCarcasModelBuilder.h"
#include "ListModelImpl.h"


ListCarcasModelBuilder::ListCarcasModelBuilder(std::shared_ptr<BaseCarcasModelReader> reader) 
: BaseCarcasModelBuilder(reader)
{
    _model = std::make_shared<ListModelImpl>();
}
