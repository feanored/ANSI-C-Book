// Check if CPU is Big Endian or Little Endian
#include <stdio.h>

int main() {
  char bytearray[4] = { 0x41,0x42,0x43,0x44 };
  int *b = (int*)bytearray;

  printf("%s <> %d\n", bytearray, *b);
  printf("%d <> %d\n", 0x41424344, 0x44434241);

  if (*b == 0x41424344) {
    printf("Big Endian!\n");
  }
  else if (*b == 0x44434241) {
    printf("Little Endian!\n");
  }
  return 0;
}
