#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

int freeLinkedList(stockPortfolio** head)
/***************************************************************************************
 This functicon takes the link list head, iterates through it and frees each structure.
 **************************************************************************************/
{
    stockPortfolio *iter =  *head;
    stockPortfolio *temp = NULL ;
    int freeCount = 0;

    while (iter != NULL )
    {

        temp = iter ;
        iter = iter ->next ;
        free ( temp);
        freeCount++;
    }
    *head = NULL ;
    return freeCount;
}

static stockPortfolio* constructsStockStruct(char* line)
{

    log_trace("Entering function %s", __func__);
    char* token ;
    const char* seperator = "|";

    stockPortfolio *stockRet = (stockPortfolio*)malloc (sizeof(stockPortfolio));
	memset ( stockRet, 0, sizeof (stockPortfolio));

    if ( line == NULL)
        return NULL ;
   token = strtok (line, seperator);
    if ( token != NULL )
    {
        log_info("Stock Id is %s", token);
        stockRet->stockId = atoi(token);
    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("Stock Name is %s", token);
        strncpy (stockRet->stockName, token, STOCK_NAME_LEN-1);

    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
	
        log_info("Stock Quantity is %s", token);
        stockRet->qty = atoi(token);

    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
	
        log_info("Stock Price is %s", token);
        stockRet->price = atoi(token);

    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("Stock was Buy or Sell is %s", token);
        strncpy (stockRet->buyOrSell, token, BUY_OR_SELL_LEN-1);

    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("Stock Day is %s", token);
        strncpy (stockRet->date, token, DATE_LEN-1);

    }

    return stockRet ;
}


int readStockPortfolioCSV (stockPortfolio** head, char* fileName )
{
    stockPortfolio *newStock = NULL ;
    char stockLine[LINE_SIZE]; // Temp buffer for reading the line
	int count = 0;

    FILE* stockFile = fopen (fileName, "r");
    if (stockFile == NULL )
    {
            printf ("Could not open the file for reading\n");
            return EXIT_FAILURE;
    }

    while (1)
    {
        if (fgets(stockLine, LINE_SIZE, stockFile) == NULL)
            break ;
        newStock =  (stockPortfolio*)constructsStockStruct(stockLine);
        append(head, newStock); 
		count++;
    }

    fclose(stockFile);
    return  count ;
}


