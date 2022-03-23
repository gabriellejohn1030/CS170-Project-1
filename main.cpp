

#include <iostream>
#include "Node.h"
#include "Problem.h"
#include <queue>
#include <map>

using namespace std;


struct compareCost {
    float operator()(const Node* cost1, const Node* cost2) const
    {
        float sum1, sum2 = 0;
        sum1 = cost1->gCost + cost1->hCost;
        sum2 = cost2->gCost + cost2->hCost;
        
        return sum1 > sum2;
    }
};


int main(int argc, const char * argv[]) {
    
    Problem *problem;
    
    int exploredSum = 0;
    int maxNumFrontier = 0;
    int input, input2;
    int a, b, c, d, e, f, g, h, i;
        
    
    cout << "Welcome to kbrad013 and gjohn010's 8 puzzle solver." << endl;
    cout << "Type “1” to use a default puzzle, or “2” to enter your own puzzle. (Use 0 for the blank)." << endl << endl;
    
    cin >> input;
    
    if(input == 1){
        cout << "Please choose from one of the following puzzles: " << endl;
        cout << "1. Trivial" << endl
             << "2. Very easy" << endl
             << "3. Easy" << endl
             << "4. Doable" << endl
             << "5. Oh boy" << endl
             << "6. Impossible" << endl << endl;
        
        cin >> input2;
        switch(input2){
            case 1:
                problem = new Problem(1, 2, 3, 4, 5, 6, 7, 8, 0);
                break;
            case 2:
                problem = new Problem(1, 2, 3, 4, 5, 6, 7, 0, 8);
                break;
            case 3:
                problem = new Problem(1, 2, 0, 4, 5, 3, 7, 8, 6);
                break;
            case 4:
                problem = new Problem(0, 1, 2, 4, 5, 3, 7, 8, 6);
                break;
            case 5:
                problem = new Problem(8, 7, 1, 6, 0, 2, 5, 4, 3);
                break;
            case 6:
                problem = new Problem(1, 2, 3, 4, 5, 6, 8, 7, 0);
                break;
        }
    }
    
    if(input == 2){
        cout << "Please enter your integers (press enter after each one." << endl;
        cin >> a;
        cin >> b;
        cin >> c;
        cin >> d;
        cin >> e;
        cin >> f;
        cin >> g;
        cin >> h;
        cin >> i;
        
        problem = new Problem(a, b, c, d, e, f, g, h, i);
    }
            
            
            
    
    
    cout << "Enter your choice of algorithm: " << endl <<
            "1. Uniform Cost Search " << endl <<
            "2. A* with the Misplaced Tile heuristic" << endl <<
            "3. A* with the Eucledian distance heuristic" << endl << endl;
    
    cin >> input;
    
    switch(input){
        case 1:
            problem->setCostChoice(1);
            break;
        case 2:
            problem->setCostChoice(2);
            break;
        case 3:
            problem->setCostChoice(3);
            break;
    }
    
    
    //initialize frontier using initial state of the problem
    priority_queue<Node*, vector<Node*>, compareCost> frontier; //create a prirorty queue in ascending order (like a min heap)
    frontier.push(problem->getInitialStateNode());

    //initialize explored set to be empty
    map<int, Node*> explored_set;
    
    //**initializing a set to hold current contents of frontier
    //for duplicate checking (if a node is in the frontier but not yet in explored set)
    map<int, Node*> current_frontier_set;
    current_frontier_set.insert(pair<int, Node*>((problem->getInitialStateNode())->puzzleID, problem->getInitialStateNode()));

    Node* current_node;
    Node* new_current_node; //node initialized to take on the return value (this value is of type Node*) which results from calling op functions
    
    cout << "Expanding state: " << endl;
    problem->getInitialStateNode()->printNode();

    
    while(true){
        //if frontier is empty, return failure, exit program
        if(frontier.empty()){
            cout << "Failed to find solution, frontier is empty." << endl;
            cout << "To solve this problem the search algorithm expanded a total of " << exploredSum << " nodes. " << endl;
            cout << "The maximum number of nodes in the queue at any one time: " << maxNumFrontier << "." << endl;
            exit(0);
        }
        
        //choose leaf node and remove from frontier
        current_node = frontier.top();
        cout << "The best state to expand with g(" << current_node->gCost <<") and h(" << current_node->hCost << ") is: " << endl;
        current_node->printNode();
        cout << endl;
        cout << "Expanding this node..." << endl << endl;
        
        //delete frontier.top();
        frontier.pop();
        
        
        
        //goal check
        if(current_node->puzzleID == (problem->getGoalStateNode())->puzzleID){
                cout << "Solution has been found." << endl;
                cout << "To solve this problem the search algorithm expanded a total of " << exploredSum << " nodes. " << endl;
                cout << "The maximum number of nodes in the queue at any one time: " << maxNumFrontier << "." << endl;
                
                return 0;
        }

        
        
        //add node to explored set
        explored_set.insert(pair<int, Node*>(current_node->puzzleID, current_node));
        exploredSum++;
        
        
        //expand current node:
        new_current_node = problem->move_up(current_node);
        
        if((new_current_node != NULL) &&
           (explored_set.find(new_current_node->puzzleID) == explored_set.end()) &&
           (current_frontier_set.find(new_current_node->puzzleID) == current_frontier_set.end())){ //move_up() returns nullptr if operation is illegal


            frontier.push(new_current_node); //add resulting node to frontier
            current_frontier_set.insert(pair<int, Node*>(new_current_node->puzzleID, new_current_node));
            
            if(frontier.size() > maxNumFrontier){
                maxNumFrontier = frontier.size();
            }

        }


        new_current_node = problem->move_down(current_node);

        if((new_current_node != NULL) &&
           (explored_set.find(new_current_node->puzzleID) == explored_set.end()) &&
           (current_frontier_set.find(new_current_node->puzzleID) == current_frontier_set.end())){

            frontier.push(new_current_node);
            current_frontier_set.insert(pair<int, Node*>(new_current_node->puzzleID, new_current_node));
            
            if(frontier.size() > maxNumFrontier){
                maxNumFrontier = frontier.size();
            }

        }

        new_current_node = problem->move_left(current_node);

        if((new_current_node != NULL) &&
           (explored_set.find(new_current_node->puzzleID) == explored_set.end()) &&
           (current_frontier_set.find(new_current_node->puzzleID) == current_frontier_set.end())){

            frontier.push(new_current_node);
            current_frontier_set.insert(pair<int, Node*>(new_current_node->puzzleID, new_current_node));
            
            if(frontier.size() > maxNumFrontier){
                maxNumFrontier = frontier.size();
            }
        }

        new_current_node = problem->move_right(current_node);

        if((new_current_node != NULL) &&
           (explored_set.find(new_current_node->puzzleID) == explored_set.end()) &&
           (current_frontier_set.find(new_current_node->puzzleID) == current_frontier_set.end())){

            frontier.push(new_current_node);
            current_frontier_set.insert(pair<int, Node*>(new_current_node->puzzleID, new_current_node));
            
            if(frontier.size() > maxNumFrontier){
                maxNumFrontier = frontier.size();
            }
        }
        
        

    }
    
    
    
    return 0;
    }






