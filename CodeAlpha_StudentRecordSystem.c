#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    float marks;
};

int main() {
    struct student s;
    FILE *fp;
    int choice, id, found;

    while(1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            fp = fopen("student.txt", "a");

            printf("Enter ID: ");
            scanf("%d", &s.id);

            printf("Enter Name: ");
            scanf("%s", s.name);

            printf("Enter Marks: ");
            scanf("%f", &s.marks);

            fwrite(&s, sizeof(s), 1, fp);
            fclose(fp);

            printf("Student record added successfully!\n");
            break;

        case 2:
            fp = fopen("student.txt", "r");

            printf("\nID\tName\tMarks\n");

            while(fread(&s, sizeof(s), 1, fp)) {
                printf("%d\t%s\t%.2f\n", s.id, s.name, s.marks);
            }

            fclose(fp);
            break;

        case 3:
            printf("Enter ID to search: ");
            scanf("%d", &id);

            fp = fopen("student.txt", "r");
            found = 0;

            while(fread(&s, sizeof(s), 1, fp)) {
                if(s.id == id) {
                    printf("Student Found\n");
                    printf("ID: %d\nName: %s\nMarks: %.2f\n", s.id, s.name, s.marks);
                    found = 1;
                }
            }

            if(!found)
                printf("Student not found!");

            fclose(fp);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!");
        }
    }

    return 0;
}
