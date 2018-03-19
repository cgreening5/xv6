#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"
#include "fs.h"
#define stdout 1

int main(int argc, char * argv[])
{
  if (argc < 2)
  {
    printf(2, "Usage: filestat <filename>\n");
    exit();
  }

  char * fileName = argv[1];
  int fd = open(fileName, O_RDONLY);
  if (fd < 0)
  {
    printf(2, "Unable to locate file '%s'\n", argv[1]);
    exit();
  }

  struct stat st;
  
  fstat(fd, &st);
  printf(stdout, "filename: %s\nchecksum: %d\ntype: %d\nsize: %d\ndevice number: %d\ninode number: %d\nlinks to file: %d\n",
         fileName,(int)st.checksum,(int)st.type,(int)st.size,st.dev,(int)st.ino,(int)st.nlink);
  close(fd);
  exit();
}
