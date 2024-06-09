#include "MatrixLoadCommand.h"

MatrixLoadCommand::MatrixLoadCommand() {
    _director_id = IdDirectorCreator::LIST;
}
void MatrixLoadCommand::Execute() {
    _director_id = IdDirectorCreator::LIST;
};