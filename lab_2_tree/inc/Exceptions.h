#pragma once 

#include "BaseException.h"

class ParantPtrExcetion: public BaseBSTreeException
{
public:
    ParantPtrExcetion(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Parant ptr points not on parant") noexcept:
                  BaseBSTreeException(time, filename, line, class_name, method_name, info){};
};

class AddNodeWithParantExcetion: public BaseBSTreeException
{
public:
    AddNodeWithParantExcetion(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Try add node with parant") noexcept:
                  BaseBSTreeException(time, filename, line, class_name, method_name, info){};
};

class ExpiredException: public BaseIteratorException
{
public:
    ExpiredException(const char *time, const char *filename,
                  const size_t &line, const char *class_name,
                  const char *method_name, const char *info = "Expired weak ptr error") noexcept:
                  BaseIteratorException(time, filename, line, class_name, method_name, info){};
};
