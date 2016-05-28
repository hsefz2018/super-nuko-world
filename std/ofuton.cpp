#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
typedef std::pair<int, int> point;
#define x first
#define y second
static const int MAXN = 50006;
static const int INF = 0x7fffffff;

int n;
point p[MAXN];

long long work()
{
    std::sort(p, p + n);

    std::multiset<int> s;
    for (int i = 0; i < n; ++i) s.insert(p[i].y);

    long long ans =
        (long long)(p[n - 1].x - p[0].x) *
        (*s.rbegin() - *s.begin());
    long long initial = ans;
    int lymin = INF, lymax = -INF;
    for (int i = 0; i < n - 1; ++i) {
        s.erase(s.find(p[i].y));
        lymin = std::min(lymin, p[i].y);
        lymax = std::max(lymax, p[i].y);
        ans = std::min(ans,
            (long long)(p[i].x - p[0].x) * (lymax - lymin) +
            (long long)(p[n - 1].x - p[i + 1].x) * (*s.rbegin() - *s.begin()));
    }

    return initial - ans;
}

int main()
{
    freopen("ofuton.in", "r", stdin);
    freopen("ofuton.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &p[i].x, &p[i].y);

    long long ans = work();
    for (int i = 0; i < n; ++i) std::swap(p[i].x, p[i].y);
    ans = std::max(ans, work());

    printf("%lld\n", ans);
    fclose(stdin); fclose(stdout);
    return 0;
}

