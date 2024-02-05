#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
/*
 * The code class
 * */
class code {
public:
    code(int length, int range, vector<int> inputGuess = {});//constructor for 'code ' class
    void initializesRandomly();//randomly initialize code
    int checkCorrect(code& guess) const;// check the number of correct
    int checkIncorrect(code& guess) const;//check the number of incorrect
    void printSecretCode();// print secret code

private:
    int n, m;// n(the length of code ), m (digits range from 0 to m-1)
    vector<int> codeVector;// the vector to store all digits
};

code::code(int length, int range, vector<int> inputGuess): n(length), m(range) {
    //constructor intializes the 'codel class

    if (!inputGuess.empty() && length == inputGuess.size()) {
        codeVector = inputGuess;//check whether input guess vector is valid
    } else if (length != 0 && range != 0) {
        initializesRandomly();// if there is no initlize input vector, use
    }
}

void code::initializesRandomly() {
    codeVector.resize(n);// resize the vector to the desgin length
    for (int i = 0; i < n; i++) {
        codeVector[i] = rand() % m;// input random value for i
    }
}

int code::checkCorrect(code& guess) const {
    int count = 0;// set innitial value for correct guesses
    for (int i = 0; i < n; i++) {
        if (codeVector[i] == guess.codeVector[i]) {
            count++;// increase the value of correct guesses
        }
    }
    return count;
}

int code::checkIncorrect(code& guess) const {
    int count = 0;// set innitial value for incorrect guesses
    vector<int> codeForCheck = codeVector;

    for (int i = 0; i < n; i++) {
        if (codeVector[i] != guess.codeVector[i]) {//starting if the digit of guess are not eqault to the same postion digit of secret code
            for (int j = 0; j < n; j++) {
                if (codeForCheck[j] == guess.codeVector[i] && codeVector[j] != guess.codeVector[j]) {
                    count++;// increase the value of incorrect guesses when value of secret in that postion j is eqaual value of guess in postion i and at the same time, the value of guess in J is different
                    codeForCheck[j] = -1;// set the postion J value of a local copy of secret code to a un reachable value for guess
                    break;
                }
            }
        }
    }
    return count;
}

void code::printSecretCode() {
    for (int i = 0; i < n; i++) {
        cout << codeVector[i] << " ";//go through code vector and print element of it
    }
    cout << endl;
}

int main(){
    srand(time(NULL));
    vector <int> vectorGuess0 = {9,0,9,3,3};//delete, test only code
    vector <int> vectorGuess1 ={5, 0, 3, 2, 6};//test guess 1
    vector <int> vectorGuess2 ={2, 1, 2, 2, 2};//test guess 2
    vector <int> vectorGuess3 ={1, 3, 3, 4, 5};//test guess 3

    code secretcode(5,10);
    secretcode.printSecretCode();
    code guess1(5,10,vectorGuess1);//set guess 1 code object
    code guess2(5,10,vectorGuess2);//set guess 2 code object
    code guess3(5,10,vectorGuess3);//set guess 3 code object
    //output result
    cout<<"guess 1 correct number: "<<secretcode.checkCorrect(guess1)<<endl;
    cout<<"guess 1 incorrect number: "<<secretcode.checkIncorrect(guess1)<<endl;
    cout<<"guess 2 correct number:  "<<secretcode.checkCorrect(guess2)<<endl;
    cout<<"guess 2 incorrect number: "<<secretcode.checkIncorrect(guess2)<<endl;
    cout<<"guess 3 correct number: "<<secretcode.checkCorrect(guess3)<<endl;
    cout<<"guess 3 incorrect number: "<<secretcode.checkIncorrect(guess3)<<endl;
}