#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

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

class response {
public:
    response(int correct, int incorrect);// constructor fo response 
    friend bool operator==(response &a, response &b);//override the operator == 
    friend ostream &operator<<(ostream &out, response &a);//override the io stream 
    void setCorrect(int inputCorrect);//set the correct number in response 
    void setIncorrect(int inputIncorrect);//set the incorrect number in response 
    int getCorrect();//get the correct number in response 
    int getIncorrect();//get the incorrect number in response 

private:
    int correctNumber, incorrectNumber;//the corret number value and incorrect number 
};

response::response(int correct, int incorrect): correctNumber(correct), incorrectNumber(incorrect) {
}// the constructor for response 

int response::getCorrect() {
    return correctNumber;//get the correct number in response 
}

int response::getIncorrect() {
    return incorrectNumber;//get the incorrect number in response 
}

void response::setCorrect(int inputCorrect) {
    correctNumber = inputCorrect;//set the correct number in response 
}

void response::setIncorrect(int inputIncorrect) {
    incorrectNumber = inputIncorrect;//set the incorrect number in response 
}

bool operator==(response &a, response &b) {
    return a.correctNumber == b.correctNumber && a.incorrectNumber == b.incorrectNumber;// check whether both response corret number and incorrect number is same 
}

ostream &operator<<(ostream &out, response &a) {
    out << "Response: number correct " << a.getCorrect() << " number incorrect " << a.getIncorrect();// set the output to the expected form 
    return out;
}

class mastermind {
public:
    mastermind(int localn, int localm);//constructor which could pass parameters from local n and local m to global n and m value 
    mastermind();// constructor without initialize value 
    void printSecretCode();// print the secret code 
    code humanGuess();// get human guess input and convert code object 
    response getResponse(code &guess) const;// obtain the guess value and covert it to the response 
    bool isSolved(response &answerresponse) const;//return bool value to determine whether the mastermind is solved 
    void playGame();// the main playgame function 

private:
    int n, m;// the mastermind n and m value 
    code secretcode;// the code object secretcode 
    int numGuesses;// the value of time of guess


};

mastermind::mastermind(): n(5), m(10), secretcode(n, m) {
}// constructor of mastermind with default n=5 and m= 10

mastermind::mastermind(int localn, int localm): secretcode(n, m) {
    cout << "Please enter the length and range (from 0 to the number you enter):" << endl;
    cin >> localn >> localm;//ask user and get the keyboard input for n and m value 
    n = localn;
    m = localm;// set those local n and m value to the member value 
    secretcode = code(n, m);// set the secret code with the n and m value 
}

void mastermind::printSecretCode() {
    secretcode.printSecretCode();// print out the secret code 
}

code mastermind::humanGuess() {
    int intguess;
    vector<int> guessvector;// set a guess vector to store the user input guess value 

    for (int i = 0; i < n; i++) {
        cout << "Please enter No." << i + 1 << " digit (0 to " << m << "): ";
        cin >> intguess;// get the user input value 
        guessvector.push_back(intguess);// put the user input value to guess vector 
    }
    return code(n, m, guessvector);//return the code object build with user guess vector 
}

response mastermind::getResponse(code &guess) const {
    return response(secretcode.checkCorrect(guess), secretcode.checkIncorrect(guess));// return response object  from code object check value 
}

bool mastermind::isSolved(response &answerresponse) const {
    response solvedresponse(n, 0);
    return answerresponse == solvedresponse;//return whether the user response is the corret number as n and 0 incorrect number 
}

void mastermind::playGame() {
    printSecretCode();// according to the given task, request to print the secret code first 
    bool endcondition = false;// initialize the end condition 
    numGuesses = 0;// initialize time of guess  

    while (!endcondition) {
        code guess = humanGuess();// set a user guess code object 
        response responseforguess = getResponse(guess);// get a response for the user guess code 
        cout << responseforguess << endl << endl;//print the response 
        endcondition = isSolved(responseforguess);//check whether the condition is 
        numGuesses++;// increase the times of guess 

        if (endcondition) {
            cout << "Congratulations, you solved the puzzle!" << endl;// if solved, print congratulation message 
        } else if (numGuesses >= 10) {
            cout << "You've reached the maximum number of allowed guesses. Codemaker wins!" << endl;// if reach to max allowed number, print failure message 
            break;
        }
    }
}

int main() {
    srand(time(NULL));// set the seed 

    mastermind game(5, 10);//default constructor 
    game.playGame();// use the playgame function

    return 0;
}
