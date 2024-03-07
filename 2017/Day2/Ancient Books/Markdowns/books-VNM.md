# Ancient Books

Thành phố Tehran là nơi đặt Thư viện Quốc gia của Iran.
Kho báu chính của thư viện này được đặt trong một phòng dài với một dãy gồm $n$ cái bàn được đánh số từ $0$ đến $n-1$, từ trái qua phải.
Trên mỗi cái bàn có một quyển sách cổ viết tay đang được trưng bày.
Các quyển sách này được xếp thứ tự dựa trên tuổi của chúng và điều đó gây khó khăn cho khách thăm quan muốn tìm kiếm sách theo tiêu đề.
Do đó người điều hành thư viện đã quyết định sắp xếp lại các cuốn sách theo thứ tự từ điển của tiêu đề.

Aryan là nhân viên thư viện chuẩn bị thực hiện công việc này.
Anh đã lập một danh sách $p$ độ dài $n$ gồm các số nguyên khác nhau trong khoảng từ $0$ đến $n-1$.
Danh sách này mô tả sự thay đổi cần thiết để phân bố lại các cuốn sách theo thứ tự từ điển: với mọi $0 \leq i < n$, quyển sách hiện đang ở bàn $i$ phải được di chuyển đến bàn $p[i]$.

Aryan bắt đầu sắp xếp các quyển sách tại bàn $s$.
Anh muốn quay trở lại bàn này sau khi kết thúc công việc sắp xếp.
Do các quyển sách là rất quí giá nên ở mỗi thời điểm anh không thể mang theo nhiều hơn một quyển.
Khi sắp xếp các quyển sách Aryan sẽ thực hiện một dãy các thao tác.
Mỗi thao tác phải thuộc một trong các thao tác sau:
* Nếu anh đang không mang theo sách và trên mặt bàn cạnh anh (bàn tại vị trí anh đang đứng) có sách, thì anh có thể nhặt cuốn sách này lên.
* Nếu anh đang mang theo sách và có một quyển sách khác đang ở trên bàn cạnh anh, thì anh có thể đổi quyển sách đang mang với quyển sách trên bàn.
* Nếu anh đang mang theo sách và trên mặt bàn cạnh anh không có sách, thì anh có thể đặt quyển sách đang mang theo xuống mặt bàn này.
* Anh có thể di chuyển đến bất cứ bàn nào. Anh có thể mang theo một quyển sách duy nhất khi di chuyển.

Với mọi $0 \leq i, j \leq n - 1$, khoảng cách giữa hai bàn $i$ và $j$ đúng bằng $|j-i|$ mét. Nhiệm vụ của bạn là tính tổng khoảng cách nhỏ nhất mà Aryan cần di chuyển để thực hiện việc sắp xếp tất cả các quyển sách.

## Chi tiết cài đặt

Bạn cần cài đặt thủ tục sau đây:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ là mảng độ dài $n$.
Quyển sách trên bàn $i$ lúc bắt đầu cần được Aryan di chuyển đến bàn $p[i]$ (với mọi $0 \leq i < n$).
* $s$ là chỉ số của bàn mà  Aryan đứng cạnh lúc bắt đầu và cũng là nơi anh ta phải quay lại sau khi sắp xếp xong các quyển sách.
* Thủ tục này cần trả lại tổng khoảng cách nhỏ nhất (tính bởi mét) mà Aryan cần di chuyển để thực hiện việc sắp xếp các quyển sách.

## Ví dụ

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

Trong ví dụ này $n=4$ và Aryan đứng cạnh bàn $0$ lúc bắt đầu.
Anh ta thực hiện sắp xếp các quyển sách như sau:
* Anh di chuyển đến bàn $1$ nhặt lên quyển sách trên bàn này. Quyển sách này cần được đặt lên bàn $2$.
* Tiếp theo, anh di chuyển đến bàn $2$ và đổi quyển sách đang mang theo với quyển sách trên bàn này.
Quyển sách mới anh đang mang theo này phải được đặt vào bàn $3$.
* Tiếp theo, anh di chuyển đến bàn $3$ và đổi quyển sách đang mang theo với quyển sách trên bàn này.
Quyển sách mới anh đang mang theo này phải được đặt ở bàn $1$.
* Tiếp theo, anh di chuyển đến bàn $1$ và đặt quyển sách đang mang theo xuống bàn này.
* Cuối cùng anh di chuyển quay về bàn $0$.

Để ý là quyển sách đang ở bàn  $0$ là đã ở đúng vị trí, bàn $0$, vì thế Aryan không phải nhặt nó lên.
Tổng khoảng cách đường di chuyển là $6$ mét.
Đây là phương án tối ưu, vì vậy, thủ tục cần trả lại $6$.

## Ràng buộc

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* Mảng $p$ chứa $n$ số nguyên phân biệt trong khoảng giữa $0$ và $n-1$, kể cả hai đầu mút.

## Subtasks

1. (12 points) $n \le 4$ và $s = 0$
1. (10 points) $n \le 1000$ và $s = 0$
1. (28 points) $s = 0$
1. (20 points) $n \le 1000$
1. (30 points) không có ràng buộc bổ sung

## Trình chấm mẫu

Trình chấm mẫu đọc dữ liệu theo khuôn dạng sau:

- dòng $1$: $\;\; n \;\; s$
- dòng $2$: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

Trình chấm mẫu ghi kết quả ra một dòng chứa giá trị trả lại của `minimum_walk`.
