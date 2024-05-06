#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<char,double>& x, const pair<char,double>& y) {
    return x.second > y.second;  // Use strict greater to ensure stable sort behavior
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<string> cipherArray;
    string cipher;
    map<char,int> freq;

    for( char ch = 'a'; ch <= 'z'; ch++ ) {
        freq[ch] = 0;
    }

    int count = 0;
    while(getline(cin,cipher)) {
        transform(cipher.begin(), cipher.end(), cipher.begin(), ::tolower);  // Convert line to lowercase
        for(char c : cipher) {
            if (isalpha(c)) {
                count++;
                freq[c]++;
            }
        }
        cipherArray.push_back(cipher);
    }

    vector<pair<char,double>> cipherFreq, plainFreq;
    cout << "--------- cipher letter Frequency ----------" << endl;
    for(auto it : freq) {
        double percentage = double(it.second * 100.00) / double(count);
        cout << it.first << "  " << fixed << setprecision(2) << percentage << "%" << endl;
        cipherFreq.push_back({it.first, percentage});
    }

    map<char, double> freqDist = {
        {'a', 8.05}, {'b', 1.67}, {'c', 2.23}, {'d', 5.1}, {'e', 12.22},
        {'f', 2.14}, {'g', 2.3}, {'h', 6.62}, {'i', 6.28}, {'j', 0.19},
        {'k', 0.95}, {'l', 4.08}, {'m', 2.33}, {'n', 6.95}, {'o', 7.63},
        {'p', 1.66}, {'q', 0.06}, {'r', 5.29}, {'s', 6.02}, {'t', 9.67},
        {'u', 2.92}, {'v', 0.82}, {'w', 2.6}, {'x', 0.11}, {'y', 2.04},
        {'z', 0.06}
    };

    cout << "--------- plain letter Frequency ----------" << endl;
    for(auto it : freqDist) {
        cout << it.first << "  " << fixed << setprecision(2) << it.second << "%" << endl;
        plainFreq.push_back({it.first, it.second});
    }

    sort(plainFreq.begin(), plainFreq.end(), cmp);
    sort(cipherFreq.begin(), cipherFreq.end(), cmp);

    map<char, char> charMap;
    cout << "--------- frequency compare ----------" << endl;
    for(int i = 0; i < 26; i++) {
        cout << cipherFreq[i].first << " -> " << plainFreq[i].first << endl;
        charMap[cipherFreq[i].first] = plainFreq[i].first;
    }

    cout << "--------- Decoding ----------" << endl;
    for(auto& line : cipherArray) {
        for(char& c : line) {
            if (isalpha(c)) {
                c = charMap[c];
            }
        }
        cout << line << endl;
    }

    return 0;
}
