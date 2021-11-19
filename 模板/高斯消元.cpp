const double EPS = 1E-9;
double Gauss(vector<vector<double>> a)
{
    double det = 1;
    for(int i = 0; i < a.size(); ++i)
    {
        int k = i;
        for(int j = i + 1; j < a.size(); ++j)
            if(abs(a[j][i]) > abs(a[k][i])) k = j;
        if(abs(a[k][i]) < EPS)
        {
            det = 0;
            break;
        }
        swap(a[i],a[k]);
        if(i != k) det = -det;
        det *= a[i][i];
        for(int j = i + 1; j < a.size(); ++j) a[i][j] /= a[i][i];
        for(int j = 0; j < a.size(); ++j)
            if(j != i && abs(a[j][i]) > EPS)
                for(int k = i + 1; k < a.size(); ++k) a[j][k] -= a[i][k] * a[j][i];
    }
    return det;
}