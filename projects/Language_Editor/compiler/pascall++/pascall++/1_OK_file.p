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
		STRUCT s1: in;
	};

	STRUCT s1: e;
}