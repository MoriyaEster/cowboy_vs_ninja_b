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
        Point sourceLocation = this->getLocation();
        Point targetLocation = target->getLocation();

        double distance = sourceLocation.distance(targetLocation);

        if (distance > _speed)
        {
            double dx = targetLocation.getX() - sourceLocation.getX();
            double dy = targetLocation.getY() - sourceLocation.getY();

            double ratio = _speed / distance;

            double newX = sourceLocation.getX() + (dx * ratio);
            double newY = sourceLocation.getY() + (dy * ratio);

            this->setLocation(Point(newX, newY));
        }
        else{
            this->setLocation(targetLocation);
        }
    }
}


void Ninja::slash(Character *target)
{
    if (this->isAlive() && ((this->getLocation()).distance(target->getLocation()) < 1))
    {
        if ((target->getself_Hit() - 40) < 0)
        {
            target->setself_Hit(0);
        }
        target->setself_Hit(target->getself_Hit() - 40);
    }
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

std::string Ninja::print() 
{
    std::ostringstream oss;
    oss << "The name of the character: 'N' - " << this->getName() << " , The num of self_Hit: " << this->getself_Hit() << " , The location of the Ninja is: " << (this->getLocation()).print();
    return oss.str();
}