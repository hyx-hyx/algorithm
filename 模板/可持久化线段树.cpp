void build(int l = 1, int r = n, int p = 1)
{
    if (l == r)
        val(p) = A[l];
    else
    {
        ls(p) = ++cnt, rs(p) = ++cnt; // 新建节点
        int mid = (l + r) / 2;
        build(l, mid, ls(p));
        build(mid + 1, r, rs(p));
        val(p) = val(ls(p)) + val(rs(p));
    }
}
// 令A_x加d，p表示原版本的节点，q表示新版本的节点
void update(int l, int r, int d, int p, int q, int cl = 1, int cr = n) // 区间修改
{
    ls(q) = ls(p), rs(q) = rs(p), mark(q) = mark(p); // 复制节点
    if (cl >= l && cr <= r)
    {
        if (cr > cl)
            mark(q) += d;
    }
    else
    {
        int mid = (cl + cr) / 2;
        if (cl <= r && mid >= l) // 提前进行判断，以免新建不必要的节点
            ls(q) = ++cnt, update(l, r, d, ls(p), ls(q), cl, mid);
        if (mid + 1 <= r && cr >= l)
            rs(q) = ++cnt, update(l, r, d, rs(p), rs(q), mid + 1, cr);
    }
    val(q) = val(p) + (min(cr, r) - max(cl, l) + 1) * d; // 根据需要更新的区间长度计算当前节点的值
}
ll query(int l, int r, int p, int cl = 1, int cr = n, ll mk = 0) // 区间查询
{
    if (cl > r || cr < l)
        return 0;
    else if (cl >= l && cr <= r)
        return val(p) + mk * (cr - cl + 1); // 加上带的标记
    else
    {
        int mid = (cl + cr) / 2;
        return query(l, r, ls(p), cl, mid, mk + mark(p)) + query(l, r, rs(p), mid + 1, cr, mk + mark(p)); // 带着标记传递
    }
}