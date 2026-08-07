#include "../include/database.h"

/*
Purpose:
    Initialize the finance database.

Inputs:
    Pointer to FinanceDB.

Returns:
    true  -> success
    false -> allocation failure

Time Complexity:
    O(1)

Space Complexity:
    O(n)
    where n = INITIAL_CAPACITY
*/

bool dbInit(FinanceDB *db)
{
    if (db == NULL)
    {
        return false;
    }

    db->transactions = malloc(INITIAL_CAPACITY * sizeof(Transaction));

    if (db->transactions == NULL)
    {
        return false;
    }

    db->size = 0;
    db->capacity = INITIAL_CAPACITY;
    db->nextTransactionId = 1;

    return true;
}


/*
Purpose:
    Doubles the database capacity when it becomes full.

Inputs:
    Pointer to FinanceDB.

Returns:
    true  -> Resize successful
    false -> Memory allocation failed

Error Cases:
    NULL database pointer
    realloc failure

Time Complexity:
    O(n) in the worst case (data copy)

Amortized Complexity:
    O(1) per insertion

Space Complexity:
    O(n)
*/

bool dbResize(FinanceDB *db)
{
    if (db == NULL)
    {
        return false;
    }

    size_t newCapacity = db->capacity * 2;

    Transaction *temp =
        realloc(db->transactions,
                newCapacity * sizeof(Transaction));

    if (temp == NULL)
    {
        return false;
    }

    db->transactions = temp;
    db->capacity = newCapacity;

    return true;
}