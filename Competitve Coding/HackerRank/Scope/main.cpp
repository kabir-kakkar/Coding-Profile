#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;

  	public:
  	int maximumDifference;

  	Difference (vector<int> v) {
        elements = v;
  	}

  	void computeDifference()
  	{
  	    int i, j, k = 0;
  	    //int diff[elements.size()];
  	    maximumDifference = 0;

  	    for (i = 0; i < elements.size()-1; i++)
        {
            for (j=i+1; j < elements.size(); j++)
            {
                int diff = abs(elements[i] - elements[j]);

                if (maximumDifference < diff) {
                    maximumDifference = diff;
                }
            }
        }
  	}

};

int main() {
  //  int N;
   // cin >> N;

    vector<int> a;

   a.push_back(1);
   a.push_back(2);
   a.push_back(5);

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}
