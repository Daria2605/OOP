#ifndef NPC_H
#define NPC_H

#include <string>
#include <iostream>

class NPC {
protected:
    std::string name;
    int x, y;

public:
    NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}
    virtual ~NPC() = default;

    virtual std::string getType() const = 0;
    virtual void print() const {
        std::cout << getType() << " " << name << " at (" << x << ", " << y << ")" << std::endl;
    }

    int getX() const { return x; }
    int getY() const { return y; }
    std::string getName() const { return name; }
};

class Knight : public NPC {
public:
    Knight(const std::string& name, int x, int y) : NPC(name, x, y) {}
    std::string getType() const override { return "Knight"; }
};

class Druid : public NPC {
public:
    Druid(const std::string& name, int x, int y) : NPC(name, x, y) {}
    std::string getType() const override { return "Druid"; }
};

class Elf : public NPC {
public:
    Elf(const std::string& name, int x, int y) : NPC(name, x, y) {}
    std::string getType() const override { return "Elf"; }
};

#endif // NPC_H