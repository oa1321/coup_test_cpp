#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    class Captain: public Player{
        public:
            Captain(Game& game, std::string name);
            void block(Player& player);
            void steal(Player& player);

            void coup(Player& player) override;
    };
};