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
  
    Gia tri cua var: 10
    
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
  
    Gia tri cua var: 100
    
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

    i lon hon 10

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

    i nho hon 10
    
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

    i bang 10
    
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
  
    case 2

  ***
  ### enum
  
  ***
  ### Vòng lặp
  
  #### 1. for
  
  #### 2. while
  
  #### 3. do while
  
  ***
</details>
