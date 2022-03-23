//
//  Node.cpp
//  cs170project1
//
//  Created by Keila Braden on 4/19/21.
//

#include "Node.h"

Node::Node(){
    gCost = 0;
    parent = nullptr;
    
    for(unsigned i =0; i < 3; ++i){
        for(unsigned j =0; j < 3; ++j){
            puzzle[i][j] = {0};
        }
    }
    puzzleID = setPuzzleID();
    
}

//copy constructor
Node::Node(const Node& node){
    gCost = node.gCost;
    parent = node.parent;
    
    for(unsigned i =0; i < 3; ++i){
        for(unsigned j =0; i < 3; ++i){
            puzzle[i][j] = node.puzzle[i][j];
        }
    }
    setPuzzleID();
    
}

Node::Node(int a, int b, int c, int d, int e, int f, int g, int h, int i){
    gCost = 0;
    parent = nullptr;
    
    puzzle[0][0] = a;
    puzzle[0][1] = b;
    puzzle[0][2] = c;
    puzzle[1][0] = d;
    puzzle[1][1] = e;
    puzzle[1][2] = f;
    puzzle[2][0] = g;
    puzzle[2][1] = h;
    puzzle[2][2] = i;
    
    puzzleID = setPuzzleID();
    
}

void Node::printNode(){

    
    for(unsigned i =0; i < 3; ++i){
        cout << "| ";
        for(unsigned j =0; j < 3; ++j){
            cout << this->puzzle[i][j] << " ";
        }
        cout << "|" << endl;
    }
}


void Node::setCost(int costNum){
    gCost = costNum;
}

int Node::setPuzzleID(){
    int multiplier = 1;
    int sum = 0;
    
    for(unsigned i = 0; i < 3; ++i){
        for(unsigned j =0; j < 3; ++j){
            sum += (puzzle[i][j] * multiplier);
            multiplier *= 10;
        }
    }
    
    puzzleID = sum;
    return sum;
    
}

void Node::outputPuzzleID(){
    cout << "SUM OF PUZZLE ID: " << puzzleID;
}

void Node::printParentNode(){
    parent->printNode();
    return;
}

//void Node::operator=(const Node& node){
//    gCost = node.gCost;
//    parent = node.parent;
//    
//    for(unsigned i =0; i < 3; ++i){
//        for(unsigned j =0; i < 3; ++i){
//            puzzle[i][j] = node.puzzle[i][j];
//        }
//    }
//}

