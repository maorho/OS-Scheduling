#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        write(1, "error\n", 6);
        exit(-1, "");
    } else {
        if (set_policy(atoi(argv[1])) == 0) {
            write(1, "success\n", 8);
        } else {
            write(1, "error\n", 6);
            exit(-1, "");
        }
    }
    exit(0, "");
}