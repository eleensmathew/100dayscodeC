#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
typedef long long int ll;
#define lll "\n";
using namespace std;
int main()
 {
 ios_base::sync_with_stdio(false);
    cin.tie(0);
   
     
         ll n,q;
          cin>>n>>q;
          ll a[n];
          ll s=0;
          for(int i=0;i<n;i++)
          {
          cin>>a[i];
          s+=a[i];
          }
          int f=0;
          ll g=0;
          unordered_map<ll,ll>mp;
          while(q--)
          {
              ll p;
               cin>>p;
               if(p==2)
               {
                   ll b;
                    cin>>b;
                    mp.clear();
                    s=n*b;
                    f=1;
                    g=b;
                    cout<<s<<"\n";
               }
               else{
                   ll x,y;
                    cin>>x>>y;
                    if(f==1)
                    {
                    if(mp[x]>0)
                    {
                        s-=mp[x];
                        s+=y;
                    }
                    else{
                    mp[x]=y;
                    s-=g;
                    s+=y;
                    }
                    mp[x]=y;
                    }
                    else{
                        s-=a[x-1];
                        s+=y;
                        a[x-1]=y;
                    }
                    cout<<s<<"\n";
               }
          }
     
 }