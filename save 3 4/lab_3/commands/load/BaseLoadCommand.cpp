#include "BaseLoadCommand.h"

BaseLoadCommand::~BaseLoadCommand(){}

IdDirectorCreator BaseLoadCommand::GetDirectorId(){ return _director_id; }

IdReaderCreator BaseLoadCommand::GetReaderId(){ return _reader_id; }