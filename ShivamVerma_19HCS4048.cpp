/* Simulate and implement stop and wait protocol for noisy channel
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
University Roll No.: 19015570031
*/

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cstdlib>

using namespace std;

// A class facilitating the timings for the frame to send and receive
class Timer
{
    private:
        unsigned long begTime;

    public:
        void start()
        {
            begTime = clock();
        }

        unsigned long elapsedTime()
        {
            return ((unsigned long)clock() - begTime) / CLOCKS_PER_SEC;
        }

        bool isTimeout(unsigned long seconds)
        {
            return seconds >= elapsedTime();
        }
};

int main()
{
    int frames[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};                     // Frames to be sent 
    unsigned long seconds = 5;
    srand(time(NULL));

    Timer t;

    cout << "Frames to be sent: ";
    for(int index = 0; index < 10; ++index)
        cout << frames[index] << "  ";

    cout << endl;

    int count = 0;
    bool delay = false;

    cout << "\nSENDER\t\t\t\t\tRECEIVER\n";
    do
    {
        bool timeout = false;
        cout << "Sending Frame: " << frames[count];
        cout.flush();

        cout << "\t\t";

        t.start();
        if(rand() % 2)                                                              // Waiting for the receiver to receive the frame
        {
            int to = 24600 + rand() % (64000 - 24600) + 1;
            for(int i = 0; i < 64000; ++i)
                for(int j = 0; j < to; ++j);
        }

        if(t.elapsedTime() <= seconds)                                      // If the receiving time is more than 5 seconds, then there will be timeout and the frame will be sent again
        {
            cout << "Received Frame: " << frames[count] << "  ";

            if(delay)
            {
                cout << "Duplicate";
                delay = false;
            }

            cout << endl;
            count++;
        }
        else
        {
            cout << "---\n";
            cout << "Timeout\n";
            timeout = true;
        }

        t.start();
        if(rand() % 2 || !timeout)                                           // Waiting for an acknowledgement at the sender's side and if it's late, then duplicate frame will be sent again
        {
            int to = 24600 + rand() % (64000 - 24600) + 1;
            for(int i = 0; i < 64000; ++i)
                for(int j = 0; j < to; ++j);

            if(t.elapsedTime() > seconds)
            {
                cout << "Delayed Acknowlodgement!!!\n";
                count--;
                delay = true;
            }
            else if(!timeout)
                cout << "Acknowledgement: " << frames[count] - 1 << endl;
        }
    } while (count != 10);

    return 0;
}