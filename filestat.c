#include "types.h"
#include "user.h"
#define stdout 1

int main(int argc, char * argv[])
{
  if (argc < 2)
  {
    printf(2, "Usage: filestat <filename>\n");
    exit();
  }

  char * filename = argv[1];
  printf(stdout, "%s\n", filename);
  exit();
}
