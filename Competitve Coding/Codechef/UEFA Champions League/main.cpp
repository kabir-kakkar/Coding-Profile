#include <bits/stdc++.h>
using namespace std;

struct Team {
    char name[12];
    int score = 0;
    int gd = 0;
};

int scorediff (int sc1, int sc2)
{
    if ( (sc1-sc2) > 0 )
        return 3;
    else if ( (sc1-sc2) == 0)
        return 1;
    else
        return 3;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Team t[4];
        char name1[12], name2[12];
        int sc1, sc2;


        for (int i=0; i<12; i++)
        {
            cin >> name1 >> sc1 >> name2 >> sc2;
            int flag1 = 0, flag2 = 0;
            int pos1=0, pos2=0;

            for (int j=0; j < 4; j++)
            {
                if (strcmp(name1,t.name[j])==0 && flag1 == 0)
                {
                    flag1 = 1;

                }
                if (strcmp(name2, t.name[j])==0 && flag2 == 0)
                {
                    flag2 = 1;

                }
            }

            if (flag1 == 0)
            {
                t[i].name = name1;
                t[i].sc += scorediff (sc1, sc2);
                t[i].gd += goaldiff (sc1, sc2);
            }
        }

    }
}
