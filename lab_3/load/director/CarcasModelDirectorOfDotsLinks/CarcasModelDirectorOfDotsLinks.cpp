#include "CarcasModelDirectorOfDotsLinks.h"
#include "BaseCarcasModelBuilderOfDotsLinks.h"


CarcasModelDirectorOfDotsLinks::CarcasModelDirectorOfDotsLinks(std::shared_ptr<BaseReader> reader)
:_builder(std::make_shared<BaseCarcasModelBuilderOfDotsLinks>())
{
    _reader = reader;
}

std::shared_ptr<BaseModel> CarcasModelDirectorOfDotsLinks::load(std::string &fileName)
{
    _reader->open(fileName);

    _builder->build();

    vector<Dot> dotes = _reader->readDotes();
    size_t dotNum = dotes.size();

    std::vector<Link> links = _reader->readLinks(dotNum);
    size_t linksNum = links.size();

    for (size_t i = 0; i < dotNum; i++)
        _builder->buildDot(dotes[i]);

    for (size_t i = 0; i < linksNum; i++)
        _builder->buildLink(links[i]);

    _reader->close();

    return _builder->get();
}
