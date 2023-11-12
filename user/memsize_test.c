#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    fprintf(1, "%d\n", memsize());
    char *test;
    test = malloc(20000);
    fprintf(1, "%d\n", memsize());
    free(test);
    fprintf(1, "%d\n", memsize());
    exit(0, "");
}