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

Ninja::Ninja(const Ninja &other)
    : Character(other), _speed(other._speed), _type(other._type)
{
}

Ninja::Ninja(Ninja &&other) noexcept
    : Character(std::move(other)), _speed(other._speed), _type(other._type)
{
}

Ninja::~Ninja() {}

Ninja &Ninja::operator=(const Ninja &other)
{
    if (this != &other)
    {
        Character::operator=(other);
        _speed = other._speed;
        _type = other._type;
    }
    return *this;
}

Ninja &Ninja::operator=(Ninja &&other) noexcept
{
    if (this != &other)
    {
        Character::operator=(std::move(other));
        _speed = other._speed;
        _type = other._type;
    }
    return *this;
}

bool Ninja::operator==(const Ninja &other) const
{
    return Character::operator==(other) && _speed == other._speed && _type == other._type;
}