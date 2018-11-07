#include <iostream>
using namespace std;
#include <ctime>

// FUNCTION Initializations
int roll();
int oneTurn(bool t);
bool loopGame(int g);


// Function Definitions
// main function
int main(){
  //Input max game points (g)
  //Call Loop Game
  //roll();
  int g;
  cout << "Play to what value: ";
  cin >> g;
  loopGame(g);
}

// roll function
int roll(){
  //Return Random Int 1-6;
  //Dont forget to seed random
  srand(time(NULL));
  int r = rand()%6 + 1;
  cout << "Rolled a " << r << endl;
  return r;
}

// one turn function
int oneTurn(bool t){
  int s; // Turn score
  int r;
  if(t = 0){
    //Human Turn
    while (){
      r = roll();
    }
    return s;
  }else{
    // Computer score
    while(){
        // Computer Logic
    }
    return s;
  }
  // If Human (0)
    // While loop
    //Ask User for Roll/Hold
      //If Roll -> Call Roll
        //IF Roll != 3
        //Add new total
  // If Computer (1)
    // Logic
}

// loop function
bool loopGame(int g){
  int h = 100;
  int c = 100;
  int t = rand(time(NULL))%2; //Generates a 0 or a 1

  // While loop Until someone wins
  while ((h < g) && (c < g)){//Conditon = Nobody has won
    if (t = 0) // Human
    {
      cout << "---  START OF HUMAN TURN  ---" << endl;
      h = h + oneTurn(0);
      cout << "---   END of HUMAN TURN   ---" << endl;
      t = 1; // Switches to Computer Turn
    }
    else // Computer
    {
      cout << "--- START OF COMPUTER TURN ---" << endl;
      c = c + oneTurn(1);
      cout << "---  END of COMPUTER TURN  ---" << endl;
      t = 0; // Switches to Human Turn
    }
    cout << "Your Score: " << h << endl;
    cout << "Comp Score: " << c << endl;
  }
  //If statement to figutr out who won;
  if (h >= g)
    return 0;
  else
    return 1;
}
