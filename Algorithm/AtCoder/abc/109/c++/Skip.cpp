#include <iostream>
#include <vector>

using namespace std;

long gcd(long a, long b) {
  if(a < b) gcd(b, a);
  long r;
  while ((r = a % b)) {
    a = b;
    b = r;
  }
  return b;
}

int main() {
    int N, X; cin >> N >> X;
    vector<long> vc;
    for (int i = 0; i < N; ++i) {
        long x; cin >> x;
        vc.push_back(abs(x - X));
    }

    long ans = vc[0];
    for (int i = 1; i < N; ++i) ans = gcd(ans, vc[i]);

    cout << ans << endl;
 
    return 0;
}