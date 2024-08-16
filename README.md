## Bài 1
### Compiler
- Compiler là một phần mềm để biên dịch một hay nhiều chương trình được viết từ ngôn ngữ bậc cao(ngôn ngữ C, C++, python,..) sang ngôn ngữ bậc thấp (thường là ngôn ngữ nhị phân) để nạp cho MCU hoặc máy tính. Hay nói cách khác compiler giống như một thông dịch viên giữa người lập trình và máy tính hoặc MCU.
### Compiler Process 
**Quá trình biên dịch trải qua 4 giai đoạn chính:**
* **Preprocessing**
Quá trình này sẽ biên dịch các file.c hoặc các file.cpp thành các file.i. Ở quá trình này sẽ loại bỏ tất cả các comment, thêm tất cả nột dung của thư viện đã được include ở file.c hoặc file .cpp nếu có và các macro nếu được define thành một file.i.
* **Compilation**
Quá trình này sẽ biên dịch các file.i thành các file.s. Quá trình này là chuyển đổi ngôn ngữ C của chúng ta thành ngôn ngữ assembly code (hợp ngữ). Hợp ngữ có thể được hiểu như là một loại ngôn ngữ của từng loại xử lý mà nhà sản xuất đã viết ra khi thiết kế ra dòng vi xử lý đó để người dùng có thể thuận tiện giao tiếp hơn. Vì vậy mỗi loại vi xử lý khác nhà sản xuất thì sẽ có hợp ngữ khác nhau.
* **Assemble**
Quá trình này sẽ biên dịch các file.s thành các file.o. Quá trình này chuyển đổi assembly code thành object code (mã máy). Vì máy tính bản chất là các bóng bán dẫn điển tử (transistor) nên chúng chỉ hiểu thành các bit logic 0 và 1 để thực hiện các nhiệm vụ.
* **Linhking**
Quá trình này sẽ biên dịch các file .o đã tạ ra trước đó thành một file duy nhất file. exe (executable machine code) hoặc file.hex để nạp cho một số dòng vi điều khiển. 
![Compiler Process](/Image/1.png)*Compiler Process*
### MACRO

Macro là một cơ chế của quá trình tiền xử lý có thể được hiểu là chúng ta sẽ định nghĩa lại nội dụng thành một đoạn nội dung khác ngắn gọn hơn.
MACRO chia thành 3 nhóm chính: 
>`#include`                                                  
>`#define,#undef`
>`#if,#elif,#else,#ifdef,#ifndef`
>

**Có một số macro sau:**

- **#include**
    - Cho phép chèn nội dung của  tệp khác vào tệp hiện tại trước khi biên dịch.
    - Sử dụng dấu '< >' cho các tệp tiêu chuẩn như các tệp tiêu đề header file trong các thư mục mục thư viện chuẩn của hệ thống.
    - Sử dụng dấu ' " " ' cho các tệp của người dùng.

- **#define**

    -   Để định nghĩa macro chúng ta dùng cú pháp như sau:

	    `#define Tên_macro  giá_trị_hoặc_đoạn_mã`

    - Các loại macro gồm:

         **Macro có tham số:** Có thể nhận tham số và thực hiện thao tác trên những tham số đó.

	    `#define SQUARE(x) ((x) * (x))`

        **Macro không tham số:** Định nghĩa một giá trị cố định

	    `#define PI 3.14159`

        Để loại bỏ macro ta sử dụng #undef

    **`#if`**
    -  Nếu điều kiện này đúng thì thực hiện đoạn mã phía dưới.

    **`#elif`**
    -  Được sử dụng sau #if hoặc #elif để kiểm tra điều khiện thêm nếu điều kiện trước sai.

    **`#else`**
    - Nếu không có điều kiện nào trước đó đúng thì sẽ thực hiện các câu lệnh sau #else.

    **`#ifdef`**
    - Dùng để kiểm tra xem macro đã được định nghĩa hay chưa.

    **`#ifndef`**
    - Dùng để kiểm tra xem macro chưa được định nghĩa.

**Variadic macros**
macro variadic được sử dụng để định nghĩa ra hàm khi ta không xác định được chính xác input đầu vào. Khi đó ta có #define func(...) dấu 3 chấm sẽ được định nghĩa thành __VA_ARGS__
## Bài 2

### Thư viện stdarg.h
- Cung cấp các phương thức để làm việc với các hàm có số lượng input 
parameter không cố định.

### Các macro chính trong thư viện:
- **Va_list**
	
	- Dùng để khai báo 1 biến kiểu dữ liệu lưu trữ thông tin của danh sách đối số biến đổi

	- Cú pháp: `va_list args;`
	
- **Va_start()**
	
	- Dùng để khởi tạo biến lưu trữ danh sách kiểu va_list vừa lưu.

	- Cú pháp: `va_start( args, last_fixed_agr);`

	- ` last_fixed_agr ` là đối số cố định cuối cùng trước khi bắt đầu danh sách đối số biến thiên.

	- Ở đây sẽ bắt đầu trỏ từ đối số đầu tiên sau   `last_fixed_agr`

- **Va_arg()**
	
	- Dùng để truy xuất từng đối số trong danh sách đối số biến đổi.

	- Mỗi lần gọi sẽ truy xuất trả về đối số tiếp theo và di chuyển con trỏ tới đối số kế tiếp.

	- Cú pháp:`va_agr(args, int);`

- **Va_end()**

	- Dùng để kết thúc việc sử dụng danh sách đối số biến đổi, dọn sạch đối tượng va_list và giải phóng tài nguyên.

	- Cú pháp:`va_end(args);`


### Thư viện Assert.h?

 - Dùng để kiểm tra một điều kiện trong mã nguồn và phát hiện lỗi.

 - Thư viện cung cấp 1 macro assert kiểm tra một điều kiện luôn luôn đúng. Nếu sai thì chương trình sẽ dừng và báo lỗi.
 
    - Cú pháp: `assert(biểu_thức);`