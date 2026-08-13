program grader;

uses train;

var
	n, m: longint;
	a, r, u, v, res: TIntArray;
	i: longint;
	// BEGIN SECRET
	secret: string;
	// END SECRET

begin
	// BEGIN SECRET
	readln(secret);
	if secret <> '3d2051c242fe2ae63792f9868123a5eb' then
	begin
		writeln('d16905a4427c193ad87ae7fa91a2bb55');
		writeln('SV');
		halt(0);
	end;
	// END SECRET
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

	// BEGIN SECRET
	writeln('d16905a4427c193ad87ae7fa91a2bb55');

	if length(res) <> n then
	begin
		writeln('WA');
		writeln('Wrong returned array size');
	end
	else
		writeln('OK');
	// END SECRET
	for i := low(res) to high(res) do
	begin
		if i > 0 then
			write(' ');
		write(res[i]);
	end;
	writeln();
end.
