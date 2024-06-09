#pragma once
#include "baseexception.h"

class DirectorException : public BaseException 
{
    public:
    DirectorException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Director exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class CarcasModelDirectorException : public DirectorException
{
    public:
    CarcasModelDirectorException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Carcasmodel director exception.")
        : DirectorException(time, filename, line, class_name, method_name, info){};
};

class CarcasModelDirectorWrongReaderException : public CarcasModelDirectorException
{
    public:
    CarcasModelDirectorWrongReaderException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Wrong Reader type passed to director, expected BaseCarcasModelReader exception.")
        : CarcasModelDirectorException(time, filename, line, class_name, method_name, info){};
};