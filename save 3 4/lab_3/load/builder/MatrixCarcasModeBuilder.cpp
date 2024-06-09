#include "MatrixCarcasModelBuilder.h"
#include "MatrixModelImpl.h"

MatrixCarcasModelBuilder::MatrixCarcasModelBuilder(std::shared_ptr<BaseCarcasModelReader> reader) 
: BaseCarcasModelBuilder(reader)
{
    _model = std::make_shared<MatrixModelImpl>();
}