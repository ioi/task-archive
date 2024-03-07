# Notice

Mỗi bài có một gói gắn kèm có thể tìm thấy trên cả CMS lẫn máy của bạn.

Đối với bài "Output-only":
* Gói gắn kèm chứa các input test cases và các test cases ví dụ.
Mỗi test case là một subtask riêng rẽ.
* Bạn phải nộp các file output dưới dạng file zip. Để thực hiện điều này, các file output của bạn phải được đặt tên `??.out`, trong đó `??` là chỉ số của test case (ví dụ, `03.out`). Bạn cần nén (zip) các file sử dụng lệnh: `zip output.zip *.out`
* Bạn có thể thực hiện nộp không quá 100 lần đối với bài output-only. Mỗi lần nộp, bạn có thể nộp file output cho mọi tập con của tập các test cases.

Đối với các bài khác:
* Gói gắn kèm chứa trình chấm mẫu, cài đặt ví dụ, các ví dụ dữ liệu, và kịch bản biên dịch.
* Bạn phải nộp đúng một file và bạn có thể nộp không quá 50 lần.
* Trình nộp của bạn không được đọc dữ liệu từ thiết bị vào chuẩn, in ra thiết bị ra chuẩn hoặc giao tiếp với bất cứ file nào khác
Tuy nhiên, có thể output ra dòng lỗi chuẩn.
* Tên của file mà bạn phải nộp được cho trong tiêu đề của bài.
Cần phải cài đặt thủ tục mô tả trong phát biểu của bài sử dụng ký hiệu được cung cấp trong các cài đặt ví dụ.
* Bạn được phép cài đặt thêm các thủ tục khác.
* Khi test thử các chương trình của bạn với trình chấm mẫu,
dữ liệu của bạn cần đáp ứng về khuôn dạng và ràng buộc như mô tả trong đầu bài, nếu không có thể có những kết quả bất thường.

## Conventions

Các phát biểu yêu cầu sử dụng kiểu dữ liệu  `bool`, `integer`, `int64`, và `int[]` (mảng).

Trong mỗi ngôn ngữ lập trình, trình chấm mẫu sử dụng kiểu dữ liệu hay cách cài đặt thích hợp như mô tả trong bảng dưới đây:

Ngôn ngữ | `bool` | `integer` | `int64` |  `int[]` | độ dài mảng `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Các giới hạn

Task | Time limit | Memory limit
--- | --- | ---
nowruz | Output-only | Output-only
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB
