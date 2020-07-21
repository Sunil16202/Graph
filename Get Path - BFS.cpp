#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> * getPath(int** edges, int n, int sv, int ev, bool* visited) {
	unordered_map<int, int> m;
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    
    bool done = false;
    
    while(!q.empty() && done == false){
		int f = q.front();
        q.pop();
        
        for(int i=0; i<n; i++){
            
            if(edges[f][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
                m[i] = f;
                
                if(ev == i){
                	done = true;
                	break;
            	}
            }
        }
    }	
    
    if(done == false){
        return NULL;
    }
    vector<int> *path = new vector<int>();
	path->push_back(ev);
    int cur = ev;
    while(cur != sv){
        cur = m[cur] ;
        path -> push_back(cur);
    }
	return path;
}


int main()
{
    int V, E, v1, v2;
    cin >> V >> E;

    int** edges = new int*[V];
    for (int i=0; i<V; i++) {
        edges[i] = new int[V];
        for (int j=0; j<V; j++) {
            edges[i][j] = 0;
        }  
    }
    
    for (int i=0; i<E; i++) {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    
    cin >> v1 >> v2;
    
    bool* visited = new bool[V];
    for (int i=0; i<V; i++) {
        visited[i] = false;
    }
    
    vector<int> * path = getPath(edges, V, v1, v2, visited);
    if(path != NULL){
        for(int i=0; i< path->size(); i++){
        	cout<<path->at(i)<< " ";
    	}
    }

    cout<<endl;

    return 0;
}
