#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

// ======================================
// ЗАДАНИЕ 1. КЛАСС STUDENT
class Student {
private:
    string fullName;
    string group;
    double grades[5];

public:
    Student(string name, string grp, double gr[]) {
        fullName = name;
        group = grp;
        for (int i = 0; i < 5; i++) {
            grades[i] = gr[i];
        }
    }

    string getFullName() const {
        return fullName;
    }

    string getGroup() const {
        return group;
    }

    double GetAverageGrade() {
        double sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += grades[i];
        }
        return sum / 5.0;
    }

    void DisplayInfo() {
        cout << "Студент: " << fullName
            << "\nГруппа: " << group
            << "\nСредний балл: " << fixed << setprecision(2)
            << GetAverageGrade() << endl;
    }
};

// ======================================
// ЗАДАНИЕ 2. КЛАСС BANKACCOUNT
class BankAccount {
private:
    string accountNumber;
    double balance;
    string ownerName;

public:
    BankAccount(string accNum, string name, double initialBalance = 0.0) {
        accountNumber = accNum;
        ownerName = name;
        balance = initialBalance;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    string getOwnerName() const {
        return ownerName;
    }

    void setOwnerName(string name) {
        ownerName = name;
    }

    double getBalance() const {
        return balance;
    }

    bool Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнено на " << amount << endl;
            return true;
        }
        else {
            cout << "Ошибка: сумма должна быть > 0!" << endl;
        }
        return false;
    }

    bool Withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снято " << amount << endl;
            return true;
        }
        else {
            cout << "Ошибка: недостаточно средств!" << endl;
        }
        return false;
    }

    void DisplayInfo() {
        cout << "Счет: " << accountNumber
            << "\nВладелец: " << ownerName
            << "\nБаланс: " << fixed << setprecision(2)
            << balance << endl;
    }
};

// ======================================
// ЗАДАНИЕ 3. КЛАСС PRODUCT
class Product {
public:
    string Name;
    double Price;
    int Quantity;

    Product(string name, double price, int quantity) {
        Name = name;
        Price = price;
        Quantity = quantity;
    }

    double GetTotalValue() {
        return Price * Quantity;
    }

    bool Sell(int amount) {
        if (amount > 0 && amount <= Quantity) {
            Quantity -= amount;
            cout << "Продано " << amount << " шт. " << Name << endl;
            return true;
        }
        else {
            cout << "Ошибка: недостаточно товара!" << endl;
        }
        return false;
    }
};

// ======================================

int main() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    //1
    cout << "=== 1 ===" << endl;

    double grades[5] = { 4.0, 5.0, 3.5, 4.5, 4.0 };
    Student s1("Иванов Иван", "ИТ-21", grades);
    s1.DisplayInfo();
    cout << endl;
    //2
    cout << "=== 2 ===" << endl;

    BankAccount acc("12345-678", "Петров Петр", 1000.0);
    acc.DisplayInfo();
    acc.Deposit(500);
    acc.Withdraw(200);
    acc.DisplayInfo();
    cout << endl;
    //3
    cout << "=== 3 ===" << endl;

    Product p1("Ноутбук", 50000.0, 10);
    cout << "Товар: " << p1.Name
        << "\nЦена: " << p1.Price
        << "\nКоличество: " << p1.Quantity
        << "\nСтоимость: " << p1.GetTotalValue() << endl;
    p1.Sell(3);
    cout << "Остаток: " << p1.Quantity
        << ", Стоимость: " << p1.GetTotalValue() << endl;

    return 0;
}