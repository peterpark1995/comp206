#include "syntax.h"
 
#include <stdlib.h>

#include "parse.h"

int strlength(char *token)
{	int i=0;
	while (*token != '\0'){
		i++;
		token++;
	} 
	return i;
}

int checkTAKEASTEP(char *token, int size){
	if (size==9){
		return (token[0]=='T'|| token[0] == 't')&&
			   (token[1]=='A'|| token[1] == 'a')&&
			   (token[2]=='K'|| token[2] == 'k')&&
			   (token[3]=='E'|| token[3] == 'e')&&
			   (token[4]=='A'|| token[4] == 'a')&&
			   (token[5]=='S'|| token[5] == 's')&&
			   (token[6]=='T'|| token[6] == 't')&&
			   (token[7]=='E'|| token[7] == 'e')&&
			   (token[8]=='P'|| token[8] == 'p');
	}
	return 0;
}

int checkLEFT(char *token, int size){
	if (size==4){
		return (token[0]=='L'|| token[0] == 'l')&&
			   (token[1]=='E'|| token[1] == 'e')&&
			   (token[2]=='F'|| token[2] == 'f')&&
			   (token[3]=='T'|| token[3] == 't');
	}
	return 0;
}
int checkRIGHT(char *token, int size){
	if (size==5){
		return (token[0]=='R'|| token[0] == 'r')&&
		       (token[1]=='I'|| token[1] == 'i')&&
		       (token[2]=='G'|| token[2] == 'g')&&
		       (token[3]=='H'|| token[3] == 'h')&&
		       (token[4]=='T'|| token[4] == 't');	
	}
	return 0;
}
int checkPICKUP(char *token, int size){
	if (size==6){
		return (token[0]=='P'|| token[0] == 'p')&&
			   (token[1]=='I'|| token[1] == 'i')&&
			   (token[2]=='C'|| token[2] == 'c')&&
			   (token[3]=='K'|| token[3] == 'k')&&
			   (token[4]=='U'|| token[4] == 'u')&&
			   (token[5]=='P'|| token[5] == 'p');
	}
	return 0;
}
int checkDROP(char *token, int size){
	if (size==4){
		return (token[0]=='D'|| token[0] == 'd')&&
			   (token[1]=='R'|| token[1] == 'r')&&
			   (token[2]=='O'|| token[2] == 'o')&&
			   (token[3]=='P'|| token[3] == 'p');
	}
	return 0;
}
int checkDETECTMARKER(char *token, int size){
	if (size==12){
		return (token[0]=='D'|| token[0] == 'd')&&
		       (token[1]=='E'|| token[1] == 'e')&&
		       (token[2]=='T'|| token[2] == 't')&&
		       (token[3]=='E'|| token[3] == 'e')&&
		       (token[4]=='C'|| token[4] == 'c')&&
		       (token[5]=='T'|| token[5] == 't')&&
		       (token[6]=='M'|| token[6] == 'm')&&
		       (token[7]=='A'|| token[7] == 'a')&&
		       (token[8]=='R'|| token[8] == 'r')&&
		       (token[9]=='K'|| token[9] == 'k')&&
		       (token[10]=='E'|| token[10] == 'e')&&
		       (token[11]=='R'|| token[11] == 'r');
	}
	return 0;
}
int checkTURNON(char *token, int size){
	if (size==6){
		return (token[0]=='T'|| token[0] == 't')&&
			   (token[1]=='U'|| token[1] == 'u')&&
			   (token[2]=='R'|| token[2] == 'r')&&
			   (token[3]=='N'|| token[3] == 'n')&&
			   (token[4]=='O'|| token[4] == 'o')&&
			   (token[5]=='N'|| token[5] == 'n');
	}
	return 0;
}
int checkTURNOFF(char *token, int size){
	if (size==7){
		return (token[0]=='T'|| token[0] == 't')&&
			   (token[1]=='U'|| token[1] == 'u')&&
			   (token[2]=='R'|| token[2] == 'r')&&
			   (token[3]=='N'|| token[3] == 'n')&&
			   (token[4]=='O'|| token[4] == 'o')&&
			   (token[5]=='F'|| token[5] == 'f')&&
			   (token[6]=='F'|| token[6] == 'f');
	}
	return 0;
}

int checkREPEAT(char *token, int size)
{
	if (size==6){
		return (token[0]=='R'|| token[0] == 'r')&&
			   (token[1]=='E'|| token[1] == 'e')&&
			   (token[2]=='P'|| token[2] == 'p')&&
			   (token[3]=='E'|| token[3] == 'e')&&
			   (token[4]=='A'|| token[4] == 'a')&&
			   (token[5]=='T'|| token[5] == 't');
	}
	return 0;	
}

int checkN(char *token, int size)
{
	int i = 0;

	while (token[i] != '\0')
	{
		if ('0' > token[i] || token[i] > '9')
		{
			return 0;
		}
		i++;
	}


	return 1;
}

int checkTIMES(char *token, int size)
{
	if (size==5){
		return (token[0]=='T'|| token[0] == 't')&&
			   (token[1]=='I'|| token[1] == 'i')&&
			   (token[2]=='M'|| token[2] == 'm')&&
			   (token[3]=='E'|| token[3] == 'e')&&
			   (token[4]=='S'|| token[4] == 's');
	}
	return 0;		
}

int checkWHILE(char *token, int size)
{
	if (size==5){
		return (token[0]=='W'|| token[0] == 'w')&&
			   (token[1]=='H'|| token[1] == 'h')&&
			   (token[2]=='I'|| token[2] == 'i')&&
			   (token[3]=='L'|| token[3] == 'l')&&
			   (token[4]=='E'|| token[4] == 'e');
	}
	return 0;		
}

int checkNOT(char *token, int size)
{
	if (size==3){
		return (token[0]=='N'|| token[0] == 'n')&&
			   (token[1]=='O'|| token[1] == 'o')&&
			   (token[2]=='T'|| token[2] == 't');
	}
	return 0;		
}

int checkDO(char *token, int size)
{
	if (size == 2){
		return (token[0]=='D'|| token[0] == 'd')&&
			   (token[1]=='O'|| token[1] == 'o');
	}
	return 0;
}

int checkSAY(char *token, int size)
{
	if (size==3){
		return (token[0]=='S'|| token[0] == 's')&&
			   (token[1]=='A'|| token[1] == 'a')&&
			   (token[2]=='Y'|| token[2] == 'y');
	}
	return 0;	
}

int checkMESSAGE(char *token, int size)
{
	if (token[0] == '\"' && token[size - 1] == '\"')
	{
		return 1;
	} else 
	{
		return 0;
	}
}

int checkEND(char *token, int size)
{
	if (size==3){
		return (token[0]=='E'|| token[0] == 'e')&&
			   (token[1]=='N'|| token[1] == 'n')&&
			   (token[2]=='D'|| token[2] == 'd');
	}
	return 0;	
}

int checkCommandList(char *token, int size)
{
	int i;
	char *temp;
	int command_length = 0;

	//Parse through comma separated list to check for each command
	for (i = 0; i < size; i++)
	{
		//Find a comma to find a command
		if (token[i] == ',' || i == (size - 1))
		{
			//If found a comma, copy the command over and check for its validity
			temp = (char *) malloc((command_length + 1) * sizeof(char));
			temp[command_length] = '\0';
			int j;
			for (j = 0; j < command_length; j++)
			{
				temp[j] = token[(i-command_length) + j];
			}
			//If this is the last letter in the token, parse for the last command including the current index
			if(i == (size - 1))
			{
				temp[command_length] = token[i];
			}

			if (!isValidCommand(temp))
			{
				free(temp);
				return 0;
			}
			//Skip this comma for next iteration
			i++;
			command_length = 0;
		}
		command_length++;
	}

	free(temp);

	return 1;
}

/*int printErrorIndicator(char *expression, int offset_length)
{
	int i = 0;
	for (i = 0; i < offset_length; i++)
	{
		printf("%c", expression[i]);
	}
	printf("***");
	while (expression[i] != '\0')
	{
		printf("%c", expression[i]);
		i++;
	}
	printf("\n");
}*/	

int checkRepeatExpression(char *expression)
{
	Rewind();

	char *first = nextToken();
	char *second = nextToken();
	char *third = nextToken();
	char *fourth = nextToken();
	char *fifth = nextToken();

	if (checkREPEAT(first, strlength(first))&&
		checkN(second, strlength(second))&&
		checkTIMES(third, strlength(third))&&
		checkCommandList(fourth, strlength(fourth))&&
		checkEND(fifth, strlength(fifth))) 
	{
		free(first);
		free(second);
		free(third);
		free(fourth);
		free(fifth);
		return 1;
	} else 
	{
		free(first);
		free(second);
		free(third);
		free(fourth);
		free(fifth);
		return 0;
	}

	return 1;
}

int checkWhileExpression(char *expression)
{
	Rewind();

	char *first = nextToken();
	char *second = nextToken();
	char *third = nextToken();
	char *fourth = nextToken();
	char *fifth = nextToken();
	char *sixth = nextToken();

	if (checkWHILE(first, strlength(first))&&
		checkNOT(second, strlength(second))&&
		isValidCommand(third)&&
		checkDO(fourth, strlength(fourth))&&
		checkCommandList(fifth, strlength(fifth))&&
		checkEND(sixth, strlength(sixth))) 
	{
		free(first);
		free(second);
		free(third);
		free(fourth);
		free(fifth);
		free(sixth);
		return 1;
	} else 
	{
		free(first);
		free(second);
		free(third);
		free(fourth);
		free(fifth);
		free(sixth);
		return 0;
	}
}

int checkSayExpression(char *expression)
{

	Rewind();

	char *first = nextToken();
	char *second = nextToken();

	if(checkSAY(first,strlength(first))&&
  	checkMESSAGE(second, strlength(second)))
	{
		free(first);
		free(second);
		return 1;
	} else
	{
		free(first);
		free(second);
		return 0;
	}

}


int isValidCommand(char *token){
	int i=0;
	int size = strlength(token);
	return checkTURNOFF(token,size)||
		   checkTURNON(token,size)||
		   checkDETECTMARKER(token,size)||
		   checkDROP(token,size)||
		   checkPICKUP(token,size)||
		   checkRIGHT(token,size)||
		   checkLEFT(token,size)||
		   checkTAKEASTEP(token,size)||
		   checkREPEAT(token,size)||
		   checkWHILE(token,size)||
		   checkSAY(token,size)||
		   checkDO(token,size)||
		   checkN(token,size)||
		   checkMESSAGE(token,size)||
		   checkEND(token,size)||
		   checkNOT(token,size)||
		   checkTIMES(token,size);
}

int isValidExpression(char *expression){
	return checkWhileExpression(expression)||
	       checkRepeatExpression(expression)||
	       checkSayExpression(expression);
}