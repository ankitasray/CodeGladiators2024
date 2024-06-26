/* Read input from STDIN. Print your output to STDOUT*/

#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *a[])
{
    //Write code here
    int t;
    cin>>t;
    while(t--){
        int p,x,r1;
    cin>>p>>x>>r1;

    int n,y,r2;
    cin>>n>>y>>r2;

    int paul_time = (p/x)+r1;
    int nina_time = (n/y)+r2;

    if(paul_time < nina_time){
        cout<<"PAUL"<<endl;
        cout<<paul_time<<endl;
    }else if(paul_time > nina_time){
        cout<<"NINA" <<endl;
        cout<<nina_time<<endl;
    }
    else{
        cout<<"BOTH" <<endl;
        cout<<nina_time<<endl;
    }
    }
    
}
