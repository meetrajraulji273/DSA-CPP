#include <bits/stdc++.h>
using namespace std;

int getMini(vector<int> &stalls){
    int mini = INT_MAX;
    for(int i=0;i<stalls.size();i++){
        mini = min(mini,stalls[i]);
    }
    return mini;
}
int getMaxi(vector<int> &stalls){
    int maxi = INT_MIN;
    for(int i=0;i<stalls.size();i++){
        maxi = max(maxi,stalls[i]);
    }
    return maxi;
}

//brute-force method ---> T.C ---> O(Maxi-mini * n) ---> S.C ---> O(1)
bool canPossible(vector<int> stalls,int cows,int minDist){
    int cntCows = 1;
    int last = stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-last>=minDist){
            cntCows++;
            last = stalls[i];
        }
    }
    if(cntCows >= cows) return true;
    else return false; 
}

int aggressiveCows1(vector<int> &stalls,int cows){
    sort(stalls.begin(),stalls.end());
    int mini = getMini(stalls);
    int maxi = getMaxi(stalls);
    for(int i=1;i<=maxi-mini;i++){
        if(canPossible(stalls,cows,i)==true){
            continue;
        }else{
            return i-1;
        }
    }
}

//optimal-approach ---> T.C ---> O(log 2 maxi-mini * n) ---> S.C ---> O(1)
int aggressiveCows2(vector<int> &stalls,int cows){
    sort(stalls.begin(),stalls.end());
    int mini = getMini(stalls);
    int maxi = getMaxi(stalls);
    int low = mini;
    int high = maxi;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(canPossible(stalls,cows,mid)==true){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    int n;
    cout<<"Enter the strength of the stalls array : ";
    cin>>n;
    vector<int> stalls(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the element stalls["<<i<<"] : ";
        cin>>stalls[i];
    }
    int cows;
    cout<<"Enter the number of cows : ";
    cin>>cows;
    cout<<"The maximum distance between the minimum distance any two cows : "<<aggressiveCows1(stalls,cows);
}