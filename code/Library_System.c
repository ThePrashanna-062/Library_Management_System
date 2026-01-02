#include <stdio.h>
#include <stdlib.h>
#include <string.h>

   //Structure to store book information

struct Book 
{
    int bookId;
    char bookName[50];
    char authorName[50];
    int quantity;
};

/* Function declarations */
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void clearData();

int main() 
{
    int choice;

    do {
        printf("\n=====================================\n");
        printf("     LIBRARY MANAGEMENT SYSTEM\n");
        printf("=====================================\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Clear All Data\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                clearData();
                break;
            case 7:
                printf("Thank you for using the system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}

   //Function to add new book record

void addBook() 
{
    FILE *fp;
    struct Book b;

    fp = fopen("book.dat", "ab"); // append binary mode
    if (fp == NULL) 
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &b.bookId);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", b.bookName);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.authorName);

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Book added successfully.\n");
}

  // Function to display all book records

void displayBooks() 
{
    FILE *fp;
    struct Book b;

    fp = fopen("book.dat", "rb");
    if (fp == NULL) 
    {
        printf("No data available.\n");
        return;
    }

    printf("\nID\tBook Name\tAuthor\t\tQuantity\n");
    printf("---------------------------------------------\n");

    while (fread(&b, sizeof(b), 1, fp)) 
    {
        printf("%d\t%s\t\t%s\t\t%d\n",
               b.bookId, b.bookName, b.authorName, b.quantity);
    }

    fclose(fp);
}

//Function to search book by ID

void searchBook() 
{
    FILE *fp;
    struct Book b;
    int id, found = 0;

    fp = fopen("book.dat", "rb");
    if (fp == NULL) 
    {
        printf("File not found.\n");
        return;
    }

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) 
    {
        if (b.bookId == id)
        {
            printf("\nBook Found!\n");
            printf("Book Name : %s\n", b.bookName);
            printf("Author    : %s\n", b.authorName);
            printf("Quantity  : %d\n", b.quantity);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book record not found.\n");

    fclose(fp);
}

//Function to issue a book

void issueBook() 
{
    FILE *fp, *temp;
    struct Book b;
    int id, found = 0;

    fp = fopen("book.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL) 
    {
        printf("File error.\n");
        return;
    }

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) 
    {
        if (b.bookId == id && b.quantity > 0) 
        {
            b.quantity--;
            found = 1;
            printf("Book issued successfully.\n");
        }
        fwrite(&b, sizeof(b), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("book.dat");
    rename("temp.dat", "book.dat");

    if (!found)
        printf("Book not available or ID not found.\n");
}

  // Function to return a book

void returnBook() 
{
    FILE *fp, *temp;
    struct Book b;
    int id, found = 0;

    fp = fopen("book.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL) 
    {
        printf("File error.\n");
        return;
    }

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) 
    {
        if (b.bookId == id) 
        {
            b.quantity++;
            found = 1;
            printf("Book returned successfully.\n");
        }
        fwrite(&b, sizeof(b), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("book.dat");
    rename("temp.dat", "book.dat");

    if (!found)
        printf("Book ID not found.\n");
}

//Function to clear all stored data

void clearData() 
{
    FILE *fp;
    char choice;

    printf("Are you sure you want to clear all data? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') 
    {
        fp = fopen("book.dat", "wb");
        fclose(fp);
        printf("All data cleared successfully.\n");
    } else 
    {
        printf("Operation cancelled.\n");
    }
}