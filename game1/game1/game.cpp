#include "game.h"
#include <iostream>

resultNode * Game::get_head() {
    return head;
}
resultNode * Game::get_last() {
    return last;
}

bool Game::isEmpty(resultNode * &head) {
    if (head == nullptr)
        return true;
    else
        return false;
    
}
void Game::first_move(resultNode * &head, resultNode * &last, char move) {
    resultNode * temp = new resultNode;
    head = temp;
    last = temp;
    last->move = move;
    last->next = nullptr;

}
void Game::set_move(resultNode * &head, resultNode * &last, char move) {
    if (isEmpty(head) == true) {
        first_move(head,last,move);
    }
    else {
        resultNode * temp = new resultNode;
        temp->move = move;
        temp->score = last->score;
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}
char Game::play() {return 0;};

void Game::execute(resultNode * &person, resultNode * &robot) { //need to store outcome char
    if (person->move == robot->move) {
        std::cout << "TIE!\nNO POINTS" << std::endl;
        person->outcome = 't'; //tie
        robot->outcome = 't'; //tie
    }
    else if (person->move == 'r' && robot->move == 'p') {
        std::cout << "PAPER BEATS ROCK!" << std::endl;
        person->outcome = 'l'; //loss
        robot->outcome = 'w'; //win
    }
    else if (person->move == 'r' && robot->move == 's') {
        std::cout << "ROCK BEATS SCISSOR!" << std::endl;
        person->outcome = 'w'; //win
        robot->outcome = 'l'; //loss
    }
    else if (person->move == 'p' && robot->move == 'r') {
        std::cout << "PAPER BEATS ROCK!" << std::endl;
        person->outcome = 'w'; //win
        robot->outcome = 'l'; //loss
    }
    else if (person->move == 'p' && robot->move == 's') {
        std::cout << "SCISSOR BEATS PAPER!" << std::endl;
        person->outcome = 'l'; //loss
        robot->outcome = 'w'; //win
    }
    else if (person->move == 's' && robot->move == 'r') {
        std::cout << "ROCK BEATS SCISSOR!" << std::endl;
        person->outcome = 'l'; //loss
        robot->outcome = 'w'; //win
    }
    else if (person->move == 's' && robot->move == 'p') {
        std::cout << "SCISSOR BEATS PAPER" << std::endl;
        person->outcome = 'w'; //win
        robot->outcome = 'l'; //loss
    }
    if(person->outcome == 'w') {
        std::cout << "POINTS PERSON" << std::endl;
        person->score = person->score + 1;
    }
    else if (robot->outcome == 'w') {
        std::cout << "POINTS ROBOT" << std::endl;
        robot->score = robot->score + 1;
    }
    
    std::cout << "SCORE: PERSON(" << person->score << ") - ROBOT(" << robot->score << ")" << std::endl << std::endl;
    
    if (person->score == 3) {
        std::cout << "PERSON WINS!" << std::endl;
        update_status();
    }
    if (robot->score == 3) {
        std::cout << "ROBOT WINS!" << std::endl;
        update_status();
    }
}
void Game::show_list(resultNode * &current) { //start with head until last
    if (isEmpty(current) == true) {
        std::cout << "NO RESULTS" << std::endl;
    }
    else {
        std::cout << current->outcome << std::flush;
        current = current->next;
    }
}
void Game::exit(resultNode * person_head, resultNode * robot_head) {
    resultNode * temp1;
    resultNode * current1;
    resultNode * temp2;
    resultNode * current2;
    current1 = person_head;
    current2 = robot_head;
    while (current1 != nullptr && current2 != nullptr) {
        temp1 = current1;
        temp2 = current2;
        current1 = current1->next;
        current2 = current2->next;
        delete temp1;
        delete temp2;
    }
    
}
bool Game::get_status() {
    return status;
}
void Game::update_status() {
    status = false;
}

