int read()
{
    int ans = 0, sgn = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            sgn *= -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans * sgn;
}