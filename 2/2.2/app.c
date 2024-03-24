#include <stdio.h>

#define LN 64

int Fold(int a, int b);
int Subtract(int a, int b);
int Multiply(int a, int b);
int Divide(int a, int b);

int main(void) {
    char* menu[] = {"f - fold a,b","s - subtract a,b","m - multiply a,b","d - divide a,b","q - exit"};
    int k = sizeof(menu)/sizeof(menu[0]);
    char choose[LN];
    do {
        choose[0] = 0;
        int a,b,res;
        fprintf(stdout, "Input value a and b: ");
        if(scanf("%d%c%d%c", &a, &choose[0], &b, &choose[1]) != 4 || choose[1] != '\n')
            continue;
		for (int i = 0; i < k; i++)
			fprintf(stdout, "%s\n", menu[i]);
		fgets(choose, LN, stdin);
		switch (choose[0])
		{
		case 'f':
			res = Fold(a, b);
            fprintf(stdout, "Result: %d\n", res);
			break;
		case 's':
			res = Subtract(a, b);
            fprintf(stdout, "Result: %d\n", res);
			break;
		case 'm':
			res = Multiply(a, b);
            fprintf(stdout, "Result: %d\n", res);
			break;
		case 'd':
			res = Divide(a, b);
            fprintf(stdout, "Result: %d\n", res);
            break;
        case 'q':
            return 0;
		default:
			break;
		}
    }while(choose[0] != 'q');
    return 0;
}

int Fold(int a, int b) {
    return a + b;
}

int Subtract(int a, int b) {
    return a - b;
}

int Multiply(int a, int b) {
    return a * b;
}

int Divide(int a, int b) {
    return a / b;
}