#include "Ninja.hpp"
#include "Character.hpp"
#include "Point.hpp"

using namespace ariel;

Ninja::Ninja(Point location, int self_Hit, std::string name, int speed)
    : Character(location, self_Hit, name), _speed(speed)
{
}

void Ninja::move(Character *target)
{
    if (this->isAlive())
    {
        this->setLocation(Point::moveTowards(this->getLocation(), target->getLocation(), _speed));
    }
}

void Ninja::slash(Character *target)
{
    if (target == nullptr)
    {
        throw std::runtime_error("The target is null");
    }
    if (!target->isAlive())
    {
        throw std::runtime_error("The target is dead");
    }
    if (!this->isAlive())
    {
        throw std::runtime_error("The player is dead");
    }
    if (this == target)
    {
        throw std::runtime_error("No self harm");
    }
    if (this->isAlive() && ((this->getLocation()).distance(target->getLocation()) <= 1))
    {
        if ((target->getself_Hit() - 40) < 0)
        {
            target->setself_Hit(0);
        }
        target->setself_Hit(target->getself_Hit() - 40);
    }
}

Ninja::Ninja(const Ninja &other)
    : Character(other), _speed(other._speed), type(other.type)
{
}

Ninja::Ninja(Ninja &&other) noexcept
    : Character(std::move(other)), _speed(other._speed), type(other.type)
{
}

Ninja::~Ninja() {}

Ninja &Ninja::operator=(const Ninja &other)
{
    if (this != &other)
    {
        Character::operator=(other);
        _speed = other._speed;
        type = other.type;
    }
    return *this;
}

Ninja &Ninja::operator=(Ninja &&other) noexcept
{
    if (this != &other)
    {
        Character::operator=(std::move(other));
        _speed = other._speed;
        type = other.type;
    }
    return *this;
}

bool Ninja::operator==(const Ninja &other) const
{
    return Character::operator==(other) && _speed == other._speed && type == other.type;
}

std::string Ninja::print()
{
    std::ostringstream oss;
    oss << "The name of the character: 'N' - " << this->getName() << " , The num of self_Hit: " << this->getself_Hit() << " , The location of the Ninja is: " << (this->getLocation()).print();
    return oss.str();
}