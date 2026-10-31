#ifndef INPUT_BUFFER_H
#define INPUT_BUFFER_H

#include <sys/types.h>

//Define a input buffer type
typedef struct{
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();
void close_input_buffer();

void read_input(InputBuffer*);
void print_prompt();
#endif
