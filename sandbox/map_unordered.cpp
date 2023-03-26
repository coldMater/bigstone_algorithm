
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;
int main() {

    um.insert({"hi!", 111});
    um.insert({"Hello!", 222});
    um.insert({"Greetings!", 333});

    for (auto p : um) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}