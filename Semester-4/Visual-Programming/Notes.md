# Visual Programming - Units 1, 2, and 3 Complete Notes

---

## UNIT 1: INTRODUCTION TO .NET

### 1.1 The .NET Framework

#### What is .NET Framework?

The .NET Framework is a comprehensive software development platform developed by Microsoft for building, deploying, and running applications. It provides a controlled programming environment where software can be developed, installed, and executed primarily on Windows-based operating systems.

#### Key Components of .NET Framework:

**1. Common Language Runtime (CLR)**

- The execution engine of .NET Framework
- Provides services like memory management, security, exception handling, and garbage collection
- Acts as a runtime environment for .NET applications

**2. Framework Class Library (FCL)**

- A collection of reusable classes, interfaces, and value types
- Provides functionality for common programming tasks
- Includes classes for string manipulation, data structures, file I/O, database connectivity, etc.

**3. Common Type System (CTS)**

- Defines how types are declared, used, and managed in the runtime
- Ensures type safety across different .NET languages
- Supports two categories: Value types and Reference types

**4. Common Language Specification (CLS)**

- A subset of CTS that defines rules for language interoperability
- Ensures that code written in one .NET language can be used by another
- Defines minimum standards that all .NET languages must follow

#### Architecture of .NET Framework:

```
┌─────────────────────────────────────────────────┐
│         Application Layer (Your Code)           │
│    (Windows Forms, ASP.NET, Console Apps)       │
└─────────────────────────────────────────────────┘
                        ↓
┌─────────────────────────────────────────────────┐
│      Framework Class Library (FCL)              │
│  (ADO.NET, WPF, WCF, ASP.NET, Windows Forms)    │
└─────────────────────────────────────────────────┘
                        ↓
┌─────────────────────────────────────────────────┐
│     Common Language Runtime (CLR)               │
│  (Memory Mgmt, Security, Exception Handling)    │
└─────────────────────────────────────────────────┘
                        ↓
┌─────────────────────────────────────────────────┐
│           Operating System (Windows)            │
└─────────────────────────────────────────────────┘
```

### 1.2 Common Language Runtime (CLR) - Deep Dive

#### What is CLR?

CLR is the virtual machine component of .NET Framework that manages the execution of .NET programs. It's the heart of the .NET Framework.

#### Key Features of CLR:

**1. Language Interoperability**

- Code written in different .NET languages can work together seamlessly
- Example: A C# class can inherit from a VB.NET class
- All .NET languages compile to Common Intermediate Language (CIL/MSIL)

**2. Memory Management**

- Automatic memory allocation and deallocation
- Garbage Collector (GC) automatically frees memory of unused objects
- Prevents memory leaks and dangling pointers

**3. Type Safety**

- Ensures that code accesses memory in safe ways
- Prevents buffer overruns and other memory-related security issues
- Verifies type safety during JIT compilation

**4. Exception Handling**

- Provides structured exception handling mechanism
- Consistent exception handling across all .NET languages
- Uses try-catch-finally blocks

**5. Security Management**

- Code Access Security (CAS) - controls what code can do
- Role-Based Security - controls what users can do
- Ensures code cannot perform unauthorized operations

**6. Thread Management**

- Manages thread creation and execution
- Provides thread pooling for efficient resource usage
- Handles synchronization and concurrency

#### How CLR Works - Execution Process:

```
Source Code (.cs, .vb, etc.)
         ↓
Language Compiler (csc.exe, vbc.exe)
         ↓
Intermediate Language (IL/MSIL) + Metadata
         ↓
Assembly (.exe or .dll)
         ↓
CLR loads assembly
         ↓
Just-In-Time (JIT) Compiler
         ↓
Native Machine Code
         ↓
Execution on CPU
```

**Step-by-Step Execution:**

1. **Compilation Phase:**

   - Developer writes code in C# or any .NET language
   - Language-specific compiler converts source code to MSIL (Microsoft Intermediate Language)
   - MSIL is platform-independent code
   - Metadata is generated containing information about types, members, references

2. **Loading Phase:**

   - When program is executed, CLR loads the assembly
   - Type information is read from metadata

3. **JIT Compilation:**

   - JIT compiler converts MSIL to native machine code
   - Compilation happens method-by-method (on-demand)
   - Once compiled, native code is cached for reuse

4. **Execution Phase:**
   - Native code is executed by the processor
   - CLR provides runtime services during execution

#### Types of JIT Compilers:

**1. Pre-JIT Compiler:**

- Compiles entire assembly at once during installation
- Slower initial load but faster execution
- Used for applications that need maximum performance

**2. Normal JIT Compiler:**

- Compiles methods when they are called
- Caches compiled code for subsequent calls
- Most commonly used

**3. Econo-JIT Compiler:**

- Compiles methods on demand like Normal JIT
- Discards compiled code when not in use
- Used for devices with memory constraints

#### CLR Services in Detail:

**Garbage Collection (GC):**

- Automatic memory management
- Three generations: Gen 0, Gen 1, Gen 2
- Gen 0: Recently allocated objects
- Gen 1: Objects that survived one GC cycle
- Gen 2: Long-lived objects

**Example of how GC works:**

```csharp
public class GarbageCollectionExample
{
    public void DemonstrateGC()
    {
        // Object created - allocated in Gen 0
        MyClass obj1 = new MyClass();

        // Object used
        obj1.DoSomething();

        // Reference removed - object becomes eligible for GC
        obj1 = null;

        // Force garbage collection (not recommended in production)
        GC.Collect();

        // Object memory is now freed
    }
}
```

**Security Features:**

- **Code Access Security:** Permissions based on code origin
- **Role-Based Security:** Permissions based on user identity
- **Cryptography:** Built-in encryption and hashing support

### 1.3 Integrated Development Environment (IDE)

#### What is an IDE?

An Integrated Development Environment is a software application that provides comprehensive facilities for software development. For .NET development, Visual Studio is the primary IDE.

#### Visual Studio Features:

**1. Code Editor:**

- IntelliSense: Auto-completion of code
- Syntax highlighting: Color-coding of keywords, variables
- Code snippets: Pre-written code templates
- Refactoring tools: Rename, extract method, etc.

**2. Designer Tools:**

- Windows Forms Designer: Visual drag-drop UI design
- WPF Designer: Design XAML-based interfaces
- Database Designer: Visual database schema design

**3. Debugger:**

- Breakpoints: Pause execution at specific lines
- Step-through execution: Execute code line-by-line
- Watch windows: Monitor variable values
- Call stack: See method call hierarchy
- Immediate window: Execute code during debugging

**4. Build Tools:**

- Compiler integration
- Build configurations (Debug, Release)
- Project and solution management
- NuGet Package Manager: Manage external libraries

**5. Testing Tools:**

- Unit testing framework integration
- Code coverage analysis
- Performance profiling

#### Creating a New Project in Visual Studio:

**Step 1: Launch Visual Studio**

- Open Visual Studio
- Select "Create a new project"

**Step 2: Choose Project Template**

- Console Application (.NET Framework) - For console apps
- Windows Forms App (.NET Framework) - For GUI apps
- Class Library - For reusable components
- ASP.NET Web Application - For web apps

**Step 3: Configure Project**

- Project Name: Name of your project
- Location: Where project files will be saved
- Solution Name: Container for multiple projects
- Framework: Select .NET Framework version

**Step 4: Project Structure**

```
Solution
├── Project
│   ├── Properties
│   │   └── AssemblyInfo.cs (assembly metadata)
│   ├── References (external assemblies)
│   ├── App.config (configuration file)
│   └── Program.cs (main code file)
```

#### Solution Explorer:

- Tree view of all files in solution
- Manage project files, references, resources
- Right-click for context menus

#### Properties Window:

- View and edit properties of selected items
- Design-time configuration of controls
- Set properties like Name, Text, Size, Location

#### Toolbox:

- Contains controls for drag-drop design
- Categories: Common Controls, Containers, Menus, Data
- Add controls to forms by dragging

#### Common Keyboard Shortcuts:

```
F5           - Start Debugging
Ctrl+F5      - Start Without Debugging
F9           - Toggle Breakpoint
F10          - Step Over
F11          - Step Into
Ctrl+K, D    - Format Document
Ctrl+.       - Show Quick Actions
Ctrl+Space   - IntelliSense
Ctrl+Shift+B - Build Solution
```

#### Understanding Debug vs Release Configuration:

**Debug Configuration:**

- Contains debugging symbols
- No code optimization
- Larger file size
- Used during development
- Easier to debug

**Release Configuration:**

- Optimized code
- Smaller file size
- Faster execution
- No debugging symbols
- Used for production deployment

---

## UNIT 2: PROGRAMMING IN C#

### 2.1 Introduction to C#

C# (pronounced "C Sharp") is a modern, object-oriented programming language developed by Microsoft as part of the .NET initiative. It combines the power of C++ with the simplicity of Visual Basic.

#### Key Features of C#:

- Simple and easy to learn
- Object-oriented
- Type-safe
- Component-oriented
- Structured programming language
- Rich library support
- Interoperability with other .NET languages

### 2.2 Data Types in C#

Data types specify the type of data that a variable can store. C# is a strongly-typed language, meaning every variable must have a declared type.

#### Categories of Data Types:

**1. Value Types**
Value types directly contain data. When you assign one value type variable to another, the actual data is copied.

**A. Integer Types:**

```csharp
// Integer types with their ranges and sizes
byte    myByte = 255;           // 8-bit:  0 to 255
sbyte   mySByte = -128;         // 8-bit:  -128 to 127
short   myShort = -32768;       // 16-bit: -32,768 to 32,767
ushort  myUShort = 65535;       // 16-bit: 0 to 65,535
int     myInt = -2147483648;    // 32-bit: -2,147,483,648 to 2,147,483,647
uint    myUInt = 4294967295;    // 32-bit: 0 to 4,294,967,295
long    myLong = -9223372036854775808; // 64-bit: Very large range
ulong   myULong = 18446744073709551615; // 64-bit: 0 to very large positive
```

**B. Floating-Point Types:**

```csharp
// Floating point types for decimal numbers
float  myFloat = 3.14F;     // 32-bit, 7 digits precision, suffix F required
double myDouble = 3.14159;  // 64-bit, 15-16 digits precision (default for decimals)
decimal myDecimal = 3.14159M; // 128-bit, 28-29 digits precision, for financial calculations
```

**When to use which:**

- `float`: Graphics, scientific calculations where precision isn't critical
- `double`: General-purpose floating-point calculations
- `decimal`: Financial and monetary calculations requiring high precision

**C. Character and Boolean Types:**

```csharp
char myChar = 'A';        // 16-bit Unicode character
bool myBool = true;       // true or false only
```

**D. Enum Type:**

```csharp
// Enumeration - set of named constants
enum Days { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday }
enum Status { Active = 1, Inactive = 0, Pending = 2 }

Days today = Days.Monday;
Status currentStatus = Status.Active;
int statusValue = (int)Status.Active; // Get underlying value: 1
```

**E. Struct Type:**

```csharp
// Structure - user-defined value type
struct Point
{
    public int X;
    public int Y;

    public Point(int x, int y)
    {
        X = x;
        Y = y;
    }
}

Point p1 = new Point(10, 20);
Point p2 = p1;  // Creates a copy
p2.X = 30;      // p1.X is still 10
```

**2. Reference Types**
Reference types store references (addresses) to their data. When you assign one reference type to another, both refer to the same object.

**A. String Type:**

```csharp
string str1 = "Hello";
string str2 = "World";
string str3 = str1 + " " + str2;  // Concatenation: "Hello World"

// String is immutable - cannot be changed after creation
str1 = str1 + "!";  // Creates new string, doesn't modify original

// String interpolation (C# 6.0+)
string name = "John";
int age = 25;
string message = $"Name: {name}, Age: {age}";

// Verbatim strings (ignore escape sequences)
string path = @"C:\Users\Documents\file.txt";

// String methods
int length = str1.Length;           // Get length
string upper = str1.ToUpper();      // Convert to uppercase
string lower = str1.ToLower();      // Convert to lowercase
bool contains = str1.Contains("ell"); // Check if contains substring
string sub = str1.Substring(0, 4);  // Extract substring: "Hell"
```

**B. Object Type:**

```csharp
// Object is the base type of all types in C#
object obj1 = 100;        // Boxing: int to object
object obj2 = "Hello";    // Boxing: string to object
object obj3 = true;       // Boxing: bool to object

// Unboxing: requires explicit cast
int num = (int)obj1;
string str = (string)obj2;
```

**C. Dynamic Type:**

```csharp
// Type checking is done at runtime, not compile time
dynamic value = 100;
value = "Now I'm a string";
value = true;
// No compile-time type checking
```

**D. Array Type:**

```csharp
// Single-dimensional array
int[] numbers = new int[5];  // Array of 5 integers
numbers[0] = 10;
numbers[1] = 20;

// Array initialization
int[] nums = { 1, 2, 3, 4, 5 };
string[] names = new string[] { "John", "Jane", "Bob" };

// Multi-dimensional array
int[,] matrix = new int[3, 3];  // 3x3 matrix
matrix[0, 0] = 1;
matrix[0, 1] = 2;

// Jagged array (array of arrays)
int[][] jaggedArray = new int[3][];
jaggedArray[0] = new int[2] { 1, 2 };
jaggedArray[1] = new int[4] { 3, 4, 5, 6 };
jaggedArray[2] = new int[3] { 7, 8, 9 };

// Array operations
int arrayLength = nums.Length;        // Get length
Array.Sort(nums);                     // Sort array
Array.Reverse(nums);                  // Reverse array
int index = Array.IndexOf(nums, 3);   // Find index of element
```

**E. Class Type:**

```csharp
class Person
{
    public string Name;
    public int Age;

    public void Display()
    {
        Console.WriteLine($"Name: {Name}, Age: {Age}");
    }
}

Person p1 = new Person();
p1.Name = "John";
p1.Age = 25;

Person p2 = p1;  // Both refer to same object
p2.Name = "Jane";  // p1.Name also becomes "Jane"
```

#### Nullable Types:

```csharp
// Value types can be made nullable using ?
int? nullableInt = null;
bool? nullableBool = null;

// Check if has value
if (nullableInt.HasValue)
{
    int value = nullableInt.Value;
}

// Null-coalescing operator
int result = nullableInt ?? 0;  // Use 0 if null
```

#### Type Conversion:

**Implicit Conversion (Automatic):**

```csharp
int intNum = 100;
long longNum = intNum;     // int to long (smaller to larger)
float floatNum = intNum;   // int to float
```

**Explicit Conversion (Casting):**

```csharp
double doubleNum = 99.99;
int intNum = (int)doubleNum;  // Loses decimal part: 99

// Using Convert class
string strNum = "123";
int num = Convert.ToInt32(strNum);
bool boolVal = Convert.ToBoolean(1);
```

**Type Conversion Methods:**

```csharp
// Parse methods
int num1 = int.Parse("123");
double num2 = double.Parse("123.45");

// TryParse methods (safer - doesn't throw exception)
int result;
bool success = int.TryParse("123", out result);
if (success)
{
    Console.WriteLine($"Parsed: {result}");
}
else
{
    Console.WriteLine("Parse failed");
}
```

### 2.3 Keywords in C#

Keywords are reserved words that have special meaning to the compiler. They cannot be used as identifiers (variable names, class names, etc.) unless prefixed with @.

#### Categories of Keywords:

**1. Access Modifiers:**

```csharp
public      // Accessible from anywhere
private     // Accessible only within the class
protected   // Accessible within class and derived classes
internal    // Accessible within the same assembly
protected internal  // Accessible within assembly or derived classes
```

**2. Type Keywords:**

```csharp
int, long, short, byte, sbyte, uint, ulong, ushort
float, double, decimal
char, string, bool
object, dynamic
void    // No return type
var     // Implicitly typed variable
```

**3. Selection Statements:**

```csharp
if, else, switch, case, default
```

**4. Iteration Statements:**

```csharp
for, foreach, while, do
```

**5. Jump Statements:**

```csharp
break       // Exit loop or switch
continue    // Skip to next iteration
return      // Exit method and optionally return value
goto        // Jump to labeled statement (avoid using)
```

**6. Exception Handling:**

```csharp
try         // Code that may throw exception
catch       // Handle exception
finally     // Code that always executes
throw       // Throw an exception
```

**7. Class and Object Keywords:**

```csharp
class       // Define a class
struct      // Define a structure
interface   // Define an interface
enum        // Define enumeration
new         // Create instance or hide inherited member
this        // Refer to current instance
base        // Refer to base class
static      // Belongs to type rather than instance
sealed      // Cannot be inherited
abstract    // Must be inherited
virtual     // Can be overridden
override    // Override virtual/abstract member
```

**8. Access and Namespace Keywords:**

```csharp
namespace   // Organize code into logical groups
using       // Import namespace or create alias
```

**9. Value and Reference Keywords:**

```csharp
null        // Null reference
const       // Compile-time constant
readonly    // Runtime constant
```

**10. Other Important Keywords:**

```csharp
is          // Check type
as          // Type cast (returns null if fails)
typeof      // Get Type object
sizeof      // Get size of type
checked     // Enable overflow checking
unchecked   // Disable overflow checking
lock        // Thread synchronization
async       // Asynchronous method
await       // Await asynchronous operation
```

#### Examples of Keywords Usage:

```csharp
using System;  // Using directive

namespace MyApplication  // Namespace keyword
{
    public class Program  // Class and access modifier
    {
        private const int MAX = 100;  // Private, const keywords

        public static void Main(string[] args)  // Public, static, void
        {
            int number = 10;  // Type keyword

            // if-else keywords
            if (number > 5)
            {
                Console.WriteLine("Greater");
            }
            else
            {
                Console.WriteLine("Smaller");
            }

            // for keyword
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine(i);
            }

            // try-catch-finally
            try
            {
                int result = 10 / 0;
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }
            finally
            {
                Console.WriteLine("Cleanup");
            }
        }
    }
}
```

### 2.4 Operators in C#

Operators are symbols that perform operations on operands (variables and values).

#### 1. Arithmetic Operators:

```csharp
int a = 10, b = 3;

int sum = a + b;         // Addition: 13
int diff = a - b;        // Subtraction: 7
int product = a * b;     // Multiplication: 30
int quotient = a / b;    // Division: 3 (integer division)
int remainder = a % b;   // Modulus: 1

// Division with floating point
double result = 10.0 / 3.0;  // 3.333...

// Unary operators
int x = 5;
int y = +x;  // Unary plus: 5
int z = -x;  // Unary minus: -5

// Increment and Decrement
int count = 10;
count++;      // Post-increment: count = 11
++count;      // Pre-increment: count = 12
count--;      // Post-decrement: count = 11
--count;      // Pre-decrement: count = 10

// Difference between pre and post
int i = 5;
int j = i++;  // j = 5, i = 6 (assign then increment)
int k = ++i;  // k = 7, i = 7 (increment then assign)
```

#### 2. Assignment Operators:

```csharp
int x = 10;      // Simple assignment

// Compound assignment operators
x += 5;   // x = x + 5;  (x = 15)
x -= 3;   // x = x - 3;  (x = 12)
x *= 2;   // x = x * 2;  (x = 24)
x /= 4;   // x = x / 4;  (x = 6)
x %= 4;   // x = x % 4;  (x = 2)
```

#### 3. Comparison (Relational) Operators:

```csharp
int a = 10, b = 20;

bool result1 = (a == b);   // Equal to: false
bool result2 = (a != b);   // Not equal to: true
bool result3 = (a > b);    // Greater than: false
bool result4 = (a < b);    // Less than: true
bool result5 = (a >= b);   // Greater than or equal to: false
bool result6 = (a <= b);   // Less than or equal to: true
```

#### 4. Logical Operators:

```csharp
bool x = true, y = false;

bool result1 = x && y;  // Logical AND: false (both must be true)
bool result2 = x || y;  // Logical OR: true (at least one must be true)
bool result3 = !x;      // Logical NOT: false (inverts value)

// Short-circuit evaluation
int a = 10, b = 0;
bool result4 = (b != 0) && (a / b > 0);  // AND stops at first false
bool result5 = (b == 0) || (a / b > 0);  // OR stops at first true

// Practical example
int age = 25;
bool hasLicense = true;
bool canDrive = (age >= 18) && hasLicense;  // true
```

#### 5. Bitwise Operators:

```csharp
int a = 5;   // Binary: 0101
int b = 3;   // Binary: 0011

int and = a & b;   // Bitwise AND: 0001 (1)
int or = a | b;    // Bitwise OR: 0111 (7)
int xor = a ^ b;   // Bitwise XOR: 0110 (6)
int not = ~a;      // Bitwise NOT: ...11111010 (-6 in two's complement)

int leftShift = a << 1;   // Left shift: 1010 (10) - multiply by 2
int rightShift = a >> 1;  // Right shift: 0010 (2) - divide by 2
```

#### 6. Ternary (Conditional) Operator:

```csharp
// Syntax: condition ? true_value : false_value
int age = 20;
string result = (age >= 18) ? "Adult" : "Minor";

// Nested ternary
int marks = 75;
string grade = (marks >= 90) ? "A" :
               (marks >= 80) ? "B" :
               (marks >= 70) ? "C" : "F";

// Practical use
int a = 10, b = 20;
int max = (a > b) ? a : b;  // Get maximum
```

#### 7. Null-Coalescing Operators:

```csharp
// Null-coalescing operator (??)
int? nullable = null;
int value = nullable ?? 0;  // Use 0 if null

// Null-coalescing assignment (??=) - C# 8.0+
int? x = null;
x ??= 100;  // Assign 100 if x is null

// Practical example
string name = null;
string displayName = name ?? "Guest";  // "Guest"
```

#### 8. Type Operators:

```csharp
// is operator - type checking
object obj = "Hello";
bool isString = obj is string;  // true
bool isInt = obj is int;        // false

// Pattern matching with is (C# 7.0+)
if (obj is string str)
{
    Console.WriteLine($"Length: {str.Length}");
}

// as operator - safe casting
object obj2 = "World";
string str2 = obj2 as string;  // Successful cast
int? num = obj2 as int?;       // null (cast failed)

// typeof operator
Type t1 = typeof(int);
Type t2 = typeof(string);
Type t3 = typeof(List<int>);
```

#### 9. Member Access and Null-Conditional Operators:

```csharp
// Member access operator (.)
Person person = new Person();
person.Name = "John";
person.Display();

// Null-conditional operator (?.)
Person nullPerson = null;
string name = nullPerson?.Name;  // null instead of exception

// Null-conditional with arrays
int[] numbers = null;
int? first = numbers?[0];  // null

// Chain null-conditionals
string upperName = person?.Name?.ToUpper();
```

#### Operator Precedence (Highest to Lowest):

```
1. Primary: x.y, x?.y, x?[y], x++, x--, new, typeof, sizeof
2. Unary: +x, -x, !x, ~x, ++x, --x
3. Multiplicative: *, /, %
4. Additive: +, -
5. Shift: <<, >>
6. Relational: <, >, <=, >=, is, as
7. Equality: ==, !=
8. Logical AND: &
9. Logical XOR: ^
10. Logical OR: |
11. Conditional AND: &&
12. Conditional OR: ||
13. Null-coalescing: ??
14. Conditional: ?:
15. Assignment: =, +=, -=, etc.
```

**Example showing precedence:**

```csharp
int result = 10 + 5 * 2;      // 20, not 30 (* before +)
int result2 = (10 + 5) * 2;   // 30 (parentheses first)

bool condition = 5 > 3 && 10 < 20 || false;  // true
// Evaluated as: ((5 > 3) && (10 < 20)) || false
```

### 2.5 Conditionals in C#

Conditional statements allow you to execute different code based on conditions.

#### 1. if Statement:

```csharp
// Basic if
int age = 20;
if (age >= 18)
{
    Console.WriteLine("You are an adult");
}

// if-else
int number = 10;
if (number > 0)
{
    Console.WriteLine("Positive");
}
else
{
    Console.WriteLine("Non-positive");
}

// if-else if-else
int marks = 75;
if (marks >= 90)
{
    Console.WriteLine("Grade: A");
}
else if (marks >= 80)
{
    Console.WriteLine("Grade: B");
}
else if (marks >= 70)
{
    Console.WriteLine("Grade: C");
}
else if (marks >= 60)
{
    Console.WriteLine("Grade: D");
}
else
{
    Console.WriteLine("Grade: F");
}

// Nested if
int age2 = 25;
bool hasLicense = true;
if (age2 >= 18)
{
    if (hasLicense)
    {
        Console.WriteLine("Can drive");
    }
    else
    {
        Console.WriteLine("Need license");
    }
}
else
{
    Console.WriteLine("Too young");
}

// Multiple conditions
int x = 10, y = 20;
if (x > 0 && y > 0)
{
    Console.WriteLine("Both positive");
}

// Short form (without braces) - not recommended
if (x > 0) Console.WriteLine("Positive");
```

#### 2. switch Statement:

```csharp
// Basic switch
int day = 3;
switch (day)
{
    case 1:
        Console.WriteLine("Monday");
        break;
    case 2:
        Console.WriteLine("Tuesday");
        break;
    case 3:
        Console.WriteLine("Wednesday");
        break;
    case 4:
        Console.WriteLine("Thursday");
        break;
    case 5:
        Console.WriteLine("Friday");
        break;
    case 6:
        Console.WriteLine("Saturday");
        break;
    case 7:
        Console.WriteLine("Sunday");
        break;
    default:
        Console.WriteLine("Invalid day");
        break;
}

// Switch with multiple cases
char grade = 'B';
switch (grade)
{
    case 'A':
    case 'a':
        Console.WriteLine("Excellent");
        break;
    case 'B':
    case 'b':
        Console.WriteLine("Good");
        break;
    case 'C':
    case 'c':
        Console.WriteLine("Average");
        break;
    default:
        Console.WriteLine("Invalid grade");
        break;
}

// Switch with string
string color = "Red";
switch (color)
{
    case "Red":
        Console.WriteLine("Stop");
        break;
    case "Yellow":
        Console.WriteLine("Ready");
        break;
    case "Green":
        Console.WriteLine("Go");
        break;
    default:
        Console.WriteLine("Invalid color");
        break;
}

// Switch expression (C# 8.0+)
string dayName = day switch
{
    1 => "Monday",
    2 => "Tuesday",
    3 => "Wednesday",
    4 => "Thursday",
    5 => "Friday",
    6 => "Saturday",
    7 => "Sunday",
    _ => "Invalid"
};

// Pattern matching in switch (C# 7.0+)
object obj = 42;
switch (obj)
{
    case int i:
        Console.WriteLine($"Integer: {i}");
        break;
    case string s:
        Console.WriteLine($"String: {s}");
        break;
    case null:
        Console.WriteLine("Null value");
        break;
    default:
        Console.WriteLine("Unknown type");
        break;
}

// Switch with when clause
int number = 15;
switch (number)
{
    case int n when n < 0:
        Console.WriteLine("Negative");
        break;
    case int n when n == 0:
        Console.WriteLine("Zero");
        break;
    case int n when n > 0 && n <= 10:
        Console.WriteLine("Small positive");
        break;
    case int n when n > 10:
        Console.WriteLine("Large positive");
        break;
}
```

### 2.6 Loops in C#

Loops allow you to execute a block of code repeatedly.

#### 1. for Loop:

```csharp
// Basic for loop
for (int i = 0; i < 5; i++)
{
    Console.WriteLine($"Iteration: {i}");
}
// Output: 0, 1, 2, 3, 4

// Loop from 1 to 10
for (int i = 1; i <= 10; i++)
{
    Console.WriteLine(i);
}

// Decrementing loop
for (int i = 10; i > 0; i--)
{
    Console.WriteLine(i);
}

// Step by 2
for (int i = 0; i < 10; i += 2)
{
    Console.WriteLine(i);  // 0, 2, 4, 6, 8
}

// Multiple variables
for (int i = 0, j = 10; i < 5; i++, j--)
{
    Console.WriteLine($"i: {i}, j: {j}");
}

// Nested for loop
for (int i = 1; i <= 3; i++)
{
    for (int j = 1; j <= 3; j++)
    {
        Console.WriteLine($"i: {i}, j: {j}");
    }
}

// Print multiplication table
for (int i = 1; i <= 10; i++)
{
    for (int j = 1; j <= 10; j++)
    {
        Console.Write($"{i * j}\t");
    }
    Console.WriteLine();
}

// Infinite loop (avoid unless intentional)
// for (;;) { }

// Array iteration with for
int[] numbers = { 10, 20, 30, 40, 50 };
for (int i = 0; i < numbers.Length; i++)
{
    Console.WriteLine($"Index {i}: {numbers[i]}");
}
```

#### 2. while Loop:

```csharp
// Basic while loop
int count = 0;
while (count < 5)
{
    Console.WriteLine($"Count: {count}");
    count++;
}

// User input validation
int input;
while (true)
{
    Console.Write("Enter a positive number: ");
    input = int.Parse(Console.ReadLine());

    if (input > 0)
        break;  // Exit loop

    Console.WriteLine("Invalid! Try again.");
}

// Sum of digits
int num = 12345;
int sum = 0;
while (num > 0)
{
    sum += num % 10;  // Add last digit
    num /= 10;        // Remove last digit
}
Console.WriteLine($"Sum of digits: {sum}");

// Reading until sentinel value
int value;
int total = 0;
Console.WriteLine("Enter numbers (0 to stop):");
while ((value = int.Parse(Console.ReadLine())) != 0)
{
    total += value;
}
Console.WriteLine($"Total: {total}");

// Factorial calculation
int n = 5;
int factorial = 1;
int i = 1;
while (i <= n)
{
    factorial *= i;
    i++;
}
Console.WriteLine($"Factorial of {n}: {factorial}");
```

#### 3. do-while Loop:

```csharp
// Basic do-while (executes at least once)
int counter = 0;
do
{
    Console.WriteLine($"Counter: {counter}");
    counter++;
} while (counter < 5);

// Menu-driven program
int choice;
do
{
    Console.WriteLine("\n--- Menu ---");
    Console.WriteLine("1. Add");
    Console.WriteLine("2. Subtract");
    Console.WriteLine("3. Multiply");
    Console.WriteLine("4. Exit");
    Console.Write("Enter choice: ");
    choice = int.Parse(Console.ReadLine());

    switch (choice)
    {
        case 1:
            Console.WriteLine("Addition selected");
            break;
        case 2:
            Console.WriteLine("Subtraction selected");
            break;
        case 3:
            Console.WriteLine("Multiplication selected");
            break;
        case 4:
            Console.WriteLine("Exiting...");
            break;
        default:
            Console.WriteLine("Invalid choice");
            break;
    }
} while (choice != 4);

// Input validation with do-while
int age;
do
{
    Console.Write("Enter age (1-120): ");
    age = int.Parse(Console.ReadLine());

    if (age < 1 || age > 120)
        Console.WriteLine("Invalid age!");

} while (age < 1 || age > 120);

// Difference between while and do-while
int x = 10;

// while - may not execute at all
while (x < 5)
{
    Console.WriteLine("While: " + x);  // Never executes
}

// do-while - executes at least once
do
{
    Console.WriteLine("Do-While: " + x);  // Executes once
} while (x < 5);
```

#### 4. foreach Loop:

```csharp
// Basic foreach (for collections)
int[] numbers = { 1, 2, 3, 4, 5 };
foreach (int num in numbers)
{
    Console.WriteLine(num);
}

// String array
string[] names = { "Alice", "Bob", "Charlie" };
foreach (string name in names)
{
    Console.WriteLine($"Hello, {name}");
}

// Iterating through string characters
string text = "Hello";
foreach (char c in text)
{
    Console.WriteLine(c);
}

// List iteration
List<int> numberList = new List<int> { 10, 20, 30, 40, 50 };
foreach (int num in numberList)
{
    Console.WriteLine(num);
}

// Dictionary iteration
Dictionary<string, int> ages = new Dictionary<string, int>
{
    { "John", 25 },
    { "Jane", 30 },
    { "Bob", 35 }
};

foreach (KeyValuePair<string, int> pair in ages)
{
    Console.WriteLine($"{pair.Key}: {pair.Value}");
}

// Or using var
foreach (var pair in ages)
{
    Console.WriteLine($"{pair.Key}: {pair.Value}");
}

// Multi-dimensional array
int[,] matrix = { { 1, 2, 3 }, { 4, 5, 6 } };
foreach (int element in matrix)
{
    Console.WriteLine(element);  // 1, 2, 3, 4, 5, 6
}

// Note: Cannot modify collection in foreach
// This will cause error:
// foreach (int num in numbers)
// {
//     num = num * 2;  // ERROR: Cannot assign to num
// }
```

#### 5. Loop Control Statements:

**break Statement:**

```csharp
// Exit loop immediately
for (int i = 0; i < 10; i++)
{
    if (i == 5)
        break;  // Exit when i is 5
    Console.WriteLine(i);
}
// Output: 0, 1, 2, 3, 4

// Break in nested loops (only exits innermost)
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        if (j == 2)
            break;  // Exits inner loop only
        Console.WriteLine($"i: {i}, j: {j}");
    }
}

// Finding first even number
int[] nums = { 1, 3, 5, 8, 9, 10 };
int firstEven = -1;
foreach (int num in nums)
{
    if (num % 2 == 0)
    {
        firstEven = num;
        break;  // Found, exit loop
    }
}
Console.WriteLine($"First even: {firstEven}");
```

**continue Statement:**

```csharp
// Skip current iteration, continue with next
for (int i = 0; i < 10; i++)
{
    if (i % 2 == 0)
        continue;  // Skip even numbers
    Console.WriteLine(i);
}
// Output: 1, 3, 5, 7, 9

// Print only positive numbers
int[] values = { -5, 3, -2, 8, -1, 6 };
foreach (int val in values)
{
    if (val < 0)
        continue;  // Skip negative
    Console.WriteLine(val);
}
// Output: 3, 8, 6

// Skip multiples of 3
for (int i = 1; i <= 20; i++)
{
    if (i % 3 == 0)
        continue;
    Console.WriteLine(i);
}
```

**goto Statement (avoid using):**

```csharp
// Jump to labeled statement
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        if (i == 1 && j == 1)
            goto exitLoops;  // Jump out of both loops

        Console.WriteLine($"i: {i}, j: {j}");
    }
}

exitLoops:
Console.WriteLine("Exited using goto");
```

#### Common Loop Patterns:

**Pattern 1: Sum of array elements**

```csharp
int[] numbers = { 10, 20, 30, 40, 50 };
int sum = 0;
foreach (int num in numbers)
{
    sum += num;
}
Console.WriteLine($"Sum: {sum}");  // 150
```

**Pattern 2: Find maximum**

```csharp
int[] numbers = { 45, 23, 67, 12, 89, 34 };
int max = numbers[0];
foreach (int num in numbers)
{
    if (num > max)
        max = num;
}
Console.WriteLine($"Maximum: {max}");  // 89
```

**Pattern 3: Count occurrences**

```csharp
int[] numbers = { 1, 2, 3, 2, 4, 2, 5 };
int target = 2;
int count = 0;
foreach (int num in numbers)
{
    if (num == target)
        count++;
}
Console.WriteLine($"Count of {target}: {count}");  // 3
```

**Pattern 4: Reverse array**

```csharp
int[] numbers = { 1, 2, 3, 4, 5 };
for (int i = 0, j = numbers.Length - 1; i < j; i++, j--)
{
    // Swap
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
}
// Result: { 5, 4, 3, 2, 1 }
```

**Pattern 5: Prime number check**

```csharp
int number = 29;
bool isPrime = true;

if (number <= 1)
{
    isPrime = false;
}
else
{
    for (int i = 2; i <= Math.Sqrt(number); i++)
    {
        if (number % i == 0)
        {
            isPrime = false;
            break;
        }
    }
}

Console.WriteLine($"{number} is {(isPrime ? "prime" : "not prime")}");
```

**Pattern 6: Fibonacci series**

```csharp
int n = 10;
int first = 0, second = 1;

Console.Write($"{first} {second} ");
for (int i = 2; i < n; i++)
{
    int next = first + second;
    Console.Write($"{next} ");
    first = second;
    second = next;
}
// Output: 0 1 1 2 3 5 8 13 21 34
```

---

## UNIT 3: .NET ASSEMBLIES

### 3.1 Introduction to .NET Assemblies

#### What is an Assembly?

An assembly is the fundamental unit of deployment, version control, reuse, and security in .NET applications. It's a compiled code library used for deployment, versioning, and security.

**Key Characteristics:**

- Assemblies are self-describing (contain metadata)
- Building blocks of .NET Framework applications
- Can be EXE (executable) or DLL (dynamic link library)
- Contains IL (Intermediate Language) code and metadata
- Unit of versioning and deployment

#### Assembly Contents:

```
┌─────────────────────────────────────┐
│         ASSEMBLY STRUCTURE          │
├─────────────────────────────────────┤
│  1. Assembly Manifest               │
│     - Assembly metadata             │
│     - Version information           │
│     - Culture information           │
│     - Referenced assemblies         │
├─────────────────────────────────────┤
│  2. Type Metadata                   │
│     - Type definitions              │
│     - Member information            │
├─────────────────────────────────────┤
│  3. IL Code (MSIL)                  │
│     - Compiled intermediate code    │
├─────────────────────────────────────┤
│  4. Resources (Optional)            │
│     - Images, strings, etc.         │
└─────────────────────────────────────┘
```

#### Types of Assemblies:

**1. Based on Deployment:**

**Private Assembly:**

- Default type of assembly
- Stored in application's directory
- Used by single application
- No version checking
- Easy to deploy (just copy)

```
Application Folder/
├── MyApp.exe
├── MyLibrary.dll (Private Assembly)
└── Helper.dll (Private Assembly)
```

**Shared Assembly:**

- Stored in Global Assembly Cache (GAC)
- Shared by multiple applications
- Must have strong name
- Version checking is enforced
- Located in C:\Windows\Assembly

**2. Based on Content:**

**Process Assembly (EXE):**

- Executable assembly
- Has entry point (Main method)
- Can be run directly
- Extension: .exe

**Library Assembly (DLL):**

- Cannot be executed directly
- Contains reusable code
- Must be referenced by other assemblies
- Extension: .dll

#### Assembly Manifest:

The manifest is metadata that describes the assembly. It contains:

```csharp
// Information in Assembly Manifest:

1. Assembly Identity
   - Name
   - Version (Major.Minor.Build.Revision)
   - Culture (language/region)
   - Public Key Token (for shared assemblies)

2. File Table
   - List of files in assembly

3. Referenced Assemblies
   - Dependencies

4. Security Permissions
   - Required permissions

5. Exported Types
   - Public types available to other assemblies
```

**Example - Viewing Assembly Information:**

```csharp
using System;
using System.Reflection;

class Program
{
    static void Main()
    {
        // Get current assembly
        Assembly assembly = Assembly.GetExecutingAssembly();

        // Display assembly name
        Console.WriteLine($"Name: {assembly.GetName().Name}");

        // Display version
        Console.WriteLine($"Version: {assembly.GetName().Version}");

        // Display culture
        Console.WriteLine($"Culture: {assembly.GetName().CultureInfo}");

        // Display location
        Console.WriteLine($"Location: {assembly.Location}");

        // List all types in assembly
        Console.WriteLine("\nTypes in assembly:");
        Type[] types = assembly.GetTypes();
        foreach (Type type in types)
        {
            Console.WriteLine($"  - {type.Name}");
        }
    }
}
```

### 3.2 Creating Assemblies

#### Creating a Private Assembly (Class Library):

**Step 1: Create Class Library Project**

```
File → New → Project → Class Library (.NET Framework)
Name: MathLibrary
```

**Step 2: Write Code (MathLibrary.cs)**

```csharp
using System;

namespace MathLibrary
{
    public class Calculator
    {
        public int Add(int a, int b)
        {
            return a + b;
        }

        public int Subtract(int a, int b)
        {
            return a - b;
        }

        public int Multiply(int a, int b)
        {
            return a * b;
        }

        public double Divide(int a, int b)
        {
            if (b == 0)
                throw new DivideByZeroException();
            return (double)a / b;
        }
    }

    public class Geometry
    {
        public double CircleArea(double radius)
        {
            return Math.PI * radius * radius;
        }

        public double RectangleArea(double length, double width)
        {
            return length * width;
        }
    }
}
```

**Step 3: Build Project**

- Build → Build Solution (Ctrl+Shift+B)
- Creates MathLibrary.dll in bin\Debug or bin\Release folder

**Step 4: Use in Another Application**

```csharp
// In a Console Application
// First, add reference to MathLibrary.dll:
// Right-click References → Add Reference → Browse → Select MathLibrary.dll

using System;
using MathLibrary;

class Program
{
    static void Main()
    {
        Calculator calc = new Calculator();
        Console.WriteLine($"Add: {calc.Add(10, 5)}");
        Console.WriteLine($"Subtract: {calc.Subtract(10, 5)}");
        Console.WriteLine($"Multiply: {calc.Multiply(10, 5)}");
        Console.WriteLine($"Divide: {calc.Divide(10, 5)}");

        Geometry geo = new Geometry();
        Console.WriteLine($"Circle Area: {geo.CircleArea(5)}");
        Console.WriteLine($"Rectangle Area: {geo.RectangleArea(10, 5)}");
    }
}
```

### 3.3 Shared Assemblies

#### What is a Shared Assembly?

A shared assembly is a common assembly that can be shared by multiple applications. It must be installed in the Global Assembly Cache (GAC).

#### Requirements for Shared Assembly:

**1. Strong Name:**
A strong name consists of:

- Simple text name
- Version number
- Culture information
- Digital signature (public key)

**Why Strong Name?**

- Uniquely identifies assembly
- Ensures integrity (tampering detection)
- Enables versioning
- Required for GAC installation

#### Creating a Strong-Named Assembly:

**Step 1: Generate Key Pair**
Open Developer Command Prompt:

```
sn -k MyKeyPair.snk
```

This creates MyKeyPair.snk file containing public/private key pair.

**Step 2: Sign Assembly**
In Visual Studio:

1. Right-click project → Properties
2. Go to Signing tab
3. Check "Sign the assembly"
4. Choose MyKeyPair.snk file

Or manually in AssemblyInfo.cs:

```csharp
[assembly: AssemblyKeyFile("MyKeyPair.snk")]
```

**Step 3: Set Assembly Information**
In AssemblyInfo.cs:

```csharp
using System.Reflection;
using System.Runtime.InteropServices;

// Assembly identity
[assembly: AssemblyTitle("SharedMathLibrary")]
[assembly: AssemblyDescription("Shared Mathematical Operations Library")]
[assembly: AssemblyCompany("MyCompany")]
[assembly: AssemblyProduct("SharedMathLibrary")]
[assembly: AssemblyCopyright("Copyright © 2025")]

// Version information (Major.Minor.Build.Revision)
[assembly: AssemblyVersion("1.0.0.0")]
[assembly: AssemblyFileVersion("1.0.0.0")]

// Culture (empty for culture-neutral)
[assembly: AssemblyCulture("")]

// COM visibility
[assembly: ComVisible(false)]

// GUID for COM
[assembly: Guid("12345678-1234-1234-1234-123456789abc")]
```

**Step 4: Build Assembly**
Build project to create strong-named DLL.

**Step 5: Install in GAC**
Open Developer Command Prompt as Administrator:

```
gacutil -i SharedMathLibrary.dll
```

To uninstall:

```
gacutil -u SharedMathLibrary
```

To view assemblies in GAC:

```
gacutil -l
```

#### Viewing Strong Name Information:

```
sn -T SharedMathLibrary.dll
```

Shows public key token.

```
sn -v SharedMathLibrary.dll
```

Verifies strong name signature.

### 3.4 Side-By-Side Execution

#### What is Side-By-Side Execution?

Side-by-side execution allows multiple versions of the same assembly to exist and run simultaneously on the same computer or in the same process.

#### Why Side-By-Side Execution?

**Problem Without Side-By-Side:**

```
Application A needs MathLib Version 1.0
Application B needs MathLib Version 2.0
Traditional system: Only one version can be installed
Result: DLL Hell - one application breaks
```

**Solution With Side-By-Side:**

```
GAC contains:
- MathLib Version 1.0
- MathLib Version 2.0
Application A uses Version 1.0
Application B uses Version 2.0
Both run simultaneously without conflict
```

#### Implementing Side-By-Side Execution:

**Version 1.0 of SharedLibrary:**

```csharp
// AssemblyInfo.cs for Version 1.0
[assembly: AssemblyVersion("1.0.0.0")]

// Calculator.cs
namespace SharedLibrary
{
    public class Calculator
    {
        public int Add(int a, int b)
        {
            return a + b;
        }

        public string GetVersion()
        {
            return "Version 1.0";
        }
    }
}
```

**Version 2.0 of SharedLibrary (with new features):**

```csharp
// AssemblyInfo.cs for Version 2.0
[assembly: AssemblyVersion("2.0.0.0")]

// Calculator.cs
namespace SharedLibrary
{
    public class Calculator
    {
        public int Add(int a, int b)
        {
            return a + b;
        }

        // New method in v2.0
        public int AddThree(int a, int b, int c)
        {
            return a + b + c;
        }

        public string GetVersion()
        {
            return "Version 2.0";
        }
    }
}
```

**Application Using Version 1.0:**

```csharp
// App.config specifies version
<?xml version="1.0" encoding="utf-8" ?>
<configuration>
  <runtime>
    <assemblyBinding xmlns="urn:schemas-microsoft-com:asm.v1">
      <dependentAssembly>
        <assemblyIdentity name="SharedLibrary"
                          publicKeyToken="abc123def456"
                          culture="neutral" />
        <bindingRedirect oldVersion="1.0.0.0"
                         newVersion="1.0.0.0" />
      </dependentAssembly>
    </assemblyBinding>
  </runtime>
</configuration>

// Program.cs
using System;
using SharedLibrary;

class Program
{
    static void Main()
    {
        Calculator calc = new Calculator();
        Console.WriteLine(calc.GetVersion());  // "Version 1.0"
        Console.WriteLine(calc.Add(5, 3));
    }
}
```

**Application Using Version 2.0:**

```csharp
// App.config
<?xml version="1.0" encoding="utf-8" ?>
<configuration>
  <runtime>
    <assemblyBinding xmlns="urn:schemas-microsoft-com:asm.v1">
      <dependentAssembly>
        <assemblyIdentity name="SharedLibrary"
                          publicKeyToken="abc123def456"
                          culture="neutral" />
        <bindingRedirect oldVersion="2.0.0.0"
                         newVersion="2.0.0.0" />
      </dependentAssembly>
    </assemblyBinding>
  </runtime>
</configuration>

// Program.cs
using System;
using SharedLibrary;

class Program
{
    static void Main()
    {
        Calculator calc = new Calculator();
        Console.WriteLine(calc.GetVersion());  // "Version 2.0"
        Console.WriteLine(calc.Add(5, 3));
        Console.WriteLine(calc.AddThree(5, 3, 2));  // New method
    }
}
```

#### Version Binding Policies:

**1. Application Configuration File (App.config):**
Specifies which version of assembly to use for specific application.

**2. Publisher Policy File:**
Assembly publisher can redirect all applications to new version.

**3. Machine Configuration File:**
Administrator can set version policy for entire machine.

**Example - Binding Redirect:**

```xml
<configuration>
  <runtime>
    <assemblyBinding xmlns="urn:schemas-microsoft-com:asm.v1">
      <dependentAssembly>
        <assemblyIdentity name="MyLibrary"
                          publicKeyToken="32ab4ba45e0a69a1"
                          culture="neutral" />
        <!-- Redirect versions 1.0-1.5 to version 2.0 -->
        <bindingRedirect oldVersion="1.0.0.0-1.5.0.0"
                         newVersion="2.0.0.0" />
      </dependentAssembly>
    </assemblyBinding>
  </runtime>
</configuration>
```

### 3.5 Benefits of Assemblies

#### 1. Self-Describing

**Benefit:** No need for registry entries or external metadata.

**Explanation:**

- Assembly contains all metadata in manifest
- Type information included
- Version information embedded
- No dependency on registry
- Eliminates "registry corruption" issues

**Example:**

```csharp
// All this information is in the assembly itself
Assembly assembly = Assembly.LoadFrom("MyLibrary.dll");
AssemblyName name = assembly.GetName();
Console.WriteLine($"Name: {name.Name}");
Console.WriteLine($"Version: {name.Version}");
Console.WriteLine($"Culture: {name.CultureInfo}");
```

#### 2. Version Control

**Benefit:** Multiple versions can coexist without conflicts.

**Explanation:**

- Each assembly has unique version number
- Strong naming ensures version integrity
- Side-by-side execution supported
- Application specifies required version
- Solves "DLL Hell" problem

**Comparison with Old DLL System:**

```
Traditional DLL:
- Only one version installed
- Newer version overwrites old
- Old applications may break
- "DLL Hell"

.NET Assembly:
- Multiple versions in GAC
- Each app uses correct version
- No conflicts
- Problem solved!
```

#### 3. Deployment Simplified

**Benefit:** XCOPY deployment - just copy files.

**Explanation:**

- Private assemblies: copy to application folder
- No registration required
- No complex installation
- Easy uninstallation (delete folder)
- Portable applications

**Example:**

```
Traditional COM DLL:
1. Copy DLL
2. Run regsvr32 mydll.dll
3. Update registry
4. Hope nothing breaks

.NET Private Assembly:
1. Copy DLL to app folder
2. Done!
```

#### 4. Security

**Benefit:** Strong names provide security and integrity.

**Explanation:**

- Digital signature prevents tampering
- Public key verifies origin
- Code access security
- Permission-based execution
- Evidence-based security

**Example:**

```csharp
// Assembly with strong name
[assembly: AssemblyKeyFile("mykey.snk")]

// CLR verifies:
// 1. Assembly hasn't been modified
// 2. Comes from expected publisher
// 3. Has required permissions
```

#### 5. Eliminates DLL Hell

**Benefit:** No conflicts between different application dependencies.

**Explanation:**

- Each app can use different versions
- Private assemblies isolated
- Shared assemblies versioned
- No global namespace pollution
- Clean uninstallation

**DLL Hell Example:**

```
Before .NET:
App A installs Library v1.0
App B installs Library v2.0 (overwrites v1.0)
App A breaks!

With .NET:
App A uses Library v1.0 (from GAC)
App B uses Library v2.0 (from GAC)
Both work perfectly!
```

#### 6. Memory Efficiency

**Benefit:** Code sharing between applications.

**Explanation:**

- Shared assemblies loaded once in memory
- Multiple applications use same copy
- Reduces memory footprint
- Better performance

**Example:**

```
10 applications use System.dll:
Without sharing: 10 copies in memory (10 MB each = 100 MB)
With GAC sharing: 1 copy in memory (10 MB total)
Savings: 90 MB
```

#### 7. Language Interoperability

**Benefit:** Use assemblies from any .NET language.

**Explanation:**

- C# assembly can be used by VB.NET
- VB.NET assembly can be used by C#
- All compile to same IL
- Seamless integration

**Example:**

```csharp
// C# Library
public class MathLib
{
    public int Add(int a, int b) => a + b;
}

// VB.NET Application can use it:
' Dim calc As New MathLib()
' Dim result = calc.Add(5, 3)
```

#### 8. Easy Maintenance and Updates

**Benefit:** Update assemblies without affecting other components.

**Explanation:**

- Replace DLL without reinstalling application
- Publisher policy files for automatic updates
- Binding redirects for version management
- Minimal application downtime

**Example:**

```xml
<!-- Publisher Policy to auto-update all apps -->
<configuration>
  <runtime>
    <assemblyBinding>
      <dependentAssembly>
        <assemblyIdentity name="MyLib" publicKeyToken="abc123" />
        <!-- All apps automatically use v2.0 -->
        <bindingRedirect oldVersion="1.0.0.0-1.9.9.9"
                         newVersion="2.0.0.0" />
      </dependentAssembly>
    </assemblyBinding>
  </runtime>
</configuration>
```

#### 9. Type Safety

**Benefit:** Strong typing enforced at assembly level.

**Explanation:**

- Type metadata in manifest
- Compile-time type checking
- Runtime type verification
- Prevents type mismatch errors
- IntelliSense support

**Example:**

```csharp
// Calculator.dll (Version 1.0)
public int Add(int a, int b) { return a + b; }

// Using application
Calculator calc = new Calculator();
calc.Add(5, 3);        // Correct
// calc.Add("5", "3"); // Compile error - type mismatch
```

#### 10. Culture-Specific Assemblies

**Benefit:** Support for localization and internationalization.

**Explanation:**

- Satellite assemblies for resources
- Culture-neutral main assembly
- Culture-specific resource assemblies
- Automatic resource loading based on culture

**Example Structure:**

```
MyApp/
├── MyApp.exe (culture-neutral)
├── en-US/
│   └── MyApp.resources.dll (English resources)
├── fr-FR/
│   └── MyApp.resources.dll (French resources)
└── hi-IN/
    └── MyApp.resources.dll (Hindi resources)
```

**Code:**

```csharp
// Automatically loads correct resource based on system culture
ResourceManager rm = new ResourceManager("MyApp.Resources",
                                        Assembly.GetExecutingAssembly());
string greeting = rm.GetString("Greeting");
// Returns "Hello" for en-US
// Returns "Bonjour" for fr-FR
// Returns "नमस्ते" for hi-IN
```

### 3.6 Assembly Loading

#### Types of Assembly Loading:

**1. Static Loading (Compile-time Reference):**

```csharp
// Add reference to assembly in Visual Studio
using MyLibrary;

class Program
{
    static void Main()
    {
        // Assembly loaded automatically when needed
        Calculator calc = new Calculator();
        calc.Add(5, 3);
    }
}
```

**2. Dynamic Loading (Runtime Loading):**

**Method 1 - Load by Name:**

```csharp
using System;
using System.Reflection;

class Program
{
    static void Main()
    {
        // Load assembly by name
        Assembly assembly = Assembly.Load("MyLibrary");

        // Get type from assembly
        Type calcType = assembly.GetType("MyLibrary.Calculator");

        // Create instance
        object calcInstance = Activator.CreateInstance(calcType);

        // Invoke method
        MethodInfo addMethod = calcType.GetMethod("Add");
        object result = addMethod.Invoke(calcInstance, new object[] { 5, 3 });

        Console.WriteLine($"Result: {result}");
    }
}
```

**Method 2 - Load from File:**

```csharp
using System;
using System.Reflection;

class Program
{
    static void Main()
    {
        // Load assembly from file path
        Assembly assembly = Assembly.LoadFrom(@"C:\MyLibraries\MyLibrary.dll");

        // Use assembly
        Type calcType = assembly.GetType("MyLibrary.Calculator");
        object calcInstance = Activator.CreateInstance(calcType);

        MethodInfo addMethod = calcType.GetMethod("Add");
        object result = addMethod.Invoke(calcInstance, new object[] { 10, 20 });

        Console.WriteLine($"Result: {result}");
    }
}
```

**Method 3 - Load into Separate AppDomain:**

```csharp
using System;
using System.Reflection;

class Program
{
    static void Main()
    {
        // Create new application domain
        AppDomain newDomain = AppDomain.CreateDomain("MyDomain");

        // Load assembly into new domain
        newDomain.Load("MyLibrary");

        // Can unload entire domain later
        AppDomain.Unload(newDomain);
    }
}
```

### 3.7 Assembly Probing

**Assembly Probing** is the process CLR uses to locate and load assemblies.

#### Probing Process:

**1. For Strong-Named Assemblies:**

```
CLR searches in this order:
1. Global Assembly Cache (GAC)
2. Configuration files (binding redirects)
3. Application base directory
4. Private paths specified in config
```

**2. For Private Assemblies:**

```
CLR searches in:
1. Application base directory
2. Subdirectories matching assembly name
3. Culture-specific subdirectories
4. Private paths in app.config
```

#### Configuring Probing Path:

**App.config:**

```xml
<?xml version="1.0" encoding="utf-8" ?>
<configuration>
  <runtime>
    <assemblyBinding xmlns="urn:schemas-microsoft-com:asm.v1">
      <!-- Specify private probing paths -->
      <probing privatePath="bin;lib;assemblies" />
    </assemblyBinding>
  </runtime>
</configuration>
```

**Example Folder Structure:**

```
MyApp/
├── MyApp.exe
├── MyApp.exe.config
├── bin/
│   └── Library1.dll
├── lib/
│   └── Library2.dll
└── assemblies/
    └── Library3.dll
```

With the above config, CLR will search all three folders for assemblies.

### 3.8 Practical Examples

#### Example 1: Creating and Using a Math Library

**Step 1: Create MathLibrary.dll**

```csharp
// File: MathOperations.cs
using System;

namespace MathLibrary
{
    public class BasicMath
    {
        public int Add(int a, int b)
        {
            return a + b;
        }

        public int Subtract(int a, int b)
        {
            return a - b;
        }

        public int Multiply(int a, int b)
        {
            return a * b;
        }

        public double Divide(int a, int b)
        {
            if (b == 0)
                throw new DivideByZeroException("Cannot divide by zero");
            return (double)a / b;
        }

        public int Power(int baseNum, int exponent)
        {
            return (int)Math.Pow(baseNum, exponent);
        }

        public double SquareRoot(int number)
        {
            if (number < 0)
                throw new ArgumentException("Cannot calculate square root of negative number");
            return Math.Sqrt(number);
        }
    }

    public class AdvancedMath
    {
        public bool IsPrime(int number)
        {
            if (number <= 1) return false;
            if (number == 2) return true;
            if (number % 2 == 0) return false;

            for (int i = 3; i <= Math.Sqrt(number); i += 2)
            {
                if (number % i == 0)
                    return false;
            }
            return true;
        }

        public int Factorial(int n)
        {
            if (n < 0)
                throw new ArgumentException("Factorial not defined for negative numbers");
            if (n == 0 || n == 1)
                return 1;

            int result = 1;
            for (int i = 2; i <= n; i++)
            {
                result *= i;
            }
            return result;
        }

        public int GCD(int a, int b)
        {
            while (b != 0)
            {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        public int LCM(int a, int b)
        {
            return (a * b) / GCD(a, b);
        }
    }
}
```

**Step 2: Use in Console Application**

```csharp
using System;
using MathLibrary;

class Program
{
    static void Main()
    {
        // Create instances
        BasicMath basic = new BasicMath();
        AdvancedMath advanced = new AdvancedMath();

        Console.WriteLine("=== Basic Math Operations ===");
        Console.WriteLine($"10 + 5 = {basic.Add(10, 5)}");
        Console.WriteLine($"10 - 5 = {basic.Subtract(10, 5)}");
        Console.WriteLine($"10 * 5 = {basic.Multiply(10, 5)}");
        Console.WriteLine($"10 / 5 = {basic.Divide(10, 5)}");
        Console.WriteLine($"2 ^ 5 = {basic.Power(2, 5)}");
        Console.WriteLine($"√16 = {basic.SquareRoot(16)}");

        Console.WriteLine("\n=== Advanced Math Operations ===");
        Console.WriteLine($"Is 17 prime? {advanced.IsPrime(17)}");
        Console.WriteLine($"Factorial of 5: {advanced.Factorial(5)}");
        Console.WriteLine($"GCD(12, 18): {advanced.GCD(12, 18)}");
        Console.WriteLine($"LCM(4, 6): {advanced.LCM(4, 6)}");

        // Exception handling
        try
        {
            basic.Divide(10, 0);
        }
        catch (DivideByZeroException ex)
        {
            Console.WriteLine($"\nError: {ex.Message}");
        }
    }
}
```

#### Example 2: Reflection to Explore Assembly

```csharp
using System;
using System.Reflection;

class AssemblyExplorer
{
    static void Main()
    {
        // Load assembly
        Assembly assembly = Assembly.LoadFrom("MathLibrary.dll");

        Console.WriteLine("=== ASSEMBLY INFORMATION ===");
        AssemblyName name = assembly.GetName();
        Console.WriteLine($"Name: {name.Name}");
        Console.WriteLine($"Version: {name.Version}");
        Console.WriteLine($"Culture: {name.CultureInfo}");
        Console.WriteLine($"Full Name: {name.FullName}");

        Console.WriteLine("\n=== TYPES IN ASSEMBLY ===");
        Type[] types = assembly.GetTypes();
        foreach (Type type in types)
        {
            Console.WriteLine($"\nType: {type.Name}");
            Console.WriteLine("  Methods:");

            MethodInfo[] methods = type.GetMethods(BindingFlags.Public |
                                                   BindingFlags.Instance |
                                                   BindingFlags.DeclaredOnly);
            foreach (MethodInfo method in methods)
            {
                Console.Write($"    {method.ReturnType.Name} {method.Name}(");

                ParameterInfo[] parameters = method.GetParameters();
                for (int i = 0; i < parameters.Length; i++)
                {
                    Console.Write($"{parameters[i].ParameterType.Name} {parameters[i].Name}");
                    if (i < parameters.Length - 1)
                        Console.Write(", ");
                }
                Console.WriteLine(")");
            }
        }

        Console.WriteLine("\n=== REFERENCED ASSEMBLIES ===");
        AssemblyName[] references = assembly.GetReferencedAssemblies();
        foreach (AssemblyName reference in references)
        {
            Console.WriteLine($"  {reference.Name}, Version={reference.Version}");
        }
    }
}
```

#### Example 3: Late Binding (Dynamic Loading)

```csharp
using System;
using System.Reflection;

class LateBinder
{
    static void Main()
    {
        Console.Write("Enter DLL name: ");
        string dllName = Console.ReadLine();

        Console.Write("Enter class name: ");
        string className = Console.ReadLine();

        Console.Write("Enter method name: ");
        string methodName = Console.ReadLine();

        try
        {
            // Load assembly dynamically
            Assembly assembly = Assembly.LoadFrom(dllName);

            // Get type
            Type type = assembly.GetType(className);
            if (type == null)
            {
                Console.WriteLine($"Class {className} not found!");
                return;
            }

            // Create instance
            object instance = Activator.CreateInstance(type);

            // Get method
            MethodInfo method = type.GetMethod(methodName);
            if (method == null)
            {
                Console.WriteLine($"Method {methodName} not found!");
                return;
            }

            // Get parameters
            ParameterInfo[] parameters = method.GetParameters();
            object[] args = new object[parameters.Length];

            for (int i = 0; i < parameters.Length; i++)
            {
                Console.Write($"Enter value for {parameters[i].Name} ({parameters[i].ParameterType.Name}): ");
                string input = Console.ReadLine();
                args[i] = Convert.ChangeType(input, parameters[i].ParameterType);
            }

            // Invoke method
            object result = method.Invoke(instance, args);

            Console.WriteLine($"\nResult: {result}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }
}
```

**Sample Run:**

```
Enter DLL name: MathLibrary.dll
Enter class name: MathLibrary.BasicMath
Enter method name: Add
Enter value for a (Int32): 15
Enter value for b (Int32): 25

Result: 40
```

### 3.9 Important Interview Questions & Concepts

#### Question 1: What is the difference between private and shared assemblies?

**Answer:**
| Aspect | Private Assembly | Shared Assembly |
|--------|-----------------|-----------------|
| Location | Application folder | Global Assembly Cache (GAC) |
| Usage | Single application | Multiple applications |
| Strong Name | Not required | Required |
| Versioning | No version checking | Strict version checking |
| Deployment | Copy to app folder | Install in GAC using gacutil |
| Isolation | Isolated per app | Shared across apps |

#### Question 2: What is GAC and why is it needed?

**Answer:**
GAC (Global Assembly Cache) is a machine-wide code cache that stores assemblies shared by multiple applications.

**Why Needed:**

- Centralized location for shared assemblies
- Multiple versions can coexist
- Improved performance (shared in memory)
- Ensures integrity through strong naming
- Solves DLL Hell problem

**Location:** `C:\Windows\Assembly` (pre-.NET 4.0) or `C:\Windows\Microsoft.NET\assembly` (.NET 4.0+)

#### Question 3: How do you create a strong-named assembly?

**Answer:**

```csharp
// Step 1: Generate key pair
// Command: sn -k mykey.snk

// Step 2: Add to AssemblyInfo.cs
[assembly: AssemblyKeyFile("mykey.snk")]

// Or use project properties in Visual Studio:
// Project → Properties → Signing → Sign the assembly

// Step 3: Build project
// Step 4: Verify strong name
// Command: sn -v MyAssembly.dll
```

#### Question 4: Explain assembly versioning.

**Answer:**
Assembly version has four parts: **Major.Minor.Build.Revision**

```csharp
[assembly: AssemblyVersion("1.2.3.4")]
//                          │ │ │ └─ Revision (bug fixes)
//                          │ │ └─── Build number
//                          │ └───── Minor version (backward compatible)
//                          └─────── Major version (breaking changes)
```

**Version Compatibility:**

- Different Major versions: Not compatible
- Different Minor versions: Usually compatible
- Different Build/Revision: Compatible

#### Question 5: What happens during assembly loading?

**Answer:**

1. **Request:** Application requests a type/method
2. **Locate:** CLR searches for assembly:
   - GAC (for strong-named)
   - Application directory
   - Probing paths
3. **Verify:** Check strong name signature (if applicable)
4. **Load:** Load assembly into memory
5. **JIT Compile:** Compile IL to native code
6. **Execute:** Run the code

#### Question 6: Advantages of assemblies over traditional DLLs?

**Answer:**

1. **Self-describing** - No registry needed
2. **Version control** - Multiple versions coexist
3. **Side-by-side execution** - No conflicts
4. **XCOPY deployment** - Just copy files
5. **Strong naming** - Security and integrity
6. **Language interoperability** - Any .NET language
7. **Metadata included** - Type information embedded
8. **No DLL Hell** - Isolated deployment

---

## SUMMARY AND KEY POINTS

### Unit 1 Summary:

- **.NET Framework** is a platform for building and running applications
- **CLR** manages code execution, memory, security, and exception handling
- **IDE (Visual Studio)** provides tools for coding, debugging, and designing
- **JIT Compiler** converts IL to native code at runtime
- **Garbage Collection** automatically manages memory

### Unit 2 Summary:

- **Data Types:** Value types (int, float, struct) and Reference types (string, array, class)
- **Keywords:** Reserved words with special meaning (if, for, class, etc.)
- **Operators:** Arithmetic (+, -, \*, /), Logical (&&, ||), Comparison (==, !=)
- **Conditionals:** if-else, switch statements for decision making
- **Loops:** for, while, do-while, foreach for repetition

### Unit 3 Summary:

- **Assembly:** Fundamental unit of deployment containing IL code and metadata
- **Private Assembly:** Used by single application, stored in app folder
- **Shared Assembly:** Used by multiple apps, stored in GAC, requires strong name
- **Strong Name:** Unique identity using public key cryptography
- **Side-by-Side Execution:** Multiple versions run simultaneously
- **Benefits:** Version control, XCOPY deployment, no DLL Hell, security

---

## PRACTICE QUESTIONS

### Short Answer Questions (3 marks each):

1. **What is CLR? Explain its role in .NET Framework.**
2. **Differentiate between value types and reference types with examples.**
3. **What is assembly manifest? What information does it contain?**
4. **Explain the concept of side-by-side execution.**
5. **Write a program to find the largest of three numbers using if-else.**
6. **What are the advantages of .NET assemblies over traditional DLLs?**
7. **Explain break and continue statements with examples.**
8. **What is strong name? Why is it required for shared assemblies?**
9. **Differentiate between for and foreach loops.**
10. **What is GAC? How do you install an assembly in GAC?**

### Long Answer Questions (10 marks each):

1. **Explain the architecture of .NET Framework in detail. Describe the role of CLR and its key features.**

2. **Write a C# program demonstrating all types of operators (arithmetic, logical, relational, bitwise). Show practical examples of each.**

3. **What are assemblies in .NET? Explain private and shared assemblies with their advantages and disadvantages. How do you create a shared assembly?**

4. **Explain different types of loops in C# with syntax and examples. Write a program using nested loops to print a pattern.**

5. **Describe the process of creating and using a class library (DLL). Write code to demonstrate both creation and consumption of the library.**

---

**End of Units 1, 2, and 3 Notes**
