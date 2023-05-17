#include "Character.hpp"

namespace ariel
{
    using namespace std;

    // ************************************************************************//
    Character::Character(Point location, int self_Hit, std::string name)
        : _location(location), _self_Hit(self_Hit), _name(name)
    {
    }

    Character::Character()
        : _location(Point()), _self_Hit(0), _name("Computer")
    {
    }

    Character::Character(const Character &other)
        : _location(other._location), _self_Hit(other._self_Hit), _name(other._name)
    {
    }

    Character::Character(Character &&other) noexcept
        : _location(std::move(other._location)), _self_Hit(std::move(other._self_Hit)), _name(std::move(other._name))
    {
        other._location = Point();
        other._self_Hit = 0;
        other._name = "";
    }

    Character::~Character()
    {
    }

    Character &Character::operator=(const Character &other)
    {
        if (this != &other)
        {
            _location = other._location;
            _self_Hit = other._self_Hit;
            _name = other._name;
        }
        return *this;
    }

    Character &Character::operator=(Character &&other) noexcept
    {
        if (this != &other)
        {
            // Move member variables from the source object
            _location = std::move(other._location);
            _self_Hit = std::move(other._self_Hit);
            _name = std::move(other._name);

            // Reset the moved-from object's data
            other._location = Point();
            other._self_Hit = 0;
            other._name = "";
        }
        return *this;
    }

    bool Character::operator==(const Character &other) const
    {
        return (_location == other._location && _self_Hit == other._self_Hit && _name == other._name);
    }

    // ************************************************************************//

    void Character::setLocation(Point location)
    {
        this->_location = location;
    }
    int Character::getself_Hit()
    {
        return this->_self_Hit;
    }
    void Character::setself_Hit(int self_Hit)
    {
        this->_self_Hit = self_Hit;
    }

    // ************************************************************************//

    bool Character::isAlive()
    {
        if (_self_Hit)
        {
            return true;
        }
        return false;
    }

    double Character::distance(Character &other)
    {
        // this->getLocation().distance(Character::other.getLocation());
        return 0.0;
    }

    void Character::hit(int value)
    {
    }

    std::string Character::getName()
    {
        return this->_name;
    }

    Point Character::getLocation()
    {
        return this->_location;
    }

    std::string Character::print()
    {
        std::ostringstream oss;
        oss << "The name of the character: " << this->getName() << " , The num of self_Hit: " << this->getself_Hit() << " , The location of the character is: ";
        (this->getLocation()).print();
        return oss.str();
    }

}