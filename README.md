# Banking System (C++ OOP Project)

> // Copyright (c) 2025 Anas Ali Chafai. All rights reserved.  
> // Contact: anaschafai04@gmail.com


A fully-featured **Banking System** built with **Object-Oriented Programming (OOP) in C++**.  
The project simulates real-world banking operations, focusing on **clean architecture**, **data validation**, and **modular design**.  
It is entirely console-based and demonstrates practical usage of **classes, inheritance, file I/O, enums, and validations**.

---

## Key Features

### 💼 Client Management
- Add new clients with account details.
- Update, search, and delete clients.
- Display all clients in a formatted list.
- Validate inputs (account number, phone, PIN, balance, etc.).

### 💰 Transactions
- Deposit and withdraw with balance checks.
- Transfer money between accounts.
- Transaction logging and total balance overview.
- Validations to prevent overdrafts or invalid operations.

### 👥 User Management & Security
- User accounts with **permissions** (bitmask-based).
- Add, update, delete users.
- Login and registration system.
- Admin vs normal user access levels.

### 💱 Currency Exchange
- List currencies and their current exchange rates.
- Update currency rates.
- Perform conversions with accurate calculations.

### ⚙️ System Design Highlights
- **Object-Oriented Approach**: Classes like `clsBankClient`, `clsUser`, `clsCurrency`, and `clsPerson` implement encapsulation and inheritance.  
- **Input Validation**: All inputs are verified (numbers, strings, account numbers).  
- **File-Based Persistence**: Data stored in `Bank.txt`, `Users.txt`, and `TransferLog.txt` (no database required).  
- **Modular Screens**: Each feature (client, user, currency, transactions) has its own screen class for separation of concerns.  
- **Utilities**: Helper classes for string handling, dates, and validation (`clsDate`, `clsUtil`, `clsInputValidate`).  

---

## 📂 Project Structure

```
Banking-System/
├── Core/                    # Core classes
│   ├── clsBankClient.h      # Client management
│   ├── clsCurrency.h        # Currency operations
│   ├── clsPerson.h          # Base person class
│   ├── clsUser.h            # User management
│   └── clsDate.h            # Date handling
├── Screens/                 # UI screens
│   ├── Client/              # Client operations
│   ├── Currencies/          # Currency exchange
│   ├── User/                # User management
│   └── LoginRegister.h      # Authentication
├── Source Files/
│   └── C11v2.cpp             # Application entry point
└── Data Files/              # Storage files
    ├── Bank.txt             # Client records
    ├── Users.txt            # User login and permissions
    ├── TransferLog.txt      # Logs of account transfers
    ├── Currencies.txt       # Currency exchange rates (e.g., France#//#EUR#//#Euro#//#0.900000)
    └── LoginLog.txt         # Login history with timestamp and details
```


---

## 📝 Data Files

- **Client.txt** → Stores client records:  

- **Users.txt** → Stores user login and permissions:  

- **TransferLog.txt** → Logs account transfers with details.

- **Currencies.txt** → Stores currency data (for exchange module)  

- **LoginRegister.txt** → Logs all login attempts  

---

### 🏛️ Architecture

This project is inspired by the **3-Tier Architecture** design:

- **Presentation Layer (Screens/)** → Handles the console UI and user interaction.  
- **Business Logic Layer (Core/)** → Contains the core classes and validation logic (OOP principles applied).  
- **Data Layer (Data Files/)** → Text files (`Bank.txt`, `Users.txt`, `TransferLog.txt`, etc.) that store application data.  

Even though it's a console application, I tried to structure it in a way that follows the 3-tier separation of concerns.

---

## How to Run

1. Clone this repository.  
2. Open the project in **Visual Studio 2022** (recommended).  
3. Build the solution.  
4. Make sure the `Data Files/` folder contains `Bank.txt` and `Users.txt` before running.  
5. Run from console to explore all features.  

---

## Learning Outcomes
This project is a strong practice in:
- Applying **OOP principles** (inheritance, encapsulation, modularity).
- Handling **file-based storage** in C++.
- Designing **validations and error handling** in console applications.
- Building **scalable console apps** with multiple modules and features.

---

**Anas Ali Chafai**  
Algiers, Algeria  
📩 anaschafai04@gmail.com 

