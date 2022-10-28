/* This file contains Append, Prepend, Traverse funtions */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

/* Append function */

int append ( stockPortfolio** head, stockPortfolio* newStock )
// Time complexity is O(n)
// Time complexity for reading the list is O(n*(n+1)/2) = O(n^2)
{
	stockPortfolio* iter = *head ;
	if (*head == NULL)
		*head =  newStock ;
	else
	{
		while ( iter -> next != NULL)
		{
			iter = iter -> next ;
		}
		iter -> next = newStock ;
		newStock -> next = NULL ;
	
		// For double linked list
		newStock -> prev= iter;
	}			
	return EXIT_SUCCESS;
}

/* Prepend funtion */

int delete_stock( stockPortfolio** head, stockPortfolio* newStock )
// Time complexity is O(1)
// Time complexity for reading the list is O(n)
{
	stockPortfolio* temp = NULL ;
    if (*head != NULL)
    {
		temp = *head;
		*head = newStock ;
		(*head) -> next = temp;
		// For double Linked List
		temp -> prev = newStock ;
    }
    return EXIT_SUCCESS ;
}


/* Traverse function */

char* getStockBuyOrSell(stockPortfolio* stock){
	printf("%s : ",stock->buyOrSell);
	return (char*)stock->buyOrSell;

}

int getStockPrice(stockPortfolio* stock){
	 //return ((int)stock->price);
	 //printf("Get stock price: %d\n",stock->price);
	return stock->price;
}
void traverse(stockPortfolio* head)
{
	int buy = 0;
	int sell =0;

    stockPortfolio* iter = head ; 
    while (iter != NULL )
    {
        //printStockStruct(iter);
		
		//if(getStockBuyOrSell(iter) == "buy"){
			if (strcmp(getStockBuyOrSell(iter),"buy"))

		{
			buy = buy + getStockPrice(iter);
			printf("%d\n\n",buy);
		}
		else if (strcmp(getStockBuyOrSell(iter),"sell"))
		{
			sell = sell + getStockPrice(iter);
			printf("%d\n",sell);
		}
        iter = iter -> next;
    }
	if((sell-buy) > 0)
	printf("profit");
	else
	printf("loss");
}
