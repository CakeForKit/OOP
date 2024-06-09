#pragma once
#include "baseexception.h"

class BuilderException : public BaseException 
{
    public:
    BuilderException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Builder exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class CarcasModelBuilderException : public BuilderException
{
    public:
    CarcasModelBuilderException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Carcasmodel builder exception.")
        : BuilderException(time, filename, line, class_name, method_name, info){};
};

class PointsNotReadCarcasModelBuilderException : public CarcasModelBuilderException
{
    public:
    PointsNotReadCarcasModelBuilderException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Points not read yet exception.")
        : CarcasModelBuilderException(time, filename, line, class_name, method_name, info){};
};

class LinksNotReadCarcasModelBuilderException : public CarcasModelBuilderException
{
    public:
    LinksNotReadCarcasModelBuilderException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Links not read yet exception.")
        : CarcasModelBuilderException(time, filename, line, class_name, method_name, info){};
};
