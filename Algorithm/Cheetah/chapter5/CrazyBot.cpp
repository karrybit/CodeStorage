#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

using Vertex = struct { int x, y; };

int n;
long double north, east, west, south;

bool contains(vector<Vertex> stack, Vertex target) {
    for (auto it = stack.begin(); it != stack.end(); it++) if (target.x == it->x && target.y == it->y) return true;
    return false;
}

long double calculateProbability(int n, long double p, vector<Vertex> stack) {
    if (n) --n;
    else   return p;

    Vertex prev;
    if (stack.begin() == stack.end()) prev = {0, 0};
    else                              prev = *--stack.end();

    Vertex northVertex = {prev.x, prev.y + 1};
    Vertex eastVertex = {prev.x + 1, prev.y};
    Vertex westVetex = {prev.x - 1, prev.y};
    Vertex southVertex = {prev.x, prev.y - 1};

    bool northContained = contains(stack, northVertex);
    bool eastContained = contains(stack, eastVertex);
    bool westContained = contains(stack, westVetex);
    bool southContained = contains(stack, southVertex);

    long double ans = 0.0;
    if (!contains(stack, northVertex)) {
        stack.push_back(northVertex);
        ans += calculateProbability(n, p * north, stack);
        stack.pop_back();
    }

    if (!contains(stack, eastVertex)) {
        stack.push_back(eastVertex);
        ans += calculateProbability(n, p * east, stack);
        stack.pop_back();
    }

    if (!contains(stack, westVetex)) {
        stack.push_back(westVetex);
        ans += calculateProbability(n, p * west, stack);
        stack.pop_back();
    }

    if (!contains(stack, southVertex)) {
        stack.push_back(southVertex);
        ans += calculateProbability(n, p * south, stack);
        stack.pop_back();
    }

    return ans;
}

int main() {
    cin >> n >> north >> east >> west >> south;
    north /= 100; east /= 100; west /= 100; south /= 100;

    long double ans = calculateProbability(n, 1, vector<Vertex>());
    printf("%Lf\n", ans);

    return 0;
}