#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int number_coins;
        cin >> number_coins;

        int value_coins[number_coins];
        int i;
        double sum = 0.0;

        for (i = 0; i < number_coins; i++)
        {
            cin >> value_coins[i];
            sum += value_coins[i];
        }
        double mean = sum/number_coins;

        bool flag = false;

        for( i=0; i < number_coins; i++)
        {
            double new_mean = ((sum-value_coins[i])/(number_coins-1));
            if( new_mean == mean )
            {
                flag = true;
                break;
            }
        }

        if(flag)
            cout<<i+1<<endl;
        else
            cout<<"Impossible"<<endl;
    }
}
