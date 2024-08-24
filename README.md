## Bài 1:
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
``` bash
    #include                                             
    #define,#undef
    #if,#elif,#else,#ifdef,#ifndef`
```

**Có một số macro sau:**

- **#include**
    - Cho phép chèn nội dung của  tệp khác vào tệp hiện tại trước khi biên dịch.
    - Sử dụng dấu '< >' cho các tệp tiêu chuẩn như các tệp tiêu đề header file trong các thư mục mục thư viện chuẩn của hệ thống.
    - Sử dụng dấu ' " " ' cho các tệp của người dùng.

- **#define**

    -   Để định nghĩa macro chúng ta dùng cú pháp như sau:

	    ```#define Tên_macro  giá_trị_hoặc_đoạn_mã```

    - Các loại macro gồm:

         **Macro có tham số:** Có thể nhận tham số và thực hiện thao tác trên những tham số đó.

	    ```#define SQUARE(x) ((x) * (x))```

        **Macro không tham số:** Định nghĩa một giá trị cố định

	    ```#define PI 3.14159```

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
## Bài 2:

### Thư viện stdarg.h
- Cung cấp các phương thức để làm việc với các hàm có số lượng input 
parameter không cố định.

### Các macro chính trong thư viện:
- **Va_list**
	
	- Dùng để khai báo 1 biến kiểu dữ liệu lưu trữ thông tin của danh sách đối số biến đổi

	- Cú pháp: ```va_list args;```
	
- **Va_start()**
	
	- Dùng để khởi tạo biến lưu trữ danh sách kiểu va_list vừa lưu.

	- Cú pháp: ```va_start( args, last_fixed_agr);```

	- ```last_fixed_agr``` là đối số cố định cuối cùng trước khi bắt đầu danh sách đối số biến thiên.

	- Ở đây sẽ bắt đầu trỏ từ đối số đầu tiên sau   ```last_fixed_agr```

- **Va_arg()**
	
	- Dùng để truy xuất từng đối số trong danh sách đối số biến đổi.

	- Mỗi lần gọi sẽ truy xuất trả về đối số tiếp theo và di chuyển con trỏ tới đối số kế tiếp.

	- Cú pháp:```va_agr(args, int);```

- **Va_end()**

	- Dùng để kết thúc việc sử dụng danh sách đối số biến đổi, dọn sạch đối tượng va_list và giải phóng tài nguyên.

	- Cú pháp:```va_end(args);```


### Thư viện Assert.h?

 - Dùng để kiểm tra một điều kiện trong mã nguồn và phát hiện lỗi.

 - Thư viện cung cấp 1 macro assert kiểm tra một điều kiện luôn luôn đúng. Nếu sai thì chương trình sẽ dừng và báo lỗi.
 
    - Cú pháp: `assert(biểu_thức);`
## Bài 3:

### Pointer

- Pointer trong ngôn ngữ lập trình C có thể được hiểu như là một biến có khả năng chứa địa chỉ bộ nhớ của một biến khác. Sử dụng Pointer giúp chúng ta truy cập đến từng vùng nhớ một cách linh họat hơn, hiểu được từng vùng địa chỉ thanh ghi của máy tính.

#### Cách khai báo pointer
``` bash
     int *ptr; // con trỏ trỏ đến address có data là kiểu int 
     char *ptr; // con trỏ trỏ đến address có data là kiểu char 
     float *ptr; // con trỏ trỏ đến address có data là kiểu float
```
#### Lấy địa chỉ của một biến 
``` bash
    int x = 10;
    int *ptr_x = &x;  // ptr_x chứa địa chỉ của x
```
#### Sử dụng con trỏ để truy cập giá trị:
``` bash
    int y = *ptr_x;  // y sẽ chứa giá trị của x 
```
- khi khai báo con trỏ, vì con trỏ chứa địa chỉ nên kích thước của con trỏ sẽ tùy thuộc vào cấu trúc của MCU hoặc máy tính sử dụng.

### Một số loại con trỏ khác
#### Void pointer
- Void pointer thường dùng để trỏ đến bất kỳ địa chỉ nào mà không cần phải quan tâm tới kiểu dữ liệu của giá trị của ô nhớ đó.
- khai báo: 
    ``` bash
     void  *ptr_void;
    ```
#### Pointer to Constant
- Pointer to Constant được hiểu là khi ta định nghĩa kiểu này thì ta không thể thay đổi giá trị địa chỉ mà nó đang trỏ đến(tức là địa chỉ không thay thể thay đổi từ còn trở đó) nhưng chúng ta có thể thay đổi giá trị của tại địa chỉ mà con trỏ đó trỏ tới.
- khai báo:
    ``` bash  
    int value = 5;
    int const *ptr_const = &value;
    printf("value: %d\n", *ptr_const);
    //*ptr_const = 7; // wrong
    value = 9;
    printf("value: %d\n", *ptr_const);
    ```
#### Constant Pointer
- Định nghĩa là một con trỏ mà khi đó giá trị nó trỏ tới địa chỉ không thể thay đổi được. Tức là con trỏ này khi khởi tạo thì nó không thể trỏ đến địa chỉ khác.
- khai báo:
    ``` bash
    int value = 5; 
    int test = 15;
    int *const const_ptr = &value;
    printf("value: %d\n", *const_ptr
    *const_ptr = 7;
    printf("value: %d\n", *const_ptr);
    //const_ptr = &test; // wrong
    ``` 
#### Function pointer
- Pointer to fuction(con trỏ hàm) là một biến chứa địa của một hàm. Có nghĩa nó trỏ tới địa chỉ của một hàm nào đó đã được định nghĩa trong chương trình.
- Khác với các con trỏ khác, con trỏ hàm cho phép ta truyền đối số của hàm khác, truyền hàm như là lưu địa chỉ hàm và trả về một giá trị từ hàm khác. 
- Ví dụ 
    ``` bash
        #include <stdio.h>
        // Hàm mẫu 1
        void greetEnglish() {
            printf("Hello!\n");
        }

        // Hàm mẫu 2
        void greetFrench() {
            printf("Bonjour!\n");
        }

        int main() {

            // Khai báo con trỏ hàm
            void (*ptrToGreet)();

            // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
            ptrToGreet = greetEnglish;

        // Gọi hàm thông qua con trỏ hàm
        (*ptrToGreet)();  // In ra: Hello!

        // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
            ptrToGreet = greetFrench;

        // Gọi hàm thông qua con trỏ hàm
            (*ptrToGreet)();  // In ra: Bonjour!

        return 0;
        }
    ```
#### Pointer to Pointer 
Pointer to Pointer được hiểu như là một biến chứa chứa địa chỉ của một con trỏ. Con trỏ này trỏ đến địa chỉ của một biến khác và chứa giá trị. Vậy nên khi gọi một con trỏ pointer to pointer thì bản chất nó đang lấy giá trị của biến chứa địa chỉ của địa chỉ của con trỏ nó gán. 

```bash
    #include <stdio.h>
    int main() {
        int value = 42;
        int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

        printf("Value: %d\n", **ptr2);

    return 0;
    }
```
#### NULL Pointer
Null Pointer được hiểu như là một con trỏ không trỏ đến bất kỳ đối tượng vùng nhớ cụ thể nào. Khi ta gán cho một biến con trỏ có giá trị là NULL thì còn con trỏ đó đang trỏ tới địa chỉ 0 và địa chỉ đó có giá trị bằng 0.

## Bài 4: 

### Exern 

- Extern là một từ khóa được sử dụng trong ngôn ngữ lập trình C. Từ khóa này được sử dụng nhằm mục đích thông báo cho chương trình biết rằng một biến hay một hàm đã được định nghĩa ở một file hay một chương trình khác rồi. Điều này giúp việc quản lý dữ liệu dữ các file một cách thuận tiện hơn và trở nên chặt chẻ hơn. Với từ khóa extern thì người dùng có thể sử dụng biến hoặc hàm đó trong một file khác.

- Ví dụ 
    - File main.c
    ``` bash 
    #include <stdio.h>

    int value = 90;

    extern void display();

    int main()
    {
	    printf("hello\n");
	    display();
    }
    ```
    - File other.c
    ``` bash
    #include <stdio.h>

    extern int value;
    void display()
    {
	    printf("value: %d\n", value);
    }
    ```
- Ứng dụng 
    - Cho phép chúng ta chia sẻ biến và hàm giữa nhiều file nguồn trong chương trình 
    - Dùng để kết nối các module hoặc thư viện trong một dự án lớn 
    ...
### Static
#### Static local variables
 - Khi ta khai báo từ khóa Static cho một biến cục bộ (local variables) điều này có ý nghĩa là biến đó sẽ dữ giá trị đó qua các lần gọi hàm và biến đó chỉ có thể được gọi trong hàm đó, và không thể tồn tại ngoài hàm.

- Ví dụ:
    ``` bash 
    #include <stdio.h>

    void exampleFunction() {
        static int count = 0;  // Biến static giữ giá trị qua các lần gọi hàm
        count++;
        printf("Count: %d\n", count);
    }

    int main() {
        exampleFunction();  // In ra "Count: 1"
        exampleFunction();  // In ra "Count: 2"
        exampleFunction();  // In ra "Count: 3"
        return 0;
    }
    ``` 
- Ứng dụng 
    - Lưu trữ giá trh sau những lần gọi hàm nên dùng để theo dõi số lần gọi hàm mà không cần khai báo một biến toàn cục
#### Static local variables
Khi ta khai báo từ khóa Static cho một biến hay một hàm toàn cục, thì điều này có ý nghĩa là biến đó hay hàm đó chỉ có thể hoạt động được trong phạm vi của file nguồn hiện tại này thôi.
- Ví dụ:
    - File main.c
    ``` bash
    #include <stdio.h>

    extern void display();
    //extern int s_g_value;
    extern int g_value;

    int main()
    {
	    printf("hello\n");
	    g_value = 40;
	    display();
	    return 0;
    }
    ``` 
    - File other.c
    ``` bash
    #include <stdio.h>

    int g_value = 30;
    static int s_g_value = 20;


    void display()
    {
	    printf("static global value: %d\n", s_g_value);
	    printf("global value: %d\n", g_value);
    }
    ```
### Volatile
- Từ khóa Volatile trong ngôn ngữ lập trình C được sử dụng tránh việc trình biên dịch tối ưu hóa hoạt động của biến đó trong chương trình. Điều này có nghĩa là trình biên dịch sẽ hiểu là biến đó sẽ có giá trị thay đổi ngẫu nhiên, cho nên trình biên dịch sẽ không được tôi hóa bỏ qua biến đó mà phải thực hiện cập nhật giá trị của biến đó theo dúng định nghĩa ban đầu.


### Register 
Trong ngôn ngữ lập trình C từ khóa Register được sử dụng nhằm mục đích thông báo biến này cần được lưu trữ ở thanh ghi của máy tính, chứ không phải lưu trữ ở bộ nhớ Ram như thông thường. Việc lưu giá trị ở trên thanh ghi sẽ giúp cải thiện tốc độ tính toán dữ liệu một cách nhanh hơn so với việc lưu trữ RAM. Vì quá trình tính toán sẽ được thực hiên bô xư lý toán hoc ALU nên khi ta lưu trữ dữ liệu ở RAM thì MUC sẽ tốn thời gian truyền dữ liệu dữ RAM và thành ghi và sau đó chép dữ liệu lên ALU để tính toán. Vì vậy đối với những biến cần tối ưu hóa về mặt thời gian người ta hường lưu chúng trên bộ nhớ thanh ghi.

Quá trình truyền dữ liệu có thể được mô tả như sau  

![Register](/Image/2.png)

- Ví dụ:
    ``` bash
    #include <stdio.h>
    #include <time.h>

    int main() {
        // Lưu thời điểm bắt đầu
        clock_t start_time = clock();

        // Đoạn mã của chương trình
        for (int i = 0; i < 1000000; ++i) {
          // Thực hiện một số công việc bất kỳ
        }

        // Lưu thời điểm kết thúc
        clock_t end_time = clock();

        // Tính thời gian chạy bằng miligiây
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);

        return 0;
    }

    ```
## Bài 5:
### Goto 
- "goto" là một từ khóa được sử dụng trong ngôn ngữ lập trình C, nó cho phép chương trình nhảy đến một nhãn label đã được đặt trước đó và label đó chỉ được đặt trong cùng một hàm. Việc sử dụng goto mặc dù đem đến khả năng kiểm soát flow của chương trình, tuy nhiên việc sử dụng goto quá nhiều là không tốt vì nó làm cho chương trình chúng ta khó có khả năng bảo trì hơn.

- Ví dụ:
    ``` bash 
    #include <stdio.h>

    int main() {
        int i = 0;
        // Đặt nhãn
        start:
        if (i >= 5) {
            goto end;  // Chuyển control đến nhãn "end"
        }

        printf("%d ", i);
        i++;

        goto start;  // Chuyển control đến nhãn "start"

        // Nhãn "end"
        end:
        printf("\n");

        return 0;
    }
    ```
- Mặc dù goto không được khuyến khích sử dụng vì khả năng khó bảo trì của nó tuy nhiên chúng ta vẫn có thể sử dụng chúng trong một số trường hợp như sau:
    - **Thoát khỏi nhiều cấp độ vòng lặp**
    Trong một số trường hợp việc thoát khỏi nhiều vòng lặp trở nên phức tạp thì việc sử dụng goto để dễ dàng thoát khỏi nhiều vòng lặp hơn
    Ví dụ:
        ``` bash
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
            if (some_condition(i, j)) {
                goto exit_loops;
                }
            }
        }
        exit_loops:
        ```
    - **Xử lý lỗi và giải phóng bộ nhớ**   
    Trong trường hợp sử lý lỗi, có thể sử dụng goto để dễ dàng giải phóng bộ nhớ đã được cấp pháp trước khi thoát khỏi hàm

    - **Implement Finite State Machines (FSM)** (máy trạng thái hữu hạn)
    Trong một số trường hợp, đặc biệt là khi triển khai Finite State Machines, goto có thể được sử dụng để chuyển đến các trạng thái khác nhau một cách dễ dàng.
    Ví dụ: 
        ```bash 
        switch (current_state) {
            case STATE_A:
                // Xử lý State A
                if (condition) {
                    goto STATE_B;
                }
                break;

            case STATE_B:
                // Xử lý State B
                break;
        }

        ```
### setjmp.h
- setjmp.h là một thư viện trong ngôn ngữ lập trình C, cung cấp hai hàm đó là setjmp và longjmp. Cả hai hàm này thường được sử dụng để thực hiện sử lý ngoại lệ của chương trình C. Xử lý ngoại lệ có nghĩa là ngoại lệ này vẫn khiến cho chương trình hoạt động một cách bình thường nhưng nó chính là kết quả không mong muốn của người dùng.
- Ví dụ
    ``` bash
    #include <stdio.h>
    #include <setjmp.h>

    jmp_buf buffer;

    void risky_function() {
        printf("Entering risky_function\n");
    
        // Thiết lập điểm cho việc "quay lại"
        if (setjmp(buffer) != 0) {
            printf("Exiting risky_function due to longjmp\n");
            return;
        }

        // Mô phỏng một tình huống lỗi
        int error_condition = 1;
        if (error_condition) {
            printf("Error detected in risky_function\n");
            longjmp(buffer, 1);  // "Quay lại" tới điểm đã được thiết lập bởi setjmp
        }

        printf("Exiting risky_function normally\n");
    }

    int main() {
        printf("Starting main\n");
        risky_function();
        printf("Back in main after risky_function\n");

        return 0;
    }

    ```