#ifndef REPORT_H
#define REPORT_H

#include "database.h"

void showIncomeExpenseSummary(const FinanceDB *db);

void showCategoryReport(const FinanceDB *db);

void showMonthlyReport(const FinanceDB *db);

#endif
