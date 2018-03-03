#include <iostream>
#include "robot.h"
#include <time.h>

Robot::Robot() {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++) {
        if (i == 8) {
            rock[i] = 'p';
            paper[i] = 'r';
            scissor[i] = 'r';
        }
        else if (i == 9) {
            rock[i] = 's';
            paper[i] = 's';
            scissor[i] = 'p';
        }
        else
        rock[i] = 'r';
        paper[i] = 'p';
        scissor[i] = 's';
    }
    random[0] = 'r';
    random[1] = 'p';
    random[2] = 's';
}

//https://motherboard.vice.com/en_us/article/gvym4x/game-theory-rock-paper-scissors
//first move is random

//The first strategy is the countertactic. Let's say you played scissors and your opponent played rock. The chance that your opponent will confidently play rock again is now very high. What that means to you: anticipate that and play paper. In other words: play the option that wasn't played in the previous round.

//The second strategy is to mirror. If you just won, play what your opponent just played, because he or she will think that you are going to play the same gesture again.

//If tie, simply play as if first move

char Robot::play(resultNode * &person, resultNode * &last){
    if (round == 1) {
        round++;
        return random[rand()%3];
    }
    else if (person->outcome == 'w') {
        if (person->move == 'r' && last->move == 's') {
            return paper[rand()%10];
        }
        else if (person->move == 'p' && last->move == 'r') {
            return scissor[rand()%10];
        }
        else if (person->move == 's' && last->move == 'p') {
            return rock[rand()%10];
        }
    }
    else if (person->outcome == 'l') {
        if (person->move == 'r') {
            return rock[rand()%10];
        }
        else if (person->move == 'p') {
            return paper[rand()%10];
        }
        else if (person->move == 's') {
            return scissor[rand()%10];
        }
    }
    else {
        return random[rand()%3];
    }
    
    return 0;
}
