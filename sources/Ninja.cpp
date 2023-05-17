#include "Ninja.hpp"
#include "Character.hpp"
#include "Point.hpp"

using namespace ariel;

Ninja::Ninja(Point location, int self_Hit, std::string name, int speed)
    : Character(location, self_Hit, name), _speed(speed)
{
}

// Ninja::Ninja(std::string name)
//     :Character(Point(), self_Hit, name), _speed(speed)
// {
// }

void Ninja::move(Character *target)
{
}
void Ninja::slash(Character *target)
{
}

// copy constructor
Ninja::Ninja(const Ninja& other) 
    : Character(other), _speed(other._speed), _type(other._type)
{
}

// destructor
Ninja::~Ninja() {}

// assignment operator
Ninja& Ninja::operator=(const Ninja& other)
{
    if (this != &other)
    {
        Character::operator=(other);
        _speed = other._speed;
        _type = other._type;
    }
    return *this;
}

// equality operator
bool Ninja::operator==(const Ninja& other) const
{
    return Character::operator==(other) && _speed == other._speed && _type == other._type;
}