#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"

using namespace ariel;

Cowboy::Cowboy(std::string name, Point location)
    : Character(location, 110, name)
{
    _num_Of_bolls = 6;
}

Cowboy::Cowboy(Cowboy &other)
    : Character(other.getLocation(), 110, other.getName())
{
}

Cowboy::Cowboy(Cowboy &&other) noexcept
    : Character(std::move(other)), _num_Of_bolls(6)
{
    // No need to move the _type member as it is a primitive type (char)
}

Cowboy::~Cowboy()
{
}

// ********************************************************************** //

void Cowboy::shoot(Character *target)
{
}

bool Cowboy::hasboolets()
{
    return true;
}

void Cowboy::reload()
{
    _num_Of_bolls += 6;
}

// ********************************************************************** //

int Cowboy::getNum_Of_bolls()
{
    return _num_Of_bolls;
}

char Cowboy::getType()
{
    return _type;
}

bool Cowboy::operator==(const Cowboy &other)
{
    return true;
}

Cowboy &Cowboy::operator=(Cowboy &&other) noexcept
{
    if (this != &other)
    {
        Character::operator=(std::move(other)); // Move assign base class members

        _num_Of_bolls = other._num_Of_bolls;
        other._num_Of_bolls = 0;

        // No need to move the _type member as it is a primitive type (char)
    }
    return *this;
}

