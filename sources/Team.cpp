//
// Created by asaf7 on 5/9/2023.
//

#include "Team.hpp"

namespace ariel {
    Character *Team::getLeader() const {
        return leader;
    }

    void Team::add(Character *character) {
        if (capacity < 10 && !character->getBelongToTeam()) {
            this->team.push_back(character);
            this->capacity++;
            character->setBelongToTeam(true);
            ariel::Team::sortVector(this->team);
        } else if (capacity == 10) {
            throw std::runtime_error("Team is full");
        } else {
            throw std::runtime_error("Character already belong to a team");
        }
    }

    void Team::attack(Team *other) {
        if (other == nullptr) {
            throw std::invalid_argument("Team is null");
        }
        if (!other->stillAlive()) {
            throw std::runtime_error("Team is dead");
        }
        if (this->stillAlive() && other->stillAlive()) {
            if (!other->getLeader()->isAlive()) {
                other->leader = other->leader->getNearestCharacter(other->team);
            }
            if (!this->leader->isAlive()) {
                this->leader = this->leader->getNearestCharacter(this->team);
            }
            if (other->getLeader() == nullptr) {
                cout << "Team is dead" << endl;
                return;
            }
            Character *target = this->leader->getNearestCharacter(other->team);
            if (target == nullptr) {
                cout << "Team is dead" << endl;
                return;
            }
            for (auto &i: this->team) {
                if (i->isAlive()) {
                    if (!target->isAlive()) {
                        target = this->leader->getNearestCharacter(other->team);
                        if (target == nullptr) {
                            cout << "Team is dead" << endl;
                            return;
                        }
                    }
                    i->attack(target);
                }
            }

        }

    }


    void Team::print() {
        for (auto &i: this->team) {
            cout << i->print() << endl;
        }

    }

    int Team::stillAlive() {
        int alive = 0;
        for (auto &i: this->team) {
            if (i->isAlive()) {
                alive++;
            }
        }
        return alive;

    }

    Team::Team(Character *leader) {
        if (leader->getBelongToTeam()) {
            throw std::runtime_error("Character already belong to a team");
        }
        this->leader = leader;
        leader->setBelongToTeam(true);
        this->capacity = 1;
        this->team.push_back(leader);
    }

    Team::~Team() {
        //remove all the characters from the team
        for (auto &i: this->team) {
            delete i;
        }
    }

    bool Team::compare(Character *a, Character *b) {
        return a->isCowboy() && !b->isCowboy();
    }

    void Team::sortVector(vector<Character *> &characters) {
        std::stable_sort(characters.begin(), characters.end(), compare);
    }

    void Team::setCapacity(int capacity) {
        Team::capacity = capacity;

    }

    int Team::getCapacity() const {
        return capacity;
    }

    vector<Character *> &Team::getTeam() {
        return team;
    }


//    Team::~Team() {
//
//    }
} // ariel