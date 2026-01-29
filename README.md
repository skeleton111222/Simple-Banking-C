# Simple Banking System in C (Using File Handling)

## 📌 Project Description
The Simple Banking System is a console-based application developed in the C programming language.  
It demonstrates the use of **functions, switch-case menu, and text file handling** to simulate basic banking operations such as creating accounts, depositing money, withdrawing money, and checking account balances.  
All account details are stored persistently in a text file, making the system simple and easy to understand for beginners.

---

## 🛠️ Technologies Used
- **Programming Language:** C  
- **Concepts Used:**
  - Functions
  - Switch-case menu
  - File handling (text files)
  - Structures (logical data grouping)
  - Loops and conditional statements

---

## 📂 Files Included
- `Bank.c` – Main source code of the banking system  
- `bank.txt` – Text file used to store account details (auto-created at runtime not uploaded)  
- `README.md` – Project documentation  

---

## ✨ Features
- Create a new bank account  
- Deposit money into an existing account  
- Withdraw money from an account  
- Check account balance  
- Menu-driven program using `switch-case`  
- Persistent data storage using text files  

---

## ▶️ How to Compile / Run
### Step 1: Clone or Download the repository
```
git clone https://github.com/skeleton111222/Simple-Banking-C
```
### Step 2: Redirect to the folder
```
cd Simple-Banking-C
```
### Step 3: Compile the program
```
gcc Bank.c -o Bank
```
### Step 4: Run the program
```
./Bank
```
---
## 🗂️ File Structure
```
Simple-Banking-C/
│
├── Bank.c        # Main C source file
├── bank.txt      # Stores account data (created automatically not uploaded)
└── README.md     # Project documentation
```

---

## 📝 Notes

- Account data is stored in plain text format inside bank.txt.
- Each record follows this format:
 ```
 AccountNumber Name Balance
 ```
- A temporary file is used internally while updating records (deposit/withdraw).
- This project is intended for learning and academic purposes.

---

## 🚀 Future Enhancements

- Add account deletion functionality
- Implement password-protected accounts
- Improve input validation
- Add interest calculation feature
- Convert to binary file handling version
- Add admin and user roles

---

## Conclusion

This project is a beginner-friendly implementation of a banking system using C.
It helps learners understand file handling, functions, and menu-driven programming, making it ideal for academic mini-projects and practice.
