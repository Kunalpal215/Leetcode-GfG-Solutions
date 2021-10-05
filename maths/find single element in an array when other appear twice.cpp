//question: https://www.geeksforgeeks.org/find-element-appears-array-every-element-appears-twice/
#include<bits/stdc++.h>
using namespace std;
int findSingle(int arr[],int n){
    int ans=arr[0];
    for(int i=1;i<n;i++){
        ans=ans^arr[i]; // element occuring twice gives xor as 1 and hence, finally
        // the single element gets stored in ans
    }
    return ans;
}
int main(){
    int arr[5]={1,2,2,1,3};
    cout<<findSingle(arr,5)<<endl;
    return 0;
}