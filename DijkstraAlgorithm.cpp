/* Implementation of Dijkstra Algorithm
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 3rd Semester
Roll No.: 19HCS4048
*/

#include <iostream>

using namespace std;
  
// Number of vertices in the graph 
#define vertices 9 

int minDistance(int distance[], bool sptSet[]) 
{ 
    int min = INT32_MAX, min_index;

    for (int i = 0; i < vertices; i++) 
        if (sptSet[i] == false && distance[i] <= min) 
        {
            min = distance[i];
            min_index = i; 
        }
  
    return min_index; 
} 

void printSolution(int distance[]) 
{ 
    cout << "VERTEX \t\t\tDISTANCE FROM SOURCE\n";
    for (int i = 0; i < vertices; i++) 
        cout << i + 1 << " \t\t\t " << distance[i] << '\n'; 
} 

void dijkstra(int graph[vertices][vertices], int src) 
{ 
    int distance[vertices];  
    bool sptSet[vertices]; 

    for (int i = 0; i < vertices; i++) 
    {
        distance[i] = INT32_MAX;
        sptSet[i] = false;  
    }

    distance[src] = 0; 

    for (int count = 0; count < vertices - 1; count++) 
	{ 
        int u = minDistance(distance, sptSet); 
        sptSet[u] = true; 
        for (int v = 0; v < vertices; v++) 
            if (!sptSet[v] && graph[u][v] && distance[u] != INT32_MAX && distance[u] + graph[u][v] < distance[v]) 
                distance[v] = distance[u] + graph[u][v]; 
    } 

    printSolution(distance); 
}

int main() 
{ 
    int graph[][vertices] = { { 0, 5, 0, 0, 0, 0, 0, 9, 0 }, 
                              { 5, 0, 9, 0, 0, 0, 0, 12, 0 }, 
                              { 0, 9, 0, 8, 0, 5, 0, 0, 3 }, 
                              { 0, 0, 8, 0, 10, 15, 0, 0, 0 }, 
                              { 0, 0, 0, 10, 0, 11, 0, 0, 0 }, 
                              { 0, 0, 5, 15, 11, 0, 3, 0, 0 }, 
                              { 0, 0, 0, 0, 0, 3, 0, 4, 7 }, 
                              { 9, 12, 0, 0, 0, 0, 2, 0, 8 }, 
                              { 0, 0, 3, 0, 0, 0, 7, 8, 0 } }; 
    
    // Source is considered as Node 0
    dijkstra(graph, 0); 
  
    return 0; 
} 
