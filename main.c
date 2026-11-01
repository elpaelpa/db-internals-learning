#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "input_buffer.h"
#include "row.h"
#include "statement.h"
#include "command.h"

//Create the REPL
int main(void){
    Table* table = new_table();
    InputBuffer* input_buffer = new_input_buffer();

    while(true){
        print_prompt();
        read_input(input_buffer);

        //If the buffer begins with '.' -> the command is a "meta-command"
        if(input_buffer->buffer[0] == '.'){
            switch(do_meta_command(input_buffer)){ 
                case (META_COMMAND_SUCCESS):
                    continue;
                case (META_COMMAND_UNRECOGNIZED_COMMAND):
                    printf("Unrecognized command '%s' .\n",input_buffer->buffer);
                    continue;
            }
        }

        Statement statement;
        switch (prepare_statement(input_buffer, &statement)){
            case (PREPARE_SUCCESS):
                break;
            case (PREPARE_SYNTAX_ERROR):
                printf("Syntax error. Could not parse statement.\n");
                continue;
            case (PREPARE_UNRECOGNIZED_STATEMENT):
                printf("Unrecognized keyword at start of '%s' .\n",input_buffer->buffer);
                continue;
 
        }
       
        // execute_statement(&statement);
        // printf("Executed.\n");
        switch(execute_statement(&statement,table)){
            case (EXECUTE_SUCCESS):
                printf("Executed.\n");
                break;
            case (EXECUTE_TABLE_FULL):
                printf("Error: Table full.\n");
                break;
        }
    }
}