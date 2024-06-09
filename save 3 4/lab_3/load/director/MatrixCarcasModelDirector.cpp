#include "MatrixCarcasModelDirector.h"
#include "MatrixCarcasModelBuilder.h"

MatrixCarcasModelDirector::MatrixCarcasModelDirector(std::shared_ptr<BaseCarcasModelReader> reader)
: BaseCarcasModelDirector(reader) {
    _builder = std::make_shared<MatrixCarcasModelBuilder>(reader);
}