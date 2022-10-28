#ifndef __MAIN_H__
#define __MAIN_H__
#include <struct.h>

//Queue implementation
//extern void display(stockPortfolio** head, char* fileName);
extern stockPortfolio* peek(stockPortfolio** head);
extern void menu(stockPortfolio** head);
extern int enqueue ( stockPortfolio** head, stockPortfolio* queue);
extern stockPortfolio* dequeue (stockPortfolio** head);
extern int isFull(stockPortfolio** head);
extern int printQueue(stockPortfolio* head);
extern int isEmpty (stockPortfolio** head );
extern int createQueueFromFile(stockPortfolio** head, char* fileName);

// Forward declarations of the functions
extern int readStockPortfolioCSV (stockPortfolio** head, char* fileName);
extern int delete_stock( stockPortfolio** head, stockPortfolio* newStock );
extern int append ( stockPortfolio** head, stockPortfolio* newStock );
extern void traverse(stockPortfolio* head);
extern int freeLinkedList(stockPortfolio** head);
extern void printStockStruct(stockPortfolio* stock);
extern void printReverseLinkedList(stockPortfolio* head);
extern void printLinkedList(stockPortfolio *head);
extern int saveToFile(stockPortfolio*, char* );
//To Do:


#endif
