// FIle Imput Example
int main(){
  char str[10];
  ifstream iFile("filename.txt");
  //Opens the file for reading
  // Ensure that filename.txt is present in the same directory as the source file.
  iFile >> str;
  // outputs the file components
  cout << str << "\n";
  // waits for keypress
  cin.get();
  // iFile is closed
}
