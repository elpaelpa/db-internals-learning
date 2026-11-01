#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statement.h"
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement){
    //INSERT 
    if(strncmp(input_buffer->buffer,"insert",strlen("insert")) == 0){
        statement->type = STATEMENT_INSERT;

        return PREPARE_SUCCESS;
    }

    //SELECT
    if(strncmp(input_buffer->buffer,"select",strlen("select")) == 0){
        statement->type = STATEMENT_SELECT;

        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED_STATEMENT;
}
void execute_statement(Statement* statement){
    switch (statement->type)
    {
    case (STATEMENT_INSERT):
        /* code */
        printf("This is where we would do an insert.\n");
        break;
    
    case (STATEMENT_SELECT):
        /* code */
        printf("This is where we would do a select.\n");
        break;
    default:
        break;
    }
}

