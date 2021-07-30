int prime[maxn];
int visit[maxn];
void Prime(){
    mem(visit,0);
    mem(prime, 0);
    for (int i = 2;i <= maxn; i++) {
        if (!visit[i]) {
            prime[++prime[0]] = i;      
        }
        for (int j = 1; j <=prime[0] && i*prime[j] <= maxn; j++) {
            visit[i*prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
