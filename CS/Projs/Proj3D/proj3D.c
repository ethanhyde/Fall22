#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 12

typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;

typedef struct
{
    int top; 
    double theStack[MAX_SIZE];

} stack;

void initialize(stack *s)
{
    //s->theStack = malloc(sizeof(double) * MAX_SIZE);
    s->top = 0;
};

void push(double val, stack *s)
{
    s->top++;
    s->theStack[s->top] = val;
    //printf("Pushed %f\n", val);
}

double pop(stack *s)
{
    double topValue = s->theStack[s->top];
    s->top--;
    return topValue;
}

void IssueBadNumberError()
{
    //printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    //printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

MathOperation GetOperation(char *op)
{
	char operation = *op;
	
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
    //Initializes stack
    stack *s = malloc(sizeof(stack));
    initialize(s);
    
    double result = 0.0;
    double v = 0;
    char op;

    
    for(int i = 1; i < argc; i++)
    {
        //Getting the operations
        if(*argv[i] == '-' || *argv[i] == '+' || *argv[i] == 'x' || *argv[i] == '/')
        {
            //printf("LOOKING FOR OP\n");
            op = GetOperation(argv[i]);

            switch (op)
            {
            case ADD:
                result = pop(s) + pop(s);
				push(result, s);
                //printf("FOUND ADD\n");
                break;
		    case MULT:
		        result = (pop(s) * pop(s));
				push(result, s);
		        break;
		    case SUBTRACT:
                double op2 = pop(s);
				double op1 = pop(s);
				//printf("OP 1 is %f\n OP 2 is %f\n", op1, op2);
			    push(op1 - op2, s);
                result = s->theStack[s->top];
				//printf("Result is %f\n", result);
			    break;
		    case DIV:
                double op3 = pop(s);
			    push(pop(s) / op3, s);
                result = s->theStack[s->top];
			    break;
		    case UNSUPPORTED:
			    IssueBadOperationError();
            }
        }

        else
        {
           // printf("LOOKING\n");
            float num = 0;
            
            num = StringToDouble(argv[i]);
            push(num, s);
        }
    }

    printf("The total is %d\n", (int) s->theStack[s->top]);
 
    return 0;
}

