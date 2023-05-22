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
}

Cowboy::~Cowboy()
{
}

// ********************************************************************** //

void Cowboy::shoot(Character *target)
{
    if (!target->isAlive())
    {
        throw std::runtime_error("the target is dead");
    }
    if (!this->isAlive())
    {
        throw std::runtime_error("the player is dead");
    }
    if (this->isAlive() && this->getNum_Of_bolls())
    {
        target->hit(10);
        this->_num_Of_bolls--;
    }
}

bool Cowboy::hasboolets()
{
    if (this->getNum_Of_bolls() > 0)
    {
        return true;
    }
    return false;
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
    return type;
}

bool Cowboy::operator==(const Cowboy &other)
{
    return Character::operator==(other) && _num_Of_bolls == other._num_Of_bolls && type == other.type;
}

Cowboy &Cowboy::operator=(Cowboy &&other) noexcept
{
    if (this != &other)
    {
        Character::operator=(std::move(other));

        _num_Of_bolls = other._num_Of_bolls;
        other._num_Of_bolls = 0;
    }
    return *this;
}

std::string Cowboy::print()
{
    std::ostringstream oss;
    oss << "The name of the character: 'C' - " << this->getName() << " , The num of self_Hit: " << this->getself_Hit() << " , The location of the Cowboy is: " << (this->getLocation()).print();
    return oss.str();
}
