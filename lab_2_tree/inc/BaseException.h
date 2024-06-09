#pragma once

#include <ctime>
#include <typeinfo> 
#include <exception>
using namespace std;

class BaseException : public std::exception
{
public:
    BaseException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info) noexcept;

    const char* what() const noexcept override;

    virtual ~BaseException() {};
protected:
    char ErrorInfo[1000];
};

class BaseBSTreeException : public BaseException
{
public:
    BaseBSTreeException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info) noexcept: 
                  BaseException(time, filename, line, class_name, method_name, info) {};

    virtual ~BaseBSTreeException() {};
protected:
    char ErrorInfo[1000];
};

class BaseIteratorException : public BaseException
{
public:
    BaseIteratorException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info) noexcept: 
                  BaseException(time, filename, line, class_name, method_name, info) {};

    virtual ~BaseIteratorException() {};
protected:
    char ErrorInfo[1000];
};