# Toy Train

Arezou và cậu em trai  Borzou là hai chị em sinh đôi.
Họ được tặng một bộ đồ chơi tầu hoả cho ngày sinh nhật của mình, và họ dùng nó để xếp một hệ thống đường tầu với $n$ ga tầu và $m$ đường ray *một chiều*.
Các ga tầu được đánh số thứ tự từ $0$ đến $n-1$.
Mỗi đường ray xuất phát từ một ga tầu và kết thúc tại chính ga tầu đó hoặc một ga tầu khác. 
Có ít nhất một đường ray xuất phát từ mỗi ga tầu. 

Một vài ga tầu là *ga nạp pin*.
Khi tầu đến một ga nạp pin, nó sẽ được nạp đầy pin. 
Tầu nạp đầy pin sẽ có đủ năng lượng để đi hết  $n$ đường ray liên tiếp.
Có nghĩa là tầu sẽ hết năng lượng khi vừa đi đến đường ray thứ $(n+1)$ sau lần nạp pin gần nhất. 

Tại mỗi ga tầu, có một nút điều khiển có thể trỏ đến bất kỳ đường ray nào xuất phát tại ga đó. 
Khi tầu đang ở tại một ga, nó rời ga theo đường ray được trỏ bởi nút điều khiển tại ga đó. 

Hai chị em sinh đôi sẽ chơi một trò chơi với chiếc tầu của họ. 
Họ phân chia tất cả các ga tầu cho nhau: mỗi ga tầu thuộc sở hữu của Arezou hoặc Borzou.
Chỉ có một chiếc tầu.
Tại thời điểm bắt đầu trò chơi, tầu ở ga  $s$ và nó được nạp đầy pin. 
Để bắt đầu trò chơi, người sở hữu ga  $s$ trỏ nút điều khiển tại ga $s$ đến một trong các đường ray xuất phát từ ga $s$.
Sau đó, họ cho tầu chạy và tầu bắt đầu chạy theo các đường ray. 

Mỗi khi tầu vào một ga lần đầu tiên, người sở hữu ga tầu thiết lập nút điều khiển tại ga đó. 
Một khi nút điều khiển được thiết lập, nó sẽ giữ nguyên như vậy trong suốt trò chơi. 
Vì vậy, nếu tầu quay lại một ga nó đã đến trước đây, nó sẽ rời ga đó theo đúng đường ray cũ. 

Vì chỉ có một số lượng hữu hạn các ga tầu, cuối cùng tầu sẽ chạy theo một *chu trình*.
Một chu trình là một dãy các ga *đôi một khác nhau* $c[0], c[1], \cdots, c[k-1]$ sao cho tầu rời ga $c[i]$ (với $0 \leq i < k-1$) sử dụng một đường ray đi đến ga $c[i+1]$, và nó rời ga $c[k-1]$ sử dụng đường ray đi đến ga $c[0]$.
Lưu ý là chu trình có thể chỉ gồm một ga tầu (tức là $k=1$) nếu như tầu rời ga $c[0]$ bằng đường ray quay trở lại ga $c[0]$.

Arezou thắng cuộc nếu tầu tiếp tục đi vô hạn, và Borzou thắng cuộc nếu tầu hết pin. 
Nói một cách khác, nếu có ít nhất một ga nạp pin trong số các ga $c[0], c[1], \cdots, c[k-1]$, tầu có thể nạp pin và đi theo chu trình vô hạn thì Arezou thắng cuộc.
Ngược lại, tầu sẽ hết pin (có thể sau khi đã đi theo chu trình vài vòng), và Borzou thắng cuộc.

Bạn được cho mô tả của hệ thống đường tầu. 
Arezou và Borzou sẽ chơi $n$ trò chơi.
Tại trò chơi thứ $s$, với $0 \leq s \leq n-1$, ban đầu tầu sẽ ở ga $s$.
Nhiệm vụ của bạn là, với mỗi trò chơi, xác định xem liệu có một chiến thuật chơi cho Arezou để đảm bảo rằng cô ấy sẽ thắng cuộc, bất kể Borzou chơi thế nào.

## Chi tiết cài đặt

Bạn phải cài đặt các thủ tục sau:

```
int[] who_wins(int[] a, int[] r, int[] u, int[] v)
```

* $a$: mảng độ dài $n$. Nếu Arezou sở hữu ga $i$, $a[i] = 1$. Ngược lại, Borzou sở hữu ga $i$ và $a[i] = 0$.
* $r$: mảng độ dài $n$. Nếu ga $i$ là ga nạp pin, $r[i] =1$. Ngược lại, $r[i] = 0$.
* $u$ và $v$: các mảng độ dài $m$.
Với mọi $0 \leq i \leq m-1$, có một đường ray một chiều xuất phát từ ga $u[i]$ và kết thúc tại ga $v[i]$.
* Thủ tục này trả về mảng $w$ độ dài $n$.
Với mỗi $0 \leq i \leq n-1$, giá trị của $w[i]$ là $1$ nếu Arezou có thể thắng trò chơi bắt đầu tại ga $i$, bất kể Borzou chơi như thế nào.
Ngược lại, giá trị của $w[i]$ là $0$.

## Ví dụ 

```
who_wins([0, 1], [1, 0], [0, 0, 1, 1], [0, 1, 0, 1])
```

![Train](train.png)

* Có $2$ ga tầu.
Borzou sở hữu ga $0$, là ga nạp pin.
Arezou sở hữu ga $1$, không phải là ga nạp pin.
* Có  $4$ đường ray $(0, 0), (0, 1), (1, 0)$, và $(1, 1)$, trong đó $(i, j)$ là đường ray một chiều từ ga $i$ đến ga $j$.
* Xét trò chơi mà ban đầu tầu được đặt tại ga $0$.
Nếu Borzou thiết lập nút điều khiển tại ga $0$ trỏ đến đường ray $(0, 0)$, tầu sẽ chạy vô hạn theo chu trình qua đường ray này (lưu ý ga $0$ là ga nạp pin).
Trong trường hợp này, Arezou thắng.
Ngược lại, nếu Borzou thiết lập nút điều khiển tại ga $0$ trỏ đến đường ray $(0, 1)$, Arezou có thể thiết lập nút điều khiển tại ga $1$ trỏ đến đường ray $(1, 0)$.
Nếu theo cách này, tầu sẽ chạy vô hạn theo chu trình chạy qua hai ga. Một lần nữa Arezou thắng, vì ga $0$ là ga nạp pin và tàu sẽ không dừng lại.
Vì vậy,  Arezou có thể thắng cuộc chơi, bất kể Borzou chơi như thế nào.
* Bằng lập luận tương tự, với trò chơi bắt đầu tại ga $1$ Arezou có thể thắng bất kể Borzou chơi như thế nào. Vì vậy, thủ tục phải trả về  $[1, 1]$.

## Các ràng buộc

* $1 \leq n \leq 5000$.
* $n \leq m \leq 20\,000$.
* Có ít nhất một ga nạp pin. 
* Có ít nhất một đường ray xuất phát từ mỗi ga.
* Có thể có đường ray xuất phát và kết thúc tại cùng một ga tầu (tức là, $u[i] = v[i]$).
* Các đường ray đôi một khác nhau. 
Nói một cách khác, không có hai chỉ số $i$ và $j$ $(0 \leq i < j \leq m-1)$ mà $u[i]=u[j]$ và $v[i]=v[j]$.
* $0 \leq u[i], v[i] \leq n-1$ (với mọi $0 \leq i \leq m-1$).

## Subtasks

1. (5 points) Với mọi $0 \leq i \leq m-1$, hoặc $v[i] = u[i]$ hoặc $v[i] = u[i] + 1$.
1. (10 points) $n \leq 15$.
1. (11 points) Arezou sở hữu tất cả các ga tầu.
1. (11 points) Borzou sở hữu tất cả các ga tầu.
1. (12 points) Chỉ có một ga nạp pin duy nhất.
1. (51 points) Không có ràng buộc nào thêm.

## Chương trình chấm mẫu

Chương trình chấm mẫu đọc dữ liệu đầu vào theo khuôn dạng sau:
* dòng $1$: $\;\; n \;\; m$
* dòng $2$: $\;\; a[0] \;\; a[1] \; \ldots\; a[n-1]$
* dòng $3$: $\;\; r[0] \;\; r[1] \; \ldots\; r[n-1]$
* dòng $4 + i$ (for $0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$

Chương trình chấm mẫu in ra giá trị trả về của `who_wins` theo khuôn dạng sau:
* dòng $1$: $\;\; w[0] \;\; w[1] \; \ldots\; w[n-1]$
