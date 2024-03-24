#include <stdio.h>

#define LN 64

void MakeCalculation(int (*operation) (int,int), int nums[], int size_nums);
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
        int vals[2],res;
        fprintf(stdout, "Input value a and b: ");
        if(scanf("%d%c%d%c", &vals[0], &choose[0], &vals[1], &choose[1]) != 4 || choose[1] != '\n')
            continue;
		for (int i = 0; i < k; i++)
			fprintf(stdout, "%s\n", menu[i]);
		fgets(choose, LN, stdin);
		switch (choose[0])
		{
		case 'f':
			MakeCalculation(Fold,vals,2);
			break;
		case 's':
			MakeCalculation(Subtract,vals,2);
			break;
		case 'm':
			MakeCalculation(Multiply,vals,2);
			break;
		case 'd':
			MakeCalculation(Divide,vals,2);
            break;
        case 'q':
            return 0;
		default:
			break;
		}
    }while(choose[0] != 'q');
    return 0;
}

void MakeCalculation(int (*operation) (int,int), int nums[], int size_nums) {
    int res = operation(nums[0], nums[1]);
    fprintf(stdout, "Result: %d\n", res);
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