#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    class Assassin: public coup::Player{
        public :
            Assassin(coup::Game& game, std::string name);

            void coup(coup::Player& player) override;
    };
};