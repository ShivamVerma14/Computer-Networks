/* Implementation of Hamming Code
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Sem
Roll No.: 19HCS4048
*/

#include <iostream>

using namespace std;

int main()
{
    int data[10];
    int receivedData[10],c,c1,c2,c3;
 
    cout << "Enter 4 bits of data one by one\n";
    cin >> data[0];
    cin >> data[1];
    cin >> data[2];
    cin >> data[4];
 
    //Calculation of even parity
    data[6] = data[0] ^ data[2] ^ data[4];
	data[5] = data[0] ^ data[1] ^ data[4];
	data[3] = data[0] ^ data[1] ^ data[2];
 
	cout<<"\nEncoded data is\n";
	for(int index = 0; index < 7; index++)
        cout << data[index];
    
	cout<<"\n\nEnter received data bits one by one\n";
    for(int index = 0; index < 7; index++)
        cin >> receivedData[index];
 
    c1 = receivedData[6] ^ receivedData[4] ^ receivedData[2] ^ receivedData[0];
	c2 = receivedData[5] ^ receivedData[4] ^ receivedData[1] ^ receivedData[0];
	c3 = receivedData[3] ^ receivedData[2] ^ receivedData[1] ^ receivedData[0];
	c = c3 * 4 + c2 * 2 + c1;
 
    if(c == 0) 
		cout << "\nNo error while transmission of data\n";

	else 
    {
		cout << "\nError on position " << c;
		
		cout << "\nData sent : ";
		for(int index = 0; index < 7; index++)
        	cout << data[index];
        
		cout << "\nData received : ";
        for(int index = 0; index < 7; index++)
        	cout << receivedData[index];
        
		cout << "\nCorrect message is\n";
        
		//if errorneous bit is 0 we complement it else vice versa
		if(receivedData[7-c] == 0)
			receivedData[7-c] = 1;
        else
		 	receivedData[7-c] = 0;

		for(int index = 0; index < 7; index++) 
			cout << receivedData[index];
	}
	
	return 0;
}