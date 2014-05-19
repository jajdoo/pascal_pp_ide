PROGRAM progtato
{
	VAR INTEGER: i;
	PROCEDURE p()
	{
		VAR INTEGER: j;
		j = 5;
	};

	PROCEDURE pp() 
	{
		VAR INTEGER: k;
		k = 5;

		PROCEDURE ppp()
		{
			VAR INTEGER: l;
			l = 5;
		};
	};

	i = 5;
}