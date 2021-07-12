/* To determine the class of an IP address
   Name: Shivam Verma
   Roll No: 19HCS4048
   Course: B.Sc. (H) Computer Science 3rd Sem
*/

#include <iostream>
#include <string>

using namespace std;

// Function defintion to determine the class of IP address 
char determineClass(string str)
{
    int networkID = 0, index;

    for(index = 0; str.at(index) != '.'; ++index);

    char *temp = new char[index];
    str.copy(temp, index + 1);

    networkID = stoi(temp);

    delete[] temp;

    // Class A 
    if (networkID >= 1 && networkID <= 126) 
        return 'A'; 
  
    // Class B 
    else if (networkID >= 128 && networkID <= 191) 
        return 'B'; 
  
    // Class C 
    else if (networkID >= 192 && networkID <= 223) 
        return 'C'; 
  
    // Class D 
    else if (networkID >= 224 && networkID <= 239) 
        return 'D'; 
  
    // Class E 
    else
        return 'E'; 

}

// Function defintion to determine the class of IP address in binary numbers
char determineClassBinary(string str)
{
    // Class A
    if(str.at(0) == '0')
        return 'A';
    
    // Class B
    else if(str.at(1) == '0')
        return 'B';

    // Class C
    else if(str.at(2) == '0')
        return 'C';
    
    // Class D
    else if(str.at(3) == '0')
        return 'D';
    
    // Class E
    else
        return 'E';
    
}

int main()
{
    string ipAddress;
    char ipClass, choice = 'N';
    int option;

    do
    {
        cout << "\t****MENU****\n";
        cout << "1. Enter IP address in decimal number\n";
        cout << "2. Enter IP address in binary number\n";
        cout << "Enter your choice: ";
        cin >> option;
        system("cls");

        switch(option)
        {
            case 1:
            {
                cout << "Enter the IP address in decimal number: ";
                cin.ignore();
                getline(cin, ipAddress);

                ipClass = determineClass(ipAddress);

                cout << "Given IP Address belongs to class " << ipClass;

                break;
            }

            case 2:
            {
                cout << "Enter the IP address in binary number: ";
                cin.ignore();
                getline(cin, ipAddress);

                ipClass = determineClassBinary(ipAddress);

                cout << "Given IP address belongs to class " << ipClass;

                break;
            } 

            default: cout << "Wrong choice of option!!!";
        }

        cout << "\n\nDo you want to continue (Y/N): ";
        cin >> choice;

        system("cls");
    } while (choice == 'Y' || choice == 'y');

    return 0;
}