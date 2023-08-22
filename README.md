# Embedded_Interview_T8
## C Programming
<details>
<summary>C cơ bản</summary>

### Kiểu dữ liệu
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
### typedef
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
### Câu điều kiện
#### 1. if
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

#### 2. if ... else
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
  
#### 3. else if
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
  
#### 4. switch case
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
### enum
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
### Vòng lặp
#### 1. for
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
#### 2. while
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
#### 3. do while
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
