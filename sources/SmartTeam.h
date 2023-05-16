//
// Created by asaf7 on 5/14/2023.
//

#ifndef COWBOY_VS_NINJA_A_SMARTTEAM_H
#define COWBOY_VS_NINJA_A_SMARTTEAM_H

#include "Team.hpp"

namespace ariel {

    class SmartTeam : public Team {
    public:
        SmartTeam(Character *leader);
        void add(Character *character) override;
        void attack(Team *other) override;

    };

} // ariel

#endif //COWBOY_VS_NINJA_A_SMARTTEAM_H
