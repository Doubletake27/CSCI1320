// Movie Tree Function Breakdown
#include <iostream>
using namespace std;

#include "MovieTree.hpp"

void printMovie(MovieNode * m);
void preOrder(MovieNode * temp, float rating, int year);
MovieNode *searchRecur(MovieNode* m, std::string title);
void preOrder(MovieNode * temp, float rating, int year);
int numNodes(MovieNode * m);
float sumNodes(MovieNode * m);
void destruct(MovieNode * m);

MovieTree::MovieTree(){
  root = nullptr;
}

MovieTree::~MovieTree(){
  destruct(root);
  root = nullptr;
}

void destruct(MovieNode * m){
  if(m!=nullptr){
    destruct(m->leftChild);
    destruct(m->rightChild);
    delete m;
  }
}

void MovieTree::printMovieInventory(){
  if(root!=nullptr){
    printMovie(root);
  }
}

void printMovie(MovieNode * m){ // Helper for printMovieInventory
  if(m -> leftChild != nullptr){
    printMovie(m-> leftChild);
  }

  cout << "Movie: " << m-> title << " " << m -> rating << endl;

  if(m -> rightChild != nullptr){
    printMovie(m->rightChild);
  }
}

void MovieTree::addMovieNode(int ranking, std::string title, int year, float rating){
  // Track Prev
  MovieNode *prev = nullptr;
  // Initialize traverser
  MovieNode *temp = root;

  // Initialize new node
  MovieNode *n = new MovieNode;
  n -> parent = nullptr;
  n -> leftChild = nullptr;
  n -> rightChild = nullptr;
  n -> ranking = ranking;
  n -> title = title;
  n -> year = year;
  n-> rating = rating;

  while(temp != nullptr){
    prev = temp;
    if(n-> title < temp-> title){
      temp = temp -> leftChild;
    }else{
      temp = temp -> rightChild;
    }
  }

  if(prev == nullptr){// Tree is empty
    root = n;
  }else{
    if(n-> title < prev -> title){
      prev -> leftChild = n;
      n->parent = prev;
    }else{
      prev -> rightChild = n;
      n-> parent = prev;
    }
  }
}

void MovieTree::findMovie(std::string title){
  MovieNode * node = searchRecur(root,title);
  if(node != nullptr){
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << node -> ranking << endl;
    cout << "Title  :" << node -> title << endl;
    cout << "Year   :" << node -> year << endl;
    cout << "rating :" << node -> rating << endl;
  }else{
    cout << "Movie not found." << endl;
  }
}

MovieNode *MovieTree::search(std::string title){ //Private Function (access to root)
  return searchRecur(root,title);
}

MovieNode *searchRecur(MovieNode* m, std::string title){
  if(m!=nullptr){
    if(m->title == title){
      return m;
    }else{
      if(m-> title > title){
        return searchRecur(m -> leftChild, title);
      }else{
        return searchRecur(m-> rightChild, title);
      }
    }
  }else{
    return nullptr;
  }
}


void MovieTree::queryMovies(float rating, int year){
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  //traverse
  preOrder(root, rating, year);
}

void preOrder(MovieNode * temp, float rating, int year){
  if(temp != nullptr){
    if((temp -> year > year)&&(temp -> rating >= rating)){
      cout << temp -> title << "(" << temp -> year << ") " << temp -> rating << endl;
    }
    preOrder(temp -> leftChild,rating,year);
    preOrder(temp -> rightChild,rating,year);
  }
}

void MovieTree::averageRating(){
  float average = 0;

  if(root != nullptr){
    int num = numNodes(root);
    float sum = sumNodes(root);
    average = sum/(float)num;
  }
  cout << "Average rating:" << average << endl;
}

int numNodes(MovieNode * m){
  int sum = 0;
  if(m->leftChild != nullptr){
    sum+=numNodes(m->leftChild);
  }

  sum ++;

  if(m->rightChild != nullptr){
    sum+=numNodes(m->rightChild);
  }

  return sum;
}

float sumNodes(MovieNode * m){
  float sum = 0;
  if(m->leftChild != nullptr){
    sum+=sumNodes(m->leftChild);
  }

  if(m!=nullptr){
    sum += m->rating;
  }

  if(m->rightChild != nullptr){
    sum+=sumNodes(m->rightChild);
  }

  return sum;
}
