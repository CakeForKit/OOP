#pragma once

class BaseReader {
    public:
        BaseReader() = default;
        virtual ~BaseReader() = 0;

        virtual void open() = 0;
        virtual void close() = 0;
        virtual bool is_open() = 0;
};