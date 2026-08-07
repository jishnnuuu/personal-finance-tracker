#include <../include/report.h>

void showIncomeExpenseSummary(const FinanceDB *db)
{
    if (db == NULL)
        return;

    float income = 0.0f;
    float expense = 0.0f;

    for (size_t i = 0; i < db->size; i++)
    {
        const Transaction *t = &db->transactions[i];

        if (strcmp(t->type, "Income") == 0)
            income += t->amount;
        else
            expense += t->amount;
    }

    printf("\n========== SUMMARY ==========\n");
    printf("Income  : %.2f\n", income);
    printf("Expense : %.2f\n", expense);
    printf("Savings : %.2f\n", income - expense);
}

void showCategoryReport(const FinanceDB *db)
{
    float food = 0;
    float travel = 0;
    float shopping = 0;
    float bills = 0;
    float salary = 0;
    float others = 0;

    for(size_t i = 0; i < db->size; i++)
    {
        const Transaction *t = &db->transactions[i];

        if(strcmp(t->category,"Food")==0)
            food += t->amount;

        else if(strcmp(t->category,"Travel")==0)
            travel += t->amount;

        else if(strcmp(t->category,"Shopping")==0)
            shopping += t->amount;

        else if(strcmp(t->category,"Bills")==0)
            bills += t->amount;

        else if(strcmp(t->category,"Salary")==0)
            salary += t->amount;

        else
            others += t->amount;
    }

    printf("\n====== CATEGORY REPORT ======\n");

    printf("Food      : %.2f\n", food);
    printf("Travel    : %.2f\n", travel);
    printf("Shopping  : %.2f\n", shopping);
    printf("Bills     : %.2f\n", bills);
    printf("Salary    : %.2f\n", salary);
    printf("Others    : %.2f\n", others);
}

void showMonthlyReport(const FinanceDB *db)
{
    char month[3];

    printf("Enter Month (MM): ");

    scanf("%2s", month);

    float income = 0;
    float expense = 0;

    for(size_t i = 0; i < db->size; i++)
    {
        const Transaction *t = &db->transactions[i];

        if(strncmp(t->date + 5, month, 2) == 0)
        {
            if(strcmp(t->type,"Income")==0)
                income += t->amount;
            else
                expense += t->amount;
        }
    }

    printf("\n===== MONTHLY REPORT =====\n");

    printf("Income : %.2f\n", income);
    printf("Expense: %.2f\n", expense);

    printf("Savings: %.2f\n",
            income-expense);
}