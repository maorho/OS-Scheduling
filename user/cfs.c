#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    int cfs_priority[1];
    long long rtime[1];
    long long stime[1];
    long long retime[1];
    set_cfs_priority(2);
    int pid = fork();
    if (pid == 0) {
        pid = fork();
        if (pid != 0) {
            set_cfs_priority(1);
        }
    } else {
        set_cfs_priority(0);
    }
    for (int i = 1; i <= 1000000; i++) {
        if (i % 100000 == 0) {
            sleep(10);
        }
    }

    get_cfs_stats(getpid(), cfs_priority, rtime, stime, retime);
    wait(0, 0);
    printf("pid: %d\ncfs_priority: %d\nrtime: %d\nstime: %d\nretime: %d\n\n",getpid(), cfs_priority[0], rtime[0], stime[0], retime[0]);
    exit(0, "");
}