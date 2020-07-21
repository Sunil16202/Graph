#include <iostream>
#include<iostream>
#include<vector>
using namespace std;

vector<int>* getPath(int **edges, int sv, int ev, int *visited, int n){
    if(ev == sv){
        vector<int> * v = new vector<int>();
        v -> push_back(ev);
        visited[ev] = true;
        return v;
    }
    
    visited[sv] = true;
    for(int i=0; i<n; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1 && !visited[i]){
            vector<int> * ans = getPath(edges,i,ev,visited,n);
            if(ans != NULL){
                ans -> push_back(sv);
                return ans;
            }
        }
    }
    return NULL;
}

int main()
{
   int v, e, tempX, tempY;
   cin >> v >> e;
   int **edges = new int*[v];
    for(int i=0;i<v;i++){
        edges[i]= new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    int *visited = new int[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    
    int v1,v2;
    cin>>v1>>v2;
    
    vector<int>* g=getPath(edges,v1,v2,visited,v);
    
    if(g != NULL){
        for(int i=0;i<g->size();i++){
            cout<<g->at(i)<<" ";
        }
    }
    else{
        cout<<""<<endl;
    }
 
    
    delete [] visited;
    for(int i=0;i<v;i++){
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}