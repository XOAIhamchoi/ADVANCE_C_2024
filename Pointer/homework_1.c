#include "stdio.h"
#include "string.h"

typedef struct{
    char ten[50];
    float diemtrungbinh;
    int id;
} sinhvien;

int stringCompare(const char *str1, const char *str2)
{
    while(*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int compareByName(const void *a, const void *b)
{
    sinhvien *sv1= (sinhvien*)a;
    sinhvien *sv2= (sinhvien*)b;
    return stringCompare(sv1->ten,sv2->ten);
}

int compareByDiemTrungBinh(const void *a, const void *b)
{
    sinhvien *sv1= (sinhvien*)a;
    sinhvien *sv2= (sinhvien*)b;
    if (sv1->diemtrungbinh > sv2->diemtrungbinh)
    {
        return 1;
    }
    return 0;
}
int compareByID(const void *a, const void *b)
{
    sinhvien *sv1= (sinhvien*)a;
    sinhvien *sv2= (sinhvien*)b;
    return sv1->id - sv2->id;
}
void sort(sinhvien array[],size_t size,int (*compareFunc)(const void*,const void*))
{
    int i,j;
    sinhvien temp;
    for(i = 0;i<size-1;i++)
        for(j=i+1;j<size;j++)
        {
            if((*compareFunc)(array+i,array+j)>0)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
}

void display(sinhvien *array, size_t size) {
   for (size_t i = 0; i < size; i++) {
       printf("ID: %d, Ten: %s, Diem Trung Binh: %.2f\n", array[i].id, array[i].ten, array[i].diemtrungbinh);
   }
   printf("\n");
}

int main(int argc, char const *argv[])
{
    sinhvien danhsachsv[] =
    {

        {"Hoang",7.5,100},
        {.ten="Tuan",.diemtrungbinh=4.5,.id=101},
        {.ten="Vy",.diemtrungbinh=6.8,.id=102},
        {"oai",8.5,103},
    };

    size_t size = sizeof(danhsachsv)/sizeof(danhsachsv[0]);
   // Sắp xếp theo tên
   sort(danhsachsv, size, compareByName);

   display(danhsachsv, size);

   // Sắp xếp theo điểm trung bình
   sort(danhsachsv, size, compareByDiemTrungBinh);

   display(danhsachsv, size);

   // Sắp xếp theo ID
   sort(danhsachsv, size, compareByID);

   display(danhsachsv, size);
    return 0;
}
