PROGRAM progtato
{
	VAR INTEGER: c;
	
	STRUCT s1
	{
		VAR INTEGER: a;
		VAR FLOAT: b;
	};


	STRUCT s2
	{
		VAR INTEGER: a;
		STRUCT s2: mm;
	};

	STRUCT s2: e;
	c = e.mm.a;
}