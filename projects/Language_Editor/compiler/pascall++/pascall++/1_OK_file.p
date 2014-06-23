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

	PROCEDURE p( VAR INTEGER: a )
	{
	};

	STRUCT s2: e;

	p(1);
	c = e.mm.a;
}