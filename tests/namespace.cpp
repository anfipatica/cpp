#include <stdio.h>

int	i = 0;

namespace one {
	int	i = 1;
}

namespace two {
	int	i = 2;
}

namespace oneAgain = one;

int	main(void)
{
¡
	printf("normal        : i = %d\n", i);
	printf("one  namespace: i = %d\n", one::i);
	printf("two  namespace: i = %d\n", two::i);
	printf("oneAgain nmspc: i = %d\n", oneAgain::i);
}