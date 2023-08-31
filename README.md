# Embedded_Interview_T8
## C Programming
<details>
<summary>Bài 1: C cơ bản</summary>

### 1. Kiểu dữ liệu
Các kiểu dữ liệu sử dụng thư viện `<stdint.h>`:

|C type                |stdint.h type  |Bits  |Range                                                    |
|:--------------------:|:-------------:|:----:|:-------------------------------------------------------:|
|unsigned char         |uint8_t        |8     |0 to 255                                                 |
|char                  |int8_t         |8     |-128 to 127                                              |
|unsigned short        |uint16_t       |16    |0 to 65,535                                              |
|short                 |int16_t        |16    |-32,768 to 32,767                                        |
|unsigned int          |uint32_t       |32    |0 to 4,294,967,295                                       |
|int                   |int32_t        |32    |-2,147,483,648 to 2,147,483,647                          |
|unsigned long long    |uint64_t       |64    |0 to 18,446,744,073,709,551,615                          |
|long long             |int64_t        |64    |-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807  |

Nếu gán cho biến một giá trị lớn hơn giới hạn kiểu dữ liệu của biến, chương trình sẽ báo lỗi.

Ví dụ:
```c
#include <stdio.h>
#include <stdint.h>

uint8_t var;

int main()
{
    var = 10;

    printf("Gia tri cua var: %d", var);
    return 0;
}
```
Output:

`Gia tri cua var: 10`
  
***
### 2. typedef
`typedef` là một từ khóa dùng để định nghĩa lại tên của một kiểu dữ liệu, cung cấp cho kiểu dữ liệu có sẵn một tên mới nhằm thuận tiện cho việc viết code.

Ví dụ:
```c
#include <stdio.h>
#include <stdint.h>

typedef int number;

int main(int argc, char const *argv[])
{
    number var = 100;

    printf("Gia tri cua var: %d", var);
    return 0;
}
```

Output:

`Gia tri cua var: 100`
  
***
### 3. Câu điều kiện
#### 3.1. if
Cú pháp:
```c
if(Điều kiện) {Khối lệnh}
```
Câu lệnh `if` sẽ kiểm tra "Điều kiện", "Khối lệnh" chỉ được thực thi khi "Điều kiện" đúng.

Ví dụ:
```c
int i = 20;

if (i > 10)
{
    printf("i lon hon 10");
}
```
Output:

`i lon hon 10`

#### 3.2. if ... else
Cú pháp:
```c
if(Điều kiện) {Khối lệnh 1}
else {Khối lệnh 2}
```
"Điều kiện" đúng sẽ thực thi "Khối lệnh 1", sai sẽ thực thi "Khối lệnh 2".

Ví dụ:
```c
int i = 5;

if (i > 10)
{
    printf("i lon hon 10");
}
else
{
    printf("i nho hon 10");
}
```
Output:

`i nho hon 10`
  
#### 3.3. else if
Muốn kiểm tra nhiều điều kiện hơn có thể sử dụng cú pháp `else if`:
```c
if(Điều kiện 1) {Khối lệnh 1}
else if(Điều kiện 2) {Khối lệnh 2}
else {Khối lệnh 3}
```
Ví dụ:
```c
int i = 10;

if (i > 10)
{
    printf("i lon hon 10");
}
else if (i == 10)
{
    printf("i bang 10");
}
else
{
    printf("i nho hon 10");
}
```
Output:

`i bang 10`
  
#### 3.4. switch case
Cú pháp:
```c
switch (expression)
​{
   case constant1:
     // statements
     break;
   case constant2:
     // statements
     break;
   default:
     // default statements
}
```
- `expression` sẽ được so sánh với các giá trị của các `case`.
- Nếu giá trị của `case` khớp với `expression`, các khối lệnh tương ứng sau case đó sẽ được thực hiện cho tới khi gặp lệnh `break`.
- Nếu không sử dụng `break` thì tất cả các case kể từ case khớp giá trị đều được thực hiện.
- `default` sẽ được thực hiện nếu không có case nào khớp giá trị với `expression`.

Ví dụ:
```c
int i = 2;

switch (i)
{
case 1:
    printf("case 1");
    break;

case 2:
    printf("case 2");
    break;
    
default:
    printf("default");
    break;
}
```
Output:

`case 2`

***
### 4. enum
Kiểu liệt kê `enum` là một kiểu dữ liệu do người dùng tự định nghĩa, dùng để gán tên cho các giá trị hằng số.

Ví dụ:
```c
#include <stdio.h>

enum var {
    var_1,
    var_2,
    var_3
};

int main(int argc, char const *argv[])
{
    printf("var_1 = %d\n", var_1);
    printf("var_2 = %d\n", var_2);
    printf("var_3 = %d\n", var_3);

    return 0;
}
```
Output:
```c
  var_1 = 0
  var_2 = 1
  var_3 = 2
```
***
### 5. Vòng lặp
#### 5.1. for
Cú pháp:
```c
for(khai báo giá trị ban đầu; điều kiện lặp; toán tử)
{
  // Khối lệnh cần lặp
}
```
- B1: Khởi tạo giá trị ban đầu.
- B2: Kiểm tra điều kiện lặp. Nếu đúng thì thực hiện khối lệnh cần lặp. Nếu sai thì kết thúc vòng lặp.
- B3: Thực hiện toán tử, trở lại B2.

Ví dụ:
```c
for (int i = 0; i < 5; i++)
{
    printf("%d  ", i);
}
```
Output:

`0  1  2  3  4`

* Ta có thể không cần khai báo giá trị ban đầu, điều kiện lặp, toán tử. Lúc này, vòng lặp `for(;;)` luôn luôn đúng và khối lệnh được lặp lại liên tục. Ta có thể sử dụng lệnh `break` để thoát khỏi vòng lặp.

Ví dụ:
```c
int i = 0;
for (;;)
{
    if (i == 5) break;
    printf("%d  ", i);
    i++;
}
```
Output:

`0  1  2  3  4`

* Ta có thể sự dụng lệnh `continue để bỏ qua một bước lặp bất kỳ.

Ví dụ:
```c
for (int i = 0; i < 5; i++)
{
    if (i == 2) continue;
    printf("%d  ", i);
}
```
Output:
```
0  1  3  4 
```
#### 5.2. while
Nếu không biết trước số vòng lặp, ta có thể sử dụng vòng lặp `while`.

Cú pháp:
```c
while(điều kiện lặp)
{
  // Khối lệnh cần lặp
}
```
Đầu tiên điều kiện lặp được kiểm tra. Nếu đúng, khối lệnh sẽ được thực thi và kiểm tra lại điều kiện để tiếp tục vòng lặp. Nếu sai sẽ kết thúc vòng lặp.

Ví dụ:
```c
int i = 0;
while (i < 5)
{
    printf("%d  ", i);
    i++;
}
```
Output:
```
0  1  2  3  4
```
#### 5.3. do while
Tương tự như vòng lặp `while` nhưng khối lệnh sẽ được thực thi trước rồi mới kiểm tra điều kiện lặp.

Cú pháp:
```c
do
{
    // Khối lệnh cần lặp
}
while (điều kiện lặp)
```
Ví dụ:
```c
int i = 0;
do
{
    printf("do ... while loop");
} while (i != 0);

printf("\n----------\n");

while (i != 0)
{
    printf("while loop");
}
```
Output:
```
do ... while loop
----------
```
Có thể thấy, chỉ có khối lệnh của vòng lặp `do while` được thực hiện.
***
</details>
    
<details>
<summary>Bài 2: Pointer</summary>
    
### 1. Khái niệm con trỏ (Pointer)
#### 1.1. Bộ nhớ lưu trữ biến 
Bộ nhớ RAM chứa rất nhiều ô nhớ, mỗi ô nhớ có kích thước 1 byte.    
Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu CPU 32 bit thì có 2^32 địa chỉ có thể đánh cho các ô nhớ trong RAM.    
<img src="https://gochocit.com/wp-content/uploads/2021/09/dia-chi-don-vi-nho-duoc-danh-dia-chi.png">    
Khi khai báo biến, trình biên dịch dành riêng một vùng nhớ với địa chỉ duy nhất để lưu biến. Trình biên dịch có nhiệm vụ liên kết địa chỉ ô nhớ đó với tên biến. Khi gọi tên biến, nó sẽ truy xuất tự động đến ô nhớ đã liên kết với tên biến để lấy dữ liệu. Các bạn phải luôn phân biệt giữa địa chỉ bộ nhớ và dữ liệu được lưu trong đó.    
![](https://gochocit.com/wp-content/uploads/2021/09/dia-chi-cua-bien-la-dia-chi-o-nho-dau-tien-687x159.png)    
Có thể lấy địa chỉ của một biến bằng cách sử dụng toán tử **&**.  
```c
int a = 10;
printf("Dia chi cua a: %p", &a);
```
```c
Dia chi cua a: 000000edb61ffb0c
```
Địa chỉ của biến bản chất cũng là một con số thường được biểu diễn ở hệ cơ số 16. Ta có thể sử dụng con trỏ (pointer) để lưu địa chỉ của các biến.    
#### 1.2. Con trỏ là gì?
Trong ngôn ngữ C/C++, **con trỏ (pointer)** là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.    
![](https://gochocit.com/wp-content/uploads/2021/09/con-tro-luu-dia-chi-cua-bien-374x245.png)    
Trong hình trên, biến **var** lưu giá trị 5 có địa chỉ là **0x61ff08**. Biến **pointVar** là biến con trỏ, lưu địa chỉ của biến **var** (trỏ đến vùng nhớ của biến var), tức là nó lưu giá trị **0x61ff08**.    
#### 1.3. Khai báo biến con trỏ
Cú pháp: `<kiểu dữ liệu> *<tên biến con trỏ>;`    
Ví dụ:
```c
char *ch1, *ch2;    // ch1 và ch2 là biến con trỏ, trỏ tới vùng nhớ kiểu char (1 byte).
int *p1, p2;        // p1 là biến con trỏ, trỏ tới vùng nhớ kiểu int (4 bytes), còn p2 là biến kiểu int bình thường.
```
#### 1.4. Khởi tạo biến con trỏ
- Một biến bất kỳ phải xác định 2 thứ: **địa chỉ của biến** và **giá trị của biến**. Biến con trỏ cũng thế.    
- Khi mới khai báo, biến con trỏ được đặt ở địa chỉ nào đó (không biết trước), chứa giá trị là một địa chỉ không xác định hoặc địa chỉ 0xCCCCCCCC – là một địa chỉ đặc biệt, cho biết con trỏ chưa được khởi tạo. Sử dụng toán tử **&** để đặt địa chỉ của một biến vào con trỏ.    
- Cú pháp: `<tên biến con trỏ> = &<tên biến>;`    
Ví dụ:
```c
int a, b;
int *pa, *pb;
pa = &a;
pb = &b;
```
#### 1.5. Sử dụng biến con trỏ
Ví dụ:
```c
#include <stdio.h>

int main()
{
    int a = 10;
    int *pa = &a;
    // Dia chi
    printf("Gia tri cua con tro pa la dia chi cua bien a: %p\n", pa);
    printf("Dia chi cua bien a: %p\n", &a);
    // Gia tri
    printf("Gia tri cua vung nho ma con tro pa tro den: %d\n", *pa);
    printf("Gia tri cua bien a: %d\n", a);

    return 0;
}
```
Output:
```c
Gia tri cua con tro pa la dia chi cua bien a: 0000007b709ffd74
Dia chi cua bien a: 0000007b709ffd74
Gia tri cua vung nho ma con tro pa tro den: 10
Gia tri cua bien a: 10
```
***
### 2. Con trỏ hàm (Function Pointer)
- Con trỏ không chỉ lưu địa chỉ của một biến mà còn có thể lưu địa chỉ của các đối tượng khác như mảng, hàm,... Một biến con trỏ lưu địa chỉ của một hàm ta gọi nó là con trỏ hàm. Thông qua con trỏ hàm, ta có thể gọi hàm mà nó trỏ tới.    
- Cú pháp: `<kiểu trả về> (*<tên con trỏ>)(<danh sách kiểu dữ liệu của các thông số đầu vào>)`    
Ví dụ:
```c
#include <stdio.h>

void tong (int a, int b){
    printf("Tong %d va %d la: %d", a, b, a+b);
}

int main()
{
    void (*ptrTong)(int, int) = &tong;    // Con trỏ ptrTong có kiểu trả về là void, tham số truyền vào có kiểu integer và integer
    ptrTong(6, 9);
    
    return 0;
}
```
Output:
```c
Tong 6 va 9 la: 15
```
Bên cạnh đó, ta có thể sử dụng con trỏ hàm để truyền vào một hàm.
Ví dụ:
```c
#include <stdio.h>

void tong (int a, int b){
    printf("Tong %d va %d la: %d", a, b, a+b);
}

void tinhtoan (int a, int b, void (*pheptinh)(int ,int)){
    pheptinh(a, b);
}

int main()
{
    tinhtoan(5, 7, &tong);

    return 0;
}
```
Output:
```c
Tong 5 va 7 la: 12
```
***
### 3. Con trỏ void
- Con trỏ chỉ có thể trỏ đến địa chỉ có kiểu dữ liệu của giá trị trùng với kiểu dữ liệu của con trỏ đó. Ví dụ con trỏ int chỉ có thể trỏ đến địa chỉ có giá trị kiểu int, con trỏ char chỉ có thể trỏ đến địa chỉ có giá trị kiểu char.
- Tuy nhiên ta có thể sử dụng con trỏ void để trỏ đến địa chỉ của bất kì kiểu dữ liệu nào.
- Để in ra giá trị mà con trỏ void trỏ đến, ta phải ép kiểu con trỏ void về kiểu của giá trị mà con trỏ void trỏ đến.     
Ví dụ:
```c
#include <stdio.h>

int tong (int a, int b){
    return a + b;
}

int main()
{
    void *ptr;

    int i = 10;
    ptr = &i;
    printf("Dia chi cua i: %p, Gia tri cua i: %d\n", ptr, *((int *)ptr));

    float f = 12.5;
    ptr = &f;
    printf("Dia chi cua f: %p, Gia tri cua f: %f\n", ptr, *((float *)ptr));

    char c = 'A';
    ptr = &c;
    printf("Dia chi cua c: %p, Gia tri cua c: %c\n", ptr, *((char *)ptr));
    
    ptr = &tong;
    printf("Dia chi cua tong: %p, Gia tri cua tong: %d\n", ptr, ((int (*)(int, int))ptr)(5, 7));

    return 0;
}
```
Output:
```c
Dia chi cua i: 000000f0aa9ffac4, Gia tri cua i: 10
Dia chi cua f: 000000f0aa9ffac0, Gia tri cua f: 12.500000
Dia chi cua c: 000000f0aa9ffabf, Gia tri cua c: A
Dia chi cua tong: 00007ff759cd1591, Gia tri cua tong: 12
```
***
### 4. Con trỏ NULL
Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.    
```c
int *p2;//con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
int *p3 = NULL;//con trỏ null không trỏ đến vùng nhớ nào
```
Khi khởi tạo con trỏ NULL, chữ **NULL** phải viết hoa, viết thường **null** sẽ bị lỗi.    
***
### 5. Con trỏ cấp 2 (Pointer to pointer)
Con trỏ cấp 2 (Pointer to pointer) là một loại con trỏ dùng để lưu trữ địa chỉ của 1 biến con trỏ khác.    
Ví dụ:
```c
int a = 10;
int *ptr = &a;
int **ptp = &ptr;

printf("- Gia tri cua ptp la dia chi cua ptr: %p\n", ptp);
printf("  Dia chi cua ptr: %p\n", &ptr);
printf("- Gia tri ma ptp tro den la dia chi cua a: %p\n", *ptp);
printf("  Dia chi cua a: %p\n", &a);
printf("- Gia tri tai dia chi ma ptp tro den: %d\n", **ptp);
printf("  Gia tri cua a: %d\n", a);
```
Output:
```c
- Gia tri cua ptp la dia chi cua ptr: 000000c9689ffc98
  Dia chi cua ptr: 000000c9689ffc98
- Gia tri ma ptp tro den la dia chi cua a: 000000c9689ffca4
  Dia chi cua a: 000000c9689ffca4
- Gia tri tai dia chi ma ptp tro den: 10
  Gia tri cua a: 10
```
***
</details>

<details>
<summary>Bài 3: Phân vùng nhớ</summary>
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/50/Program_memory_layout.pdf/page1-225px-Program_memory_layout.pdf.jpg">
    
### 1. Phân vùng text
– Quyền truy cập chỉ Read và nó chứa lệnh để thực thi nên tránh sửa đổi instruction.
– Chứa khai báo hằng số trong chương trình (.rodata).
### 2. Phân vùng data
– Quyền truy cập là read-write.
– Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.
– Được giải phóng khi kết thúc chương trình.
### 4. Phân vùng Bss
– Quyền truy cập là read-write.
– Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.
– Được giải phóng khi kết thúc chương trình.
### 5. Phân vùng Stack
– Quyền truy cập là read-write.
– Được sử dụng cấp phát cho biến local, input parameter của hàm,…
– Sẽ được giải phóng khi ra khỏi block code/hàm
### 6. Phân vùng Heap
– Quyền truy cập là read-write.
– Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
– Sẽ được giải phóng khi gọi hàm free,...
***
</details>

<details>
<summary>Bài 4: Các dạng khai báo biến đặc biệt</summary>

### 1. Static
- Biến static hay biến tĩnh, được tạo ra bên trong một khối lệnh có khả năng lưu giữ giá trị của nó cho dù chương trình đã chạy ra bên ngoài khối lệnh chứa nó.
- Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm.
- Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
- Cú pháp: `static <kiểu dữ liệu> <tên biến>;`
     
Ví dụ:    
Không sử dụng static:
```c
#include <stdio.h>

void sum()
{
    int i = 0;
    i++;
    printf("i = %d\n", i);
}

int main(int argc, char const *argv[])
{
    sum();
    sum();
    sum();
    return 0;
}
```
```c
i = 1
i = 1
i = 1
```
Sử dụng static:
```c
#include <stdio.h>

void sum()
{
    static int i = 0;
    i++;
    printf("i = %d\n", i);
}

int main(int argc, char const *argv[])
{
    sum();
    sum();
    sum();
    return 0;
}
```
```c
i = 1
i = 2
i = 3
```
***
### 2. Extern
Trong C, khi 1 biến đi sau từ khóa “extern” có nghĩa là:
- Nó là tham chiếu của một biến,hàm cùng tên nào đó, đã được định nghĩa bên ngoài. Nó chỉ khai báo chứ không định nghĩa ( cấp phát bộ nhớ cho biến ).
- Biến được tham chiếu phải được khai báo ở cấp độ cao nhất (toàn cục), và có thể nằm trong một file khác.
Trong C, một chương trình lớn có thể được chia thành các module nhỏ hơn, các module này có thể được biên dịch riêng lẻ và được liên kết lại với nhau. Điều này được thực hiện nhằm tăng tốc độ quá trình biên dịch các chương trình lớn.

Tuy nhiên, khi các module được liên kết, các tập tin phải được chương trình thông báo cho biết về các biến toàn cục được yêu cầu. Một biến toàn cục chỉ có thể được khai báo một lần. Nếu hai biến toàn cục có cùng tên được khai báo trong cùng một tập tin, một thông điệp lỗi ‘duplicate variable name’ (tên biến trùng) có thể được hiển thị hoặc đơn giản trình biên dịch C chọn một biến khác.

Để sử dụng được biến toàn cục ở một file khác, chúng ta phải khai báo lại biến và thêm từ khóa extern phía trước, để báo rằng biến này đã được khi báo ở file khác.

Cú pháp: `extern <kiểu dữ liệu> <Tên Biến>;`

Lưu ý:
- Khi sử dụng extern, không được khai báo giá trị ban đầu cho biến.
- Extern không thể tham chiếu được các biến static của file khác.

Ví dụ:    
File 1 ta khai báo các biến và hàm:
```c
#include <stdio.h>

int value = 0;

void check()
{
    printf("Hello!\n");
}
```
Ở file 2, ta dùng extern để gọi các biến và hàm ở file 1:
```c
#include <stdio.h>

extern int value;

extern void check();

int main(int argc, char const *argv[])
{
    value = 20;
    printf("%d\n", value);

    check();

    return 0;
}
```
Kết quả:
```c
20
Hello!
```
***
### 3. Volatile
Volatile có nghĩa là không dự đoán được. Một biến sử dụng với volatile qualifier có nghĩa là nói với compiler là biến này có thể sẽ được thay đổi ở bất kì chỗ nào.

Một biến cần được khai báo dưới dạng biến volatile khi mà giá trị của nó có thể thay đổi một cách không báo trước. Việc khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler.

Cú pháp: `volatile <kiểu dữliệu> <tên dữ liệu>;`
***
### 4. Register
Tác dụng của từ khóa register, nói một cách ngắn gọn là làm tăng hiệu năng(performance) của chương trình.

Cú pháp: `register <kiểu dữ liệu> <tên biến>;`

Trong kiến trúc của vi xử lý thì ALU (Arithmetic Logic Unit) đóng vai trò xử lý các tính toán số học. Dữ liệu đưa vào làm việc với ALU phải chứa trong một vùng đặc biệt, gọi là các thanh ghi(register), và ALU chỉ làm việc với đống thanh ghi đó.

Trong khi đó các biến khai báo trong chương trình thì đặt ở bộ nhớ ngoài (RAM chẳng hạn …). Do đó với khai báo biến thông thường, để thực hiện một phép tính thì cần có 3 bước.
1. Nạp giá trị từ vùng nhớ chứa biến vào register
2. Yêu cầu ALU xử lý register vừa được nạp giá trị.
3. Đưa kết quả vừa xử lý của ALU ra ngoài vùng nhớ chứa biến.

![](https://khuenguyencreator.com/wp-content/uploads/2021/09/register-.jpg)

Khi thêm từ khóa register để khai báo biến, thì tức là ta đã yêu cầu trình biên dịch ưu tiên đặc biệt dành luôn vùng register để chứa biến đó. Và hiển nhiên khi thực hiện tính toán trên biến đó thì giảm được bước 1 và 3, giảm bớt thủ tục vậy nên hiệu năng tăng lên.
***
</details>

<details>
<summary>Bài 5: Struct/Union</summary>

</details>

<details>
<summary>Bài 6: Compiler</summary>

</details>

<details>
<summary>Bài 7: Macro</summary>
</details>

<details>
<summary>Bài 8: Function</summary>
</details>
