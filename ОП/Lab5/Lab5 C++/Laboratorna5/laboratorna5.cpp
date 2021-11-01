#include <iostream>
#include <cmath>
using namespace std;

int main()
{
 int n;
    int i;

    for (i = 1; i <= 100; i = i + 1) {          //i=1 because 0 is not natural
        n = i;
        if (i>=10 && n / 10 == n%10 && int(pow(n,2))/100 == int(pow(n, 2))%10) {
                cout << i << endl;
            
        }
        else if (i < 4 ) {           //[1;3]-single digit in square
            cout << i << endl;
        }
        else if (4 <= i && i< 10 && int(pow(n, 2)) / 10 == int(pow(n, 2)) % 10) {          //two digits
            cout << i << endl;
        }
    }
}