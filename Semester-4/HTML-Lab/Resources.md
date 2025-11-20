# 📚 Comprehensive PHP Form Handling Guide

## Table of Contents

1. [HTML Form Structure](#html-form-structure)
2. [PHP Superglobals for Form Data](#php-superglobals)
3. [Form Data Handling Methods](#form-data-handling)
4. [Validation Methods](#validation-methods)
5. [Sanitization Methods](#sanitization-methods)
6. [Database Connection](#database-connection)
7. [MySQLi Methods Reference](#mysqli-methods)
8. [Prepared Statements](#prepared-statements)
9. [File Upload Handling](#file-uploads)
10. [Security Best Practices](#security)

---

## 1. HTML Form Structure {#html-form-structure}

### Basic Form Anatomy

```html
<form action="process.php" method="POST" enctype="multipart/form-data">
  <!-- Form fields here -->
</form>
```

### Form Attributes

| Attribute | Description                 | When to Use                                |
| --------- | --------------------------- | ------------------------------------------ |
| `action`  | URL where form data is sent | Always specify target PHP file             |
| `method`  | HTTP method (GET/POST)      | POST for sensitive data, GET for search    |
| `enctype` | Encoding type               | Use `multipart/form-data` for file uploads |
| `name`    | Form identifier             | For JavaScript reference                   |
| `id`      | Unique identifier           | For CSS/JavaScript targeting               |

### Form Methods: GET vs POST

#### **GET Method**

```html
<form action="search.php" method="GET">
  <input type="text" name="query" />
  <button type="submit">Search</button>
</form>
```

**Characteristics:**

- ✅ Data visible in URL: `search.php?query=hello`
- ✅ Can be bookmarked
- ✅ Browser history saved
- ❌ Not secure (visible in URL)
- ❌ Limited data size (~2000 characters)
- ❌ Never use for passwords

**When to Use:**

- Search queries
- Filtering/sorting
- Pagination
- Shareable links

**When NOT to Use:**

- Login forms
- Sensitive data
- Large data
- File uploads

#### **POST Method**

```html
<form action="register.php" method="POST">
  <input type="password" name="password" />
  <button type="submit">Register</button>
</form>
```

**Characteristics:**

- ✅ Data NOT visible in URL
- ✅ More secure
- ✅ No size limit
- ✅ Supports file uploads
- ❌ Cannot be bookmarked
- ❌ Not in browser history

**When to Use:**

- Login/Registration
- Password forms
- Large data submission
- File uploads
- Creating/updating records

---

### All HTML Input Types

```html
<!-- Text Inputs -->
<input type="text" name="username" />
<!-- Plain text -->
<input type="email" name="email" />
<!-- Email validation -->
<input type="password" name="password" />
<!-- Hidden characters -->
<input type="tel" name="phone" />
<!-- Phone number -->
<input type="url" name="website" />
<!-- URL validation -->
<input type="search" name="query" />
<!-- Search box -->

<!-- Number Inputs -->
<input type="number" name="age" min="18" max="100" />
<input type="range" name="rating" min="1" max="5" />

<!-- Date/Time Inputs -->
<input type="date" name="dob" />
<!-- Date picker -->
<input type="time" name="appointment" />
<!-- Time picker -->
<input type="datetime-local" name="event" />
<!-- Date + Time -->
<input type="month" name="month" />
<!-- Month/Year -->
<input type="week" name="week" />
<!-- Week picker -->

<!-- Selection Inputs -->
<input type="radio" name="gender" value="male" />
<!-- Single choice -->
<input type="checkbox" name="terms" value="yes" />
<!-- Multiple choice -->

<!-- File Input -->
<input type="file" name="avatar" accept="image/*" />

<!-- Special Inputs -->
<input type="color" name="theme" />
<!-- Color picker -->
<input type="hidden" name="user_id" value="123" />
<!-- Hidden field -->

<!-- Buttons -->
<input type="submit" value="Submit" />
<input type="reset" value="Reset" />
<input type="button" value="Click" />
<button type="submit">Submit</button>
<!-- Better than input submit -->

<!-- Textarea -->
<textarea name="message" rows="5" cols="30"></textarea>

<!-- Select Dropdown -->
<select name="country">
  <option value="">-- Select --</option>
  <option value="USA">USA</option>
  <option value="UK">UK</option>
</select>

<!-- Multi-select -->
<select name="skills[]" multiple>
  <option value="PHP">PHP</option>
  <option value="JavaScript">JavaScript</option>
</select>
```

### Important Input Attributes

```html
<input type="text" name="username"
<!-- Required: name for PHP -->
id="username"
<!-- For label/CSS -->
value="default"
<!-- Pre-filled value -->
placeholder="Enter name"
<!-- Hint text -->
required
<!-- HTML5 validation -->
disabled
<!-- Cannot interact -->
readonly
<!-- Can view, not edit -->
maxlength="50"
<!-- Max characters -->
minlength="3"
<!-- Min characters -->
pattern="[A-Za-z]+"
<!-- Regex validation -->
autocomplete="off"
<!-- Disable autocomplete -->
autofocus>
<!-- Auto focus on load -->
```

---

## 2. PHP Superglobals for Form Data {#php-superglobals}

### $\_POST - POST Method Data

```php
// Access single field
$username = $_POST['username'];

// Check if exists before accessing
if (isset($_POST['username'])) {
    $username = $_POST['username'];
}

// Get all POST data
$all_post_data = $_POST;

// Check if form submitted
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // Process form
}

// Better check
if (isset($_POST['submit'])) {
    // submit button was clicked
}
```

**When to Use:**

- Login forms
- Registration
- Data modification
- File uploads

**When NOT to Use:**

- Search queries (use GET)
- Pagination (use GET)
- Shareable URLs (use GET)

---

### $\_GET - GET Method Data

```php
// URL: page.php?id=5&name=John

// Access single parameter
$id = $_GET['id'];      // 5
$name = $_GET['name'];  // John

// Check if exists
if (isset($_GET['id'])) {
    $id = $_GET['id'];
}

// Get all GET data
$all_get_data = $_GET;
```

**When to Use:**

- Search functionality
- Filtering results
- Pagination
- Sorting
- Tracking parameters

**When NOT to Use:**

- Passwords/sensitive data
- Large data
- File uploads

---

### $\_REQUEST - Both GET and POST

```php
// Works with both GET and POST
$username = $_REQUEST['username'];

// Check existence
if (isset($_REQUEST['username'])) {
    $username = $_REQUEST['username'];
}
```

**When to Use:**

- When form method might change
- Flexible form handling

**When NOT to Use:**

- Security-critical applications (ambiguous source)
- **NOT RECOMMENDED** in production (use specific $\_POST or $\_GET)

---

### $\_FILES - File Upload Data

```php
// File upload structure
$_FILES['avatar'] = [
    'name' => 'photo.jpg',          // Original filename
    'type' => 'image/jpeg',         // MIME type
    'tmp_name' => '/tmp/php123',    // Temporary location
    'error' => 0,                   // Error code
    'size' => 50000                 // Size in bytes
];

// Access file data
$filename = $_FILES['avatar']['name'];
$file_tmp = $_FILES['avatar']['tmp_name'];
$file_size = $_FILES['avatar']['size'];
$file_error = $_FILES['avatar']['error'];

// Check if file uploaded
if (isset($_FILES['avatar']) && $_FILES['avatar']['error'] == 0) {
    // Process file
}
```

---

### $\_SERVER - Server & Request Info

```php
// Request method
$_SERVER['REQUEST_METHOD'];     // GET, POST, PUT, DELETE

// Current script
$_SERVER['PHP_SELF'];           // /path/to/script.php
$_SERVER['SCRIPT_NAME'];        // /path/to/script.php

// Server info
$_SERVER['SERVER_NAME'];        // localhost
$_SERVER['SERVER_ADDR'];        // 127.0.0.1
$_SERVER['SERVER_PORT'];        // 80 or 443

// Client info
$_SERVER['REMOTE_ADDR'];        // Client IP: 192.168.1.1
$_SERVER['HTTP_USER_AGENT'];    // Browser info
$_SERVER['HTTP_REFERER'];       // Previous page URL

// Request info
$_SERVER['REQUEST_URI'];        // /page.php?id=5
$_SERVER['QUERY_STRING'];       // id=5&name=John

// HTTPS check
$_SERVER['HTTPS'];              // 'on' if HTTPS

// Example usage
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // Handle POST request
}

if (isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] == 'on') {
    echo "Secure connection";
}
```

---

### $\_SESSION - Session Data

```php
// Start session (REQUIRED at top of file)
session_start();

// Set session variable
$_SESSION['username'] = 'John';
$_SESSION['user_id'] = 123;

// Get session variable
$username = $_SESSION['username'];

// Check if exists
if (isset($_SESSION['user_id'])) {
    echo "User logged in";
}

// Remove specific session
unset($_SESSION['username']);

// Destroy all sessions
session_destroy();
```

**When to Use:**

- User login state
- Shopping cart
- Multi-step forms
- Flash messages

---

### $\_COOKIE - Cookie Data

```php
// Set cookie (before any output)
setcookie('username', 'John', time() + 86400, '/'); // 1 day

// Get cookie
$username = $_COOKIE['username'];

// Check if exists
if (isset($_COOKIE['username'])) {
    echo "Welcome back " . $_COOKIE['username'];
}

// Delete cookie
setcookie('username', '', time() - 3600, '/');
```

---

## 3. Form Data Handling Methods {#form-data-handling}

### Checking if Data Exists

```php
// Method 1: isset() - Check if variable exists and not NULL
if (isset($_POST['username'])) {
    // Variable exists
}

// Method 2: empty() - Check if empty (0, "", NULL, FALSE, [])
if (!empty($_POST['username'])) {
    // Has a value
}

// Method 3: array_key_exists() - Check if key exists (even if NULL)
if (array_key_exists('username', $_POST)) {
    // Key exists
}
```

**Comparison:**

```php
$_POST['username'] = "";

isset($_POST['username']);           // TRUE
empty($_POST['username']);           // TRUE
array_key_exists('username', $_POST); // TRUE

// Unset variable
unset($_POST['username']);

isset($_POST['username']);           // FALSE
empty($_POST['username']);           // TRUE
array_key_exists('username', $_POST); // FALSE
```

### Getting Data with Default Values

```php
// Ternary operator
$username = isset($_POST['username']) ? $_POST['username'] : 'Guest';

// Null coalescing operator (PHP 7+) - RECOMMENDED
$username = $_POST['username'] ?? 'Guest';

// Multiple fallbacks
$value = $_POST['value'] ?? $_GET['value'] ?? 'default';
```

---

## 4. Validation Methods {#validation-methods}

### Built-in Validation Functions

#### filter_var() - Versatile Validation

```php
// Email validation
$email = "test@example.com";
if (filter_var($email, FILTER_VALIDATE_EMAIL)) {
    echo "Valid email";
} else {
    echo "Invalid email";
}

// URL validation
$url = "https://example.com";
if (filter_var($url, FILTER_VALIDATE_URL)) {
    echo "Valid URL";
}

// Integer validation
$age = "25";
if (filter_var($age, FILTER_VALIDATE_INT)) {
    echo "Valid integer";
}

// Integer with range
$age = filter_var($age, FILTER_VALIDATE_INT, [
    'options' => ['min_range' => 18, 'max_range' => 100]
]);

if ($age !== false) {
    echo "Valid age: $age";
}

// Float validation
$price = "19.99";
if (filter_var($price, FILTER_VALIDATE_FLOAT)) {
    echo "Valid price";
}

// IP address validation
$ip = "192.168.1.1";
if (filter_var($ip, FILTER_VALIDATE_IP)) {
    echo "Valid IP";
}

// Boolean validation
$active = "true";
$bool = filter_var($active, FILTER_VALIDATE_BOOLEAN, FILTER_NULL_ON_FAILURE);

// MAC address
if (filter_var($mac, FILTER_VALIDATE_MAC)) {
    echo "Valid MAC address";
}
```

**All FILTER*VALIDATE*\* Constants:**

- `FILTER_VALIDATE_BOOLEAN`
- `FILTER_VALIDATE_EMAIL`
- `FILTER_VALIDATE_FLOAT`
- `FILTER_VALIDATE_INT`
- `FILTER_VALIDATE_IP`
- `FILTER_VALIDATE_MAC`
- `FILTER_VALIDATE_REGEXP`
- `FILTER_VALIDATE_URL`

---

#### String Validation Functions

```php
// Check if empty
if (empty($username)) {
    echo "Username is required";
}

// String length
$password = "mypass";
if (strlen($password) < 8) {
    echo "Password must be at least 8 characters";
}

// Check if numeric
if (is_numeric($age)) {
    echo "Age is numeric";
}

// Check if integer
if (is_int($value)) {
    echo "Is integer";
}

// Check if string
if (is_string($name)) {
    echo "Is string";
}

// Check if array
if (is_array($hobbies)) {
    echo "Is array";
}
```

---

#### Regular Expression Validation

```php
// preg_match() - Pattern matching

// Letters only
if (preg_match("/^[a-zA-Z]+$/", $name)) {
    echo "Valid name (letters only)";
}

// Letters and spaces
if (preg_match("/^[a-zA-Z ]+$/", $name)) {
    echo "Valid name";
}

// Alphanumeric
if (preg_match("/^[a-zA-Z0-9]+$/", $username)) {
    echo "Valid username";
}

// Phone number (10 digits)
if (preg_match("/^[0-9]{10}$/", $phone)) {
    echo "Valid phone";
}

// Strong password (min 8 chars, 1 upper, 1 lower, 1 number)
$pattern = "/^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,}$/";
if (preg_match($pattern, $password)) {
    echo "Strong password";
}

// Date format (YYYY-MM-DD)
if (preg_match("/^\d{4}-\d{2}-\d{2}$/", $date)) {
    echo "Valid date format";
}

// Postal code (India)
if (preg_match("/^[1-9][0-9]{5}$/", $pincode)) {
    echo "Valid pincode";
}
```

**Common Regex Patterns:**

```php
$patterns = [
    'email'     => '/^[\w\.-]+@[\w\.-]+\.\w+$/',
    'phone'     => '/^[0-9]{10}$/',
    'url'       => '/^https?:\/\/[\w\-]+(\.[\w\-]+)+[/#?]?.*$/',
    'username'  => '/^[a-zA-Z0-9_]{3,20}$/',
    'password'  => '/^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/',
    'letters'   => '/^[a-zA-Z ]+$/',
    'numbers'   => '/^[0-9]+$/',
    'alphanumeric' => '/^[a-zA-Z0-9]+$/',
];
```

---

#### Date Validation

```php
// Check date format and validity
function validateDate($date, $format = 'Y-m-d') {
    $d = DateTime::createFromFormat($format, $date);
    return $d && $d->format($format) === $date;
}

if (validateDate('2024-12-31')) {
    echo "Valid date";
}

// Check age (18+)
$dob = '2000-01-01';
$age = date_diff(date_create($dob), date_create('now'))->y;
if ($age >= 18) {
    echo "Age is valid";
}

// Check if date is in past
$date = strtotime($input_date);
if ($date < time()) {
    echo "Date is in the past";
}
```

---

### Custom Validation Functions

```php
// Username validation
function validateUsername($username) {
    if (empty($username)) {
        return "Username is required";
    }
    if (strlen($username) < 3) {
        return "Username must be at least 3 characters";
    }
    if (!preg_match("/^[a-zA-Z0-9_]+$/", $username)) {
        return "Username can only contain letters, numbers, and underscore";
    }
    return true;
}

// Email validation
function validateEmail($email) {
    if (empty($email)) {
        return "Email is required";
    }
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        return "Invalid email format";
    }
    return true;
}

// Password validation
function validatePassword($password) {
    if (empty($password)) {
        return "Password is required";
    }
    if (strlen($password) < 8) {
        return "Password must be at least 8 characters";
    }
    if (!preg_match("/[A-Z]/", $password)) {
        return "Password must contain at least one uppercase letter";
    }
    if (!preg_match("/[a-z]/", $password)) {
        return "Password must contain at least one lowercase letter";
    }
    if (!preg_match("/[0-9]/", $password)) {
        return "Password must contain at least one number";
    }
    return true;
}

// Usage
$errors = [];
$result = validateUsername($_POST['username']);
if ($result !== true) {
    $errors['username'] = $result;
}
```

---

## 5. Sanitization Methods {#sanitization-methods}

### Why Sanitize?

- Remove dangerous characters
- Prevent XSS attacks
- Prevent SQL injection
- Clean user input

### filter_var() - Sanitization

```php
// Sanitize string (remove tags)
$clean = filter_var($input, FILTER_SANITIZE_STRING);

// Sanitize email
$email = filter_var($email, FILTER_SANITIZE_EMAIL);

// Sanitize URL
$url = filter_var($url, FILTER_SANITIZE_URL);

// Sanitize integer
$number = filter_var($input, FILTER_SANITIZE_NUMBER_INT);

// Sanitize float
$price = filter_var($input, FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);

// Remove all HTML tags
$clean = filter_var($input, FILTER_SANITIZE_STRIPPED);

// Encode special HTML characters
$clean = filter_var($input, FILTER_SANITIZE_SPECIAL_CHARS);
```

**All FILTER*SANITIZE*\* Constants:**

- `FILTER_SANITIZE_EMAIL`
- `FILTER_SANITIZE_ENCODED`
- `FILTER_SANITIZE_NUMBER_FLOAT`
- `FILTER_SANITIZE_NUMBER_INT`
- `FILTER_SANITIZE_SPECIAL_CHARS`
- `FILTER_SANITIZE_STRING` (deprecated PHP 8.1+)
- `FILTER_SANITIZE_STRIPPED` (alias of STRING)
- `FILTER_SANITIZE_URL`

---

### htmlspecialchars() - XSS Prevention

```php
// Convert special characters to HTML entities
$safe = htmlspecialchars($input, ENT_QUOTES, 'UTF-8');

// Example:
$input = "<script>alert('XSS')</script>";
$safe = htmlspecialchars($input, ENT_QUOTES, 'UTF-8');
echo $safe; // &lt;script&gt;alert('XSS')&lt;/script&gt;

// Flags:
// ENT_QUOTES - Convert both single and double quotes
// ENT_NOQUOTES - Don't convert quotes
// ENT_HTML5 - Handle as HTML5
```

**When to Use:**

- Before displaying user input in HTML
- Displaying data from database
- Preventing XSS attacks

---

### htmlentities() - Convert All Characters

```php
// Convert all applicable characters to HTML entities
$safe = htmlentities($input, ENT_QUOTES, 'UTF-8');

// Difference from htmlspecialchars:
// htmlspecialchars: converts <, >, &, ", '
// htmlentities: converts ALL characters that have HTML entity equivalents
```

---

### strip_tags() - Remove HTML/PHP Tags

```php
// Remove all HTML and PHP tags
$clean = strip_tags($input);

// Allow specific tags
$clean = strip_tags($input, '<p><a><strong>');

// Example:
$input = "<p>Hello <script>alert('XSS')</script> World</p>";
$clean = strip_tags($input);
echo $clean; // Hello  World

$clean = strip_tags($input, '<p>');
echo $clean; // <p>Hello  World</p>
```

**When to Use:**

- Cleaning rich text input
- Removing unwanted HTML
- Blog comments

**When NOT to Use:**

- If you need some HTML (use whitelist instead)
- Alone for XSS prevention (use with htmlspecialchars)

---

### trim() - Remove Whitespace

```php
// Remove whitespace from both sides
$clean = trim($input);

// Remove specific characters
$clean = trim($input, " \t\n");

// Remove from left only
$clean = ltrim($input);

// Remove from right only
$clean = rtrim($input);

// Example:
$input = "  hello world  ";
$clean = trim($input);
echo "'$clean'"; // 'hello world'
```

---

### addslashes() / stripslashes()

```php
// Add slashes before quotes (OLD METHOD - DON'T USE)
$escaped = addslashes($input);

// Remove slashes
$original = stripslashes($escaped);
```

**⚠️ WARNING:** Don't use `addslashes()` for database queries!
Use prepared statements instead.

---

### mysqli_real_escape_string() - SQL Escaping

```php
// Escape special characters for SQL (OLD METHOD)
$safe = $conn->real_escape_string($input);

$query = "SELECT * FROM users WHERE name = '$safe'";
```

**⚠️ WARNING:** Still vulnerable! Use prepared statements instead.

**When to Use:**

- Legacy code maintenance
- When prepared statements not available

**When NOT to Use:**

- New projects (use prepared statements)

---

### Complete Sanitization Function

```php
function sanitizeInput($data) {
    $data = trim($data);                              // Remove whitespace
    $data = stripslashes($data);                      // Remove slashes
    $data = htmlspecialchars($data, ENT_QUOTES, 'UTF-8'); // Convert special chars
    return $data;
}

// Usage
$username = sanitizeInput($_POST['username']);
```

---

### Sanitization by Input Type

```php
// Text input
function sanitizeText($input) {
    return htmlspecialchars(trim($input), ENT_QUOTES, 'UTF-8');
}

// Email
function sanitizeEmail($email) {
    return filter_var(trim($email), FILTER_SANITIZE_EMAIL);
}

// Integer
function sanitizeInt($input) {
    return filter_var($input, FILTER_SANITIZE_NUMBER_INT);
}

// Float
function sanitizeFloat($input) {
    return filter_var($input, FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
}

// URL
function sanitizeURL($url) {
    return filter_var(trim($url), FILTER_SANITIZE_URL);
}

// Remove all HTML
function sanitizeHTML($input) {
    return strip_tags($input);
}
```

---

## 6. Database Connection {#database-connection}

### MySQLi Connection (Recommended)

```php
<?php
// Connection parameters
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "mydb";
$port = 3306;

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname, $port);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Set charset (IMPORTANT for security)
$conn->set_charset("utf8mb4");

echo "Connected successfully";

// Close connection
$conn->close();
?>
```

---

### PDO Connection (Alternative)

```php
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "mydb";

try {
    // Create connection
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);

    // Set error mode
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Set charset
    $conn->exec("set names utf8mb4");

    echo "Connected successfully";

} catch(PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}

// Close connection
$conn = null;
?>
```

---

### Connection with Error Handling

```php
<?php
// Configuration
define('DB_SERVER', 'localhost');
define('DB_USERNAME', 'root');
define('DB_PASSWORD', '');
define('DB_NAME', 'mydb');
define('DB_PORT', 3306);

// Enable mysqli error reporting
mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);

try {
    // Create connection
    $conn = new mysqli(DB_SERVER, DB_USERNAME, DB_PASSWORD, DB_NAME, DB_PORT);

    // Set charset
    $conn->set_charset("utf8mb4");

    echo "✅ Connected successfully<br>";
    echo "Server: " . $conn->server_info . "<br>";
    echo "Host: " . $conn->host_info . "<br>";

} catch (mysqli_sql_exception $e) {
    // Log error (don't show to users in production)
    error_log("Database Error: " . $e->getMessage());

    // Show user-friendly message
    die("❌ Unable to connect to database. Please try again later.");
}
?>
```

---

### Connection Options & Settings

```php
// Set connection timeout
$conn->options(MYSQLI_OPT_CONNECT_TIMEOUT, 5);

// Enable/disable autocommit
$conn->autocommit(FALSE);

// Set character set
$conn->set_charset("utf8mb4");

// Change database
$conn->select_db("another_db");

// Get connection info
echo "Thread ID: " . $conn->thread_id . "<br>";
echo "Server info: " . $conn->server_info . "<br>";
echo "Host info: " . $conn->host_info . "<br>";
echo "Protocol: " . $conn->protocol_version . "<br>";

// Check if connection is alive
if ($conn->ping()) {
    echo "Connection is active";
}
```

---

### Connection Best Practices

```php
// 1. Store in separate config file
// config.php
<?php
return [
    'host' => 'localhost',
    'username' => 'root',
    'password' => '',
    'database' => 'mydb',
    'port' => 3306,
    'charset' => 'utf8mb4'
];

// main.php
$config = require 'config.php';
$conn = new mysqli(
    $config['host'],
    $config['username'],
    $config['password'],
    $config['database'],
    $config['port']
);
$conn->set_charset($config['charset']);

// 2. Use environment variables (production)
$conn = new mysqli(
    getenv('DB_HOST'),
    getenv('DB_USER'),
    getenv('DB_PASS'),
    getenv('DB_NAME')
);

// 3. Create reusable connection function
function getDBConnection() {
    static $conn = null;

    if ($conn === null) {
        $conn = new mysqli('localhost', 'root', '', 'mydb');
        if ($conn->connect_error) {
            throw new Exception("Connection failed");
        }
        $conn->set_charset("utf8mb4");
    }

    return $conn;
}

// Usage
$conn = getDBConnection();
```

---

## 7. MySQLi Methods Reference {#mysqli-methods}

### Connection Methods

| Method          | Description               | Returns       | Example                                               |
| --------------- | ------------------------- | ------------- | ----------------------------------------------------- |
| `new mysqli()`  | Create connection         | mysqli object | `$conn = new mysqli($host, $user, $pass, $db, $port)` |
| `connect_error` | Connection error message  | string/null   | `$conn->connect_error`                                |
| `connect_errno` | Connection error number   | int           | `$conn->connect_errno`                                |
| `close()`       | Close connection          | bool          | `$conn->close()`                                      |
| `ping()`        | Check if connection alive | bool          | `$conn->ping()`                                       |
| `select_db()`   | Change database           | bool          | `$conn->select_db("newdb")`                           |
| `set_charset()` | Set character set         | bool          | `$conn->set_charset("utf8mb4")`                       |

---

### Query Execution Methods

| Method          | Description               | Use Case               | Example                                                      |
| --------------- | ------------------------- | ---------------------- | ------------------------------------------------------------ |
| `query()`       | Execute SQL query         | Simple queries         | `$conn->query("SELECT * FROM users")`                        |
| `multi_query()` | Execute multiple queries  | Batch operations       | `$conn->multi_query("Q1; Q2; Q3")`                           |
| `prepare()`     | Create prepared statement | Secure queries         | `$stmt = $conn->prepare("SELECT * FROM users WHERE id = ?")` |
| `real_query()`  | Execute query (no result) | When result not needed | `$conn->real_query("UPDATE users SET ...")`                  |

**When to Use:**

- `query()`: Simple SELECT, one-time queries
- `prepare()`: When using user input (ALWAYS)
- `multi_query()`: Running SQL scripts, batch operations

---

### Prepared Statement Methods

| Method           | Description                   | Parameters    | Example                                                                   |
| ---------------- | ----------------------------- | ------------- | ------------------------------------------------------------------------- |
| `prepare()`      | Prepare SQL with placeholders | SQL string    | `$stmt = $conn->prepare("INSERT INTO users (name, email) VALUES (?, ?)")` |
| `bind_param()`   | Bind values to placeholders   | types, values | `$stmt->bind_param("ss", $name, $email)`                                  |
| `execute()`      | Execute prepared statement    | none          | `$stmt->execute()`                                                        |
| `get_result()`   | Get result set                | none          | `$result = $stmt->get_result()`                                           |
| `store_result()` | Store result in memory        | none          | `$stmt->store_result()`                                                   |
| `fetch()`        | Fetch single row              | none          | `$stmt->fetch()`                                                          |
| `bind_result()`  | Bind result to variables      | variables     | `$stmt->bind_result($id, $name)`                                          |
| `close()`        | Close statement               | none          | `$stmt->close()`                                                          |

**bind_param() Type Codes:**

- `s` = string
- `i` = integer
- `d` = double/float
- `b` = blob (binary)

```php
// Examples
$stmt->bind_param("s", $name);              // One string
$stmt->bind_param("si", $name, $age);       // String + integer
$stmt->bind_param("ssd", $name, $email, $salary); // 2 strings + double
```

---

### Result Methods

| Method           | Description                    | Returns     | Example                                    |
| ---------------- | ------------------------------ | ----------- | ------------------------------------------ |
| `fetch_assoc()`  | Fetch row as associative array | array/null  | `$row = $result->fetch_assoc()`            |
| `fetch_row()`    | Fetch row as numeric array     | array/null  | `$row = $result->fetch_row()`              |
| `fetch_array()`  | Fetch as both assoc & numeric  | array/null  | `$row = $result->fetch_array()`            |
| `fetch_object()` | Fetch row as object            | object/null | `$row = $result->fetch_object()`           |
| `fetch_all()`    | Fetch all rows at once         | array       | `$rows = $result->fetch_all(MYSQLI_ASSOC)` |
| `num_rows`       | Number of rows                 | int         | `$result->num_rows`                        |
| `free()`         | Free result memory             | void        | `$result->free()`                          |
| `close()`        | Close result                   | void        | `$result->close()`                         |

**Fetch Examples:**

```php
// fetch_assoc() - Most common
$result = $conn->query("SELECT id, name, email FROM users");
while ($row = $result->fetch_assoc()) {
    echo $row['id'] . " - " . $row['name'] . "<br>";
}

// fetch_row() - Numeric index
$row = $result->fetch_row();
echo $row[0] . " - " . $row[1]; // id - name

// fetch_object() - Object properties
$row = $result->fetch_object();
echo $row->id . " - " . $row->name;

// fetch_all() - Get everything at once
$rows = $result->fetch_all(MYSQLI_ASSOC);
foreach ($rows as $row) {
    echo $row['name'] . "<br>";
}
```

---

### Transaction Methods

| Method                | Description                | Use Case                   | Example                      |
| --------------------- | -------------------------- | -------------------------- | ---------------------------- |
| `begin_transaction()` | Start transaction          | Multiple related queries   | `$conn->begin_transaction()` |
| `commit()`            | Save all changes           | Transaction successful     | `$conn->commit()`            |
| `rollback()`          | Undo all changes           | Transaction failed         | `$conn->rollback()`          |
| `autocommit()`        | Enable/disable auto-commit | Manual transaction control | `$conn->autocommit(FALSE)`   |

**Transaction Example:**

```php
$conn->begin_transaction();

try {
    // Transfer money between accounts
    $conn->query("UPDATE accounts SET balance = balance - 100 WHERE id = 1");
    $conn->query("UPDATE accounts SET balance = balance + 100 WHERE id = 2");

    // If both succeed, commit
    $conn->commit();
    echo "Transfer successful!";

} catch (Exception $e) {
    // If any fails, rollback
    $conn->rollback();
    echo "Transfer failed: " . $e->getMessage();
}
```

**When to Use Transactions:**

- Banking operations
- Order processing
- Multi-table updates
- Data consistency required

---

### Information Methods

| Property/Method        | Description                | Returns | Example                            |
| ---------------------- | -------------------------- | ------- | ---------------------------------- |
| `insert_id`            | Last AUTO_INCREMENT ID     | int     | `echo $conn->insert_id`            |
| `affected_rows`        | Rows changed by last query | int     | `echo $conn->affected_rows`        |
| `error`                | Last error message         | string  | `echo $conn->error`                |
| `errno`                | Last error number          | int     | `echo $conn->errno`                |
| `info`                 | Info about last query      | string  | `echo $conn->info`                 |
| `warning_count`        | Number of warnings         | int     | `echo $conn->warning_count`        |
| `stat()`               | Server statistics          | string  | `echo $conn->stat()`               |
| `thread_id`            | Connection thread ID       | int     | `echo $conn->thread_id`            |
| `server_info`          | Server version             | string  | `echo $conn->server_info`          |
| `host_info`            | Host information           | string  | `echo $conn->host_info`            |
| `protocol_version`     | Protocol version           | int     | `echo $conn->protocol_version`     |
| `character_set_name()` | Current charset            | string  | `echo $conn->character_set_name()` |

---

### Security Methods

| Method                 | Description                   | Use Case         | Example                                     |
| ---------------------- | ----------------------------- | ---------------- | ------------------------------------------- |
| `real_escape_string()` | Escape special SQL characters | Legacy code only | `$safe = $conn->real_escape_string($input)` |

**⚠️ WARNING:** Don't use for new code! Use prepared statements instead.

---

## 8. Prepared Statements (CRITICAL) {#prepared-statements}

### Why Use Prepared Statements?

**❌ Without Prepared Statements (VULNERABLE):**

```php
$username = $_POST['username']; // User input: admin' OR '1'='1
$password = $_POST['password'];

$query = "SELECT * FROM users WHERE username = '$username' AND password = '$password'";
$result = $conn->query($query);

// SQL becomes: SELECT * FROM users WHERE username = 'admin' OR '1'='1' AND password = ''
// Returns all users! 🚨 SQL INJECTION
```

**✅ With Prepared Statements (SECURE):**

```php
$stmt = $conn->prepare("SELECT * FROM users WHERE username = ? AND password = ?");
$stmt->bind_param("ss", $username, $password);
$stmt->execute();

// Input treated as DATA, not SQL code! ✨ SAFE
```

---

### Prepared Statement Complete Guide

#### INSERT Example

```php
// Prepare
$stmt = $conn->prepare("INSERT INTO users (name, email, age) VALUES (?, ?, ?)");

// Bind parameters
$stmt->bind_param("ssi", $name, $email, $age);

// Set values
$name = "John Doe";
$email = "john@example.com";
$age = 25;

// Execute
if ($stmt->execute()) {
    echo "New record created successfully";
    echo "New user ID: " . $stmt->insert_id;
} else {
    echo "Error: " . $stmt->error;
}

$stmt->close();
```

---

#### SELECT Example

```php
// Prepare
$stmt = $conn->prepare("SELECT id, name, email FROM users WHERE age > ?");

// Bind parameter
$stmt->bind_param("i", $min_age);

// Set value
$min_age = 18;

// Execute
$stmt->execute();

// Get result
$result = $stmt->get_result();

// Fetch rows
while ($row = $result->fetch_assoc()) {
    echo $row['id'] . " - " . $row['name'] . " - " . $row['email'] . "<br>";
}

$stmt->close();
```

---

#### UPDATE Example

```php
// Prepare
$stmt = $conn->prepare("UPDATE users SET email = ?, age = ? WHERE id = ?");

// Bind parameters
$stmt->bind_param("sii", $email, $age, $user_id);

// Set values
$email = "newemail@example.com";
$age = 30;
$user_id = 5;

// Execute
if ($stmt->execute()) {
    echo "Record updated successfully";
    echo "Rows affected: " . $stmt->affected_rows;
} else {
    echo "Error: " . $stmt->error;
}

$stmt->close();
```

---

#### DELETE Example

```php
// Prepare
$stmt = $conn->prepare("DELETE FROM users WHERE id = ?");

// Bind parameter
$stmt->bind_param("i", $user_id);

// Set value
$user_id = 5;

// Execute
if ($stmt->execute()) {
    echo "Record deleted successfully";
    echo "Rows affected: " . $stmt->affected_rows;
} else {
    echo "Error: " . $stmt->error;
}

$stmt->close();
```

---

#### Multiple Inserts (Loop)

```php
$stmt = $conn->prepare("INSERT INTO users (name, email) VALUES (?, ?)");
$stmt->bind_param("ss", $name, $email);

$users = [
    ['John Doe', 'john@example.com'],
    ['Jane Smith', 'jane@example.com'],
    ['Bob Wilson', 'bob@example.com']
];

foreach ($users as $user) {
    $name = $user[0];
    $email = $user[1];
    $stmt->execute();
}

echo "Total inserted: " . $stmt->affected_rows;
$stmt->close();
```

---

#### Checking if Record Exists

```php
$stmt = $conn->prepare("SELECT id FROM users WHERE email = ?");
$stmt->bind_param("s", $email);
$email = "test@example.com";
$stmt->execute();
$stmt->store_result();

if ($stmt->num_rows > 0) {
    echo "Email already exists";
} else {
    echo "Email available";
}

$stmt->close();
```

---

### bind_result() Alternative Method

```php
// Prepare
$stmt = $conn->prepare("SELECT id, name, email FROM users WHERE age > ?");

// Bind parameter
$stmt->bind_param("i", $min_age);
$min_age = 18;

// Execute
$stmt->execute();

// Bind result to variables
$stmt->bind_result($id, $name, $email);

// Fetch rows
while ($stmt->fetch()) {
    echo "$id - $name - $email<br>";
}

$stmt->close();
```

**When to Use:**

- `get_result()` + `fetch_assoc()`: More flexible (recommended)
- `bind_result()` + `fetch()`: Slightly faster, less flexible

---

## 9. File Upload Handling {#file-uploads}

### Complete File Upload Example

```php
<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_FILES['avatar'])) {

    $file = $_FILES['avatar'];

    // File properties
    $filename = $file['name'];           // original.jpg
    $file_tmp = $file['tmp_name'];       // /tmp/phpXXXXXX
    $file_size = $file['size'];          // 50000 (bytes)
    $file_error = $file['error'];        // 0 if no error
    $file_type = $file['type'];          // image/jpeg

    // 1. Check for upload errors
    if ($file_error !== UPLOAD_ERR_OK) {
        die("Upload error code: $file_error");
    }

    // 2. Validate file size (2MB max)
    $max_size = 2 * 1024 * 1024; // 2MB in bytes
    if ($file_size > $max_size) {
        die("File too large. Max 2MB allowed.");
    }

    // 3. Validate file type using MIME type
    $allowed_types = ['image/jpeg', 'image/jpg', 'image/png', 'image/gif'];
    $finfo = finfo_open(FILEINFO_MIME_TYPE);
    $mime_type = finfo_file($finfo, $file_tmp);
    finfo_close($finfo);

    if (!in_array($mime_type, $allowed_types)) {
        die("Invalid file type. Only JPG, PNG, GIF allowed.");
    }

    // 4. Validate file extension
    $file_ext = strtolower(pathinfo($filename, PATHINFO_EXTENSION));
    $allowed_ext = ['jpg', 'jpeg', 'png', 'gif'];

    if (!in_array($file_ext, $allowed_ext)) {
        die("Invalid file extension.");
    }

    // 5. Generate unique filename
    $new_filename = uniqid() . '_' . time() . '.' . $file_ext;

    // 6. Set upload directory
    $upload_dir = 'uploads/';
    if (!is_dir($upload_dir)) {
        mkdir($upload_dir, 0755, true);
    }

    // 7. Full upload path
    $upload_path = $upload_dir . $new_filename;

    // 8. Move uploaded file
    if (move_uploaded_file($file_tmp, $upload_path)) {
        echo "File uploaded successfully: $upload_path";

        // 9. Save to database
        $stmt = $conn->prepare("INSERT INTO users (avatar) VALUES (?)");
        $stmt->bind_param("s", $upload_path);
        $stmt->execute();

    } else {
        die("Failed to move uploaded file.");
    }
}
?>
```

---

### File Upload Error Codes

| Error Code | Constant                | Meaning                      |
| ---------- | ----------------------- | ---------------------------- |
| 0          | `UPLOAD_ERR_OK`         | Success                      |
| 1          | `UPLOAD_ERR_INI_SIZE`   | File exceeds php.ini limit   |
| 2          | `UPLOAD_ERR_FORM_SIZE`  | File exceeds HTML form limit |
| 3          | `UPLOAD_ERR_PARTIAL`    | File partially uploaded      |
| 4          | `UPLOAD_ERR_NO_FILE`    | No file uploaded             |
| 6          | `UPLOAD_ERR_NO_TMP_DIR` | Missing temp folder          |
| 7          | `UPLOAD_ERR_CANT_WRITE` | Failed to write to disk      |
| 8          | `UPLOAD_ERR_EXTENSION`  | PHP extension stopped upload |

```php
// Handle errors
switch ($file_error) {
    case UPLOAD_ERR_OK:
        break;
    case UPLOAD_ERR_INI_SIZE:
    case UPLOAD_ERR_FORM_SIZE:
        die("File too large");
    case UPLOAD_ERR_PARTIAL:
        die("File only partially uploaded");
    case UPLOAD_ERR_NO_FILE:
        die("No file uploaded");
    default:
        die("Upload error");
}
```

---

### File Validation Functions

```php
// Get file extension
$ext = pathinfo($filename, PATHINFO_EXTENSION);
$ext = strtolower($ext);

// Get filename without extension
$name = pathinfo($filename, PATHINFO_FILENAME);

// Get MIME type
$finfo = finfo_open(FILEINFO_MIME_TYPE);
$mime = finfo_file($finfo, $file_tmp);
finfo_close($finfo);

// Check if image
if (getimagesize($file_tmp) !== false) {
    echo "File is an image";
}

// Get image dimensions
list($width, $height) = getimagesize($file_tmp);
echo "Dimensions: {$width}x{$height}";

// File exists check
if (file_exists($upload_path)) {
    die("File already exists");
}
```

---

### Multiple File Upload

```php
<form method="POST" enctype="multipart/form-data">
    <input type="file" name="files[]" multiple>
    <button type="submit">Upload</button>
</form>

<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $files = $_FILES['files'];

    $total = count($files['name']);

    for ($i = 0; $i < $total; $i++) {
        $filename = $files['name'][$i];
        $file_tmp = $files['tmp_name'][$i];
        $file_size = $files['size'][$i];
        $file_error = $files['error'][$i];

        if ($file_error == 0) {
            // Process each file
            $upload_path = "uploads/" . $filename;
            move_uploaded_file($file_tmp, $upload_path);
            echo "Uploaded: $filename<br>";
        }
    }
}
?>
```

---

### Image Resizing (Optional)

```php
function resizeImage($source, $destination, $max_width, $max_height) {
    list($width, $height, $type) = getimagesize($source);

    // Calculate new dimensions
    $ratio = min($max_width / $width, $max_height / $height);
    $new_width = $width * $ratio;
    $new_height = $height * $ratio;

    // Create image resource
    switch ($type) {
        case IMAGETYPE_JPEG:
            $image = imagecreatefromjpeg($source);
            break;
        case IMAGETYPE_PNG:
            $image = imagecreatefrompng($source);
            break;
        case IMAGETYPE_GIF:
            $image = imagecreatefromgif($source);
            break;
        default:
            return false;
    }

    // Create new image
    $new_image = imagecreatetruecolor($new_width, $new_height);
    imagecopyresampled($new_image, $image, 0, 0, 0, 0, $new_width, $new_height, $width, $height);

    // Save resized image
    imagejpeg($new_image, $destination, 90);

    // Free memory
    imagedestroy($image);
    imagedestroy($new_image);

    return true;
}

// Usage
resizeImage($file_tmp, 'uploads/thumb_' . $filename, 300, 300);
```

---

## 10. Security Best Practices {#security}

### 1. SQL Injection Prevention

```php
// ❌ NEVER DO THIS
$id = $_GET['id'];
$query = "SELECT * FROM users WHERE id = $id";
$result = $conn->query($query);

// ✅ ALWAYS DO THIS
$stmt = $conn->prepare("SELECT * FROM users WHERE id = ?");
$stmt->bind_param("i", $id);
$stmt->execute();
$result = $stmt->get_result();
```

**Rules:**

- ALWAYS use prepared statements for user input
- NEVER concatenate user input into SQL
- NEVER trust any user input

---

### 2. XSS (Cross-Site Scripting) Prevention

```php
// ❌ VULNERABLE
$name = $_POST['name'];
echo "Hello " . $name; // <script>alert('XSS')</script>

// ✅ SAFE
$name = htmlspecialchars($_POST['name'], ENT_QUOTES, 'UTF-8');
echo "Hello " . $name; // &lt;script&gt;alert('XSS')&lt;/script&gt;
```

**Rules:**

- ALWAYS use `htmlspecialchars()` when displaying user input
- Use `ENT_QUOTES` flag
- Specify UTF-8 encoding

---

### 3. CSRF (Cross-Site Request Forgery) Prevention

```php
// Generate token
session_start();
if (empty($_SESSION['csrf_token'])) {
    $_SESSION['csrf_token'] = bin2hex(random_bytes(32));
}

// In form
<input type="hidden" name="csrf_token" value="<?php echo $_SESSION['csrf_token']; ?>">

// Validate token
if ($_POST['csrf_token'] !== $_SESSION['csrf_token']) {
    die("CSRF token validation failed");
}
```

---

### 4. Password Security

```php
// ❌ NEVER store plain passwords
$conn->query("INSERT INTO users (password) VALUES ('$password')");

// ✅ ALWAYS hash passwords
$hashed = password_hash($password, PASSWORD_DEFAULT);
$stmt = $conn->prepare("INSERT INTO users (password) VALUES (?)");
$stmt->bind_param("s", $hashed);
$stmt->execute();

// Verify password
$stmt = $conn->prepare("SELECT password FROM users WHERE email = ?");
$stmt->bind_param("s", $email);
$stmt->execute();
$result = $stmt->get_result();
$user = $result->fetch_assoc();

if (password_verify($password, $user['password'])) {
    echo "Login successful";
} else {
    echo "Invalid password";
}
```

---

### 5. File Upload Security

```php
// 1. Validate MIME type (not extension!)
$finfo = finfo_open(FILEINFO_MIME_TYPE);
$mime = finfo_file($finfo, $file_tmp);
finfo_close($finfo);

// 2. Whitelist allowed types
$allowed = ['image/jpeg', 'image/png', 'image/gif'];
if (!in_array($mime, $allowed)) {
    die("Invalid file type");
}

// 3. Generate unique filename (prevent overwriting)
$new_name = uniqid() . '_' . time() . '.' . $ext;

// 4. Store outside web root (if possible)
$upload_dir = '/var/www/uploads/'; // Outside public_html

// 5. Limit file size
if ($file_size > 2 * 1024 * 1024) {
    die("File too large");
}
```

---

### 6. Session Security

```php
// Start session securely
session_start([
    'cookie_lifetime' => 0,
    'cookie_httponly' => true,
    'cookie_secure' => true,    // HTTPS only
    'cookie_samesite' => 'Strict'
]);

// Regenerate session ID after login
session_regenerate_id(true);

// Logout
session_unset();
session_destroy();
```

---

### 7. Input Validation Checklist

```php
// Always validate:
// ✅ Data type (int, string, email)
// ✅ Length (min/max)
// ✅ Format (regex patterns)
// ✅ Range (min/max values)
// ✅ Required fields

$errors = [];

// Required
if (empty($_POST['email'])) {
    $errors['email'] = "Email is required";
}

// Format
if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    $errors['email'] = "Invalid email format";
}

// Length
if (strlen($password) < 8) {
    $errors['password'] = "Password must be 8+ characters";
}

// Range
if ($age < 18 || $age > 100) {
    $errors['age'] = "Age must be between 18-100";
}
```

---

### 8. Error Handling (Production)

```php
// ❌ DON'T show detailed errors in production
die("Database error: " . $conn->error);

// ✅ Log errors, show generic message
error_log("Database error: " . $conn->error);
die("An error occurred. Please try again later.");

// Set error reporting
// Development
error_reporting(E_ALL);
ini_set('display_errors', 1);

// Production
error_reporting(0);
ini_set('display_errors', 0);
ini_set('log_errors', 1);
ini_set('error_log', '/var/log/php_errors.log');
```

---

### 9. HTTPS Only

```php
// Force HTTPS
if (empty($_SERVER['HTTPS']) || $_SERVER['HTTPS'] === 'off') {
    $redirect = 'https://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
    header('Location: ' . $redirect);
    exit();
}
```

---

### 10. Rate Limiting

```php
session_start();

// Simple rate limiting
if (!isset($_SESSION['login_attempts'])) {
    $_SESSION['login_attempts'] = 0;
    $_SESSION['last_attempt'] = time();
}

// Check attempts
if ($_SESSION['login_attempts'] >= 5) {
    $time_passed = time() - $_SESSION['last_attempt'];
    if ($time_passed < 300) { // 5 minutes
        die("Too many attempts. Try again in " . (300 - $time_passed) . " seconds.");
    } else {
        $_SESSION['login_attempts'] = 0;
    }
}

// Increment on failed login
if ($login_failed) {
    $_SESSION['login_attempts']++;
    $_SESSION['last_attempt'] = time();
}
```

---

## Complete Form Processing Example

```php
<?php
session_start();

// Database connection
$conn = new mysqli("localhost", "root", "", "mydb");
if ($conn->connect_error) {
    die("Connection failed");
}
$conn->set_charset("utf8mb4");

$errors = [];

if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['submit'])) {

    // CSRF validation
    if ($_POST['csrf_token'] !== $_SESSION['csrf_token']) {
        die("Invalid request");
    }

    // Sanitize and validate
    $name = trim($_POST['name']);
    $name = htmlspecialchars($name, ENT_QUOTES, 'UTF-8');

    if (empty($name)) {
        $errors['name'] = "Name is required";
    } elseif (strlen($name) < 3) {
        $errors['name'] = "Name must be 3+ characters";
    }

    // Email
    $email = filter_var(trim($_POST['email']), FILTER_SANITIZE_EMAIL);
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $errors['email'] = "Invalid email";
    }

    // Password
    $password = $_POST['password'];
    if (strlen($password) < 8) {
        $errors['password'] = "Password must be 8+ characters";
    }
    $hashed_password = password_hash($password, PASSWORD_DEFAULT);

    // If no errors, insert
    if (empty($errors)) {
        $stmt = $conn->prepare("INSERT INTO users (name, email, password) VALUES (?, ?, ?)");
        $stmt->bind_param("sss", $name, $email, $hashed_password);

        if ($stmt->execute()) {
            $_SESSION['success'] = "Registration successful!";
            header("Location: success.php");
            exit();
        } else {
            $errors['database'] = "Registration failed";
        }
        $stmt->close();
    }
}

// Generate CSRF token
if (empty($_SESSION['csrf_token'])) {
    $_SESSION['csrf_token'] = bin2hex(random_bytes(32));
}

$conn->close();
?>
```

---

## Quick Reference Summary

### When to Use What

| Task              | Method               | Example                                         |
| ----------------- | -------------------- | ----------------------------------------------- |
| Get POST data     | `$_POST`             | `$_POST['name']`                                |
| Get GET data      | `$_GET`              | `$_GET['id']`                                   |
| Check if set      | `isset()`            | `isset($_POST['name'])`                         |
| Check if empty    | `empty()`            | `empty($_POST['name'])`                         |
| Default value     | `??`                 | `$_POST['name'] ?? 'default'`                   |
| Validate email    | `filter_var()`       | `filter_var($email, FILTER_VALIDATE_EMAIL)`     |
| Sanitize string   | `htmlspecialchars()` | `htmlspecialchars($input, ENT_QUOTES, 'UTF-8')` |
| Remove whitespace | `trim()`             | `trim($input)`                                  |
| Remove HTML       | `strip_tags()`       | `strip_tags($input)`                            |
| Pattern match     | `preg_match()`       | `preg_match("/^[A-Z]/", $input)`                |
| Database query    | `prepare()`          | `$conn->prepare("SELECT...")`                   |
| Bind parameters   | `bind_param()`       | `$stmt->bind_param("s", $value)`                |
| Get result        | `get_result()`       | `$stmt->get_result()`                           |
| Fetch row         | `fetch_assoc()`      | `$result->fetch_assoc()`                        |
| Hash password     | `password_hash()`    | `password_hash($pass, PASSWORD_DEFAULT)`        |
| Verify password   | `password_verify()`  | `password_verify($pass, $hash)`                 |

---

### Common Mistakes to Avoid

1. ❌ Not using prepared statements
2. ❌ Not sanitizing output with `htmlspecialchars()`
3. ❌ Storing plain text passwords
4. ❌ Not validating file uploads properly
5. ❌ Trusting client-side validation only
6. ❌ Not setting character set (use utf8mb4)
7. ❌ Not checking `isset()` before accessing array keys
8. ❌ Using `mysqli_real_escape_string()` instead of prepared statements
9. ❌ Not implementing CSRF protection
10. ❌ Showing detailed error messages in production

---

## END OF GUIDE

This comprehensive guide covers all essential aspects of PHP form handling, from basic HTML structure to advanced security practices. Always prioritize security and follow best practices!
