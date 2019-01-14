// Henry Meyerson
// 109100761
// CSCI 1320 - 112
// Lab 11
#include <iostream>
#include <string>
using namespace std;


// Class Declaration
class AnimalPatient{
  public:
    // Constructor (Overloaded)
    AnimalPatient(){ // Constructor with 0 inputs
      patientName = "Liger";
      species = "Liger";
      age = -1;
      weight = -1;
    }

    AnimalPatient(string n, string s, int a, int w){ // Constructor with 4 inputs
      patientName = n;
      species = s;
      age = a;
      weight = w;
    }


    // Mutator Functions
    void setName(string name){// Name Mutator
      patientName = name;
    }

    void setSpecies(string s){// Species Mutator
      species = s;
    }

    void setAge(int n){// age Mutator
      // Validate for Positive
      if(n<0){
        cout << "Age must be a positive number!" << endl;
      }else{
        age = n;
      }
    }

    void setWeight(int w){// weight Mutator
      // Validate for Positive
      if(w<0){
        cout << "Weight must be a positive number!" << endl;
      }else{
        weight = w;
      }
    }


    // Accessor Functions
    string name(){
      return patientName;
    }

    string type(){
      return species;
    }

    int years(){
      return age;
    }

    int lbsWeight(){
      return weight;
    }

    // Weight in Kg function
    float kgWeight(){
      const int C = 2.205; // kilograms per pound
      float kg = weight/C;
      return kg;
    }

  private:
    string patientName;
    string species;
    int age; //Years
    int weight; //Pounds
};

// Initializes the table printing functions
string center(string s,int w);
string rowDiv(int l, int w);
void dispRow(string text[], int l, int w);

int main(){
  int noEntries = 3;
  string n;
  string s;
  int a, w;
  AnimalPatient dataBase[noEntries];
  for(int i = 0; i<noEntries;i++){
    cout << "Enter Patient " << i+1 << " Information" << endl;

    // Name
    cout << "Name: ";
    cin >> n;
    dataBase[i].setName(n);

    // Species
    cout << "Species: ";
    cin >> s;
    dataBase[i].setSpecies(s);

    // Age
    cout << "Age: ";
    cin >> a;
    dataBase[i].setAge(a);

    // Weight
    cout << "Weight: ";
    cin >> w;
    dataBase[i].setWeight(w);

    cout << endl;
  }

  // This table print is just for fun
  const int cSize = 15; // Column size
  int rowLen = 4; // Number of columns
  string row[] = {"Name","Species","Age","Weight"};

  // Table Header
  dispRow(row,rowLen,cSize);
  rowDiv(rowLen,cSize);

  //Generates Table Body
  for(int i = 0; i < noEntries; i++){ // Loops through the number of rows I want
    row[0] = dataBase[i].name();
    row[1] = dataBase[i].type();
    row[2] = to_string(dataBase[i].years());
    row[3] = to_string(dataBase[i].lbsWeight());
    dispRow(row,rowLen,cSize);
  }

  return 0;
}
// Table Printing functions that I wrote for fun
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
