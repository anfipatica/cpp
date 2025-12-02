

int	main(void)
{
	int		a = 42;			// Reference value;

	double	b = a;			// Implicit conversion cast;
	double	c = (double) a;	// Explicit conversion cast;

	// un int son 32 bits, un double son 64. Cuando asignas un int a un double
	// hay espacio de sobra para que no se pierda información, todo OK.
	// Cuando el casteo implicaría pérdida de precisión, es un demotion.
	double	d = a;			// Implicit promotion -> OK;
	int		e = d;			// Implicit demotion  -> Hazardous! ;
	int		f = (int) d;	// Explicit demotion  -> Ok, you're in charge;

	/* Realmente el Implicit demotion no es que esté mal pero es buena práctica
	hacerlo  explícito para evitar el programas grandes errores de cálculo por
	un implicit demotion que no pretendíamos*/

	/* Hay un flag en c++ -Wno-conversion o algo así para impedir implicit demotions.
	Podríamos haber tenido este problema en el CUB3D??? Who knows....*/

}