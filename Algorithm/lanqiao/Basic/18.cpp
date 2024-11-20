#include <iostream>
using namespace std;

int main()
{
    double ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;
    // 将x1转化为左下点, x2转化为右上点
    double newax1 = min(ax1, ax2);
    double neway1 = min(ay1, ay2);
    double newax2 = max(ax1, ax2);
    double neway2 = max(ay1, ay2);
    double newbx1 = min(bx1, bx2);
    double newby1 = min(by1, by2);
    double newbx2 = max(bx1, bx2);
    double newby2 = max(by1, by2);
    double overlapLong = max(0.0, min(newax2, newbx2) - max(newax1, newbx1));
    double overlapWidth = max(0.0, min(neway2, newby2) - max(neway1, newby1));
    double s = overlapLong * overlapWidth;
    printf("%.2lf", s);
    return 0;
}