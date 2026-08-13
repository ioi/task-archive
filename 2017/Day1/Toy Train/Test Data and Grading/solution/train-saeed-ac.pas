unit train;

interface

type
	TIntArray = array of longint;

function who_wins(a, r, u, v : TIntArray) : TIntArray;

implementation

const
	BORZOU = 0;
	AREZOU = 1;
	MAXN = 10000 + 10;
	MAXM = 20000 + 10;

function who_wins(a, r, u, v : TIntArray) : TIntArray;
var
	n, m : longint;
	osz, isz : array [0..MAXN] of longint;
	tail : array[0..MAXN, 0..1] of longint;
	prev : array[0..MAXM, 0..1] of longint;

	q_head, q_tail : longint;
	q, f, need : array[0..MAXN] of longint;
	checked, mark : array[0..MAXN] of boolean;

	i, temp, front, pnt : longint;
	flag : boolean;
	
begin
	n := length(a);
	m := length(u);
	for i := 0 to n-1 do
	begin
		tail[i][0] := -1;
		tail[i][1] := -1;
		osz[i] := 0;
		isz[i] := 0;
	end;
	for i := 0 to m-1 do
	begin
		prev[i][0] := tail[u[i]][0];
		tail[u[i]][0] := i;
		prev[i][1] := tail[v[i]][1];
		tail[v[i]][1] := i;
		inc(osz[u[i]]);
		inc(isz[v[i]]);
	end;
	for i := 0 to n-1 do
		f[i] := AREZOU;
	while true do
	begin
		for i := 0 to n-1 do
		begin
			if f[i] <> BORZOU then
			begin
				mark[i] := false;
				checked[i] := false;
				if a[i] = AREZOU then
					need[i] := 1
				else
					need[i] := osz[i];
			end;
		end;
		q_head := 0;
		q_tail := 0;
		fillchar(q, sizeof(q), 0);
		for i := 0 to n-1 do
		begin
			if (r[i] = 1) and (f[i] = AREZOU) then
			begin
				q[q_tail] := i; inc(q_tail);
			end;
		end;
		while q_head <> q_tail do
		begin
			front := q[q_head]; inc(q_head);
			if checked[front] = true then
				continue;
			checked[front] := true;
			pnt := tail[front][1];
			while pnt <> -1 do
			begin
				temp := u[pnt];
				dec(need[temp]);
				if (need[temp] = 0) and (mark[temp] = false) and (f[temp] = AREZOU) then
				begin
					q[q_tail] := temp; inc(q_tail);
					mark[temp] := true;
				end;
				pnt := prev[pnt][1];
			end;
		end;
		flag := false;
		for i := 0 to n-1 do
		begin
			if (f[i] = AREZOU) and (mark[i] = false) then
			begin
				f[i] := BORZOU;
				flag := true;
			end;
		end;
		if not flag then
			break;
	end;
	SetLength(who_wins, n);
	for i := 0 to n-1 do
		who_wins[i] := f[i];
end;

begin
end.

