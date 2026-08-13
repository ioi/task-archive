unit train;

interface

type
	TIntArray = array of longint;

function who_wins(a, r, u, v: TIntArray): TIntArray;

implementation

function who_wins(a, r, u, v: TIntArray): TIntArray;
var
	res: TIntArray;
	i: longint;
begin
	setLength(res, length(a));
	for i := 0 to length(res) - 1 do
		res[i] := i mod 2;
	who_wins := res;
end;

end.
