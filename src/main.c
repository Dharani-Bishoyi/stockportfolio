/* this is a main funtion and contains menu function */
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>





int main(int argc, char** argv)
{
       
	stockPortfolio **head = NULL ;
	int count = 0;
	head = (stockPortfolio**)malloc (sizeof(stockPortfolio*));
	*head = NULL ;

	count = createQueueFromFile(head, "../data/stocks.csv") ;
	if( *head  == NULL || count == 0)
        {
        printf("Could not read the stocks file.\n");
        }
	else
		printf ("%d records read from the csv file\n", count);


 	int Menu;
 	printf("\n\nEnter a Menu Option: ");
 	scanf("%d", &Menu);
 	if( Menu != 1) 
	{
  		printf("Invalid Entry!");
 	} 
	else 
	{
  	menu(head);
	//printf("Your Menu Option is: %d\n", menu);
 	}

	
}

/* Menu function */

void menu(stockPortfolio** head)
{
        int choice ;
        int v;
        do{
                printf("\n*************************************************************************");
                printf("\n-----------------------Welcome To Stock Portfolio------------------------");
                printf("\n*************************************************************************");
                printf("\nMenu:");
                printf("\n1.Display the Stock Portfolio");
                printf("\n2.Insert Stock in the Portfolio");
		printf("\n3.Remove Stock in the Portfolio");
		printf("\n4.View Profit or Loss");
                printf("\n\nEnter Your Choice : ");
                scanf("%d", &choice);
                switch(choice)
                {
				   /* Display */

                        case 1:
                                printQueue(*head);
                            

                                break;
		       
                        case 2:
			       
                                   
					
					 stockPortfolio s;
								
								
							    
								printf("Enter the StockId :");
							    scanf("%d",&s.stockId);
                                printf("Enter the StockName : ");
                                scanf("%s",s.stockName);
                                printf("Enter the Quantity : ");
                                scanf("%d",&s.qty);
                                printf("Enter the Price : ");
                                scanf("%d",&s.price);
                                printf("Enter the buy or sell : ");
                                scanf("%s",s.buyOrSell);
                                printf("Enter date : ");
                                scanf("%s",s.date);




                                stockPortfolio* newStock = (stockPortfolio*)calloc(1, sizeof(stockPortfolio));
                                newStock -> stockId = s.stockId;
                                strcpy (newStock -> stockName, s.stockName);
                                newStock -> qty = s.qty;
                                newStock -> price = s.price;
                                strcpy (newStock -> buyOrSell, s.buyOrSell);
                                strcpy (newStock -> date , s.date);
			
                                append(head,newStock);

                                
				printf("Stock ID :%d \n Stock Name : %s \n Stock Quantity : %d \n Stock Price : %d \n Action : %s \n Date : %s \n",s.stockId,s.stockName,s.qty,s.price,s.buyOrSell,s.date);

                              
                                break; 
                        case 3:
							
								
										
                                 		int sid, found =0;
									printf("Enter stock Id to delete: ");
									scanf("%d",&sid);
									
									newStock = *head;
									if(newStock -> stockId == sid);
									*head = newStock -> next;
									free(newStock);
									found =1;
									
									while(newStock -> next!=NULL)
									
									{
									 stockPortfolio *tmp = newStock -> next;
									 if(tmp -> stockId == sid)

									{
										newStock ->next = tmp ->next;
										free(tmp);
										found = 1;
										break;	
									
									}
										newStock = newStock -> next;
									
									} 
									if(found)
									{
										printf("The Deleted value was deleted successfully\n\n");
									}									
									else
									{
										printf("Record not found\n");
									}
									
									
									//prepend(head, newStock);
                                    
									 //printQueue(*head);
   
                               break;
			case 4:
				 
						int  b, S, r; 
                                    printf("Enter Buy Price: ");
                                     scanf("%d", &b);
                                     printf("Enter Sell Price: ");
                                     scanf("%d", &S);

                                     if(b > S)
                                     {
                                      r = b - S;
                                      printf("loss = %d\n", r);
                                     }
                                     else if(S > b)
                                     {
                                      r = S - b;
                                      printf("Profit = %d\n", r);
                                     }
                                     else
                                     {
                                      printf("No Profit No Loss.");
                                     }
			      				
							      
			             break;
                        default:
                                printf("\nWrong Input");
				break;
                }
				 printf("Do you want to continue (press q to quit):-");
                scanf("%c",&v);
                v=fgetc(stdin);

        }
        while(v!='q');
}

















	
