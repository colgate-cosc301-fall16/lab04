// Test that the childcount syscall works properly

#include "types.h"
#include "user.h"

#define CHILDREN  10
#define PAUSE     100

int main(void) {
  printf(1, "Running child test...\n");

  int ppid = getpid();

  int i = 0;
  for(i = 0; i < CHILDREN; i++) {
    int pid = fork();
    if(pid < 0)
      break;
    if(pid == 0) {
      sleep(PAUSE);
      exit();
    }
  }

  int count = -ppid;
  //count = childcount(ppid);

  for (int j = 0; j < i; j++) {
    wait();
  }

  if (count != i) {
    printf(1, "FAIL: Child count should be %d not %d\n", i, count);
  } else {
    printf(1, "PASSED\n");
  }
  exit();
}
