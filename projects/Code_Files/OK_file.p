PROGRAM test
{
VAR INTEGER: z,x,y,c,d,a,b,g[10][10];
z=g[1][3];
g[1][3]=z;
WHILE ( c == d) DO
		c = d + g[1][3];
		d = d + a;
OD
IF (a < b) THEN
WHILE(x<y)
DO 
		x=x+y+2;
		WHILE(x<y+5)
		DO
			x = x + y + 5;
			y = y + 1;
		OD
		y = y + 6;
		g[x][y]=z;
OD
x=x+3;
ELSE
WHILE(x<a + b)
DO
	x = x + y + 5;
	y = y + 1;
OD
FI
}
