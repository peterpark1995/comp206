#include "parse.h"

#include <stdlib.h>

#define BUFFER_SIZE 60

typedef struct Parser 
{
	int string_length;
	int current_index;
	int curruent_number_of_tokens; //Number of tokens as buffer empties
	int number_of_tokens; //Initial number of tokens
	char buffer[BUFFER_SIZE];
}Parser;

Parser parser;

void initBuffer(char *inputLine)
{
	// Initialize the current buffer's index
	parser.string_length = 0;
	parser.current_index = 0;
	parser.curruent_number_of_tokens = 0;

	// Check whether or not the inputLine is null, if not loop through the pointer
	int index = 0;

	if (inputLine)
	{
		int message_token_found = 0;
		int spaces = 0;
		while (inputLine[index] != '\0')
		{
			if (parser.string_length < BUFFER_SIZE)
			{
				parser.buffer[index] = inputLine[index];

				if (parser.buffer[index] == ' ' && !message_token_found)
				{
					spaces++;
				} else if (parser.buffer[index] == '\"')
				{
					if (message_token_found)
					{
						message_token_found = 0;
					} else 
					{
						message_token_found = 1;
					}
				}
				index++;
				parser.string_length++;
			}
		}
		parser.curruent_number_of_tokens = spaces + 1;
	}

	parser.number_of_tokens = parser.curruent_number_of_tokens;
}

int hasNextToken()
{
	if (parser.curruent_number_of_tokens)
	{
		return 1;
	} else
	{
		return 0;
	}
}

char *nextToken()
{
	if (parser.string_length == 0)
	{
		return NULL;
	}

	int length_of_next_token = 0;
	int index = parser.current_index; 
	int message_token_found = 0;
	while (index < parser.string_length)
	{
		if (parser.buffer[index] == ' ' && !message_token_found)
		{
			break;
		} else if (parser.buffer[index] == '\"')
		{
			if (message_token_found)
			{
				length_of_next_token++;
				break;
			}
			else 
			{
				message_token_found = 1;
			}
		}

		length_of_next_token++;
		index++;
	}

	index++;

	// Create a char array and copy over the token
	// Token will be null terminated
	char *next_token = (char *) malloc((length_of_next_token + 1) * sizeof(char));
	for (index = 0; index < length_of_next_token; index++)
	{
		next_token[index] = parser.buffer[parser.current_index];
		parser.current_index++;
	}

	// Move one more step to make index point past currently found space or quortation mark
	parser.current_index++;

	next_token[index] = '\0';

	//Now the array has one less token
	parser.curruent_number_of_tokens--;

	return next_token;
}

void Rewind()
{
	parser.current_index = 0;
	parser.curruent_number_of_tokens = parser.number_of_tokens;
}