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
  output:
  
    Gia tri cua var: 10
  ***
  ### typedef
  
  ***
  ### Câu điều kiện
  #### 1. if
  
  #### 2. else
  
  #### 3. else if
  
  #### 4. switch case
  
  ***
  ### enum
  
  ***
  ### Vòng lặp
  
  #### 1. for
  
  #### 2. while
  
  #### 3. do while
  
  ***
</details>
