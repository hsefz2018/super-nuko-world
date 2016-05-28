#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXN = 300007;

int n;
int h[MAXN], ops[MAXN];

template <typename T> void discretize(int n, T *a)
{
    static std::pair<T, int> p[MAXN];
    for (int i = 0; i < n; ++i)
        p[i] = std::make_pair(a[i], i);
    std::sort(p, p + n);
    int rk = 1; // 1-based for Fenwick trees
    for (int i = 0; i < n; ++i) {
        if (i && p[i].first != p[i - 1].first) ++rk;
        a[p[i].second] = rk;
    }
}

int fwk[MAXN];
inline void fwk_add(int pos, int val) {
    while (pos < MAXN) {
        fwk[pos] += val;
        pos += (pos & -pos);
    }
}
inline int fwk_sum(int right) {
    int ans = 0;
    while (right) {
        ans += fwk[right];
        right -= (right & -right);
    }
    return ans;
}
inline int fwk_sum(int left, int right) {
    return fwk_sum(right) - fwk_sum(left - 1);
}

int main()
{
    freopen("matatabi.in", "r", stdin);
    freopen("matatabi.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
    discretize(n, h);

    std::fill(fwk, fwk + MAXN, 0);
    for (int i = 0; i < n; ++i) {
        ops[i] = fwk_sum(h[i] + 1, n);
        fwk_add(h[i], 1);
    }
    std::fill(fwk, fwk + MAXN, 0);
    for (int i = n - 1; i >= 0; --i) {
        ops[i] = std::min(ops[i], fwk_sum(h[i] + 1, n));
        fwk_add(h[i], 1);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) ans += ops[i];
    printf("%lld\n", ans);

    fclose(stdin); fclose(stdout);
    return 0;
}

