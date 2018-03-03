#ifndef resultNode_h
#define resultNode_h

struct resultNode {
    char move;
    char outcome;
    int score = 0;
    resultNode * next;
};


#endif /* resultNode_h */
