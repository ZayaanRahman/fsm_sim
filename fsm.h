#ifndef FSM_H
#define FSM_H

// mealy state
typedef struct State
{
    char name[20];

    struct State *next0;
    int next0_out;

    struct State *next1;
    int next1_out;
} State;

// mealy fsm
typedef struct Fsm
{
    int num_states;
    struct State *state_arr;
    struct State *current_state;
} Fsm;

// create a new fsm with an array of states
// first state is default state
Fsm new_fsm(State *state_arr, int num_states);

// wrong, returns pointer to local variable
// // create a new fsm with an array of state names
// // recommended, as does not dynamically allocate memory for state array
// Fsm new_fsm_names(char **state_names, int num_states);

// create state array from names
State *new_state_arr(char **state_names, int num_states);

// free state array
void free_state_arr(State *state_arr);

// get ptr to state based on its name, return NULL if name not found
State *get_state(Fsm *fsm, char *state_name);

// connect states to the next states for input 0 or 1, and set outputs 0 or 1 for transition
void connect_states(State *source, State *next0, int next0_out, State *next1, int next1_out);

// proccess input string and return string output and state for each input
char *process_input(Fsm *fsm, char *input);

// reset to state[0]
void reset_fsm(Fsm *fsm);

#endif