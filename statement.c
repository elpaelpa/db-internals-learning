#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statement.h"

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement){
    //INSERT 
    if(strncmp(input_buffer->buffer,"insert",strlen("insert")) == 0){
        statement->type = STATEMENT_INSERT;

        //arguments

        int args_assigned = sscanf(
            input_buffer->buffer, 
            "insert %d %s %s", 
            &(statement->row_to_insert.id),
            statement->row_to_insert.username,
            statement->row_to_insert.email
        );

        if(args_assigned < 3){
            return PREPARE_SYNTAX_ERROR;
        }

        return PREPARE_SUCCESS;
    }

    //SELECT
    if(strncmp(input_buffer->buffer,"select",strlen("select")) == 0){
        statement->type = STATEMENT_SELECT;

        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED_STATEMENT;
}

ExecuteResult execute_statement(Statement* statement,Table* table){
    switch (statement->type) {
    case (STATEMENT_INSERT):
        /* code */
        return execute_insert(statement,table);
    case (STATEMENT_SELECT):
        /* code */
        return execute_select(statement,table);
    }
    return EXECUTE_SUCCESS; // i hate you compiler
}
//Execute queries implementations
ExecuteResult execute_insert (Statement* statement, Table* table){
    if (table->num_rows >= TABLE_MAX_ROWS){
        return EXECUTE_TABLE_FULL;
    }

    Row* row_to_insert = &(statement->row_to_insert);

    serialize_row(row_to_insert,row_slot(table,table->num_rows));
    table->num_rows += 1;

    return EXECUTE_SUCCESS;
}


ExecuteResult execute_select(Statement* statement, Table* table){
    Row row;

    (void) statement; //leave me alone compiler

    for (uint32_t i = 0;i < table->num_rows; i++){
        deserialize_row(row_slot(table,i),&row);
        print_row(&row);
    }

    return EXECUTE_SUCCESS;
}