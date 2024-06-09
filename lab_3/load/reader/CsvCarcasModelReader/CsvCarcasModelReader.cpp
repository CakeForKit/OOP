#include "CsvCarcasModelReader.h"
#include "csvreaderexception.h"

CsvCarcasModelReader::CsvCarcasModelReader(const char* filename) 
: _fname(filename), _centerStrategy(std::make_shared<CenterStrategy>()) {}

CsvCarcasModelReader::~CsvCarcasModelReader() {
    if (is_open()) {
        close();
    }
}

bool CsvCarcasModelReader::is_open() {
    return _file.is_open();
}

void CsvCarcasModelReader::open() {
    if (_file.is_open())
        return;
    _file.open(_fname);
    if (!_file) {
        time_t now = time(nullptr);
        throw CsvNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}

void CsvCarcasModelReader::close() {
    if (!_file.is_open())
        return
    _file.close();
}

std::vector<Point> CsvCarcasModelReader::ReadPoints() {
    if (!is_open())
        return std::vector<Point>();
    std::vector<Point> points;
    _file.clear();
    _file.seekg(0, std::ios::beg);
    
    int size = 0;
    _file >> size;
    points.resize(size);
    char tmp;
    double x, y, z;
    for (int i = 0; i < size; i++) {
        if (!(_file >> x) || !(_file >> tmp) || !(_file >> y) || !(_file >> tmp) || !(_file >> z))
        {
            time_t tm = time(NULL);
            throw CsvReadException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__);
        }
        points[i].SetX(x);
        points[i].SetY(y);
        points[i].SetZ(z);
        
    }

    return points;
}

std::vector<Link> CsvCarcasModelReader::ReadLinks() {
    if (!is_open())
        return std::vector<Link>();
    std::vector<Link> Links;
    ReadPoints();

    int size = 0;
    char tmp;
    int a, b;
    _file >> size;
    Links.resize(size);
    for (int i = 0; i < size; i++) {
        if (!(_file >> a) || !(_file >> tmp) || !(_file >> b))
        {
            time_t tm = time(NULL);
            throw CsvReadException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__);
        }
        Links[i].SetFirst(a - 1);
        Links[i].SetSecond(b - 1);
    }
    return Links;
}


Point CsvCarcasModelReader::ReadCenter() {
    std::vector<Point> points = ReadPoints();
    return _centerStrategy->CenterAlgorithm(points);
}

