#pragma once

#include "Ninja.hpp"

namespace ariel
{

    class TrainedNinja : public Ninja
    {

    public:
        TrainedNinja(std::string name, Point location);
        TrainedNinja(const TrainedNinja &other);
        ~TrainedNinja();
        bool operator==(const TrainedNinja &other) const;
    };
}
