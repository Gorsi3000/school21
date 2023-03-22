#include <stdio.h>
#include <stdlib.h>

#include "master_levels.h"
#include "master_modules.h"
#include "master_status_events.h"
#include "shared.h"

int main() {
    int mode;
    do {
        printf(
            "\nWelcome to s21 DB!\n\nChoose which operation you would like to perform:\n"
            " 1. SELECT\n"
            " 2. INSERT\n"
            " 3. UPDATE\n"
            " 4. DELETE\n"
            " 5. Get all active additional modules (last module status is 1)\n"
            " 6. Delete modules by ids\n"
            " 7. Set protected mode for module by id\n"
            " 8. Move module by id to specified memory level and cell\n"
            " 9. Set protection flag of the specified memory level\n"
            " 10. [DEVELOPMENT] Display all tables at once\n"
            " 0. Close the program\n\n");
        if (scanf("%d", &mode) == 1 && mode > -1 && mode < 11) {
            switch (mode) {
                case 1: {
                    printf(
                        "\nChoose table:\n"
                        " 1. Modules\n"
                        " 2. Levels\n"
                        " 3. Status events\n\n");
                    int table = 1;
                    if (scanf("%d", &table) == 1 && table > 0 && table < 4) {
                        printf("\nEnter amount of rows to display or put -1 to output all of them:\n\n");
                        int amount = -1;
                        if (scanf("%d", &amount) == 1 && amount > -1) {
                            if (table == 2) {
                                for (int i = 1; i < amount + 1; i++) {
                                    select(table, i);
                                }
                            } else {
                                for (int i = 0; i < amount; i++) {
                                    select(table, i);
                                }
                            }
                        } else if (amount == -1) {
                            select(table, amount);
                        } else {
                            printf("\nNo such row in the table!\n");
                        }
                    } else {
                        printf("\nNo such table!\n");
                    }
                    break;
                }
                case 2:
                    printf("\n[placeholder] insert\n");
                    break;
                case 3:
                    printf("\n[placeholder] update\n");
                    break;
                case 4:
                    printf("\n[placeholder] delete\n");
                    break;
                case 5:
                    printf("\n[placeholder] get modules\n");
                    break;
                case 6:
                    printf("\n[placeholder] delete modules\n");
                    break;
                case 7:
                    printf("\n[placeholder] set protected modules\n");
                    break;
                case 8:
                    printf("\n[placeholder] move modules\n");
                    break;
                case 9:
                    printf("\n[placeholder] set flags\n");
                    break;
                case 10:
                    printf("\nTHIS IS DEVELOPMENTAL FEATURE\n\n");
                    printf("\nModules\n");
                    FILE *fptr;
                    fptr = fopen("../materials/master_modules.db", "r+b");
                    int fields_count = count_modules(fptr);
                    print_modules(fptr, fields_count);
                    fclose(fptr);
                    printf("\nLevels\n");
                    fptr = fopen("../materials/master_levels.db", "r+b");
                    fields_count = count_levels(fptr);
                    print_levels(fptr, fields_count);
                    fclose(fptr);
                    printf("\nStatus events\n");
                    fptr = fopen("../materials/master_status_events.db", "r+b");
                    fields_count = count_events(fptr);
                    print_events(fptr, fields_count);
                    fclose(fptr);
                    break;
            }
        } else {
            printf("\nNo such operation in the menu! Try again.\n");
        }
    } while (mode != 0);
    printf("\nThanks for using s21 DB! Program termination.\n\n");
}