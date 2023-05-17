#include "Ninja.hpp"
#include "TrainedNinja.hpp"
#include "Point.hpp"
#include "Character.hpp"


using namespace ariel;

TrainedNinja::TrainedNinja(std::string name, Point location)
    :Ninja(location, 120, name, 12)
{
}

TrainedNinja::TrainedNinja(const TrainedNinja& other)
    : Ninja(other)
{
}

TrainedNinja::~TrainedNinja()
{
}

bool TrainedNinja::operator==(const TrainedNinja& other) const
{
    return (static_cast<const Ninja&>(*this) == static_cast<const Ninja&>(other));
}