//
//  problem.hpp
//  cs170project1
//
//  Created by Keila Braden on 4/19/21.
//

#ifndef Problem_h
#define Problem_h

#include <stdio.h>
#include "Node.h"

class Problem : public Node {
    
private:
    Node* initialState;
    Node* goalState;
    int costChoice;
 

public:
    Problem();
    Problem (int a, int b, int c, int d, int e, int f, int g, int h, int i);
    
    Node* getInitialStateNode();
    Node* getGoalStateNode();
    
    //operator functions
    Node* move_up(Node*);
    Node* move_left(Node*);
    Node* move_right(Node*);
    Node* move_down(Node*);
    
    void setCostChoice(int choice);
    int getCostChoice();
    
    int misplacedHeuristic(Node*);
    
    float euclideanHeuristic(Node*);
    float computeEuclidean(int, int, int);

    
    
    
};
#endif /* problem_hpp */
