#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Captain.hpp"

namespace coup{
        Captain::Captain(Game& game, std::string name): Player(game, std::move(name)){}
        void Captain::block(Player& player){
            std::cout << "Captain " << this->player_name << " blocked stealing " << player.name() << std::endl;
        }
        void Captain::steal(Player& player){
            std::cout << "Captain " << this->player_name << " stole coins from " << player.name() << std::endl;
        }

        void Captain::coup(Player& player){
            std::cout << "Captain " << this->player_name << " couped " << player.name() << std::endl;
        }  
};