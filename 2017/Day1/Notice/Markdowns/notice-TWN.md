# 注意事項 Notice

每一個任務在CMS與你的電腦中都有一個附加包裹檔案。

對於"Output-only" 任務：
* 附加包裹檔案中包含輸入測資與範例測資。每一個測試資料是個別的一個子任務。
* 你可以用zip檔一次繳交多個輸出檔案，若要如此做，你的輸出檔案必須命名為`??.out`, 其中`??` 是測資編號 (例如 `03.out`)。你可以使用命令`zip output.zip *.out`來zip打包多個檔案。
* 對於output-only的任務，你可以最多繳交100次。每一次可以上傳所有測資的任意子集合的輸出檔案。

對於其他任務：
* 附加包裹檔案中包含sample graders, sample implementations, 範例測資,以及編譯命令(compile scripts)。
* 你必須上傳恰好一個檔案，你可以最多上傳50次繳交。
* 你上傳的程式不可以從標準輸入做讀取，不可輸出至標準輸出，也不可與任何其他檔案互動。然而，可以輸出到standard error stream。
* 你應上傳繳交的檔案名稱在題目描述的標題中給定，它必須實作題目敘述中的函式並且遵循在 sample implementations中提供的函式原型(signature)。
* 你可以視需要實作其他函式。
* 當使用sample grader測試你的程式時，你的輸入必須符合題目敘述中的格式與限制，否則可能發生不在預期中的行為。


## Conventions

題目描述均使用一般的資料型態名稱  `bool`, `integer`, `int64`, and `int[]` (array).

對於每一種提供的程式語言，評分程式使用以下的資料型態與實現：

Language | `bool` | `integer` | `int64` |  `int[]` | length of array `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limits

Task | Time limit | Memory limit
--- | --- | ---
nowruz | Output-only | Output-only
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB

