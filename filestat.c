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
  int fd = open(fileName,O_CHECKED | ORDWR);
  struct stat st;
  
  fstat(fd, &st);
  printf(stdout, "filename=%s checksum: %d \n type: %d  \n size =%d \n device number =%d \n inode number =%d\n links to file =%d\n ",
         fileName,(int)st.checksum,(int)st.type,(int)st.size,st.dev,(int)st.ino,(int)st.nlink);
  //printf(stdout, "%s\n", filename);
  exit();
}
