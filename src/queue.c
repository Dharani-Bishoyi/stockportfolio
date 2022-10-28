#include <stdio.h>
#include <main.h>
#include <string.h>
#include <stdlib.h>

/*
 isEmpty
 isFull
 enqueue
 dequeue
 peek

Auxillary functions
 createQueue    
 deleteQueue
 printQueue
*/

int createQueueFromFile(stockPortfolio** head, char* fileName)
{
	return readStockPortfolioCSV(head, fileName);
}

stockPortfolio* peek(stockPortfolio** head)
{
	return *head;

}

int enqueue ( stockPortfolio** head, stockPortfolio* queue)
{
	return append ( head, queue);
}

stockPortfolio* dequeue ( stockPortfolio** head)
{
    stockPortfolio* iter = *head;
	*head = iter -> next;
	(*head) -> prev = NULL ;
	return iter ;
}

int isFull(stockPortfolio** head)
{
	return FALSE;
}

int isEmpty (stockPortfolio** head )
{
	if (head != NULL && *head == NULL)
		return TRUE;
	else
		return FALSE;
}

int printQueue(stockPortfolio* head)
{
	printLinkedList(head);
	return EXIT_SUCCESS;
}
