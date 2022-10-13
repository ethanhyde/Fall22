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
 
    return 0;
}

