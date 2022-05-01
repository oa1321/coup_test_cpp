#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"

namespace coup{
        Assassin::Assassin(Game& game, std::string name): Player(game, std::move(name)){}
        void Assassin::coup(Player& player){
            std::cout << "Assassin " << this->player_name << " assined/coup " << player.name() << std::endl;
        }
};