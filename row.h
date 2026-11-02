#ifndef ROW_H
#define ROW_H

#include <stdint.h>



#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255


//ROW  (hardcoded table for now)
typedef struct{
  uint32_t id;
  char username[COLUMN_USERNAME_SIZE + 1]; //+1 for null terminator character
  char email[COLUMN_EMAIL_SIZE + 1];//+1 for null terminator character
} Row;

extern const uint32_t ID_SIZE;
extern const uint32_t USERNAME_SIZE;
extern const uint32_t EMAIL_SIZE;
extern const uint32_t ID_OFFSET;
extern const uint32_t USERNAME_OFFSET;
extern const uint32_t EMAIL_OFFSET;
extern const uint32_t ROW_SIZE;

//TABLE stuff

extern const uint32_t PAGE_SIZE; //standard virtual memory page size => db page maps directly 
#define TABLE_MAX_PAGES 100
extern const uint32_t ROWS_PER_PAGE;
extern const uint32_t TABLE_MAX_ROWS;

typedef struct{
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
} Table;

Table* new_table();
void free_table(Table* table);

// Row serialization
void serialize_row(Row*, void*);
void deserialize_row(void*,Row *);

void* row_slot(Table* table, uint32_t row_num);
void print_row(Row* row);

#endif