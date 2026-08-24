#include "types.h"
#include "fcntl.h"
#include "stat.h"
#include "user.h"
#include "fs.h"


int
main(int argc, char *argv[])
{
  int fd, i, n;
  char buf[128];
  if (argc < 1) {
    printf(1, "provide file name\n");
    exit();
  } 
  fd = open(argv[1], O_RDONLY);
  if (fd < 0) {
    printf(1, "error while file open\n");
    exit();
  }
  lseek(fd, 10, SEEK_SET);
  n = read(fd, buf, 5);
  if (n < 0) {
    printf(1, "error while read file");
    exit();
  }
  for(i = 0; i < n; i++)
    printf(1, "%c", buf[i]);
  printf(1, "\n");


  lseek(fd, 10, SEEK_CUR);
  n = read(fd, buf, 5);
  if (n < 0) {
    printf(1, "error while read file");
    exit();
  }
  for(i = 0; i < n; i++)
    printf(1, "%c", buf[i]);
  printf(1, "\n");

  lseek(fd, -5, SEEK_END); 
  n = read(fd, buf, 5);
  if (n < 0) {
    printf(1, "error while read file");
    exit();
  }
  for(i = 0; i < n; i++)
    printf(1, "%c", buf[i]);
  printf(1, "\n");

  lseek(fd, 5, SEEK_END);
  n = read(fd, buf, 5);
  for(i = 0; i < n; i++)
    printf(1, "%c", buf[i]);
  printf(1, "\n");
  exit();
}
