#include <iostream>
using namespace std;

class Student{
  public:

    void setIdNumber(int x){
      if(x>0)
        idNumber = x;
      else
        cout << "id number must be positive " << endl;
    }

    void setName(string n){
      studentName = n;
    }

    void dispInfo(){
      cout << "name: " << studentName << endl << "id number: " << idNumber << endl;
    }

  private:
    string studentName;
    int idNumber;
    string major;
};

int main(){
  Student s1;

  s1.setIdNumber(69420);
  s1.setName("Monch");

  s1.dispInfo();

  return 0;
}
