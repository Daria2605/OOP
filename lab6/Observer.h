#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <fstream>
#include <iostream>

class Observer {
public:
    virtual void update(const std::string& event) = 0;
    virtual ~Observer() = default;
};

class FileLogger : public Observer {
private:
    std::string filename;

public:
    FileLogger(const std::string& filename) : filename(filename) {}

    void update(const std::string& event) override {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << event << std::endl;
            file.close();
        }
    }
};

class ScreenLogger : public Observer {
public:
    void update(const std::string& event) override {
        std::cout << event << std::endl;
    }
};

#endif // OBSERVER_H