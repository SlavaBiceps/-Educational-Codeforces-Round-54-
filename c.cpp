#include <iostream>
#include <cmath>

using namespace std;
int main() {
    long long d,t;
    long long m[10000];
    cin >> t;
    for (long long i=0;i<t;i++){cin >> m[i];}
    for (long long i=0;i<t;i++){
        d=m[i];
            if (d*d-4*d>=0) {
            cout << "Y ";
            printf("%.17lf", (d-sqrt(d*d-4*d))/2);
            cout << " ";
            printf("%.17lf", (d+sqrt(d*d-4*d))/2);
            cout << endl;
            } else {cout << "N" << endl;}
    }
    return 0;
}