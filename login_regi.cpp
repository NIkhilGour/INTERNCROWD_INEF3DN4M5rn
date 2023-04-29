#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
    public:
    string username;
    string password;
};

void registerUser() {
    ofstream file("users.txt", ios::app);
    User user;
    cout << "Enter username: ";
    cin >> user.username;
    cout << "Enter password: ";
    cin >> user.password;
    file << user.username << " " << user.password << endl;
    file.close();
    cout << "Registration successful!" << endl;
}

bool validateUser(string username, string password) {
    ifstream file("users.txt");
    string storedUsername, storedPassword;
    while (file >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            return true;
        }
    }
    return false;
}

void login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (validateUser(username, password)) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "1. Register\n2. Login\n3. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 3);
    return 0;
}
