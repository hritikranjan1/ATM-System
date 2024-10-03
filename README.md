# Octanet_internship
🏧 Building an ATM System in C/C++ 🏧
# ATM System in C++

This project is a simple ATM system built in C++. It supports functionalities such as user registration, login, withdrawal, deposit, transfer, checking balance, and viewing transaction history.

## Features
- **User Registration**: Register a new user with a name, username, password, and account number.
- **Login**: Secure login with username and password.
- **Withdraw**: Withdraw funds from your account.
- **Deposit**: Deposit money into your account.
- **Transfer**: Transfer funds to another recipient with a limit of Rs 80000.
- **Check Balance**: View the current balance in your account.
- **Transaction History**: View a detailed history of transactions.

## Setup Instructions

### Prerequisites
- A C++ compiler like `g++`
- Basic knowledge of the terminal/command line

### Compilation and Execution
1. Clone the repository:
    ```bash
    git clone https://github.com/hritikranjan1/ATM-System.git
    cd ATM-System
    ```

2. Compile the program using `g++`:
    ```bash
    g++ main.cpp -o atm-system
    ```

3. Run the executable:
    ```bash
    ./atm-system
    ```

## Usage
1. **Register**: Enter your name, username, password, and account number.
2. **Login**: Log in using the registered username and password.
3. **Use the ATM**: Once logged in, you can perform the following operations:
   - Withdraw
   - Deposit
   - Transfer
   - Check Balance
   - View Transaction History
   - Exit

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Future Enhancements
- Add functionality for saving transaction history to a file.
- Implement interest calculation on the account balance.
- Enhance the security of login with password encryption.
