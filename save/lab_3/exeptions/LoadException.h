#pragma once

#include "BaseException.h"

class FileException: public BaseLoadException
{
public:
    FileException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "File stream error ") noexcept:
                  BaseLoadException(time, filename, line, class_name, method_name, info){};
};

class FileOpenException: public BaseLoadException
{
public:
    FileOpenException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "File open error ") noexcept:
                  BaseLoadException(time, filename, line, class_name, method_name, info){};
};

class FileReadCountException: public BaseLoadException
{
public:
    FileReadCountException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Count data error ") noexcept:
                  BaseLoadException(time, filename, line, class_name, method_name, info){};
};

class FileReadDotException: public BaseLoadException
{
public:
    FileReadDotException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Dot data error ") noexcept:
                  BaseLoadException(time, filename, line, class_name, method_name, info){};
};

class FileReadLinkException: public BaseLoadException
{
public:
    FileReadLinkException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Link data error ") noexcept:
                  BaseLoadException(time, filename, line, class_name, method_name, info){};
};

// class DotsNumException: public BaseLoadException
// {
// public:
//     DotsNumException(const char *time, const char *filename,
//                   const size_t line, const char *class_name,
//                   const char *method_name, const char *info = "Dots count error ") noexcept:
//                   BaseLoadException(time, filename, line, class_name, method_name, info){};
// };

// class LinksNumException: public BaseLoadException
// {
// public:
//     LinksNumException(const char *time, const char *filename,
//                   const size_t line, const char *class_name,
//                   const char *method_name, const char *info = "Links count error ") noexcept:
//                   BaseLoadException(time, filename, line, class_name, method_name, info){};
// };

class LinkDataException: public BaseLoadException
{
public:
    LinkDataException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info = "Link index error") noexcept:
                  BaseLoadException(time, filename, line, class_name, method_name, info){};
};

