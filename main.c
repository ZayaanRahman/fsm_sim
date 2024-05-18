#include <stdio.h>
#include "fsm.h"
#include "cli.h"

// gcc -o test main.c fsm.c cli.c

int main()
{
    State *state_arr = new_state_arr((char *[]){"s0", "s1", "s2", "s3"}, 4);
    Fsm fsm = new_fsm(state_arr, 4);

    connect_states(&state_arr[0], &state_arr[0], 0, &state_arr[1], 0);
    connect_states(&state_arr[1], &state_arr[2], 0, &state_arr[1], 0);
    connect_states(&state_arr[2], &state_arr[0], 0, &state_arr[3], 0);
    connect_states(&state_arr[3], &state_arr[0], 1, &state_arr[1], 0);

    process_input(&fsm, "10");
    process_input(&fsm, "10");

    free_state_arr(state_arr);
}