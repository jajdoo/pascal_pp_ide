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

	STRUCT potato: pp;
	VAR INTEGER: bbb;
	bbb = 5;
	pp.t.a = 6;
}
