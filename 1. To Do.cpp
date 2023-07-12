# include <iostream>
# include <string>
# include <fstream>
using namespace std;


int categorizeList() { // not final, are yung ginagawa ko kanina
  int chooseCateg;
  bool loop_initialzer = true;
  string arrayCategories[30]; //initial size
  string newCateg;
  int categoryCount = 0; // Variable to keep track of the number of categories

  do {
    cout << "\n   1: Choose Category    \n   2: Add New\n";
    cout << "   Enter Here: ";
    cin >> chooseCateg;

    if (chooseCateg == 1) {
      if (categoryCount == 0) {
        cout << "\nNo Existing Categories.";
      } else {
        system("cls");
        for (int i = 0; i < categoryCount; i++) {
          cout << "\n\n    Existing Categories: \n" << "\t" <<arrayCategories[i] << endl;
        }
      }
    } else if (chooseCateg == 2) {
      cout << "\nNew Category: ";
      cin >> newCateg;
      if (categoryCount < 30) {
        arrayCategories[categoryCount] = newCateg;
        categoryCount++; // Increment the category count
      } else {
        cout << "\nMaximum number of categories reached.";
      }
    }
  } while (loop_initialzer);
}


void searchFileForString(const string& filename, const string& searchString) {
  ifstream file(filename);
  if (file.is_open()) {
    string line;
    bool found = false;
    
    while (getline(file, line)) { // reads each line of the file and stores it in the line variable
      if (found) {
        cout << line << endl;
      } else if (line.find(searchString) != string::npos) {
        found = true;
      }
    }
    
    file.close();
    
    if (!found) {
      cout << "String not found in the file." << endl;
    }
  } else {
      cout << "Unable to open file: " << filename << endl;
  }
}


string viewToDo2(string filename){
  fstream tasksFile(filename);
  int viewTasks;
  cout << "\n    View To Do: \n";
  cout << "\n      1: All Tasks\n      1: Unfinished Tasks\n";
  cout << "\n      Enter Here: ";
  cin >> viewTasks;

  if (viewTasks == 1){
    cout << "\n\tALL TASKS\n";
    searchFileForString(filename, "ALL TASKS");
}

if (viewTasks == 2){
  cout << "\nUNFINISHED TASKS\n";
  searchFileForString(filename, "UNFINISHED TASKS");
}
}


int main(){
  system("cls");
  string filename = "file.txt";
  viewToDo2(filename);
}

