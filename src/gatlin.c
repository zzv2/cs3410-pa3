#include "lordofthecache.h"

/* Greedy Bot. Fills its own half of memory using cores 0 and 1,
 * and fills the opponent's half using cores 2 and 3.
 * Uses a simple loop with a random start address.
 */
void __start(int core_id, int num_crashes, unsigned char payload) {

  if (core_id == 3) {
    while (1) {
      int i;
      for (i = 0; i < TAUNT_SIZE; i++) {
        if (HOME_STATUS->taunt[i] >= 0) {
        Eye_Of_Sauron(HOME_STATUS->taunt[i]);
        }
      }
    }
  } else {
    //invoke into cache
    char[4] ct = {payload, payload, payload, payload};
    int it = *(int *)a;
    int it2 = it; //what if they overwrote this value to their payload value
    printf("char payload : %c", payload);
    int *ptr = (int *)HOME_DATA_SEGMENT + ((HOME_DATA_SIZE/4)/3 * core_id);

    int i = 0;
    while (1) {
      
      ptr[i++] = (int) it;
    }
}
