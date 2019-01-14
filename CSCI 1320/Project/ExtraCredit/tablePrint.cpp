// Test table print
#include <iostream>
#include <string>
using namespace std;

string center(string s,int w);
string rowDiv(int l, int w);
void dispRow(string text[], int l, int w);


int main(){

  const int cSize = 15;
  int rowLen = 4;
  string row[] = {"Col 1","Col 2","Col 3","Col 4"};
  dispRow(row,rowLen,cSize);
  rowDiv(rowLen,cSize);
  int numRows = 100;
  for(int i = 0; i < numRows; i++){ // Loops through the number of rows I want
    for(int j = 0; j < rowLen; j++){ // Loops through each column in the row
      row[j] = to_string((i+1)*(j+1));
    }
    dispRow(row,rowLen,cSize);
  }

  return 0;
}

void dispRow(string text[], int l, int w){
  cout << center(text[0],w);
  for(int i = 1; i < l; i++){
    cout << " | " << center(text[i],w);
  }
  cout << endl;
}

string rowDiv(int l, int w){
  for(int j = 0; j < w; j++)
    cout << "-";
  cout << "+";
  for(int i = 1; i < l ; i++){
    for(int j = 0; j < w+1; j++)
      cout << "-";
    if(i!=l-1)
      cout<<"+";
  }

  cout << endl;
}

string center(string s, int w){
  string space = "";
  string spaced;
  int padding = w - s.size();
  for(int i = 1; i < padding/2; i++)
    space = space + " ";
  if(padding%2!=0){
    spaced = " " + space + s + space + " ";
  }else{
    spaced = space + s + space +" ";
  }

  return spaced;
}
