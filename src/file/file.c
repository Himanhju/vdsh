#include <sys/types.h>
#include <sys/stat.h>

long file_GetSize(const char *filename) {
  struct stat file_stats;

  if (stat(filename, &file_stats) < 0) {
    return -1;
  }

  return (long)file_stats.st_size;
}