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
	char opration; //Returned value
	char operation = *op;
	int operationSecured = 0;
	
	if(operation == '+')
		{
			return ADD;
		}	
	else if(operation == '-')
		{
			return SUBTRACT;
		}	
	else if(operation == '/')
		{
			return DIV;
		}
	else if(operation == 'x')
		{
			return MULT;
		}
	else return UNSUPPORTED;
	

}
double CalculateFraction(char* str) {
	for(int j = 0; str[j] != '\0'; ++j)
		{

			if(str[j] < 48 || str[j] > 57)
			{	
				IssueBadNumberError();
			}
			
		}
	double remainder = 0.0;
	double decimalValue = 1.0;
	for(int i = 0; str[i] != '\0'; i++) {
		decimalValue /= 10;
		remainder += decimalValue * (str[i] - '0');
	}
		
	return remainder;	
}

double StringToDouble(char *str)
{
	double remainder = 0.0;
	double sum = 0.0; //Holds the num from argument
	double isNegative = 1; //Make negative if negative	
	for(int i = 0; str[i] != '\0'; ++i)
		{
			
			if(str[0] == '-')
			{
				isNegative = -1;
				++str;
			}

			if(str[i] == '.')
			{
				remainder = CalculateFraction(str + 1 + i);
				break;
			}

			if(str[i] < 48 || str[i] > 57)
			{
				IssueBadNumberError();
			}
			if (i > 0)
				sum = sum * 10;
			sum += str[i] - '0';
		}
		
		
		sum += remainder;
		sum *= isNegative;
		return sum;
}
int main(int argc, char *argv[])
{
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
	for(int i = 0; argv[2][i] != '\0'; ++i)
	{
		if(i > 0)
		{
				IssueBadOperationError();
		}
	}

    double v2 = StringToDouble(argv[3]);
    double result = 0.0;
    switch (op)
    {
       case ADD:
         result = v+v2;
         break;
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
    }
    printf("%d\n", (int) result);
 
    return 0;
}

