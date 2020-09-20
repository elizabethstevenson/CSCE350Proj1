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
using std::stack;
using std::vector;

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
void printStep(string n, int from, int to) {
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

void moveStackOfPairs(string n, int a, int b, int c) {
    if(n.length()<2) {
        cout << "APPLE ";


        //move a disk from A to C
        printStep(n.at(n.length()-1), a, c);
        //MOVE PEG
        printPegStatus();


        //move a disk from A to B
        printStep(n.at(n.length()-1), a, b);
        //MOVE PEG
        printPegStatus();


        //move a disk from C to B
        printStep(n.at(n.length()-1), c, b);
        //MOVE PEG
        printPegStatus();

    } else {
        cout << "BANANA ";


        moveStackOfPairs((n.at(n.length()-2)), a, b, c);
        

        //move a disk from A to C
        printStep(n.at(n.length()-1), a, c);
        //MOVE PEG
        printPegStatus();
        

        //move another disk from A to C
        printStep(n.at(n.length()-1), a, c);
        //MOVE PEG
        printPegStatus();


        moveStackOfPairs((n.at(n.length()-2)), b, a, c);


        //move a disk from C to B
        printStep(n.at(n.length()-1), c, b);
        //MOVE PEG
        printPegStatus();


        //move another disk from C to B
        printStep(n.at(n.length()-1), c, b);
        //MOVE PEG
        printPegStatus();


        moveStackOfPairs((n.at(n.length()-2)), a, b, c);
    }
}

void solveHuger(string n, int a, int b, int c) {
    if(n.length()<2) {
        cout << "ORANGE ";


        //move a disk from A to C
        printStep(n.at(n.length()-1), a, c);
        //MOVE PEG
        printPegStatus();


        //move a disk from A to B
        printStep(n.at(n.length()-1), a, b);
        //MOVE PEG
        printPegStatus();

    } else {
        cout << "GRAPE ";

        moveStackOfPairs((n.at(n.length()-2)), a, b, c);

        //move a disk from A to C
        printStep(n.at(n.length()-1), a, c);
        //MOVE PEG
        printPegStatus();


        //move a disk from A to B
        printStep(n.at(n.length()-1), a, b);
        //MOVE PEG
        printPegStatus();


        moveStackOfPairs((n.at(n.length()-1)), a, b, c);

        
        //move disk from C to B
        printStep(n.at(n.length()-1), c, b);
        //MOVE PEG
        printPegStatus();


        solveHuger((n.at(n.length()-2)), a, b, c);
    }
}

int main(int argc, char* argv[]) {
    int n; //number of pairs
    cin >> n;

    int a = 0;
    int b = 1;
    int c = 2;

    //making the stack/first peg populated with A1B2C3...
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

    string tower;
    for(unsigned int i = 0; i < pegTemp.size(); ++i){
        tower += pegTemp.at(i);
    }
    //reverse(tower.begin(), tower.end());


    while(cin.good()) { 
        cout << "Starting At:" << endl;
        printPegStatus();
        solveHuger(tower, a, b, c);
        cout << "Done!" << endl;
        stepCounter = 0;
        peg0.clear();
        peg1.clear();
        peg2.clear();
        cin >> n;
    }

    return 0;
}







