//Elizabeth Stevenson
//CSCE350-001 Project1

#include <iostream>
#include <string.h>
#include <stack>
#include <sstream>
#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::stack;

/*
 n = number of garnet and black pairs
 a = from pole ---> 0
 b = to pole   ---> 1
 c = temp pole ---> 2
*/

int stepCounter = 0; //used to show number of steps

//3 pegs
stack<string> peg0;
stack<string> peg1;
stack<string> peg2;

stack<string> pegTemp;

//prints which certain disk moved from certain peg to certain peg
void printStep(int n, int from, int to) {
    stepCounter++;
    cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << from << " to peg " << to << ".";
    cout << endl;
}


//stack printer
void printStack(stack<string> s) {
    if(s.empty()) {
        return;
    }
    string value = s.top();
    s.pop();
    printStack(s);
    cout << value;
    s.push(value);
}

//prints pegs
void printPegStatus() {
    cout << " 0:";
    printStack(peg0);
    cout << endl;
    cout << " 1:";
    printStack(peg1);
    cout << endl;
    cout << " 2:";
    printStack(peg2);
    cout << endl;
}

void moveStackOfPairs(int n, int a, int b, int c) {
    if(n<2) {
        cout << "APPLE ";


        //move a disk from A to C
        printStep(n, a, c);
        //MOVE PEG
        printPegStatus();


        //move a disk from A to B
        printStep(n, a, b);
        //MOVE PEG
        printPegStatus();


        //move a disk from C to B
        printStep(n, c, b);
        //MOVE PEG
        printPegStatus();

    } else {
        cout << "BANANA ";


        moveStackOfPairs((n-1), a, b, c);
        

        //move a disk from A to C
        printStep(n, a, c);
        //MOVE PEG
        printPegStatus();
        

        //move another disk from A to C
        printStep(n, a, c);
        //MOVE PEG
        printPegStatus();


        moveStackOfPairs((n-1), b, a, c);


        //move a disk from C to B
        printStep(n, c, b);
        //MOVE PEG
        printPegStatus();


        //move another disk from C to B
        printStep(n, c, b);
        //MOVE PEG
        printPegStatus();


        moveStackOfPairs((n-1), a, b, c);
    }
}

void solveHuger(int n, int a, int b, int c) {
    if(n<2) {
        cout << "ORANGE ";


        //move a disk from A to C
        printStep(n, a, c);
        //MOVE PEG
        printPegStatus();


        //move a disk from A to B
        printStep(n, a, b);
        //MOVE PEG
        printPegStatus();

    } else {
        cout << "GRAPE ";


        moveStackOfPairs((n-1), a, b, c);


        //move a disk from A to C
        printStep(n, a, c);
        //MOVE PEG
        printPegStatus();


        //move a disk from A to B
        printStep(n, a, b);
        //MOVE PEG
        printPegStatus();


        moveStackOfPairs((n-1), a, b, c);

        
        //move disk from C to B
        printStep(n, c, b);
        //MOVE PEG
        printPegStatus();


        solveHuger((n-1), a, b, c);
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
        pegTemp.push(letter);
        peg0.push(letter);
        pegTemp.push(number);
        peg0.push(number);
    }

    string tower;
    for(int i = pegTemp.size(); i > 0; i--){
        tower += pegTemp.top();
        pegTemp.pop();
    }
    reverse(tower.begin(), tower.end());

    while(cin.good()) { 
        cout << "Starting At:" << endl;
        printPegStatus();
        solveHuger(n, a, b, c);
        cout << "Done!";
        stepCounter = 0;
        cin >> n;
    }

    return 0;
}








