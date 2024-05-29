#include "BaseCarcasModelDirector.h"
#include "BaseReader.h"
#include "BaseCarcasModelBuilderOfDotsLinks.h"

class CarcasModelDirectorOfDotsLinks : public BaseCarcasModelDirector
{
public:
    CarcasModelDirectorOfDotsLinks(std::shared_ptr<BaseReader> reader);

    ~CarcasModelDirectorOfDotsLinks() override = default;

    std::shared_ptr<BaseModel> load(std::string &fileName);

protected:
    std::shared_ptr<BaseReader> _reader;
    std::shared_ptr<BaseCarcasModelBuilderOfDotsLinks> _builder;
};

