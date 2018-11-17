#include <iostream>

using namespace std;
int main() {
    int n,i;
    string s;
    cin >> n;
    cin >> s;
    for (i=0;i<n-1;i++) {
        if (s[i]>s[i+1]) {
            break;
        }
        cout << s[i];
    }
    for (int k=i+1;k<n;k++){
        cout << s[k];
    }
    return 0;
}