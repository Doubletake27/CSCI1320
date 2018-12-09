// TimeEg

#include <iostream>
#include <string>
using namespace std;

class Time12{
  private:
    int hour;
    int minute;
    string mer; // meridiem (am or pm)
  public:
    void printDate(){
      cout << hour << ":" << minute << mer << endl;
    }
    void setHour(int h){
      if(h>=1 && h <= 12)
        hour = h;
      else
        cout << "you are bad and you should feel bad" << endl;
    }

    void setMinute(int m){
      if(m>=0 && m<=59)
        minute = m;
      else
        cout << "bad choice" << endl;
    }

    void setMer(string s){
      if(s == "AM" || s == "PM")
        mer = s;
      else
        cout << "Feck off moite" << endl;
    }

    int getHour(){
      return hour;
    }
};

int main(){
  Time12 t;
  t.setHour(11);
  t.setMinute(35);
  t.setMer("AM");
  t.printDate();

  cout << "Hour " << t.getHour() << endl;

  return 0;
}
