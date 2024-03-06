#ifndef ALGOLIB_HPP
# define ALGOLIB_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>

    class Build {
        public :
            int deck1[52];
            int deck2[52];
            int curentStack1[52];
            int curentStack2[52];

            int stepD1;
            int stepD2;
            int stepS1;
            int stepS2;

            Build(void);
            ~Build(void);

            void cardUp(void);
            bool setValueInDeck(void);
            void setCard(int card1, int card2, int dest);
            void finishCurentDuel(int isd1ord2);
    };

    class Game {
        public :
            // Stat :
            int winner;
            int countRound;
            int countDuel;
            int countBattle;
            int stepCurentDuel;

            // Game Action :
            void    duel(t_data *data);
            void    battle(t_data *data);

            // setup :
            Game(void);
            ~Game(void);
    };

    typedef struct data {
        Build bld;
        Game game;
    }   t_data;

#endif