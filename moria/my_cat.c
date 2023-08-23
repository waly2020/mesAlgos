#include <stdio.h>

void my_cat(const char* source) {
  FILE* src = fopen(source, "r");
  if (src == NULL) {
    fprintf(stderr, "Error\n");
    return;
  }
  char buffer[10000];
  size_t letters;

  while ((letters = fread(buffer, 1, sizeof(buffer), src)) > 0) {
    fwrite(buffer, 1, letters, stdout);
  }
  fclose(src);
}
int main(int argc, char* argv[]) {
  if (argc < 2) {
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    my_cat(argv[i]);
  }

  return 0;
}