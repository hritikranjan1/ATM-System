#include <iostream>
#include <string>

class BankAccount {
public:
    std::string name;
    std::string userName;
    std::string password;
    std::string accountNo;
    float balance = 0.0f;
    int transactions = 0;
    std::string transactionHistory = "";

    bool login() {
        std::cout << "Enter Your Username: ";
        std::cin >> userName;

        if (userName == this->userName) {
            std::cout << "Enter Your Password: ";
            std::cin >> password;

            if (password == this->password) {
                std::cout << "Login successful..." << std::endl;
                return true;
            } else {
                std::cout << "Incorrect Password!!\nPlease Enter Correct Password and Try Again" << std::endl;
            }
        } else {
            std::cout << "Username not found!!" << std::endl;
        }

        return false;
    }

    void withdraw() {
        std::cout << "Enter amount to withdraw: ";
        float amount;
        std::cin >> amount;

        if (amount <= 0) {
            std::cout << "Invalid amount entered." << std::endl;
            return;
        }

        if (balance >= amount) {
            transactions++;
            balance -= amount;
            std::cout << "\nWithdraw Successful...." << std::endl;
            std::string str = std::to_string(amount) + " Rs Withdrawn\n";
            transactionHistory += str;
        } else {
            std::cout << "\nInsufficient Balance" << std::endl;
        }
    }

    void registerUser() {
        std::cout << "\nEnter Your Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Your Username: ";
        std::cin >> userName;
        std::cout << "Enter Your Password: ";
        std::cin >> password;
        std::cout << "Enter Your Account Number: ";
        std::cin >> accountNo;
        std::cout << "\nRegistration completed. Kindly login" << std::endl;
    }

    void transfer() {
        std::cout << "\nEnter Recipient's Name: ";
        std::string recipient;
        std::cin.ignore();
        std::getline(std::cin, recipient);
        std::cout << "Enter amount to transfer: ";
        float amount;
        std::cin >> amount;

        if (amount <= 0) {
            std::cout << "Invalid amount entered." << std::endl;
            return;
        }

        if (balance >= amount) {
            if (amount <= 80000.0f) {
                transactions++;
                balance -= amount;
                std::cout << "\nSuccessfully Transferred to " << recipient << std::endl;
                std::string str = std::to_string(amount) + " Rs transferred to " + recipient + "\n";
                transactionHistory += str;
            } else {
                std::cout << "\nSorry...Limit is 80000.00" << std::endl;
            }
        } else {
            std::cout << "\nInsufficient Balance" << std::endl;
        }
    }

    void checkBalance() {
        std::cout << "\nBalance: " << balance << " Rs" << std::endl;
    }

    void displayTransactionHistory() {
        if (transactions == 0) {
            std::cout << "\nEmpty" << std::endl;
        } else {
            std::cout << "\nTransaction History:\n" << transactionHistory << std::endl;
        }
    }

    void deposit() {
        std::cout << "\nEnter amount to deposit: ";
        float amount;
        std::cin >> amount;

        if (amount <= 0) {
            std::cout << "Invalid amount entered." << std::endl;
            return;
        }

        if (amount <= 200000.0f) {
            transactions++;
            balance += amount;
            std::cout << "\nSuccessfully Deposited..." << std::endl;
            std::string str = std::to_string(amount) + " Rs deposited\n";
            transactionHistory += str;
        } else {
            std::cout << "\nSorry...Limit is 200000.00" << std::endl;
        }
    }
};

int main() {
    std::cout << "\nWELCOME TO ATM SYSTEM\n";
    std::cout << "1. Register\n";
    std::cout << "2. Quit\n";
    std::cout << "Enter Your Choice: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        BankAccount b;
        b.registerUser();
        while (true) {
            std::cout << "\n1. Login\n2. Quit\n";
            std::cout << "Enter Your Choice: ";
            int n;
            std::cin >> n;
            if (n == 1) {
                if (b.login()) {
                    std::cout << "\n\nWELCOME BACK " << b.name << "\n";
                    bool isFinished = false;
                    while (!isFinished) {
                        std::cout << "\n1. Withdraw\n2. Deposit\n3. Transfer\n4. Check Balance\n5. Transaction History\n6. Exit\n";
                        std::cout << "Enter Your Choice: ";
                        int c;
                        std::cin >> c;
                        switch (c) {
                            case 1:
                                b.withdraw();
                                break;
                            case 2:
                                b.deposit();
                                break;
                            case 3:
                                b.transfer();
                                break;
                            case 4:
                                b.checkBalance();
                                break;
                            case 5:
                                b.displayTransactionHistory(); // Corrected function name
                                break;
                            case 6:
                                isFinished = true;
                                break;
                        }
                    }
                }
            } else {
                return 0;
            }
        }
    } else {
        return 0;
    }
}
