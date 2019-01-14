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
  srand(time(NULL));   // Seed Random
  int g;   //Input max game points (g)
  cout << "Play to what value: ";
  cin >> g;
  //Call Loop Game
  if (loopGame(g)==0){
    cout << "CONGRATS YOU WIN!" << endl;
  }else{
    cout << "YOU LOSE!" << endl;
  }
}

// roll function
int roll(){
  //Return Random Int 1-6;
  //Dont forget to seed random
  int r = rand()%6 + 1;
  cout << "Rolled a " << r << endl;
  return r;
}

// one turn function
int oneTurn(bool t){
  int s = 0; // Turn total
  int r; // Dice Roll
  bool c; // User choice
  //int i = 0; // This is for my winning strategy
  if(t == 0){
    //Human Turn
    do{ // did not roll a 3 or elect to hold // Make Do While
      cout << "Would you Like to Roll or Hold(0/1)? ";
      cin >> c;
      if(c== 0){
        r = roll(); // Rolls
        s = s+r;
      }
    }while ((r!=3)&&(c!=1));

    if(r==3){
      return 3;
    }else{
      return s;
    }

  }else{
    // Computer TURN
    // With a little probability / game theory it seems that best move is to try to roll 3x and then hold
    // This works better than adding up to a number
    //while(r!=3 && i++<3){
    // Reccomended while loop:
    while(r!=3 && s<=10){ //Keeps rolling until turn score is greater than or equal to 10
      r = roll(); //Rolls
      s = s+r;
    }
    if(r==3){
      return 3;
    }else{
      return s;
    }
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
  int h = 100; // Human Score
  int c = 100; // Computer Score
  int d = 0;   // Turn Total
  int t = rand()%2; //Generates a 0 or a 1

  // While loop Until someone wins
  while ((h < g) && (c < g)){//Conditon = Nobody has won
    if (t == 0) // Human
    {
      cout << "---  START OF HUMAN TURN  ---" << endl;
      d = oneTurn(0);
      h = h + d;
      c = c - d;
      cout << "---   END of HUMAN TURN   ---" << endl;
      t = 1; // Switches to Computer Turn
    }
    else // Computer
    {
      cout << "--- START OF COMPUTER TURN ---" << endl;
      d = oneTurn(1);
      c = c + d;
      h = h - d;
      cout << "---  END of COMPUTER TURN  ---" << endl;
      // cout << "------------------------------" << endl;
      t = 0; // Switches to Human Turn
    }
    cout << "------------------------------" << endl;
    cout << "Your Score: " << h << endl;
    cout << "Comp Score: " << c << endl;
    cout << "------------------------------" << endl;
  }
  //If statement to figure out who won;
  if (h >= g) // Human Win
    return 0;
  else // Computer Win
    return 1;
}
