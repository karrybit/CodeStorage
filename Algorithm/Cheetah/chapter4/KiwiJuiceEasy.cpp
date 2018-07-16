#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, i, j, value;
    cin >> n >> m;

    vector<int> capacities, bottles, fromId, toId;

    for (i = 0; i < 2; i++) for (j = 0; j < n; j++) {
        cin >> value;
        if (i == 0) capacities.push_back(value);
        else        bottles.push_back(value);
    }

    for (i = 0; i < 2; i++) for (j = 0; j < m; j++) {
        cin >> value;
        if (i == 0) fromId.push_back(value);
        else        toId.push_back(value);
    }

    for (i = 0; i < m; i++) {
        int sum = bottles[fromId[i]] + bottles[toId[i]];
        bottles[toId[i]] = min(sum, capacities[toId[i]]);
        bottles[fromId[i]] = sum - bottles[toId[i]];
    }

    for (i = 0; i < n; i++) {
        cout << bottles[i];
        if (i != n-1) cout << " ";
    }
    cout << endl;

    return 0;
}
