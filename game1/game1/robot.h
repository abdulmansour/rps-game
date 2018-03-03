#ifndef robot_h
#define robot_h
#include "game.h"
#include "resultNode.h"

class Robot : public Game {
public:
    Robot();
    virtual char play(resultNode * &person, resultNode * &last);
private:
    char rock[10]; //chance of playing rock
    char paper[10]; //chance of playing paper
    char scissor[10]; //chance of player scissor
    char random[3];
    char move;
    int round = 1;
};


#endif /* robot_h */
