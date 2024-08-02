#include<bits/stdc++.h>
using namespace std;


int Matrix_chain_Mul(vector<int> &arr, int n){
    vector<vector<int>> dp(n, vector<int>(n));

    int i,j,k,l,cnt;
    for(i=1;i<n;i++){
        dp[i][i] = 0;
    }
    for(l=2;l<=n;l++){
        for(i=1;i<n-l+1;i++){
            j = i+l-1;
            dp[i][j] = INT_MAX;
            for(k=i;k<=j-1;k++){
                cnt = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(cnt < dp[i][j])  dp[i][j] = cnt;
            }
        }
    }
    return dp[1][n-1];
}



int main(){
    int n;
    cout<<"Enter number of matrices:"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter sequence where: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Minimum number of matrix element multiplication is : "<<endl<<Matrix_chain_Mul(arr,n);;
    
    return 0;

}