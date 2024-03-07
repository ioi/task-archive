# Nowruz

Vài ngày nữa là tới Nowruz (năm mới của Ba Tư), ông nội đã mời các thành viên trong gia đình đến khu vườn của ông. Trong số đó có $k$ đứa trẻ. Để buổi gặp mặt thêm niềm vui cho trẻ nhỏ, ông nội sẽ thiết kế một trò chơi trốn tìm.

Khu vườn có thể biểu diễn bởi lưới kích thước $m \times n$ ô vuông đơn vị.
Một số (có thể là không) ô bị chặn bởi đá, và các ô còn lại được gọi là *tự do*. Hai ô được gọi là *lân cận* nếu chúng có chung cạnh. Như vậy, mỗi ô có thể có tới 4 ô lân cận: hai ô theo chiều ngang và hai ô theo chiều dọc. Ông nội muốn biến khu vườn của mình thành một mê cung. Với mục đích đó, ông có thể chặn một số ô tự do bằng cách trồng bụi cây vào đó. Các ô mà ông trồng bụi cây sẽ không còn là ô tự do nữa.

Một mê cung phải có tính chất sau đây. Đối với mỗi cặp ô tự do $a$ và $b$ trong mê cung phải có đúng một *đường đi đơn* giữa chúng. Một đường đi đơn giữa hai ô $a$ và $b$ là một dãy các ô tự do, trong đó ô đầu tiên là $a$, ô cuối cùng là $b$, tất cả các ô là phân biệt và hai ô liên tiếp là lân cận.

Một đứa trẻ có thể trốn trong một ô khi và chỉ khi ô đó là tự do và có *đúng* một ô lân cận tự do. Không có hai đứa trẻ nào trốn trong cùng một ô. 

Bạn được cho bản đồ khu vườn như là đầu vào. Nhiệm vụ của bạn là giúp ông nội tạo ra một mê cung trong đó nhiều đứa trẻ có thể trốn.

## Chi tiết cài đặt
Đây là một bài output-only với cách tính điểm thành phần. Bạn được cho $10$ file đầu vào, mỗi file mô tả khu vườn của ông nội. Đối với mỗi file đầu vào, bạn cần nộp một file đầu ra là một bản đồ của mê cung. Đối với mỗi file đầu ra, bạn sẽ nhận được điểm dựa trên số lượng đứa trẻ có thể trốn trong mê cung của bạn.

Bạn không phải nộp bất kỳ mã nguồn nào cho bài này.

## Input format

Mỗi file đầu vào mô tả một lưới biểu diễn một khu vườn và số lượng đứa trẻ $k$ được ông nội mời. Khuôn dạng như sau:
* dòng $1$: $\;\; m \;\; n \;\; k$
* dòng $1+i$ (với $1 \leq i \leq m$): hàng $i$ của lưới, là một xâu độ dài $n$, bao gồm các ký tự sau đây (không có ký tự trắng):
  - '`.`': ô tự do,
  - '`#`': ô có đá.

## Output format

* Dòng $i$ (với $1 \leq i \leq m$): dòng $i$ của mê cung (khu vườn sau khi các bụi cây được trồng). Là một xâu độ dài $n$, bao gồm các ký tự sau đây (không có ký tự trắng):
  -  '`.`': ô tự do,
  -  '`#`': ô có đá,
  -  '`X`': ô có bụi cây. (Chú ý rằng ký tự X phải là ký tự in hoa.)

## Ràng buộc

* $1 \leq m, n \leq 1024$

## Scoring

Một file đầu ra được coi là *hợp lệ* nếu tất cả các điều kiện sau được thỏa mãn:
* Bản đồ đầu ra phải khớp với bản đồ đầu vào với ngoại lệ duy nhất là một số bất kỳ các ký tự '`.`' trong bản đồ đầu vào có thể được thay đổi thành ký tự '`X`' (ô bị chặn bởi bụi cây).
* Bản đồ đầu ra phải có tính chất của một mê cung đã được định nghĩa trong phát biểu bài toán.

Nếu đầu ra của bạn cho một bộ dữ liệu là không hợp lệ, điểm số của bạn cho bộ dữ liệu đó sẽ là $0$. Trái lại, điểm số sẽ là $\min(10, 10 \cdot l/k)$ điểm, được làm tròn xuống đến hai chữ số sau dấu chấm thập phân. Ở đây, $l$ là số đứa trẻ có thể trốn trong mê cung đầu ra của bạn, và $k$ là số được cho trong đầu vào. Bạn sẽ đạt được điểm $10$ cho một bộ dữ liệu nếu và chỉ nếu đầu ra của bạn là một mê cung, trong đó có $k$ đứa trẻ hoặc nhiều hơn có thể trốn. Đối với mỗi bộ dữ liệu, luôn tồn tại một phương án đạt $10$ điểm.

Lưu ý rằng nếu phương án của bạn hợp lệ nhưng vẫn đạt điểm $0$ theo công thức trên, thông báo chấm điểm mà bạn thấy trong CMS sẽ là 'Wrong Answer'.

## Example

Xem ví dụ đầu vào sau:

```
4 5 5
....#
.#..#
...#.
....#
```

Dưới đây là một đầu ra hợp lệ:

```
.X.X#
.#..#
...#X
XX..#
```

Vì $l=4$ đứa trẻ có thể trốn trong mê cung này, phương án này sẽ nhận được $10 \cdot 4 / 5 = 8$ điểm. Các ô mà đứa trẻ có thể trốn được đánh dấu bằng  `O` dưới đây:

```
OXOX#
.#.O#
...#X
XX.O#
```

Ba đầu ra dưới đây là không hợp lệ:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

Trong đầu ra bên trái không có đường đi đơn giữa ô tự do nằm ở góc trên cùng bên trái và ô tự do nằm ở cột phải nhất. Trong hai đầu ra còn lại, cho mỗi cặp ô tự do khác biệt có đúng hai đường đi đơn phân biệt giữa chúng.
