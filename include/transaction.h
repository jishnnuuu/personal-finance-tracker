#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "database.h"

bool addTransaction(FinanceDB *db, const Transaction *transaction);

int searchTransaction(const FinanceDB *db, int id);

bool updateTransaction(FinanceDB *db,
                        int id,
                       const Transaction *updatedTransaction);

bool deleteTransaction(FinanceDB *db, int id);

void viewTransactions(const FinanceDB *db);

bool inputTransaction(Transaction *transaction);

#endif