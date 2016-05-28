#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <utility>
static const int MAXN = 100007;

typedef std::pair<int, int> edge;
typedef std::set<edge> edgelist;

int n, m;
int depth[MAXN] = { 0 };

int dsu_par[MAXN];
inline void dsu_init() {
    for (int i = 0; i < n; ++i) dsu_par[i] = i;
}
inline int dsu_getroot(int u) {
    if (dsu_par[u] == u) return u;
    else return (dsu_par[u] = dsu_getroot(dsu_par[u]));
}
inline bool dsu_union(int u, int v) {
    u = dsu_getroot(u);
    v = dsu_getroot(v);
    if (u == v) return false;
    if (rand() & 1) dsu_par[u] = v;
    else dsu_par[v] = u;
    return true;
}

int main()
{
    unsigned int seed = (unsigned)time(NULL);
    fprintf(stderr, "Seed: %u\n", seed);
    srand(seed);

    edgelist s;
    int prevent_cycles;
    scanf("%d%d%d", &n, &m, &prevent_cycles);
    printf("%d %d\n", n, m);
    dsu_init();
    int u, v;
    if (!prevent_cycles) for (int i = 0; i < m; ++i) {
        do {
            u = rand() % n, v = rand() % n;
        } while (u == v || s.find(edge(u, v)) != s.end());
        printf("%d %d\n", u + 1, v + 1);
        s.insert(edge(u, v));
        s.insert(edge(v, u));
    } else {
        static int mapped[MAXN];
        for (int i = 0; i < n; ++i) mapped[i] = i + 1;
        for (int i = 0; i < n; ++i) std::swap(mapped[rand() % n], mapped[rand() % n]);
        //for (int i = 0; i < n; ++i) printf("%d%c", mapped[i], i == n - 1 ? '\n' : ' ');
        int cur = 0;
        for (int i = 0; i < m; ++i) {
            if (cur == 0 || (cur < n - 1 && rand() % 16)) {
                ++cur;
                u = rand() % cur;
                printf("%d %d\n", mapped[cur], mapped[u]);
                depth[cur] = depth[u] + 1;
                s.insert(edge(cur, u));
                s.insert(edge(u, cur));
            } else {
                do {
                    u = rand() % (cur + 1), v = rand() % (cur + 1);
                } while (u == v || (depth[u] - depth[v]) % 2 == 0 || s.find(edge(u, v)) != s.end());
                printf("%d %d\n", mapped[u], mapped[v]);
                s.insert(edge(u, v));
                s.insert(edge(v, u));
            }
        }
    }

    return 0;
}

