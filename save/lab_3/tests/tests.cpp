#include "tests.h"

using namespace std;

void test_readertxt()
{
    try
    {
        shared_ptr<ReaderSolution> reader_solution = make_full_solution();
        shared_ptr<BaseReaderCreator> cr(reader_solution->create(IdReaderCreator::TXT));

        shared_ptr<BaseReader> reader = cr->getReader();
        string filename {"data/pyramid.txt"};
        // string filename {"data/cannotread.txt"};
        reader->open(filename);
        vector<Dot> dots = reader->readDotes();
        size_t countdots = dots.size();
        vector<Link> links = reader->readLinks(countdots);
    }
    catch(const BaseException &err)
    {
        cout << err.what() << '\n';
    }
}

void test_readercsv()
{
    try
    {
        shared_ptr<ReaderSolution> reader_solution = make_full_solution();
        shared_ptr<BaseReaderCreator> cr(reader_solution->create(IdReaderCreator::CSV));

        shared_ptr<BaseReader> reader = cr->getReader();
        string filename {"data/pyramid.csv"};
        // // string filename {"data/cannotread.txt"};
        reader->open(filename);

        // size_t count = reader->readCount();
        // cout << count << '\n';
        // Dot dot = reader->readDot();
        // cout << dot.getX() << " " << dot.getY() << " " << dot.getZ() << endl;

        vector<Dot> dots = reader->readDotes();
        size_t countdots = dots.size();
        vector<Link> links = reader->readLinks(countdots);
    }
    catch(const BaseException &err)
    {
        cout << err.what() << '\n';
    }
}