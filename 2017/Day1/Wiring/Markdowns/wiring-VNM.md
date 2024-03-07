# Wiring

Maryam là kỹ sư điện.
Cô đang thiết kế kết nối trên một tháp truyền thông.
Trên tháp có một số điểm kết nối nằm ở các độ cao khác nhau.
Một đoạn dây có thể sử dụng để nối hai điểm kết nối.
Mỗi điểm kết nối có thể được nối với một số lượng tùy ý các đoạn dây.
Có hai loại điểm kết nối: đỏ và xanh.

Đối với mục đích của bài toán này tháp có thể xem như một đường thẳng và các điểm kết nối là các điểm màu xanh và đỏ đặt tại các tọa độ nguyên không âm trên đường thẳng này.
Độ dài của đoạn dây là khoảng cách giữa hai điểm kết nối được nối bởi nó.

Mục đích của bạn là giúp Maryam tìm sơ đồ kết nối sao cho:
1. Mỗi điểm kết nối có ít nhất một đoạn dây nối với một điểm kết nối khác màu.
1. Tổng độ dài của các đoạn dây kết nối là nhỏ nhất.

## Chi tiết cài đặt

Bạn cần cài đặt thủ tục sau đây:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: mảng độ dài $n$ chứa các vị trí của các điểm kết nối màu đỏ theo thứ tự tăng dần.
* $b$: mảng độ dài $m$ chứa các vị trí của các điểm kết nối màu xanh theo thứ tự tăng dần.
* Thủ tục này cần trả lại tổng độ dài nhỏ nhất của các đoạn dây nối trong số tất cả các sơ đồ kết nối hợp lệ.
* Chú ý là kiểu của giá trị trả lại của thủ tục này là `int64`.

## Ví dụ

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Hình vẽ sau đây minh họa cho ví dụ này.
![Wiring](wiring.png)
* Tháp được vẽ nằm ngang.
* Trong dạng in đen trắng của phát biểu bài toán các điểm kết nối màu đỏ được thể hiện bởi màu tối còn các điểm kết nối màu xanh được thể hiện bởi màu sáng.
* Tất cả có $4$ điểm kết nối màu đỏ ở đặt ở các vị trí $1, 2, 3,$ và $7$.
* Tất cả có $5$ điểm kết nối màu xanh đặt ở các vị trí $0, 4, 5, 9,$ và $10$.
* Một lời giải tối ưu được thể hiện trong hình vẽ trên.
* Trong lời giải này tổng độ dài của các đoạn dây nối là $1 + 2 + 2 + 2 + 3 = 10$, và là tối ưu.
Do đó, thủ tục phải trả lại $10$.
* Chú ý là có hai đoạn dây nối liên kết với điểm kết nối ở vị trí $7$.

## Ràng buộc

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (với mọi $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (với mọi $0 \leq i \leq m-1$),
* Mỗi mảng $r$ và $b$ được sắp xếp theo thứ tự tăng dần.
* Tất cả $n+m$ giá trị của các mảng $r$ và $b$ là đôi một khác nhau.

## Subtasks

1. (7 điểm) $n, m \leq 200$,
1. (13 điểm) Tất cả các điểm kết nối màu đỏ có vị trí nhỏ hơn so với mọi điểm kết nối màu xanh.
1. (10 điểm) Có ít nhất một điểm kết nối màu đỏ và một điểm kết nối màu xanh trong số mỗi dãy $7$ điểm kết nối liên tiếp.
1. (25 điểm) Tất cả các điểm kết nối có vị trí khác nhau ở trong khoảng $[1, n+m]$.
1. (45 điểm) Không có ràng buộc bổ sung.

## Trình chấm mẫu

Trình chấm mẫu đọc dữ liệu theo khuôn dạng sau đây:
* dòng $1$: $\;\; n \;\; m$
* dòng $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* dòng $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Trình chấm mẫu in ra trên một dòng duy nhất giá trị trả lại của `min_total_length`.