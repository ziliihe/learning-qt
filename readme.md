QLabel的继承关系是QObject→QWidget→QFrame→QLabel

main 函数作为程序的入口，主要功能是创建应用程序，创建窗口，显示窗口，运行应用程序，开始应用程序的消息循环和事件处理。

## 命名空间
- 在一个编译单元中，目标，类型，函数或者对象，只能有不超过一个定义
- 整个程序，一个对象或者非内联函数不能有超过一个定义
- 在不同的库中可能有不同的命名冲突，所以需要有一种方式来组织大型的库

> c++的命名空间的特点是避免和其他库或者定义冲突，同时其自身的定义可以跨多个文件定义到一个命名空间是吗？可以往标准库的比如std添加我们自己的定义吗？
```
是的，C++中命名空间的一个主要特点就是避免名称冲突，可以将同一命名空间内的一组相关的函数、类、变量等定义在一起，避免和其他库或者定义冲突。

同时，命名空间的定义可以跨多个文件进行，可以在不同的文件中定义同一个命名空间，只要这些定义通过头文件等方式在同一编译单元中被引用即可。

在C++中，标准库命名空间std是预定义的，包含了许多标准库的类、函数、变量等。虽然不建议修改标准库的定义，但在一些情况下，我们可以在std命名空间中添加自己的定义，比如定义一个std命名空间内的辅助函数或者重载某个std命名空间中的函数等。但是需要注意的是，由于标准库的实现可能会随着版本更新而发生变化，因此在向std命名空间中添加自己的定义时需谨慎，以避免与标准库的定义发生冲突。此外，建议将自己的定义放在自定义的命名空间中，以免影响标准库的定义。
```
可以多个命名空间嵌套
```
namespace outer {
    namespace my {
        class set {
        public:
            set() {
                std::cout << "class set" << std::endl;
            }
        };
    }
}

// 使用
outer::my::set v4;
```

为了避免命名空间污染，我们可以采取以下几种方式：
- 使用命名空间：将相关的函数、类、变量等定义在一个命名空间内，避免与其他库或者定义冲突。
- 使用局部变量：将变量定义在函数内部或者代码块内部，避免将变量定义为全局变量。
- 使用静态变量：将变量定义为static，使其只在当前文件中可见，避免将变量定义为全局变量。
- 使用类和对象：将函数和变量封装在类内部，避免定义全局变量和函数。

尽量限定相关函数、类型、变量、对象的范围，避免将它们定义为全局变量或函数，可以有效避免命名空间污染的问题。

命名空间别名
```cc
namespace atest = outer::my;
atest::set v5;
```

命名空间内联(inline):
- 在命名空间 A 中嵌套一个内联的命名空间 B, 那么可以通过 A::xxxx 直接访问 B 中的所有命名，也可以通过 A::B::xxxx 访问
- 便于库的版本管理
```cc
namespace MyLib {
  inline namespace Utils {
    int add(int a, int b) { return a + b; }
    int sub(int a, int b) { return a - b; }
    int version = 2;
    
    inline namespace v2 {
      int mul(int a, int b) { return a * b; }
      int div(int a, int b) { return a / b; }
    }
  }
}
```
- 支持库的逐步替换：使用inline命名空间可以方便地逐步替换库的实现，因为新的实现可以直接添加到旧的命名空间中，而不会影响已有的代码。访问新版本 MyLib::Utils::v2::mul(1, 2)， 不会影响旧版本访问  MyLib::Utils::add(1, 2)。

## Argument-Dependent Lookup (ADL)
根据函数参数类型在命名空间中查找函数的机制。
- 首先在当前作用域中查找函数
- 如果当前作用域中找不到函数，则在包含当前作用域的命名空间中查找函数
- 如果包含当前作用域的命名空间中也找不到函数，则在与函数参数类型相关联的命名空间中查找函数
- 如果与函数参数类型相关联的命名空间中也找不到函数，则在全局命名空间中查找函数
```c
namespace A {
  struct X {};
  void f(X x) {}
}

int main() {
  A::X x;
  f(x); // 调用 A::f(A::X x)
  return 0;
}
```

## Q_OBJECT 宏
使用 Q_OBJECT 宏能够为一个类添加以下特性：

- 自动元对象：Q_OBJECT 宏会自动为类生成一个元对象，该元对象包含了类的信号和槽等元信息。元对象机制是 Qt 中的一种运行时反射机制，用于支持信号和槽、动态属性、对象名称等特性。
- 信号和槽机制：Q_OBJECT 宏可以为类声明信号和槽，这样就可以使用 Qt 的信号和槽机制进行对象间通信。通过使用信号和槽机制，我们可以实现对象之间的松耦合，从而提高代码的可维护性和可扩展性。
- RTTI 支持：Q_OBJECT 宏会启用类的运行时类型信息（RTTI）支持，从而可以在运行时获取类的类型信息，如类名等。

ui_widget.h是对widget.ui文件编译后自动生成的，widget.ui又是通过UI设计器可视化设计生成的。

objectName是窗体上创建的组件的实例名称，界面上的每个组件需要有一个唯一的 objectName，程序里访问界面组件时都是通过其objectName进行访问。

**信号和槽是 Qt 的核心机制之一，它们可以用于实现组件之间的通信和交互。**

qt 的布局，就是界面上组件的排列方式，使用布局可以使组件有规则地分布，并且随着窗体大小变化自动地调整大小和相对位置。

**GUI程序设计的主要内容就是对界面上各组件的信号的响应，只需要知道什么情况下发射哪些信号，合理地去响应和处理这些信号就可以了。槽（Slot）就是对信号响应的函数。槽函数可以与一个信号关联，当信号被发射时，关联的槽函数被自动执行**

信号与槽关联是用`QObject::connect()`函数实现的。--> `QObject::connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));`QObject是所有Qt类的基类。

SIGNAL和SLOT是Qt的宏，用于指明信号和槽，并将它们的参数转换为相应的字符串。

示例：`QObject::connect(btnClose, SIGNAL(clicked()), Widget, SLOT(close()));`

**一个信号可以连接多个槽**，当一个信号与多个槽函数关联时，槽函数按照建立连接时的顺序依次执行。

**多个信号可以连接同一个槽**，当其中一个信号触发时，会自动执行槽函数。


```c
QObject::connect(sender, SIGNAL(signal), receiver, SLOT(slot));
```
`sender`发送`signal`信号给`receiver`，然后`slot`槽函数对信号进行处理。

一个信号可以连接另外一个信号，当一个信号发射时，也会发射另外一个信号:
```c
connect(spinNum, SIGNAL(valueChanged(int)), this, SIGNAL(refreshInfo(int));
```
一个信号可以连接到多个槽函数和/或信号上，而一个槽函数和/或信号也可以连接到多个信号上。

**在使用信号与槽的类中，必须在类的定义中加入宏 Q_OBJECT**

信号与槽的参数个数和类型需要一致，至少信号的参数不能少于槽的参数。

当一个信号被发射时，与其关联的槽函数通常被立即执行，就像正常调用一个函数一样。只有当信号关联的所有槽函数执行完毕后，才会执行发射信号处后面的代码。

`connectSlotsByName(QWDialog)`函数将搜索`QWDialog`界面上的所有组件，将信号与槽函数匹配的信号和槽关联起来，它假设槽函数的名称是，`void on_<object name>_<signal name>(<signal parameters>);`

增加信号和槽的关联，可以通过界面设计通过组件跳转`转到槽`设计，这里是通过`connectSlotsByName`方式来做到；还可以通过界面操作，进入`编辑信号/槽函数`模式，选择组件拖动到空白处添加对应的关联关系，自动会在 UI 头文件中添加`connect`方法。