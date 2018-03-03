#include <iostream>
#include <time.h>
#include "game.h"
#include "person.h"
#include "robot.h"
#include "resultNode.h"
using namespace std;

int main() {
    Game rps;
    Person person;
    Robot robot;
    resultNode * person_head = person.get_head();
    resultNode * person_last = person.get_last();
    resultNode * robot_head = robot.get_head();
    resultNode * robot_last = robot.get_last();
    
    while(rps.get_status()) {
        robot.set_move(robot_head,robot_last,robot.play(person_last,robot_last));
        person.set_move(person_head,person_last,person.play());
        rps.execute(person_last,robot_last);
    }
    
    rps.exit(person.get_last(),robot.get_last());
    
    
}
