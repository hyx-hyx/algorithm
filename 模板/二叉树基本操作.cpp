/*在接下来的代码块中我们约定:
n为结点个数，
h为高度，
val[x] 为结点x处存的数值，
cnt[x]为结点x存的值所出现的次数,
lc[x] 和 rc[x] 分别为结点x的左子结点和右子结点。
*/
//遍历二叉树
void print(int o) {
  // 遍历以 o 为根节点的二叉搜索树
  if (!o) return;  // 遇到空树，返回
  print(lc[o]);    // 递归遍历左子树
  for (int i = 1; i <= cnt[o]; i++) printf("%d\n", val[o]);  // 输出根节点信息
  print(rc[o]);  // 递归遍历右子树
}
//查找最大最小值
int findmin(int o) {
  if (!lc[o]) return o;
  return findmin(lc[o]);  // 一直向左儿子跳
}
int findmax(int o) {
  if (!rc[o]) return o;
  return findmax(rc[o]);  // 一直向右儿子跳
}
//插入一个元素
void insert(int& o, int v) {
  if (!o) {
    val[o = ++sum] = v;
    cnt[o] = siz[o] = 1;
    lc[o] = rc[o] = 0;
    return;
  }
  siz[o]++;
  if (val[o] == v) {
    cnt[o]++;
    return;
  }
  if (val[o] > v) insert(lc[o], v);
  if (val[o] < v) insert(rc[o], v);
}
//删除一个元素
int deletemin(int& o) {
  if (!lc[o]) {
    int u = o;
    o = rc[o];
    return u;
  } else {
    int u = deletemin(lc[o]);
    siz[o] -= cnt[u];
    return u;
  }
}
void del(int& o, int v) {
  // 注意 o 有可能会被修改
  siz[o]--;
  if (val[o] == v) {
    if (cnt[o] > 1) {
      cnt[o]--;
      return;
    }
    if (lc[o] && rc[o]) o = deletemin(rc[o]);
    // 这里以找右子树的最小值为例
    else
      o = lc[o] + rc[o];
    return;
  }
  if (val[o] > v) del(lc[o], v);
  if (val[o] < v) del(rc[o], v);
}
//求元素的排名
int queryrnk(int o, int v) {
  if (val[o] == v) return siz[lc[o]] + 1;
  if (val[o] > v) return queryrnk(lc[o], v);
  if (val[o] < v) return queryrnk(rc[o], v) + siz[lc[o]] + cnt[o];
}
//查找排名为k的元素
int querykth(int o, int k) {
  if (siz[lc[o]] >= k) return querykth(lc[o], k);
  if (siz[lc[o]] < k - cnt[o]) return querykth(rc[o], k - siz[lc[o]] - cnt[o]);
  return val[o];
  // 如要找排名为 k 的元素所对应的结点，直接 return o 即可
}


