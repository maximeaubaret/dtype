
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_DELAY_BETWEEN_CHARS 100 // milli

void
print(
  char *string,
  int delay)
{
  // Disable stdout buffering
  setbuf(stdout, NULL);

  for (int i = 0; i < strlen(string); i++) {
    printf("%c", string[i]);
    usleep(delay * 1000);
  }
}

void
help(
  const char *program_name)
{
  printf("Usage: %s [options] <text>\n", program_name);
  printf("  Options:\n");
  printf("    -d, --delay <delay>: delay in milliseconds between each character\n");
}

int
main(
  int argc,
  char const *argv[])
{
  if (argc <= 1) {
    help(argv[0]);
    return EXIT_SUCCESS;
  }

  int delay = DEFAULT_DELAY_BETWEEN_CHARS;
  int argsToPrint = 1;

  // Do we have the delay option?
  if (strcmp(argv[1], "--delay") == 0 ||
      strcmp(argv[1], "-d") == 0) {

    // Parse the delay
    delay = atoi(argv[2]);

    argsToPrint += 2;
  }

  // Iterate over the remaining arguments
  for (int i = argsToPrint; i < argc; i++) {
    print((char *)argv[i], delay);

    // Keep a space between arguments
    if (i < argc - 1) {
      printf(" ");
    }
  }

  printf("\n");

  return EXIT_SUCCESS;
}
