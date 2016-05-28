#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <sys/time.h>

static const char *emoji[] = {
    "|･ω･｀)",
    "o(^▽^)o",
    "♪",
    "\\(//∇//)\\"
};
static const int emoji_ct = sizeof(emoji) / sizeof(emoji[0]);

std::pair<float, const char *> check(FILE *inpt, FILE *crct, FILE *ctst)
{
    int jury_t, jury_w, part_t, part_w;
    assert(fscanf(crct, "%d%d", &jury_t, &jury_w) == 2);
    if (fscanf(ctst, "%d%d", &part_t, &part_w) != 2) {
        return std::make_pair(0.0,
            "Incorrect format: two integers expected");
    }
    if (jury_t == part_t) {
        if (jury_w == part_w) {
            static char s[256];
            sprintf(s, "Correct %s", emoji[rand() % emoji_ct]);
            return std::make_pair(1.0, s);
        } else {
            return std::make_pair(0.3, "Acceptable: answer to the first question is correct");
        }
    } else {
        return std::make_pair(0.0, "Incorrect answer to the first question");
    }
}

int main(int argc, char *argv[])
{
    struct timeval tv; gettimeofday(&tv, NULL);
    srand((unsigned)(time(NULL) + tv.tv_sec + tv.tv_usec));

    assert(argc == 4);
    FILE *crct = fopen(argv[2], "r");
    FILE *ctst = fopen(argv[3], "r");
    assert(crct && ctst);
    std::pair<float, const char *> result = check(NULL, crct, ctst);
    fclose(crct);
    fclose(ctst);
    fprintf(stdout, "%lf", result.first);
    fprintf(stderr, "%s\n", result.second);
    return 0;
}

