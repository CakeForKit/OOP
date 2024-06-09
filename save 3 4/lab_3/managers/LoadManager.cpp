#include "LoadManager.h"
#include "managerexception.h"
#include "ReaderCreator.h"
#include "ReaderSolution.h"

LoadManager::LoadManager() {
    _dsolution.Register(IdDirectorCreator::LIST, std::make_shared<ListCarcasModelDirectorCreator>());
    _dsolution.Register(IdDirectorCreator::MATRIX, std::make_shared<MatrixCarcasModelDirectorCreator>());

    _rsolution.Register(IdReaderCreator::TXT, std::make_shared<TxtCarcasModelReaderCreator>());
    _rsolution.Register(IdReaderCreator::CSV, std::make_shared<CsvCarcasModelReaderCreator>());
}


std::shared_ptr<Object> LoadManager::LoadCarcasModelFile(IdDirectorCreator directorID, IdReaderCreator ReaderID, const char* filename) {
    std::shared_ptr<BaseDirectorCreator> absDirectorCr = _dsolution.Create(directorID);
    std::shared_ptr<BaseReaderCreator> absReaderCr = _rsolution.Create(ReaderID);

    std::shared_ptr<CarcasModelDirectorCreator_t> carcasModelDirectorCr = std::dynamic_pointer_cast<CarcasModelDirectorCreator_t>(absDirectorCr);
    if (carcasModelDirectorCr == nullptr) {
        time_t now = time(nullptr);
        throw LoadManagerWrongDirectorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<CarcasModelReaderCreator_t> carcasModelReaderCr = std::dynamic_pointer_cast<CarcasModelReaderCreator_t>(absReaderCr);
    if (carcasModelReaderCr == nullptr) {
        time_t now = time(nullptr);
        throw LoadManagerWrongReaderException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<BaseCarcasModelReader> carcasModelReader = carcasModelReaderCr->Create(std::move(filename));
    std::shared_ptr<BaseCarcasModelDirector> carcasModelDirector = carcasModelDirectorCr->Create(std::move(carcasModelReader));
    // carcasModelDirector->Create();
    return carcasModelDirector->Get();
};