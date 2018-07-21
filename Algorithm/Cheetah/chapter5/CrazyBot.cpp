#include <iostream>

using namespace std;

enum Direction { NORTH, EAST, WEST, SOUTH };
int n;
long double north, east, west, south;

/// 回ることのないケースのみ解く
long double calculateProbability(int n, Direction d) {
    if (!n) return 0;

    long double dProbability;
    switch (d) {
        case NORTH:
            dProbability = north;
            break;

        case EAST:
            dProbability = east;
            break;

        case WEST:
            dProbability = west;
            break;

        case SOUTH:
            dProbability = south;
            break;
    }

    Direction s;
    long double sum;
    switch (d) {
        case NORTH:
            s = SOUTH;
            break;

        case EAST:
            s = WEST;
            break;

        case WEST:
            s = EAST;
            break;

        case SOUTH:
            s = NORTH;
            break;
    }

    Direction allCases[] = {NORTH, EAST, WEST, SOUTH};
    for (Direction e: allCases) {
        if (s == e) continue;
        sum += dProbability * calculateProbability(--n, e);
    }

    return sum;
}


int main() {
    int _north, _east, _west, _south;
    cin >> n >> _north >> _east >> _west >> _south;
    north = _north / 100;
    east = _east / 100;
    west = _west / 100;
    south = _south / 100;

    long double ans;
    Direction allCases[] = {NORTH, EAST, WEST, SOUTH};
    for (Direction e: allCases) ans += calculateProbability(--n, e);

    cout << ans << endl;

    return 0;
}