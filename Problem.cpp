//
//  problem.cpp
//  cs170project1
//
//  Created by Keila Braden on 4/19/21.
//

#include "Problem.h"
#include "Node.h"
#include <algorithm>

Problem::Problem(){
    return;
}

Problem::Problem (int a, int b, int c, int d, int e, int f, int g, int h, int i){
    initialState = new Node(a, b, c, d, e, f, g, h, i);
    goalState = new Node(1, 2, 3, 4, 5, 6, 7, 8, 0);
}

Node* Problem::getInitialStateNode(){
    return initialState;
}

Node* Problem::getGoalStateNode(){
    return goalState;
}

Node* Problem::move_up(Node* puzzleNode){
    

//    cout << "Before move up: " << endl;
//    puzzleNode->printNode();
//    cout << endl;
    
   // check to see if move is legal
    for(unsigned j = 0; j < 3; ++j){
        if(puzzleNode->puzzle[0][j] == 0){
            cout << "You cannot move the blank space up as it's in the top row" << endl << endl;
            return nullptr;

        }
    }
    
    Node* newNode = new Node();
    
    
    //create new node and move blank space
            for(unsigned i =0; i < 3; ++i){
                for(unsigned j =0; j < 3; ++j){
                    if(puzzleNode->puzzle[i][j] == 0){
                        
                        //create new node
                        //set new node equal to puzzleNode
                        *newNode = *puzzleNode;
                        
                        
                        //set new node's parent pointer equal to puzzleNode
                        newNode->parent = puzzleNode;
                        newNode->gCost = (puzzleNode->gCost) + 1;
                       
                        
                        //swap necessary array elements to complete operation
                        swap(newNode->puzzle[i][j], newNode->puzzle[i-1][j]);
                        newNode->setPuzzleID();
                        //newNode->outputPuzzleID();
                        
                        cout << "Move up: " << endl;
                        newNode->printNode();
                        cout << endl;
                        
                        
                        switch(costChoice){
                            case 1: //uniform cost
                                return newNode;
                                break;
                            case 2: //a* with misplaced tile
                                newNode->hCost = misplacedHeuristic(newNode);
                                return newNode;
                                break;
                            case 3: //a* with euclidean dist.
                                newNode->hCost = euclideanHeuristic(newNode);
                                return newNode;
                                break;
                                
                        }
                    
                    }
                    
                }
            }
    
    
    return nullptr;
    
}
 
Node* Problem::move_left(Node* puzzleNode){
    

//    cout << "Before move left: " << endl;
//    puzzleNode->printNode();
//    cout << endl;

        //check to see if operation is legal
        for(unsigned j = 0; j < 3; ++j){
            if(puzzleNode->puzzle[j][0] == 0){
                cout << "You cannot move the blank space left as it's in the left column." << endl << endl;
                return nullptr;
            }
        }
    
    Node* newNode = new Node();
    
            for(unsigned i =0; i < 3; ++i){
                for(unsigned j =0; j < 3; ++j){
                    if(puzzleNode->puzzle[i][j] == 0){
                        
                        //create new node
                        //set new node equal to puzzleNode
                        *newNode = *puzzleNode;
                        
                        
                        //set new node's parent pointer equal to puzzleNode
                        newNode->parent = puzzleNode;
                        newNode->gCost = (puzzleNode->gCost) + 1;

                        //swap necessary array elements to complete operation
                        swap(newNode->puzzle[i][j], newNode->puzzle[i][j-1]);
                        newNode->setPuzzleID();
                        

                        cout << "Move left: " << endl;
                        newNode->printNode();
                        cout << endl;


                        switch(costChoice){
                            case 1: //uniform cost
                                return newNode;
                                break;
                            case 2: //a* with misplaced tile
                                newNode->hCost = misplacedHeuristic(newNode);
                                return newNode;
                                break;
                            case 3: //a* with euclidean dist.
                                newNode->hCost = euclideanHeuristic(newNode);
                                return newNode;
                                break;

                        }

                    }
                }

            }




    return nullptr;
}

Node* Problem::move_right(Node* puzzleNode){
//
//
//    cout << "Before move right: " << endl;
//    puzzleNode->printNode();
//    cout << endl;

    //check to see if operation is legal
        for(unsigned j = 0; j < 3; ++j){
            if(puzzleNode->puzzle[j][2] == 0){
                cout << "You cannot move the blank space right as it's in the right column." << endl << endl;
                return nullptr;
            }
        }
    
        Node* newNode = new Node();
    
            for(unsigned i =0; i < 3; ++i){
                for(unsigned j =0; j < 3; ++j){
                    if(puzzleNode->puzzle[i][j] == 0){
                        //create new node
                        //set new node equal to puzzleNode
                        *newNode = *puzzleNode;
                        
                        //set new node's parent pointer equal to puzzleNode
                        newNode->parent = puzzleNode;
                        newNode->gCost = (puzzleNode->gCost) + 1;

                        //swap necessary array elements to complete operation
                        swap(newNode->puzzle[i][j], newNode->puzzle[i][j+1]);
                        newNode->setPuzzleID();
                        //newNode->outputPuzzleID();
                        
                        cout << "Move right: " << endl;
                        newNode->printNode();
                        cout << endl;

                        switch(costChoice){
                            case 1:
                                return newNode;
                                break;
                            case 2: //a* with misplaced tile
                                newNode->hCost = misplacedHeuristic(newNode);
                                return newNode;
                                break;
                            case 3:
                                newNode->hCost = euclideanHeuristic(newNode);
                                return newNode;
                                break;

                        }
                    }
                }

            }





    return nullptr;
}

Node* Problem::move_down(Node* puzzleNode){
    

//    cout << "Before move down: " << endl;
//    puzzleNode->printNode();
//    cout << endl;

    //check to see if operation is legal

        for(unsigned j = 0; j < 3; ++j){
            if(puzzleNode->puzzle[2][j] == 0){
                cout << "You cannot move the blank space down as it's in the bottom row." << endl << endl;
                return nullptr;
            }
        }
    
    Node* newNode = new Node();
    
            for(unsigned i =0; i < 3; ++i){
                for(unsigned j =0; j < 3; ++j){
                    if(puzzleNode->puzzle[i][j] == 0){
                        
                        //create new node
                        //set new node equal to puzzleNode
                        *newNode = *puzzleNode;
                        
                        
                        //set new node's parent pointer equal to puzzleNode
                        newNode->parent = puzzleNode;
                        newNode->gCost = (puzzleNode->gCost) + 1;

                        //swap necessary array elements to complete operation
                        swap(newNode->puzzle[i][j], newNode->puzzle[i+1][j]);
                        newNode->setPuzzleID();
                        //newNode->outputPuzzleID();

                        cout << "Move down: " << endl;
                        newNode->printNode();
                        cout << endl;

                        switch(costChoice){
                            case 1: //uniform cost
                                return newNode;
                                break;
                            case 2: //a* with misplaced tile
                                newNode->hCost = misplacedHeuristic(newNode);
                                return newNode;
                                break;
                            case 3: //a* w euclidean distance
                                newNode->hCost = euclideanHeuristic(newNode);
                                return newNode;
                                break;

                        }

                    }

                }

            }



    return nullptr;
}



void Problem::setCostChoice(int choice){
    
    switch(choice){
        case 1:
            this->costChoice = 1;
            break;
        case 2:
            this->costChoice = 2;
            break;
        case 3:
            this->costChoice = 3;
            break;
    }
    
    return;
}


int Problem::getCostChoice(){
    return costChoice;
}

int Problem::misplacedHeuristic(Node* node){
    int sum = 0;
    
    if(node->puzzle[0][0] != 1){
        sum++;
    }
    if(node->puzzle[0][1] != 2){
        sum++;
    }
    if(node->puzzle[0][2] != 3){
        sum++;
    }
    if(node->puzzle[1][0] != 4){
        sum++;
    }
    if(node->puzzle[1][1] != 5){
        sum++;
    }
    if(node->puzzle[1][2] != 6){
        sum++;
    }
    if(node->puzzle[2][0] != 7){
        sum++;
    }
    if(node->puzzle[2][1] != 8){
        sum++;
    }
    if(node->puzzle[2][2] != 0){
        sum++;
    }
    
    return sum;
}


float Problem::euclideanHeuristic(Node* node){ 
    float sum = 0;
    
    for(unsigned i =0; i < 3; ++i){
        for(unsigned j =0; j < 3; ++j){
            sum += computeEuclidean(node->puzzle[i][j], i, j);
        }
    }
    
    return sum;
    

}

float Problem::computeEuclidean(int num, int r, int c){
    int horizontal, vertical = 0;
    
    if(num == 0){
        horizontal = abs(r-2);
        vertical = abs(c-2);
        
        return (sqrt(pow(horizontal, 2) + pow(vertical, 2)) );
    }
    
    if(num == 1){
        horizontal = abs(r-0);
        vertical = abs(c-0);
        
        return (sqrt(pow(horizontal, 2) + pow(vertical, 2)) );
    }
    
    if(num == 2){
        horizontal = abs(r-0);
        vertical = abs(c-1);
        
        return (sqrt(pow(horizontal, 2) + pow(vertical, 2)) );
    }
    
    if(num == 3){
        horizontal = abs(r-0);
        vertical = abs(c-2);
        
        return (sqrt(pow(horizontal, 2) + pow(vertical, 2)) );
    }
    if(num == 4){
        horizontal = abs(r-1);
        vertical = abs(c-0);
        
        return (sqrt(pow(horizontal, 2) + pow(vertical, 2)) );
    }
    
    if(num == 5){
        horizontal = abs(r-1);
        vertical = abs(c-1);
        
        return (sqrt(pow(horizontal, 2) + pow(vertical, 2)) );
    }
    
    if(num == 6){
        horizontal = abs(r-1);
        vertical = abs(c-2);
        
        return (sqrt(pow(horizontal, 2) + pow(vertical, 2)) );
    }
    
    if(num == 7){
        horizontal = abs(r-2);
        vertical = abs(c-0);
        
        return (sqrt(pow(horizontal, 2) + pow(vertical, 2)) );
    }
    
    if(num == 8){
        horizontal = abs(r-2);
        vertical = abs(c-1);
        
        return (sqrt(pow(horizontal, 2) + pow(vertical, 2)) );
    }

    
    return -1;
}
