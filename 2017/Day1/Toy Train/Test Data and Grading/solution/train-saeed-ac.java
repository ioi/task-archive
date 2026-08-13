import java.util.Queue;
import java.util.LinkedList;
import java.io.*;

public class train {

	final static int B = 0;
	final static int A = 1;

    public int[] who_wins(int[] a, int[] r, int[] u, int[] v) {
		
		boolean[] mark = new boolean[a.length];
		boolean[] checked = new boolean[a.length];
		int[] need = new int[a.length];
		int[] f = new int[a.length];
		int[][] tail = new int[a.length][2];
		int[][] prev = new int[u.length][2];
		int[] osz = new int[a.length];
		int[] isz = new int[a.length];

		for (int i = 0; i < a.length; i++) {
			tail[i][0] = -1;
			tail[i][1] = -1;
		}

		for (int i = 0; i < u.length; i++) {
			prev[i][0] = tail[u[i]][0];
			tail[u[i]][0] = i;
			prev[i][1] = tail[v[i]][1];
			tail[v[i]][1] = i;
			osz[u[i]]++;
			isz[v[i]]++;
		}

		for (int i = 0; i < a.length; i++)
			f[i] = A;

		int[] q = new int[a.length];
		while (true) {
			for (int i = 0; i < a.length; i++) if (f[i] != B) {
				mark[i] = false;
				checked[i] = false;
				if (a[i] == A)
					need[i] = 1;
				else
					need[i] = osz[i];
			}
			int qtail = 0;
			for (int i = 0; i < a.length; i++) if (r[i] == 1 && f[i] == A)
				q[qtail++] = i;
			while (qtail > 0) {
				int front = q[--qtail];
				if (checked[front] == true)
					continue;
				checked[front] = true;
				int pnt = tail[front][1];
				while (pnt != -1){
					int temp = u[pnt];
					--need[temp];
					if (need[temp] == 0 && mark[temp] == false && f[temp] == A) {
						q[qtail++] = temp;
						mark[temp] = true;
					}
					pnt = prev[pnt][1];
				}
			}
			boolean flag = false;
			for (int i = 0; i < a.length; i++) if (f[i] == A && mark[i] == false) {
				f[i] = B;
				flag = true;
			}
			if (flag == false)
				break;
		}
		return f;
    }
}

