#include "MatrixLoadCommand.h"

MatrixLoadCommand::MatrixLoadCommand() {
    _director_id = IdDirectorCreator::MATRIX;
}
void MatrixLoadCommand::Execute() {
    _director_id = IdDirectorCreator::MATRIX;
};