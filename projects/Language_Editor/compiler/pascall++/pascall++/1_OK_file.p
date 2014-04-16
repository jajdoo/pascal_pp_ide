PROGRAM progtato
{

	STRUCT tomato 
	{
		VAR INTEGER: a,b,c,d,e,f;
	};

	STRUCT potato 
	{
		STRUCT tomato: t;
		VAR INTEGER: c;
	};

	VAR INTEGER: bbb;
	bbb = 5;
}
