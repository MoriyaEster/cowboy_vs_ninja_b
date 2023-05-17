#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "Character.hpp"

using namespace ariel;

OldNinja::OldNinja(std::string name, Point location)
    : Ninja(location, 150, name, 8)
{
}

OldNinja::OldNinja(const OldNinja &other)
    : Ninja(other)
{
}
bool OldNinja::operator==(const OldNinja &other) const
{
    return (static_cast<const Ninja &>(*this) == static_cast<const Ninja &>(other));
}

OldNinja::~OldNinja()
{
}
