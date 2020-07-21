#include <iostream>
#include<iostream>
#include<queue>
using namespace std;
void DFS(int ** edges,int n,int sv, bool * visited){
    cout<<sv<<" ";
    visited[sv] = true;

    for(int i=0; i<n; i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i] == true){
                continue;
            }
            DFS(edges, n, i, visited);
        }
    }
    
}

//check the starting vertex if graph is disjoint then this function will find the the disjoint point and call the BFS again

void PrintBFS(int ** edges, int n) {
    bool* visited = new bool[n];
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }
    
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            DFS(edges, n, i, visited);
        }
    } 
}



int main() {
    int n;
    int e;
    cin >> n >> e;
    int ** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int [n];
        for(int j=0; j<n; j++){
            edges[i][j] =   0;
        }
    }
    for(int i=0; i<e; i++){
        int f,s;
        cin >> f>> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    

    PrintBFS(edges,n);

    for(int i=0; i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
}