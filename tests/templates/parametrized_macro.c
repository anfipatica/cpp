#include <stdio.h>

#define PRINT_VAR(X) printf(#X" is %d at \n", X);
#define MULTI_LINE(STRING)\
	printf(STRING"a ");\
	printf(STRING"b ");\
	printf(STRING"c ");\
	printf(STRING"d ");\
	printf(STRING"e ");\
	printf(STRING"f ");

#define MAX(A, B) (A >= B ? A : B)

int	function(int n)
{
	printf("Haciendo cositas con %d...\n", n);
	return (n);
}

int main(void)
{
	int	n1 = 10;
	int n2 = 42;
	PRINT_VAR(n1);

	printf("%d\n", MAX(3, 8));

	printf("%d\n", MAX(function(3), function(8)));
	return (0);
}