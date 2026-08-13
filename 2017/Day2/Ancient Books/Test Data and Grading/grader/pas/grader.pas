uses books;
// BEGIN SECRET
const
	input_secret = 'f58fb993-f209-43d7-9391-c46c61f180b9';
	output_secret = '9048298f-efa0-4f8a-9322-0c8855609a66';
// END SECRET

type
	TIntArray = array of longint;

var
	n, s: longint;
	p: TIntArray;
	i: longint;
	res: int64;
	// BEGIN SECRET
	secret: string;
	// END SECRET

begin
	// BEGIN SECRET
	readln(secret);
	if secret <> input_secret then
	begin
		writeln(output_secret);
		writeln('SV');
		halt(0);
	end;
	// END SECRET
	read(n);
	read(s);

	setlength(p, n);
	for i := 0 to n - 1 do
	begin
		read(p[i]);
	end;

	res := books.minimum_walk(p, s);
	// BEGIN SECRET
	writeln(output_secret);
	writeln('OK');
	// END SECRET
	writeln(res);
end.
