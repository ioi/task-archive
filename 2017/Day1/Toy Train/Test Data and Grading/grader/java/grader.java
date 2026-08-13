import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;

public class grader {
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		// BEGIN SECRET
		final String input_secret = "3d2051c242fe2ae63792f9868123a5eb";
		final String output_secret = "d16905a4427c193ad87ae7fa91a2bb55";
		String secret = in.readString();
		if(!input_secret.equals(secret)) {
			System.out.println(output_secret);
			System.out.println("SV");
			System.out.close();
			System.exit(0);
		}
		// END SECRET
		int n = in.readInt();
		int m = in.readInt();

		int[] a = new int[n];
		int[] r = new int[n];
		int[] u = new int[m];
		int[] v = new int[m];

		for(int i = 0; i < n; i++)
			a[i] = in.readInt();

		for(int i = 0; i < n; i++)
			r[i] = in.readInt();

		for(int i = 0; i < m; i++) {
			u[i] = in.readInt();
			v[i] = in.readInt();
		}

		int[] res = new train().who_wins(a, r, u, v);

		// BEGIN SECRET
		System.out.println(output_secret);

		if(res.length != n) {
			System.out.println("OK");
			System.out.println("Wrong returned array size");
		} else
			System.out.println("OK");
		// END SECRET
		if (res != null) {
			for (int i = 0; i < res.length; i++) {
				System.out.print((i > 0 ? " " : "") + res[i]);
			}
		}

		System.out.println();
	}

}

class InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1) {
			throw new InputMismatchException();
		}
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0) {
				return -1;
			}
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = read();
		while (isSpaceChar(c)) {
			c = read();
		}
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9') {
				throw new InputMismatchException();
			}
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public String readString() {
		int c = eatWhite();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private int eatWhite() {
		int c = read();
		while (isSpaceChar(c)) {
			c = read();
		}
		return c;
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
}
