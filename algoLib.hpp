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

            Build(void);
            ~Build(void);

            bool setValueInDeck(void);
            void setCard(int card1, int card2, int isd1ord2);
    };

    class Game {
        public :
            // Stat :
            int winner;
            int countRound;
            int countBattle;

            // Game Action :
            void    duel(t_data *data);
            void    battle(t_data *data);

            // setup :
            Game(void);
            ~Game(void);
    };

    typedef struct data {
        Build bld;
    }   t_data;

#endif