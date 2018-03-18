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

void error(char * mesg)
{
  printf(2, "%s\n", mesg);
  exit();
}

int main()
{
  printf(stdout, "Creating new file.\n");
  int fd = open(FILENAME, O_CHECKED | O_WRONLY | O_CREATE);
  if (fd < 0)
    error("Unable to open file.");
  printfstat(fd);

  printf(stdout, "Writing to file.\n");
  char * testmesg = "This is a test."; 
  if (write(fd, testmesg, strlen(testmesg)) < 0)
    error("An error occurred writing to the new file.");
  printfstat(fd);
  
  printf(stdout, "Closing file.\n");
  if (close(fd) < 0)
    error("Unable to close file.");
  printfstat(fd);

  printf(stdout, "Unlinking file.\n");
  if (unlink(FILENAME) < 0)
    error("An error occurred unlinking the file.");

  printfstat(fd);
  exit();
}
