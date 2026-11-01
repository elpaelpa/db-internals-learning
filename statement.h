#ifndef STATEMENT_H
#define STATEMENT_H

#include "input_buffer.h"

typedef enum { 
    PREPARE_SUCCESS,
     PREPARE_UNRECOGNIZED_STATEMENT 
} PrepareResult;

typedef enum { 
    STATEMENT_INSERT, 
    STATEMENT_SELECT 
} StatementType;

typedef struct {
  StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer*, Statement*);
void execute_statement(Statement*);


#endif