import java.lang.*;

class books {
	private static final int MAX = 1000005;
	int[] le = new int[MAX];
	int[] ri = new int[MAX];
	int[] pos = new int[MAX];
	int[] mark = new int[MAX];
	int l,r;
	public int val(int x){
		return ( x > 0 ? x : -x);
	}
	public void go(int nl,int nr){
		while (nl < l || r < nr)
            if (nl != l){
                l--;
                nl = Math.min(nl, le[l]);
                nr = Math.max(nr, ri[l]);
            }
            else{
                r++;
                nl = Math.min(nl, le[r]);
                nr = Math.max(nr, ri[r]);
            }
    }
    public int dist(int s, int t){
        if (s == t)
            return 0;
        int ns = s;
        if (t < s)
		{
            while (s >= ns)
            {
                ns = Math.min(ns, le[s]);
                s--;
                if (ns <= t)
                    return 0;
            }
        }
        else
        {
            while (s <= ns)
            {
                ns = Math.max(ns, ri[s]);
                s++;
                if (ns >= t)
                    return 0;
            }
        }
        return dist(s, t) + 2;
    }
    public long minimum_walk(int[] p, int s)
    {
        int n = p.length;
        long ans = 0;
        for (int i = 0; i < n; i++)
            ans += val(i - p[i]);
        for (int i = 0; i < n; i++)
            le[i] = ri[i] = i;
        for (int i = 0; i < n; i++)
            pos[p[i]] = i;
        for (int i = 0; i < n; i++)
            if (mark[i]==0)
            {
                int v = i;
                while (mark[v] < 2)
                {
                    le[v] = Math.min(le[v], le[p[v]]);
                    ri[v] = Math.max(ri[v], ri[p[v]]);
                    mark[v]++;
                    v = pos[v];
                }
            }
        int gl = 0;
        while (gl < s && p[gl] == gl)
            gl++;
        int gr = n - 1;
        while (gr > s && p[gr] == gr)
            gr--;
        l = s + 1;
		r = s;
        go(s, s);
        boolean done = false;
        while (gl < l || r < gr)
        {
            int nl = l, nr = r;
            if (!done)
            {
                while (nl >= 0 && ri[nl] <= r)
                    nl--;
            }
            if (nl == -1)
                done = true;
            if (done)
            {
                nl = l;
                if (l <= gl)
                {
                    nr++;
                    ans += 2;
                }
                else
                {
                    nl--;
                    ans += 2;
                }
            }
            else
            {
                while (l <= le[nr])
                    nr++;
                ans += Math.min(dist(l - 1, nl), dist(r + 1, nr)) + 2;
            }
            go(nl, nr);
        }
        return ans;
    }
}
