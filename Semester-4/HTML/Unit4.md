# UNIT 4: Data Access & Error Handling - Complete Notes

## 1. Introduction to PHP

**PHP (Hypertext Preprocessor)** is a server-side scripting language designed for web development. It's embedded in HTML and executed on the server.

### What is PHP?

- **PHP** = **P**HP: **H**ypertext **P**reprocessor (recursive acronym)
- Server-side scripting language
- Open source and free
- Runs on web server (Apache, Nginx, IIS)
- Generates dynamic web pages
- File extension: **.php**
- Created by Rasmus Lerdorf in 1994

### Why We Use PHP?

**1. Dynamic Web Pages**
- Generate content based on user input
- Display different content for different users
- Update content without changing HTML

**2. Database Integration**
- Connect to databases (MySQL, PostgreSQL, Oracle)
- Perform CRUD operations (Create, Read, Update, Delete)
- Manage user data, products, orders, etc.

**3. Form Processing**
- Collect and validate user input
- Process registration, login, contact forms
- Handle file uploads

**4. Session Management**
- Track user login status
- Maintain shopping carts
- Store user preferences

**5. Server-Side Operations**
- Send emails
- Generate PDFs, images
- Access files on server
- Perform calculations

**6. Cross-Platform**
- Runs on Windows, Linux, Mac
- Works with all major web servers
- Platform independent

**7. Cost-Effective**
- Free and open source
- No licensing fees
- Large community support

---

## 2. Features of PHP

### Basic Features:

**1. Simple and Easy to Learn**
- Easy syntax similar to C
- Quick learning curve
- Good for beginners

**2. Open Source**
- Free to download and use
- Large community support
- Regular updates

**3. Platform Independent**
- Runs on Windows, Linux, Unix, Mac
- Write once, run anywhere

**4. Server-Side Scripting**
- Executes on server, not client
- More secure than client-side
- Users cannot see source code

**5. Fast Performance**
- Uses its own memory
- Reduces server load
- Quick execution time

**6. Database Support**
- MySQL (most common)
- PostgreSQL
- Oracle
- MongoDB
- SQLite
- MS SQL Server

**7. Embedded in HTML**
```php
<html>
<body>
    <h1>Welcome <?php echo "User"; ?></h1>
</body>
</html>
```

**8. Cross-Platform Database Support**
- Works with multiple databases
- Database abstraction layers available

**9. Error Reporting**
- Built-in error handling
- Multiple error reporting levels
- Custom error handlers

**10. Rich Library Support**
- Built-in functions for:
  - String manipulation
  - Array operations
  - Date/time
  - File handling
  - Image processing
  - Email sending

**11. Security Features**
- Data encryption
- Password hashing
- SQL injection prevention
- XSS protection

**12. Object-Oriented Programming**
- Supports OOP concepts
- Classes and objects
- Inheritance, polymorphism
- Encapsulation

**13. Supports Multiple Protocols**
- HTTP, HTTPS
- FTP
- IMAP, POP3
- LDAP

**14. Real-Time Monitoring**
- Track user activities
- Monitor server performance
- Log system events

**15. Loosely Typed Language**
- No need to declare variable types
- Automatic type conversion
- Flexible variable usage

**16. Case Sensitive**
- Variable names are case-sensitive
- Function names are NOT case-sensitive

---

### PHP Advantages:

1. **Easy to learn** - Simple syntax
2. **Free** - No cost
3. **Fast** - Quick execution
4. **Flexible** - Works with many databases
5. **Portable** - Platform independent
6. **Large community** - Lots of resources
7. **Built-in functions** - Reduces development time
8. **Framework support** - Laravel, CodeIgniter, Symfony

### PHP Disadvantages:

1. **Open source** - Security vulnerabilities if not careful
2. **Not suitable for large applications** - Better alternatives exist
3. **Error handling** - Weak compared to other languages
4. **Performance** - Slower than compiled languages
5. **Security** - Requires careful coding

---

### PHP Syntax Basics:

**PHP Tags:**
```php
<?php
    // PHP code here
?>
```

**Variables:**
```php
<?php
    $name = "John";        // String
    $age = 25;             // Integer
    $price = 99.99;        // Float
    $is_student = true;    // Boolean
?>
```

**Comments:**
```php
<?php
    // Single line comment

    # Another single line comment

    /*
       Multi-line
       comment
    */
?>
```

**Output:**
```php
<?php
    echo "Hello World";
    print "Hello World";
?>
```

---

## 3. Web Techniques

### Client-Server Architecture

**Definition:** A distributed application structure that partitions tasks between service providers (servers) and service requesters (clients).

### Components:

**1. Client**
- User's computer/device
- Web browser (Chrome, Firefox, Safari)
- Requests resources from server
- Displays web pages
- Examples: Desktop, Mobile, Tablet

**2. Server**
- Powerful computer storing web files
- Always on and connected to internet
- Processes client requests
- Sends responses back to client
- Examples: Apache, Nginx, IIS

**3. Network**
- Internet connection
- Connects client and server
- Uses HTTP/HTTPS protocols

---

### How Client-Server Works:

**Step-by-Step Process:**

```
1. User enters URL in browser → www.example.com
2. Browser sends HTTP request to server
3. Server receives request
4. Server processes request (runs PHP, queries database)
5. Server generates HTML response
6. Server sends response to client
7. Browser receives HTML
8. Browser renders page
9. User sees webpage
```

**Diagram:**
```
Client (Browser)                    Server
     |                                |
     | -------- HTTP Request -------> |
     |         (GET /index.php)       |
     |                                |
     |                        [Process Request]
     |                        [Run PHP Code]
     |                        [Query Database]
     |                                |
     | <------- HTTP Response ------- |
     |         (HTML Content)         |
     |                                |
[Render HTML]
[Display Page]
```

---

### Types of Client-Server Architecture:

**1. Two-Tier Architecture**
- Client directly communicates with server
- Simple and fast
- Example: Client → Database Server

**2. Three-Tier Architecture**
- Client → Application Server → Database Server
- Better security and scalability
- Most common for web applications

```
Presentation Layer (Client)
     ↓
Application Layer (Web Server with PHP)
     ↓
Data Layer (Database Server)
```

---

### Advantages of Client-Server:

1. **Centralized data management** - Data stored in one place
2. **Security** - Controlled access to data
3. **Scalability** - Easy to add more clients
4. **Resource sharing** - Multiple clients use same resources
5. **Backup and recovery** - Centralized backup
6. **Maintenance** - Update server, all clients benefit

### Disadvantages:

1. **Server dependency** - If server fails, all clients affected
2. **Cost** - Expensive servers required
3. **Network dependency** - Requires stable network
4. **Maintenance** - Server needs constant monitoring

---

## 4. HTTP Basics

**HTTP (HyperText Transfer Protocol)** is the foundation of data communication on the World Wide Web.

### What is HTTP?

- **Application layer protocol**
- Used for transmitting web pages
- Stateless protocol (doesn't remember previous requests)
- Runs on top of TCP/IP
- Default port: **80** (HTTP), **443** (HTTPS)

---

### Basic Features of HTTP:

**1. Connectionless**
- After request/response, connection closes
- No persistent connection by default
- Each request is independent

**2. Stateless**
- Server doesn't remember previous requests
- Each request treated as new
- Use cookies/sessions to maintain state

**3. Media Independent**
- Can transmit any type of data
- Images, videos, text, files
- Content-Type header specifies type

**4. Client-Server Protocol**
- Client sends request
- Server sends response

---

### HTTP Request Methods:

**1. GET**
- Retrieves data from server
- Parameters visible in URL
- Can be bookmarked
- Length limited
- Not secure for sensitive data

```php
// Example URL
http://example.com/page.php?name=John&age=25
```

**2. POST**
- Sends data to server
- Parameters hidden in request body
- Cannot be bookmarked
- No length limit
- More secure than GET

```php
// Data sent in request body (not visible in URL)
```

**3. PUT**
- Updates existing resource
- Replaces entire resource

**4. DELETE**
- Deletes specified resource

**5. HEAD**
- Same as GET but returns only headers
- No response body

**6. OPTIONS**
- Returns supported HTTP methods

**7. PATCH**
- Partially updates resource

---

### HTTP Request Structure:

```
Request Line: GET /index.php HTTP/1.1
Headers:
    Host: www.example.com
    User-Agent: Mozilla/5.0
    Accept: text/html
    Cookie: session_id=abc123

Body: (for POST requests)
    name=John&age=25
```

---

### HTTP Response Structure:

```
Status Line: HTTP/1.1 200 OK
Headers:
    Content-Type: text/html
    Content-Length: 1234
    Set-Cookie: session_id=abc123
    Date: Mon, 01 Jan 2024 12:00:00 GMT

Body:
    <html>
    <body>
        <h1>Hello World</h1>
    </body>
    </html>
```

---

### HTTP Status Codes:

**1xx - Informational**
- 100 Continue
- 101 Switching Protocols

**2xx - Success**
- **200 OK** - Request successful
- **201 Created** - Resource created
- **204 No Content** - Successful but no content

**3xx - Redirection**
- **301 Moved Permanently** - URL permanently changed
- **302 Found** - Temporary redirect
- **304 Not Modified** - Cached version is current

**4xx - Client Errors**
- **400 Bad Request** - Invalid syntax
- **401 Unauthorized** - Authentication required
- **403 Forbidden** - Access denied
- **404 Not Found** - Resource doesn't exist
- **405 Method Not Allowed** - Wrong HTTP method

**5xx - Server Errors**
- **500 Internal Server Error** - Server crashed
- **502 Bad Gateway** - Invalid response from upstream
- **503 Service Unavailable** - Server overloaded

---

### HTTP Headers:

**Request Headers:**
```
Host: www.example.com
User-Agent: Mozilla/5.0
Accept: text/html
Accept-Language: en-US
Cookie: session_id=abc123
Referer: http://previous-page.com
```

**Response Headers:**
```
Content-Type: text/html; charset=UTF-8
Content-Length: 1234
Set-Cookie: session_id=xyz789
Location: http://redirect-url.com
Cache-Control: no-cache
```

---

### HTTPS (HTTP Secure):

- Encrypted version of HTTP
- Uses SSL/TLS encryption
- Port 443
- Protects data from eavesdropping
- Required for sensitive data (passwords, credit cards)
- Green padlock in browser

---

## 5. Server Information in PHP

PHP provides superglobal arrays to access server and request information.

### `$_SERVER` Superglobal:

Contains server and execution environment information.

**Common `$_SERVER` Variables:**

```php
<?php
// Server Name
echo $_SERVER['SERVER_NAME'];        // www.example.com

// Server IP Address
echo $_SERVER['SERVER_ADDR'];        // 192.168.1.1

// Server Software
echo $_SERVER['SERVER_SOFTWARE'];    // Apache/2.4

// Server Protocol
echo $_SERVER['SERVER_PROTOCOL'];    // HTTP/1.1

// Request Method
echo $_SERVER['REQUEST_METHOD'];     // GET or POST

// Request URI
echo $_SERVER['REQUEST_URI'];        // /page.php?id=5

// Script Name
echo $_SERVER['SCRIPT_NAME'];        // /folder/page.php

// Query String
echo $_SERVER['QUERY_STRING'];       // id=5&name=John

// Document Root
echo $_SERVER['DOCUMENT_ROOT'];      // /var/www/html

// Client IP Address
echo $_SERVER['REMOTE_ADDR'];        // 192.168.1.100

// Client Port
echo $_SERVER['REMOTE_PORT'];        // 54321

// User Agent (Browser)
echo $_SERVER['HTTP_USER_AGENT'];    // Mozilla/5.0...

// Referer (Previous Page)
echo $_SERVER['HTTP_REFERER'];       // http://previous.com

// Host Header
echo $_SERVER['HTTP_HOST'];          // www.example.com

// Current Script Filename
echo $_SERVER['SCRIPT_FILENAME'];    // /var/www/html/page.php

// PHP Self (Current Page)
echo $_SERVER['PHP_SELF'];           // /page.php
?>
```

---

### Complete Server Information Example:

```php
<!DOCTYPE html>
<html>
<head>
    <title>Server Information</title>
    <style>
        table { border-collapse: collapse; width: 100%; }
        th, td { border: 1px solid #ddd; padding: 10px; text-align: left; }
        th { background-color: #4CAF50; color: white; }
    </style>
</head>
<body>
    <h2>Server Information</h2>
    <table>
        <tr>
            <th>Variable</th>
            <th>Value</th>
        </tr>
        <tr>
            <td>Server Name</td>
            <td><?php echo $_SERVER['SERVER_NAME']; ?></td>
        </tr>
        <tr>
            <td>Server IP</td>
            <td><?php echo $_SERVER['SERVER_ADDR']; ?></td>
        </tr>
        <tr>
            <td>Server Software</td>
            <td><?php echo $_SERVER['SERVER_SOFTWARE']; ?></td>
        </tr>
        <tr>
            <td>Request Method</td>
            <td><?php echo $_SERVER['REQUEST_METHOD']; ?></td>
        </tr>
        <tr>
            <td>Request URI</td>
            <td><?php echo $_SERVER['REQUEST_URI']; ?></td>
        </tr>
        <tr>
            <td>Client IP</td>
            <td><?php echo $_SERVER['REMOTE_ADDR']; ?></td>
        </tr>
        <tr>
            <td>Browser</td>
            <td><?php echo $_SERVER['HTTP_USER_AGENT']; ?></td>
        </tr>
        <tr>
            <td>Current Script</td>
            <td><?php echo $_SERVER['PHP_SELF']; ?></td>
        </tr>
    </table>

    <h3>All $_SERVER Variables</h3>
    <pre><?php print_r($_SERVER); ?></pre>
</body>
</html>
```

---

## 6. Processing Forms in PHP

Forms are the primary way to collect user input and send it to the server for processing.

### Form Processing Methods:

### GET Method:

**HTML Form:**
```html
<form action="process.php" method="GET">
    Name: <input type="text" name="username">
    Age: <input type="number" name="age">
    <input type="submit" value="Submit">
</form>
```

**PHP Processing (process.php):**
```php
<?php
if ($_SERVER['REQUEST_METHOD'] == 'GET') {
    $username = $_GET['username'];
    $age = $_GET['age'];

    echo "Name: " . $username . "<br>";
    echo "Age: " . $age;
}
?>
```

**URL:** `process.php?username=John&age=25`

---

### POST Method:

**HTML Form:**
```html
<form action="process.php" method="POST">
    Email: <input type="email" name="email" required>
    Password: <input type="password" name="password" required>
    <input type="submit" value="Login">
</form>
```

**PHP Processing (process.php):**
```php
<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $email = $_POST['email'];
    $password = $_POST['password'];

    echo "Email: " . $email . "<br>";
    echo "Password: " . $password;
}
?>
```

**URL:** `process.php` (no parameters visible)

---

### Complete Form Processing Example:

**registration.php:**
```php
<!DOCTYPE html>
<html>
<head>
    <title>Registration Form</title>
</head>
<body>
    <h2>Student Registration</h2>

    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
        <label>Full Name:</label>
        <input type="text" name="fullname" required><br><br>

        <label>Email:</label>
        <input type="email" name="email" required><br><br>

        <label>Password:</label>
        <input type="password" name="password" required><br><br>

        <label>Age:</label>
        <input type="number" name="age" min="18" max="100" required><br><br>

        <label>Gender:</label>
        <input type="radio" name="gender" value="Male" required> Male
        <input type="radio" name="gender" value="Female"> Female<br><br>

        <label>Course:</label>
        <select name="course" required>
            <option value="">--Select--</option>
            <option value="BCA">BCA</option>
            <option value="MCA">MCA</option>
            <option value="BTech">B.Tech</option>
        </select><br><br>

        <label>Hobbies:</label>
        <input type="checkbox" name="hobbies[]" value="Reading"> Reading
        <input type="checkbox" name="hobbies[]" value="Sports"> Sports
        <input type="checkbox" name="hobbies[]" value="Music"> Music<br><br>

        <label>Address:</label>
        <textarea name="address" rows="4" cols="30" required></textarea><br><br>

        <input type="submit" name="submit" value="Register">
        <input type="reset" value="Clear">
    </form>

    <?php
    if (isset($_POST['submit'])) {
        // Retrieve form data
        $fullname = $_POST['fullname'];
        $email = $_POST['email'];
        $password = $_POST['password'];
        $age = $_POST['age'];
        $gender = $_POST['gender'];
        $course = $_POST['course'];
        $address = $_POST['address'];

        // Retrieve checkboxes (array)
        $hobbies = isset($_POST['hobbies']) ? $_POST['hobbies'] : array();

        // Display submitted data
        echo "<h3>Registration Successful!</h3>";
        echo "<p><strong>Name:</strong> " . $fullname . "</p>";
        echo "<p><strong>Email:</strong> " . $email . "</p>";
        echo "<p><strong>Age:</strong> " . $age . "</p>";
        echo "<p><strong>Gender:</strong> " . $gender . "</p>";
        echo "<p><strong>Course:</strong> " . $course . "</p>";
        echo "<p><strong>Address:</strong> " . $address . "</p>";
        echo "<p><strong>Hobbies:</strong> " . implode(", ", $hobbies) . "</p>";
    }
    ?>
</body>
</html>
```

---

### Form Validation:

**Validation Example:**
```php
<?php
$errors = array();

if (isset($_POST['submit'])) {
    // Name validation
    $name = trim($_POST['name']);
    if (empty($name)) {
        $errors[] = "Name is required";
    } elseif (strlen($name) < 3) {
        $errors[] = "Name must be at least 3 characters";
    }

    // Email validation
    $email = trim($_POST['email']);
    if (empty($email)) {
        $errors[] = "Email is required";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $errors[] = "Invalid email format";
    }

    // Age validation
    $age = $_POST['age'];
    if (empty($age)) {
        $errors[] = "Age is required";
    } elseif ($age < 18 || $age > 100) {
        $errors[] = "Age must be between 18 and 100";
    }

    // Password validation
    $password = $_POST['password'];
    if (empty($password)) {
        $errors[] = "Password is required";
    } elseif (strlen($password) < 6) {
        $errors[] = "Password must be at least 6 characters";
    }

    // If no errors, process the form
    if (empty($errors)) {
        echo "<p style='color: green;'>Registration successful!</p>";
        // Process data (save to database, etc.)
    } else {
        // Display errors
        echo "<div style='color: red;'>";
        echo "<h4>Please fix the following errors:</h4>";
        echo "<ul>";
        foreach ($errors as $error) {
            echo "<li>$error</li>";
        }
        echo "</ul>";
        echo "</div>";
    }
}
?>
```

---

### Sanitizing User Input:

**Security Best Practices:**
```php
<?php
// Remove whitespace
$name = trim($_POST['name']);

// Remove HTML tags
$name = strip_tags($name);

// Convert special characters to HTML entities
$name = htmlspecialchars($name);

// Remove backslashes
$name = stripslashes($name);

// Combined sanitization
$name = htmlspecialchars(strip_tags(trim($_POST['name'])));

// Sanitize email
$email = filter_var($_POST['email'], FILTER_SANITIZE_EMAIL);

// Validate and sanitize URL
$url = filter_var($_POST['website'], FILTER_VALIDATE_URL);

// Sanitize integer
$age = filter_var($_POST['age'], FILTER_SANITIZE_NUMBER_INT);
?>
```

---

## 7. Setting Response Headers in PHP

Headers send additional information with HTTP response.

### `header()` Function:

**Syntax:**
```php
header(string $header, bool $replace = true, int $response_code = 0)
```

**Important:** Must be called before any output (HTML, echo, print).

---

### Common Header Examples:

**1. Redirect to Another Page:**
```php
<?php
header("Location: welcome.php");
exit();
?>
```

**2. Set Content-Type:**
```php
<?php
// HTML (default)
header("Content-Type: text/html; charset=UTF-8");

// Plain text
header("Content-Type: text/plain");

// JSON
header("Content-Type: application/json");

// XML
header("Content-Type: application/xml");

// PDF
header("Content-Type: application/pdf");
?>
```

**3. Force Download:**
```php
<?php
$file = "document.pdf";
header("Content-Type: application/pdf");
header("Content-Disposition: attachment; filename=\"$file\"");
header("Content-Length: " . filesize($file));
readfile($file);
exit();
?>
```

**4. Set HTTP Status Code:**
```php
<?php
// Not Found
header("HTTP/1.1 404 Not Found");

// Unauthorized
header("HTTP/1.1 401 Unauthorized");

// Forbidden
header("HTTP/1.1 403 Forbidden");

// Internal Server Error
header("HTTP/1.1 500 Internal Server Error");
?>
```

**5. Prevent Caching:**
```php
<?php
header("Cache-Control: no-cache, no-store, must-revalidate");
header("Pragma: no-cache");
header("Expires: 0");
?>
```

**6. Set Cookie:**
```php
<?php
header("Set-Cookie: username=John; expires=Fri, 31-Dec-2024 23:59:59 GMT; path=/");
?>
```

**7. Enable CORS (Cross-Origin Resource Sharing):**
```php
<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST, PUT, DELETE");
header("Access-Control-Allow-Headers: Content-Type");
?>
```

**8. Refresh Page:**
```php
<?php
// Refresh after 5 seconds
header("Refresh: 5");

// Refresh and redirect
header("Refresh: 5; url=welcome.php");
?>
```

---

### Complete Header Example:

```php
<?php
// login_process.php

if (isset($_POST['submit'])) {
    $email = $_POST['email'];
    $password = $_POST['password'];

    // Check credentials (simplified)
    if ($email == "user@example.com" && $password == "123456") {
        // Successful login - redirect to dashboard
        header("Location: dashboard.php");
        exit();
    } else {
        // Failed login - redirect back with error
        header("Location: login.php?error=1");
        exit();
    }
}

// If accessed directly, redirect to login
header("Location: login.php");
exit();
?>
```

---

### Checking if Headers Already Sent:

```php
<?php
if (!headers_sent()) {
    header("Location: welcome.php");
    exit();
} else {
    echo "Headers already sent, cannot redirect";
}
?>
```

---

## 8. Maintaining State (Sessions & Cookies)

HTTP is stateless, so we need mechanisms to maintain user state across multiple requests.

### A. Cookies

**Definition:** Small text files stored on client's computer by the web browser.

**Creating Cookie:**
```php
<?php
// Syntax
setcookie(name, value, expire, path, domain, secure, httponly);

// Simple cookie
setcookie("username", "John", time() + 3600); // Expires in 1 hour

// Cookie with all parameters
setcookie("user_id", "12345", time() + (86400 * 30), "/", "", false, true);
// Expires in 30 days, available site-wide
?>
```

**Accessing Cookie:**
```php
<?php
if (isset($_COOKIE['username'])) {
    echo "Welcome " . $_COOKIE['username'];
} else {
    echo "Cookie not set";
}
?>
```

**Deleting Cookie:**
```php
<?php
// Set expiration time in the past
setcookie("username", "", time() - 3600);
?>
```

**Complete Cookie Example:**
```php
<?php
// Set cookie when form submitted
if (isset($_POST['remember'])) {
    $username = $_POST['username'];
    setcookie("username", $username, time() + (86400 * 30)); // 30 days
    echo "Cookie set for $username";
}

// Check if cookie exists
if (isset($_COOKIE['username'])) {
    echo "Welcome back, " . $_COOKIE['username'];
}
?>

<form method="POST">
    Username: <input type="text" name="username">
    <input type="checkbox" name="remember"> Remember Me
    <input type="submit" value="Login">
</form>
```

---

### B. Sessions

**Definition:** Server-side mechanism to store user information across multiple pages during a visit.

**Starting Session:**
```php
<?php
session_start(); // Must be first line before any output
?>
```

**Creating Session Variables:**
```php
<?php
session_start();

$_SESSION['username'] = "John";
$_SESSION['user_id'] = 123;
$_SESSION['email'] = "john@example.com";
$_SESSION['role'] = "admin";
?>
```

**Accessing Session Variables:**
```php
<?php
session_start();

if (isset($_SESSION['username'])) {
    echo "Welcome " . $_SESSION['username'];
} else {
    echo "Please login first";
}
?>
```

**Destroying Specific Session Variable:**
```php
<?php
session_start();
unset($_SESSION['username']);
?>
```

**Destroying All Session Data:**
```php
<?php
session_start();
session_destroy();
?>
```

**Complete Logout:**
```php
<?php
session_start();
$_SESSION = array(); // Clear all session variables
session_destroy(); // Destroy session
header("Location: login.php");
exit();
?>
```

---

### Complete Login System Example:

**login.php:**
```php
<?php
session_start();

// If already logged in, redirect to dashboard
if (isset($_SESSION['username'])) {
    header("Location: dashboard.php");
    exit();
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Login</title>
</head>
<body>
    <h2>Login Form</h2>

    <?php
    if (isset($_GET['error'])) {
        echo "<p style='color: red;'>Invalid email or password!</p>";
    }
    if (isset($_GET['logout'])) {
        echo "<p style='color: green;'>Logged out successfully!</p>";
    }
    ?>

    <form action="login_process.php" method="POST">
        Email: <input type="email" name="email" required><br><br>
        Password: <input type="password" name="password" required><br><br>
        <input type="submit" name="login" value="Login">
    </form>
</body>
</html>
```

**login_process.php:**
```php
<?php
session_start();

if (isset($_POST['login'])) {
    $email = $_POST['email'];
    $password = $_POST['password'];

    // Check credentials (in real app, check against database)
    if ($email == "user@example.com" && $password == "password123") {
        // Set session variables
        $_SESSION['username'] = "John Doe";
        $_SESSION['email'] = $email;
        $_SESSION['user_id'] = 1;
        $_SESSION['login_time'] = time();

        // Redirect to dashboard
        header("Location: dashboard.php");
        exit();
    } else {
        // Redirect back with error
        header("Location: login.php?error=1");
        exit();
    }
}
?>
```

**dashboard.php:**
```php
<?php
session_start();

// Check if user is logged in
if (!isset($_SESSION['username'])) {
    header("Location: login.php");
    exit();
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Dashboard</title>
</head>
<body>
    <h2>Welcome, <?php echo $_SESSION['username']; ?>!</h2>
    <p>Email: <?php echo $_SESSION['email']; ?></p>
    <p>User ID: <?php echo $_SESSION['user_id']; ?></p>
    <p>Login Time: <?php echo date("Y-m-d H:i:s", $_SESSION['login_time']); ?></p>

    <a href="logout.php">Logout</a>
</body>
</html>
```

**logout.php:**
```php
<?php
session_start();

// Destroy all session data
$_SESSION = array();
session_destroy();

// Redirect to login page
header("Location: login.php?logout=1");
exit();
?>
```

---

### Session Configuration:

**Get Session ID:**
```php
<?php
session_start();
echo "Session ID: " . session_id();
?>
```

**Regenerate Session ID (Security):**
```php
<?php
session_start();
session_regenerate_id(true); // Prevents session fixation
?>
```

**Set Session Name:**
```php
<?php
session_name("MyApp");
session_start();
?>
```

**Session Timeout:**
```php
<?php
session_start();

// Set timeout (30 minutes)
$timeout = 1800;

if (isset($_SESSION['last_activity'])) {
    if (time() - $_SESSION['last_activity'] > $timeout) {
        session_destroy();
        header("Location: login.php?timeout=1");
        exit();
    }
}

$_SESSION['last_activity'] = time();
?>
```

---

### Cookies vs Sessions:

| Feature | Cookies | Sessions |
|---------|---------|----------|
| Storage Location | Client (browser) | Server |
| Security | Less secure | More secure |
| Size Limit | 4KB | No limit (server dependent) |
| Expiration | Can be set | Ends when browser closes |
| Access | Can be accessed by client | Only server can access |
| Best For | Remember me, preferences | Login status, shopping cart |

---

### PHP Session - What and Why:

**What is PHP Session?**
- Way to store user information on server
- Data available across multiple pages
- Each user has unique session ID
- Stored in temporary files on server
- More secure than cookies

**Why Use Sessions?**
1. **User Authentication** - Track logged-in users
2. **Shopping Cart** - Store items across pages
3. **User Preferences** - Remember settings
4. **Form Data** - Keep data during multi-step forms
5. **Security** - Data stored on server, not client
6. **Temporary Storage** - Store data during user visit

**Session Workflow:**
```
1. User visits website
2. session_start() creates unique session ID
3. Session ID stored in cookie on client
4. Session data stored on server
5. User navigates to different pages
6. Session ID sent with each request
7. Server retrieves session data using ID
8. User logs out or closes browser
9. Session destroyed
```

---

## 9. Databases

**Database:** Organized collection of structured data stored electronically.

### Types of Databases:

**1. Relational Databases (SQL)**
- MySQL (most popular with PHP)
- PostgreSQL
- Oracle
- MS SQL Server
- SQLite

**2. NoSQL Databases**
- MongoDB
- Redis
- Cassandra

---

### Database Concepts:

**1. Database:** Collection of tables
**2. Table:** Collection of rows and columns
**3. Row:** Single record
**4. Column:** Field/attribute
**5. Primary Key:** Unique identifier for row
**6. Foreign Key:** Links tables together

**Example Structure:**
```
Database: school
  Table: students
    Columns: id, name, email, age, course
    Row: 1, "John Doe", "john@example.com", 20, "BCA"
```

---

### MySQL Database Operations:

**1. CREATE - Create Database/Table:**
```sql
-- Create database
CREATE DATABASE school;

-- Use database
USE school;

-- Create table
CREATE TABLE students (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE,
    age INT,
    course VARCHAR(50),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
```

**2. INSERT - Add Data:**
```sql
INSERT INTO students (name, email, age, course)
VALUES ('John Doe', 'john@example.com', 20, 'BCA');

-- Multiple rows
INSERT INTO students (name, email, age, course) VALUES
('Jane Smith', 'jane@example.com', 21, 'MCA'),
('Bob Johnson', 'bob@example.com', 19, 'BTech');
```

**3. SELECT - Retrieve Data:**
```sql
-- All records
SELECT * FROM students;

-- Specific columns
SELECT name, email FROM students;

-- With condition
SELECT * FROM students WHERE age > 20;

-- With sorting
SELECT * FROM students ORDER BY name ASC;

-- With limit
SELECT * FROM students LIMIT 10;
```

**4. UPDATE - Modify Data:**
```sql
UPDATE students
SET age = 21, course = 'MCA'
WHERE id = 1;
```

**5. DELETE - Remove Data:**
```sql
DELETE FROM students WHERE id = 5;

-- Delete all records
DELETE FROM students;
```

---

## 10. Using PHP to Access Database

### Steps to Connect Database:

**1. Create Connection**
**2. Select Database**
**3. Execute Query**
**4. Fetch Results**
**5. Close Connection**

---

### Method 1: MySQLi (MySQL Improved)

**Procedural Style:**

```php
<?php
// 1. Create connection
$servername = "localhost";
$username = "root";
$password = "";
$database = "school";

$conn = mysqli_connect($servername, $username, $password, $database);

// 2. Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
echo "Connected successfully<br>";

// 3. Execute query
$sql = "SELECT * FROM students";
$result = mysqli_query($conn, $sql);

// 4. Fetch and display results
if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        echo "ID: " . $row['id'] . " - Name: " . $row['name'] . " - Email: " . $row['email'] . "<br>";
    }
} else {
    echo "No records found";
}

// 5. Close connection
mysqli_close($conn);
?>
```

**Object-Oriented Style:**

```php
<?php
// 1. Create connection
$servername = "localhost";
$username = "root";
$password = "";
$database = "school";

$conn = new mysqli($servername, $username, $password, $database);

// 2. Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully<br>";

// 3. Execute query
$sql = "SELECT * FROM students";
$result = $conn->query($sql);

// 4. Fetch and display results
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "ID: " . $row['id'] . " - Name: " . $row['name'] . "<br>";
    }
} else {
    echo "No records found";
}

// 5. Close connection
$conn->close();
?>
```

---

### Complete Database Connection Steps:

**Step 1: Create Database and Table** (Run in phpMyAdmin or MySQL client)

```sql
CREATE DATABASE school;

USE school;

CREATE TABLE students (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    age INT NOT NULL,
    course VARCHAR(50) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Insert sample data
INSERT INTO students (name, email, age, course) VALUES
('John Doe', 'john@example.com', 20, 'BCA'),
('Jane Smith', 'jane@example.com', 21, 'MCA'),
('Bob Johnson', 'bob@example.com', 19, 'BTech');
```

---

**Step 2: Create Database Configuration File**

**config.php:**
```php
<?php
// Database configuration
define('DB_SERVER', 'localhost');
define('DB_USERNAME', 'root');
define('DB_PASSWORD', '');
define('DB_NAME', 'school');

// Create connection
$conn = mysqli_connect(DB_SERVER, DB_USERNAME, DB_PASSWORD, DB_NAME);

// Check connection
if ($conn === false) {
    die("ERROR: Could not connect to database. " . mysqli_connect_error());
}
?>
```

---

**Step 3: INSERT Data**

**insert.php:**
```php
<?php
require_once 'config.php';

if (isset($_POST['submit'])) {
    // Get form data
    $name = mysqli_real_escape_string($conn, $_POST['name']);
    $email = mysqli_real_escape_string($conn, $_POST['email']);
    $age = mysqli_real_escape_string($conn, $_POST['age']);
    $course = mysqli_real_escape_string($conn, $_POST['course']);

    // SQL query
    $sql = "INSERT INTO students (name, email, age, course) VALUES ('$name', '$email', '$age', '$course')";

    // Execute query
    if (mysqli_query($conn, $sql)) {
        echo "<p style='color: green;'>Record inserted successfully!</p>";
    } else {
        echo "<p style='color: red;'>Error: " . mysqli_error($conn) . "</p>";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Add Student</title>
</head>
<body>
    <h2>Add New Student</h2>
    <form method="POST">
        Name: <input type="text" name="name" required><br><br>
        Email: <input type="email" name="email" required><br><br>
        Age: <input type="number" name="age" required><br><br>
        Course:
        <select name="course" required>
            <option value="">--Select--</option>
            <option value="BCA">BCA</option>
            <option value="MCA">MCA</option>
            <option value="BTech">B.Tech</option>
        </select><br><br>
        <input type="submit" name="submit" value="Add Student">
    </form>

    <br>
    <a href="view.php">View All Students</a>
</body>
</html>

<?php mysqli_close($conn); ?>
```

---

**Step 4: SELECT/DISPLAY Data**

**view.php:**
```php
<?php
require_once 'config.php';

// SQL query
$sql = "SELECT * FROM students ORDER BY id DESC";
$result = mysqli_query($conn, $sql);
?>

<!DOCTYPE html>
<html>
<head>
    <title>View Students</title>
    <style>
        table { border-collapse: collapse; width: 100%; }
        th, td { border: 1px solid #ddd; padding: 10px; text-align: left; }
        th { background-color: #4CAF50; color: white; }
        tr:hover { background-color: #f5f5f5; }
    </style>
</head>
<body>
    <h2>All Students</h2>

    <?php
    if (mysqli_num_rows($result) > 0) {
        echo "<table>";
        echo "<tr>
                <th>ID</th>
                <th>Name</th>
                <th>Email</th>
                <th>Age</th>
                <th>Course</th>
                <th>Created At</th>
                <th>Actions</th>
              </tr>";

        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>" . $row['id'] . "</td>";
            echo "<td>" . $row['name'] . "</td>";
            echo "<td>" . $row['email'] . "</td>";
            echo "<td>" . $row['age'] . "</td>";
            echo "<td>" . $row['course'] . "</td>";
            echo "<td>" . $row['created_at'] . "</td>";
            echo "<td>
                    <a href='edit.php?id=" . $row['id'] . "'>Edit</a> |
                    <a href='delete.php?id=" . $row['id'] . "' onclick='return confirm(\"Are you sure?\")'>Delete</a>
                  </td>";
            echo "</tr>";
        }

        echo "</table>";
    } else {
        echo "<p>No students found.</p>";
    }
    ?>

    <br>
    <a href="insert.php">Add New Student</a>
</body>
</html>

<?php mysqli_close($conn); ?>
```

---

**Step 5: UPDATE Data**

**edit.php:**
```php
<?php
require_once 'config.php';

$id = $_GET['id'];

// Fetch existing data
$sql = "SELECT * FROM students WHERE id = $id";
$result = mysqli_query($conn, $sql);
$student = mysqli_fetch_assoc($result);

// Update data
if (isset($_POST['update'])) {
    $name = mysqli_real_escape_string($conn, $_POST['name']);
    $email = mysqli_real_escape_string($conn, $_POST['email']);
    $age = mysqli_real_escape_string($conn, $_POST['age']);
    $course = mysqli_real_escape_string($conn, $_POST['course']);

    $sql = "UPDATE students SET name='$name', email='$email', age='$age', course='$course' WHERE id=$id";

    if (mysqli_query($conn, $sql)) {
        echo "<p style='color: green;'>Record updated successfully!</p>";
        header("Location: view.php");
        exit();
    } else {
        echo "<p style='color: red;'>Error: " . mysqli_error($conn) . "</p>";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Edit Student</title>
</head>
<body>
    <h2>Edit Student</h2>
    <form method="POST">
        Name: <input type="text" name="name" value="<?php echo $student['name']; ?>" required><br><br>
        Email: <input type="email" name="email" value="<?php echo $student['email']; ?>" required><br><br>
        Age: <input type="number" name="age" value="<?php echo $student['age']; ?>" required><br><br>
        Course:
        <select name="course" required>
            <option value="BCA" <?php if($student['course']=='BCA') echo 'selected'; ?>>BCA</option>
            <option value="MCA" <?php if($student['course']=='MCA') echo 'selected'; ?>>MCA</option>
            <option value="BTech" <?php if($student['course']=='BTech') echo 'selected'; ?>>BTech</option>
        </select><br><br>
        <input type="submit" name="update" value="Update Student">
    </form>

    <br>
    <a href="view.php">Back to List</a>
</body>
</html>

<?php mysqli_close($conn); ?>
```

---

**Step 6: DELETE Data**

**delete.php:**
```php
<?php
require_once 'config.php';

if (isset($_GET['id'])) {
    $id = $_GET['id'];

    // SQL query
    $sql = "DELETE FROM students WHERE id = $id";

    if (mysqli_query($conn, $sql)) {
        header("Location: view.php?deleted=1");
        exit();
    } else {
        echo "Error: " . mysqli_error($conn);
    }
}

mysqli_close($conn);
?>
```

---

### Using Prepared Statements (Secure Method):

**Prevents SQL Injection - Recommended for Exams**

```php
<?php
require_once 'config.php';

if (isset($_POST['submit'])) {
    // Prepare statement
    $stmt = mysqli_prepare($conn, "INSERT INTO students (name, email, age, course) VALUES (?, ?, ?, ?)");

    // Bind parameters (s = string, i = integer)
    mysqli_stmt_bind_param($stmt, "ssis", $name, $email, $age, $course);

    // Set parameters
    $name = $_POST['name'];
    $email = $_POST['email'];
    $age = $_POST['age'];
    $course = $_POST['course'];

    // Execute
    if (mysqli_stmt_execute($stmt)) {
        echo "Record inserted successfully!";
    } else {
        echo "Error: " . mysqli_error($conn);
    }

    // Close statement
    mysqli_stmt_close($stmt);
}

mysqli_close($conn);
?>
```

---

## 11. Security

### Common Security Threats:

**1. SQL Injection**
**2. Cross-Site Scripting (XSS)**
**3. Session Fixation**
**4. File Upload Vulnerabilities**
**5. Cross-Site Request Forgery (CSRF)**

---

### 1. SQL Injection Prevention:

**Vulnerable Code:**
```php
<?php
$username = $_POST['username'];
$sql = "SELECT * FROM users WHERE username = '$username'";
// Attacker can input: admin' OR '1'='1
?>
```

**Secure Code:**
```php
<?php
// Method 1: Prepared Statements
$stmt = mysqli_prepare($conn, "SELECT * FROM users WHERE username = ?");
mysqli_stmt_bind_param($stmt, "s", $username);
$username = $_POST['username'];
mysqli_stmt_execute($stmt);

// Method 2: Escape Strings
$username = mysqli_real_escape_string($conn, $_POST['username']);
$sql = "SELECT * FROM users WHERE username = '$username'";
?>
```

---

### 2. XSS (Cross-Site Scripting) Prevention:

**Vulnerable Code:**
```php
<?php
echo "Hello " . $_GET['name'];
// Attacker can input: <script>alert('Hacked!')</script>
?>
```

**Secure Code:**
```php
<?php
echo "Hello " . htmlspecialchars($_GET['name'], ENT_QUOTES, 'UTF-8');
// Converts special characters to HTML entities
?>
```

---

### 3. Session Fixation Prevention:

**Secure Session Management:**
```php
<?php
session_start();

// Regenerate session ID after login
if (isset($_POST['login'])) {
    // Verify credentials
    if (verify_credentials()) {
        session_regenerate_id(true); // Prevent session fixation
        $_SESSION['user_id'] = $user_id;
        $_SESSION['username'] = $username;
    }
}
?>
```

---

### 4. File Upload Security:

**Secure File Upload:**
```php
<?php
if (isset($_FILES['file'])) {
    $file = $_FILES['file'];

    // Check file size
    if ($file['size'] > 5000000) {
        die("File too large");
    }

    // Check file type
    $allowed = array('jpg', 'jpeg', 'png', 'gif', 'pdf');
    $ext = pathinfo($file['name'], PATHINFO_EXTENSION);

    if (!in_array(strtolower($ext), $allowed)) {
        die("Invalid file type");
    }

    // Generate unique filename
    $new_name = uniqid() . '.' . $ext;
    $destination = 'uploads/' . $new_name;

    // Move file
    if (move_uploaded_file($file['tmp_name'], $destination)) {
        echo "File uploaded successfully";
    } else {
        echo "Upload failed";
    }
}
?>
```

---

### 5. Password Security:

**Secure Password Handling:**
```php
<?php
// Hashing password during registration
$password = $_POST['password'];
$hashed_password = password_hash($password, PASSWORD_DEFAULT);

// Store $hashed_password in database

// Verifying password during login
$input_password = $_POST['password'];
$stored_hash = // Get from database

if (password_verify($input_password, $stored_hash)) {
    echo "Login successful";
} else {
    echo "Invalid password";
}
?>
```

---

## 12. File Uploads

### HTML Form for File Upload:

```html
<!DOCTYPE html>
<html>
<head>
    <title>File Upload</title>
</head>
<body>
    <h2>Upload File</h2>
    <form action="upload.php" method="POST" enctype="multipart/form-data">
        Select File: <input type="file" name="myfile" required><br><br>
        <input type="submit" name="submit" value="Upload">
    </form>
</body>
</html>
```

### PHP File Upload Processing:

**upload.php:**
```php
<?php
if (isset($_POST['submit'])) {
    // File information
    $file = $_FILES['myfile'];

    $file_name = $file['name'];
    $file_tmp = $file['tmp_name'];
    $file_size = $file['size'];
    $file_error = $file['error'];
    $file_type = $file['type'];

    // Get file extension
    $file_ext = strtolower(pathinfo($file_name, PATHINFO_EXTENSION));

    // Allowed extensions
    $allowed = array('jpg', 'jpeg', 'png', 'gif', 'pdf', 'doc', 'docx');

    if (in_array($file_ext, $allowed)) {
        if ($file_error === 0) {
            if ($file_size <= 5000000) { // 5MB max
                // Generate unique name
                $new_name = uniqid('file_', true) . '.' . $file_ext;
                $destination = 'uploads/' . $new_name;

                // Move file
                if (move_uploaded_file($file_tmp, $destination)) {
                    echo "<p style='color: green;'>File uploaded successfully!</p>";
                    echo "<p>Filename: $new_name</p>";
                    echo "<p>Size: " . ($file_size / 1024) . " KB</p>";
                } else {
                    echo "<p style='color: red;'>Error uploading file!</p>";
                }
            } else {
                echo "<p style='color: red;'>File is too large! Maximum 5MB allowed.</p>";
            }
        } else {
            echo "<p style='color: red;'>Error occurred during upload!</p>";
        }
    } else {
        echo "<p style='color: red;'>Invalid file type! Allowed: " . implode(', ', $allowed) . "</p>";
    }
}
?>
```

---

### `$_FILES` Array Structure:

```php
Array (
    [myfile] => Array (
        [name] => document.pdf        // Original filename
        [type] => application/pdf     // MIME type
        [tmp_name] => /tmp/phpABC123  // Temporary location
        [error] => 0                  // Error code (0 = success)
        [size] => 123456              // File size in bytes
    )
)
```

---

## 13. File Access in PHP

### Reading Files:

**1. file_get_contents() - Read Entire File:**
```php
<?php
$content = file_get_contents('file.txt');
echo $content;
?>
```

**2. fopen(), fread(), fclose() - Manual Reading:**
```php
<?php
$file = fopen('file.txt', 'r');
if ($file) {
    $content = fread($file, filesize('file.txt'));
    echo $content;
    fclose($file);
}
?>
```

**3. file() - Read into Array:**
```php
<?php
$lines = file('file.txt');
foreach ($lines as $line) {
    echo $line . "<br>";
}
?>
```

**4. fgets() - Read Line by Line:**
```php
<?php
$file = fopen('file.txt', 'r');
while (!feof($file)) {
    $line = fgets($file);
    echo $line . "<br>";
}
fclose($file);
?>
```

---

### Writing Files:

**1. file_put_contents() - Write Entire File:**
```php
<?php
$content = "Hello World!";
file_put_contents('file.txt', $content);
?>
```

**2. fopen(), fwrite(), fclose() - Manual Writing:**
```php
<?php
$file = fopen('file.txt', 'w');
fwrite($file, "Hello World!");
fclose($file);
?>
```

---

### File Modes:

| Mode | Description |
|------|-------------|
| 'r' | Read only, pointer at beginning |
| 'r+' | Read/Write, pointer at beginning |
| 'w' | Write only, creates file, truncates existing |
| 'w+' | Read/Write, creates file, truncates existing |
| 'a' | Write only (append), creates if not exists |
| 'a+' | Read/Write (append), creates if not exists |

---

### File Functions:

```php
<?php
// Check if file exists
if (file_exists('file.txt')) {
    echo "File exists";
}

// Check if readable
if (is_readable('file.txt')) {
    echo "File is readable";
}

// Check if writable
if (is_writable('file.txt')) {
    echo "File is writable";
}

// Get file size
$size = filesize('file.txt');
echo "Size: $size bytes";

// Delete file
if (unlink('file.txt')) {
    echo "File deleted";
}

// Rename file
rename('old.txt', 'new.txt');

// Copy file
copy('source.txt', 'destination.txt');
?>
```

---

## 14. Error Handling in PHP

### Types of Errors:

**1. Parse Error (Syntax Error)**
- Missing semicolon, brackets
- Fatal - script stops

**2. Fatal Error**
- Calling undefined function
- Script stops execution

**3. Warning Error**
- Including missing file
- Script continues

**4. Notice Error**
- Accessing undefined variable
- Script continues

---

### Error Reporting Levels:

```php
<?php
// Show all errors
error_reporting(E_ALL);

// Show no errors
error_reporting(0);

// Show errors except notices
error_reporting(E_ALL & ~E_NOTICE);

// Display errors on screen
ini_set('display_errors', 1);
?>
```

---

### try-catch (Exception Handling):

```php
<?php
try {
    // Code that may throw exception
    $result = 10 / 0;

} catch (Exception $e) {
    // Handle exception
    echo "Error: " . $e->getMessage();

} finally {
    // Always executes
    echo "Cleanup code";
}
?>
```

---

### Custom Error Handler:

```php
<?php
function customError($errno, $errstr, $errfile, $errline) {
    echo "<b>Error:</b> [$errno] $errstr<br>";
    echo "Error on line $errline in $errfile<br>";
}

// Set error handler
set_error_handler("customError");

// Trigger error
echo $undefined_variable;
?>
```

---

### Logging Errors:

```php
<?php
// Log to file
ini_set('log_errors', 1);
ini_set('error_log', '/path/to/error.log');

// Trigger error
error_log("Custom error message");
?>
```

---

## 15. Handling Output

### Output Buffering:

```php
<?php
// Start output buffering
ob_start();

echo "Hello ";
echo "World!";

// Get buffer contents
$output = ob_get_contents();

// Clean buffer
ob_clean();

// End buffering and send output
ob_end_flush();
?>
```

---

### Output Functions:

```php
<?php
// echo - Output one or more strings
echo "Hello", " ", "World!";

// print - Output a string
print "Hello World!";

// printf - Formatted output
printf("Name: %s, Age: %d", "John", 25);

// print_r - Print array/object (for debugging)
print_r($array);

// var_dump - Detailed variable information
var_dump($variable);
?>
```

---

## Key Points to Remember for Exams:

1. **PHP** - Server-side scripting language for dynamic web pages
2. **Client-Server** - Client requests, server processes and responds
3. **HTTP** - Stateless protocol, uses GET/POST methods
4. **Forms** - GET (visible in URL), POST (hidden, secure)
5. **Sessions** - Server-side storage, more secure than cookies
6. **Cookies** - Client-side storage, 4KB limit
7. **Database Steps** - Connect → Query → Fetch → Close
8. **Security** - Use prepared statements, htmlspecialchars(), password_hash()
9. **File Upload** - Validate type, size, use unique names
10. **Error Handling** - try-catch, error_reporting(), custom handlers

---

**This covers all topics from Unit 4 needed for both 10-mark and 3-mark questions!**
