#ifndef FILE_H
#define FILE_H

#include "database.h"

bool saveDatabase(const FinanceDB *db);

bool loadDatabase(FinanceDB *db);

#endif
