# Expense Tracker in C

## About the Project

This is a console-based Expense Tracker developed in C. The application helps users record, manage, and analyze their expenses through a simple menu-driven interface.

All expense records are stored in a binary file, allowing data to remain available even after the program is closed.

---

## Features

- Add Expense
- View All Expenses
- Search Expenses by Category
- Update Existing Expense Records
- Delete Expense Records
- Calculate Total Expenses
- Find Highest Expense
- Generate Category-wise Summary
- Analytics Dashboard
- Persistent Storage using File Handling

---

## Technologies Used

- C Programming Language
- Structures
- Functions
- File Handling

---

## Expense Structure

```c
struct Expense
{
    int id;
    char category[30];
    float amount;
    char date[15];
};
```

---

## Project Structure

```text
Expense-Tracker/
│
├── expense_tracker.c
└── README.md
```

---

## Menu

```text
====================================
         EXPENSE TRACKER
====================================

1. Add Expense
2. View Expenses
3. Search By Category
4. Show Total Expenses
5. Show Highest Expense
6. Update Expense
7. Delete Expense
8. Category Summary
9. Analytics Dashboard
10. Exit
```

---

## How It Works

### Add Expense

The user enters:

- Expense ID
- Category
- Amount
- Date

The record is stored in `expenses.dat`.

### View Expenses

Displays all expense records stored in the file.

### Search By Category

Filters expenses based on a category such as:

- Food
- Travel
- Shopping
- Education

### Update Expense

Allows modification of an existing expense record.

### Delete Expense

Removes an expense using a temporary file replacement technique.

### Total Expenses

Calculates the sum of all recorded expenses.

### Highest Expense

Identifies the expense with the largest amount.

### Category Summary

Displays spending grouped by category.

Example:

```text
Food       : 2500.00
Travel     : 1800.00
Shopping   : 4200.00
Education  : 1000.00
Other      : 700.00
```

### Analytics Dashboard

Provides:

- Total Expenses
- Number of Transactions
- Average Expense
- Highest Expense Category
- Highest Expense Amount

---

## Sample Output

### Adding an Expense

```text
Expense ID: 1
Category: Food
Amount: 250
Date: 09-06-2026

Expense Added Successfully!
```

### Viewing Expenses

```text
ID    CATEGORY        AMOUNT      DATE

1     Food            250.00      09-06-2026
2     Travel          500.00      10-06-2026
```

### Analytics Dashboard

```text
=================================
      ANALYTICS DASHBOARD
=================================

Total Expenses          : 750.00
Number of Transactions  : 2
Average Expense         : 375.00
Highest Expense Category: Travel
Highest Expense Amount  : 500.00
```


## What I Practiced

While building this project, I worked with:

- Structures
- Functions
- File Handling
- Binary Files
- CRUD Operations
- Searching using Strings
- Data Analysis
- Temporary File Management

---

## Future Improvements

Some enhancements I would like to add in the future:

- Monthly Expense Reports
- Sorting Expenses by Amount
- Export Reports to CSV
- Budget Tracking
- Graphical User Interface (GUI)
- Database Integration

---

## Compilation

### Linux / macOS

```bash
gcc expense_tracker.c -o expense_tracker
./expense_tracker
```

### Windows

```bash
gcc expense_tracker.c -o expense_tracker.exe
expense_tracker.exe
```

---

## Author

**Om Singh**

- B.Tech Computer Engineering  
- Thapar Institute of Engineering and Technology
