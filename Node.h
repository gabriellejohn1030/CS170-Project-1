//
//  Node.hpp
//  cs170project1
//
//  Created by Keila Braden on 4/19/21.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include <iostream>

using namespace std;


class Node {

    
public:
    int gCost;
    float hCost;
    int puzzle[3][3];
    int puzzleID;
    Node* parent;
    
    Node();
    Node(int a, int b, int c, int d, int e, int f, int g, int h, int i);
    void printNode();
    void setCost(int costNum);
    Node(const Node& node);
    int setPuzzleID();
    void outputPuzzleID();
    void printParentNode();
    //void operator=(const Node& node);
    
    
    
};

#endif /* Node_hpp */
