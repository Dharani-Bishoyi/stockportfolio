#pragma once

#define STOCK_NAME_LEN 100
#define BUY_OR_SELL_LEN 100
#define DATE_LEN 100


#define LINE_SIZE 600

#define TRUE 1
#define FALSE 0 

typedef struct _stockPortfolio_
{
    int stockId;
    char stockName[STOCK_NAME_LEN];
    int qty;
    int price;
    char buyOrSell[BUY_OR_SELL_LEN];
    char date[DATE_LEN];
    

	struct _stockPortfolio_  *next;
	struct _stockPortfolio_  *prev;
 
} stockPortfolio;

