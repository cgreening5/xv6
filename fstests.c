#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"
#include "fs.h"
#define stdout 1
#define FILENAME "test.txt"

char buffer[BSIZE];

void printfstat(int fd)
{
  struct stat st;
  if (fstat(fd, &st) < 0)
  {
    printf(stdout, "Unable to get file info.\n");
    return;
  }
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

void testlargefile()
{
  printf(stdout, "Creating new file.\n");
  int fd = open(FILENAME, O_CHECKED | O_WRONLY | O_CREATE);
  char * teststring = "this is a test.";
  int len = strlen(teststring);
  printfstat(fd);

  printf(stdout, "Writing to file.\n");

  //fill buffer with whatever. Too much repetition tends to cause
  //0 checksums
  for (int i = 0; i < BSIZE; i++)
    buffer[i] = teststring[i % len];

  for (int i = 0; i <= NDIRECT; i++)
  {
    write(fd, buffer, BSIZE);
  }
  printfstat(fd);
  
  printf(stdout, "Closing file.\n");

  printf(stdout, "Opening file for reading\n.");
  fd = open(FILENAME, O_RDONLY);
  printfstat(fd);

  printf(stdout, "Verifying data from file\n");
  for (int i = 0; i <= NDIRECT; i++)
  {
    read(fd, buffer, BSIZE);
    for (int i = 0; i < BSIZE; i++)
    {
      if (buffer[i] != teststring[i % len])
      {
        error("File corrupted.");
      }
    }
  }

  printfstat(fd);

  close(fd);
  fd = open(FILENAME, O_WRONLY);
}

void testsmallfile()
{
  printf(stdout, "Testing writing to file.\n");
  char * teststring = "This is a test.";
  int len = strlen(teststring);
  char buffer[len + 1];
  int fd = open(FILENAME, O_WRONLY | O_CREATE | O_CHECKED);
  write(fd, teststring, strlen(teststring));
  printfstat(fd);
  close(fd);
  
  fd = open(FILENAME, O_RDONLY | O_CHECKED);
  read(fd, buffer, strlen(teststring));
  if (strcmp(teststring, buffer) == 0)
    printf(stdout, "Success\n.");
  else
  {
    printf(stdout, "Failure: expected %s, found %s", teststring, buffer);
  } 
  close(fd);
  unlink(FILENAME);
}

int main()
{
  testsmallfile();
  testlargefile(); 
  exit();
}
