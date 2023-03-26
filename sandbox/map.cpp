#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
string names[3] = {"박찬울", "안성은", "박유민"};
int main() {
    for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
        mp[names[i]] = i + 1;
    }

    cout << mp.size() << endl;

    cout << mp["bigstone"] << endl; // 없는 키를 인덱싱하게 되면 해당 key 에 value 는 0 으로 세팅된다.

    cout << mp.size() << "\n";// 없는 키를 불러오기만 했을 뿐인데, 사이즈가 1개 늘었다. (위와 같은 이유로)

    mp["bigstone"] = 4;

    auto it = mp.find("없는키");
    if (it == mp.end()) {
        cout << "indexed non-existing key" + '\n';
    }

    mp["exist"] = 100;
    auto p = mp.find("exist");
    if (p != mp.end()) {
        cout << (*p).first << " : " << (*p).second << '\n';
    }

    cout << "Every pair of MAP" << endl;

    for (auto k : mp) {
        cout << k.first << " : " << k.second << endl;
    }

    cout << "Loop every pair of MAP through pointer" << "\n";
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << (*it).first << " : " << (*it).second << '\n';
    }

    // insert pair to map
    mp.insert({"LikeThis", 123});

    // empty value of string
    map<string, string> map2;
    cout << map2["anonymous"] << "\n";
    cout << "When string default string value of pair of map: " << (*map2.find("anonymous")).second << "\n";

    // If you need to check if a specific key exists, use `if(m.find("key") != m.end())` instead of `if(m["key"] != 0)`.

    return 0;
}
