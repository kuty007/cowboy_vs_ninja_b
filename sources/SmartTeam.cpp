//
// Created by asaf7 on 5/14/2023.
//

#include "SmartTeam.h"

namespace ariel {
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {

    }

    void SmartTeam::attack(Team *other) {
        if (other == nullptr) {
            throw std::invalid_argument("Team is null");
        }
        if (!other->stillAlive()) {
            throw std::runtime_error("Team is dead");
        }
        if (this->stillAlive()) {
            if (!other->getLeader()->isAlive()) {
                other->setLeader(other->getLeader()->getNearestCharacter(other->getTeam()));
            }
            if (other->getLeader() == nullptr) {
                cout << "Team is dead" << endl;
                return;
            }
            Character *target = nullptr;
//            other->sortVector(other->getTeam(), compare_by_life);
//            for (auto &i: other->getTeam()) {
//                if (i->isAlive()) {
//                    target = i;
//                    break;
//                }
//            }

            for (auto &i: this->getTeam()) {
                if (i->isAlive()) {
                    if (i->isCowboy()) {
                        ariel::Team::sortVector(other->getTeam(), compare_by_life);
                        target = nullptr;
                        for (auto &j: other->getTeam()) {
                            if (j->isAlive()) {
                                target = j;
                                break;
                            }
                        }
                        if (target == nullptr) {
                            cout << "Team is dead" << endl;
                            return;
                        }
                        i->attack(target);
                    } else {
                        target = i->getNearestCharacter(other->getTeam());
                        if (target == nullptr) {
                            cout << "Team is dead" << endl;
                            return;
                        }
                        i->attack(target);
                    }

                }
            }

        }

    }

//    void SmartTeam::add(Character *character) {
//        if (this->getCapacity() < 10 && !character->getBelongToTeam()) {
//            this->getTeam().push_back(character);
//            this->setCapacity(this->getCapacity() + 1);
//        } else if (this->getCapacity() == 10) {
//            throw std::runtime_error("Team is full");
//        } else {
//            throw std::runtime_error("Character already belong to a team");
//        }
//    }

    bool SmartTeam::compare_by_life(Character *a_c, Character *b_c) {
        return a_c->getHealthPoints() < b_c->getHealthPoints();
    }

    void SmartTeam::add(Character *character) {
        Team::add(character);
    }
} // ariel