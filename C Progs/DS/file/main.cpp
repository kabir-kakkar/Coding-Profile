#include <iostream>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

int main()
{
    /*
    pair<char, int> x ;
    map<char, int> m ;

    for(char ch = 'a'; ch <= 'z'; ch++)
    {
        x.first = ch ;
        x.second = (int) ch ;

        m.insert(x) ;
    }

    map<char, int>::iterator it = m.begin() ;


    for(it=m.begin(); it != m.end() ; it++)
    {
        cout << (*it).first << " " << (*it).second << endl ;
    }

    */



    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, int> m ;
    pair<string, int> x ;


    long int number ;
    char name[50], search[50] ;

    int n ;
    cin >> n ;


    for(int i =0; i<n; i++)
    {
        cin >> x.first ;
        cin >> x.second ;

       m.insert(x) ;
    }


    return 0;
}



