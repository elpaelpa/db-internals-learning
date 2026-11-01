#ifndef STATEMENT_H
#define STATEMENT_H

#include "input_buffer.h"
#include "row.h"



typedef enum { 
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED_STATEMENT,
  PREPARE_SYNTAX_ERROR
} PrepareResult;

typedef enum { 
  STATEMENT_INSERT, 
  STATEMENT_SELECT 
} StatementType;

typedef struct {
  StatementType type;
  Row row_to_insert;
} Statement;

typedef enum { 
  EXECUTE_SUCCESS, 
  EXECUTE_TABLE_FULL
} ExecuteResult;


PrepareResult prepare_statement(InputBuffer*, Statement*);
ExecuteResult execute_statement(Statement*,Table* table);

//Queries
ExecuteResult execute_insert (Statement* statement, Table* table);
ExecuteResult execute_select(Statement* statement, Table* table);

#endif