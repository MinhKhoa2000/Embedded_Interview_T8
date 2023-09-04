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

![](http://www.avr-asm-tutorial.net/avr_gra/sram.gif)

Khi thêm từ khóa register để khai báo biến, thì tức là ta đã yêu cầu trình biên dịch ưu tiên đặc biệt dành luôn vùng register để chứa biến đó. Và hiển nhiên khi thực hiện tính toán trên biến đó thì giảm được bước 1 và 3, giảm bớt thủ tục vậy nên hiệu năng tăng lên.
***
</details>

<details>
<summary>Bài 5: Struct/Union</summary>

### 1. Struct
Structure trong C là một kiểu dữ liệu do người dùng tự định nghĩa cho phép lưu trữ các loại phần tử khác nhau.

Mỗi phần tử của một cấu trúc được gọi là một thành viên (member).

Cú pháp:
```c
struct structure_name {
    data_type member1;
    data_type member2;
    ...
    data_type memeberN;
};
```
Ví dụ:
```c
struct SinhVien {
    int id;
    char name[50];
    char class[10];
} sv1, sv2;
```
Ta có thể truy cập các thành viên trong con trỏ bằng cách khai báo toán tử `.` hoặc `->` (đối với con trỏ).

Ví dụ:
```c
sv1.id = 100;
sv1.name = "Nam";
sv1.class = "ABC123";
```
***
### 2. Union
Cũng giống như structure, union trong C là kiểu dữ liệu do người dùng định nghĩa được sử dụng để chứa các loại phần tử khác nhau, nhưng nó cho cho phép các thành viên sử dụng chung địa chỉ.

Điều này có nghĩa khi thay đổi giá trị một thành viên sẽ ảnh hưởng tới giá trị của các thành viên khác.

Cú pháp:
```c
union union_name {
    data_type member1;
    data_type member2;
    ...
    data_type memeberN;
};
```
Cách khai báo và truy cập các thành viên của union tương tự như khi sử dụng structure.
***
### 3. Tổ chức bộ nhớ của struct và union
Cả struct và union đều được dùng lưu giá trị của nhiều đối tượng, tuy nhiên chúng có sự khác nhau về mặt quản lý bộ nhớ:
- Mỗi thành viên trong struct được lưu trữ ở các vùng nhớ khác nhau. Kích thước của struct là tổng độ lớn của các vùng nhớ này.
- Các thành viên trong union dùng chung một vùng nhớ. Kích thước của union bằng độ lớn của vùng nhớ này.

**Đối với struct:**

Ta xét ví dụ sau:
```c
#include <stdio.h>

typedef struct
{
    int i;      // 4 byye
    float f;    // 4 byte
    char c[5];  // 4 byte + 1 byte + 3 byte padding = 8 byte
} struct_Data;  // 4 + 4 + 8 = 16 byte

int main()
{
    printf("size truct: %d\n", sizeof(struct_Data));
}
```
Kết quả:
```
size truct: 16
```
Đối với struct trên, int có kích thước 4 byte, float là 4 byte, char là 1 byte, vì thế kích thước mong đợi là 4 + 4 + 5 = 13 byte. Tuy nhiên thực tế kích thước nhận được là 16 byte.

Đầu tiên trình biên dịch sẽ lấy kích thước của kiểu dữ liệu lớn nhất (ở đây là 4 byte), sau đó cấp phát 1 block bằng đúng 4 byte cho biến i, cấp tiếp 4 byte cho biến f, đối với mảng c có 5 ký tự, trình biên dịch cấp 4 byte cho 4 ký tự đầu tiên, cấp tiếp 4 byte để lưu ký tự thứ 5 nên sẽ dư ra 3 byte đệm.

Vì vậy struct trên sử dụng 13 byte và dư 3 byte, tổng là 16 byte.

Ta xét thêm một ví dụ:
```c
typedef struct
{
    int i;      // 4 byye
    char c1;    // 1 byte + 3 byte padding = 4 byte
    char c2;    // 1 byte -> padding of c1 = 0 byte
} struct_Data;  // 4 + 4 = 8 byte
```
Đối với ví dụ trên, kiểu dữ liệu có kích thước lớn nhất là int (4 byte). Tương tự như ví dụ đầu tiên, trình biên dịch sẽ cấp 1 block 4 byte cho biến i, cấp 4 byte tiếp theo cho biến c1. Do c1 chỉ sử dụng 1 byte nên còn dư 3 byte. Do còn dư 3 byte chưa sử dụng nên trình biên dịch sẽ "đẩy" biến c2 có kích thước 1 byte vào, dư lại 2 byte.

Vì thế struct trên sử dụng 6 byte và dư 2 byte, tổng là 8 byte.

**Đối với union**

Xét ví dụ sau:
```c
typedef union
{
    int i;
    char c[5];
} union_Data;
```
Tương tự như struct, trình biên dịch chọn kích thước của của kiểu dữ liệu có kích thước lớn nhất để cấp phát ô nhớ.

Đối với ví dụ trên, đầu tiên trình biên dịch cấp 4 byte nhớ, vừa đủ để lưu biến i nhưng lại dư ra 1 ký tự của mảng c. Trình biên dịch sẽ tiếp tục cấp thêm 4 byte để lưu ký tự này và dư ra 3 byte đệm. Tổng số byte được cấp cho union này là 8 byte.
***
</details>

<details>
<summary>Bài 6: Compiler</summary>

</details>

<details>
<summary>Bài 7: Macro</summary>

**1.** Khi ta sử dụng chỉ thị #include, nội dung chứa trong header file sẽ được sao chép vào file hiện tại.
Khi include sử dụng dấu ngoặc nhọn < > thì preprocessor sẽ được dẫn tới Include Directory của Compiler.

#include <file>

Còn khi sử dụng dấu ngoặc kép " " thì preprocessor sẽ tìm kiếm file trong thư mục cùng chứa với file chương trình của bạn

#include “file”
***
**2.**  Một Macro có thể coi là một loại viết tắt. Trước khi sử dụng một macro, bạn phải định nghĩa nó rõ ràng bằng chỉ thị #define, cấu trúc như ví dụ sau:

`#define BUFFER_SIZE 1020`

Ví dụ trên sẽ định nghĩa macro có tên ‘BUFFER_SIZE’ là viết tắt của ‘1020’.

Nếu sau lệnh #define này có xuất hiện macro ‘BUFFER_SIZE’ thì bộ Preprocessor thay thế bằng ‘1020’.

Ví dụ:
```c
#inclde <stdio.h>
#define BUFFER_SIZE 1020
int main()
{
printf(“buffer size is %d”, BUFFER_SIZE );
return 0;
}
```
Output: 
```
buffer size is 1020
```
***
**3.** Macro có thể là hàm chứa các tham số, các tham số này sẽ không được kiểm tra kiểu dữ liệu.

Ví dụ, macro INCREMENT(x) ở dưới, x có thể là bất cứ kiểu dữ liệu nào.
```c
#inclde <stdio.h>
#define INCREMENT(x) ++x
int main()
{
char *ptr = “12345”;
int x = 99;
printf(“%s\n”, INCREMENT(ptr));
printf(“%d\n”, INCREMENT(x));
return 0;
}
```
Output:
```
2345
100
```
***
**4.** Preprocessor chỉ thực hiện thay thế các macro chứ không thực hiện các phép tính toán.

Ta có ví dụ như sau:
```c
#include <stdio.h>
#define CALC(X,Y) (X*Y)
int main()
{
printf(“%d\n”,CALC(1+2, 3+4));
return 0;
}
```
Output:
```
11
```
Có thể thấy kết quả mong muốn là 21, tuy nhiên lại bằng 11.

Bởi vì các tham số sẽ được tính toán sau khi được thay thế nên macro CALC(1+2,3+4) sẽ trở thành (1+2*3+4) = (1+6+4) =(11).

Vậy để kết quả được tính đúng thì ta phải sửa lại như sau:
```c
#include <stdio.h>
#define CALC(X,Y) (X)*(Y)
int main()
{
printf(“%d\n”,CALC(1+2, 3+4));
return 0;
}
```
Output:
```
21
```
***
**5.** Các tokens được truyền cho các macro có thể được nối bằng cách sử dụng toán tử ## (còn được gọi là toán tử Token-Pasting)

Ví dụ:
```c
#include <stdio.h>
#define merge(X,Y) X##Y
int main()
{
printf(“%d\n”,merge(12, 34));
return 0;
}
```
Output:
```
1234
```
***
**6.** Một token được truyền cho macro có thể được chuyển thành một chuỗi kí tự bằng cách sử dụng dấu # trước nó

Ví dụ:
```c
#include <stdio.h>
#define convert(a) #a
int main()
{
printf(“%s”,convert(Hello!));
return 0;
}
```
Output:
```
Hello!
```
***
**7.** Các macro có thể được viết trong nhiều dòng bằng cách sử dụng dấu ‘\’. Dòng cuối cùng không cần có dấu ‘\’.

Ví dụ:
```c
#include <stdio.h>
#define PRINT(i,limit) while (i<limit)     \
                        {                  \
                        printf(“123 ”);    \
                        i++;               \
                        }
int main()
{
int i=0;
PRINT(i,3);
return 0;
}
```
Output:
```
123 123 123
```
***
**8.** Bộ Preprocessor có hỗ trợ các chỉ thị #if - #else nhằm sử dụng các macro làm các điều kiện thực thi lệnh

Ví dụ:
```c
#include <stdio.h>
#define NUMBER 3
int main()
{
#if NUMBER >= 2
printf(“Hello World!!!”);
#else
printf(“No define”);
#endif
}
```
Output:
```
Hello World!!!
```
***
**9.** Một header file có thể được thêm vào nhiều hơn 1 lần, điều này sẽ dẫn đến khai báo lại nhiều biến, hàm giống nhau và xuất hiện lỗi khi biên dịch. Để tránh vấn đề này, nên sử dụng #defined, #ifdef và #ifndef

Ví dụ:
```c
#include <stdio.h>
#ifndef MATH_H
#define MATH_H
#include <math.h>
int main()
{
int a=9;
printf(“%d”, sqrt(a));
}
#endif
```
Output:
```
3.000000
```
***
**10.** `__VA_ARGS__`

Ví dụ:
```c
#define SUM(...) printf ("SUM: ", __VA_ARGS__)
```
Macro này gọi là variadic. Khi macro này được gọi, tất cả những thứ gì nằm trong dấu "..." sẽ được thay thế hết vào `__VA_ARGS__`.
```c
SUM(1 + 2);
//Sẽ được thay thế thành:
printf ("SUM: ", 1 + 2);
```
Output:
```
SUM: 3
```
***
</details>

<details>
<summary>Bài 8: Function</summary>
</details>
