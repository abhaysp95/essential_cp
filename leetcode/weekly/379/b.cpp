#include <iostream>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        bool betr = false, betb = false;
        if (abs(c - e) == abs(d - f)) {
            betb = true;
            if (abs(a - c) == abs(b - d) &&
                    ((a < e && a > c) || (a > e && a < c))) {  // if rook is in between
                betr = true;
            }
        }
        if (!betr && betb) return 1;

        if (a == e || b == f) {
            if (a == e && ((c >= e && c <= a) || (c <= e && c >= a))) {
                return 2;
            } else if (b == f && ((d >= f && d <= b) || (d <= f && d >= b))) {
                return 2;
            }
            return 1;
        }

        return 2;
    }
};
