#include <iostream>
#include<queue>
using namespace std;

bool hasPath(int ** edges,int a,int b,bool *visited,int v){
    queue<int> path;
    path.push(a);
    visited[a] = true;
    
    while(!path.empty()){
        int curr = path.front();
        path.pop();
        
        //chech if it has path
        if(curr == b){
            return true;
        }
        for(int i=0; i<v; i++){
            if(i==curr){
                continue;
            }
            if(edges[curr][i] == 1 && !visited[i]){
                
                path.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
    
}
int main() {
    int v, e;
    cin >> v >> e;

  /*

       Write Your Code Here
       Complete the Rest of the Program
       You have to take input and print the output yourself
     
  */

 int **edges = new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    
    //take input
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    
    int a,b;
    cin>>a>>b;
    bool ans =hasPath(edges,a,b,visited,v);
    if(ans == 0){
        cout<<"false";
    }
    else{
        cout<<"true";
    }
    delete [] visited;
    for(int i=0;i<v;i++){
        delete [] edges[i];
    }
    delete []edges;
  return 0;
}