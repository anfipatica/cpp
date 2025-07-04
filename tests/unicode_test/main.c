#include <stdio.h>
#include <unistd.h>


void	print_bits(unsigned char octet)
{
	int mask = 0b10000000;
	for (int i = 0; i <= 7; i++){
		(octet & mask ? write(1,"1",1) : write(1,"0",1));
		mask >>= 1;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	int	i = 0;
	char *str = "𝄟";
	while (str[i])
	{
		printf("(%d)%c ", str[i], str[i]);
		print_bits(str[i]);
		i++;
	}
	printf("%d\n", i);
}