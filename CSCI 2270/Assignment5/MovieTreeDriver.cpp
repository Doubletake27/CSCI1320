// Movie Tree Driver
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "MovieTree.hpp"

int menu();
// void printMovie(MovieNode * m);
// void preOrder(MovieNode * temp, float rating, int year);
// MovieNode *searchRecur(MovieNode* m, std::string title);
// void preOrder(MovieNode * temp, float rating, int year);
// int numNodes(MovieNode * m);
// float sumNodes(MovieNode * m);
// void destruct(MovieNode * m);

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
    getline(raw,title,',');
    getline(raw,y,',');
    getline(raw,rat,'\n');
    rank = stoi(ran);
    year = stoi(y);
    rating = stof(rat);


    movies.addMovieNode(rank,title,year,rating);
  }

  int choice = 0;
  while(choice != 5){
    choice = menu();
    switch(choice){
      case 1: // Find a Movie
        cout << "Enter title:" << endl;
        // cin >> title;
        cin.ignore();
        getline(cin,title);
        // cout << "Title: " << title << endl;
        movies.findMovie(title);
        break;

      case 2: // Query Movies
        cout << "Enter minimum rating:" << endl;
        cin >> rating;
        cout << "Enter minimum year:" << endl;
        cin >> year;
        movies.queryMovies(rating,year);
        break;

      case 3: // Print the Inventory
        movies.printMovieInventory();
        break;

      case 4: // Average Rating of Movies
        movies.averageRating();
        break;

      case 5: // Quit
        cout << "Goodbye!" << endl;
        break;
    }
  }

  return 0;
}

int menu(){
  cout << "======Main Menu======" << endl;
  cout << "1. Find a movie" << endl;
  cout << "2. Query movies" << endl;
  cout << "3. Print the inventory" << endl;
  cout << "4. Average Rating of movies" << endl;
  cout << "5. Quit" << endl;

  int choice;
  cin >> choice; // Maybe add in validation if time

  return choice;
}
