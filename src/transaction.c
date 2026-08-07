#include "../include/transaction.h"

bool addTransaction(FinanceDB *db,
                    const Transaction *transaction)
{
    if (db == NULL || transaction == NULL)
    {
        return false;
    }

    if (db->size == db->capacity)
    {
        if (!dbResize(db))
        {
            return false;
        }
    }

    Transaction temp = *transaction;
    temp.id = db->nextTransactionId++;
    db->transactions[db->size] = temp;

    db->size++;

    return true;
}

int searchTransaction(const FinanceDB *db,
                        int id)
{
    if (db == NULL)
    {
        return -1;
    }

    for (size_t i = 0; i < db->size; i++)
    {
        if (db->transactions[i].id == id)
        {
            return (int)i;
        }
    }

    return -1;
}

bool deleteTransaction(FinanceDB *db,
                        int id)
{
    int index = searchTransaction(db, id);

    if (index == -1)
    {
        return false;
    }

    for (size_t i = index; i < db->size - 1; i++)
    {
        db->transactions[i] =
            db->transactions[i + 1];
    }

    db->size--;

    return true;
}

bool updateTransaction(FinanceDB *db,
                        int id,
                       const Transaction *updated)
{
    int index = searchTransaction(db, id);

    if (index == -1)
    {
        return false;
    }

    /* structure assignment to update the transaction at the found index  */
    db->transactions[index] = *updated;

    return true;
}

void viewTransactions(const FinanceDB *db)
{
    if (db == NULL || db->size == 0)
    {
        printf("No transactions found.\n");
        return;
    }

    printf("\n");

    for (size_t i = 0; i < db->size; i++)
    {
        Transaction *t = &db->transactions[i];

        printf("ID          : %d\n", t->id);
        printf("Date        : %s\n", t->date);
        printf("Type        : %s\n", t->type);
        printf("Category    : %s\n", t->category);
        printf("Amount      : %.2f\n", t->amount);
        printf("Description : %s\n", t->description);

        printf("-------------------------------\n");
    }
}


bool inputTransaction(Transaction *t)
{
    if (t == NULL)
    {
        return false;
    }

    if (!readString("Date (YYYY-MM-DD): ",
                    t->date,
                    DATE_LENGTH))
        return false;

    if (!readString("Type (Income/Expense): ",
                    t->type,
                    MAX_TYPE_LENGTH))
        return false;

    if (!readString("Category: ",
                    t->category,
                    MAX_CATEGORY_LENGTH))
        return false;

    if (!readFloat("Amount: ",
                    &t->amount))
        return false;

    if (!readString("Description: ",
                    t->description,
                    MAX_DESCRIPTION_LENGTH))
        return false;

    return true;
}