#include "kernel/types.h"
#include "user/user.h"

#define STDOUT 1

void print(const char *s) {
    write(STDOUT, s, strlen(s));
}

int main(int argc, char *argv[]) {
    print("          ____\n");
    print("         / __ \\__  __\n");
    print("        / / / / / / /\n");
    print("       / /_/ / /_/ / \n");
    print("      /_/   \\__,_/  \n\n");

    print("OS: fyntora\n");
    print("Kernel: xv6-public\n");
    print("User: root\n");


    exit(0);
}
