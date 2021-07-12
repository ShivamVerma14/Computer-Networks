/* Implementing Distance Vector Algorithm
Name: Shivam Verma 
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <iostream>

using namespace std;

struct Node
{
    int* distance;
    int* from;

    // A constructor
    Node(int noOfNodes = 0)
    {
        distance = new int[noOfNodes];
        from = new int[noOfNodes];
    }

    // A Destructor
    ~Node()
    {
        delete[] distance;
        delete[] from;
    }
};

int main()
{
    Node* nodes;
    int **costMatrix;
    int noOfNodes = 0;

    cout << "Enter the number of nodes: ";
    cin >> noOfNodes;

    nodes = new Node[noOfNodes];

    costMatrix = new int*[noOfNodes];
    for(int index = 0; index < noOfNodes; ++index)
        costMatrix[index] = new int[noOfNodes];

    cout << "Enter the Cost Matrix...\n";
    for(int row = 0; row < noOfNodes; ++row)
        for(int col = 0; col < noOfNodes; ++col)
        {
            cin >> costMatrix[row][col];
            costMatrix[row][row] = 0;

            nodes[row].distance[col] = costMatrix[row][col];
            nodes[row].from[col] = col;
        }

    for(int row = 0; row < noOfNodes; ++row)  
        for(int col = row + 1; col < noOfNodes; ++col)
            for(int temp = 0; temp < noOfNodes; ++temp)
                if(nodes[row].distance[col] > costMatrix[row][temp] + nodes[temp].distance[col])
                {   
                    nodes[row].distance[col] = nodes[row].distance[temp] + nodes[temp].distance[col];
                    nodes[col].distance[row] = nodes[row].distance[col];
                    nodes[row].from[col] = temp;
                    nodes[col].from[row] = temp;
                }

    system("cls");

    cout << "\t****Distance Vector Algorithm****\n";

    for(int row = 0; row < noOfNodes; row++)
    {
        cout << "\n\n For router: " << row + 1;

        for(int col = 0; col < noOfNodes; col++)
            cout << "\t\n Node " << col + 1 << " via " << nodes[row].from[col] + 1 << " Distance " << nodes[row].distance[col];

        cout << "\n\n";
    }

    for(int index = 0; index < noOfNodes; ++index)
        delete[] costMatrix[index];
    delete[] costMatrix;

    delete[] nodes;

    return 0;
}
