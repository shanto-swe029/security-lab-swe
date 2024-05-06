#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<char,double>x,pair<char,double>y)
{
    return x.second>=y.second;
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<string>cipherArray;
    string cipher;
    map<char,int>freq;
  
    vector<int>v;

    int count = 0;
    // Input from File 
    while(getline(cin,cipher))  
    {
        for(int i = 0; i < cipher.size(); i++)
        {
            char c = cipher[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                count++;
                freq[tolower(cipher[i])]++;
            }
             
        }
        cipherArray.push_back(cipher);
    }
    vector<pair<char,double>>cipherFreq,plainFreq;
   cout<<"--------- cipher letter Frequency ----------"<<endl;
    for(auto it : freq)
    {
        cout<<it.first<<"  "<<double((it.second*100.00)/count)<<setprecision(2)<<fixed<<" %"<<endl;
        cipherFreq.push_back({it.first,double((it.second*100.00)/count)});
    }
    map<char, double> freqDist = {
        {'a', 8.05},
        {'b', 1.67},
        {'c', 2.23},
        {'d', 5.1},
        {'e', 12.22},
        {'f', 2.14},
        {'g', 2.3},
        {'h', 6.62},
        {'i', 6.28},
        {'j', 0.19},
        {'k', 0.95},
        {'l', 4.08},
        {'m', 2.33},
        {'n', 6.95},
        {'o', 7.63},
        {'p', 1.66},
        {'q', 0.06},
        {'r', 5.29},
        {'s', 6.02},
        {'t', 9.67},
        {'u', 2.92},
        {'v', 0.82},
        {'w', 2.6},
        {'x', 0.11},
        {'y', 2.04},
        {'z', 0.06}
    };
        cout<<"--------- plain letter Frequency ----------"<<endl;
    for(auto it : freqDist)
    {
        // Plain letter Frequency --   
        cout<<it.first<<"  "<<it.second<<setprecision(2)<<fixed<<" %"<<endl;
        plainFreq.push_back({it.first,it.second});
    }
    sort(plainFreq.begin(),plainFreq.end(),cmp);
    sort(cipherFreq.begin(),cipherFreq.end(),cmp);
  cout<<"--------- frequency compare ----------"<<endl;
    for(int i = 0; i < 26; i++)
    {
        
       cout<< cipherFreq[i].first<<" ->  "<<plainFreq[i].first<<endl;

    } 
//  Fir second cipher
map<char, char> sub = {
        {'u', 'e'},
        {'v', 't'},
        {'e', 'a'},
        {'c', 's'},
        {'d', 'h'},
        {'m', 'r'},
        {'s', 'i'},
        {'n', 'w'},
        {'h', 'n'},
        {'y', 'd'},
        {'o', 'g'},
        {'z', 'b'},
        {'f', 'l'},
        {'l', 'o'},
        {'i', 'f'},
        {'a', 'v'},
        {'b', 'u'},
        {'p', 'y'},
        {'g', 'm'},
        {'k', 'p'},
        {'t', 'c'},
        {'x', 'k'},
        {'r', 'x'},
        {'q', 'z'},
        {'j', 'q'},
        {'w', 'j'}
    };
    for(int i = 0; i < 26; i++)
    {
        char c = char('a'+i);
        if(sub.find(c)!=sub.end())
            {
                cout<<"mapped - "<<char('a'+i)<<" -> "<<sub[char('a'+i)]<<endl;
            }
    }
      cout<<"--------- Decoding ----------"<<endl;
    for(int k = 0 ; k < cipherArray.size() ; k++)
    {
        cipher = cipherArray[k];
        for(int i = 0; i < cipher.size(); i++)
        {
            char c = cipher[i];
            if (sub.find(tolower(c))!=sub.end())
            {
               
                cipher[i] = (sub[tolower(c)]);
            }
             
        }
        cout<<cipher<<endl;
    }
    
}
