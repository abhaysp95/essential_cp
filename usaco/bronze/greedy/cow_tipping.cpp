#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("cowtip.in");
ofstream fout("cowtip.out");

void print_mat(vector<vector<bool>>& mat, int n) {
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
       fout << mat[i][j] << ' ';
    }
    fout << '\n';
  }
  fout << "----------\n";
}

void solve() {
  int n;
  fin >> n;
  vector<vector<bool>> mat(n, vector<bool>(n, false));
  for (int i=0;i<n;i++) {
    string s;
    fin >> s;
    for (int j=0;j<s.size();j++)
      mat[i][j]=s[j]-'0';
  }
  // print_mat(mat, n);

  int tc=0;
  for (int i=n-1;i>=0;i--) {
    for (int j=n-1;j>=0;j--) {
      if (mat[i][j]) {
        tc+=1;
        for (int a=i;a>=0;a--) {
          for (int b=j;b>=0;b--) mat[a][b]=mat[a][b]^1;
        }
        // print_mat(mat, n);
      }
    }
  }
  fout << tc << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}

