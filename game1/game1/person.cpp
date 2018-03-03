#include <iostream>
#include "person.h"

char Person::play() {
    do {
        std::cout << "ROCK(r), PAPER(p), SCISSOR(s)! : " << std::flush;
        std::cin >> move;
    }
    while (move != 'r' && move!= 'p' && move!= 's');
    return move;
}