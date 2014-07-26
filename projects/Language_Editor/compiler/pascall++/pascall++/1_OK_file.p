PROGRAM progtato
{
	STRUCT s1
	{
		VAR INTEGER: a;
		VAR FLOAT: b;
	};

	STRUCT s2
	{
		VAR INTEGER: a;
		STRUCT s1: b;
	};

	PROCEDURE p( VAR STRUCT s2: pa, VAL STRUCT s1: pb, VAL INTEGER: pc )
	{
		PROCEDURE pp( VAR INTEGER: ppa )
		{
		};
	};

	STRUCT s2: aaa;
	STRUCT s1: bbb;
	VAR INTEGER: c;

	c = aaa.a;

	p(aaa,bbb,c);
}