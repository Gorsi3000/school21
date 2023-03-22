#include <stdio.h>

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
                " 0. Close the program\n\n");
        if (scanf("%d", &mode) == 1 && mode > -1 && mode < 10) {
            switch (mode) {
                case 1:
                    printf("\n[placeholder] select\n");
                    break;
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
            }
        } else {
            printf("No such operation in the menu! Try again.\n");
        }
    } while (mode != 0);
    printf("\nThanks for using s21 DB! Program termination.\n\n");
}