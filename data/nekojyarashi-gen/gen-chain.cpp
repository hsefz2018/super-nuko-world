#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <utility>
#include <vector>
static const int MAXN = 100007;
static const int MAXM = 100007;

int n, m;
int mapped[MAXN];
std::vector<int> c[MAXN];
typedef std::pair<int, int> edge;
typedef std::vector<edge> edgelist;
//edgelist e;
edge e[MAXM];

int main()
{
    unsigned int seed = (unsigned)time(NULL);
    fprintf(stderr, "Seed: %u\n", seed);
    srand(seed);

    scanf("%d%d", &n, &m);
    printf("%d %d\n", n, m);

    for (int i = 0; i < n; ++i) mapped[i] = i + 1;
    for (int i = 0; i < n; ++i) std::swap(mapped[rand() % n], mapped[rand() % n]);

    for (int i = 0; i < n; ++i) c[rand() % (n - m)].push_back(i);
    int ct = 0;
    for (int i = 0; i < (n - m); ++i) if (c[i].size() > 1) {
        int last = c[i][0];
        for (std::vector<int>::iterator j = c[i].begin() + 1; j != c[i].end(); ++j) {
            if (rand() & 1) e[ct++] = edge(mapped[last], mapped[*j]);
            else e[ct++] = edge(mapped[*j], mapped[last]);
            last = *j;
        }
    }

    for (int i = 0; i < m; ++i) std::swap(e[rand() % m], e[rand() % m]);
    //for (edgelist::iterator i = e.begin(); i != e.end(); ++i)
    for (int i = 0; i < m; ++i)
        printf("%d %d\n", e[i].first, e[i].second);

    return 0;
}

