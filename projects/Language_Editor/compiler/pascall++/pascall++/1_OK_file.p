PROGRAM potato
{
STRUCT tomato 
{
	VAR INTEGER: a, b;
	VAR BOOLEAN: c^;
	VAR FLOAT: d[4], e[5][7];
};

VAR INTEGER: i, j, k;
STRUCT tomato: t;
i=5;
t.a = i + t.b.c;
}
