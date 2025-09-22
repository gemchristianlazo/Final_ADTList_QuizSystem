#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

#define MAX 5

struct Record {
  string name;
  float quiz1;
  float quiz2;
  float quiz3;
};

struct List {
  Record DATA[MAX];
  int last;
};

class ADTLIST {
  private:
    List L;

  public:
    void makeNull();
    bool isFull();
    int isEmpty();
    int locate(string n);

    void insert(Record x);
    void del(string name);
    void display();
    void save();
    void retrieve();

    void update(string n);
};


int menu() {
    system("cls");
    int choice;
    cout << "MENU\n1. Add Record\n2. Delete Record\n3. Update Record\n4. Display Record\n5. Exit\nEnter choice: ";
    cin >> choice;
    return choice;
}

int main() {
  ADTLIST L;
  Record r;
  L.makeNull();
  L.retrieve();

  while(true) {
    switch(menu()) {
      case 1:
        system("cls");
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, r.name);
        cout << "Enter Quiz 1: ";
        cin >> r.quiz1;
        cout << "Enter Quiz 2: ";
        cin >> r.quiz2;
        cout << "Enter Quiz 3: ";
        cin >> r.quiz3;
        L.insert(r);
        L.save();
        system("pause");
        break;
      case 2:
        system("cls");
        cout << "Enter name to delete: ";
        cin.ignore();
        getline(cin, r.name);
        L.del(r.name);
        L.save();
        system("pause");
        break;
      case 3:
        system("cls");
        cout << "Enter name to update: ";
        cin.ignore();
        getline(cin, r.name);
        L.update(r.name);
        system("pause");
        break;
      case 4:
        system("cls");
        L.display();
        system("pause");
        break;

      case 5:
        L.save();
        return 0;

      default:
        cout << "Not valid." << endl;
        system("pause");
    }
  }
  return 0;
}

void ADTLIST::makeNull() {
  L.last = -1;
}

bool ADTLIST::isFull() {
  return (L.last >= MAX-1);
}

int ADTLIST::isEmpty() {
  return (L.last == -1);
}

int ADTLIST::locate(string n) {
  for (int i=0; i<=L.last; i++) {
    if (L.DATA[i].name == n) {
      return i;
    }
  }
  return -1;
}

void ADTLIST::insert(Record x) {
  if (isFull()) {
    cout << "List is full." << endl;
  }
  else {
    L.last++;
    L.DATA[L.last].name = x.name;
    L.DATA[L.last].quiz1 = x.quiz1;
    L.DATA[L.last].quiz2 = x.quiz2;
    L.DATA[L.last].quiz3 = x.quiz3;
    cout << x.name << " is added." << endl;
  }
}

void ADTLIST::del(string name) {
  if (isEmpty()) {
    cout << "List is empty\n";
    return;
  }
  int p = locate(name);
  if (p < 0) {
    cout << "Data not found." << endl;
  }
  else {
    cout << name << " is deleted.\n" << endl;
    for(int i=p; i<L.last; i++) {
      L.DATA[i].name = L.DATA[i+1].name;
      L.DATA[i].quiz1 = L.DATA[i+1].quiz1;
      L.DATA[i].quiz2 = L.DATA[i+1].quiz2;
      L.DATA[i].quiz3 = L.DATA[i+1].quiz3;
    }
    L.last--;
  }
}

void ADTLIST::display() {
  if (isEmpty()) {
    cout << "No records to display.\n";
    return;
  }
  cout << "No.\tName\tQ1\tQ2\tQ3\tAverage\tRemarks" << endl;
  for (int i=0; i<=L.last; i++) {
    float average = (round(((L.DATA[i].quiz1 + L.DATA[i].quiz2 + L.DATA[i].quiz3)/3)*100))/100;
    cout << (i+1) << ". " << "\t"
         << L.DATA[i].name << "\t"
         << L.DATA[i].quiz1 << "\t"
         << L.DATA[i].quiz2 << "\t"
         << L.DATA[i].quiz3 << "\t"
         << average << "\t"
         << (average >= 75 ? "Passed" : "Failed") << endl;
  }
  cout << "\n";
}

void ADTLIST::save(){
    ofstream outFile("record.txt");
    if(!outFile){
        cout << "Error opening file for saving!\n";
        return;
    }

    for(int i=0; i<=L.last; i++) {
        outFile << L.DATA[i].name << ","
        << L.DATA[i].quiz1 << ","
        << L.DATA[i].quiz2 << ","
        << L.DATA[i].quiz3 << endl;
    }
    outFile.close();
    cout << "Records saved successfully.\n";
}

void ADTLIST::retrieve(){
    ifstream inFile("record.txt");
    if (!inFile) {
        cout << "No saved records found.\n";
        return;
    }

    string line;
    while(getline(inFile, line)) {
        if(line.empty()) continue;

        Record d;

        int pos1 = line.find(",");
        int pos2 = line.find(",", pos1+1);
        int pos3 = line.find(",", pos2+1);

        d.name = line.substr(0, pos1);
        d.quiz1 = stoi(line.substr(pos1 + 1, pos2-(pos1+1)));
        d.quiz2 = stoi(line.substr(pos2 + 1, pos3-(pos2+1)));
        d.quiz3 = stoi(line.substr(pos3 + 1));

        if(!isFull()){
            L.last++;
            L.DATA[L.last] = d;
        }
    }

    inFile.close();
    cout << "Records retrieved successfully.\n";
}


void ADTLIST::update(string n){
    int p = locate(n);
    if (p==-1) {
        cout << "Record not found.\n";
        return;
    }

    int choice;
    do {
        system("cls");
        cout << "Updating quizzes for " << L.DATA[p].name << endl;
        cout << "1. Quiz 1: " << L.DATA[p].quiz1 << endl;
        cout << "2. Quiz 2: " << L.DATA[p].quiz2 << endl;
        cout << "3. Quiz 3: " << L.DATA[p].quiz3 << endl;
        cout << "4. Go back\n";
        cout << "Enter quiz number to update (or 4 go back): ";
        cin >> choice;

        switch(choice){
            case 1: cout << "Enter new score for Quiz 1: "; cin >> L.DATA[p].quiz1; break;
            case 2: cout << "Enter new score for Quiz 2: "; cin >> L.DATA[p].quiz2; break;
            case 3: cout << "Enter new score for Quiz 3: "; cin >> L.DATA[p].quiz3; break;
            case 4: cout << "Going back..."; break;
            default: cout << "Invalid choice.\n";
        }

        if (choice >= 1 && choice <= 3) {
            save();
        }

        system("pause");

    } while(choice!=4);
}
