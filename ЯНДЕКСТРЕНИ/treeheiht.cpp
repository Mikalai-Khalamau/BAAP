#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int HeightCalculator(const string& name,const unordered_map<string,string>& Parents,unordered_map<string,int>& Heights) {
    if (Heights.find(name)!=Heights.end()) {
        return Heights[name];
    }
    if (Parents.find(name)==Parents.end()) {
        Heights[name] = 0;
    }
    else {
        Heights[name]=HeightCalculator(Parents.at(name),Parents,Heights)+1;
    }
    return Heights[name];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    unordered_map<string, string> Parents;
    unordered_map<string, int> Heights;
    for (int i = 0; i < N - 1; ++i) {
        string descendant, parent;
        cin >> descendant >> parent;
        Parents[descendant] = parent;
    }

    for (const auto& pair : Parents) {
        HeightCalculator(pair.first, Parents, Heights);
    }

    for (const auto& pair : Parents) {
        Heights[pair.second];
    }


    vector<string> names;

    for (const auto& pair : Heights) {
        names.push_back(pair.first);
    }
    sort(names.begin(), names.end());
    for (const string& name : names) {
        cout << name << " " << Heights[name] << '\n';
    }
    return 0;
}