//
// Created by asaf7 on 5/14/2023.
//

#include "SmartTeam.h"

namespace ariel {
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {

    }

    void SmartTeam::attack(Team *other) {
//        if (this->stillAlive() && other->stillAlive()) {
//            if (!other->getLeader()->isAlive()) {
//                other->leader = other->leader->getNearestCharacter(other->team);
//            }
//            if (other->getLeader() == nullptr) {
//                cout << "Team is dead" << endl;
//                return;
//            }
//            Character *target = nullptr;
//
//            for (auto &i: this->team) {
//                if (i->alive) {
//                    if(i->is_cowboy)
//                    if (!target->isAlive()) {
//                        target = this->leader->getNearestCharacter(other->team);
//                    }
//                    i->attack(target);
//                }
//            }
//
//        }

    }

    void SmartTeam::add(Character *character) {
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