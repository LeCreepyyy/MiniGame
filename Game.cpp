#include "algoLib.hpp"

Game::Game(void) {
    winner = 0;
    countDuel = 0;
    countBattle = 0;
    countRound = 0;
    stepCurentDuel = 0;
}

Game::~Game(void) {
    std::cout << "End of game" << std::endl;
}

void    Game::duel(t_data *data) {
    countDuel++;
    if (data->bld.deck1[stepCurentDuel] < data->bld.deck2[stepCurentDuel]) {
        data->bld.curentStack1[data->bld.stepS1] = data->bld.deck1[stepCurentDuel];
        data->bld.curentStack2[data->bld.stepS2] = data->bld.deck2[stepCurentDuel];
    }
    else if (data->bld.deck1[stepCurentDuel] > data->bld.deck2[stepCurentDuel]) {
        data->bld.curentStack1[data->bld.stepS1] = data->bld.deck1[stepCurentDuel];
        data->bld.curentStack2[data->bld.stepS2] = data->bld.deck2[stepCurentDuel];
    }
    else {
        data->bld.curentStack1[data->bld.stepS1] = data->bld.deck1[stepCurentDuel];
        data->bld.curentStack2[data->bld.stepS2] = data->bld.deck2[stepCurentDuel];
        stepCurentDuel++;
        data->bld.stepS1++;
        data->bld.stepS2++;
        battle(data);
    }
}

void    Game::battle(t_data *data) {
    countBattle++;
    data->bld.curentStack1[data->bld.stepS1] = data->bld.deck1[stepCurentDuel];
    data->bld.curentStack2[data->bld.stepS2] = data->bld.deck2[stepCurentDuel];
    stepCurentDuel++;
    data->bld.stepS1++;
    data->bld.stepS2++;
    duel(data);
}
