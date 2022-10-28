#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

void printStockStruct(stockPortfolio* stock)
{
    printf("%5d | %41s | %4d | %9d | %7s | %11s |\n", stock->stockId, stock->stockName, stock->qty, stock->price, stock->buyOrSell, stock->date);

}

void printReverseLinkedList(stockPortfolio* head)
{

	log_info ("\nPrinting the linkd list in reverse order !!");
    stockPortfolio* iter = head ;
	stockPortfolio* tail = NULL ;

    while (iter != NULL )
    {
		tail = iter;
        iter = iter -> next;
    }

	iter = tail; 
	while ( iter != NULL )
	{
		printStockStruct(iter);
		iter = iter -> prev ;
	}
	log_info ("Printing in reverse order finished !!\n");
}

void printLinkedList(stockPortfolio* head)
{
    stockPortfolio* iter = head ;
    while (iter != NULL )
    {
        printStockStruct(iter);
        iter = iter -> next;
    }
}

/*int saveToFile(stockPortfolio* head, char* fileName)
{
	FILE* fp = fopen (fileName, "w");
	stockPortfolio* iter = head ;
	int countRecords = 0;

	if ( head == NULL ) //|| *head == NULL )
		return EXIT_FAILURE;

	if ( fp == NULL )
		return EXIT_FAILURE;

	while (iter != NULL)
	{
		fprintf(fp, "%d|%s|%d|%d|%s|%s\n", iter-> stockId, iter -> stockName, iter -> qty, iter -> price, iter -> buyOrSell, iter -> date);
		iter = iter -> next;
		countRecords++ ;
	}

	fclose(fp);

	return countRecords; // Return number of records saved!

}
*/