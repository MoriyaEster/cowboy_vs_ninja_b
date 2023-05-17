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

OldNinja::OldNinja(OldNinja &&other) noexcept
    : Ninja(std::move(other))
{
}

OldNinja::~OldNinja()
{
}

OldNinja &OldNinja::operator=(const OldNinja &other)
{
    if (this != &other)
    {
        Ninja::operator=(other);
    }
    return *this;
}

bool OldNinja::operator==(const OldNinja &other) const
{
    return (static_cast<const Ninja &>(*this) == static_cast<const Ninja &>(other));
}

OldNinja &OldNinja::operator=(OldNinja &&other) noexcept
{
    if (this != &other)
    {
        Ninja::operator=(std::move(other));
    }
    return *this;
}
