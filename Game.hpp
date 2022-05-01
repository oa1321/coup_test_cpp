#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#pragma once

namespace coup{
    class Game{
        private:
            std::vector<std::string> all_players;
            std::string currentPlayer;
            int player_amount;
            int turn_number; // for debuging
            int alivePlayers;

        public:
            Game();
            void AddPlayer(const std::string &player);
            std::vector<std::string> players();
            std::string turn();
            std::string winner();

    };
};