#include<bits/stdc++.h>

using namespace std;
int main ()
{
    int a[5];
    for(int i = 0 ; i<5 ; i++)
    {
        cin>>a[i];
    }

    for(int i = 0 ; i<5 ; i++)
    {
        int flag = 0;
        if(a[i] <2)
           flag = 0;
        else
        {
            for(int j = 2 ; j*j<=a[i]; j++)
            {
                if(a[i]%j == 0)
                {
                     flag = 0;
                     break;
                }
                else flag = 1;
            }
        }
        if( flag == 1)
            cout<<a[i];
            else cout<<"NO";

    }

}