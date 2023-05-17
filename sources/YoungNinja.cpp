#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "Character.hpp"

using namespace ariel;

YoungNinja::YoungNinja(std::string name, Point location)
    : Ninja(location, 100, name, 14)
{
}

YoungNinja::YoungNinja(const YoungNinja &other)
    : Ninja(other)
{
}

YoungNinja::~YoungNinja()
{
}

bool YoungNinja::operator==(const YoungNinja &other) const
{
    return (static_cast<const Ninja &>(*this) == static_cast<const Ninja &>(other));
}