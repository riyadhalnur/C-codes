/*
    Name: Student Management
    Author: Riyadh Al Nur
    ID: 10-16100-1 (EEE)
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
const char DATA_FILE[] = "records.dat"; // file containing student information

void append(); // function prototype
void list(); // function prototype
void search(); // function prototype
void modify(); // function prototype
void del(); // function prototype
FILE *fp;

/*****************************
* Student Database structure
******************************/
struct student{
	int ID;
	char name[30];
	char Dept[5];
	float CGPA;
} record;

/*****************************************************
* Function: main()
******************************************************/
int main()
{
    int a;
    char ch;

    printf("STUDENT MANAGEMENT 1.0\n");
    do {
        printf("\nOptions Menu\n");
        printf("1. Append Student Information\n");
        printf("2. List Student Information\n");
        printf("3. Modify Student Information\n");
        printf("4. Delete Student Information\n");
        printf("5. Search Student Information\n");
        printf("Enter choice: ");
        scanf("%d", &a);

        switch(a) {
            case 1:
            append();
            break;
            case 2:
            list();
            break;
            case 3:
            modify();
            break;
            case 4:
            del();
            break;
            case 5:
            search();
            break;
            default:
            printf("Invalid choice");
        }
        printf("More actions? (Y/N): ");
        fflush(stdin);
        scanf("%c", &ch);
    } while(ch == 'y' || ch == 'Y');

    return 0;
}

/********************************************************************************
* FUNCTION: append()
* USAGE: displays the admin area where a user can write and append student info
********************************************************************************/
void append()
{
    int i, n;

    fp = fopen(DATA_FILE, "a");

    if(fp == NULL) {
        printf("Error - File creation failed!");
    }
    printf("Enter the number of records to enter: ");
    scanf("%d", &n);

    for(i=0; i < n; i++) {
        printf("Enter name: ");
        fflush(stdin);
        gets(record.name);
        printf("Enter Department: ");
        fflush(stdin);
        gets(record.Dept);
        printf("Enter ID: ");
        scanf("%d", &record.ID);
        printf("Enter CGPA: ");
        scanf("%f", &record.CGPA);
        printf("\n\n");

        fwrite((char *)&record, sizeof(record), 1, fp);
    }

    fclose(fp);
}

/********************************************************************************
* FUNCTION: list()
* USAGE: lists student info from file
********************************************************************************/
void list()
{
    int nofrec = 0;

    fp = fopen(DATA_FILE, "r");

    if(fp == NULL) {
        printf("Error - File reading failed!");
    }

    while((fread((char *)&record, sizeof(record), 1, fp)) == 1)
    {
        nofrec++;
        printf("\nName: %s", record.name);
        printf("\nDepartment: %s", record.Dept);
        printf("\nID: %d", record.ID);
        printf("\nCGPA: %.2f", record.CGPA);
        printf("\n\n");
    }
    printf("Total records: %d\n", nofrec);

    fclose(fp);
}

/********************************************************************************
* FUNCTION: modify()
* USAGE: modifies student info from file
********************************************************************************/
void modify()
{
    int recno, nofrec = 0;
    char ch;

    fp = fopen(DATA_FILE, "r+");

    printf("Enter Student ID to be modified: ");
    scanf("%d", &recno);

    while((fread((char *)&record, sizeof(record), 1, fp)) == 1)
    {
        nofrec++;

        if(record.ID == recno) {
            printf("\nName: %s", record.name);
            printf("\nDepartment: %s", record.Dept);
            printf("\nID: %d", record.ID);
            printf("\nCGPA: %.2f", record.CGPA);
            printf("\n");

            printf("Do you want to modify this data? (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);

            fseek(fp, ((nofrec-1)*sizeof(record)), 0);
            if(ch == 'y' || ch == 'Y') {
                printf("Enter name: ");
                fflush(stdin);
                gets(record.name);
                printf("Enter Department: ");
                fflush(stdin);
                gets(record.Dept);
                printf("Enter ID: ");
                scanf("%d", &record.ID);
                printf("Enter CGPA: ");
                scanf("%f", &record.CGPA);

                fwrite((char *)&record, sizeof(record), 1, fp);
                printf("Record Modified!\n");
            } else {
                printf("No records were modified\n");
            }

            fclose(fp);
        }
    }
}

/********************************************************************************
* FUNCTION: del()
* USAGE: deletes student info from file
********************************************************************************/
void del()
{
    int recno;
    char ch;
    FILE *ft;

    fp = fopen(DATA_FILE, "r+");
    ft = fopen("temp.dat", "w+");

    printf("Enter the student ID to delete: ");
    scanf("%d", &recno);

    while((fread((char *)&record, sizeof(record), 1, fp)) == 1)
    {
        if(record.ID == recno)
        {
            printf("\nName: %s", record.name);
            printf("\nDepartment: %s", record.Dept);
            printf("\nID: %d", record.ID);
            printf("\nCGPA: %.2f", record.CGPA);
            printf("\n");

            printf("Do you want to delete this record? (Y/N): ");
            fflush(stdin);
            scanf("%c", &ch);
        }
    }

    if(ch == 'y' || ch == 'Y')
    {
        rewind(fp);
        while((fread((char *)&record, sizeof(record), 1, fp)) == 1)
        {
            if(recno != record.ID) {
                fwrite((char *)&record, sizeof(record), 1, ft);
            }
        }
    }
    else {
        printf("No records were deleted\n");
    }

    fclose(fp);
    fclose(ft);
    remove(DATA_FILE);
    rename("temp.dat", DATA_FILE);
}

/********************************************************************************
* FUNCTION: search()
* USAGE: searches student info from file
********************************************************************************/
void search()
{
    int s, recno;
    char sname[30];

    fp = fopen(DATA_FILE, "r");

    printf("\n1. Search by Name\n2. Search by ID\n3. Search by CGPA\nEnter choice: ");
    scanf("%d", &s);

    switch(s) {
        case 1:
        printf("Enter name to search: ");
        fflush(stdin);
        gets(sname);
        while((fread((char *)&record, sizeof(record), 1, fp)) == 1)
        {
            if(strcmp(sname,record.name) == 0) {
                printf("\nName: %s", record.name);
                printf("\nDepartment: %s", record.Dept);
                printf("\nID: %d", record.ID);
                printf("\nCGPA: %.2f", record.CGPA);
                printf("\n");
            }
        }
        break;
        case 2:
        printf("Enter ID to search: ");
        scanf("%d", &recno);
        while((fread((char *)&record, sizeof(record), 1, fp)) == 1)
        {
            if(record.ID == recno) {
                printf("\nName: %s", record.name);
                printf("\nDepartment: %s", record.Dept);
                printf("\nID: %d", record.ID);
                printf("\nCGPA: %.2f", record.CGPA);
                printf("\n");
            }
        }
        break;
        case 3:
        printf("Enter CGPA to search: ");
        scanf("%d", &recno);
        while((fread((char *)&record, sizeof(record), 1, fp)) == 1)
        {
            if(record.CGPA == recno && record.CGPA > 3) {
                printf("\nName: %s", record.name);
                printf("\nDepartment: %s", record.Dept);
                printf("\nID: %d", record.ID);
                printf("\nCGPA: %.2f", record.CGPA);
                printf("\n");
            }
        }
    }
}











