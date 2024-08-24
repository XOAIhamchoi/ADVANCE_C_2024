#include <stdio.h>
#include <setjmp.h>

typedef enum
{
    NO_ERROR,
    FILE_ERROR,
    NETWORK_ERROR,
    CALCULATION_ERROR,
}   ErrorCodes;

jmp_buf buffer;
ErrorCodes exception_code;
char *error_message;
#define TRY if((exception_code=setjmp(buffer))==NO_ERROR)
#define CATCH(x) else if (exception_code == x)
#define THROW(x,message)  error_message = message;\
                            longjmp(buffer,x);

void readFile()
{
    printf("Đọc file...\n");
    THROW(FILE_ERROR,"Lỗi đọc file: File không tồn tại.\n");

}
void networkOperation() {
    printf("Hoạt động mạng...\n");// Bổ sung chương trình
    THROW(NETWORK_ERROR,"Lỗi mạng: Mạng không hoạt động.\n");// Bổ sung chương trình
}

void calculateData() {
    printf("Tính toán dữ liệu...\n");// Bổ sung chương trình
    THROW(NETWORK_ERROR,"Lỗi mạng: Mạng không hoạt động.\n");// Bổ sung chương trình
   
}
int main(int argc, char const *argv[])
{
    
    TRY {
        readFile();
        networkOperation();
        calculateData();
    } 
    CATCH(FILE_ERROR) {
        printf("%s\n",error_message);
        }
    CATCH(NETWORK_ERROR) 
        {
          printf("%s\n",error_message);  
        }
    CATCH(CALCULATION_ERROR) 
        {
          printf("%s\n",error_message);  
        }
        // Bổ sung thêm nhiều CATCH
    return 0;
}
