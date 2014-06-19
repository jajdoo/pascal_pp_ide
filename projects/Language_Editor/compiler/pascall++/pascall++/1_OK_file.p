PROGRAM progtato
{
	STRUCT tester
	{
		VAR INTEGER: intmemb;
		VAR FLOAT: realmemb;
	};

	PROCEDURE t( VAR INTEGER: a, VAR INTEGER: c ) 
	{
		VAR INTEGER: b;
		PROCEDURE tt( VAR FLOAT: a )
		{
			VAR BOOLEAN: b;
		}; 
	};
}