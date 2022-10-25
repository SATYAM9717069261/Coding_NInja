#include<iostream>
#include<string>
using namespace std;
int *getLPS(string pattern)
{
    int len=pattern.length();
    int *lps=new int [len];
    lps[0]=0;
    int i=1, j=0;
    while(i<len)
    {
        if(pattern[i]==pattern[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
            
        }
    }
    return lps;
}
bool KmpSearch(string text, string pattern)
{
    int *lps=getLPS(pattern);
    int lenText=text.length();
    int lenPattern=pattern.length();
    int i=0, j=0;
    while(i<lenText&&j<lenPattern)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
            
        }
        
    }
    return j==lenPattern?true:false;
}
int main()
{
    int test;cin>>test;
    while(test--){
        string subString; cin>>subString;
        string str;cin>>str;
        if(KmpSearch(str, subString))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
