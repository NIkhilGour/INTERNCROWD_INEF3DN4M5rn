#include<iostream>
#include<vector>
using namespace std;
class birthday
{       public:
        string name;
        int day;
        int month;
        int year;

        
};

void display(vector<birthday>birthdays)
{
    for(int i=0;i<birthdays.size();i++)
    {
            cout<<birthdays[i].name<<" :"<<birthdays[i].day<<"-"<<birthdays[i].month<<"-"<<birthdays[i].year<<endl;

    }

    return;
}
void editbirthday(vector<birthday>birthdays)
{
        string name;
        cout<<"Enter name to be edit"<<endl;
        cin>>name;
        for(int i=0;i<birthdays.size();i++)
        {
            if(birthdays[i].name==name)
            {
                cout<<"Enter new details of birthday in DD-MM-YYY format"<<endl;

                cin>>birthdays[i].day>>birthdays[i].month>>birthdays[i].year;

                cout<<"New Details of "<<birthdays[i].name<<"are :"<<endl;

                cout<<birthdays[i].day<<"-"<<birthdays[i].month<<"-"<<birthdays[i].year<<endl;

                return;

            }

        }

        cout<<"Name not found in list";





}
void createBirthday(vector<birthday>& birthdays) {
    birthday newBirthday;
    cout << "Enter name: ";
    cin >> newBirthday.name;
    cout << "Enter day: ";
    cin >> newBirthday.day;
    cout << "Enter month: ";
    cin >> newBirthday.month;
    cout << "Enter year: ";
    cin >> newBirthday.year;
    birthdays.push_back(newBirthday);
}

void searchBirthday(vector<birthday>& birthdays) {
    string name;
    cout << "Enter name to search: ";
    cin >> name;
    for (int i = 0; i < birthdays.size(); i++) {
        if (birthdays[i].name == name) {
            cout << birthdays[i].name << " : " << birthdays[i].day << "-" << birthdays[i].month << "-" << birthdays[i].year << endl;
            return;
        }
    }
    cout << "Birthday not found." << endl;
}
int main()
{
    vector<birthday>birthdays;

        
    int choice;
    do {
        cout << "1. Create new birthday entry" << endl;
        cout << "2. Edit existing birthday entry" << endl;
        cout << "3. Display all birthdays" << endl;
        cout << "4. Search for a birthday entry" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                createBirthday(birthdays);
                break;
            case 2:
                editbirthday(birthdays);
                break;
            case 3:
                display(birthdays);
                break;
            case 4:
                searchBirthday(birthdays);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 5);



return 0;
}