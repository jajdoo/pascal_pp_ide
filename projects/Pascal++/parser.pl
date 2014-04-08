#!/usr/bin/perl

local $/;
open(FILE, '<out2.ir') or die "Can't read file 'filename' [$!]\n";  
$document = <FILE>; 
close (FILE);  
open (MYFILE, '>graph.dot');
print MYFILE "digraph G \n {";
my @bblocks = split(/-+/, $document);
$i = 0;
foreach my $bblock (@bblocks)
{
	my @lines = split(/\[/, $bblock);
	foreach $lst (@lines)
	{$sav = $lst;}
	my @lass = split(/\]/, $sav);
	my @fir = split(/\]/, $lines[1]);
	if($i > 0)
	{
		@lass[1] =~ tr/\r\n//d;
		push(@last, @lass[1]);
		push(@first, @fir[0]);
		open (MYF, ">$i".".html");
		$bblock =~ s/\n/\n<br>/g;;
		print MYF "$bblock";
		close (MYF);
		print MYFILE "$i [URL=\"$i".".html\"]";
	} 
	$i++;
}
#Building a hash.
$i = 1;
foreach $tmp (@first)
{
	$tmp =~ tr/\/n\/r//d;
	$has{ $tmp } = $i;
	$i++;
}
$i = 1;
foreach $tmp ( @last)
{
	@tt = split(/ /, $tmp);
	if(@tt[1] eq 'BRA')
	{
		@tt[2] =~ tr/\r\n//d;
		print MYFILE "$i -> $has{@tt[2]} \n";
	}
	elsif(@tt[1] eq 'BGE' || @tt[1] eq 'BNE' )
	{
		@temp = split(/\,/, @tt[2]);
		@temp[1] =~ tr/\r\n//d;
		$j = $i+1;
		print MYFILE "$i -> $has{@temp[1]} \n";
		print MYFILE "$i -> $j \n";
	}
	elsif(@tt[1] eq 'NOP'){}
	else
	{
		$j = $i+1;
		print MYFILE "$i -> $j \n";
	}
	$i ++;
}
print MYFILE "}";
close (MYFILE);
