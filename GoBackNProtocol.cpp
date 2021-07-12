/* Implementation of Go Back N Protocol
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Sem
Roll No.: 19HCS4048
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int noOfFrames, windowSize, transmittedFrames = 0;

    srand(time(NULL));

    cout << "Enter the total number of Frames: ";
    cin >> noOfFrames;

    cout << "Enter the size of Window: ";
    cin >> windowSize;

    cout << endl;

    for(int iterate = 1; iterate <= noOfFrames; )
    {
        int x = 0;

        for(int sendFrame = iterate; sendFrame < iterate + windowSize && sendFrame <= noOfFrames; sendFrame++)
        {
            cout << "Sent Frame: " << sendFrame << '\n';
            transmittedFrames++;
        }

        for(int receivedFrame = iterate; receivedFrame < iterate + windowSize && receivedFrame <= noOfFrames; receivedFrame++)
        {
            int flag = rand() % 2;

            if(!flag)
            {
                cout << "Acknowledgement for Frame: " << receivedFrame << '\n';
                x++;
            } 
            else
            {
                cout << "Frame: " << receivedFrame << " not received.\n";
                cout << "Retransmitting Window\n";
                break;
            } 
        }

        cout << endl;
        iterate += x;
    }

    cout << "Total Number of Transmissions: " << transmittedFrames;
    return 0;
}