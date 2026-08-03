#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "data.txt";
    string textToAppend;

    cout << "Enter text to append: ";
    getline(cin, textToAppend);

    ofstream file(filename, ios::app); // open in append mode
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << textToAppend << endl;
    file.close();

    cout << "Text appended successfully." << endl;

    // Display file content
    ifstream infile(filename);
    string line;
    cout << "\nFile content:\n";
    while (getline(infile, line))
        cout << line << endl;

    return 0;
}


=================================================

#include <iostream>
using namespace std;

class ClassB; // forward declaration

class ClassA {
    int valueA;
public:
    ClassA(int a) : valueA(a) {}
    friend int addValues(ClassA, ClassB);
};

class ClassB {
    int valueB;
public:
    ClassB(int b) : valueB(b) {}
    friend int addValues(ClassA, ClassB);
};

int addValues(ClassA a, ClassB b) {
    return a.valueA + b.valueB;
}

int main() {
    ClassA objA(10);
    ClassB objB(20);

    cout << "Sum = " << addValues(objA, objB) << endl;
    return 0;
}

=================================================

#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount." << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
            return;
        }
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrew: " << amount << endl;
    }

    void showBalance() {
        cout << "Account No: " << accountNumber
             << ", Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc("AC123456", 1000.0);

    acc.showBalance();
    acc.deposit(500);
    acc.withdraw(300);
    acc.withdraw(5000); // should fail
    acc.showBalance();

    return 0;
}

=================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<string> strings;
    string temp;
    int n = 10;

    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        strings.push_back(temp);
    }

    cout << "\nVector before sorting:\n";
    for (const auto& s : strings)
        cout << s << " ";
    cout << endl;

    sort(strings.begin(), strings.end());

    cout << "\nVector after sorting:\n";
    for (const auto& s : strings)
        cout << s << " ";
    cout << endl;

    return 0;
}

=========÷=======================================

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matrix {
private:
    vector<vector<T>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(r, vector<T>(c, 0));
    }

    void input() {
        cout << "Enter " << rows << "x" << cols << " matrix elements:" << endl;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++) {
                T sum = 0;
                for (int k = 0; k < cols; k++)
                    sum += data[i][k] * other.data[k][j];
                result.data[i][j] = sum;
            }
        return result;
    }
};

int main() {
    cout << "--- Integer Matrices ---" << endl;
    Matrix<int> a1(2, 2), b1(2, 2);
    a1.input();
    b1.input();

    cout << "Sum:\n";
    (a1 + b1).display();

    cout << "Product:\n";
    (a1 * b1).display();

    cout << "\n--- Float Matrices ---" << endl;
    Matrix<float> a2(2, 2), b2(2, 2);
    a2.input();
    b2.input();

    cout << "Sum:\n";
    (a2 + b2).display();

    cout << "Product:\n";
    (a2 * b2).display();

    return 0;
}

=================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<double> nums(10);

    cout << "Enter 10 doubles:" << endl;
    for (int i = 0; i < 10; i++)
        cin >> nums[i];

    cout << "\nBefore sorting:\n";
    for (double n : nums)
        cout << n << " ";
    cout << endl;

    // Using lambda function for descending order
    sort(nums.begin(), nums.end(), [](double a, double b) {
        return a > b;
    });

    cout << "\nAfter sorting (descending):\n";
    for (double n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}