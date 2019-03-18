// Movie Tree Driver 2

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "MovieTree.hpp"

int menu();

int main(int argc, char *argv[]){
  string fname = argv[1];

  int rank, year;
  float rating;
  string title, ran, y ,rat;

  MovieTree movies;

  ifstream raw;
  raw.open(fname);

  // Read in Movies
  while(!raw.eof()){
    getline(raw,ran,',');
    // cout << ran << " ";
    getline(raw,title,',');
    // cout << title << " ";
    getline(raw,y,',');
    // cout << y << " ";
    getline(raw,rat,'\n');
    // cout << rat << endl;
    if(ran != ""){
      rank = stoi(ran);
      year = stoi(y);
      rating = stof(rat);

      movies.addMovie(rank,title,year,rating);
    }
  }

  int choice = 0;
  while(choice != 3){
    choice = menu();
    switch(choice){
      case 1: // Print The Inventory
        movies.printMovieInventory();
        break;

      case 2: // Call Delete Function
        cout << "Enter a movie title:" << endl;
        // cin >> title;
        cin.ignore();
        getline(cin,title);
        // cout << "Title: " << title << endl;
        movies.deleteMovie(title);
        break;

      case 3: // Quit
        cout << "Goodbye!" << endl;
        break;
    }
  }


  return 0;
}

int menu(){
  cout << "======Main Menu======" << endl;
  cout << "1. Print the inventory" << endl;
  cout << "2. Delete a movie" << endl;
  cout << "3. Quit" << endl;

  int choice;
  cin >> choice; // Maybe add in validation if time

  return choice;
}
