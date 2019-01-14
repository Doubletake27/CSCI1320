#include <iostream>
#include <ctime>
using namespace std;

int rand0toX(int x); // Takes in an interger value x, returns a random value b/w 0 & X

int guessNumber(); // Takes in nothing. Prompts user to guess number. keeps prompting until user guessed correctly, Returns number of tries

int main(){
  // cout << "Random Number " << rand0toX(20) << endl;
  srand(time(NULL));

  int noOfTries = guessNumber();
  cout << "Good Job, you guessed the correct number in " << noOfTries << " tries." <<endl;

  return 0;
}

int rand0toX(int x){
  int out;
  out = rand()%(x+1);
  return out;
}

int guessNumber(){
  int counter = 0;
  int hiddenNumber = rand0toX(20);
  int userGuess;
  do{
    cout << "Guess a number b/w 0 and 20 ";
    cin >> userGuess;
    counter++;
  }while(userGuess != hiddenNumber);
  return counter;
}
