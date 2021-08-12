int gcd(int x, int y)
{
    while(y^=x^=y^=x%=y);
    return x;
}
//========================================
inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}
