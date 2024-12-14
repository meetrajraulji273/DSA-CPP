#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> &books){
    int maxi = INT_MIN;
    for(int i=0;i<books.size();i++){
        maxi = max(maxi,books[i]);
    }
    return maxi;
}

int getSum(vector<int> &books){
    int sum = 0;
    for(int i=0;i<books.size();i++){
        sum += books[i];
    }
    return sum;
}

int noOfStudents(vector<int> books,int pages){
    int students = 1;
    int stdPages = books[0];
    for(int i=1;i<books.size();i++){
        if(books[i]+stdPages>pages){
            students++;
            stdPages = books[i];
        }else{
            stdPages += books[i];
        }
    }
    return students;
}

//brute-force-approach ---> T.C ---> O(sum - maxi * n) ---> S.C ---> O(1)
int bookAllocation1(vector<int> &books,int students){
    int sum = getSum(books);
    int maxi = getMax(books);
    for(int pages=maxi;pages<=sum;pages++){
        if(noOfStudents(books,pages)==students){
            return pages;
        }
    }
}

//optimal-approach ---> T.C ----> O(log 2 (sum - maxi) * n) ---> S.C ---> O(1)
int bookAllocation2(vector<int> &books,int students){
    int sum = getSum(books);
    int maxi = getMax(books);
    int low = maxi;
    int high = sum;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(noOfStudents(books,mid)>=students){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    int n;
    cout<<"Enter the strength of the books array : ";
    cin>>n;
    vector<int> books(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the element book["<<i<<"] : ";
        cin>>books[i];
    }
    int students;
    cout<<"Enter the number of students among books should be distributed : ";
    cin>>students;

    cout<<"The minimum of the maximum pages to a student distributing among given students is : "<<bookAllocation1(books,students);
}