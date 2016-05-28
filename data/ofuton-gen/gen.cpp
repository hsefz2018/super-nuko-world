#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <utility>

int main()
{
    typedef std::pair<int, int> point;
    std::set<point> s;
    unsigned int seed = (unsigned)time(NULL);
    fprintf(stderr, "Seed: %u\n", seed);
    srand(seed);

    int n, coord_max;
    scanf("%d%d", &n, &coord_max);
    printf("%d\n", n);

    point p;
    std::set<point>::iterator it;
    p.first = rand() % coord_max + 1;
    p.second = rand() % coord_max + 1;
    s.insert(p);
    printf("%d %d\n", p.first, p.second);
    while (--n) {
        do {
            p.first = rand() % coord_max + 1;
            p.second = rand() % coord_max + 1;
        } while ((it = s.find(p)) != s.end());
        s.insert(it, p);
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}

