#include <iostream>

using namespace std;
int main() {
    long long n,kol;
    cin >> n;
    kol=0;
    if (n%2==0) {
        kol+=n/2;
        n=0;
    }
    while (n>0){
        kol++;
        long long d=1;
        for (long long i=2;i<=n;i++){
            if (i*i>n){
                n=0;
                d=0;
                break;
            }
            if (n%i==0) {d=i;break;}
        }
        n=n-d;
        if (n%2==0) {
            kol+=n/2;
            n=0;
        }
    }
    cout << kol;
    return 0;
}