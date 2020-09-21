//Elizabeth Stevenson
//CSCE350-001 Project1

#include <iostream>
#include <string.h>
#include <stack>
#include <sstream>
#include <bits/stdc++.h>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::stack; //I tried to do it with stacks first but then it got a little too confusing so I switched to vectors
using std::vector;
using std::move;

/*
 n = number of garnet and black pairs
 a = from pole ---> 0
 b = to pole   ---> 1
 c = temp pole ---> 2
*/

unsigned int stepCounter = 0; //used to show number of steps

//3 pegs
vector<string> peg0;
vector<string> peg1;
vector<string> peg2;

vector<string> pegTemp;

//prints which certain disk moved from certain peg to certain peg
//n was supposed to be a string but it would not work well in moveStackOfPairs and solveHuger
void printStep(int n, int from, int to) {
    stepCounter++;
    cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << from << " to peg " << to << ".";
    cout << endl;
}


//entire vector printer
void printVector(vector<string> s) {
    for (unsigned int i = 0; i < s.size(); i++) {
        cout << s.at(i);
    }
}

//prints pegs
void printPegStatus() {
    cout << " 0:";
    printVector(peg0);
    cout << endl;
    cout << " 1:";
    printVector(peg1);
    cout << endl;
    cout << " 2:";
    printVector(peg2);
    cout << endl;
}

/* I originally made the variable n a string so then the disks could 
 * go through the moves from peg to peg but it would not compile 
 * and would not show the labels for the pegs so I changed it back
 * to int to show that. The comments behind the recursion were code that 
 * I was trying to do when n was a string and trying to go through each character.
 * I was trying a lot of different approaches with the recurions with the string
 * but all the trials led to errors.
*/
void moveStackOfPairs(int n, int a, int b, int c) {
    if(n<2) {
        //move a disk from A to C
        printStep(n, a, c);
        peg2.end() = move(peg0.end()); //move(peg0.end(), peg2.end());
        printPegStatus();


        //move a disk from A to B
        printStep(n, a, b);
        peg1.end() = move(peg0.end()); //move(peg0.end(), peg1.end());
        printPegStatus();


        //move a disk from C to B
        printStep(n, c, b);
        peg2.end() = move(peg1.end()); //move(peg2.end(), peg1.end());
        printPegStatus();
    } else {
        moveStackOfPairs(n-1, a, b, c); //moveStackOfPairs(n.at(pegTemp.size()-1), a, b, c);
        
        //move a disk from A to C
        printStep(n, a, c);
        peg2.end() = move(peg0.end()); //move(peg0.end(), peg2.end());
        printPegStatus();
        
        //move another disk from A to C
        printStep(n, a, c);
        peg2.end() = move(peg0.end()); //move(peg0.end(), peg2.end());
        printPegStatus();

        moveStackOfPairs(n-1, a, b, c); //moveStackOfPairs(n.at(pegTemp.size()-1), b, a, c);

        //move a disk from C to B
        printStep(n, c, b);
        peg1.end() = move(peg2.end()); //move(peg2.end(), peg1.end());
        printPegStatus();

        //move another disk from C to B
        printStep(n, c, b);
        peg1.end() = move(peg2.end()); //move(peg2.end(), peg1.end());
        printPegStatus();

        moveStackOfPairs(n, a, b, c); //moveStackOfPairs(n.at(pegTemp.size()-1), a, b, c);
    }
}

/* I also originally made the variable n a string so then the disks could 
 * go through the moves from peg to peg but it would not compile 
 * and would not show the labels for the pegs so I changed it back
 * to int to show that.  The comments behind the recursion were code that 
 * I was trying to do when n was a string and trying to go through each character.
 * I was trying a lot of different approaches with the recurions with the string
 * but all the trials led to errors.
*/
void solveHuger(int n, int a, int b, int c) {
    if(n<2) {
        //move a disk from A to C
        printStep(n, a, c);
        peg2.end() = move(peg0.end()); //move(peg0.end(), peg2.end());
        printPegStatus();


        //move a disk from A to B
        printStep(n, a, b);
        peg1.end() = move(peg0.end()); //move(peg0.end(), peg1.end());
        printPegStatus();
    } else {
        moveStackOfPairs(n-1, a, b, c); //moveStackOfPairs(n.at(pegTemp.size()-1), a, b, c);

        //move a disk from A to C
        printStep(n, a, c);
        peg2.end() = move(peg0.end()); //move(peg0.end(), peg2.end());
        printPegStatus();


        //move a disk from A to B
        printStep(n, a, b);
        peg1.end() = move(peg0.end()); //move(peg0.end(), peg1.end());
        printPegStatus();

        moveStackOfPairs(n-1, a, b, c); //moveStackOfPairs(n.at(pegTemp.size()-1), a, b, c);

        
        //move disk from C to B
        printStep(n, c, b);
        peg1.end() = move(peg2.end()); //move(peg2.end(), peg1.end());
        printPegStatus();

        solveHuger(n-1, a, b, c); //solveHuger(n.at(pegTemp.size()-1), a, b, c);
    }
}

int main(int argc, char* argv[]) {
    int n; //number of pairs
    cin >> n;

    int a = 0;
    int b = 1;
    int c = 2;

    //making the vector/first peg populated with A1B2C3...
    for(int i = 0; i < n; i++) {
        char addLetter = i + 'A';
        char addNumber = i + '1';
        //converting char to string
        string letter;
        string number;
        stringstream letterLetter;
        stringstream numberNumber;
        letterLetter << addLetter;
        letterLetter >> letter;
        numberNumber << addNumber;
        numberNumber >> number;
        pegTemp.push_back(letter);
        peg0.push_back(letter);
        pegTemp.push_back(number);
        peg0.push_back(number);
    }

    //making a string with A1B2C3...
    string tower;
    for(unsigned int i = 0; i < pegTemp.size(); ++i){
        tower += pegTemp.at(i);
    }

    while(cin.good()) { 
        cout << "Starting At:" << endl;
        printPegStatus();
        //solveHuger(tower, a, b, c); this was for when the first parameter was a string
        solveHuger(n, a, b, c);
        cout << "Done!" << endl;
        stepCounter = 0;
        //clears pegs for the next input
        peg0.clear();
        peg1.clear();
        peg2.clear();
        cin >> n;
    }

    return 0;
}
