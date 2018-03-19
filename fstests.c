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
  printfstat(fd);

  printf(stdout, "Writing to file.\n");
  char * testmesg = "This is a test."; 

  //fill buffer with whatever
  for (int i = 0; i < BSIZE; i++)
    buffer[i] = 'A';

  for (int i = 0; i <= NDIRECT; i++)
  {
    write(fd, testmesg, BSIZE);
    printf(stdout, "%d blocks written of %d\n", i, NDIRECT);
  }
  printfstat(fd);
  
  printf(stdout, "Closing file.\n");
  if (close(fd) < 0)
    error("Unable to close file.");

  printf(stdout, "Opening file for reading\n.");
  fd = open(FILENAME, O_RDONLY);
  printfstat(fd);

  printf(stdout, "Reading data from file\n");
  read(fd, buffer, BSIZE);

  if (strcmp(buffer, testmesg) != 0)
    error("Invalid memory.");
  printfstat(fd);

  close(fd);
  fd = open(FILENAME, O_WRONLY);
}

void testsmallfile()
{
  printf(stdout, "Testing writing to file.\n");
  char * teststring = "This is a test.";
  char buffer[strlen(teststring + 1)];
  int fd = open(FILENAME, O_WRONLY);
  write(fd, teststring, strlen(teststring));
  printfstat(fd);
  close(fd);
  fd = open(FILENAME, O_RDONLY);
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
