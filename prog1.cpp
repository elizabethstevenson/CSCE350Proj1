//Elizabeth Stevenson
//CSCE350-001 Project1

#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 n = number of garnet and black pairs
 a = from pole ---> 0
 b = to pole   ---> 1
 c = temp pole ---> 2
*/

int stepCounter = 0; //used to show number of steps

void moveStackOfPairs(int n, string a, string b, string c) {
    if(n<2) {
        cout << "APPLE ";

        //move a disk from A to C
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << a << " to peg " << c << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;

        //move a disk from A to B
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << a << " to peg " << b << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;

        //move a disk from C to B
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << c << " to peg " << b << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;

    } else {
        cout << "BANANA ";

        moveStackOfPairs((n-1), a, b, c);
        
        //move a disk from A to C
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << a << " to peg " << c << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;
        
        //move another disk from A to C
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << a << " to peg " << c << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;

        moveStackOfPairs((n-1), b, a, c);

        //move a disk from C to B
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << c << " to peg " << b << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;

        //move another disk from C to B
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << c << " to peg " << b << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;

        moveStackOfPairs((n-1), a, b, c);
    }
}

void solveHuger(int n, string a, string b, string c) {
    if(n<2) {
        cout << "ORANGE ";

        //move a disk from A to C
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << a << " to peg " << c << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;

        //move a disk from A to B
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << a << " to peg " << b << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;

    } else {
        cout << "GRAPE ";

        moveStackOfPairs((n-1), a, b, c);

        //move a disk from A to C
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << a << " to peg " << c << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;

        //move a disk from A to B
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << a << " to peg " << c << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;

        moveStackOfPairs((n-1), a, b, c);
        
        //move disk from C to B
        stepCounter++;
        cout << "Step " << stepCounter << ": Move disk " << n << " from peg " << c << " to peg " << b << ".";
        cout << endl;

        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;

        solveHuger((n-1), a, b, c);
    }
}


int main(int argc, char* argv[]) {
    int n; //number of pairs
    cin >> n;

/*
    char a, b, c; //poles
    a = 'A';
    b = 'B';
    c = 'C';
*/
 /*   int a = 0;
    int b = 1;
    int c = 2;
*/

    string a = "0";
    string b = "1";
    string c = "2";
    


//HOW DO I MAKE A1 B2 C3 LIKE ???



    while(cin.good()) { 
        cout << "Starting At:" << endl;
        cout << " 0:" << "____" << endl;
        cout << " 1:" << "____" << endl;
        cout << " 2:" << "____" << endl;
        solveHuger(n, a, b, c);
        cout << "Done!";
        stepCounter = 0;
        cin >> n;
    }
}








