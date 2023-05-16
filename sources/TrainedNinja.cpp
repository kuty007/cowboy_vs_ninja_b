//
// Created by asaf7 on 5/9/2023.
//

#include "TrainedNinja.hpp"

namespace ariel {

    TrainedNinja::TrainedNinja(const string &name, const Point &location) : Ninja(
            name, location) {
        this->setHealthPoints(120);
        this->setSpeed(12);
    }
} // ariel