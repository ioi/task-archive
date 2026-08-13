program grader;

uses train;

var
	n, m: longint;
	a, r, u, v, res: TIntArray;
	i: longint;

begin
	readln(n, m);

	setLength(a, n);
	setLength(r, n);
	setLength(u, m);
	setLength(v, m);

	for i := 0 to n - 1 do
		read(a[i]);

	for i := 0 to n - 1 do
		read(r[i]);

	for i := 0 to m - 1 do
		read(u[i], v[i]);

	res := who_wins(a, r, u, v);

	for i := low(res) to high(res) do
	begin
		if i > 0 then
			write(' ');
		write(res[i]);
	end;
	writeln();
end.
