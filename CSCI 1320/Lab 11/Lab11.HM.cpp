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
  return 0;
}
