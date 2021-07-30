#include <iostream>
using namespace std;
int main()
{
    // int i2;
    // int i = -1, &r = 0;
    // int *const p2 = &i2;
    // const int i = -1, &r = 0;
    // const int *const p3 = &i2;
    // const int *p1 = &i2;
    // const int &const r2;
    // const int i2 = i, &r = i;

    int i, *const cp;
    int *p1, *const p2;
    const int ic, &r = ic;
    const int *const p3;
    const int *p;
    i = ic;
    p1 = p3;
    p1 = &ic;
    p3 = &ic;
    p2 = p1;
    ic = *p3;

    


}
