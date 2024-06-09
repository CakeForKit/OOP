#include "ListLoadCommand.h"

ListLoadCommand::ListLoadCommand() {
    _director_id = IdDirectorCreator::LIST;
}
void ListLoadCommand::Execute() {
    _director_id = IdDirectorCreator::LIST;
};