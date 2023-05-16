//
// Created by asaf7 on 5/14/2023.
//

#include "Team2.hpp"

namespace ariel {
    Team2::Team2(Character *leader) : Team(leader) {


    }

    void Team2::add(Character *character) {
        if (this->getCapacity() < 10 && !character->getBelongToTeam()) {
            this->getTeam().push_back(character);
            this->setCapacity(this->getCapacity()+1);
        } else if (this->getCapacity() == 10) {
            throw std::runtime_error("Team is full");
        } else {
            throw std::runtime_error("Character already belong to a team");
        }
    }
} // ariel