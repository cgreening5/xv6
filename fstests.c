#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"
#include "fs.h"
#define stdout 1
#define FILENAME "test.txt"

void printfstat(int fd)
{
  struct stat st;
  fstat(fd, &st);
  printf(stdout, "filename: %s\n"
      "checksum: %d\n"
      "type: %d\n"
      "size: %d\n"
      "device number: %d\n"
      "inode number: %d\n"
      "links to file: %d\n\n",
         FILENAME,
         (int)st.checksum,
         (int)st.type,
         (int)st.size,st.dev,
         (int)st.ino,
         (int)st.nlink);
}

int main()
{
  int fd = open(FILENAME, O_CHECKED | O_WRONLY | O_CREATE);
  printfstat(fd);
 
  char * testmesg = "This is a test."; 
  write(fd, testmesg, strlen(testmesg));
  printfstat(fd);
  close(fd);
  printfstat(fd);
  unlink(FILENAME);
  printfstat(fd);
  exit();
}
