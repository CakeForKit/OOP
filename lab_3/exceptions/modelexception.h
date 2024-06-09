#pragma once
#include "baseexception.h"

class ModelImplException : public BaseException 
{
    public:
    ModelImplException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Model impl exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class LinkOutOfPointsException : public ModelImplException 
{
    public:
    LinkOutOfPointsException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Link has not existing points exception.")
        : ModelImplException(time, filename, line, class_name, method_name, info){};
};

