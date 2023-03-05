#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int anagrama(string s1, string s2)
{
    int ok=0;
    int l1,l2;
    l1=s1.length();
    l2=s2.length();
    if(l1!=l2)
        return 0;
    else
    {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i=0;i<l1;i++)
        {
            if(s1[i]!=s2[i])
                return 0;
        }
    }
    return 1;
}
int main()
{
    vector <string> cuvinte;
    string cuvant;
    int counter;
    while(cin>>cuvant)
    {
        cuvinte.push_back(cuvant);
    }
    for(int i=0;i<cuvinte.size();i++)
    {
        counter=0;
        for(int j=0;j<cuvinte.size();j++)
        {
            if(anagrama(cuvinte[i],cuvinte[j])==1 && i!=j)
            {
                cuvinte.erase(cuvinte.begin()+j);
                counter++;
                j--;
            }
        }
        if(counter!=0)
        {
            cuvinte.erase(cuvinte.begin()+i);
            i--;
        }
    }
    for(int i=0;i<cuvinte.size();i++)
        cout<<cuvinte[i]<<endl;
    return 0;
}
