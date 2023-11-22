#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int a;
        long long sum=0;
        cin>>a;
        map<char,int>cnt;
        int j=1;
        for(char ch='a';ch<='z';ch++){
            cnt[ch]=j;
            j++;
        }
        for(auto u:s){
            sum+=cnt[u];
            //cout<<cnt[u]<<" ";
        }
        if(sum<=a){
            cout<<s<<endl;
            continue;
        }
        //cout<<sum<<endl;
        map<pair<char,int>,int>cn;
        vector<pair<char,int>>p;
        for(int i=0;i<s.size();i++){
            p.push_back({s[i],i});
            cn[{s[i],i}]=0;
        }
        sort(p.begin(),p.end());
        /*for(int i=0;i<s.size();i++){
            //cout<<p[i].first
        }*/
        for(int i=s.size()-1;i>=0;i--){
            sum-=cnt[p[i].first];
            cn[{p[i].first,p[i].second}]=1;
            if(sum<=a){
                break;
            }
        }
        string st;
        for(int i=0;i<s.size();i++){
            if(cn[{s[i],i}]==0){
                st+=s[i];
            }
        }
        cout<<st<<endl;
    }
}
