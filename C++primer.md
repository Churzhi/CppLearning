# **C++** primer

```c++
#include<iostream>

int main() 
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;
    return 0;
}
```



# 1.控制流

## 1.1`while`语句

- 求1到10个数之和

  ```c++
  #include<iostream>
  
  int main() 
  {
      int sum = 0, val = 1;
    //只要val小于等于10，while循环会持续执行
      while (val <= 10)
      {
          sum += val;//将sum + val 赋予 sum
          ++val;     //将val加1
      }
      std::cout << "Sum of 1 to 10 inclusive is "
                << sum << std::endl;
      return 0;
  }
  ```

  

## 1.2`for`语句

- 求1到10个数之和

  ```c++
  int main() 
  {
      int sum =0;
      for (int val = 1; val <= 10; val++)
      {
          sum += val;
      }
      std::cout << "Sum of 1 to 10 inclusive is "
                << sum << std::endl;
      return 0;
  }
  ```

- `for` 循环的执行流程

  - 创建变了val，将其初始化为1。
  - 检测val是否小于等于10。若检测成功，执行`for`循环体。若失败，退出循环，继续执行`for`循环体后的第一条语句。
  - 将val的值增加1。
  - 重复第二步中的条件检测，只要条件为真就继续执行剩余步骤。

## 1.3`if`语句

- 统计输入每个数中连续出现多少次

  ```c++
  #include<iostream>
  int main() 
  {
    //currVal正在统计的数，val输入的新值
    int currVal = 0, val = 0;
    if (std::cin >> currVal)
    {
      int cnt = 1;
      while (std::cin >> val)
      {
        if (val == currVal)
        {
          ++cnt;
        }
        else
        {
          std::cout << currVal << " occurs "
                    << cnt << " times " << std::endl;
            currVal = val;
            cnt = 1; 
        }
      }
      std::cout << currVal << "occurs"
                << cnt << " times " << std::endl;
    }
    return 0;
    
  }
  ```

## 1.4类简介

在C++中，通过定义一个**类（class）**来定义自己的数据结构。一个类定义了一个类型，以及与其关联的一组操作。

- 类名是什么？

- 它在哪里定义？

- 它支持什么操作？

  ```c++
  #include<iostream>
  #include "Sales_item.h"
  int main()
  {
      Sales_item book;
      //读入ISBN号、售出的册数以及销售价格
      std::cin >> book;
      //写入ISBN号、售出的册数、总销售额和平均价格
      std::cout << book << std::endl;
      return 0;
  
  }
  ```

- 书本例子`Sales_item`对象的加法

  ```c++
  #include<iostream>
  #include "Sales_item.h"
  int main()
  {
      Sales_item item1, item2;
      //读入ISBN号、售出的册数以及销售价格
      std::cin >> item1 >> item2;
      //写入ISBN号、售出的册数、总销售额和平均价格
      std::cout << item1 + item2 << std::endl;
      return 0;
  
  }
  //结果：
   churzhi@zhouchuzhideMacBook-Pro  ~/VSCode/c++第一章  cd "/Users/churzhi/VSCode/c++第一章/" && g++ Sales_item.cpp -o Sales_item && "/Users/churzhi/VSCode/c++第一章/"Sales_item
  0-201-78345-X 3 20.00
  0-201-78345-X 2 25.00
  
  0-201-78345-X 5 110 22
  ```


## 1.5成员函数

- 将两个`Sales_item`对象相加的程序首先应该检查两个对象是否具有相同的ISBN。

```c++
#include<iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    //读入ISBN号、售出的册数以及销售价格
    std::cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn()) {
        //写入ISBN号、售出的册数、总销售额和平均价格
    std::cout << item1 + item2 << std::endl;
    }else {
        std::cout << "Data must refer to same ISBN "
                  << std::endl;
    }
    return 0;

}
```

> `item1.isbn() == item2.isbn()`调用名为`isbn`的成员函数（member function）。成员函数是定义为类的一部分的函数，有时也称为 **方法**（**method**）。
>
> 通常以一个类对象的名义来调用成员函数。
>
> 例如`item1.isbn()`
>
> 使用**点运算符（.）**来表达我们需要“名为`item1`的对象的`isbn`成员”。点运算只能用于类类型的对象。运算结果为右侧运算对象指定的成员。

- 读取多条销售记录，并统计每个isbn（每本书）有几条销售记录

```c++
#include<iostream>
#include "Sales_item.h"
/*
*读取多条销售记录，并统计每个isbn（每本书）有几条销售记录
*/
int main()
{
    Sales_item curr_item,next_item;
    if (std::cin >> curr_item) {
        int cnt = 1;
        while(std::cin >> next_item) {
        if (curr_item.isbn() == next_item.isbn()) {
            ++cnt;
        }
        else {
            std::cout << "书号为: " << curr_item.isbn()
                      << "的书销售了" << cnt << "次" << std::endl;
            curr_item = next_item;
            cnt = 1;
        }
    }
    std::cout << "书号为: " << curr_item.isbn()
                      << "的书销售了" << cnt << "次" << std::endl;
    }
    return 0;
}
```

# 2.变量和基本类型

<u>C++是一种静态数据类型语言，它的类型检查发生在编译时，因此，编译器必须知道程序中每一个变量对应的数据类型。</u>

## 2.1算术类型

| bool        | 布尔类型       | 最小尺寸                   |
| ----------- | -------------- | -------------------------- |
| bool        | 布尔类型       | 未定义（ 1 字节）          |
| char        | 字符           | 8位（ 1 字节）             |
| wchar_t     | 宽字符         | 16位（ 2 字节）            |
| char16_t    | Unicode字符    | 16位（ 2 字节）            |
| char32_t    | Unicode字符    | 3位（ 2 字节）             |
| short       | 短整形         | 16位（ 2 字节）            |
| int         | 整形           | 16位（ 4 字节）            |
| long        | 长整形         | 32位（ 4 字节）            |
| long long   | 长整形         | 64位（ 8 字节）            |
| float       | 单精度浮点数   | 6位有效数字（4字节）       |
| double      | 双精度浮点数   | 10位有效数字（8字节）      |
| long double | 扩展精度浮点数 | 10位有效数字（12字节）**** |

练习2.1：类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？

```c++
(1)int和short类型最小尺寸为16位，long类型为32位，long long类型为64位。
(2)无符号类型仅可表示大于0的数值，带符号类型可以表示正数、负数、0。
  （char类型中，unsigned char与char不相等）
(3)float为单精度浮点类型，double为双精度浮点类型，通常float和double以16位和32位来表示，
  且float和double分别具有7和16个有效位。
```



## 2.2带符号类型和无符号类型

- **带符号类型**可以表示正数、负数或 0 ，**无符号类型**仅能表示大于等于 0 的值。

- 选择类型的经验：
  1 当明确知晓数值不可能为负时，选用无符号类型。
  2 使用int执行整数运算，如果溢出，则使用long long。
  3 在算术表达式中不使用char或bool类型，仅在存放字符或布尔值时才使用它们。
  4 执行浮点运算时选用double。

## 2.3类型转换规则

- 非布尔转布尔型：值为0，转为False，否则为True；
- 布尔转非布尔型：值为False，转为0，值为True，转为1；
- 浮点型转整型：做近似处理，仅保留小数点之前部分；
- 整型转浮点型：小数部分记为0；
- 当赋一个超出其范围的值给无符号类型时，结果为初始值对无符号类型表示数字总数取模后的余数；
- 当给带符号类型赋超过其表示范围的数值时，其结果是未定义的，可能导致程序崩溃。
- **请勿混用带符号类型和无符号类型**：当表达式中既有带符号类型又有无符号类型时，带符号数会自动转换成无符号数。

## 2.4字面值常量

- 整型字面值
  - 形式：
    - 八进制：以0开头
    - 十进制：正常表示
    - 十六进制：以0x开头
  - 整型字面值可以有后缀：
    - u或U对应unsigned；
    - l或L对应long；
    - ll或LL对应long long。
- 浮点型字面值(默认double)
  - 形式：
    - 小数：如3.14159 .001
    - 科学计数法：指数部分用E或e标识，如0. 0e0 3.14159E0
  - 浮点型字面值可以有后缀：
    - f或F对应float；
    - l或L对应long double。
- 字符和字符串字面值
  - 形式：
    - 字符字面值：用单引号括起来，'a'
    - 字符串字面值：用双引号括起来，"abc"
    - 注意：字符串字面值实际上是由常量字符构成的数组，在每个字符串结尾处添加空字符'\0'，**字符串字面值的实际长度比它的内容多1**
  - 字符和字符串字面值可以有前缀：
    - u表示Unicode16字符
    - U表示Unicode32字符
    - L表示宽字符
    - u8表示UTF-8(仅用于字符串字面常量)
- 不能直接使用的字符：
  - 形式：
    - 不可打印的字符，如退格等控制字符，因为没有可视的图符
    - 转义序列：以反斜杠开始
    - 泛化转移序列：
      - 反斜杠\后紧跟1～3个数字
      - 反斜杠\x后紧跟一个或多个八进制数字
- 布尔字面值和指针字面值
  - true和false是布尔类型的字面值；
  - nullptr是指针字面值

## 2.5转义序列

| C++转义序列    |      |            |      |
| -------------- | ---- | ---------- | ---- |
| 换行符         | \n   | 横向制表符 | \t   |
| 纵向制表符     | \v   | 退格符     | \b   |
| 反斜线         | \\\  | 问号       | \?   |
| 回车符         | \r   | 进纸符     | \f   |
| 报警（响铃）符 | \a   | 双引号     | \\"  |
| 单引号         | \\'  |            |      |

## 2.6变量

- 定义形式：类型说明符 一个或多个变量名组成的列表，如int a; int a,b;
- 初始值：对象在创建时获得的一个特定的值，一旦定义即可马上使用 (在同一条定义语句中，也可以用先定义的变量值去初始化后定义的变量)
- **初始化不是赋值，初始化的含义是创建变量时赋予其一个初始值，而赋值的含义是把对象的当前值擦除，而以一个新值来替代。**
- 列表初始化的4种方式：
  - int units_sold = 0;
  - int units_sold = {0};
  - int units_sold{0};
  - int units_sold(0);

- 默认初始化：在定义变量时没有指定初值，变量被默认初始化。**若内置类型的变量未被显示初始化，则它的值是由定义的位置决定的。定义于任何函数体之外的变量初始化为0；在函数体内部的变量不被初始化(即值未定义)，在拷贝或访问此类值时将引发错误。**因此，**建议初始化每一个内置类型的变量。**

- 声明和定义：为了支持分离式编译（separate compilation），C++将声明和定义区分。声明使得名字为程序所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。定义负责创建与名字关联的实体。**变量的声明和定义都规定了变量的类型和名字，但是定义还可以申请存储空间，也可能为变量赋初值。**

  - 声明**extern**：`extern int i;`
  - 定义：`int j;`
  - 显式化的声明即为定义：`extern double pi = 3.14159： //定义`
  - **变量能且只能定义一次，但是可以被多次声明**
  - 在变量第一次被使用的附近定义它
  - 一条声明语句由一个**基本数据类型**和一个**声明符**列表组成。

- 变量命名规范：由字母、数字和下划线组成，必须以字母或下划线开头。

  - 定义在函体外的标识符不能以下画线开头

  - 标识符要体现实际含义
  - 变量名一般用小写字母
  - 用户自定义的**类名**一般以大写字母开头`Sales_item`
  - 如果标识符由多个单词组成，单词间应该有明显区分（下划线或首字母大写）`student_loan、studentLoan`

- **作用域**：以花括号{ }分隔

  - 外层作用域的变量内层可见
  - 全局作用域所有可见

## 2.7指针、引用、const

### 引用

- 引用并非对象，相反的，它只是为一个已经存在的对象所起的另外一个名字。

- 引用为对象起了别名，在定义引用时，程序将引用和它的初始值**绑定(bind)**，一旦初始化完成，**引用和它的初始化对象**一直绑定在一起，因此**引用必须初始化**。
- 定义： int i = 1024; int &r = i;

### 指针

- 指针实现对其他对象的间接访问，指针内存放着某个对象的地址。**建议初始化所有指针**

- 定义：

  - int *p1;
  - 获取对象的地址：int ival = 42; int *p2 = &ival;
  - 解引用*：如果指针指向了一个对象，可以使用**解引用操作符\*来访问指针指向的对象**
  - 空指针： int *p3 = nullptr;

- **辨析\*p 和 p：\*p是指针所指的对象，p是指针所指的对象的地址值。**

- 赋值语句改变了**指针的值？**or**指针所指对象的值？**

  - **赋值永远改变的是等号左侧的对象**

  - ```c++
    pi = &ival; //pi的值被改变，现在pi指向了ival
    *pi = 0; //ival的值被改变，指针pi并没有改变
    ```

- `void*`指针

  - 和别的指针比较
  - 作为函数的输入输出
  - 赋给另外一个`void*`指针
  - 不能直接操作`void*`指针所指的对象，因为我们并不知道这个对象到底是什么类型，也就无法确定可以在这个对象上面做哪些操作。

- 指针的值和指针所指对象的值的区别

  - ```c++
    #include <iostream>
    int main() {
        int i = 5, j = 10;
        int *p = &i;
        //p为指针所指对象i的地址值，*p此时输出所指向对象i的值 5
        std::cout << p << " " << *p << std::endl;
        p = &j;
        //p为指针所指对象j的地址值，*p此时输出所指向对象j的值 10
        std::cout << p << " " << *p << std::endl;
        *p = 20;//为指针所指对象j赋值 20
        //p为指针所指对象j的地址值，*p此时输出所指向对象j的值 20
        std::cout << p << " " << *p << std::endl;
        j = 30;//赋值
        //p为指针所指对象j的地址值，*p此时输出所指向对象j的值 30
        std::cout << p << " " << *p << std::endl;
        return 0;
    }
    //指针p的值一般为p所指对象的地址值
    
    //结果：
    0x7ffee598a578 5
    0x7ffee598a574 10
    0x7ffee598a574 20
    0x7ffee598a574 30
    ```

    



### 指针和引用的区别（补充）

- 指针本身是一个对象，引用只是对象的别名
- 指针在其生命周期内可以先后指向不同的对象，引用在初始化完成后，即和它的初始化对象绑定在一起。
- 指针无需在定义时赋初值，引用必须初始化。

### 指向引用的指针和指针的引用

- 指针的引用：指针必须指向一个对象，引用不是对象，故指针的引用不存在

- 指向引用的指针：

  ```c++
  int i = 42; 
  int &r = i; 
  int *p; 
  int *&r= p; // r为对指针p的引用
  ```

### const

- const对象必须初始化，一旦创建后其值就不能再改变
- const对象以初始化的方式定义时，在**编译过程**中把用到该const变量的地方都替换成对应的值。
- 默认状态下，const对象仅在文件内有效，如果想在多个文件之间共享const对象，必须在变量的定义之前添加extern(声明)。
- 定义：

```c++
 int const i = 42;         //编译时初始化
 int const j = get_size(); //运行时初始化
```

### const的引用

- 对常量的引用简称常量引用，在初始化常量引用时允许用任意表达式作为初始值，允许为一个常量引用绑定非常量的对象、字面值、一般表达式。
- 常量引用不允许通过引用修改其绑定对象的值，但可以通过其他途径修改其绑定对象的值（直接修改绑定对象的值，通过其他非常量引用修改等）。

### 指向常量的指针和常量指针

- 指向常量的指针：指针指向的对象的值不能变（*p不能变）
- 常量指针：指针的值（指针内存放的地址不能变）（p不能变）**const指针本质是一个const对象，const对象必须初始化**
- 定义：从右向左阅读
  - 指向常量的指针：const int *p; int const* p;
  - 常量指针：int *const p;

### 顶层const和底层const

- 定义
  - 顶层const（top-level const）：指针本身是个常量
  - 底层const（low-level const）：指针所指的对象是个常量
- 执行对象的拷贝操作时：
  - 1)**顶层const不受影响**；
  - 2)对于底层const而言:
    - 拷入和拷出的对象必须具有**相同的底层const资格**
    - 两个对象的数据类型必须能够转换。一般来说，**非常量可以转换为常量**，反之则不行。
- 用于声明引用的const都是底层const

## 2.8constexpr(常量表达式)

- 定义：值不会改变并且在编译过程就能得到计算结果的表达式。（在编译时运算，直接保存计算结果）
- constexpr所定义的对象为顶层const。

## 2.9类型别名

- 定义类型别名的两种方法：
  - typedef： typedef double wages; //wages等同于double
  - 别名声明（alias declaration）：using SI = Sales_item; //SI等同于Sales_item
- 在复合类型或常量中，在定义了别名后不要试图替换为本来的样子进行理解会造成错误。

## 2.10auto和decltype

- auto：让编译器代替分析表达式所属的类型。**通过初始值推算变量类型**
  - auto会忽略引用和顶层const，保留底层const
  - 在一条语句内定义多个变量时，初始值必须为同一类型
- decltype：在不用表达式的值初始化变量的情况下，从表达式的类型推断出要定义的变量的类型。**编译器分析表达式并得到他的类型，却不实际计算表达式的值**

# 3.标准库类型

### 3.1string

#### 3.1.1 习题：3.3**`string`和 `getline`函数

 **`string`和 `getline`函数处理字符串对空白字符处理的差异。**

​	标准库 string 的输入运算符自动忽略字符串开头的空白 （包括空格符、换行符、制表符等），从第一个真正的字符开始读起，直到遇见下一个空白为止。

​	如果希望在最终的字符串中保留输入时的空白符，应该使用`getline`函数代替原来的`>>`运算符，`getline`从给定的输入流中读取数据，直到遇到换行符为止，此时换行符也被读取出来，但不存储在最后的字符串中。

##### 练习3.6 使用`for`语句把字符串内的所有字符用 X 代替

```c++
#include <iostream>
#include <string>
using namespace std;
int main () {
    string s ;
    cout << "请输入一个字符串：" << endl;
    getline (cin, s);
    for (auto &c : s ) {
        c = 'X';
    }
    cout << s << endl;
    return 0;

}
```

##### 练习3.10 读入一个含标点符号的字符串，将标点符号去除后输出字符串

```c++
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
//for 遍历  逐行输出非标点符号字符 
int main () {
    cout << "请输入带标点符号的字符串：" << endl;
    string s;
    getline (cin, s);
    for (auto c : s) {
        if (!ispunct(c))
            cout << c;
    }
    cout << endl;
    return 0;
}

```

```c++
//遍历字符串，通过下标进行随机访问，把非标点字符拼接成新串输出
int main () {
    cout << "请输入带标点符号的字符串：" << endl; 
    string s, result;
    getline (cin, s);
    for (decltype(s.size()) i = 0; i < s.size(); i++) {
        if (!ispunct(s[i]))
            result += s[i];
    }
    cout << result << endl;
    return 0;
}
```



#### 3.1.2处理`string`对象中的字符

| cctype头文件中的函数 |                                                              |
| -------------------- | ------------------------------------------------------------ |
| `isalnum(c)`         | 当 c 是字母或数字时为真                                      |
| `isalpha(c)`         | 当 c 是字母时为真                                            |
| `iscntrl(c)`         | 当 c 是控制字符时为真                                        |
| `isdigit(c)`         | 当 c 是数字时为真                                            |
| `isgraph(c)`         | 当 c 不是空格但可以打印时为真                                |
| `islower(c)`         | **当 c 是小写字母时为真**                                    |
| `isprint(c)`         | 当 c 可以打印时为真（即 c 是空格或 c 具有可视形式）          |
| `ispunct(c)`         | 当 c 是标点符号时为真（即 c 不是控制字符、数字、字母、可打印空白中的一种） |
| `isspace(c)`         | 当 c 是空白时为真（即 c 是空格、横向制表符、纵向制表符、回车符、换行符、进纸符中的一种） |
| `isupper(c)`         | **当 c 是大写字母时为真**                                    |
| `isxdigit(c)`        | 当 c 是十六进制数字时为真                                    |
| `totower(c)`         | **如果 c 是大写字母，输出对应的小写字母：否则原样输出 c**    |
| `toupper(c)`         | 如果 c 是小写字母，输出对应的大写字母：否则原样输出 c        |

```c++
//使用范围for语句改变字符串中的字符
//改变string对象中的字符，必须把循环变量定义成引用类型

#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s ("Hello World!!!");
    for ( auto &c :s)
        c = toupper(c);
    cout << s << endl;
}
```

`string`对象的下标必须大于等于 0 而小于`s.size()`

```c++
/*只处理一部分字符
* 方法1:使用下标，方法2:迭代器
*/
```

### 3.2`vector`

#### 3.2.1标准库类型`vector`

`vector`表示对象的集合，其中所有对象的类型都相同，也称作 **容器**

#### 3.2.2 定义和初始化 `vector`对象

| 初始化 `vector`对象的方法     |                                                              |
| ----------------------------- | ------------------------------------------------------------ |
| `vector<T> v1; `              | `v1` 是一个空 `vector` ，它潜在的元素是 T 类型，执行默认初始化 |
| `vector<T> v2(v1); `          | `v2` 中包含有` v1` 所有的元素的副本                          |
| `vector<T> v2 = v1; `         | 等价于 `v2(v1)`，`v2` 中包含有 `v1` 所有的元素的副本         |
| `vector<T> v3(n, val); `      | `v3` 包含了 `n` 个重复的元素，每个元素的值是 val             |
| `vector<T> v4(n); `           | `v4` 包含了 `n` 个重复地执行了值初始化的对象                 |
| `vector<T> v5{a,b,c...}; `    | `v5` 包含了 初始值个数的元素，每个元素被赋予相应的初始值     |
| `vector<T> v5 = {a,b,c...}; ` | 等价于 `v5 {a, b, c ...}`                                    |

- 列表初始值

  - ```c++
    vector<int> v1(10);//v1有10个元素，每个的值都是0
    vector<int> v2{10};//v2有1个元素，该元素的值是10
    vector<int> v3(10, 1);//v3有10个元素，每个的值都是1
    vector<int> v4({10, 1}//v4有2个元素，值分别是10和1
                   
    vector<string> v5{"hi"};//列表初始化：v5有一个元素        
    vector<string> v6("hi");//错误：不能使用字符串字面值构建vector对象
    vector<string> v7{10};//v7有10个默认初始化的元素
    vector<string> v8{10, "hi"};//v8有10个值为”hi“的元素
    ```

    

##### 3.2.2.1习题

练习3.14

```c++
#include <iostream>
#include <vector>
using namespace std;
/**
 * 用cin存入一组整数 并把他们放入vector对象中
*/
int main () {
    int numbers = 0;
    vector<int> item;
    char cont = 'y';
    while (cin >> numbers) {
        item.push_back(numbers);
        cout << "你要继续吗?(y or n)" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto mem : item) 
        cout << mem << " " << endl;
    return 0;
}
```



练习3.15

```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//用cin存入一组字符串 并把他们放入vector对象中
int main () {
    string str;
    char cont = 'y';
    vector<string> Str_vector;
    while (cin >> str) {
        Str_vector.push_back(str);
        cout << "你要继续输入吗？（y or n）" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto Str : Str_vector) {
        cout << Str << " " << endl;
    }
    return 0;
}
```



### 3.3迭代器 `iterator`

#### 介绍

- 所有标准库容器都可以使用迭代器

- **`iterator`类似于指针类型，提供对对象的简介访问，使用迭代器可以访问某个元素，迭代器也能从一个元素移动到另外一个元素。**

- 迭代器有**有效**和**无效**之分
  - **有效的迭代器或者指向某个元素，或者指向容器中尾元素的下一位置；其他所有情况都为无效**



#### 使用

- 和指针不一样迭代器不是使用取地址符，迭代器的类型同时拥有返回迭代器的成员

**例如：**

```c++
/*
 *类型都有名为begin 和 and 的成员
 *其中 begin 成员负责返回指向第一个元素（或第一个字符）的迭代器
 */

//由编译器决定 b 和 e 的类型
//b 表示 v 的第一个元素，e 表示 v 尾元素的下一个位置
auto b = v.begin(), e = v.end();//b 和 e 类型相同
```

==尾元素的下一个位置：（one past the end）==

- 即该迭代器只是的是容器的一个本不存在的 “尾后（off the end）” 元素，仅作为标记，表示已经处理完容器中的所有元素 
- `end`成员返回的迭代器通常被称为**尾迭代器（end iterator）**
- 特殊情况下如果容器为空，则 `begin` 和 `end` 返回的是同一个迭代器，都是尾迭代器



#### 迭代器运算符

- `*iter` ----返回迭代器 iter 所指元素的引用
- `iter->mem`----解引用 iter 并获取该元素的名为 mem 的成员，等价于 `(*iter).mem`
- `++iter`----令 iter 指向容器中的下一个元素
- `--iter`----令 iter 指向容器中的上一个元素
- `iter1 == iter2  ；iter != iter2`----判断两个迭代器是否相等（不相等），如果两个迭代器指示的是同一个元素或者他们是同一个容器的尾迭代器，则相等；反之，不相等。

