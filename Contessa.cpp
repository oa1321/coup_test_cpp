#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Contessa.hpp"

namespace coup{
        Contessa::Contessa(Game& game, std::string name): Player(game, std::move(name)){}
        void Contessa::block(Player& player){
            std::cout << "Contessa " << this->player_name << " blocked assassintion " << player.name() << std::endl;
        }
        void Contessa::coup(Player& player){
            std::cout << "Contessa " << this->player_name << " couped " << player.name() << std::endl;
        }
};