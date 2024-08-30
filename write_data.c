#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int accno, pin; char name[30]; float balance;
} customer;

main()
{

	int entry = 0;
	FILE *fw, *fr;
	customer c, lastacc;
	char enter;
	fw = fopen("CUSTOME.DAT","a+");
	fr = fopen("CUSTOME.DAT","rb");
	if(fw == NULL)
	{
		printf("File Error");
		exit(1);
	}
	
	printf("\n Press 0 if there is data in the file of customers else press 1 : ");
	scanf("%d",&entry);
	if(entry == 1)
	{
		printf("\nEnter Custemor Ac. number : ");
		scanf("%d",&c.accno);
	}
	
	do
	{
		
		fflush(stdin);
		do
		{
			printf("\nEnter Custemor Name : ");
			gets(c.name);
		}while(strlen(c.name) < 2);
		
		do
		{
			printf("\nSet a 4 digit account pin : ");
			scanf("%d",&c.pin);
		}while(c.pin < 1000 && c.pin > 9999);
		
		do
		{
			printf("\nEnter Custemor Balance : ");
			scanf("%f",&c.balance);
		}while(c.balance < 100);
		


		if(enter != 'y')
			while(fread(&lastacc,sizeof(customer),1,fr) == 1);
		else
			lastacc.accno++;
		

		if(entry == 0)
			c.accno = lastacc.accno+1;
		
		fwrite(&c,sizeof(customer),1,fw);
		
		printf("\nTo store more data press y : ");
		enter = getche();
		entry = 0;
	}while(enter == 'y');
	
	fclose(fw);
	fclose(fr);
	return 1;

}
