# Student Quiz Record System (ADT List + File Handling)

This project is a C++ program that manages student quiz records using an **Array-based ADT List**.  
It was developed by extending concepts from MP1–MP7, integrating file handling (CSV-like storage)  
and menu-driven interaction.

---

## ✨ Features
- Add new student records (Name + Quiz 1–3 scores)
- Delete a record by name
- Update quiz scores for a student
- Display all records with:
  - Quiz scores
  - Computed average (2 decimal places)
  - Remarks (Passed/Failed, passing is 75)
- Save records to a text file (`record.txt`) in CSV format
- Retrieve records from file on startup

---

## 📂 File Structure
- `Final_ADTList_QuizSystem.cpp` → Main source code  
- `record.txt` → Data file automatically created/updated by the program

Format of `record.txt`:
```
Name,Quiz1,Quiz2,Quiz3
```

Example:
```
Glinda,85,90,88
Bob,70,65,72
```

---

## ▶️ How to Compile and Run
### Using g++:
```bash
g++ Final_ADTList_QuizSystem.cpp -o quiz_system
./quiz_system
```

### Using Dev-C++ / Code::Blocks:
1. Create a new C++ project.
2. Add `Final_ADTList_QuizSystem.cpp`.
3. Compile and run.

---

## 📜 Notes
- Maximum records: 5 (can be changed by modifying `#define MAX 5`).
- Records are automatically saved after each operation (insert, delete, update).
- If `record.txt` does not exist, the program will start with an empty list.

---

## ✅ Sample Run
```
MENU
1. Add Record
2. Delete Record
3. Update Record
4. Display Record
5. Exit
Enter choice: 1
Enter Name: Glinda
Enter Quiz 1: 85
Enter Quiz 2: 90
Enter Quiz 3: 88
Glinda is added.
Records saved successfully.
```
```
No.   Name    Q1   Q2   Q3   Average   Remarks
1.    Glinda   85   90   88   87.67     Passed
```
