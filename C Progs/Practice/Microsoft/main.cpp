#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    char *input1 = "1234";
    int input2 = 4;
    int input3 = 4;
   int cnt = 0;
    for (int i = 0; i < input3; i++)
    {
        if (input1[i] <= (int)input2)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
