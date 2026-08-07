#include "../include/database.h"
#include "../include/file.h"
#include "../include/report.h"
#include "../include/transaction.h"
#include "../include/utils.h"

int main(void)
{
    FinanceDB db;

    if (!dbInit(&db))
    {
        fprintf(stderr, "Failed to initialize database.\n");
        return EXIT_FAILURE;
    }

    if (!loadDatabase(&db))
    {
        fprintf(stderr, "Warning: Failed to load existing data.\n");
    }

    int choice;

    while (1)
    {
        printMenu();

        if (!readInt("Enter choice: ", &choice))
        {
            printf("Invalid input.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                Transaction t;

                if (inputTransaction(&t) &&
                    addTransaction(&db, &t))
                {
                    printf("Transaction added successfully.\n");
                }
                break;
            }

            case 2:
                viewTransactions(&db);
                break;

            case 3:
            {
                int id;

                if (readInt("Enter Transaction ID: ", &id))
                {
                    deleteTransaction(&db, id);
                }
                break;
            }

            case 4:
            {
                int id;
                Transaction updated;

                if (readInt("Enter Transaction ID: ", &id) &&
                    inputTransaction(&updated))
                {
                    updateTransaction(&db, id, &updated);
                }
                break;
            }

            case 5:
                showIncomeExpenseSummary(&db);
                break;

            case 6:
                showCategoryReport(&db);
                break;

            case 7:
                showMonthlyReport(&db);
                break;

            case 8:
                saveDatabase(&db);
                dbDestroy(&db);
                return EXIT_SUCCESS;

            default:
                printf("Invalid choice.\n");
        }
    }
}