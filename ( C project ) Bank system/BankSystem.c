#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BankSystem.h"

// declaration of the node structure which contains the customer's data
struct customers{
int S_credit;
int S_salary;
int S_password;
char S_username[100];
int S_taxes;
struct customers *next;

};

//initializing admin name and password  
char admin_username[100]={"Abdo"};
int admin_password=1234;


struct customers* head = NULL;


int main()
{ 
    int d;
    int flag =1;
    int choice;
    int C_pass;
    int C_salary,C_Credit,C_Taxes,C_psw;
    char C_name [100];
    int a_options;
    char a_username[100];
    int a_password,check_name;


    fill_Database(&head);


    while (flag) {

    printf("\n[1]ADMIN\n[2]Customer\n");
    printf("Please Enter your Identity: ");
    scanf("%d",&choice);


    if(choice == 1){

        printf("\nEnter Your Name: ");
        scanf("%s",&a_username);
        printf("\nEnter Your Password : ");
        scanf("%d",&a_password);
        
        //checking if the entered admin name and password are correct
        check_name = strcmp(admin_username,a_username);

        if( ( check_name == 0) && (a_password == admin_password)){

            printf("\n[1]Add Customer\n[2]Delete Customer\n[3]Show all Customers\nChoice:");
            scanf("%d",&a_options);
        // switch case for the provided options for the admin : add new customer or delete or show the list
            switch(a_options){

                case 1:
                    printf("Please customer's name: ");
                    scanf("%s",&C_name);
                    printf("\n Please customer's password: ");
                    scanf("%d",&C_psw);
                    printf("\n Please customer's credit number: ");
                    scanf("%d",&C_Credit);
                    printf("\n Please customer's salary: ");
                    scanf("%d",&C_salary);
                    printf("\n Please customer's Taxes: ");
                    scanf("%d",&C_Taxes);
                    addCustomer(&head, C_Credit, C_salary, C_psw, C_name, C_Taxes);
                    printf("\n The new list after adding new customer \n ");
                    printAllCustomers(head);

                    break;

               case 2:

                    printf("Please customer's name you want to delete: ");
                    scanf("%s", &C_name);
                    deleteByName(&head, C_name);
                    printf("\n The new list after deleting the customer \n ");
                    printAllCustomers(head);
                    break;

               case 3:
                    printAllCustomers(head);
                    break;

               default:
                    break;


        }
    }
        else {
            printf("\n  Wrong password or username \n");
        }
   }
        if (choice == 2){
            printf("\n  You are in customer mode: \n ");
            printf("Please enter your name: \n ");
            scanf("%s", &C_name);
            printf("Please the password: \n ");
            scanf ("%d",&C_pass);
            print_one_customer(head, C_name,C_pass);

            printf("\n Do you want another service ?: \n 1> Yes \n 2> No \n : ");
            scanf("%d",&d);

            if (d==1){
                flag=1;
                }
            else{
                flag=0;
            }
            printf("\n Do you want another service ?: \n 1> Yes \n 2> No \n : ");
            scanf("%d",&d);

            if (d==1){
                flag=1;
                }
            else{
                flag=0;
            }
    }
        }
    return 0;
    }


void addCustomer(struct customers** head,int credit, int salary, int password, char* username, int taxes) {
    struct customers* newNode = (struct customers*)malloc(sizeof(struct customers));
    newNode->S_credit =credit;
    newNode->S_salary = salary;
    newNode->S_password = password;
    strcpy(newNode->S_username, username);
    newNode->S_taxes = taxes;
    newNode->next = *head;
    *head = newNode;

}



void fill_Database(struct customers** head){
    addCustomer(head,5600,  3000, 1222,"Ahmed", 800);
    addCustomer(head,5697,  2500, 1222,"May", 500);
    addCustomer(head,5696,  6000, 1222,"Aliaa", 1000);

}

void printAllCustomers(struct customers* head) {
    struct customers* current = (struct customers*)malloc(sizeof(struct customers));
    current= head;
    printf("\n The list of the customers : \n");
    while (current != NULL) {
        printf("\n customer's name : %s ,", current->S_username);
        printf(" credit :%d ,",current->S_credit);
        printf("Salary : %d ,",current->S_salary);
        printf("taxes : %d \n",current->S_taxes );
        current = current->next;
        printf("\n");
    }
}

void print_one_customer(struct customers* head ,char*username,int pass) {
    struct customers* current = (struct customers*)malloc(sizeof(struct customers));
    current= head;
    while (current != NULL) {
        if ((strcmp(current->S_username, username) == 0) && (current->S_password == pass)){
            printf(" Here is your data : \n");
            printf("\n customer's name : %s \n", current->S_username);
            printf("credit : %d \n",current->S_credit);
            printf("salary : %d \n",current->S_salary);
            printf("taxes : %d \n",current->S_taxes );
            return;
        }
        else{
            current = current->next;
        }
    }
        printf(" \n wrong username or password  \n");
}


void deleteByName(struct customers** head, const char* username) {
    struct customers* temp = *head;
    struct customers* prev = NULL;

    // If the list is empty, return
    if (*head == NULL) {
        return;
    }

    // Check if the head node needs to be deleted
    if (temp != NULL && strcmp(temp->S_username, username) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Find the node to be deleted and keep track of the previous node
    while (temp != NULL && strcmp(temp->S_username, username) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If the name was not found in the list, return
    if (temp == NULL) {
        printf("Node with name '%s' not found in the list.\n", username);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;

    // Free the memory allocated for the node
    free(temp);
}
