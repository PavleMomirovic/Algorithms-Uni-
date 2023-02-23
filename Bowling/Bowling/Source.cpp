#include <iostream>
using namespace std;

int max(int a, int b, int c) {
    if (a > b) {
        if (a > c) {
            return a;
        }
        else return c;
    }
    else {
        if (b > c) {
            return b;
        }
        else return c;
    }
}

int main()
{
    int n;
    cin >> n;
    int niz[1000]={{0}};

    for (int i = 0;i < n;i++) {
        cin >> niz[i];
    }

    int b[1000];
    b[n] = 0;
    b[n + 1] = 0;

    for (int i = n - 1;i >= 0;i--) {
        b[i] = max(b[i + 1], b[i + 1] + niz[i], b[i + 2] + (niz[i] * niz[i + 1]));
    }

    cout << endl << b[0];

    return 0;
}
/*
* test example:
10

1 1 7 8 -2 -4 -5 2 3 4

result:92 [ 1+1+7*8+(-4)*(-5)+2+3*4=92 ]

it testes all the basic cases plus the case with two 1's next to each other (1+1 > 1*1) and testes multiplying two negative numbers (-4*(-5))=20 
*/