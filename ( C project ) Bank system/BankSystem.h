/*
 * BankSystem.h
 *
 * Created: 01/11/2023 11:11:54 م
 *  Author: EGYPT
 */ 


#ifndef BANKSYSTEM_H_
#define BANKSYSTEM_H_

// function to add new customer and takes the input data as parameters
void addCustomer(struct customers** head, int credit, int salary, int password, char* username, int taxes);

//function to fill the database of the bank system
void fill_Database(struct customers** head);

// function to print the customers list
void printAllCustomers(struct customers* head);

//function to delete the customer from the list by taking his name as an input parameter
void deleteByName(struct customers** head,const char* username);

//function to print all the customer data
void print_one_customer(struct customers* head ,char*username,int pass);



#endif /* BANKSYSTEM_H_ */