#include <stdio.h> //standard library
#include <math.h> //for math functions
#include <stdlib.h> //for atof
#include <ctype.h> //for toupper and tolower

char optionFunction(void); //declaring option function for B, U, A, V, E
double binaryFunction(double num1, double num2, char operation); //declaring binary function 
double unaryFunction(double x, char operator); //declaring unary function
void variableFunction(double num, char variable); //declaring variable function
char exitFunction(void); //declaring exit function

//declaring global variables
double a=0;
double b=0;
double c=0;
double d=0;
double e=0;

int main(void) {
    printf("Welcome to my Command-Line Calculator (CLC)\nDeveloper: Hiba Rehman\nVersion: 3\nDate: 11/30/2022\n"); //welcome message
	printf("---------------------------------------------------------\n");
	printf("Select one of the following items:\nB) - Binary Mathematical Operations, such as addition and subtraction.\nU) - Unary Mathematical Operations, such as square root, and log.\nA) - Advances Mathematical Operations, using variables, arrays\nV) - Define variables and assign them values.\nE) - Exit\n"); //list of options
    while(1) {
        char option=optionFunction(); //calling the option function
        while(getchar()!='\n'); //all throughout code, clears input buffer
        switch(toupper(option)) { //switch case for option selected (B, U, A, V, E)
            case 'B': { //binary operator
                double num1=0, num2=0;
                char operation=' ';
                printf("The result is %lf\n", binaryFunction(num1, num2, operation)); //calling the function
                break;
            }
            case 'U': { //unary operator
                double x=0;
                char operator=' ';
                printf("The result is %lf\n", unaryFunction(x, operator)); //calling the function
                break;
            }
            case 'A': { //advanced operator
                char selection;
                int x=1;
                while(x==1) { //setting a condition for the while loop (basically, 1 means 'true' in this case)
                    printf("Please make a selection (B, U, E):\n"); //choosing between B, U, and E
	                scanf(" %c", &selection);
                    selection=toupper(selection); //changing to upper case
                    if(selection!='B' && selection!='U' && selection!='E') {
                        puts("Invalid operation. Please try again.");
                        x=1; //the code will loop again until there is a valid input
                    }
                    else {
                        x=0; //exiting the loop (the condition is now 'false')
                    }
                }
                switch(toupper(selection)) { //switch case for selection
                    case 'B': {
                        double num1, num2, result;
                        char vnum[0]; //temporary array for string to be stored in
                        char operation;
                        do { //checks if input is number, variable, or invalid (something else)
                            while (getchar()!='\n');
                            printf("Please enter the first number or a variable:\n");
                            if (scanf("%s", vnum)!= 1) //if it is a character (symbols won't work)
                                continue;
                            if (vnum[0]=='a' || vnum[0]=='b' || vnum[0]=='c' || vnum[0]=='d' || vnum[0]=='e') { 
                                switch (vnum[0]) { //if it's a,b,c,d,e then assign num1 to that variable
                                case 'a':
                                    num1=a;
                                    break;
                                case 'b':
                                    num1=b;
                                    break;
                                case 'c':
                                    num1=c;
                                    break;
                                case 'd':
                                    num1=d;
                                    break;
                                case 'e':
                                    num1=e;
                                    break;
                                }
                                break;
                            }
                            else {
                                num1=atof(vnum); //convert string to float
                                if(num1!=0.0) { //so that it only works if is a number
                                    break;
                                }
                            }
                        } while(1);
                        // anything other than a number or a,b,c,d,e won't work
                        // the reason for the array is so that only one character will be checked and so a comparison can be made
            
                        do { //checks if input is number, variable, or invalid (something else)
                            while (getchar()!='\n');
                            printf("Please enter the second number or a variable:\n");
                            if (scanf("%s", vnum)!=1) //same as above but with num2
                                continue;
                            if (vnum[0]=='a' || vnum[0]=='b' || vnum[0]=='c' || vnum[0]=='d' || vnum[0]=='e') {
                                switch (vnum[0]) {
                                case 'a':
                                    num2=a;
                                    break;
                                case 'b':
                                    num2=b;
                                    break;
                                case 'c':
                                    num2=c;
                                    break;
                                case 'd':
                                    num2=d;
                                    break;
                                case 'e':
                                    num2=e;
                                    break;
                                }
                                break;
                            }
                            else {
                                num2=atof(vnum);
                                if(num2!=0.0) {
                                    break;
                                }
                            }
                        } while(1);

                        do
                        { // checking if operation is valid
                            printf("Please enter the operation (+, -, *, /, %%, P, X, I):\n");
                            scanf(" %c", &operation);
                            while(getchar()!='\n');
                        } while (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '%' && toupper(operation) != 'P' && toupper(operation) != 'X' && toupper(operation) != 'I' && puts("Invalid input. Please try again."));

                        switch(operation) { //doing the math for binary function
                            case '+': {
		                        result=num1+num2;
                                break; 
                            }
		                    case '-': {
		                        result=num1-num2;
                                break;
                            }
                            case '*': {
                                result=num1*num2;
                                break;
                            }
                            case '/': {
                                if(num2!=0) {
                                    result=num1/num2;
                                }
                                else {
                                    puts("The denominator can't be 0.");
                                    result=0;
                                }
                                break;
                            }
                            case '%': {
                                result=fmod(num1,num2);
                                break;
                            }
                            case 'P':
                            case 'p': {
                                result=pow(num1,num2);
                                break;
                            }
                            case 'X':
                            case 'x': {
                                result=fmax(num1,num2);
                                break;
                            }
                            case 'I':
                            case 'i': {
                                result=fmin(num1,num2);
                                break;
                            }
                            default: {
                                puts("This operation is invalid.");
                                break;
                            }
                        }
                        printf("The result is %lf\n", result);
                        break;
                    }
                    case 'U': {
                        double x, result;
                        char vnum[10]; //temp array
                        char operator;
                        printf("Please enter a number or a variable:\n");
			            do { //checks if input is number, variable, or invalid (something else)
                            while (getchar()!='\n');
                            if (scanf("%s", vnum)!=1) //same as above but with x
                                continue;
                            if (vnum[0]=='a' || vnum[0]=='b' || vnum[0]=='c' || vnum[0]=='d' || vnum[0]=='e') {
                                switch (vnum[0]) {
                                case 'a':
                                    x=a;
                                    break;
                                case 'b':
                                    x=b;
                                    break;
                                case 'c':
                                    x=c;
                                    break;
                                case 'd':
                                    x=d;
                                    break;
                                case 'e':
                                    x=e;
                                    break;
                                }
                                break;
                            }
                            else {
                                x=atof(vnum);
                                if(x!=0.0) {
                                    break;
                                }
                            }
                        } while(1);

                        do { //checking if operator is valid
                            printf("Please enter an operator (S, L, E, C, F):\n");
                            scanf(" %c", &operator);
                            operator=toupper(operator);
                            while(getchar()!='\n');
                        } while(operator!='S' && operator!='L' && operator!='E' && operator!='C' && operator!='F' && puts("Invalid input. Please try again."));
       
                        switch(toupper(operator)) { //doing the math for unary function
                            case 'S': {
                                result=sqrt(x);
                                break;
                            }
                            case 'L': {
                                result=log(x);
                                break;
                            }
                            case 'E': {
                                result=exp(x);
                                break;
                            }
                            case 'C': {
                                result=ceil(x);
                                break;
                            }
                            case 'F': {
                                result=floor(x);
                                break;
                            }
                            default: {
                                puts("This operation is invalid.");
                                break;
                            }
                        }
                        printf("The result is %lf\n", result);
                        break;
                    }
                    case 'E': {
                        break; //simply goes out of advanced operator but not the program
                    }  
                }
                break;
            }
            case 'V': { //variable function
                double num, check1;
                char variable;
                do { //checking if letter is between a-e, invalid message if not true
                    printf("Please enter a variable letter (from a-e):\n");
                    scanf("%s", &variable);
                    while(getchar()!='\n');
                } while(tolower(variable)!='a' && tolower(variable)!='b' && tolower(variable)!='c' && tolower(variable)!='d' && tolower(variable)!='e' && puts("Invalid input. Please try again."));

                printf("Please enter a number to assign to variable:\n");
                check1=scanf("%lf", &num); //to check if input is a number (won't work for anything else)
                if(check1!=1) {
                    while(check1!=1){
                        while(getchar()!='\n');
                        puts("Invalid input. Please try again.");
                        puts("Please enter a number to assign to variable:");
                        check1=scanf("%lf", &num);
                    }
                }

                variableFunction(num, variable); //calls variable function
                break;
            }
            case 'E': { //exit function
                exitFunction();
                return 0;
                break;
            }
        }
    }
} //end of main function

//functions
//binary and unary functions were not used in case A due to the 'number checker' having to be used for variables as well in case A

double binaryFunction(double num1, double num2, char operation) { //binary function for each operation + does math
    double result, check1, check2;
    printf("Please enter the first number:\n");
    check1=scanf("%lf", &num1); //to check if input is a number (won't work for anything else)
    if(check1!=1) {
        while(check1!=1){
            while(getchar()!='\n');
            puts("Invalid input. Please try again.");
            puts("Please enter the first number:");
            check1=scanf("%lf", &num1);
        }
    }
    while(getchar()!='\n'); 

    printf("Please enter the second number:\n");
    check2=scanf("%lf", &num2); //to check if input is a number (won't work for anything else)
    if(check2!=1) {
        while(check2!=1){
            while(getchar()!='\n');
            puts("Invalid input. Please try again.");
            puts("Please enter the second number:");
            check2=scanf("%lf", &num2);
        }
    }
    while(getchar()!='\n');

    do { //runs again if invalid input (such as another symbol/letter/number) & prints invalid message
        printf("Please enter the operation (+, -, *, /, %%, P, X, I):\n");
		scanf(" %c", &operation);
        while(getchar()!='\n');
    } while(operation!='+' && operation!='-' && operation!='*' && operation!='/' && operation!='%' && toupper(operation)!='P' && toupper(operation)!='X' && toupper(operation)!='I' && puts("Invalid input. Please try again."));

    switch(operation) {
        case '+': {
		    result=num1+num2;
            break; 
        }
		case '-': {
		    result=num1-num2;
            break;
        }
        case '*': {
            result=num1*num2;
            break;
        }
        case '/': {
            if(num2!=0) {
                result=num1/num2;
            }
            else {
                puts("The denominator can't be 0.");
                result=0;
            }
            break;
        }
        case '%': {
            result=fmod(num1,num2);
            break;
        }
        case 'P':
        case 'p': {
            result=pow(num1,num2);
            break;
        }
        case 'X':
        case 'x': {
            result=fmax(num1,num2);
            break;
        }
        case 'I':
        case 'i': {
            result=fmin(num1,num2);
            break;
        }
        default: {
            puts("This operation is invalid.");
            break;
        }
    }
    return result;
}

double unaryFunction(double x, char operator) { //unary function for each operator + does math
    double result, check1;
    printf("Please enter a number:\n");
    check1=scanf("%lf", &x); //to check if input is a number (won't work for anything else)
    if(check1!=1) {
        while(check1!=1){
            while(getchar()!='\n');
            puts("Invalid input. Please try again.");
            puts("Please enter a number:");
            check1=scanf("%lf", &x);
        }
    }

    do {
        printf("Please enter an operator (S, L, E, C, F):\n");
        scanf(" %c", &operator);
        operator=toupper(operator);
        while(getchar()!='\n');
    } while(operator!='S' && operator!='L' && operator!='E' && operator!='C' && operator!='F' && puts("Invalid input. Please try again."));
       
    switch(toupper(operator)) {
        case 'S': {
            result=sqrt(x);
            break;
        }
        case 'L': {
            result=log(x);
            break;
        }
        case 'E': {
            result=exp(x);
            break;
        }
        case 'C': {
            result=ceil(x);
            break;
        }
        case 'F': {
            result=floor(x);
            break;
        }
        default: {
            puts("This operation is invalid.");
            break;
        }
    }
    return result;
}

void variableFunction(double num, char variable) { //variable function to store a value into the variable for later use
    switch(tolower(variable)) {
        case 'a': {
            a=num;
            break;
        }
        case 'b': {
            b=num;
            break;
        }
        case 'c': {
            c=num;
            break;
        }
        case 'd': {
            d=num;
            break;
        }
        case 'e': {
            e=num;
            break;
        }
        default: {
            puts("Invalid input.");
            break;
        }
    }
}

char optionFunction(void) { //option function
    char op;
    int x=1;
    while(x==1) { //setting a condition for the while loop (basically, 1 means 'true' in this case)
        printf("Please select your option (B, U, A, V, E)\n");
	    scanf(" %c", &op); //reading option input by user
        op=toupper(op); //changing to upper case
        if(op!='B' && op!='U' && op!='A' && op!='V' && op!='E') {
            puts("Invalid operation. Please try again.");
            x=1; //the code will loop again until there is a valid input
        }
        else {
            x=0; //exiting the loop (the condition is now 'false')
        }
    }
   return toupper(op);
}

char exitFunction(void) { //exit function
    puts("Thanks for using my Simple Calculator. Hope to see you again soon. Goodbye!");
    exit(1); //exits the entire program
}