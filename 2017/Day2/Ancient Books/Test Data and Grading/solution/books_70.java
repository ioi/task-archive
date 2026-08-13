import java.lang.*;
import java.util.*;

class books{
    
	final int maxn = 1000 + 10;
	final int inf = 1000000000;
	final int mod = 1000000007;
	long ans;
	boolean[] mark = new boolean[maxn];
	int tmpMIN,tmpMAX,n,tmp;
	int[] MIN = new int[maxn];
	int[] MAX = new int[maxn];
	int[] nex = new int[maxn];
	int[][] dp = new int[maxn][maxn];
	class Pair{
        int first, second;
        Pair(){
            first = 0;
            second = 0;
        }
        Pair(int x, int y) {
            first = x;
            second = y;
        }
        boolean cmp(Pair p) {
            if(first < p.first) return true;
            if(first > p.first) return false;
            return second < p.second;
        }
	public boolean equals(Object o) {
	    Pair p = (Pair)o;
	    return (first == p.first && second == p.second);
	}
	public int hashCode() {
	    long ret = first;
	    ret = (ret * maxn + second) % mod;
	    return (int)ret;
	}
    }
	Pair[] P = new Pair[maxn];
	public void dfs(int v,int u){
		mark[v]=true;
		tmpMIN=Math.min(tmpMIN,v);
		tmpMAX=Math.max(tmpMAX,v);
		MIN[v]=tmpMIN;
		MAX[v]=tmpMAX;
		if(nex[v]!=u) dfs(nex[v],u);
	}
	
	public int go(int l,int r){
		if(l==0 && r==n-1) return 0;
		if(dp[l][r]!=-1) return dp[l][r];
		dp[l][r]=Math.min((l==0?inf:go(P[l-1].first,Math.max(P[l-1].second,r))),(r==n-1?inf:go(Math.min(l,P[r+1].first),P[r+1].second)))+2;
		return dp[l][r];
	}

	public Pair mol(int l,int r){
		int nl=MIN[l],nr=MAX[r];
		while(nl<l || r<nr){
			if(nl<l){
				l--;
				nl=Math.min(nl,P[l].first);
				nr=Math.max(nr,P[l].second);
				l=P[l].first;
			}
			else{
				r++;
				nl=Math.min(nl,MIN[r]);
				nr=Math.max(nr,MAX[r]);
			}
		}
		return new Pair(l,r);
	}

	long minimum_walk(int[] p,int s){
		n=p.length;
		for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) dp[i][j]=-1;
		for(int i=0;i<n;i++) nex[i]=p[i];
		for(int i=0;i<n;i++){
			ans+=Math.abs(i-p[i]);
			if(!mark[i]) {
				tmpMIN=tmpMAX=i;
				dfs(i,i);
				dfs(i,i);
			}
		}
		if(ans==0) return 0;
		for(int i=0;p[i]==i && i<s;i++)
			ans-=2;
		for(int i=n-1;p[i]==i && i>s;i--)
			ans-=2;
		for(int i=0;i<n;i++) P[i]=mol(i,i);
			ans+=go(P[s].first,P[s].second);
		return ans;
	}
    
}
