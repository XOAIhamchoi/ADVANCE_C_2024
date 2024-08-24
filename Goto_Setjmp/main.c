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