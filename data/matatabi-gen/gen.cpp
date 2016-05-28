#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
    unsigned int seed = (unsigned)time(NULL);
    srand(seed);
    fprintf(stderr, "Seed: %u\n", seed);

    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    do printf("%d\n", rand() % n + 1); while (--n);

    return 0;
}

