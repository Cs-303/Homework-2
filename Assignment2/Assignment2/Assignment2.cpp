//Steven Pham
//Cs 303

#include <iostream>
#include "LinkedList.h"
#include "Employees.h"
using namespace std;

int main() {
    SingleLinkedList<string> list1;
    char choice;
    string input;
    int pos;

    //question 1 -  single linked list
    //has a recurring menu with built-in try and catch; loop until you quit
    do {
        try {
            list1.printList();
            cout << "---Options---\n"
                << "1 - push front\n"
                << "2 - push back\n"
                << "3 - pop front\n"
                << "4 - pop back\n"
                << "5 - insert\n"
                << "6 - remove\n"
                << "7 - find\n"
                << "8 - return front\n"
                << "9 - return back\n"
                << "0 - check if list is empty\n"
                << "Q - Quit linked list. (Goes to next section)\n";
            cout << "What choice would you like to pick? ";
            cin >> choice;

            switch (toupper(choice)) {
            case '1':
                cout << "What would you like to push front? ";
                cin >> input;
                list1.push_front(input);
                break;

            case '2':
                cout << "What would you like to push back? ";
                cin >> input;
                list1.push_back(input);
                break;

            case '3':
                list1.pop_front();
                break;

            case '4':
                list1.pop_back();
                break;

            case '5':
                cout << "What position would you like to insert? ";
                cin >> pos;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Invalid input received, you must enter a number.");
                }

                cout << "What would you like to insert? ";
                cin >> input;
                list1.insert(pos, input);
                break;

            case '6':
                cout << "What position would you like to remove? ";
                cin >> pos;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Invalid input received, you must enter a number.\n");
                }

                if (list1.remove(pos)) cout << "Index " << pos << " is removed\n";
                else cout << "Index cannot be removed as it is beyond the boundary\n";
                break;

            case '7':
                cout << "What item would you like to find? ";
                cin >> input;
                cout << "If not found, size of the linked list is returned.\n";
                cout << "The item " << input << " is located at position " << list1.find(input) << " if possible\n";
                break;

            case '8':
                cout << "Header is " << list1.front() << endl;
                break;

            case '9':
                cout << "Tail is " << list1.back() << endl;
                break;

            case '0':
                if (list1.empty()) cout << "list is empty\n";
                else cout << "List is not empty\n";
                break;

            case 'Q':
                cout << "You entered Q. Going to next section.";
                break;
            }
            cout << "\n\n\n";
        }
        catch (runtime_error e) { cout << e.what() << "\n\n\n"; }
    } while (toupper(choice) != 'Q');



    //question 2 - abstract class
    cout << "Next section - Employees\n\n";
    Professional prof("Daniel Slatskey", 8000);  //name, monthly salary
    nonProfessional nonProf("Connor Dailey", 37, 15.00); //name, hours worked, hourly rate

    cout << "Professional\n";
    cout << "   Name : " << prof.name() << endl;;
    cout << "   Health Care contribution: $" << prof.calculateHealthCareContributions() << endl;
    cout << "   Weekly Salary: $" << prof.calculateWeeklySalary() << endl;
    cout << "   Vacation Days: " << prof.calculateVacationDays() << " days" << endl;

    cout << "\n\nNon-Professional\n";
    cout << "   Name : " << nonProf.name() << endl;;
    cout << "   Health Care contribution: $" << nonProf.calculateHealthCareContributions() << endl;
    cout << "   Weekly Salary: $" << nonProf.calculateWeeklySalary() << endl;
    cout << "   Vacation Days: " << nonProf.calculateVacationDays() << " days" << endl;

}
