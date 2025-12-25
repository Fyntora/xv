#include "kernel/types.h"
#include "user/user.h"

int main(void) {
    ps(); // call the syscall
    exit(0);
}
