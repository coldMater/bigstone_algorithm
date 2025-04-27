#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    
    int l = stations[0];
    int sum = 0;
    for (int i = 1; i < stations.size(); ++i) {
        int d = (stations[i] - l) - 1 - (2 * w); // |>>__<<|
        
        if (d > 0) {
            int c = d / (2 * w + 1);
            int r = d % (2 * w + 1) > 0 ? 1 : 0;
            sum += (c + r);
        }
        l = stations[i];
    }
    cout << sum << "\n";
    
    // left end
    {
        int d = stations[0] - 1 - w;
        if (d > 0) {
            int c = d / (2 * w + 1);
            int r = d % (2 * w + 1) > 0 ? 1 : 0;
            sum += (c + r);
        }
    }
    cout << sum << "\n";
    
    // right end
    {
        int d = (n + 1) - stations[stations.size() - 1] - 1 - w;
        if (d > 0) {
            int c = d / (2 * w + 1);
            int r = d % (2 * w + 1) > 0 ? 1 : 0;
            sum += (c + r);
        }
    }
    cout << sum << "\n";

    return sum;
}