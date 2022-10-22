#include <stdio.h>
#include <stdlib.h>
typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;
void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}
MathOperation GetOperation(char *op)
{
    /* Implement me! */
}
double StringToDouble(char *str)
{
    /* Implement me! */

	double number; //Holds the num from argument
    int len;    //Length of the string
    while(str[len] != '\0')
    {
        len = len + 1;
    }
    printf("%d\n", len);
	/*for(int i = 0; i < )
	{
		number = *str;
		if(i + 1 == '\0')
		{
		*/	return number;
	//	}
	//}
	printf("%s\n", number);
}
int main(int argc, char *argv[])
{
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
    switch (op)
    {
       case ADD:
         result = v+v2;
         break;
       /* Implement more cases... */
		case MULT:
		  result = v*v2;
		  break;
		case SUBTRACT:
			result = v-v2;
			break;
		case DIV:
			result = v/v2;
			break;
		case UNSUPPORTED:
			IssueBadOperationError();
			//Check this
    }
    printf("%d\n", (int) result);
    printf("%c\n", "HELLO");
 
    return 0;
}

