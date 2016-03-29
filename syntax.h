#ifndef SYNTAX_H_
#define SYNTAX_H_

// Returns 1 if the token is one of the valid robot commands,
// otherwise it returns 0
int isValidCommand(char *token);

// Returns 1 if the expression agrees with one of the legal 
// robot expressions, otherwise it returns 0
int isValidExpression(char *expression);

#endif // SYNTAX_H_
