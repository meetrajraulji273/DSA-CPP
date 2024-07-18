#include<bits/stdc++.h>
using namespace std;

void print1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void print2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void print3(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<j<<" ";
		}
		cout<<endl;
    }
}
void print4(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<i<<" ";
		}
		cout<<endl;
    }
}
void print5(int n){
    	for(int i=n;i>0;i--){
		for(int j=1;j<=i;j++){
			cout<<"* ";
		}
		cout<<endl;
	}
}
void print6(int n){
    	for(int i=n;i>0;i--){
		for(int j=1;j<=i;j++){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}
void print7(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int k=0;k<2*i+1;k++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void print8(int n){
     for(int i=n;i>0;i--){
        for(int j=0;j<=n-i-1;j++){
            cout<<" ";
        }
        for(int k=0;k<2*i-1;k++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void print9(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int k=0;k<2*i+1;k++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=n;i>0;i--){
        for(int j=0;j<=n-i-1;j++){
            cout<<" ";
        }
        for(int k=0;k<2*i-1;k++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void print10(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=n-1;i>0;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void print11(int n){
    int start =1;
    for(int i=0;i<n;i++){
        if(i%2==0) start =1;
        else start=0;
        for(int j=0;j<=i;j++){
            cout<<start<<" ";
            start = 1- start;
        }
        cout<<endl;
    }
}
void print12(int n){
    int spaces = 2*(n-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int k=1;k<=spaces;k++) //k<=2*n-2*i
        { 
            cout<<" ";
        }
        for(int l=i;l>=1;l--){
            cout<<l;
        }
        cout<<endl;
        spaces-=2;
    }
}
void print13(int n){
    int num=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<num<<" ";
            num += 1;
        }
        cout<<endl;
    }
}
void print14(int n){
      for(int i=0;i<n;i++){
          for(char ch = 'A'; ch<='A'+i;ch++){
              cout<<ch<<" ";
              
          }
          cout<<endl;
      }
}
void print15(int n){
    for(int i=n;i>0;i--){
        for(char ch='A';ch<'A'+i;ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }    
}
void print16(int n){
    for(int i=0;i<n;i++){
        char ch='A'+i;
        for(int j=0;j<=i;j++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
void print17(int n){
    for(int i=n-1;i>=0;i--){
        char ch='A'+i;
        for(int j=0;j<=i;j++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
void print18(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2*(n-i)-1;j++){
            cout<<" ";
        }
        for(char ch='A';ch<'A'+i;ch++){
            cout<<ch<<" ";
        }
        if(i>1){
            
            for(char ch = 'A'+i-2; ch>='A';ch--){
              cout<<ch<<" ";
          }
        }
        cout<<endl;
    }
}
void print19(int n){
    cout<<"--------";
    cout<<endl<<endl;

    for(int i=0;i<n;i++){
       for(char ch='E'-i;ch<='E';ch++){
        cout<<ch<<" ";
       }
       cout<<endl;
    }
    
    cout<<endl<<endl;
    cout<<"--------";
}
void print20(int n){
    cout<<"--------";
    cout<<endl<<endl;

    for(int i=0;i<n;i++){
        char ch = 'A'+n-1;
        for(int j=0;j<=i;j++){
            cout<<ch<<" ";
            ch--;
        }
        cout<<endl;
    }

    cout<<endl<<endl;
    cout<<"--------";
}
void print21(int n){
    cout<<"---------";
    cout<<endl<<endl;

    cout<<endl<<endl;
    cout<<"---------";
}
int main(){
    cout<<"--------";
    cout<<endl<<endl;

    int t;
    cout<<"enter the no. of times you have to test the program : ";
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cout<<"Enter the no. of rows : ";
        cin>>n;
        print20(n);
    }
    
    cout<<endl<<endl;
    cout<<"--------";
    return 0;
}