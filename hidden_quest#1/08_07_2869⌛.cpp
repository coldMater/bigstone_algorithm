#include <bits/stdc++.h>
using namespace std;

double A, B, V;
int main () {
  cin >> A >> B >> V;
  cout << int(ceil((V - A) / (A - B))) + 1;
  return 0;
}

// It took a lot of time. I understood the problem, but it took me a long time to figure out the relationship between the last day and the correct answer.
// Hint: When the bar is fully climbed, how many days are needed if you exclude the distance climbed on the last day?