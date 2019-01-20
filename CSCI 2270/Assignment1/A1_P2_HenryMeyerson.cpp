#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct User{
  string username;
  float gpa;
  int age;
};

void addUser(User users[], string _username, float _gpa, int _age, int length);
void printList(User users[], int length);

// int main(){ // For Testing

int main(int argc, char *argv[]){
  // cout << "0 " << argv[1] << endl;
  string fInName = argv[1];
  // cout << "1 " << argv[2] << endl;
  string fOutName = argv[2];
  // cout << "2 " << argv[3] << endl;
  float minGPA = stof(argv[3]);
  User users[100];

  ifstream students;
  students.open(fInName);

  ofstream goodStudents;
  goodStudents.open(fOutName);

  string name, gpa, age;
  int len = 0;

  while(!students.eof()){
    getline(students,name,',');
    getline(students,gpa,',');
    getline(students,age,'\n');
    addUser(users,name,stof(gpa),stoi(age),len++);
  }
  for(int i = 0; i < len-1; i++){
    if(users[i].gpa>=minGPA){
      goodStudents << users[i].username << "," << users[i].gpa << "," << users[i].age << endl;
    }
  }

  goodStudents.close();
  students.close();
  printList(users,len);
}

void addUser(User users[], string _username, float _gpa, int _age, int length){
  users[length].username = _username;
  users[length].gpa = _gpa;
  users[length].age = _age;
}

void printList(User users[], int length){
  for(int i = 0; i < length; i++){
    cout << users[i].username << " [" << users[i].gpa << "] age: "<< users[i].age << endl;
  }
}
