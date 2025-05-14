#include <stdio.h>

//int	i = 0;
//Si añadimos esta línea, en el printf normal no especificamos el ámbito en que
//se encuentra i, por tanto como usamos el namespace one, no sabe si se refiere a
// ::i o a one::i.

namespace one {
	int	i = 1;
}

namespace two {
	int	i = 2;
}

namespace oneAgain = one;

using namespace one;

int	main(void)
{
	printf("normal        : i = %d\n", i);
	printf("one  namespace: i = %d\n", one::i);
	printf("two  namespace: i = %d\n", two::i);
	printf("oneAgain nmspc: i = %d\n", oneAgain::i);
}