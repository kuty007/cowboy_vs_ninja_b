//
// Created by asaf7 on 5/9/2023.
//

#include "Team.hpp"

namespace ariel {
    /**
     *get the team leader
     * @return Character pointer to the leader
     */
    Character *Team::getLeader() const {
        return leader;
    }
/**
 * set the team leader
 * @param leader
 */
    void Team::setLeader(Character *leader) {
        Team::leader = leader;
    }
/**
 * add a character to the team
 * @param character
 */
    void Team::add(Character *character) {
        if (capacity < 10 && !character->getBelongToTeam()) {
            this->team.push_back(character);
            this->capacity++;
            character->setBelongToTeam(true);
            ariel::Team::sortVector(this->team, compare);
        } else if (capacity == 10) {
            throw std::runtime_error("Team is full");
        } else {
            throw std::runtime_error("Character already belong to a team");
        }
    }
/**
 * attack the other team
 * @param Team *other
 */
    void Team::attack(Team *other) {
        if (other == nullptr) {
            throw std::invalid_argument("Team is null");
        }
        if (!other->stillAlive()) {
            throw std::runtime_error("Team is dead");
        }
        if (this->stillAlive()) {
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

/**
 * print the team characters
 */
    void Team::print() {
        for (auto &i: this->team) {
            cout << i->print() << endl;
        }

    }
    /**
     * check if the team is still alive
     * @return the number of alive characters
     */

    int Team::stillAlive() {
        int alive = 0;
        for (auto &i: this->team) {
            if (i->isAlive()) {
                alive++;
            }
        }
        return alive;

    }

    /**
     * constructor
     * @param leader
     */

    Team::Team(Character *leader) {
        if (leader->getBelongToTeam()) {
            throw std::runtime_error("Character already belong to a team");
        }
        this->leader = leader;
        leader->setBelongToTeam(true);
        this->capacity = 1;
        this->team.push_back(leader);
    }
    /**
     * destructor
     */
    Team::~Team() {
        //remove all the characters from the team
        for (auto &i: this->team) {
            delete i;
        }
    }
/**
 * compare function for the sort function
 * @param Character* a
 * @param Character* b
 * @return true if a is a cowboy and b is not
 */
    bool Team::compare(Character *a, Character *b) {
        return a->isCowboy() && !b->isCowboy();
    }
    /**
     * sort the vector by the compare function
     * @param characters
     * @param compare
     */
    void Team::sortVector(vector<Character *> &characters, bool (*compare)(Character *, Character *)) {
        std::stable_sort(characters.begin(), characters.end(), compare);
    }
/**
 * set the capacity of the team
 * @param capacity
 */
    void Team::setCapacity(int capacity) {
        Team::capacity = capacity;

    }
    /**
     * get the capacity of the team
     * @return capacity
     */
    int Team::getCapacity() const {
        return capacity;
    }
/**
 * get the team vector
 * @return team vector
 */
    vector<Character *> &Team::getTeam() {
        return team;
    }


} // ariel