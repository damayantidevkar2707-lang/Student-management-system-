#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int roll;
    char name[30];
    float marks;
};

void addStudent()
{
    FILE *fp;
    struct student s;

    fp = fopen("student.txt", "a");

    printf("\nEnter Roll: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);
    printf("\nStudent Record Saved Successfully\n");
}

void viewStudent()
{
    FILE *fp;
    struct student s;

    fp = fopen("student.txt", "r");

    printf("\n--- Student Records ---\n");

    while (fread(&s, sizeof(s), 1, fp))
    {
        printf("Roll: %d Name: %s Marks: %.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent()
{
    FILE *fp;
    struct student s;
    int r, found = 0;

    printf("\nEnter Roll to Search: ");
    scanf("%d", &r);

    fp = fopen("student.txt", "r");

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == r)
        {
            printf("Record Found\n");
            printf("Roll: %d Name: %s Marks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
        }
    }

    if (!found)
        printf("Record Not Found\n");

    fclose(fp);
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n1.Add Student\n2.View Student\n3.Search Student\n4.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addStudent();
            break;

        case 2:
            viewStudent();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice");
        }
    }
}
