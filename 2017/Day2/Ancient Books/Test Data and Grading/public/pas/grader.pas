uses books;

type
	TIntArray = array of longint;

var
	n, s: longint;
	p: TIntArray;
	i: longint;
	res: int64;

begin
	read(n);
	read(s);

	setlength(p, n);
	for i := 0 to n - 1 do
	begin
		read(p[i]);
	end;

	res := books.minimum_walk(p, s);
	writeln(res);
end.
