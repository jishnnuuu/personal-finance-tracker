#include "../include/file.h"

bool saveDatabase(const FinanceDB *db)
{
    if (db == NULL)
    {
        return false;
    }

    FILE *fp = fopen(DATA_FILE, "wb");

    if (fp == NULL)
    {
        return false;
    }

    fwrite(&db->size,
            sizeof(size_t),
            1,
            fp);

    fwrite(db->transactions,
            sizeof(Transaction),
            db->size,
            fp);

    fclose(fp);

    return true;
}


bool loadDatabase(FinanceDB *db)
{
    if (db == NULL)
        return false;

    FILE *fp = fopen(DATA_FILE, "rb");

    if (fp == NULL)
        return true;

    size_t count;

    if (fread(&count,
                sizeof(size_t),
                1,
                fp) != 1)
    {
        fclose(fp);
        return false;
    }

    if (count > MAX_TRANSACTIONS)
    {
        fclose(fp);
        return false;
    }

    size_t newCapacity =
    (count > INITIAL_CAPACITY)
        ? count
        : INITIAL_CAPACITY;

    Transaction *temp =
        realloc(db->transactions,
                newCapacity * sizeof(Transaction));
                
    if (temp == NULL)
    {
        fclose(fp);
        return false;
    }

    db->transactions = temp;
    db->size = count;
    db->capacity = (count == 0) ? INITIAL_CAPACITY : count;

    if (count > 0)
    {
        if (fread(db->transactions,
                    sizeof(Transaction),
                    count,
                    fp) != count)
        {
            fclose(fp);
            return false;
        }
    }

    fclose(fp);

    int maxId = 0;

    for(size_t i = 0; i < db->size; i++)
    {
        if(db->transactions[i].id > maxId)
            maxId = db->transactions[i].id;
    }

    db->nextTransactionId = maxId + 1;

    return true;
}

bool saveDatabase(const FinanceDB *db)
{
    if (db == NULL)
        return false;

    FILE *fp = fopen(DATA_FILE, "wb");

    if (fp == NULL)
        return false;

    if (fwrite(&db->size,
                sizeof(size_t),
                1,
                fp) != 1)
        {
        fclose(fp);
        return false;
    }

    if (fwrite(db->transactions,
                sizeof(Transaction),
                db->size,
                fp) != db->size)
    {
        fclose(fp);
        return false;
    }

    fclose(fp);

    return true;
}