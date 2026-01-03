# UNIT 2: Advanced HTML - Complete Notes

## 1. HTML Tables

Tables are used to display data in rows and columns format. Tables are created using `<table>` tag along with several related tags.

### Basic Table Structure:

```html
<table>
    <tr>
        <th>Header 1</th>
        <th>Header 2</th>
    </tr>
    <tr>
        <td>Data 1</td>
        <td>Data 2</td>
    </tr>
</table>
```

### Table Tags:

| Tag | Purpose |
|-----|---------|
| `<table>` | Defines the table |
| `<tr>` | Table Row - creates a row |
| `<th>` | Table Header - bold and centered by default |
| `<td>` | Table Data - regular cell data |
| `<caption>` | Table caption/title |
| `<thead>` | Groups header content |
| `<tbody>` | Groups body content |
| `<tfoot>` | Groups footer content |
| `<col>` | Defines column properties |
| `<colgroup>` | Groups columns for formatting |

---

### Table Tag Attributes:

**Attributes of `<table>` tag:**

**1. `border`**
- Specifies border width in pixels
- Example: `border="1"`
- Value 0 = no border

**2. `width` and `height`**
- Sets table dimensions
- Values in pixels or percentage
- Example: `width="500"` or `width="80%"`

**3. `cellpadding`**
- Space between cell content and cell border
- Example: `cellpadding="10"`

**4. `cellspacing`**
- Space between cells
- Example: `cellspacing="5"`

**5. `align`** (deprecated - use CSS)
- Horizontal alignment: left, center, right
- Example: `align="center"`

**6. `bgcolor`** (deprecated - use CSS)
- Background color of table
- Example: `bgcolor="yellow"`

**7. `background`** (deprecated - use CSS)
- Background image for table
- Example: `background="pattern.jpg"`

**8. `bordercolor`**
- Color of the border
- Example: `bordercolor="blue"`

**9. `frame`**
- Which sides of border to show
- Values: void, above, below, hsides, vsides, lhs, rhs, box, border

**10. `rules`**
- Which internal borders to show
- Values: none, groups, rows, cols, all

---

### Attributes of `<tr>` (Table Row):

- `align` - Horizontal alignment (left, center, right, justify)
- `valign` - Vertical alignment (top, middle, bottom, baseline)
- `bgcolor` - Background color for the row
- `height` - Height of the row

---

### Attributes of `<td>` and `<th>` (Table Data/Header):

**1. `colspan`** - Very Important!
- Merges cells horizontally (across columns)
- Specifies number of columns a cell should span
- Example: `<td colspan="3">Merged Cell</td>`

**2. `rowspan`** - Very Important!
- Merges cells vertically (across rows)
- Specifies number of rows a cell should span
- Example: `<td rowspan="2">Merged Cell</td>`

**3. `width` and `height`**
- Sets cell dimensions
- Example: `width="150"`

**4. `align`**
- Horizontal alignment
- Values: left, center, right, justify

**5. `valign`**
- Vertical alignment
- Values: top, middle, bottom, baseline

**6. `bgcolor`**
- Background color
- Example: `bgcolor="#ff0000"`

**7. `nowrap`**
- Prevents text wrapping
- Example: `nowrap="nowrap"`

---

### Complete Table Example:

```html
<!DOCTYPE html>
<html>
<head>
    <title>Table Example</title>
</head>
<body>
    <table border="1" width="600" cellpadding="10" cellspacing="0" align="center">
        <caption><b>Student Marks Report</b></caption>

        <thead bgcolor="#cccccc">
            <tr>
                <th>Roll No</th>
                <th>Name</th>
                <th>Subject</th>
                <th>Marks</th>
            </tr>
        </thead>

        <tbody>
            <tr align="center">
                <td>101</td>
                <td>John</td>
                <td>HTML</td>
                <td>85</td>
            </tr>
            <tr align="center">
                <td>102</td>
                <td>Sarah</td>
                <td>CSS</td>
                <td>90</td>
            </tr>
            <tr align="center">
                <td>103</td>
                <td>Mike</td>
                <td>JavaScript</td>
                <td>78</td>
            </tr>
        </tbody>

        <tfoot bgcolor="#ffff99">
            <tr>
                <td colspan="3" align="right"><b>Average:</b></td>
                <td align="center"><b>84.33</b></td>
            </tr>
        </tfoot>
    </table>
</body>
</html>
```

---

### Rowspan and Colspan Examples:

**Example 1: Colspan (Horizontal Merge)**
```html
<table border="1" width="400">
    <tr>
        <td colspan="3" align="center">Header spanning 3 columns</td>
    </tr>
    <tr>
        <td>Cell 1</td>
        <td>Cell 2</td>
        <td>Cell 3</td>
    </tr>
</table>
```

**Example 2: Rowspan (Vertical Merge)**
```html
<table border="1" width="400">
    <tr>
        <td rowspan="3">This cell spans 3 rows</td>
        <td>Row 1, Cell 2</td>
    </tr>
    <tr>
        <td>Row 2, Cell 2</td>
    </tr>
    <tr>
        <td>Row 3, Cell 2</td>
    </tr>
</table>
```

**Example 3: Combining Rowspan and Colspan**
```html
<table border="1" width="500" cellpadding="8">
    <tr>
        <td colspan="2" align="center" bgcolor="#cccccc"><b>Header</b></td>
        <td rowspan="2" align="center">Rowspan 2</td>
    </tr>
    <tr>
        <td>Data 1</td>
        <td>Data 2</td>
    </tr>
    <tr>
        <td colspan="3" align="center" bgcolor="#ffff99">Footer</td>
    </tr>
</table>
```

**Example 4: Complex Table (Time Table)**
```html
<table border="2" width="600" cellpadding="5" cellspacing="0">
    <caption><h2>Class Time Table</h2></caption>
    <tr bgcolor="#3399ff" align="center">
        <th>Time</th>
        <th>Monday</th>
        <th>Tuesday</th>
        <th>Wednesday</th>
    </tr>
    <tr align="center">
        <td>9:00-10:00</td>
        <td>HTML</td>
        <td rowspan="2" bgcolor="#ffcc99">Workshop</td>
        <td>CSS</td>
    </tr>
    <tr align="center">
        <td>10:00-11:00</td>
        <td>JavaScript</td>
        <td>PHP</td>
    </tr>
    <tr align="center">
        <td>11:00-12:00</td>
        <td colspan="3" bgcolor="#99ff99">Lunch Break</td>
    </tr>
</table>
```

---

### Nested Tables:

A table within a table:

```html
<table border="1" width="500">
    <tr>
        <td>Outer Table Cell 1</td>
        <td>
            <!-- Nested Table -->
            <table border="1" width="100%">
                <tr>
                    <td>Inner Cell 1</td>
                    <td>Inner Cell 2</td>
                </tr>
            </table>
        </td>
    </tr>
</table>
```

---

## 2. Frames and Framesets

Frames allow you to divide the browser window into multiple sections, where each section can load a separate HTML document.

**Note:** Frames are **deprecated** in HTML5 and not recommended, but still important for exams.

### Basic Concepts:

- **Frameset**: Defines the layout of frames
- **Frame**: Individual section within frameset
- **Frames do not use `<body>` tag**
- Each frame displays a different HTML page

---

### Frameset Tag and Attributes:

**`<frameset>` Tag:**
- Replaces the `<body>` tag
- Used to define frame structure

**Important Attributes:**

**1. `rows`**
- Divides window horizontally (top to bottom)
- Values: pixels, percentage, or * (remaining space)
- Example: `rows="20%, 80%"` or `rows="100, *"`

**2. `cols`**
- Divides window vertically (left to right)
- Values: pixels, percentage, or *
- Example: `cols="25%, 75%"` or `cols="200, *"`

**3. `border`**
- Border width between frames
- Example: `border="5"`

**4. `frameborder`**
- Show/hide borders
- Values: 0 (no border), 1 (border)

**5. `framespacing`**
- Space between frames
- Example: `framespacing="10"`

---

### Frame Tag and Attributes:

**`<frame>` Tag:**
- Defines individual frame within frameset
- Self-closing tag

**Important Attributes:**

**1. `src`** - Required
- Specifies the HTML file to display
- Example: `src="page1.html"`

**2. `name`**
- Names the frame for targeting
- Example: `name="content"`
- Used with anchor tag: `<a href="page.html" target="content">`

**3. `scrolling`**
- Controls scrollbars
- Values: yes, no, auto (default)

**4. `noresize`**
- Prevents user from resizing frame
- Boolean attribute

**5. `marginwidth`**
- Left and right margins in pixels
- Example: `marginwidth="10"`

**6. `marginheight`**
- Top and bottom margins in pixels
- Example: `marginheight="10"`

**7. `frameborder`**
- Border for specific frame
- Values: 0 (no), 1 (yes)

---

### Types of Framesets:

**1. Horizontal Frames (Rows):**
```html
<frameset rows="30%, 70%">
    <frame src="top.html" name="topframe">
    <frame src="bottom.html" name="bottomframe">
</frameset>
```

**2. Vertical Frames (Columns):**
```html
<frameset cols="25%, 75%">
    <frame src="left.html" name="leftframe">
    <frame src="right.html" name="rightframe">
</frameset>
```

**3. Mixed Frames (Nested):**
```html
<frameset rows="20%, *">
    <frame src="header.html" name="header">
    <frameset cols="30%, 70%">
        <frame src="menu.html" name="menu">
        <frame src="content.html" name="content">
    </frameset>
</frameset>
```

---

### **Exam Question: Divide Web Page into Four Equal Parts**

**Question:** Divide the web page into four equal parts, each displaying a different web page.

**Solution:**

```html
<!DOCTYPE html>
<html>
<head>
    <title>Four Equal Parts</title>
</head>
<frameset rows="50%, 50%">
    <frameset cols="50%, 50%">
        <frame src="page1.html" name="topleft">
        <frame src="page2.html" name="topright">
    </frameset>
    <frameset cols="50%, 50%">
        <frame src="page3.html" name="bottomleft">
        <frame src="page4.html" name="bottomright">
    </frameset>
    <noframes>
        <body>Your browser does not support frames.</body>
    </noframes>
</frameset>
</html>
```

**Alternative Method:**
```html
<frameset rows="50%, 50%" cols="50%, 50%">
    <frame src="page1.html" name="frame1">
    <frame src="page2.html" name="frame2">
    <frame src="page3.html" name="frame3">
    <frame src="page4.html" name="frame4">
</frameset>
```

**Explanation:**
- Outer frameset divides into 2 rows (50% each)
- Each row further divided into 2 columns (50% each)
- Results in 4 equal quadrants
- Each frame displays different HTML page

---

### Common Frame Layouts:

**Layout 1: Header, Menu, Content**
```html
<frameset rows="100, *">
    <frame src="header.html" noresize scrolling="no">
    <frameset cols="200, *">
        <frame src="menu.html" name="menu">
        <frame src="content.html" name="main">
    </frameset>
</frameset>
```

**Layout 2: Three Equal Columns**
```html
<frameset cols="33.33%, 33.33%, 33.34%">
    <frame src="left.html">
    <frame src="middle.html">
    <frame src="right.html">
</frameset>
```

---

### `<noframes>` Tag:

Used to provide alternative content for browsers that don't support frames.

```html
<frameset rows="50%, 50%">
    <frame src="top.html">
    <frame src="bottom.html">
    <noframes>
        <body>
            <p>Your browser does not support frames.</p>
            <p><a href="top.html">Click here</a> to view content.</p>
        </body>
    </noframes>
</frameset>
```

---

### Targeting Frames with Links:

**Creating Navigation:**

**menu.html:**
```html
<html>
<body>
    <h3>Menu</h3>
    <a href="home.html" target="content">Home</a><br>
    <a href="about.html" target="content">About</a><br>
    <a href="contact.html" target="content">Contact</a>
</body>
</html>
```

**main.html (Frameset):**
```html
<frameset cols="200, *">
    <frame src="menu.html" name="menu">
    <frame src="home.html" name="content">
</frameset>
```

**Special Target Values:**
- `target="_self"` - Same frame
- `target="_parent"` - Parent frameset
- `target="_top"` - Full window (breaks out of frames)
- `target="_blank"` - New window

---

## 3. Floating Frames (Inline Frames) - `<iframe>`

An iframe (inline frame) is used to embed another HTML document within the current page. **Unlike framesets, iframes can be used with the `<body>` tag.**

### Basic Syntax:
```html
<iframe src="page.html"></iframe>
```

### Attributes of `<iframe>`:

**1. `src`** - Required
- URL of the page to embed
- Example: `src="content.html"`

**2. `width` and `height`**
- Dimensions of iframe
- Example: `width="600" height="400"`

**3. `name`**
- Name for targeting
- Example: `name="myframe"`

**4. `frameborder`**
- Show/hide border
- Values: 0 (no), 1 (yes)

**5. `scrolling`**
- Scrollbar control
- Values: yes, no, auto

**6. `align`** (deprecated)
- Alignment: left, right, top, middle, bottom

**7. `marginwidth` and `marginheight`**
- Internal margins

**8. `sandbox`** (HTML5)
- Security restrictions
- Example: `sandbox="allow-scripts"`

**9. `loading`** (HTML5)
- Lazy loading
- Values: lazy, eager

**10. `allowfullscreen`**
- Allows fullscreen mode
- For videos, maps, etc.

---

### Complete Iframe Examples:

**Example 1: Basic Iframe**
```html
<!DOCTYPE html>
<html>
<head>
    <title>Iframe Example</title>
</head>
<body>
    <h1>Main Page</h1>
    <p>Below is an embedded page:</p>

    <iframe src="content.html"
            width="600"
            height="400"
            frameborder="1">
        Your browser does not support iframes.
    </iframe>
</body>
</html>
```

**Example 2: Iframe with Navigation**
```html
<!DOCTYPE html>
<html>
<body>
    <h2>Navigation Menu</h2>
    <a href="home.html" target="display">Home</a> |
    <a href="about.html" target="display">About</a> |
    <a href="services.html" target="display">Services</a>

    <br><br>

    <iframe src="home.html"
            name="display"
            width="800"
            height="500"
            frameborder="0">
    </iframe>
</body>
</html>
```

**Example 3: Embedding YouTube Video**
```html
<iframe width="560"
        height="315"
        src="https://www.youtube.com/embed/VIDEO_ID"
        frameborder="0"
        allowfullscreen>
</iframe>
```

**Example 4: Embedding Google Map**
```html
<iframe src="https://www.google.com/maps/embed?pb=..."
        width="600"
        height="450"
        frameborder="0"
        allowfullscreen>
</iframe>
```

**Example 5: Multiple Iframes**
```html
<!DOCTYPE html>
<html>
<body>
    <h1>Multiple Iframes Example</h1>

    <table border="1" width="100%">
        <tr>
            <td>
                <iframe src="page1.html" width="400" height="300"></iframe>
            </td>
            <td>
                <iframe src="page2.html" width="400" height="300"></iframe>
            </td>
        </tr>
        <tr>
            <td colspan="2">
                <iframe src="footer.html" width="100%" height="100"></iframe>
            </td>
        </tr>
    </table>
</body>
</html>
```

---

### Difference Between Frameset and Iframe:

| Feature | Frameset | Iframe |
|---------|----------|--------|
| Location | Replaces `<body>` | Inside `<body>` |
| Usage | Divides entire window | Embeds content inline |
| HTML5 Support | Deprecated | Supported |
| Flexibility | Less flexible | More flexible |
| Multiple frames | Yes | Yes |
| SEO-friendly | No | Better |
| Recommended | No | Yes |

---

## 4. HTML Forms

Forms are used to collect user input and send it to a server for processing. Forms are essential for user interaction.

### Form Tag:

**`<form>` Tag:**
- Container for all form elements
- Defines how and where to submit data

**Syntax:**
```html
<form action="process.php" method="post">
    <!-- Form elements here -->
</form>
```

---

### Important Attributes of `<form>`:

**1. `action`** - Required
- URL where form data is sent
- Server-side script that processes data
- Example: `action="register.php"`
- Can be same page or different page

**2. `method`** - Required
- How data is sent to server
- Two values:
  - **GET**: Data visible in URL, less secure, limited size (default)
  - **POST**: Data hidden, more secure, no size limit (recommended)
- Example: `method="post"`

**3. `name`**
- Names the form for JavaScript access
- Example: `name="registrationForm"`

**4. `target`**
- Where to display response
- Values: _self, _blank, _parent, _top
- Example: `target="_blank"`

**5. `enctype`**
- Encoding type for form data
- Values:
  - `application/x-www-form-urlencoded` (default)
  - `multipart/form-data` (for file uploads)
  - `text/plain`
- Example: `enctype="multipart/form-data"`

**6. `autocomplete`**
- Enable/disable auto-fill
- Values: on, off
- Example: `autocomplete="off"`

**7. `novalidate`**
- Disables HTML5 form validation
- Boolean attribute

---

### Form Elements/Controls:

### 1. **Text Input**
```html
<input type="text" name="username" placeholder="Enter username" size="30" maxlength="50">
```

**Attributes:**
- `name` - Identifies the field
- `value` - Default value
- `size` - Visible width
- `maxlength` - Maximum characters
- `placeholder` - Hint text
- `required` - Makes field mandatory
- `readonly` - Cannot be edited
- `disabled` - Disabled field

---

### 2. **Password Input**
```html
<input type="password" name="pwd" placeholder="Enter password" required>
```
- Hides characters with dots/asterisks
- Same attributes as text input

---

### 3. **Email Input** (HTML5)
```html
<input type="email" name="email" placeholder="email@example.com" required>
```
- Validates email format
- Shows email keyboard on mobile

---

### 4. **Number Input** (HTML5)
```html
<input type="number" name="age" min="18" max="100" step="1" value="25">
```

**Attributes:**
- `min` - Minimum value
- `max` - Maximum value
- `step` - Increment value

---

### 5. **Radio Buttons**
```html
<input type="radio" name="gender" value="male" checked> Male
<input type="radio" name="gender" value="female"> Female
<input type="radio" name="gender" value="other"> Other
```

**Important:**
- Same `name` for grouping (only one selectable)
- Different `value` for each option
- `checked` attribute for default selection

---

### 6. **Checkboxes**
```html
<input type="checkbox" name="hobby" value="reading"> Reading
<input type="checkbox" name="hobby" value="music" checked> Music
<input type="checkbox" name="hobby" value="sports"> Sports
```

**Important:**
- Multiple selections allowed
- Same or different names
- `checked` for default selection

---

### 7. **Textarea** (Multi-line text)
```html
<textarea name="address" rows="5" cols="40" placeholder="Enter address">
Default text here
</textarea>
```

**Attributes:**
- `rows` - Number of visible lines
- `cols` - Width in characters
- `maxlength` - Character limit
- `wrap` - Text wrapping (soft, hard, off)

---

### 8. **Select Dropdown (Dropdown List)**
```html
<select name="country" size="1">
    <option value="">--Select Country--</option>
    <option value="india" selected>India</option>
    <option value="usa">USA</option>
    <option value="uk">UK</option>
</select>
```

**Attributes of `<select>`:**
- `name` - Field identifier
- `size` - Visible options (1 = dropdown)
- `multiple` - Allow multiple selections

**Attributes of `<option>`:**
- `value` - Value sent to server
- `selected` - Default selection

---

### 9. **File Upload**
```html
<input type="file" name="resume" accept=".pdf,.doc,.docx">
```

**Attributes:**
- `accept` - Allowed file types
- `multiple` - Multiple file selection
- **Note:** Form must have `enctype="multipart/form-data"`

---

### 10. **Date Input** (HTML5)
```html
<input type="date" name="dob" min="1900-01-01" max="2024-12-31">
```

Other date-related inputs:
- `type="datetime-local"` - Date and time
- `type="month"` - Month and year
- `type="week"` - Week and year
- `type="time"` - Time

---

### 11. **Color Picker** (HTML5)
```html
<input type="color" name="favcolor" value="#ff0000">
```

---

### 12. **Range Slider** (HTML5)
```html
<input type="range" name="volume" min="0" max="100" value="50" step="10">
```

---

### 13. **URL Input** (HTML5)
```html
<input type="url" name="website" placeholder="https://example.com">
```

---

### 14. **Hidden Input**
```html
<input type="hidden" name="userid" value="12345">
```
- Not visible to user
- Used to pass data silently

---

### 15. **Submit Button**
```html
<input type="submit" value="Register">
```
- Submits form data to server
- `value` attribute sets button text

---

### 16. **Reset Button**
```html
<input type="reset" value="Clear Form">
```
- Clears all form fields to default values

---

### 17. **Button** (Generic)
```html
<button type="button" onclick="alert('Clicked')">Click Me</button>
```

**Types:**
- `type="submit"` - Submits form
- `type="reset"` - Resets form
- `type="button"` - Generic button (for JavaScript)

---

### 18. **Label Tag**
```html
<label for="username">Username:</label>
<input type="text" id="username" name="username">
```
- Associates label with input
- Clicking label focuses input
- Important for accessibility

---

### 19. **Fieldset and Legend**
```html
<fieldset>
    <legend>Personal Information</legend>
    <!-- Form fields here -->
</fieldset>
```
- Groups related form elements
- Creates visual box around fields
- Legend provides title

---

## **Complete Registration Form Example** (Exam Important)

```html
<!DOCTYPE html>
<html>
<head>
    <title>Registration Form</title>
</head>
<body>
    <h2 align="center">Student Registration Form</h2>

    <form action="register.php" method="post" enctype="multipart/form-data">
        <fieldset>
            <legend>Personal Details</legend>

            <label>Full Name:</label>
            <input type="text" name="fullname" placeholder="Enter full name" required size="30">
            <br><br>

            <label>Email:</label>
            <input type="email" name="email" placeholder="email@example.com" required>
            <br><br>

            <label>Password:</label>
            <input type="password" name="password" required minlength="6">
            <br><br>

            <label>Date of Birth:</label>
            <input type="date" name="dob" required>
            <br><br>

            <label>Age:</label>
            <input type="number" name="age" min="18" max="100" required>
            <br><br>

            <label>Gender:</label>
            <input type="radio" name="gender" value="male" checked> Male
            <input type="radio" name="gender" value="female"> Female
            <input type="radio" name="gender" value="other"> Other
            <br><br>

            <label>Hobbies:</label>
            <input type="checkbox" name="hobby[]" value="reading"> Reading
            <input type="checkbox" name="hobby[]" value="music"> Music
            <input type="checkbox" name="hobby[]" value="sports"> Sports
            <input type="checkbox" name="hobby[]" value="travel"> Travel
            <br><br>
        </fieldset>

        <br>

        <fieldset>
            <legend>Academic Details</legend>

            <label>Course:</label>
            <select name="course" required>
                <option value="">--Select Course--</option>
                <option value="bca">BCA</option>
                <option value="mca">MCA</option>
                <option value="btech">B.Tech</option>
                <option value="mtech">M.Tech</option>
            </select>
            <br><br>

            <label>Semester:</label>
            <input type="number" name="semester" min="1" max="8" required>
            <br><br>

            <label>Upload Photo:</label>
            <input type="file" name="photo" accept="image/*" required>
            <br><br>

            <label>Upload Resume:</label>
            <input type="file" name="resume" accept=".pdf,.doc,.docx">
            <br><br>
        </fieldset>

        <br>

        <fieldset>
            <legend>Contact Information</legend>

            <label>Phone:</label>
            <input type="tel" name="phone" placeholder="1234567890" pattern="[0-9]{10}" required>
            <br><br>

            <label>Address:</label>
            <textarea name="address" rows="4" cols="40" placeholder="Enter full address" required></textarea>
            <br><br>

            <label>City:</label>
            <input type="text" name="city" required>
            <br><br>

            <label>State:</label>
            <select name="state" required>
                <option value="">--Select State--</option>
                <option value="jharkhand">Jharkhand</option>
                <option value="bihar">Bihar</option>
                <option value="delhi">Delhi</option>
                <option value="maharashtra">Maharashtra</option>
            </select>
            <br><br>

            <label>PIN Code:</label>
            <input type="text" name="pincode" pattern="[0-9]{6}" maxlength="6" required>
            <br><br>

            <label>Website:</label>
            <input type="url" name="website" placeholder="https://example.com">
            <br><br>
        </fieldset>

        <br>

        <fieldset>
            <legend>Additional Information</legend>

            <label>Skills:</label>
            <input type="checkbox" name="skills[]" value="html"> HTML
            <input type="checkbox" name="skills[]" value="css"> CSS
            <input type="checkbox" name="skills[]" value="javascript"> JavaScript
            <input type="checkbox" name="skills[]" value="php"> PHP
            <br><br>

            <label>Experience (Years):</label>
            <input type="range" name="experience" min="0" max="20" value="0" step="1">
            <br><br>

            <label>Favorite Color:</label>
            <input type="color" name="color" value="#0000ff">
            <br><br>

            <label>Comments:</label>
            <textarea name="comments" rows="5" cols="40" placeholder="Any additional comments"></textarea>
            <br><br>

            <input type="checkbox" name="terms" required>
            I agree to terms and conditions
            <br><br>
        </fieldset>

        <br>

        <input type="submit" value="Register">
        <input type="reset" value="Clear Form">
    </form>
</body>
</html>
```

---

## Key Points to Remember for Exams:

### Tables:
1. **Basic tags**: table, tr, td, th, caption
2. **colspan** - merges horizontally, **rowspan** - merges vertically
3. **cellpadding** - space inside cell, **cellspacing** - space between cells
4. Always close all table tags properly

### Frames:
1. **Frameset** replaces body tag, not used in HTML5
2. **rows** - horizontal division, **cols** - vertical division
3. **src** attribute required in frame tag
4. Use **name** for targeting frames with links
5. **iframe** works inside body tag (modern approach)

### Forms:
1. **action** - where to send data, **method** - how to send (GET/POST)
2. **name** attribute required for all form controls
3. Radio buttons: same name, different values
4. Checkboxes: can have same or different names
5. File upload requires **enctype="multipart/form-data"**
6. Use **label** tag for accessibility
7. **required** attribute makes field mandatory

---

**This covers all topics from Unit 2 needed for both 10-mark and 3-mark questions!**
