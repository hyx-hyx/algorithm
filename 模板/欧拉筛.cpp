#define maxn 
int prime[maxn];
int visit[maxn];
void Prime(){
    memset(visit,0,sizeof(prime));
    memset(prime, 0,sizeof(prime));
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
