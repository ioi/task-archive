unit books;

interface

type
	TIntArray = array of longint;

function minimum_walk(p: TIntArray; s: longint): int64;

implementation

uses math;

const
	maxn = 1000005;

var
	le, ri, ps, mark: array[0..maxn] of longint;

function vl(x: longint): longint;
begin
	if x > 0 then
		vl := x
	else
		vl := -x;
end;

procedure go(var l, r: longint; nl, nr: longint);
begin
	while (nl < l) or (r < nr) do
	begin
		if nl <> l then
		begin
			l := l - 1;
			nl := min(nl, le[l]);
			nr := max(nr, ri[l]);
		end
		else
		begin
			r := r + 1;
			nl := min(nl, le[r]);
			nr := max(nr, ri[r]);
		end;
	end;
end;

function dist(s, t: longint): longint;
var
	ns: longint;
begin
	if s = t then
	begin
		dist := 0;
		exit;
	end;
	ns := s;
	if t < s then
	begin
		while s >= ns do
		begin
			ns := min(ns, le[s]);
			s := s - 1;
			if ns <= t then
			begin
				dist := 0;
				exit;
			end;
		end;
	end
	else
	begin
		while s <= ns do
		begin
			ns := max(ns, ri[s]);
			s := s + 1;
			if ns >= t then
			begin
				dist := 0;
				exit;
			end;
		end;
	end;
	dist := dist(s, t) + 2;
end;
function minimum_walk(p: TIntArray; s: longint): int64;
var
	n, i, v, gl, gr, nl, nr, l, r: longint;
	ans: int64;
	done: boolean;
begin
	n := length(p);
	ans := 0;
	for i := 0 to n - 1 do
	begin
		ans := ans + vl(i - p[i]);
		le[i] := i;
		ri[i] := i;
		ps[p[i]] := i;
		mark[i] := 0;
	end;
	for i := 0 to n - 1 do
		if mark[i] = 0 then
		begin
			v := i;
			while mark[v] < 2 do
			begin
				le[v] := min(le[v], le[p[v]]);
				ri[v] := max(ri[v], ri[p[v]]);
				mark[v] := mark[v] + 1;
				v := ps[v];
			end;
		end;
	gl := 0;
	while (gl < s) and (p[gl] = gl) do
		gl := gl + 1;
	gr := n - 1;
	while (gr > s) and (p[gr] = gr) do
		gr := gr - 1;
	l := s + 1;
	r := s;
	go(l, r, s, s);
	done := false;
	while (gl < l) or (r < gr) do
	begin
		nl := l;
		nr := r;
		if not done then
			while (nl >= 0) and (ri[nl] <= r) do
				nl := nl - 1;
		if nl = -1 then
			done := true;
		if done then
		begin
			nl := l;
			if l <= gl then
			begin
				nr := nr + 1;
				ans := ans + 2;
			end
			else
			begin
				nl := nl - 1;
				ans := ans + 2;
			end;
		end
		else
		begin
			while l <= le[nr] do
				nr := nr + 1;
			ans := ans + min(dist(l - 1, nl), dist(r + 1, nr)) + 2;
		end;
		go(l, r, nl, nr);
	end;
	minimum_walk := ans;
end;

end.
