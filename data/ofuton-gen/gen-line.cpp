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

    int n, coord_max, same_y;
    scanf("%d%d%d", &n, &coord_max, &same_y);
    printf("%d\n", n);

    point p;
    std::set<point>::iterator it;
    p.first = rand() % coord_max + 1;
    p.second = 25252;
    s.insert(p);
    if (same_y) printf("%d %d\n", p.first, p.second);
    else printf("%d %d\n", p.second, p.first);
    while (--n) {
        do {
            p.first = rand() % coord_max + 1;
            p.second = 25252;
        } while ((it = s.find(p)) != s.end());
        s.insert(it, p);
        if (same_y) printf("%d %d\n", p.first, p.second);
        else printf("%d %d\n", p.second, p.first);
    }

    return 0;
}

