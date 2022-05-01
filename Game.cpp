#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"

namespace coup{
    Game::Game(): player_amount(0), turn_number(0), alivePlayers(0), currentPlayer(""){}
    void Game::AddPlayer(const std::string& player){
        std::cout << "Adding player: " << player << std::endl;
        this->all_players.push_back(player);
        this->player_amount++;
        this->alivePlayers++;
    }
    std::vector<std::string> Game::players(){
        //returns alive players
        return this->all_players;
    }
    std::string Game::turn(){
        std::cout << "Turn: " << this->turn_number << std::endl;
        return this->currentPlayer;
    }
    std::string Game::winner(){
        std::cout << "Winner: " << this->currentPlayer << std::endl;
        return this->currentPlayer;
    }

};