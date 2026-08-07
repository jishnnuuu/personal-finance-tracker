#ifndef DATABASE_H
#define DATABASE_H

#include "common.h"

/*
 * Represents one financial transaction.
 */

typedef struct
{
    int id;
    char date[DATE_LENGTH];
    char type[MAX_TYPE_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
    char description[MAX_DESCRIPTION_LENGTH];
} Transaction;

/*
 * Owns all transactions in memory.
 */

typedef struct
{
    Transaction *transactions;
    size_t size;
    size_t capacity;
} FinanceDB;

/*
 * Initializes the database.
 */
bool dbInit(FinanceDB *db);

/*
 * Releases allocated memory.
 */
void dbDestroy(FinanceDB *db);

/*
 * Increases storage when required.
 */
bool dbResize(FinanceDB *db);

#endif