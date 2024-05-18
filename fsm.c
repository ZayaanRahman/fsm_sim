#include "fsm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Fsm new_fsm(State *state_arr, int num_states)
{
    Fsm fsm;
    fsm.num_states = num_states;
    fsm.state_arr = state_arr;
    fsm.current_state = &state_arr[0];

    return fsm;
}

// wrong, returns pointer to local variable
// Fsm new_fsm_names(char **state_names, int num_states)
// {
//     State state_arr[num_states];
//     for (int i = 0; i < num_states; i++)
//     {
//         State state;
//         strcpy(state.name, state_names[i]);
//         state_arr[i] = state;
//     }

//     return new_fsm(state_arr, num_states);
// }


State *new_state_arr(char **state_names, int num_states)
{
    State *state_arr = (State *)malloc(num_states * sizeof(State));
    for (int i = 0; i < num_states; i++)
    {
        State state;
        strcpy(state.name, state_names[i]);
        state_arr[i] = state;
    }

    return state_arr;
}

void free_state_arr(State *state_arr)
{
    free(state_arr);
}

State *get_state(Fsm *fsm, char *state_name)
{
    for (int i = 0; i < fsm->num_states; i++)
    {
        if (strcmp(fsm->state_arr[i].name, state_name) == 0)
        {
            return &fsm->state_arr[i];
        }
    }

    return NULL;
}

void connect_states(State *source, State *next0, int next0_out, State *next1, int next1_out)
{
    source->next0 = next0;
    source->next0_out = next0_out;
    source->next1 = next1;
    source->next1_out = next1_out;
}

char *process_input(Fsm *fsm, char *input)
{
    State *current_state = fsm->current_state;
    printf("start: %s\n", current_state->name);

    for (int i = 0; i < strlen(input); i++)
    {

        if (input[i] == '0')
        {
            printf("%s -> %s output: %d\n", current_state->name, current_state->next0->name, current_state->next0_out);
            current_state = current_state->next0;
        }
        else
        {
            printf("%s -> %s output: %d\n", current_state->name, current_state->next1->name, current_state->next1_out);
            current_state = current_state->next1;
        }
    }
    fsm->current_state = current_state;
}

void reset_fsm(Fsm *fsm)
{
    fsm->current_state = &(fsm->state_arr[0]);
}