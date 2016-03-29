#include <stdio.h> 
#include <stdlib.h>

#include "parse.h"
#include "syntax.h"

#define LINE_LENGTH 60

int stringlength(char *token)
{	int i=0;
	while (*token != '\0'){
		i++;
		token++;
	} 
	return i;
}

int isWhileExpression(char *token, int size)
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


int isSayExpression(char *token, int size)
{
	if (size==3){
		return (token[0]=='S'|| token[0] == 's')&&
			   (token[1]=='A'|| token[1] == 'a')&&
			   (token[2]=='Y'|| token[2] == 'y');
	}
	return 0;	
}

int isRepeatExpression(char *token, int size)
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

int isValidCommandList(char *token)
{
	int size = stringlength(token);
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

void printErrorIndicator()
{
	Rewind();
	char *token;
	printf("\t");
	while (hasNextToken())
	{
		token = nextToken();
		if (isValidCommand(token) || isValidCommandList(token))
		{
			printf("%s ", token);
		} else 
		{
			printf("***%s ", token);
		}
	}
	printf("\n");
}	

void removeTrailingNewLine(char *string)
{
	int i = 0;
	while (string[i] != '\n')
	{
		i++;
	}
	string[i] = '\0';	
}

int main(int argc, char *argv[])
{
	int line_num = 0;
	if (argc < 1)
	{
		return -1;
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("Error in opening %s\n", argv[1]);
		return -1;
	}

	char line[LINE_LENGTH]; //How long is a line?
	//printf("Reading lines \n");
	while (fgets(line, LINE_LENGTH, file) != NULL)
	{
		line_num++;
		//printString(line);
		removeTrailingNewLine(line);
		// Do something while reading a line
		//printf("The line is: %s\n", line);

		//Check the first token to see if it is an expression r
		initBuffer(line);

		char *temp = nextToken();
		int size = stringlength(temp);

		if (isRepeatExpression(temp,size))
		{
			if (!isValidExpression(line))
			{
				printf("Error: Line %i is an invalid expression\n", line_num);
				//print where the error occured
				printErrorIndicator();

				printf("Expecting REPEAT n TIMES comma-separated-list-of-commands END\n");
						
			}	
		} else if (isWhileExpression(temp,size))
		{
			if (!isValidExpression(line))
			{
				printf("Error: Line %i is an invalid expression\n", line_num);
				//print where the error occured
				printErrorIndicator();

				printf("WHILE NOT c DO comma-separated-list-of-commands END\n");
						
			}	
		} else if (isSayExpression(temp,size))
		{
			if (!isValidExpression(line))
			{
				printf("Error: Line %i is an invalid expression\n", line_num);
				//print where the error occured
				printErrorIndicator();

				printf("Expecting SAY “message”\n");
			}
		} else 
		{
			if (!isValidCommand(temp))
			{
				printf("Error: In line %i, expecting a valid command or expression\n", line_num);				
			}
		}
	}

	return 0;
}