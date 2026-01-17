# C# Programming Practice Guide

## Unit 2: Programming in C# - 10 Programs

### Program 1: Value Types & Reference Types - Employee Data Management
**Question:** Demonstrate value types (int, double, bool, enum, struct) vs reference types (string, arrays)

```csharp
using System;

// Enum for employee department
enum Department { IT, HR, Finance, Marketing, Sales }

// Structure for salary details
struct SalaryInfo
{
    public double Basic;
    public double HRA;
    public double DA;

    public double CalculateTotal()
    {
        return Basic + HRA + DA;
    }
}

class Program1
{
    static void Main()
    {
        Console.WriteLine("=== Employee Data Management ===");

        // Value types
        int empId = 1001;
        bool isActive = true;
        Department dept = Department.IT;

        // Structure (value type)
        SalaryInfo salary;
        salary.Basic = 50000;
        salary.HRA = 15000;
        salary.DA = 10000;

        // Reference types
        string empName = "Rajesh Kumar";
        string[] skills = { "C#", "ASP.NET", "SQL" };

        Console.WriteLine($"Employee ID: {empId}");
        Console.WriteLine($"Name: {empName}");
        Console.WriteLine($"Department: {dept}");
        Console.WriteLine($"Active: {isActive}");
        Console.WriteLine($"Total Salary: ₹{salary.CalculateTotal()}");
        Console.Write("Skills: ");
        foreach (string skill in skills)
            Console.Write(skill + " ");
        Console.WriteLine("\n");
    }
}
```

---

### Program 2: Nullable Types & Type Conversion
**Question:** Work with nullable types, implicit and explicit type conversions

```csharp
using System;

class Program2
{
    static void Main()
    {
        Console.WriteLine("=== Nullable Types & Type Conversion ===");

        // Nullable types
        int? marks = null;
        double? percentage = 85.5;

        Console.WriteLine($"Marks: {marks ?? 0} (using null-coalescing)");
        Console.WriteLine($"Percentage: {percentage?.ToString() ?? "N/A"}");

        // Implicit conversion (smaller to larger)
        int num = 100;
        long bigNum = num;
        double decNum = num;

        Console.WriteLine($"\nImplicit: int {num} -> long {bigNum} -> double {decNum}");

        // Explicit conversion (larger to smaller)
        double pi = 3.14159;
        int truncated = (int)pi;

        Console.WriteLine($"Explicit: double {pi} -> int {truncated}");

        // Using Convert class
        string strNum = "250";
        int converted = Convert.ToInt32(strNum);

        Console.WriteLine($"String '{strNum}' -> int {converted}");

        // Checking null values
        if (marks.HasValue)
            Console.WriteLine($"Marks value: {marks.Value}");
        else
            Console.WriteLine("Marks not assigned yet\n");
    }
}
```

---

### Program 3: Advanced Operators - Bitwise & Ternary
**Question:** Implement bitwise operators and ternary operator for practical scenarios

```csharp
using System;

class Program3
{
    static void Main()
    {
        Console.WriteLine("=== Advanced Operators ===");

        // Bitwise operators (file permissions simulation)
        int READ = 4;    // 100 in binary
        int WRITE = 2;   // 010 in binary
        int EXECUTE = 1; // 001 in binary

        int userPermission = READ | WRITE;  // Bitwise OR
        int adminPermission = READ | WRITE | EXECUTE;

        Console.WriteLine("File Permissions:");
        Console.WriteLine($"User: {userPermission} (Binary: {Convert.ToString(userPermission, 2)})");
        Console.WriteLine($"Admin: {adminPermission} (Binary: {Convert.ToString(adminPermission, 2)})");

        // Check specific permission using AND
        bool canExecute = (userPermission & EXECUTE) != 0;
        Console.WriteLine($"Can user execute? {canExecute}");

        // Ternary operator
        int score = 75;
        string result = score >= 40 ? "Pass" : "Fail";
        string grade = score >= 90 ? "A" : score >= 75 ? "B" : score >= 60 ? "C" : "D";

        Console.WriteLine($"\nScore: {score}");
        Console.WriteLine($"Result: {result}");
        Console.WriteLine($"Grade: {grade}");

        // Null-coalescing operator
        string userName = null;
        string displayName = userName ?? "Guest";
        Console.WriteLine($"Display Name: {displayName}\n");
    }
}
```

---

### Program 4: Switch Expression (C# 8.0+) - Order Processing
**Question:** Use modern switch expressions for order status management

```csharp
using System;

enum OrderStatus { Pending, Processing, Shipped, Delivered, Cancelled }

class Program4
{
    static void Main()
    {
        Console.WriteLine("=== Order Processing System ===");

        OrderStatus status = OrderStatus.Shipped;

        // Switch expression (modern C#)
        string message = status switch
        {
            OrderStatus.Pending => "Order is pending confirmation",
            OrderStatus.Processing => "Order is being processed",
            OrderStatus.Shipped => "Order has been shipped",
            OrderStatus.Delivered => "Order delivered successfully",
            OrderStatus.Cancelled => "Order was cancelled",
            _ => "Unknown status"
        };

        int daysToDeliver = status switch
        {
            OrderStatus.Pending => 5,
            OrderStatus.Processing => 4,
            OrderStatus.Shipped => 2,
            OrderStatus.Delivered => 0,
            OrderStatus.Cancelled => -1,
            _ => 0
        };

        double discount = status switch
        {
            OrderStatus.Delivered => 10.0,
            OrderStatus.Cancelled => 0.0,
            _ => 5.0
        };

        Console.WriteLine($"Status: {status}");
        Console.WriteLine($"Message: {message}");
        Console.WriteLine($"Estimated Days: {daysToDeliver}");
        Console.WriteLine($"Discount: {discount}%\n");
    }
}
```

---

### Program 5: For Loop Variations - Pattern Printing
**Question:** Use nested loops to create patterns and work with loop control

```csharp
using System;

class Program5
{
    static void Main()
    {
        Console.WriteLine("=== Pattern Printing ===");

        int rows = 5;

        // Right triangle
        Console.WriteLine("Right Triangle:");
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                Console.Write("* ");
            }
            Console.WriteLine();
        }

        // Pyramid
        Console.WriteLine("\nPyramid:");
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= rows - i; j++)
                Console.Write(" ");
            for (int k = 1; k <= 2 * i - 1; k++)
                Console.Write("*");
            Console.WriteLine();
        }

        // Number pattern with continue
        Console.WriteLine("\nNumber Pattern (skip multiples of 3):");
        for (int i = 1; i <= 20; i++)
        {
            if (i % 3 == 0)
                continue;
            Console.Write(i + " ");
        }
        Console.WriteLine("\n");
    }
}
```

---

### Program 6: While & Do-While - Menu-Driven Calculator
**Question:** Create a menu-driven program using while loop with break/continue

```csharp
using System;

class Program6
{
    static void Main()
    {
        Console.WriteLine("=== Menu-Driven Calculator ===");

        int choice;
        double num1, num2, result;

        do
        {
            Console.WriteLine("\n1. Addition");
            Console.WriteLine("2. Subtraction");
            Console.WriteLine("3. Multiplication");
            Console.WriteLine("4. Division");
            Console.WriteLine("5. Modulus");
            Console.WriteLine("0. Exit");
            Console.Write("Enter choice: ");

            choice = Convert.ToInt32(Console.ReadLine());

            if (choice == 0)
                break;

            if (choice < 1 || choice > 5)
            {
                Console.WriteLine("Invalid choice!");
                continue;
            }

            Console.Write("Enter first number: ");
            num1 = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter second number: ");
            num2 = Convert.ToDouble(Console.ReadLine());

            result = choice switch
            {
                1 => num1 + num2,
                2 => num1 - num2,
                3 => num1 * num2,
                4 => num2 != 0 ? num1 / num2 : double.NaN,
                5 => num1 % num2,
                _ => 0
            };

            if (double.IsNaN(result))
                Console.WriteLine("Error: Division by zero!");
            else
                Console.WriteLine($"Result: {result}");

        } while (choice != 0);

        Console.WriteLine("Calculator closed.\n");
    }
}
```

---

### Program 7: Arrays & Foreach - Student Grade Analysis
**Question:** Analyze student grades using arrays and foreach loop

```csharp
using System;

class Program7
{
    static void Main()
    {
        Console.WriteLine("=== Student Grade Analysis ===");

        // Jagged array for student marks
        int[][] classMarks = new int[3][];
        classMarks[0] = new int[] { 85, 90, 78, 92 };
        classMarks[1] = new int[] { 76, 88, 95 };
        classMarks[2] = new int[] { 82, 79, 85, 88, 90 };

        string[] studentNames = { "Section A", "Section B", "Section C" };

        int studentNum = 0;
        foreach (int[] marks in classMarks)
        {
            Console.WriteLine($"\n{studentNames[studentNum]}:");

            int total = 0, count = 0, max = int.MinValue, min = int.MaxValue;

            foreach (int mark in marks)
            {
                total += mark;
                count++;
                if (mark > max) max = mark;
                if (mark < min) min = mark;
            }

            double average = (double)total / count;

            Console.WriteLine($"Students: {count}");
            Console.WriteLine($"Average: {average:F2}");
            Console.WriteLine($"Highest: {max}");
            Console.WriteLine($"Lowest: {min}");

            studentNum++;
        }
        Console.WriteLine();
    }
}
```

---

### Program 8: String Manipulation & StringBuilder
**Question:** Perform various string operations and compare String vs StringBuilder

```csharp
using System;
using System.Text;

class Program8
{
    static void Main()
    {
        Console.WriteLine("=== String Manipulation ===");

        string text = "  C# Programming Language  ";

        // String methods
        Console.WriteLine($"Original: '{text}'");
        Console.WriteLine($"Trimmed: '{text.Trim()}'");
        Console.WriteLine($"Uppercase: {text.ToUpper().Trim()}");
        Console.WriteLine($"Substring: {text.Substring(5, 11)}");
        Console.WriteLine($"Replace: {text.Replace("C#", "CSharp")}");
        Console.WriteLine($"Contains 'Programming': {text.Contains("Programming")}");

        // String split
        string csv = "John,25,IT,Developer";
        string[] parts = csv.Split(',');
        Console.WriteLine("\nCSV Parsing:");
        Console.WriteLine($"Name: {parts[0]}, Age: {parts[1]}, Dept: {parts[2]}, Role: {parts[3]}");

        // StringBuilder for efficient string building
        StringBuilder sb = new StringBuilder();
        Console.WriteLine("\nUsing StringBuilder:");

        for (int i = 1; i <= 5; i++)
        {
            sb.Append($"Line {i}");
            if (i < 5) sb.AppendLine();
        }

        Console.WriteLine(sb.ToString());
        sb.Insert(0, "Header\n");
        sb.AppendLine("\nFooter");
        Console.WriteLine($"\nFinal Output:\n{sb}\n");
    }
}
```

---

### Program 9: Exception Handling - ATM Withdrawal System
**Question:** Implement try-catch-finally for error handling in ATM operations

```csharp
using System;

class Program9
{
    static void Main()
    {
        Console.WriteLine("=== ATM Withdrawal System ===");

        double balance = 5000;
        double withdrawAmount;

        try
        {
            Console.Write("Enter withdrawal amount: ");
            withdrawAmount = Convert.ToDouble(Console.ReadLine());

            if (withdrawAmount <= 0)
                throw new ArgumentException("Amount must be positive!");

            if (withdrawAmount > balance)
                throw new InvalidOperationException("Insufficient balance!");

            if (withdrawAmount % 100 != 0)
                throw new ArgumentException("Amount must be multiple of 100!");

            balance -= withdrawAmount;
            Console.WriteLine($"Withdrawal successful!");
            Console.WriteLine($"Amount withdrawn: ₹{withdrawAmount}");
            Console.WriteLine($"Remaining balance: ₹{balance}");
        }
        catch (FormatException)
        {
            Console.WriteLine("Error: Please enter a valid number!");
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
        catch (InvalidOperationException ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Unexpected error: {ex.Message}");
        }
        finally
        {
            Console.WriteLine("Thank you for using our ATM service.\n");
        }
    }
}
```

---

### Program 10: Struct vs Class - Performance Comparison
**Question:** Compare struct and class behavior with memory allocation

```csharp
using System;

// Struct (Value Type - Stack allocation)
struct Point2D
{
    public int X;
    public int Y;

    public Point2D(int x, int y)
    {
        X = x;
        Y = y;
    }

    public double Distance()
    {
        return Math.Sqrt(X * X + Y * Y);
    }
}

// Class (Reference Type - Heap allocation)
class Circle
{
    public Point2D Center;
    public double Radius;

    public Circle(Point2D center, double radius)
    {
        Center = center;
        Radius = radius;
    }

    public double Area()
    {
        return Math.PI * Radius * Radius;
    }
}

class Program10
{
    static void Main()
    {
        Console.WriteLine("=== Struct vs Class Behavior ===");

        // Struct behavior (value type)
        Point2D p1 = new Point2D(3, 4);
        Point2D p2 = p1;  // Creates a copy
        p2.X = 10;

        Console.WriteLine("Struct (Value Type):");
        Console.WriteLine($"p1: ({p1.X}, {p1.Y})");
        Console.WriteLine($"p2: ({p2.X}, {p2.Y})");
        Console.WriteLine("p1 and p2 are independent copies\n");

        // Class behavior (reference type)
        Circle c1 = new Circle(new Point2D(0, 0), 5);
        Circle c2 = c1;  // Copies reference, not object
        c2.Radius = 10;

        Console.WriteLine("Class (Reference Type):");
        Console.WriteLine($"c1 radius: {c1.Radius}");
        Console.WriteLine($"c2 radius: {c2.Radius}");
        Console.WriteLine("c1 and c2 point to same object\n");

        // Performance characteristics
        Console.WriteLine($"Point distance from origin: {p1.Distance():F2}");
        Console.WriteLine($"Circle area: {c1.Area():F2}\n");
    }
}
```

---

## OOP Concepts in C# - 5 Programs

### Program 11: Classes, Properties & Constructors - Library Management
**Question:** Create a Book class with properties, constructors, and methods

```csharp
using System;

class Book
{
    // Auto-implemented properties
    public string Title { get; set; }
    public string Author { get; set; }
    public string ISBN { get; private set; }

    // Property with backing field
    private decimal price;
    public decimal Price
    {
        get { return price; }
        set
        {
            if (value >= 0)
                price = value;
            else
                throw new ArgumentException("Price cannot be negative");
        }
    }

    // Read-only property
    public int PublicationYear { get; }

    // Constructors
    public Book()
    {
        Title = "Unknown";
        Author = "Unknown";
        ISBN = "000-0-00-000000-0";
        PublicationYear = DateTime.Now.Year;
    }

    public Book(string title, string author, string isbn, int year, decimal price)
    {
        Title = title;
        Author = author;
        ISBN = isbn;
        PublicationYear = year;
        Price = price;
    }

    // Method
    public void DisplayInfo()
    {
        Console.WriteLine($"Title: {Title}");
        Console.WriteLine($"Author: {Author}");
        Console.WriteLine($"ISBN: {ISBN}");
        Console.WriteLine($"Year: {PublicationYear}");
        Console.WriteLine($"Price: ₹{Price}");
    }

    public int GetAge()
    {
        return DateTime.Now.Year - PublicationYear;
    }
}

class Program11
{
    static void Main()
    {
        Console.WriteLine("=== Library Management System ===\n");

        Book book1 = new Book("C# in Depth", "Jon Skeet", "978-1-61729-134-3", 2019, 899);
        Book book2 = new Book();

        Console.WriteLine("Book 1:");
        book1.DisplayInfo();
        Console.WriteLine($"Age: {book1.GetAge()} years\n");

        Console.WriteLine("Book 2 (Default):");
        book2.DisplayInfo();
        Console.WriteLine();
    }
}
```

---

### Program 12: Encapsulation & Access Modifiers - Banking System
**Question:** Implement proper encapsulation with private, protected, and public members

```csharp
using System;
using System.Collections.Generic;

class BankAccount
{
    // Private fields
    private string accountNumber;
    private string accountHolder;
    private decimal balance;
    private List<string> transactions;

    // Public property with validation
    public string AccountNumber
    {
        get { return accountNumber; }
        private set { accountNumber = value; }
    }

    // Protected field (accessible in derived classes)
    protected decimal minimumBalance = 1000;

    // Constructor
    public BankAccount(string accNum, string holder, decimal initialBalance)
    {
        AccountNumber = accNum;
        accountHolder = holder;
        balance = initialBalance;
        transactions = new List<string>();
        AddTransaction($"Account opened with ₹{initialBalance}");
    }

    // Private method
    private void AddTransaction(string transaction)
    {
        transactions.Add($"{DateTime.Now:dd-MM-yyyy HH:mm} - {transaction}");
    }

    // Public methods
    public void Deposit(decimal amount)
    {
        if (amount > 0)
        {
            balance += amount;
            AddTransaction($"Deposited ₹{amount}");
            Console.WriteLine($"Successfully deposited ₹{amount}");
        }
    }

    public bool Withdraw(decimal amount)
    {
        if (amount > 0 && balance - amount >= minimumBalance)
        {
            balance -= amount;
            AddTransaction($"Withdrawn ₹{amount}");
            Console.WriteLine($"Successfully withdrawn ₹{amount}");
            return true;
        }
        Console.WriteLine("Insufficient balance or invalid amount!");
        return false;
    }

    public decimal GetBalance()
    {
        return balance;
    }

    public void ShowStatement()
    {
        Console.WriteLine($"\n--- Account Statement for {accountHolder} ---");
        Console.WriteLine($"Account Number: {AccountNumber}");
        foreach (string trans in transactions)
        {
            Console.WriteLine(trans);
        }
        Console.WriteLine($"Current Balance: ₹{balance}");
        Console.WriteLine("-----------------------------\n");
    }
}

class Program12
{
    static void Main()
    {
        Console.WriteLine("=== Banking System ===\n");

        BankAccount account = new BankAccount("SB001234", "Priya Sharma", 5000);
        account.Deposit(2000);
        account.Withdraw(1500);
        account.Withdraw(6000); // Will fail
        account.ShowStatement();
    }
}
```

---

### Program 13: Inheritance & Method Overriding - Employee Hierarchy
**Question:** Create employee hierarchy with base and derived classes

```csharp
using System;

// Base class
class Employee
{
    public int EmployeeId { get; set; }
    public string Name { get; set; }
    public string Department { get; set; }
    protected decimal baseSalary;

    public Employee(int id, string name, string dept, decimal salary)
    {
        EmployeeId = id;
        Name = name;
        Department = dept;
        baseSalary = salary;
    }

    // Virtual method (can be overridden)
    public virtual decimal CalculateSalary()
    {
        return baseSalary;
    }

    public virtual void DisplayInfo()
    {
        Console.WriteLine($"ID: {EmployeeId}");
        Console.WriteLine($"Name: {Name}");
        Console.WriteLine($"Department: {Department}");
        Console.WriteLine($"Salary: ₹{CalculateSalary()}");
    }
}

// Derived class 1
class Manager : Employee
{
    public decimal Bonus { get; set; }
    public int TeamSize { get; set; }

    public Manager(int id, string name, string dept, decimal salary, decimal bonus, int team)
        : base(id, name, dept, salary)
    {
        Bonus = bonus;
        TeamSize = team;
    }

    public override decimal CalculateSalary()
    {
        return baseSalary + Bonus + (TeamSize * 500);
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Bonus: ₹{Bonus}");
        Console.WriteLine($"Team Size: {TeamSize}");
    }
}

// Derived class 2
class Developer : Employee
{
    public string[] Skills { get; set; }
    public int ProjectsCompleted { get; set; }

    public Developer(int id, string name, string dept, decimal salary, string[] skills, int projects)
        : base(id, name, dept, salary)
    {
        Skills = skills;
        ProjectsCompleted = projects;
    }

    public override decimal CalculateSalary()
    {
        decimal projectBonus = ProjectsCompleted * 2000;
        return baseSalary + projectBonus;
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.Write("Skills: ");
        foreach (string skill in Skills)
            Console.Write(skill + " ");
        Console.WriteLine($"\nProjects: {ProjectsCompleted}");
    }
}

class Program13
{
    static void Main()
    {
        Console.WriteLine("=== Employee Management System ===\n");

        Manager mgr = new Manager(101, "Amit Singh", "IT", 80000, 15000, 8);
        Developer dev = new Developer(102, "Sneha Patel", "Development", 60000,
                                     new string[] { "C#", "SQL", "Azure" }, 5);

        Console.WriteLine("MANAGER DETAILS:");
        mgr.DisplayInfo();

        Console.WriteLine("\nDEVELOPER DETAILS:");
        dev.DisplayInfo();
        Console.WriteLine();
    }
}
```

---

### Program 14: Polymorphism & Interfaces - Payment Gateway
**Question:** Implement runtime polymorphism using interfaces

```csharp
using System;

// Interface
interface IPayment
{
    bool ProcessPayment(decimal amount);
    void GenerateReceipt();
    string GetPaymentMethod();
}

// Implementation 1
class CreditCardPayment : IPayment
{
    private string cardNumber;
    private decimal amountPaid;

    public CreditCardPayment(string card)
    {
        cardNumber = card;
    }

    public bool ProcessPayment(decimal amount)
    {
        amountPaid = amount;
        Console.WriteLine($"Processing credit card payment of ₹{amount}...");
        Console.WriteLine("Payment successful!");
        return true;
    }

    public void GenerateReceipt()
    {
        Console.WriteLine("\n--- RECEIPT ---");
        Console.WriteLine($"Payment Method: Credit Card");
        Console.WriteLine($"Card: XXXX-XXXX-XXXX-{cardNumber.Substring(cardNumber.Length - 4)}");
        Console.WriteLine($"Amount: ₹{amountPaid}");
        Console.WriteLine("---------------\n");
    }

    public string GetPaymentMethod()
    {
        return "Credit Card";
    }
}

// Implementation 2
class UPIPayment : IPayment
{
    private string upiId;
    private decimal amountPaid;

    public UPIPayment(string upi)
    {
        upiId = upi;
    }

    public bool ProcessPayment(decimal amount)
    {
        amountPaid = amount;
        Console.WriteLine($"Processing UPI payment of ₹{amount}...");
        Console.WriteLine("Payment successful!");
        return true;
    }

    public void GenerateReceipt()
    {
        Console.WriteLine("\n--- RECEIPT ---");
        Console.WriteLine($"Payment Method: UPI");
        Console.WriteLine($"UPI ID: {upiId}");
        Console.WriteLine($"Amount: ₹{amountPaid}");
        Console.WriteLine("---------------\n");
    }

    public string GetPaymentMethod()
    {
        return "UPI";
    }
}

// Implementation 3
class NetBankingPayment : IPayment
{
    private string bankName;
    private decimal amountPaid;

    public NetBankingPayment(string bank)
    {
        bankName = bank;
    }

    public bool ProcessPayment(decimal amount)
    {
        amountPaid = amount;
        Console.WriteLine($"Processing net banking payment of ₹{amount}...");
        Console.WriteLine("Redirecting to bank portal...");
        Console.WriteLine("Payment successful!");
        return true;
    }

    public void GenerateReceipt()
    {
        Console.WriteLine("\n--- RECEIPT ---");
        Console.WriteLine($"Payment Method: Net Banking");
        Console.WriteLine($"Bank: {bankName}");
        Console.WriteLine($"Amount: ₹{amountPaid}");
        Console.WriteLine("---------------\n");
    }

    public string GetPaymentMethod()
    {
        return "Net Banking";
    }
}

class Program14
{
    static void Main()
    {
        Console.WriteLine("=== Payment Gateway System ===\n");

        // Polymorphism - same interface, different implementations
        IPayment[] payments = new IPayment[3];
        payments[0] = new CreditCardPayment("1234-5678-9012-3456");
        payments[1] = new UPIPayment("user@paytm");
        payments[2] = new NetBankingPayment("HDFC Bank");

        decimal[] amounts = { 1500, 2500, 3000 };

        for (int i = 0; i < payments.Length; i++)
        {
            Console.WriteLine($"Transaction {i + 1}:");
            payments[i].ProcessPayment(amounts[i]);
            payments[i].GenerateReceipt();
        }
    }
}
```

---

### Program 15: Abstract Classes - Vehicle Management
**Question:** Use abstract classes to implement common behavior with forced implementation

```csharp
using System;

// Abstract class
abstract class Vehicle
{
    public string Brand { get; set; }
    public string Model { get; set; }
    public int Year { get; set; }
    protected double fuelLevel;

    public Vehicle(string brand, string model, int year)
    {
        Brand = brand;
        Model = model;
        Year = year;
        fuelLevel = 0;
    }

    // Abstract methods (must be implemented by derived classes)
    public abstract void Start();
    public abstract void Stop();
    public abstract double CalculateMileage();

    // Concrete method
    public void Refuel(double liters)
    {
        fuelLevel += liters;
        Console.WriteLine($"Refueled {liters}L. Current fuel: {fuelLevel}L");
    }

    public void DisplayInfo()
    {
        Console.WriteLine($"{Brand} {Model} ({Year})");
        Console.WriteLine($"Fuel Level: {fuelLevel}L");
        Console.WriteLine($"Mileage: {CalculateMileage()} km/L");
    }
}

// Derived class 1
class Car : Vehicle
{
    public int Doors { get; set; }
    private bool isRunning;

    public Car(string brand, string model, int year, int doors)
        : base(brand, model, year)
    {
        Doors = doors;
        isRunning = false;
    }

    public override void Start()
    {
        if (fuelLevel > 0)
        {
            isRunning = true;
            Console.WriteLine("Car engine started. Vroom!");
        }
        else
        {
            Console.WriteLine("Cannot start. No fuel!");
        }
    }

    public override void Stop()
    {
        isRunning = false;
        Console.WriteLine("Car engine stopped.");
    }

    public override<function_calls>
<invoke name="artifacts">
<parameter name="command">update</parameter>
<parameter name="id">csharp_basics_programs</parameter>
<parameter name="old_str">    public override</parameter>
<parameter name="new_str">    public override double CalculateMileage()
    {
        return 15.5; // km per liter for car
    }
}

// Derived class 2
class Motorcycle : Vehicle
{
    public string Type { get; set; }
    private bool isRunning;

    public Motorcycle(string brand, string model, int year, string type)
        : base(brand, model, year)
    {
        Type = type;
        isRunning = false;
    }

    public override void Start()
    {
        if (fuelLevel > 0)
        {
            isRunning = true;
            Console.WriteLine("Motorcycle started. Kick!");
        }
        else
        {
            Console.WriteLine("Cannot start. No fuel!");
        }
    }

    public override void Stop()
    {
        isRunning = false;
        Console.WriteLine("Motorcycle stopped.");
    }

    public override double CalculateMileage()
    {
        return Type == "Sports" ? 25.0 : 40.0; // Different mileage for sports vs standard
    }
}

class Program15
{
    static void Main()
    {
        Console.WriteLine("=== Vehicle Management System ===\n");

        Vehicle[] vehicles = new Vehicle[2];
        vehicles[0] = new Car("Honda", "City", 2023, 4);
        vehicles[1] = new Motorcycle("Yamaha", "R15", 2024, "Sports");

        foreach (Vehicle v in vehicles)
        {
            Console.WriteLine($"\n--- {v.GetType().Name} ---");
            v.DisplayInfo();
            v.Refuel(10);
            v.Start();
            v.Stop();
        }
        Console.WriteLine();
    }
}
```

---

## Summary

### Unit 2 - Advanced Concepts Covered:

**Data Types:**
- ✅ Value Types (int, double, bool, char, decimal)
- ✅ Reference Types (string, arrays, objects)
- ✅ Enumerations (enum)
- ✅ Structures (struct)
- ✅ Nullable Types (int?, double?)
- ✅ Type Conversion (implicit, explicit, Convert class)

**Operators:**
- ✅ Arithmetic (+, -, *, /, %)
- ✅ Relational (==, !=, <, >, <=, >=)
- ✅ Logical (&&, ||, !)
- ✅ Bitwise (&, |, ^, ~, <<, >>)
- ✅ Ternary (?:)
- ✅ Null-coalescing (??, ??=)

**Control Structures:**
- ✅ If-else statements
- ✅ Switch statements & expressions
- ✅ For loops (with nested patterns)
- ✅ While loops
- ✅ Do-while loops
- ✅ Break & Continue
- ✅ Foreach loops

**Advanced Topics:**
- ✅ Exception Handling (try-catch-finally)
- ✅ String manipulation & StringBuilder
- ✅ Arrays (single, multi-dimensional, jagged)

### OOP - Core Pillars:

**1. Encapsulation:**
- ✅ Properties (auto-implemented, with backing fields)
- ✅ Access modifiers (private, protected, public)
- ✅ Getters and Setters

**2. Inheritance:**
- ✅ Base and derived classes
- ✅ Constructor chaining (: base())
- ✅ Method overriding (virtual/override)
- ✅ Protected members

**3. Polymorphism:**
- ✅ Compile-time (method overloading)
- ✅ Runtime (method overriding)
- ✅ Interface implementation
- ✅ Abstract classes

**4. Abstraction:**
- ✅ Abstract classes
- ✅ Abstract methods
- ✅ Interfaces
- ✅ Separation of interface and implementation

### Program: Simple Calculator

```csharp
using System;
using System.Windows.Forms;

namespace SimpleCalculator
{
    public partial class Form1 : Form
    {
        // Controls: TextBox, Button, Label
        private TextBox txtNum1;
        private TextBox txtNum2;
        private Label lblResult;
        private Button btnAdd;
        private Button btnSubtract;
        private Button btnMultiply;
        private Button btnDivide;

        public Form1()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            this.Text = "Simple Calculator";
            this.Size = new System.Drawing.Size(350, 250);

            // Label for Number 1
            Label lbl1 = new Label();
            lbl1.Text = "Number 1:";
            lbl1.Location = new System.Drawing.Point(20, 20);
            lbl1.Size = new System.Drawing.Size(80, 20);
            this.Controls.Add(lbl1);

            // TextBox for Number 1
            txtNum1 = new TextBox();
            txtNum1.Location = new System.Drawing.Point(110, 20);
            txtNum1.Size = new System.Drawing.Size(200, 20);
            this.Controls.Add(txtNum1);

            // Label for Number 2
            Label lbl2 = new Label();
            lbl2.Text = "Number 2:";
            lbl2.Location = new System.Drawing.Point(20, 50);
            lbl2.Size = new System.Drawing.Size(80, 20);
            this.Controls.Add(lbl2);

            // TextBox for Number 2
            txtNum2 = new TextBox();
            txtNum2.Location = new System.Drawing.Point(110, 50);
            txtNum2.Size = new System.Drawing.Size(200, 20);
            this.Controls.Add(txtNum2);

            // Buttons
            btnAdd = new Button();
            btnAdd.Text = "+";
            btnAdd.Location = new System.Drawing.Point(20, 90);
            btnAdd.Size = new System.Drawing.Size(60, 30);
            btnAdd.Click += BtnAdd_Click;
            this.Controls.Add(btnAdd);

            btnSubtract = new Button();
            btnSubtract.Text = "-";
            btnSubtract.Location = new System.Drawing.Point(90, 90);
            btnSubtract.Size = new System.Drawing.Size(60, 30);
            btnSubtract.Click += BtnSubtract_Click;
            this.Controls.Add(btnSubtract);

            btnMultiply = new Button();
            btnMultiply.Text = "*";
            btnMultiply.Location = new System.Drawing.Point(160, 90);
            btnMultiply.Size = new System.Drawing.Size(60, 30);
            btnMultiply.Click += BtnMultiply_Click;
            this.Controls.Add(btnMultiply);

            btnDivide = new Button();
            btnDivide.Text = "/";
            btnDivide.Location = new System.Drawing.Point(230, 90);
            btnDivide.Size = new System.Drawing.Size(60, 30);
            btnDivide.Click += BtnDivide_Click;
            this.Controls.Add(btnDivide);

            // Result Label
            lblResult = new Label();
            lblResult.Text = "Result: ";
            lblResult.Location = new System.Drawing.Point(20, 140);
            lblResult.Size = new System.Drawing.Size(300, 30);
            lblResult.Font = new System.Drawing.Font("Arial", 12, System.Drawing.FontStyle.Bold);
            this.Controls.Add(lblResult);
        }

        private void BtnAdd_Click(object sender, EventArgs e)
        {
            Calculate('+');
        }

        private void BtnSubtract_Click(object sender, EventArgs e)
        {
            Calculate('-');
        }

        private void BtnMultiply_Click(object sender, EventArgs e)
        {
            Calculate('*');
        }

        private void BtnDivide_Click(object sender, EventArgs e)
        {
            Calculate('/');
        }

        private void Calculate(char operation)
        {
            try
            {
                double num1 = double.Parse(txtNum1.Text);
                double num2 = double.Parse(txtNum2.Text);
                double result = 0;

                switch (operation)
                {
                    case '+': result = num1 + num2; break;
                    case '-': result = num1 - num2; break;
                    case '*': result = num1 * num2; break;
                    case '/':
                        if (num2 == 0)
                        {
                            MessageBox.Show("Cannot divide by zero!");
                            return;
                        }
                        result = num1 / num2;
                        break;
                }

                lblResult.Text = "Result: " + result.ToString();
            }
            catch
            {
                MessageBox.Show("Please enter valid numbers!");
            }
        }

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.Run(new Form1());
        }
    }
}
```

### Program: Student Registration Form

```csharp
using System;
using System.Windows.Forms;

namespace StudentRegistration
{
    public partial class Form1 : Form
    {
        // Controls: TextBox, ComboBox, RadioButton, CheckBox, DateTimePicker, Button
        private TextBox txtName;
        private ComboBox cmbCourse;
        private RadioButton rdMale;
        private RadioButton rdFemale;
        private CheckBox chkSports;
        private CheckBox chkMusic;
        private CheckBox chkArt;
        private DateTimePicker dtpBirthDate;
        private Button btnSubmit;

        public Form1()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            this.Text = "Student Registration Form";
            this.Size = new System.Drawing.Size(400, 450);

            // Name
            Label lblName = new Label();
            lblName.Text = "Student Name:";
            lblName.Location = new System.Drawing.Point(20, 20);
            lblName.Size = new System.Drawing.Size(100, 20);
            this.Controls.Add(lblName);

            txtName = new TextBox();
            txtName.Location = new System.Drawing.Point(130, 20);
            txtName.Size = new System.Drawing.Size(220, 20);
            this.Controls.Add(txtName);

            // Birth Date
            Label lblBirth = new Label();
            lblBirth.Text = "Birth Date:";
            lblBirth.Location = new System.Drawing.Point(20, 60);
            lblBirth.Size = new System.Drawing.Size(100, 20);
            this.Controls.Add(lblBirth);

            dtpBirthDate = new DateTimePicker();
            dtpBirthDate.Location = new System.Drawing.Point(130, 60);
            dtpBirthDate.Size = new System.Drawing.Size(220, 20);
            dtpBirthDate.Format = DateTimePickerFormat.Short;
            this.Controls.Add(dtpBirthDate);

            // Gender
            Label lblGender = new Label();
            lblGender.Text = "Gender:";
            lblGender.Location = new System.Drawing.Point(20, 100);
            lblGender.Size = new System.Drawing.Size(100, 20);
            this.Controls.Add(lblGender);

            rdMale = new RadioButton();
            rdMale.Text = "Male";
            rdMale.Location = new System.Drawing.Point(130, 100);
            rdMale.Size = new System.Drawing.Size(80, 20);
            rdMale.Checked = true;
            this.Controls.Add(rdMale);

            rdFemale = new RadioButton();
            rdFemale.Text = "Female";
            rdFemale.Location = new System.Drawing.Point(220, 100);
            rdFemale.Size = new System.Drawing.Size(80, 20);
            this.Controls.Add(rdFemale);

            // Course
            Label lblCourse = new Label();
            lblCourse.Text = "Course:";
            lblCourse.Location = new System.Drawing.Point(20, 140);
            lblCourse.Size = new System.Drawing.Size(100, 20);
            this.Controls.Add(lblCourse);

            cmbCourse = new ComboBox();
            cmbCourse.Location = new System.Drawing.Point(130, 140);
            cmbCourse.Size = new System.Drawing.Size(220, 20);
            cmbCourse.Items.Add("Computer Science");
            cmbCourse.Items.Add("Information Technology");
            cmbCourse.Items.Add("Electronics");
            cmbCourse.Items.Add("Mechanical");
            cmbCourse.Items.Add("Civil");
            cmbCourse.SelectedIndex = 0;
            this.Controls.Add(cmbCourse);

            // Hobbies
            Label lblHobbies = new Label();
            lblHobbies.Text = "Hobbies:";
            lblHobbies.Location = new System.Drawing.Point(20, 180);
            lblHobbies.Size = new System.Drawing.Size(100, 20);
            this.Controls.Add(lblHobbies);

            chkSports = new CheckBox();
            chkSports.Text = "Sports";
            chkSports.Location = new System.Drawing.Point(130, 180);
            chkSports.Size = new System.Drawing.Size(100, 20);
            this.Controls.Add(chkSports);

            chkMusic = new CheckBox();
            chkMusic.Text = "Music";
            chkMusic.Location = new System.Drawing.Point(130, 210);
            chkMusic.Size = new System.Drawing.Size(100, 20);
            this.Controls.Add(chkMusic);

            chkArt = new CheckBox();
            chkArt.Text = "Art";
            chkArt.Location = new System.Drawing.Point(130, 240);
            chkArt.Size = new System.Drawing.Size(100, 20);
            this.Controls.Add(chkArt);

            // Submit Button
            btnSubmit = new Button();
            btnSubmit.Text = "Submit Registration";
            btnSubmit.Location = new System.Drawing.Point(130, 290);
            btnSubmit.Size = new System.Drawing.Size(150, 35);
            btnSubmit.Click += BtnSubmit_Click;
            this.Controls.Add(btnSubmit);
        }

        private void BtnSubmit_Click(object sender, EventArgs e)
        {
            string name = txtName.Text;
            string birthDate = dtpBirthDate.Value.ToShortDateString();
            string gender = rdMale.Checked ? "Male" : "Female";
            string course = cmbCourse.SelectedItem.ToString();

            string hobbies = "";
            if (chkSports.Checked) hobbies += "Sports, ";
            if (chkMusic.Checked) hobbies += "Music, ";
            if (chkArt.Checked) hobbies += "Art, ";
            if (hobbies.Length > 0) hobbies = hobbies.Substring(0, hobbies.Length - 2);

            string message = "Registration Details:\n\n" +
                           "Name: " + name + "\n" +
                           "Birth Date: " + birthDate + "\n" +
                           "Gender: " + gender + "\n" +
                           "Course: " + course + "\n" +
                           "Hobbies: " + (hobbies.Length > 0 ? hobbies : "None");

            MessageBox.Show(message, "Registration Successful");
        }

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.Run(new Form1());
        }
    }
}
```

### Program: Image Viewer with Timer

```csharp
using System;
using System.Windows.Forms;

namespace ImageViewer
{
    public partial class Form1 : Form
    {
        // Controls: PictureBox, OpenFileDialog, Button, Timer, ProgressBar, Panel
        private PictureBox pictureBox;
        private OpenFileDialog openFileDialog;
        private Button btnOpen;
        private Button btnStartSlideshow;
        private Button btnStop;
        private Timer timer;
        private ProgressBar progressBar;
        private Panel panel;
        private Label lblStatus;
        private int imageCount = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            this.Text = "Image Viewer";
            this.Size = new System.Drawing.Size(700, 550);

            // Panel for controls
            panel = new Panel();
            panel.Location = new System.Drawing.Point(10, 10);
            panel.Size = new System.Drawing.Size(660, 60);
            panel.BorderStyle = BorderStyle.FixedSingle;
            this.Controls.Add(panel);

            // Open Button
            btnOpen = new Button();
            btnOpen.Text = "Open Image";
            btnOpen.Location = new System.Drawing.Point(10, 15);
            btnOpen.Size = new System.Drawing.Size(100, 30);
            btnOpen.Click += BtnOpen_Click;
            panel.Controls.Add(btnOpen);

            // Start Slideshow Button
            btnStartSlideshow = new Button();
            btnStartSlideshow.Text = "Start Timer (5s)";
            btnStartSlideshow.Location = new System.Drawing.Point(120, 15);
            btnStartSlideshow.Size = new System.Drawing.Size(120, 30);
            btnStartSlideshow.Click += BtnStartSlideshow_Click;
            panel.Controls.Add(btnStartSlideshow);

            // Stop Button
            btnStop = new Button();
            btnStop.Text = "Stop Timer";
            btnStop.Location = new System.Drawing.Point(250, 15);
            btnStop.Size = new System.Drawing.Size(100, 30);
            btnStop.Enabled = false;
            btnStop.Click += BtnStop_Click;
            panel.Controls.Add(btnStop);

            // Status Label
            lblStatus = new Label();
            lblStatus.Text = "Status: Ready";
            lblStatus.Location = new System.Drawing.Point(370, 20);
            lblStatus.Size = new System.Drawing.Size(280, 20);
            panel.Controls.Add(lblStatus);

            // PictureBox
            pictureBox = new PictureBox();
            pictureBox.Location = new System.Drawing.Point(10, 80);
            pictureBox.Size = new System.Drawing.Size(660, 380);
            pictureBox.BorderStyle = BorderStyle.FixedSingle;
            pictureBox.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox.BackColor = System.Drawing.Color.LightGray;
            this.Controls.Add(pictureBox);

            // ProgressBar
            progressBar = new ProgressBar();
            progressBar.Location = new System.Drawing.Point(10, 470);
            progressBar.Size = new System.Drawing.Size(660, 25);
            progressBar.Minimum = 0;
            progressBar.Maximum = 50; // 5 seconds = 50 * 100ms
            this.Controls.Add(progressBar);

            // OpenFileDialog
            openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.gif;*.bmp";
            openFileDialog.Title = "Select an Image";

            // Timer
            timer = new Timer();
            timer.Interval = 100; // 100ms
            timer.Tick += Timer_Tick;
        }

        private void BtnOpen_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    pictureBox.Image = System.Drawing.Image.FromFile(openFileDialog.FileName);
                    lblStatus.Text = "Status: Image loaded - " +
                                   System.IO.Path.GetFileName(openFileDialog.FileName);
                    imageCount++;
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error loading image: " + ex.Message);
                }
            }
        }

        private void BtnStartSlideshow_Click(object sender, EventArgs e)
        {
            if (pictureBox.Image != null)
            {
                timer.Start();
                progressBar.Value = 0;
                btnStartSlideshow.Enabled = false;
                btnStop.Enabled = true;
                lblStatus.Text = "Status: Timer running...";
            }
            else
            {
                MessageBox.Show("Please load an image first!");
            }
        }

        private void BtnStop_Click(object sender, EventArgs e)
        {
            timer.Stop();
            progressBar.Value = 0;
            btnStartSlideshow.Enabled = true;
            btnStop.Enabled = false;
            lblStatus.Text = "Status: Timer stopped";
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if (progressBar.Value < progressBar.Maximum)
            {
                progressBar.Value++;
            }
            else
            {
                timer.Stop();
                MessageBox.Show("Timer completed! 5 seconds elapsed.", "Timer Alert");
                progressBar.Value = 0;
                btnStartSlideshow.Enabled = true;
                btnStop.Enabled = false;
                lblStatus.Text = "Status: Timer completed";
            }
        }

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.Run(new Form1());
        }
    }
}
```

### Program: To-Do List Manager

```csharp
using System;
using System.Windows.Forms;

namespace ToDoList
{
    public partial class Form1 : Form
    {
        // Controls: ListBox, TextBox, Button, Label
        private TextBox txtTask;
        private ListBox lstTasks;
        private Button btnAdd;
        private Button btnRemove;
        private Button btnClear;
        private Label lblCount;

        public Form1()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            this.Text = "To-Do List Manager";
            this.Size = new System.Drawing.Size(450, 400);

            // Title Label
            Label lblTitle = new Label();
            lblTitle.Text = "My To-Do List";
            lblTitle.Location = new System.Drawing.Point(20, 15);
            lblTitle.Size = new System.Drawing.Size(200, 25);
            lblTitle.Font = new System.Drawing.Font("Arial", 14, System.Drawing.FontStyle.Bold);
            this.Controls.Add(lblTitle);

            // Task TextBox
            Label lblTask = new Label();
            lblTask.Text = "Enter Task:";
            lblTask.Location = new System.Drawing.Point(20, 50);
            lblTask.Size = new System.Drawing.Size(80, 20);
            this.Controls.Add(lblTask);

            txtTask = new TextBox();
            txtTask.Location = new System.Drawing.Point(110, 50);
            txtTask.Size = new System.Drawing.Size(250, 20);
            this.Controls.Add(txtTask);

            // Add Button
            btnAdd = new Button();
            btnAdd.Text = "Add Task";
            btnAdd.Location = new System.Drawing.Point(370, 48);
            btnAdd.Size = new System.Drawing.Size(60, 25);
            btnAdd.Click += BtnAdd_Click;
            this.Controls.Add(btnAdd);

            // ListBox
            Label lblTasks = new Label();
            lblTasks.Text = "Tasks:";
            lblTasks.Location = new System.Drawing.Point(20, 90);
            lblTasks.Size = new System.Drawing.Size(80, 20);
            this.Controls.Add(lblTasks);

            lstTasks = new ListBox();
            lstTasks.Location = new System.Drawing.Point(20, 115);
            lstTasks.Size = new System.Drawing.Size(410, 160);
            this.Controls.Add(lstTasks);

            // Remove Button
            btnRemove = new Button();
            btnRemove.Text = "Remove Selected";
            btnRemove.Location = new System.Drawing.Point(20, 285);
            btnRemove.Size = new System.Drawing.Size(120, 30);
            btnRemove.Click += BtnRemove_Click;
            this.Controls.Add(btnRemove);

            // Clear All Button
            btnClear = new Button();
            btnClear.Text = "Clear All";
            btnClear.Location = new System.Drawing.Point(150, 285);
            btnClear.Size = new System.Drawing.Size(100, 30);
            btnClear.Click += BtnClear_Click;
            this.Controls.Add(btnClear);

            // Count Label
            lblCount = new Label();
            lblCount.Text = "Total Tasks: 0";
            lblCount.Location = new System.Drawing.Point(20, 325);
            lblCount.Size = new System.Drawing.Size(150, 20);
            lblCount.Font = new System.Drawing.Font("Arial", 10, System.Drawing.FontStyle.Bold);
            this.Controls.Add(lblCount);
        }

        private void BtnAdd_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrWhiteSpace(txtTask.Text))
            {
                lstTasks.Items.Add(txtTask.Text);
                txtTask.Clear();
                UpdateCount();
                txtTask.Focus();
            }
            else
            {
                MessageBox.Show("Please enter a task!", "Warning");
            }
        }

        private void BtnRemove_Click(object sender, EventArgs e)
        {
            if (lstTasks.SelectedIndex != -1)
            {
                lstTasks.Items.RemoveAt(lstTasks.SelectedIndex);
                UpdateCount();
            }
            else
            {
                MessageBox.Show("Please select a task to remove!", "Warning");
            }
        }

        private void BtnClear_Click(object sender, EventArgs e)
        {
            if (lstTasks.Items.Count > 0)
            {
                DialogResult result = MessageBox.Show("Are you sure you want to clear all tasks?",
                                                     "Confirm", MessageBoxButtons.YesNo);
                if (result == DialogResult.Yes)
                {
                    lstTasks.Items.Clear();
                    UpdateCount();
                }
            }
        }

        private void UpdateCount()
        {
            lblCount.Text = "Total Tasks: " + lstTasks.Items.Count;
        }

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.Run(new Form1());
        }
    }
}
```

---

# ADO.NET Programming Assignment

## Unit 5: ADO.NET - 5 Simple Programs

This assignment contains 5 programs covering ADO.NET fundamentals with simple, easy-to-understand examples.

---

## Prerequisites
- Visual Studio (any recent version)
- SQL Server or SQL Server Express
- Basic C# and Windows Forms knowledge

---

## Database Setup

Before running these programs, create a database named `StudentDB` and run this SQL script:

```sql
CREATE DATABASE StudentDB;
GO

USE StudentDB;
GO

CREATE TABLE Students (
    StudentID INT PRIMARY KEY IDENTITY(1,1),
    Name NVARCHAR(100),
    Age INT,
    Course NVARCHAR(50),
    Email NVARCHAR(100)
);
GO

INSERT INTO Students (Name, Age, Course, Email) VALUES
('John Doe', 20, 'Computer Science', 'john@email.com'),
('Jane Smith', 22, 'Information Technology', 'jane@email.com'),
('Mike Johnson', 21, 'Electronics', 'mike@email.com');
GO
```

**Connection String**: Update the connection string in each program:
```csharp
string connectionString = @"Data Source=(LocalDB)\MSSQLLocalDB;Initial Catalog=StudentDB;Integrated Security=True";
```

---

## Program 1: Basic Database Connection

**Question**: Write a program to establish a connection to SQL Server database and display connection status.

**Concepts Covered**:
- Introduction to ADO.NET
- SqlConnection class
- Opening and closing connections

**Code**: `Program1_BasicConnection.cs`

```csharp
using System;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace AdonetPrograms
{
    public partial class Program1_BasicConnection : Form
    {
        public Program1_BasicConnection()
        {
            InitializeComponent();
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            string connectionString = @"Data Source=(LocalDB)\MSSQLLocalDB;Initial Catalog=StudentDB;Integrated Security=True";

            SqlConnection connection = null;

            try
            {
                // Create connection object
                connection = new SqlConnection(connectionString);

                // Open the connection
                connection.Open();

                // Check connection state
                if (connection.State == System.Data.ConnectionState.Open)
                {
                    MessageBox.Show("Database Connected Successfully!",
                                    "Success",
                                    MessageBoxButtons.OK,
                                    MessageBoxIcon.Information);

                    lblStatus.Text = "Status: Connected";
                    lblStatus.ForeColor = System.Drawing.Color.Green;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message,
                                "Connection Failed",
                                MessageBoxButtons.OK,
                                MessageBoxIcon.Error);

                lblStatus.Text = "Status: Connection Failed";
                lblStatus.ForeColor = System.Drawing.Color.Red;
            }
            finally
            {
                // Always close the connection
                if (connection != null && connection.State == System.Data.ConnectionState.Open)
                {
                    connection.Close();
                    lblStatus.Text += " (Closed)";
                }
            }
        }
    }
}
```

**Form Design**:
- 1 Button (btnConnect) - "Connect to Database"
- 1 Label (lblStatus) - Display connection status

---

## Program 2: Insert Data using Command Object

**Question**: Write a program to insert a new student record into the database using SqlCommand.

**Concepts Covered**:
- SqlCommand class
- ExecuteNonQuery() method
- Parameterized queries

**Code**: `Program2_InsertData.cs`

```csharp
using System;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace AdonetPrograms
{
    public partial class Program2_InsertData : Form
    {
        string connectionString = @"Data Source=(LocalDB)\MSSQLLocalDB;Initial Catalog=StudentDB;Integrated Security=True";

        public Program2_InsertData()
        {
            InitializeComponent();
        }

        private void btnInsert_Click(object sender, EventArgs e)
        {
            // Validate input
            if (string.IsNullOrWhiteSpace(txtName.Text))
            {
                MessageBox.Show("Please enter student name!", "Validation Error");
                return;
            }

            SqlConnection connection = null;
            SqlCommand command = null;

            try
            {
                // Create connection
                connection = new SqlConnection(connectionString);

                // SQL Insert query with parameters
                string query = "INSERT INTO Students (Name, Age, Course, Email) VALUES (@Name, @Age, @Course, @Email)";

                // Create command object
                command = new SqlCommand(query, connection);

                // Add parameters to prevent SQL injection
                command.Parameters.AddWithValue("@Name", txtName.Text);
                command.Parameters.AddWithValue("@Age", int.Parse(txtAge.Text));
                command.Parameters.AddWithValue("@Course", txtCourse.Text);
                command.Parameters.AddWithValue("@Email", txtEmail.Text);

                // Open connection
                connection.Open();

                // Execute the command
                int rowsAffected = command.ExecuteNonQuery();

                if (rowsAffected > 0)
                {
                    MessageBox.Show("Student record inserted successfully!",
                                    "Success",
                                    MessageBoxButtons.OK,
                                    MessageBoxIcon.Information);

                    // Clear textboxes
                    ClearFields();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                if (connection != null)
                    connection.Close();
            }
        }

        private void ClearFields()
        {
            txtName.Clear();
            txtAge.Clear();
            txtCourse.Clear();
            txtEmail.Clear();
            txtName.Focus();
        }
    }
}
```

**Form Design**:
- 4 TextBoxes: txtName, txtAge, txtCourse, txtEmail
- 1 Button: btnInsert - "Insert Student"
- Labels for each field

---

## Program 3: Retrieve Data using DataReader

**Question**: Write a program to display all student records using SqlDataReader.

**Concepts Covered**:
- SqlDataReader class
- ExecuteReader() method
- Reading data row by row

**Code**: `Program3_DataReader.cs`

```csharp
using System;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace AdonetPrograms
{
    public partial class Program3_DataReader : Form
    {
        string connectionString = @"Data Source=(LocalDB)\MSSQLLocalDB;Initial Catalog=StudentDB;Integrated Security=True";

        public Program3_DataReader()
        {
            InitializeComponent();
        }

        private void btnLoadData_Click(object sender, EventArgs e)
        {
            SqlConnection connection = null;
            SqlCommand command = null;
            SqlDataReader reader = null;

            try
            {
                // Create connection
                connection = new SqlConnection(connectionString);

                // SQL Select query
                string query = "SELECT StudentID, Name, Age, Course, Email FROM Students";

                // Create command
                command = new SqlCommand(query, connection);

                // Open connection
                connection.Open();

                // Execute reader
                reader = command.ExecuteReader();

                // Clear existing text
                txtDisplay.Clear();
                txtDisplay.AppendText("===== STUDENT RECORDS =====\r\n\r\n");

                // Read data row by row
                while (reader.Read())
                {
                    txtDisplay.AppendText("Student ID: " + reader["StudentID"].ToString() + "\r\n");
                    txtDisplay.AppendText("Name: " + reader["Name"].ToString() + "\r\n");
                    txtDisplay.AppendText("Age: " + reader["Age"].ToString() + "\r\n");
                    txtDisplay.AppendText("Course: " + reader["Course"].ToString() + "\r\n");
                    txtDisplay.AppendText("Email: " + reader["Email"].ToString() + "\r\n");
                    txtDisplay.AppendText("---------------------------\r\n\r\n");
                }

                if (!reader.HasRows)
                {
                    txtDisplay.AppendText("No records found!");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                if (reader != null)
                    reader.Close();
                if (connection != null)
                    connection.Close();
            }
        }
    }
}
```

**Form Design**:
- 1 Button: btnLoadData - "Load Students"
- 1 TextBox: txtDisplay (Multiline, ReadOnly, ScrollBars)

---

## Program 4: Using DataAdapter and DataSet

**Question**: Write a program to fill a DataSet using DataAdapter and display records.

**Concepts Covered**:
- SqlDataAdapter class
- DataSet and DataTable
- Fill() method

**Code**: `Program4_DataAdapter.cs`

```csharp
using System;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace AdonetPrograms
{
    public partial class Program4_DataAdapter : Form
    {
        string connectionString = @"Data Source=(LocalDB)\MSSQLLocalDB;Initial Catalog=StudentDB;Integrated Security=True";

        public Program4_DataAdapter()
        {
            InitializeComponent();
        }

        private void btnFillDataSet_Click(object sender, EventArgs e)
        {
            SqlConnection connection = null;
            SqlDataAdapter adapter = null;

            try
            {
                // Create connection
                connection = new SqlConnection(connectionString);

                // SQL query
                string query = "SELECT StudentID, Name, Age, Course, Email FROM Students";

                // Create DataAdapter
                adapter = new SqlDataAdapter(query, connection);

                // Create DataSet
                DataSet dataSet = new DataSet();

                // Fill DataSet (connection opens and closes automatically)
                adapter.Fill(dataSet, "Students");

                // Get DataTable from DataSet
                DataTable dataTable = dataSet.Tables["Students"];

                // Display data
                txtDisplay.Clear();
                txtDisplay.AppendText("===== DATASET CONTENTS =====\r\n\r\n");
                txtDisplay.AppendText("Total Records: " + dataTable.Rows.Count + "\r\n\r\n");

                // Loop through rows
                foreach (DataRow row in dataTable.Rows)
                {
                    txtDisplay.AppendText("Student ID: " + row["StudentID"].ToString() + "\r\n");
                    txtDisplay.AppendText("Name: " + row["Name"].ToString() + "\r\n");
                    txtDisplay.AppendText("Age: " + row["Age"].ToString() + "\r\n");
                    txtDisplay.AppendText("Course: " + row["Course"].ToString() + "\r\n");
                    txtDisplay.AppendText("Email: " + row["Email"].ToString() + "\r\n");
                    txtDisplay.AppendText("---------------------------\r\n\r\n");
                }

                MessageBox.Show("DataSet filled successfully!", "Success");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
```

**Form Design**:
- 1 Button: btnFillDataSet - "Fill DataSet"
- 1 TextBox: txtDisplay (Multiline, ReadOnly, ScrollBars)

---

## Program 5: DataGridView with Database

**Question**: Write a program to connect a database with Windows Application using DataGridView control to display and manage student records.

**Concepts Covered**:
- DataGridView control
- Binding data to DataGridView
- Complete CRUD operations

**Code**: `Program5_DataGridView.cs`

```csharp
using System;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace AdonetPrograms
{
    public partial class Program5_DataGridView : Form
    {
        string connectionString = @"Data Source=(LocalDB)\MSSQLLocalDB;Initial Catalog=StudentDB;Integrated Security=True";
        SqlDataAdapter adapter;
        DataTable dataTable;

        public Program5_DataGridView()
        {
            InitializeComponent();
        }

        private void Form_Load(object sender, EventArgs e)
        {
            LoadData();
        }

        private void LoadData()
        {
            try
            {
                SqlConnection connection = new SqlConnection(connectionString);

                // SQL query
                string query = "SELECT StudentID, Name, Age, Course, Email FROM Students";

                // Create DataAdapter
                adapter = new SqlDataAdapter(query, connection);

                // Create DataTable
                dataTable = new DataTable();

                // Fill DataTable
                adapter.Fill(dataTable);

                // Bind to DataGridView
                dataGridView1.DataSource = dataTable;

                // Format DataGridView
                dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
                dataGridView1.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

                lblRecordCount.Text = "Total Records: " + dataTable.Rows.Count;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnRefresh_Click(object sender, EventArgs e)
        {
            LoadData();
            MessageBox.Show("Data refreshed successfully!", "Success");
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrWhiteSpace(txtSearch.Text))
                {
                    dataTable.DefaultView.RowFilter = "";
                }
                else
                {
                    // Filter data
                    dataTable.DefaultView.RowFilter = string.Format("Name LIKE '%{0}%'", txtSearch.Text);
                }

                lblRecordCount.Text = "Total Records: " + dataTable.DefaultView.Count;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (dataGridView1.SelectedRows.Count == 0)
                {
                    MessageBox.Show("Please select a row to delete!", "Warning");
                    return;
                }

                DialogResult result = MessageBox.Show("Are you sure you want to delete this record?",
                                                      "Confirm Delete",
                                                      MessageBoxButtons.YesNo,
                                                      MessageBoxIcon.Question);

                if (result == DialogResult.Yes)
                {
                    int studentID = Convert.ToInt32(dataGridView1.SelectedRows[0].Cells["StudentID"].Value);

                    SqlConnection connection = new SqlConnection(connectionString);
                    string query = "DELETE FROM Students WHERE StudentID = @StudentID";
                    SqlCommand command = new SqlCommand(query, connection);
                    command.Parameters.AddWithValue("@StudentID", studentID);

                    connection.Open();
                    command.ExecuteNonQuery();
                    connection.Close();

                    MessageBox.Show("Record deleted successfully!", "Success");
                    LoadData();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
```

**Form Design**:
- 1 DataGridView: dataGridView1
- 3 Buttons: btnRefresh ("Refresh"), btnSearch ("Search"), btnDelete ("Delete Selected")
- 1 TextBox: txtSearch - for searching
- 1 Label: lblRecordCount - to show record count

---

## Summary of Programs

| Program | Topic | Key Classes Used |
|---------|-------|------------------|
| 1 | Basic Connection | SqlConnection |
| 2 | Insert Data | SqlConnection, SqlCommand |
| 3 | Read Data | SqlConnection, SqlCommand, SqlDataReader |
| 4 | DataAdapter & DataSet | SqlDataAdapter, DataSet, DataTable |
| 5 | DataGridView | SqlDataAdapter, DataTable, DataGridView |

---

## Important Notes

1. **Connection String**: Update the connection string according to your SQL Server instance
2. **Error Handling**: All programs include try-catch blocks for proper error handling
3. **Resource Cleanup**: Connections are properly closed in finally blocks
4. **SQL Injection**: Parameterized queries are used to prevent SQL injection attacks
5. **DataGridView**: Program 5 demonstrates binding data to UI controls

---

# Quick Reference - Short Programs

These are simple, exam-friendly programs covering key concepts from each unit.

---

## Unit 1: .NET Framework Basics

### Program: Display CLR Version

```csharp
using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("CLR Version: " + Environment.Version);
        Console.WriteLine("OS Version: " + Environment.OSVersion);
        Console.WriteLine(".NET Runtime: " + Environment.Version.Major);
    }
}
```

---

## Unit 2: C# Fundamentals - Short Programs

### Program: Data Types Demo

```csharp
using System;

class Program
{
    static void Main()
    {
        int age = 21;
        float marks = 85.5f;
        char grade = 'A';
        bool pass = true;
        string name = "Rahul";

        Console.WriteLine($"Name: {name}, Age: {age}");
        Console.WriteLine($"Marks: {marks}, Grade: {grade}, Pass: {pass}");
    }
}
```

### Program: Arithmetic Operators

```csharp
using System;

class Program
{
    static void Main()
    {
        int a = 10, b = 3;

        Console.WriteLine($"Addition: {a + b}");
        Console.WriteLine($"Subtraction: {a - b}");
        Console.WriteLine($"Multiplication: {a * b}");
        Console.WriteLine($"Division: {a / b}");
        Console.WriteLine($"Modulus: {a % b}");
    }
}
```

### Program: If-Else Statement

```csharp
using System;

class Program
{
    static void Main()
    {
        int marks = 75;

        if (marks >= 40)
            Console.WriteLine("Result: Pass");
        else
            Console.WriteLine("Result: Fail");
    }
}
```

### Program: Switch Statement

```csharp
using System;

class Program
{
    static void Main()
    {
        int day = 3;

        switch (day)
        {
            case 1: Console.WriteLine("Monday"); break;
            case 2: Console.WriteLine("Tuesday"); break;
            case 3: Console.WriteLine("Wednesday"); break;
            default: Console.WriteLine("Other day"); break;
        }
    }
}
```

### Program: For Loop

```csharp
using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Numbers 1 to 5:");
        for (int i = 1; i <= 5; i++)
        {
            Console.Write(i + " ");
        }
    }
}
```

### Program: While Loop

```csharp
using System;

class Program
{
    static void Main()
    {
        int i = 1;
        while (i <= 5)
        {
            Console.WriteLine($"Count: {i}");
            i++;
        }
    }
}
```

### Program: Array Example

```csharp
using System;

class Program
{
    static void Main()
    {
        int[] numbers = { 10, 20, 30, 40, 50 };

        foreach (int num in numbers)
        {
            Console.WriteLine(num);
        }
    }
}
```

---

## Unit 3: .NET Assemblies

### Program: Assembly Information

```csharp
using System;
using System.Reflection;

class Program
{
    static void Main()
    {
        Assembly asm = Assembly.GetExecutingAssembly();

        Console.WriteLine("Assembly Name: " + asm.GetName().Name);
        Console.WriteLine("Version: " + asm.GetName().Version);
        Console.WriteLine("Location: " + asm.Location);
    }
}
```

---

## Unit 4: Windows Forms - Short Programs

### Program: Simple Message Box

```csharp
using System;
using System.Windows.Forms;

class Program
{
    [STAThread]
    static void Main()
    {
        MessageBox.Show("Hello, Welcome to C#!", "Greeting");
    }
}
```

### Program: Button Click Event

```csharp
using System;
using System.Windows.Forms;

class MyForm : Form
{
    Button btn;

    public MyForm()
    {
        btn = new Button();
        btn.Text = "Click Me";
        btn.Location = new System.Drawing.Point(50, 50);
        btn.Click += Btn_Click;
        this.Controls.Add(btn);
    }

    void Btn_Click(object sender, EventArgs e)
    {
        MessageBox.Show("Button Clicked!");
    }

    [STAThread]
    static void Main()
    {
        Application.Run(new MyForm());
    }
}
```

### Program: TextBox Input

```csharp
using System;
using System.Windows.Forms;

class MyForm : Form
{
    TextBox txt;
    Button btn;

    public MyForm()
    {
        txt = new TextBox();
        txt.Location = new System.Drawing.Point(20, 20);
        this.Controls.Add(txt);

        btn = new Button();
        btn.Text = "Show";
        btn.Location = new System.Drawing.Point(20, 50);
        btn.Click += (s, e) => MessageBox.Show("You typed: " + txt.Text);
        this.Controls.Add(btn);
    }

    [STAThread]
    static void Main()
    {
        Application.Run(new MyForm());
    }
}
```

### Program: CheckBox Example

```csharp
using System;
using System.Windows.Forms;

class MyForm : Form
{
    CheckBox chk;
    Button btn;

    public MyForm()
    {
        chk = new CheckBox();
        chk.Text = "I agree to terms";
        chk.Location = new System.Drawing.Point(20, 20);
        this.Controls.Add(chk);

        btn = new Button();
        btn.Text = "Submit";
        btn.Location = new System.Drawing.Point(20, 50);
        btn.Click += (s, e) =>
        {
            if (chk.Checked)
                MessageBox.Show("Thank you!");
            else
                MessageBox.Show("Please accept terms!");
        };
        this.Controls.Add(btn);
    }

    [STAThread]
    static void Main()
    {
        Application.Run(new MyForm());
    }
}
```

### Program: RadioButton Example

```csharp
using System;
using System.Windows.Forms;

class MyForm : Form
{
    RadioButton rdMale, rdFemale;
    Button btn;

    public MyForm()
    {
        rdMale = new RadioButton();
        rdMale.Text = "Male";
        rdMale.Location = new System.Drawing.Point(20, 20);
        this.Controls.Add(rdMale);

        rdFemale = new RadioButton();
        rdFemale.Text = "Female";
        rdFemale.Location = new System.Drawing.Point(20, 50);
        this.Controls.Add(rdFemale);

        btn = new Button();
        btn.Text = "Show Gender";
        btn.Location = new System.Drawing.Point(20, 80);
        btn.Click += (s, e) =>
        {
            string gender = rdMale.Checked ? "Male" : "Female";
            MessageBox.Show("Gender: " + gender);
        };
        this.Controls.Add(btn);
    }

    [STAThread]
    static void Main()
    {
        Application.Run(new MyForm());
    }
}
```

### Program: ComboBox Example

```csharp
using System;
using System.Windows.Forms;

class MyForm : Form
{
    ComboBox cmb;
    Button btn;

    public MyForm()
    {
        cmb = new ComboBox();
        cmb.Items.AddRange(new string[] { "BCA", "BBA", "BSc" });
        cmb.Location = new System.Drawing.Point(20, 20);
        this.Controls.Add(cmb);

        btn = new Button();
        btn.Text = "Select";
        btn.Location = new System.Drawing.Point(20, 50);
        btn.Click += (s, e) => MessageBox.Show("Course: " + cmb.Text);
        this.Controls.Add(btn);
    }

    [STAThread]
    static void Main()
    {
        Application.Run(new MyForm());
    }
}
```

### Program: ListBox Example

```csharp
using System;
using System.Windows.Forms;

class MyForm : Form
{
    ListBox lst;
    Button btn;

    public MyForm()
    {
        lst = new ListBox();
        lst.Items.AddRange(new string[] { "C#", "Java", "Python" });
        lst.Location = new System.Drawing.Point(20, 20);
        lst.Size = new System.Drawing.Size(100, 60);
        this.Controls.Add(lst);

        btn = new Button();
        btn.Text = "Select";
        btn.Location = new System.Drawing.Point(20, 90);
        btn.Click += (s, e) =>
        {
            if (lst.SelectedItem != null)
                MessageBox.Show("Selected: " + lst.SelectedItem);
        };
        this.Controls.Add(btn);
    }

    [STAThread]
    static void Main()
    {
        Application.Run(new MyForm());
    }
}
```

### Program: DateTimePicker Example

```csharp
using System;
using System.Windows.Forms;

class MyForm : Form
{
    DateTimePicker dtp;
    Button btn;

    public MyForm()
    {
        dtp = new DateTimePicker();
        dtp.Location = new System.Drawing.Point(20, 20);
        this.Controls.Add(dtp);

        btn = new Button();
        btn.Text = "Show Date";
        btn.Location = new System.Drawing.Point(20, 50);
        btn.Click += (s, e) => MessageBox.Show("Date: " + dtp.Value.ToShortDateString());
        this.Controls.Add(btn);
    }

    [STAThread]
    static void Main()
    {
        Application.Run(new MyForm());
    }
}
```

### Program: Timer Example

```csharp
using System;
using System.Windows.Forms;

class MyForm : Form
{
    Label lbl;
    Timer timer;
    int count = 0;

    public MyForm()
    {
        lbl = new Label();
        lbl.Text = "0";
        lbl.Location = new System.Drawing.Point(50, 50);
        this.Controls.Add(lbl);

        timer = new Timer();
        timer.Interval = 1000;
        timer.Tick += (s, e) => { count++; lbl.Text = count.ToString(); };
        timer.Start();
    }

    [STAThread]
    static void Main()
    {
        Application.Run(new MyForm());
    }
}
```

### Program: ProgressBar Example

```csharp
using System;
using System.Windows.Forms;

class MyForm : Form
{
    ProgressBar pb;
    Button btn;

    public MyForm()
    {
        pb = new ProgressBar();
        pb.Location = new System.Drawing.Point(20, 20);
        pb.Maximum = 100;
        this.Controls.Add(pb);

        btn = new Button();
        btn.Text = "Load";
        btn.Location = new System.Drawing.Point(20, 50);
        btn.Click += (s, e) => { pb.Value = 75; };
        this.Controls.Add(btn);
    }

    [STAThread]
    static void Main()
    {
        Application.Run(new MyForm());
    }
}
```

### Program: OpenFileDialog Example

```csharp
using System;
using System.Windows.Forms;

class MyForm : Form
{
    Button btn;
    Label lbl;

    public MyForm()
    {
        btn = new Button();
        btn.Text = "Open File";
        btn.Location = new System.Drawing.Point(20, 20);
        btn.Click += Btn_Click;
        this.Controls.Add(btn);

        lbl = new Label();
        lbl.Location = new System.Drawing.Point(20, 60);
        lbl.Size = new System.Drawing.Size(300, 20);
        this.Controls.Add(lbl);
    }

    void Btn_Click(object sender, EventArgs e)
    {
        OpenFileDialog ofd = new OpenFileDialog();
        if (ofd.ShowDialog() == DialogResult.OK)
        {
            lbl.Text = ofd.FileName;
        }
    }

    [STAThread]
    static void Main()
    {
        Application.Run(new MyForm());
    }
}
```

### Program: SaveFileDialog Example

```csharp
using System;
using System.Windows.Forms;

class MyForm : Form
{
    Button btn;

    public MyForm()
    {
        btn = new Button();
        btn.Text = "Save File";
        btn.Location = new System.Drawing.Point(20, 20);
        btn.Click += (s, e) =>
        {
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Filter = "Text Files|*.txt";
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                MessageBox.Show("Saved to: " + sfd.FileName);
            }
        };
        this.Controls.Add(btn);
    }

    [STAThread]
    static void Main()
    {
        Application.Run(new MyForm());
    }
}
```

---

## Unit 5: ADO.NET - Short Programs

### Program: Simple Database Connection

```csharp
using System;
using System.Data.SqlClient;

class Program
{
    static void Main()
    {
        string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;Initial Catalog=TestDB;Integrated Security=True";

        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        Console.WriteLine("Connected Successfully!");
        conn.Close();
    }
}
```

### Program: Execute SQL Command

```csharp
using System;
using System.Data.SqlClient;

class Program
{
    static void Main()
    {
        string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;Initial Catalog=TestDB;Integrated Security=True";

        using (SqlConnection conn = new SqlConnection(connStr))
        {
            conn.Open();
            SqlCommand cmd = new SqlCommand("INSERT INTO Students(Name) VALUES('John')", conn);
            int rows = cmd.ExecuteNonQuery();
            Console.WriteLine($"Rows affected: {rows}");
        }
    }
}
```

### Program: Read Data with DataReader

```csharp
using System;
using System.Data.SqlClient;

class Program
{
    static void Main()
    {
        string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;Initial Catalog=TestDB;Integrated Security=True";

        using (SqlConnection conn = new SqlConnection(connStr))
        {
            conn.Open();
            SqlCommand cmd = new SqlCommand("SELECT * FROM Students", conn);
            SqlDataReader reader = cmd.ExecuteReader();

            while (reader.Read())
            {
                Console.WriteLine(reader["Name"].ToString());
            }
        }
    }
}
```

### Program: DataAdapter and DataSet

```csharp
using System;
using System.Data;
using System.Data.SqlClient;

class Program
{
    static void Main()
    {
        string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;Initial Catalog=TestDB;Integrated Security=True";

        SqlDataAdapter adapter = new SqlDataAdapter("SELECT * FROM Students", connStr);
        DataSet ds = new DataSet();
        adapter.Fill(ds, "Students");

        foreach (DataRow row in ds.Tables["Students"].Rows)
        {
            Console.WriteLine(row["Name"]);
        }
    }
}
```

---

## Summary Table - Short Programs

| Unit | Topic | Programs Count |
|------|-------|----------------|
| 1 | .NET Framework | 1 |
| 2 | C# Fundamentals | 7 |
| 3 | Assemblies | 1 |
| 4 | Windows Forms | 12 |
| 5 | ADO.NET | 4 |

**Total Short Programs: 25**

---
