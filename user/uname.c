#include "kernel/types.h"
#include "user/user.h"

#define STDOUT 1

void print(const char *s) {
    write(STDOUT, s, strlen(s));
}

int main(int argc, char *argv[]) {
    #define STR_HELPER(x) #x
    #define STR(x) STR_HELPER(x)

    print("FyntoraXV1 - " STR(VERS) "\n");
    exit(0);

}