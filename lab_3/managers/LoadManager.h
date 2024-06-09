#pragma once
#include "DirectorSolution.h"
#include "ReaderSolution.h"
#include <cstdlib>
#include <memory>


class LoadManager {
    public:
        LoadManager();
        ~LoadManager() = default;

        std::shared_ptr<Object> LoadCarcasModelFile(IdDirectorCreator directorID, IdReaderCreator readerID, const char *filename);

    protected:
        DirectorSolution _dsolution;
        ReaderSolution _rsolution;
};