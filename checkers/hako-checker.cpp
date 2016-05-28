#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <sys/time.h>

static const char *ans = "mikan";

inline bool validate(char &ch) {
    if (ch >= 'A' && ch <= 'N') { ch += 32; return true; }
    if (ch >= 'a' && ch <= 'n') { return true; }
    return false;
}

std::pair<float, const char *> check(FILE *inpt, FILE *crct, FILE *ctst)
{
    static char part[5];
    static char s[256];
    for (int i = 0; i < 5; ++i) {
        part[i] = fgetc(ctst);
        if (!validate(part[i])) {
            sprintf(s, "Incorrect format: five letters between A and N expected, but '%c' (#%d) found", part[i], part[i]);
            return std::make_pair(0.0, s);
        }
    }
    int matched = 0, distinct = 0;
    for (int i = 0; i < 5; ++i)
        if (part[i] == ans[i]) ++matched;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            if (ans[i] == part[j]) { ++distinct; break; }
    }
    if (matched == 5) {
        sprintf(s, "みかんですね ♪");
    } else {
        sprintf(s, "%d position%s fully matched; extra %d distinct letter%s present in your guess.",
            matched, matched == 1 ? "" : "s",
            distinct - matched, distinct - matched == 1 ? " is" : "s are");
    }
    return std::make_pair(0.2 * matched, s);
}

int main(int argc, char *argv[])
{
    struct timeval tv; gettimeofday(&tv, NULL);
    srand((unsigned)(time(NULL) + tv.tv_sec + tv.tv_usec));
    
    assert(argc == 4);
    FILE *ctst = fopen(argv[3], "r");
    assert(ctst);
    std::pair<float, const char *> result = check(NULL, NULL, ctst);
    fclose(ctst);
    fprintf(stdout, "%lf", result.first);
    fprintf(stderr, "%s\n", result.second);
    return 0;
}

