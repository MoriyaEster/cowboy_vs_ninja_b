#pragma once

#include "Ninja.hpp"

namespace ariel
{

    class TrainedNinja : public Ninja
    {

    public:
        TrainedNinja(std::string name, Point location);
        TrainedNinja(const TrainedNinja &other);
        TrainedNinja(TrainedNinja &&other) noexcept;
        virtual ~TrainedNinja();

        bool operator==(const TrainedNinja &other) const;
        TrainedNinja &operator=(const TrainedNinja &other);
        TrainedNinja &operator=(TrainedNinja &&other) noexcept;
    };
}
