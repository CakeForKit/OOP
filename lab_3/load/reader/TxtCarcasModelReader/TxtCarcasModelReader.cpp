#include "TxtCarcasModelReader.h"
#include "txtreaderexception.h"

TxtCarcasModelReader::TxtCarcasModelReader(const char* filename) : _fname(filename), _centerStrategy(std::make_shared<CenterStrategy>()) {}

TxtCarcasModelReader::~TxtCarcasModelReader() {
    if (is_open()) {
        close();
    }
}

bool TxtCarcasModelReader::is_open() {
    return _file.is_open();
}

void TxtCarcasModelReader::open() {
    if (_file.is_open())
        return;
    _file.open(_fname);
    if (!_file) {
        time_t now = time(nullptr);
        throw TxtNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}

void TxtCarcasModelReader::close() {
    if (!_file.is_open())
        return
    _file.close();
}

std::vector<Point> TxtCarcasModelReader::ReadPoints() {
    if (!is_open())
        return std::vector<Point>();
    std::vector<Point> points;
    _file.clear();
    _file.seekg(0, std::ios::beg);
    
    int size = 0;
    _file >> size;
    points.resize(size);
    double x, y, z;
    for (int i = 0; i < size; i++) {
        _file >> x >> y >> z;
        if (!_file) {
            time_t now = time(nullptr);
            throw TxtNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }
        points[i].SetX(x);
        points[i].SetY(y);
        points[i].SetZ(z);
        
    }

    return points;
}

std::vector<Link> TxtCarcasModelReader::ReadLinks() {
    if (!is_open())
        return std::vector<Link>();
    std::vector<Link> Links;
    ReadPoints();

    int size = 0;
    _file >> size;
    Links.resize(size);
    for (int i = 0; i < size; i++) {
        int a, b;
        _file >> a >> b;
        if (!_file) {
            time_t now = time(nullptr);
            throw TxtNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }
        Links[i].SetFirst(a - 1);
        Links[i].SetSecond(b - 1);
    }
    return Links;
}


Point TxtCarcasModelReader::ReadCenter() {
    std::vector<Point> points = ReadPoints();
    return _centerStrategy->CenterAlgorithm(points);
}

