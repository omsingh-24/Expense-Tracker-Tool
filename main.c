#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense
{
    int id;
    char category[30];
    float amount;
    char date[15];
};

void addExpense();
void viewExpenses();
void searchCategory();
void totalExpenses();
void highestExpense();
void updateExpense();
void deleteExpense();
void categorySummary();
void analytics();

int main()
{
    int choice;

    while(1)
    {
        printf("\n====================================\n");
        printf("         EXPENSE TRACKER\n");
        printf("====================================\n");

        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Search By Category\n");
        printf("4. Show Total Expenses\n");
        printf("5. Show Highest Expense\n");
        printf("6. Update Expense\n");
        printf("7. Delete Expense\n");
        printf("8. Category Summary\n");
        printf("9. Analytics Dashboard\n");
        printf("10. Exit\n");

        printf("\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                searchCategory();
                break;

            case 4:
                totalExpenses();
                break;

            case 5:
                highestExpense();
                break;

            case 6:
                updateExpense();
                break;

            case 7:
                deleteExpense();
                break;

            case 8:
                categorySummary();
                break;

            case 9:
                analytics();
                break;

            case 10:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

void addExpense()
{
    FILE *fp;
    struct Expense e;

    fp = fopen("expenses.dat","ab");

    if(fp == NULL)
    {
        printf("File Error!\n");
        return;
    }

    printf("Expense ID: ");
    scanf("%d",&e.id);

    printf("Category: ");
    scanf(" %[^\n]",e.category);

    printf("Amount: ");
    scanf("%f",&e.amount);

    printf("Date (DD-MM-YYYY): ");
    scanf("%s",e.date);

    fwrite(&e,sizeof(struct Expense),1,fp);

    fclose(fp);

    printf("Expense Added Successfully!\n");
}

void viewExpenses()
{
    FILE *fp;
    struct Expense e;

    fp = fopen("expenses.dat","rb");

    if(fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\n---------------------------------------------------------\n");
    printf("ID\tCATEGORY\t\tAMOUNT\t\tDATE\n");
    printf("---------------------------------------------------------\n");

    while(fread(&e,sizeof(struct Expense),1,fp))
    {
        printf("%d\t%-15s\t%.2f\t\t%s\n",
               e.id,
               e.category,
               e.amount,
               e.date);
    }

    fclose(fp);
}

void searchCategory()
{
    FILE *fp;
    struct Expense e;

    char category[30];
    int found = 0;

    printf("Enter Category: ");
    scanf(" %[^\n]",category);

    fp = fopen("expenses.dat","rb");

    if(fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    while(fread(&e,sizeof(struct Expense),1,fp))
    {
        if(strcmp(e.category,category)==0)
        {
            printf("\nID       : %d\n",e.id);
            printf("Category : %s\n",e.category);
            printf("Amount   : %.2f\n",e.amount);
            printf("Date     : %s\n",e.date);

            found = 1;
        }
    }

    if(found==0)
    {
        printf("No Matching Records Found!\n");
    }

    fclose(fp);
}

void totalExpenses()
{
    FILE *fp;
    struct Expense e;

    float total = 0;

    fp = fopen("expenses.dat","rb");

    if(fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    while(fread(&e,sizeof(struct Expense),1,fp))
    {
        total += e.amount;
    }

    printf("\nTotal Expenses = %.2f\n",total);

    fclose(fp);
}

void highestExpense()
{
    FILE *fp;
    struct Expense e;
    struct Expense highest;

    int first = 1;

    fp = fopen("expenses.dat","rb");

    if(fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    while(fread(&e,sizeof(struct Expense),1,fp))
    {
        if(first)
        {
            highest = e;
            first = 0;
        }

        if(e.amount > highest.amount)
        {
            highest = e;
        }
    }

    printf("\n===== HIGHEST EXPENSE =====\n");

    printf("ID       : %d\n",highest.id);
    printf("Category : %s\n",highest.category);
    printf("Amount   : %.2f\n",highest.amount);
    printf("Date     : %s\n",highest.date);

    fclose(fp);
}

void updateExpense()
{
    FILE *fp,*temp;

    struct Expense e;

    int id;
    int found = 0;

    printf("Enter Expense ID To Update: ");
    scanf("%d",&id);

    fp = fopen("expenses.dat","rb");

    if(fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    temp = fopen("temp.dat","wb");

    while(fread(&e,sizeof(struct Expense),1,fp))
    {
        if(e.id == id)
        {
            found = 1;

            printf("New Category: ");
            scanf(" %[^\n]",e.category);

            printf("New Amount: ");
            scanf("%f",&e.amount);

            printf("New Date: ");
            scanf("%s",e.date);
        }

        fwrite(&e,sizeof(struct Expense),1,temp);
    }

    fclose(fp);
    fclose(temp);

    remove("expenses.dat");
    rename("temp.dat","expenses.dat");

    if(found)
        printf("Expense Updated Successfully!\n");
    else
        printf("Expense Not Found!\n");
}

void deleteExpense()
{
    FILE *fp,*temp;

    struct Expense e;

    int id;
    int found = 0;

    printf("Enter Expense ID To Delete: ");
    scanf("%d",&id);

    fp = fopen("expenses.dat","rb");

    if(fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    temp = fopen("temp.dat","wb");

    while(fread(&e,sizeof(struct Expense),1,fp))
    {
        if(e.id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&e,sizeof(struct Expense),1,temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("expenses.dat");
    rename("temp.dat","expenses.dat");

    if(found)
        printf("Expense Deleted Successfully!\n");
    else
        printf("Expense Not Found!\n");
}

void categorySummary()
{
    FILE *fp;
    struct Expense e;

    float food=0;
    float travel=0;
    float shopping=0;
    float education=0;
    float other=0;

    fp = fopen("expenses.dat","rb");

    if(fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    while(fread(&e,sizeof(struct Expense),1,fp))
    {
        if(strcmp(e.category,"Food")==0)
            food += e.amount;

        else if(strcmp(e.category,"Travel")==0)
            travel += e.amount;

        else if(strcmp(e.category,"Shopping")==0)
            shopping += e.amount;

        else if(strcmp(e.category,"Education")==0)
            education += e.amount;

        else
            other += e.amount;
    }

    printf("\n===== CATEGORY SUMMARY =====\n");

    printf("Food      : %.2f\n",food);
    printf("Travel    : %.2f\n",travel);
    printf("Shopping  : %.2f\n",shopping);
    printf("Education : %.2f\n",education);
    printf("Other     : %.2f\n",other);

    fclose(fp);
}

void analytics()
{
    FILE *fp;
    struct Expense e;
    struct Expense highest;

    float total = 0;
    float average = 0;

    int count = 0;
    int first = 1;

    fp = fopen("expenses.dat","rb");

    if(fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    while(fread(&e,sizeof(struct Expense),1,fp))
    {
        total += e.amount;
        count++;

        if(first)
        {
            highest = e;
            first = 0;
        }

        if(e.amount > highest.amount)
        {
            highest = e;
        }
    }

    if(count > 0)
        average = total / count;

    printf("\n=================================\n");
    printf("      ANALYTICS DASHBOARD\n");
    printf("=================================\n");

    printf("Total Expenses          : %.2f\n",total);
    printf("Number of Transactions  : %d\n",count);
    printf("Average Expense         : %.2f\n",average);
    printf("Highest Expense Category: %s\n",
           highest.category);
    printf("Highest Expense Amount  : %.2f\n",
           highest.amount);

    fclose(fp);
}
