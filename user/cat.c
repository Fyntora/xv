#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

#define BUF_SIZE 512
#define STDIN   0
#define STDOUT  1
#define STDERR  2

static char buf[BUF_SIZE];

static void
cat_fd(int fd)
{
  int n;

  for (;;) {
    n = read(fd, buf, sizeof(buf));

    if (n == 0)
      return;   // EOF

    if (n < 0) {
      fprintf(STDERR, "cat: read error\n");
      exit(1);
    }

    if (write(STDOUT, buf, n) != n) {
      fprintf(STDERR, "cat: write error\n");
      exit(1);
    }
  }
}

int
main(int argc, char *argv[])
{
  int fd;

  // No arguments: read from stdin
  if (argc == 1) {
    cat_fd(STDIN);
    exit(0);
  }

  for (int i = 1; i < argc; i++) {
    fd = open(argv[i], O_RDONLY);
    if (fd < 0) {
      fprintf(STDERR, "cat: cannot open %s\n", argv[i]);
      exit(1);
    }

    cat_fd(fd);
    close(fd);
  }

  exit(0);
}
