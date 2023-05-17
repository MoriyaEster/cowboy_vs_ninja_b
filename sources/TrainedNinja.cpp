#include "Ninja.hpp"
#include "TrainedNinja.hpp"
#include "Point.hpp"
#include "Character.hpp"

using namespace ariel;

TrainedNinja::TrainedNinja(std::string name, Point location)
    : Ninja(location, 120, name, 12)
{
}

TrainedNinja::TrainedNinja(const TrainedNinja &other)
    : Ninja(other)
{
}

TrainedNinja::TrainedNinja(TrainedNinja &&other) noexcept
    : Ninja(std::move(other))
{
}

TrainedNinja::~TrainedNinja()
{
}

bool TrainedNinja::operator==(const TrainedNinja &other) const
{
    return (static_cast<const Ninja &>(*this) == static_cast<const Ninja &>(other));
}

TrainedNinja &TrainedNinja::operator=(const TrainedNinja &other)
{
    if (this != &other)
    {
        Ninja::operator=(other);
    }
    return *this;
}


TrainedNinja &TrainedNinja::operator=(TrainedNinja &&other) noexcept
{
    if (this != &other)
    {
        Ninja::operator=(std::move(other));
    }
    return *this;
}