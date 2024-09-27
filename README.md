## Bài 1: COMPILER-MACRO
<details><summary>Chi tiết</summary>

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
</details>

## Bài 2: STDARG-ASSERT LIBRARY

<details><summary>Chi tiết</summary>

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

</details>

## Bài 3: POINTER
<details><summary>Chi tiết</summary>

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
</details>

## Bài 4: EXTERN-STATIC-VOLATILE-REGISTER
<details><summary>Chi tiết</summary>

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
</details>

## Bài 5: GOTO-SETJMP
<details><summary>Chi tiết</summary>

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
</details>

## Bài 6: BITMASK
<details><summary>Chi tiết</summary>

### Bitmask 
- Bitmask là một kĩ thuật được sử dụng để làm việc với các bit. Nó chủ yếu được ứng dụng lưu trữ hoặc thao tác với các flag hoặc để chỉ trạng thái của chân tín hiệu nào đó. Ta có thể chỉ sửa xóa bit đó với Bitmask. Ứng dụng phổ biến của Bitmask có thể nói tới là để tối ưu hóa bộ nhớ,thực hiện các toán với bit, quyền truy cập hoặc các thuộc tính lên đối tượng,..
#### Các toán tử bitwise
**a. AND bitwise**
 - Thực hiện phép AND bitwise giữa các căp bit với nhau. Kết quả bằng 1 nếu cả hai bit đều là 1, còn lại thì kết quả đều bằng 0;
 - Ví dụ khai báo:
    ```bash
    int result = num1 & num2;
    ```
**b. OR bitwise**
- Thực hiện phép OR bitwise giữa các căp bit với nhau. Kết quả bằng 0 nếu cả hai bit đều là 0, còn lại thì kết quả đều bằng 1;
 - Ví dụ khai báo:
    ```bash
    int result = num1 | num2;
    ```
**c. XOR bitwise**
- Thực hiện phép XOR bitwise giữa các căp bit với nhau. Kết quả bằng 0 nếu cả hai bit đều giống nhau(tức là cùng bằng 0 hoặc cùng bằng 1), còn lại thì kết quả đều bằng 1;
 - Ví dụ khai báo:
    ```bash
    int result = num1 ^ num2;
    ```
**d. NOt bitwise**
 - Đây là phép đảo từng bit của một số. Có nghĩa là 0 lấy not sẽ là 1, ngược lại 1 lấy not sẽ là 0
 - Ví dụ khai báo:
    ```bash
    int result = ~num;
    ```
**e. Shift left or Shift right**
 - Dùng để dịch bit sang phải hoặc sang trái 
 - Khi ta muốn dịch các bit từ trái sang phải, ta sử dụng ký hiệu " >> " + với số phần tử muốn dịch, sau khi địch các tùy vào số phần tử muốn dịch mà ta phải thêm bấy nhiêu số bit 0 or bit 1 (xét bit 0 or 1 phải giựa vào giá trị đó có phải là số có dấu hay không or hoặc quy định bởi bit MSB);
 - Ví vụ:
    ```bash
    int resultLeftShift = num >> shiftAmount;
    \\ giả sử ban đầu  num =0b00011110;
    \\ nếu dịch 3 phần từ, tức là shiftAmount =3;
    \\ kết quả dich sang phải 0b00000011;
    ```
 - Khi ta muốn dịch các bit từ phải sang trái, ta sử dụng ký hiệu " << " + với số phần tử muốn dịch, sau khi địch các tùy vào số phần tử muốn dịch mà ta phải thêm bấy nhiêu số bit 0;
 - Ví vụ:
    ```bash
    int resultLeftShift = num << shiftAmount;
    \\ giả sử ban đầu  num =0b00011110;
    \\ nếu dịch 3 phần từ, tức là shiftAmount =3;
    \\ kết quả dich sang trái 0b11110000;
    ```

#### Một số ví dụ về ứng dụng của BITMASK
- example 1:
```bash
#include <stdio.h>
#include <stdint.h>

#define GENDER        1 << 0  // Bit 0: Giới tính (0 = Nữ, 1 = Nam)
#define TSHIRT        1 << 1  // Bit 1: Áo thun (0 = Không, 1 = Có)
#define HAT           1 << 2  // Bit 2: Nón (0 = Không, 1 = Có)
#define SHOES         1 << 3  // Bit 3: Giày (0 = Không, 1 = Có)
// Tự thêm 5 tính năng khác
#define FEATURE1      1 << 4  // Bit 4: Tính năng 1
#define FEATURE2      1 << 5  // Bit 5: Tính năng 2
#define FEATURE3      1 << 6  // Bit 6: Tính năng 3
#define FEATURE4      1 << 7  // Bit 7: Tính năng 4

void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature;
}

void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}


int isFeatureEnabled(uint8_t features, uint8_t feature) {
    return (features & feature) != 0;
}

void listSelectedFeatures(uint8_t features) {
    printf("Selected Features:\n");

    if (features & GENDER) {
        printf("- Gender\n");
    }
    if (features & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (features & HAT) {
        printf("- Hat\n");
    }
    if (features & SHOES) {
        printf("- Shoes\n");
    }
    // Thêm các điều kiện kiểm tra cho các tính năng khác
}

void removeFeatures(uint8_t *features, uint8_t unwantedFeatures) {
    *features &= ~unwantedFeatures;
}



int main() {
    uint8_t options = 0;
    // Thêm tính năng 
    enableFeature(&options, GENDER | TSHIRT | HAT);

    removeFeatures(&options, TSHIRT);

    // Liệt kê các tính năng đã chọn
    listSelectedFeatures(options);
    
    return 0;
}
```
- example 2:
``` bash
#include <stdio.h>

#define LED1 1 << 0 // 0001
#define LED2 1 << 1 // 0010
#define LED3 1 << 2 // 0100
#define LED4 1 << 3 // 1000


void enableLED(unsigned int *GPIO_PORT, unsigned int LED) {
    *GPIO_PORT |= LED;
}

void disableLED(unsigned int *GPIO_PORT, unsigned int LED) {
    *GPIO_PORT &= ~LED;
}


int main() {
    unsigned int GPIO_PORT = 0; // Giả sử là biến điều khiển cổng GPIO

    // Bật LED1 và LED3
    enableLED(&GPIO_PORT, LED1 | LED3);
    if (GPIO_PORT & LED1 )
    {
        printf("LED1 is on\n");
    }

    if (GPIO_PORT & LED2)
    {
        printf("LED2 is on\n");
    }

    if (GPIO_PORT & LED3)
    {
        printf("LED3 is on\n");
    }
  
    // Tắt LED1 và bật LED2
    disableLED(&GPIO_PORT, LED1);
    enableLED(&GPIO_PORT, LED2);

    if (GPIO_PORT & LED1 )
    {
        printf("LED1 is on\n");
    }

    if (GPIO_PORT & LED2)
    {
        printf("LED2 is on\n");
    }

    if (GPIO_PORT & LED3)
    {
        printf("LED3 is on\n");
    }

    // Cập nhật trạng thái của GPIO_PORT tương ứng với hardware

    return 0;
}

```
- example 3:
```bash
#include <stdio.h>
#include <stdint.h>

#define ENABLE 1
#define DISABLE 0

typedef struct {
    uint8_t LED1 : 1;
    uint8_t LED2 : 1;
    uint8_t LED3 : 1;
    uint8_t LED4 : 1;
    uint8_t LED5 : 1;
    uint8_t LED6 : 1;
    uint8_t LED7 : 1;
    uint8_t LED8 : 1;
} LEDStatus;



int main() {
    LEDStatus ledStatus = {.LED7 = ENABLE};
    // Bật LED 1 và 3
    ledStatus.LED1 = ENABLE;
    ledStatus.LED3 = ENABLE;

    // Kiểm tra trạng thái của LED 1
    if (ledStatus.LED1) {
        printf("LED1 is on\n");
    }


    return 0;
}
```

</details>

## Bài 7: STRUCT-UNION

<details><summary>Chi tiết</summary>


### Struct
- Struct được hiểu như là một kiểu dữ liệu có cấu trúc nó phép các lập trình viên định nghĩa ra nhiều biến có nhiều kiểu dữ liệu khác nhau ở trong đó. mỗi member trong một struct thì sẽ có một vùng nhớ lưu trữ riêng.

- Ví dụ 
  - **Sử dụng Struct**
    ``` bash
    struct Point {
        int x;
        int y;
    };
    void printPoint(struct Point p);

    void updatePoint(struct Point* p, int newX, int newY);

    int main()
    {
        // Để khởi tạo một biến thuộc kiểu struct, bạn sử dụng cú pháp như sau:
        struct Point p1 = {10, 20};
        // Để truy cập các thành viên, bạn sử dụng toán tử ( . ):
        printf("X coordinate: %d\n", p1.x);
    }

    //Bạn có thể truyền một biến thuộc kiểu struct như một tham số cho một hàm.

    void printPoint(struct Point p) {
    printf("(%d, %d)\n", p.x, p.y);

    //Bạn có thể truyền con trỏ đến struct như một tham số cho một hàm, cho phép thay đổi giá trị của struct bên trong hàm.
        void updatePoint(struct Point* p, int newX, int     newY) {
        p->x = newX;
        p->y = newY;
        }

    }
    ```
  - **Sử dụng từ khóa typedef thêm tên cho struct để rút gọn cú pháp khai báo biến:**
    
    ``` bash
    typedef struct {
        char name[50];
        double maxSpeed;
        double maxAccel;
    int seats;
    } Car;

    Car myCar = {.name = "Honda", .maxSpeed = 200.0, .maxAccel = 500.0, .seats = 4};
    ```
- Cách sắp xếp vùng nhớ của Struct 
    Việc hiểu rõ về việc cách sắp xếp vùng nhớ của struct rất quan trọng, nó giúp chúng ta giảm đi kích thước của bộ nhớ. Điều này là rất quan trọng trong khi làm việc với các project về tối ưu hóa bộ nhớ chương trình.
    
    Khi ta định nghĩa một kiểu dữ liệu struct, thì lập tức máy tính sẽ cấp một địa chỉ để lưu trữ Struct đó. Và kích của Struct nó phụ thuộc vào biến có kích thước lớn nhất. 

    ![Register](/Image/3.png)

    ``` bash
    //ban đầu biền a chiếm 1 byte và dư 3 padding 
    //biến b có kiểu dữ liệu 4 byte thì nó lấp đầy và không dư padding nào.
    //biến c có kiểu dữ liệu 2 byte thì lấp đầy 2 ô và dư 2 padding.
    //tính tống số ô nhớ struct này  1 2byte trong đó có 7 byte để chứa data 5 padding 
    ```
- Ứng dụng nhiều trong việc xử lý json và list. Bên cạnh đó còn ứng dụng vào viết diver library trong nhúng ví dụ cấu hình các chức năng của protocol truyền dữ liệu SPI, I2C,...
### Union 
- Union cũng là một kiểu dữ liệu có cấu trúc nó cho phép các lập trình viên định nghĩa nhiều biến có các kiểu dữ liệu khác nha. Tuy nhiên, các member trong union đều sử dụng chung một vung nhớ ( tức là có cùng địa chỉ) và kích thức của một biến có kiểu dữ union phụ thuộc biến Mentor có kích thước lớn nhất.
- Ví dụ

``` bash 
typedef union {
    uint8_t member_1;
    uint16_t member_2;
    uint32_t member_3;
} union_1;

union_1 myUnion;
myUnion.member_3 = 1048574; // các member trong myUnion để có chung 1 vùng địa chỉ nên ta chỉ cần gán giá trị cho bất kỳ member nào thì đều được giá trị như vậy

// kết quả 
/*
member_3 = 1048574 // cho kết đúng với giá trị đã nhập vào ban đầu vì nó có kiểu 4 byte 
member_2 = 65534 // kết quả sai do member_2 chỉ có 16bit vì vậy nó sẽ chữa được 2byte từ giá trị 1048574 và nó lấy từ LSB 
member_1 = 254 // kết quả sai do member_1 có 1 byte nên nó chỉ chứa 1byte tính từ LSB của giá trị 
*/

```
- **Lưu ý kích thước của một kiểu dữ liệu Union là biến được định nghĩa bên trong Union**


### Kết hợp giữa Union và Struct 

``` bash
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// union lồng struct
typedef union {
    struct {
        uint8_t id[2];  // 2byte 
        uint8_t data[4]; // 4byte 
        uint8_t check_sum[2]; // 2byte 
    } data; // thiết kể không có padding 
    // union có 2 biến data và frame và mỗi biến đều cùng vùng địa chỉ và địa chỉ lưu 8byte dữ liệu 
    uint8_t frame[8]; 

} Data_Frame;


int main(int argc, char const *argv[])
{

    // ứng dụng trong việc truyền nhận dữ liệu 
    Data_Frame transmitter_data;
    
    strcpy(transmitter_data.data.id, "10");
    strcpy(transmitter_data.data.data, "1234");
    strcpy(transmitter_data.data.check_sum, "70");

	Data_Frame receiver_data;
    strcpy(receiver_data.frame, transmitter_data.frame);
	
    
    return 0;
}

```

</details>

## Bài 8: MEMORY LAYOUT

<details><summary>Chi tiết</summary>

- Sau khi compiler biên dịch ra các file. hex hoặc executable file thì sẽ được lưu ở bộ nhớ Flash của MCU hoặc SSD đối với máy tính. Khi ta bắt đầu chạy một chương trình thì executable file sẽ được coppy vào bộ nhớ RAM để thực thi.
            ![Memory layout](/Image/4.png)

Khi coppy vào RAM, thì chương trình được sắp xếp theo từng vùng nhớ. Phân vùng nhớ của một chương trình C/C++ gồm 5 phần:

### TEXT SEGMENT
Phân vung TEXT là vùng nhớ có địa chỉ thấp nhất. Phân vùng text chỉ có thể đọc ra và không thể ghi bất kỳ thứ gì vào phân vung này (READ ONLY)

- Chứa các lệnh thực thi của chương trình 
- chứa các biến hằng số và con trỏ kiểu char
``` bash
#include <stdio.h>

const int a = 10;
char arr[] = "Hello";
char *arr1 = "Hello";

int main() {
   

    printf("a: %d\n", a);

    arr[3] = 'W';
    printf("arr: %s", arr);// arr là một mảng nên nó có thể thay đổi được giá trị do không phải phân vùng text

    // arr1[3] = 'E';
    printf("arr1: %s", arr1); // do arr1 là một con trỏ kiểu char nên không thể thay đổi giá trị do nó nằm ở phân vùng text

    
    return 0;
}
```

### Data segment
Initialized Data Segment (Dữ liệu Đã Khởi Tạo): là phân vùng lưu global variables, static variables được khởi tạo với giá trị khác 0.
- Chứa các biến toàn cục được khởi tạo với giá trị khác 0
- Chứa các biến static được khởi tạo với giá trị khác 0.
- cho phép đọc và ghi dữ liệu, tức là dữ liệu có thể thay đổi
- Tất cả các biến sẽ bị thu hồi vùng nhớ khi chương trình kết thúc.
``` bash
#include <stdio.h>

int a = 10; // data khác 0 nên lưu phân  vùng DS
double d = 20.5; // data khác 0 nên lưu phân  vùng DS

static int var = 5; // data khác 0 nên lưu phân  vùng DS

void test()
{
    static int local = 10; // data khác 0 nên lưu phân  vùng DS
}


int main(int argc, char const *argv[])
{  
    a = 15; // thay đổi được giá trị 
    d = 25.7; // thay dổi được giá trị 
    var = 12;// thay dổi được giá trị
    printf("a: %d\n", a); // in ra giá trị hiện tại
    printf("d: %f\n", d);
    printf("var: %d\n", var);



    return 0;
}
```
### Bss segment (Block started by symbol)
Uninitialized Data Segment (Dữ liệu Chưa Khởi Tạo):là phân vùng lưu global variables, static variables không được khởi tạo giá trị hoặc được khởi tạo với giá trị là 0.
- cho phép đọc và ghi tại phân vùng này
- Tất cả các biến trong phân vùng này sẽ bị thu hồi sau khi kết thúc chương trình 
``` bash
#include <stdio.h>


typedef struct 
{
    int x;
    int y;
} Point_Data; // chưa khởi tạo giá trị nên lưu ở phân vùng BSS


int a = 0; // khởi tạo giá trị bằng 0 nên lưu BSS
int b; // chưa khởi tao giá trị nên lưu BSS

static int global = 0; // tương tư
static int global_2;// 

static Point_Data p1 = {5,7}; // ban đầu chưa khởi tao nên lưu BSS, sau đó khởi tạo giá trị thì biến đó vẫn lưu ở BSS



void test()
{
    static int local = 0;
    static int local_2;
}

int main() {

    
    printf("a: %d\n", a);
    printf("global: %d\n", global);
   

    
    
    return 0;
}

```
### Stack
Stack là phân vùng nhớ được cấp pháp tự động trong quá trình thực thi chương trình, hoạt động theo cấu trúc LIFO (Last In First Out).Vùng nhớ stack chứa các biến cục bộ, tham số truyền vào của hàm khi được gọi.
- Có thể thực hiện đọc và ghi giá trị trong suốt thời gian gọi hàm.
- Vùng nhớ sẽ bị thu hồi khi thoát ra khỏi hàm đó
``` bash 
#include <stdio.h>


void test()
{
    int test = 0;
    test = 5;
    printf("test: %d\n",test);
}

int sum(int a, int b)
{
    int c = a + b;
    printf("sum: %d\n",c);
    return c;
}



int main() {

    sum(3,5);
    /*
        0x01 // khi goi hàm 0x01 chưa tham số truyền vào 3
        0x02 // // khi goi hàm 0x02 chưa tham số truyền vào 5
        0x03 // khi goi hàm 0x03 chưa tham số phép cộng 8
        // giả xử 0x01 0x02 0x03 là 3 điaj chỉ của phân vùng stack 
    */
   test();
   /*
    int test = 0; // 0x01
   */


    
    return 0;
}

```
### Heap
Heap là vùng nhớ lưu các biến được cấp phát động trong quá trình thực thi chương trình. Khi không còn sử dụng vùng nhớ đã được cấp pháp trên heap thì phải giải phóng vùng nhớ đó. Nếu không giải  phóng có thể dẫn tới mất dữ liệu (memory leak) do không còn vùng nhớ để lưu.

Sử dụng các hàm alloc, realloc, free, delete,… từ thư viện stdlib.h để cấp phát bộ nhớ trên vùng heap.

Vậy câu hỏi đặt ra là tại sao phải sử dụng head ? Ví dụ chúng ta muốn nhập trên một người từ bàn phím sau đó. Nếu chúng ta sử dụng phương pháp bình thường là mảng để chứa dữ liệu thì có thể gây dư vùng nhớ. Sẽ không tối ưu khi không biết chắc chắn kích thước size của mảng là bao nhiêu. Vì vậy giải pháp tối ưu hơn là sử dụng cấp pháp động 

Để cấp phát động với ta có thể sử dụng cú pháp như sau.
```bash
int *ptr = (int *)malloc(sizeof(int) * 10); // Cấp phát bộ nhớ cho 10 số nguyên
// hiểu đơn giản đoan code này tham số truyền vào hàm malloc là size, 
nghĩa là số byte ta muốn cấp phát, ví dụ này là 40byte
// kết quả trả về của hàm malloc là một con trỏ kiểu void
// vậy nên để truy cập đến giá trị được cấp phát của hàm đó phải ép kiểu
// trường hợp này ép kiểu về kiểu int


```
ví dụ khác 
``` bash
// Cấp phát vùng nhớ trên heap và sửa dụng vùng nhớ đó.

#include <stdio.h>
#include <stdlib.h>

void function_1() {
    int size = sizeof(int)*10;
    int *list_num = (int *)malloc(size); // bản châts nó đang trỏ tới địa chỉ đầu tiên trong 10 phần tử được khởi tạo

    printf("Malloc size: %d byte.\n", size);

    for(int index=0;index<10;index++) {
        list_num[index] = index;
    }

    for(int index=0;index<10;index++) {
        // printf("Address: 0x%p, Value: %d.\n", &list_num[index], list_num[index]);
        printf("Address: 0x%p, Value: %d.\n", list_num+index, *(list_num+index));// xuất ra địa chỉ là giá trị của từng ô địa chỉ đó
    }
    
    free(list_num);
}

int main(void) {

    function_1();
    return 0;
}
```

- **lưa ý**

Một biến constant local có thể thay đổi thay đổi được giá trị của nó thông qua một con trỏ đến địa chỉ của nó, vì biến constant local đó được lưu trên stack. Tuy nhiên khi biên dịch thì compiler sẽ cảnh báo.

Một biến constant global thì không có cách nào thay đổi được giá trị vì nó nằm trên phân vùng text.
### SỰ KHÁC NHAU GIỮA STACK và HEAP SEGMENT
- đều cho phép đọc và ghi dữ liệu
- Stack để lưu trữ các biến cục bộ và tham số truyền vào khi gọi hàm, việc cấp phát vùng nhớ là do chương trình tự quản lý và cơ chế tự thu hồi vùng nhớ.
- Cả hai vùng nhớ này đều có thể xảy ra memory leak khi sử dụng stack ta tạo một lượng biến cục bộ quá lớn dẫn đến over stack. Còn với heap khi ta cấp phát vùng nhớ mà chưa thu hồi cũng sẽ gây ra over heap . Stack và Heap sẽ ảnh dữ liệu lẫn nhau.

### Malloc và calloc
Malloc và calloc vùng để cấp phát một vùng nhớ trên heap
Tuy nhiên, chúng cả 2 hàm này vẫn có sự khác biệt 
- malloc:
    - Sẽ cấp phát một vùng nhớ mà không khởi tạo giá trị cho các ô nhớ đó. Tức là giá trị của vùng nhớ đó vẫn sẽ giữ nguyên như trước khi cấp phát vùng nhớ. Các giá trị ngẫu nhiên này gọi là garbage values
    - malloc chỉ cần một tham số truyền vào là số byte bộ nhớ sẽ cấp phát.
    ``` bash 
     char *line = (char *)malloc(20 * sizeof(char));
    ```
- calloc:
    - Sẽ cấp phát một vùng nhớ và khởi tạo giá trị 0 cho các ô nhớ.
    - calloc có hai giá trị truyền vào là số phần tử cần cấp phát và kích thước (số byte) của mỗi phần tử.

    ``` bash
     char *line = (char *)calloc(20, sizeof(char));
    ```
</details>

## Bài  9: LINKED LIST 

<details><summary>Chi tiết</summary>

- Linked list (danh sách liên kết) là một cấu trúc dữ liệu động. Một linked list bao gồm nhiều notes được liên kết lại với nhau thông qua next. Khi làm việc với note ta cần quan tâm tới 3 thông số: 1 là địa chỉ của note đó(address), 2 là giá trị mà note đó lưu trữ (value), 3 là next, nó chứa địa chỉ của
- Expand, đối với singly linked list thì sẽ có 1 next element và nó trỏ tới địa chỉ của note tiếp theo. Also, đối với double linked list thì sẽ có 2 next element và nó trỏ tới địa của note tiếp theo và địa chỉ của note trước đó.
- Để define ra một note trong C la thực hiện như sau:
    ```bash
    typedef struct node
    {
    int value; // đây là phần data 
    struct node *next; // đây là con trỏ dùng để trỏ tới node tiếp theo 
    } node_t;
    ```

### Ưu Nhược điểm của linked list
- Một listed list cung cấp một cách linh hoạt thêm xóa và chèn các phần tử mà không cần thêm xóa các phần mà không cần phải dịch hay di chuyển các phần tử như mảng. Tuy nhiên, nó cũng có nhược điểm là nó phải trỏ đến các địa chỉ tiếp của note tiếp theo nên nó tăng độ phức tạp của bộ nhớ dẫn đến giảm hiệu xuất so với mảng 

</details>


 ## Bài  10: STACK AND QUEUE
 
<details><summary>Chi tiết</summary>   

### STACK
- Stack (ngăn xếp) là một cấu trúc dữ liệu tuân thử theo nguyên tắc "LAST IN FIRST OUT", nghĩa là phần tử được thêm vào stack cuối cùng sẽ được lấy ra khỏi stack đầu tiên.
![STACK](/Image/5.png)

- Các thao tác cơ bản trên stack bao gồm:
    - "push" để thêm một phần tử vào đỉnh của stack
    - "pop" để xóa một phần tử ở đỉnh stack.
    - “top” để lấy giá trị của phần tử ở đỉnh stack.


- Để định nghĩa một Stack ta sử dụng struct 

``` bash
typedef struct Stack {
    int* items; // con trỏ trỏ tơi địa chỉ của các phần tử trong stack 
    int size; // kich thước stack 
    int top; // chỉ số tại đỉnh của stack
} Stack;
```

### QUEUE

- Queue (hàng đợi) là một cấu trúc dữ liệu tuân thủ theo nguyên tắc "First in First out" FIFO, tức là phần tử vào Queue đầu tiên thì sẽ ra khỏi queue đầu tiên. 

**BEFORE**

![QUEUE](/Image/6.png)

**AFTER**

![QUEUE AFTER](/Image/7.png)

- Các thao tác cơ bản trên hàng đợi bao gồm:
    - “enqueue” (thêm phần tử vào cuối hàng đợi)
    - “dequeue” (lấy phần tử từ đầu hàng đợi). 
    - “front” để lấy giá trị của phần tử đứng đầu hàng đợi

- Để định nghĩa một Queue ta sử dụng struct 
``` bash
typedef struct queue
{
    int *items; // con trỏ này sẽ trỏ đến địa chỉ của queue
    int size; // kích thước queue
    int rear, front; // rear cuối hàng đợi, front là đầu hàng chờ;
}queue_t;

```
</details>


 ## Bài  11: JSON 

<details><summary>Chi tiết</summary>   

Json viết tắt là JavaScript Object Notation. Đây là một định dạng truyền tải dữ liệu được ứng dụng phổ biến trong lập trình. Ta có thể bắt gặp nó khi giao tiếp giữa các thiết bị với một cơ sở dữ liệu trên Website,...

JSON có được cấu tạo từ nhiều cặp Key - Value. 1 cặp Key và Value thì có thể được hiểu đây chính là một đối tượng (Object)

For example như sau:
``` bash
    [
    {
        "name": "John Doe",
        "age": 30,
        "city": "New York",
        "occupation": "Software Engineer",
        "isStudent": false
    }, // Object cách nhau dấu ","
    {
        "name": "Jane Smith",
        "age": null,
        "city": "Los Angeles",
        "contact": {
        "email": "jane.smith@example.com",
        "phone": "555-1234"
        }
    },
    {
        "name": "Bob Johnson",
        "age": 35,
        "city": "Chicago"
    }
    ]
    // Sử dụng Json dùng để quản lý thông tin người dùng,
    // dữ liệu thuộc nhiều kiểu khác nhau, 
    // và lượng thông tin của một đối tượng không có định
    // trong 1 object có thể là các thành phần thông tin có thể là nhiều kiểu dữ liệu khcs nhau
    // nó có thể value, string, array, thậm chi có thể object, or bool_value,...
```

Phân Tách Chuỗi Json

Đầu tiên ta phải định nghĩa ra 1 danh sách kiểu dữ liệu JSON sẽ có 
``` bash 
typedef enum{
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT,
}JsonType;
```
Định nghĩa ra 1 JsonValue gồm type và value. Vì vậy ta dung Struct tạo ra 2 member. 
``` bash 
typedef struct JsonValue
{
    JsonType type;// type có kiểu dữ liệu đã được định nghĩa ở trên 
    union
    {
        int boolean;
        double number;
        char *string;
        struct {
            struct JsonValue *values;
            size_t count;
        } array; // nếu là mảng => dùng 1 con trỏ trỏ tới địa chỉ đầu tiên mảng, 
        // 1 biến count để lưu số lượng phần tử trong mảng 
        struct
        {
            char **key; // có lưu trữ nhiều key, mỗi key là 1 string 
            // vd: ["key1","key2","key3"],
            struct JsonValue *values;
            size_t count; // có bao nhiêu cặp key Value
        }object;
        // 
    } value; // value sử dụng union vì nó sẽ sử dung 1 trong những kiểu dữ liệu này tại 1 thời điểm.
} JsonValue;

```

Continue, Mục tiêu là chúng ta sẽ có một chuỗi Json lớn được lưu trữ với trong biến có kiểu string. Và chúng ta sẽ phân tích thành từng element khác nhau với kiểu sử liệu khác nhau. 

Để thực hiện được điều đó chúng ta phải viết các Fuction khác nhau để phân tay chúng từ kiểu Json 

``` bash
JsonValue *parse_json(const char **json);
// nó sẽ cấp phát vùng nhớ và trả về địa chỉ chứa các object, và trong object đó sẽ chứa value với nhiều kiểu khác nhau chẳng hạn .

// bản chất là nó sẽ thực hiện việc đệ quy nhiều lần cho tới hết chuỗi Json ban đầu
static void skip_whitespace(const char **json);

// bỏ qua khoảng trắng

JsonValue *parse_null(const char **json);

// địa chỉ của 1 key nào đó có value là kiểu NULL

JsonValue *parse_boolean(const char **json);
JsonValue *parse_number(const char **json);
JsonValue *parse_string(const char **json);
JsonValue *parse_array(const char **json);
JsonValue  *parse_object(const char** json);

// tương tự ta sẽ có được đỉa chỉ 1 object ban đầu là ta sử con trỏ để trỏ đén các cặp key value trong object đó

 void free_json_value(JsonValue *json_value);

 // truyền vào function này địa chỉ của biến biến giá trị của key value vừa tao, nghĩa là biến này là con trỏ có kiểu JsonValue và vừa được khởi tạo bằng malloc. 
 // Tiếp theo nó Clear vùng nhớ vừa tạo 
 // vd là mảng nó sẽ thu hồi vùng nhớ của các giá trị trong mảng đó  và thu hôi luôn cả vung nhớ của phần tử đầu tiên của mảng 
```

</details>

## Bài  12: BINARY SEARCH - FILE OPENRATION - CODE CONVENTION

<details><summary>Chi tiết</summary>   

### Binary Search

 Thuật toán tìm kiếm nhị phân là một phương pháp tìm kiếm các phần tử trong một mảng đã được sắp xếp. Có thể là mảng sẽ được sắp xếp theo chiều từ nhỏ đến lớn hoặc từ lớn đến bé. Giải thuật này giúp tối ưu bộ nhớ của chương trình vì giảm số lần thực hiện so với phương pháp thông thường

 Giả sử có 1000 phần tử với giải thuật thông thường sẽ trãi qua 1000 vòng lặp để tìm ra số phần từ, but with Binay Search chỉ mất 14 ỏ 15 vòng lặp for. 

 Mô tả:
#### Sắp xếp mảng: Đầu tiên mảng phải sắp xếp tăng dần hoặc giảm dần
#### Ban đầu, ta tìm kiếm số 25
![](/Image/8.png)
#### Xác Định Lelf và Right và Mid 
![](/Image/11.png)

#### So sách giá trị cần tìm với giá trị tại Mid, lớn hơn bé or bằng 
##### => trong trường hợp này tại Mid có value = 18 
##### => value cần tìm lớn hơn value của Mid
##### => Lelf lúc này sẽ = Mid + 1:

![](/Image/12.png)

#### Vậy là chúng ta đã giới hạn được các giá trị 

![](/Image/13.png)

#### Cuối cùng, chúng ta sẽ lại có Right Lelf và Mid mới khi chưa tìm thấy giá trị mong muốn 
![](/Image/14.png)

### Từ lý thuyết ta sẽ phát triển thành code 

- Có 2 giải thuật cần quan tâm. 
    - Một là giải thuật tìm kiếm giá trị. Điều đó có nghĩa ta sẽ cần truyền vào giá trị cần tìm kiếm và truyền vào địa chỉ của number list, left and right 

    ``` bash
    int binarySearch(int* arr, int l, int r, int x)
    {
        if (r >= l)
        {
            int mid = (r + l) / 2;

    
            if (arr[mid] == x)  return mid;

    
            if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);

    
            return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
    }
    ```
    -  Hai là giải thuật sắp xếp. Cái này khá đơn giản 

    ``` bash
    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void bubbleSort(int arr[], int n)
    {
        int i, j;
        for (i = 0; i < n - 1; i++)
        {
           
            for (j = 0; j < n - i - 1; j++)
            {
               
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    
    ```

</details>

## Bài  13: CLASS

<details><summary>Chi tiết</summary>   
Từ khóa Class được sử dụng trong C++ để định nghĩa một lớp, một cấu trúc dữ liệu, tức là nó có thể chứa các biến hoặc các hàm liên quan trong đó.

Class nó cũng giống với Struct hay Union bên C vậy. Nhưng điểm khác biệt là Class nó định nghĩa được nhiều dạng cấu trúc dữ liệu hơn. Cụ thể Class ta có thể định nghĩa được hàm mà Struct hay Union không thể làm được.

### For example about defination a class

``` bash
class ClassName {
class ClassName {
private:
    // Các thành phần riêng tư (private) chỉ có thể truy cập bên trong lớp
    // Dữ liệu thành viên, hàm thành viên, ...

protected:
    // Các thành phần bảo vệ (protected) tương tự như private, nhưng có thể truy cập từ lớp kế thừa

public:
    // Các thành phần công khai (public) được truy cập từ bên ngoài lớp
    // Dữ liệu thành viên, hàm thành viên, ...
    // Hàm thành viên và các phương thức khác có thể được định nghĩa tại đây
    // ...

};

```

### Example sample and explain it 

``` bash


#include <iostream>
using namespace std;

class information {
    public: 
        char* name;
        int old;  
};

class HinhChuNhat {
    public:
        double chieu_dai; // property 
        double chieu_rong; // property cách gọi trong C++
        double DienTich(){
            return chieu_dai*chieu_rong; // Method  
        }
        void Display(); // Method 

        // class nó cung cấp 1 contructor và nó trung tên với class 
        // và nó có thể nằm ở bất kỳ phạm vi nào

        HinhChuNhat()
        {
            chieu_dai = 10;
            chieu_rong = 30;
        }
        // contructor co tác dụng khi chung ta khởi tao object bất kỳ
        // thì hàm contructor sẽ tự động chạy
        // nghia là nó sẽ tự động gán giá trị chiều dài, chiều rộng 
        // khi khởi tạo object

        // cách khởi tạo contructor khác
        

        // destructor khi khởi tạo object nó cũng sẽ chạy destructor này
        // destructor này có giống lệnh free trong C
        // nghĩa là nó giải phóng đối tượng 
        ~HinhChuNhat(){

        }
        
};

void HinhChuNhat::Display (){
    cout << "dientich:" <<DienTich()<<endl;
}

    int main(int argc, char const *argv[])
    {
        HinhChuNhat Hinh_1;  // Hinh_1 được gọi object 
        Hinh_1.chieu_dai = 10.5;
        Hinh_1.chieu_rong = 5;

        cout << "chieudai:" <<Hinh_1.chieu_dai<<endl;
        cout << "chieurong:" <<Hinh_1.chieu_rong<<endl;
        Hinh_1.Display();
        
        information oai;
        oai.name="nguyen xuan oai";
        oai.old =22;
        cout<<"ten:"<<oai.name<<endl;
        cout<<"ole:"<<oai.old<<endl;
        return 0;
    }

```

</details>
