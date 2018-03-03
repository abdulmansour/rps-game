#ifndef person_h
#define person_h
#include "game.h"
#include "resultNode.h"

class Person : public Game {
public:
    virtual char play();
private:
    char move;
};

#endif /* person_h */
