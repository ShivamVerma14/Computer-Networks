/* Cyclic Redundancy Code
   Name: Shivam Verma
   Roll No: 19HCS4048
   Course: B.Sc. (H) Computer Science 3rd Sem
*/

#include <iostream>

using namespace std;

// Function to divide message and key
void divide(int* temp, int* key, int sizeofMessage, int sizeofKey)
{
    for(int index = 0; index < sizeofMessage; ++index)
        if(key[0] == temp[index])
            for(int keyIterator = 0, changingIndex = index; keyIterator < sizeofKey; ++keyIterator, ++changingIndex)
                if(!(temp[changingIndex] ^ key[keyIterator]))
                    temp[changingIndex] = 0;
                else
                    temp[changingIndex] = 1;
}

int main()
{
    int sizeofMessage = 0, sizeofKey = 0;
    int *message, *key, *temp;

    cout << "At Sender's End..." << endl << endl ;

    // Taking the size and elements of message and key
    cout << "Enter the size of Message: ";
    cin >> sizeofMessage;
    cout << "Enter the size of key: ";
    cin >> sizeofKey;

    message = new int[sizeofMessage + sizeofKey - 1];
    temp = new int[sizeofMessage + sizeofKey -1];
    key = new int[sizeofKey];

    cout << "Enter the message: " << endl;
    for(int index = 0; index < sizeofMessage; ++index)
        cin >> message[index];

    cout << "Enter the key: " << endl;
    for(int index = 0; index < sizeofKey; ++index)
        cin >> key[index];

    // Appending sizeofKey-1 zeroes at the end of message
    for(int index = 0; index < sizeofKey - 1; ++index)
        message[sizeofMessage + index] = 0;

    // Copying the message into temporary message
    for(int index = 0; index < sizeofMessage + sizeofKey -1; ++index)
        temp[index] = message[index];
    
    divide(temp, key, sizeofMessage, sizeofKey);

    // Showing remainder
    cout << "Remainder: ";
    for(int index = 0; index < sizeofKey - 1; ++index)
        cout << temp[sizeofMessage + index];

    // Adding remainder in message to get transmitted message
    for(int index = 0; index < sizeofKey - 1; ++index)
        message[sizeofMessage + index] = temp[sizeofMessage + index];

    // Transmitted Message
    cout << "\nTransmitted Message: ";
    for(int index = 0; index < sizeofMessage + sizeofKey - 1; ++index)
        cout << message[index];

    cout << "\n\nAt Receiver's End..." << endl << endl;

    // Entering Received Message and copying the same into temporary array
    cout << "Enter the received message: " << endl;
    for(int index = 0; index < sizeofMessage + sizeofKey - 1; ++index)
        cin >> message[index];

    // Copying message into temporary array
    for(int index = 0; index < sizeofMessage + sizeofKey - 1; ++index)
        temp[index] = message[index];

    divide(temp, key, sizeofMessage, sizeofKey);

    // Checking for error in message
    for(int index = 0; index < sizeofKey - 1; ++index)
        if(temp[sizeofMessage + index])
        {
            cout << "Error detected in received message" << endl;
            return 0;
        }
    cout << "No error detected in received message" << endl;

    // Showing received message
    cout << "Received Message: ";
    for(int index = 0; index < sizeofMessage; ++index) 
        cout << message[index];
    
    delete[] message, temp, key;

    return 0;
}