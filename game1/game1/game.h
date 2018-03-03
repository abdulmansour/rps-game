#ifndef game_h
#define game_h
#include "resultNode.h"

class Game : public resultNode {
private:
    resultNode * head = nullptr;//first added element
    resultNode * last = nullptr;//last added element
    bool status = true;
    
public:
    resultNode * get_head();
    resultNode * get_last();
    bool isEmpty(resultNode * &head);
    void first_move(resultNode * &head, resultNode * &last, char move);
    void set_move(resultNode * &head, resultNode * &last, char move);
    virtual char play();
    void execute(resultNode * &player, resultNode * &robot); //need to store outcome char
    void show_list(resultNode * &current);
    void exit(resultNode * person_head, resultNode * robot_head);
    bool get_status();
    void update_status();
    
};


#endif /* game_h */
