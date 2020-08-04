int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    int count = 0;
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
          int one = i;
          int two = arr[i]-1;
          int len = 1;
          visited[i] = 1;
          
          while(two != i){
            visited[two] = 1;
            one = two;
            two = arr[two] - 1;
            len++;
          }
          
          count += len-1;
        }
    }
    return count;
}