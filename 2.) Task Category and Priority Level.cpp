#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<string> q) {
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
  cout << endl;
}

string categoriesList() {
    int chooseCateg;
    string userTaskCateg;
    bool loop_initialzer = true;
    string newCateg;
    queue<string> categories;
    categories.push("Work"); // defaults
    categories.push("Personal");
    categories.push("Fitness and Health");
    categories.push("Academics");
    categories.push("Music");

    do {
        cout << "\n   1: Choose Task Category\n   2: Add New\n   Enter Here: ";
        cin >> chooseCateg;

        switch (chooseCateg) {
        case 1:
            system("cls");
            cout << "\nTask Categories:\n";
            printQueue(categories);
            cout << "\n\n   Enter Task Category: ";
            cin >> userTaskCateg;
            {
                queue<string> tempQueue = categories; // Create a temporary queue for searching
                bool categoryFound = false;
                while (!tempQueue.empty()) {
                    string existingCateg = tempQueue.front();
                    tempQueue.pop();
                    if (existingCateg == userTaskCateg) {
                        categoryFound = true;
                        break;
                    }
                }
                if (categoryFound) {
                    return userTaskCateg;
                }
                else {
                    cout << "Category Not Found!\n";
                }
            }
            break;

        case 2:
            cout << "\nNew Category: ";
            cin >> newCateg;
            categories.push(newCateg);
            break;
        }
    } while (loop_initialzer);
}

string priorityLevel(){
  int priorityTask;
  bool loopInitialzer = true;
  do{
    cout << "\n\tChoose Priority Level: \n"
       << "\t  1: Critical/Important\n"
       << "\t  2: Not Priority Today\n"
       << "\t  3: Low Importance\n"
       << "\n\t   Enter Here: ";

    cin >> priorityTask;

    if (priorityTask != 1 && priorityTask != 2 && priorityTask != 3){
      system("cls");
      cout << "Invalid Input";
      loopInitialzer = false;
      }

    else{
      loopInitialzer = true;
      switch (priorityTask)
      {
      case 1:
        return "1: High"; // feel free to modify the terms
        break;

      case 2:
        return "2: Moderate ";
        break;

      case 3:
        return "3: Low";
        break;
      }
    }
    
  }while(loopInitialzer == false); 
}

int main() {

    // task priority level
    string taskPriority = priorityLevel();

  // task category
    string taskCategory = categoriesList();

    cout << "Task Priority Level: " << taskPriority;
    cout << "\nTask Category: " << taskCategory;
    return 0;
}
