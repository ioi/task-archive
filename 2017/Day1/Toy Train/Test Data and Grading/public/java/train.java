public class train {

	public int[] who_wins(int[] a, int[] r, int[] u, int[] v) {
		int[] res = new int[a.length];
		for(int i = 0; i < a.length; i++)
			res[i] = i % 2;
		return res;
	}
}
