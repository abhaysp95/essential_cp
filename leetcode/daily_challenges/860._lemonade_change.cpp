#include <vector>
using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int>& bills) {
    int a=0,b=0;
    for (int i=0; i<bills.size(); i++) {
      if (bills[i]==5) a++;
      else if (bills[i]==10) {
        if (a==0) return false;
        a--;
        b++;
      } else if (bills[i]==20) {
        if (!(a>=3||(a>=1&&b>=1))) return false;
        if (a>=1&&b>=1) a--,b--;
        else a-=3;
      }
    }
    return true;
  }

  // this below method will not work, because it's not like the customer who can
  // pay 10 will always come after all the 5 and those who will pay 20 will
  // always come at last
  bool lemonadeChange2(vector<int>& bills) {
    int a=0,b=0,c=0;
    for (int i=0; i<bills.size(); i++) {
      if (bills[i]==5) a++;
      else if(bills[i]==10) b++;
      else c++;
    }
    if (a>=b+3*c||(a-b>=c&&b>=c)) return true;
    return false;
  }
};
