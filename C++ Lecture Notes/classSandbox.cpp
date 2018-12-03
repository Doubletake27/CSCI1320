#include <iostream>
using namespace std;

class Student{
  public:
    string studentName;
    int idNumber;

    void dispInfo(){
      cout << "name: " << studentName << endl << "id number: " << idNumber << endl;
    }
  private:
    string major;
};

int main(){
  Student s1;

  s1.studentName = "sara";
  s1.idNumber = 2048;

  // s1.major = "aero"; // BAD

  s1.dispInfo();

  return 0;
}
