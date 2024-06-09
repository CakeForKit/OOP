#pragma once
#include "baseexception.h"

class CsvReaderException : public BaseException 
{
    public:
    CsvReaderException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Csv Reader exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class CsvNoFileException : public CsvReaderException
{
    public:
    CsvNoFileException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Can't open csv file exception.")
        : CsvReaderException(time, filename, line, class_name, method_name, info){};
};

class CsvReadException : public CsvReaderException
{
    public:
    CsvReadException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Can't read from csv file exception.")
        : CsvReaderException(time, filename, line, class_name, method_name, info){};
};