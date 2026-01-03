# UNIT 3: CSS (Cascading Style Sheets) - Complete Notes

## 1. Introduction to CSS

**CSS (Cascading Style Sheets)** is a styling language used to control the presentation and layout of HTML documents. It separates content (HTML) from presentation (CSS).

### What is CSS?
- CSS stands for **Cascading Style Sheets**
- Describes how HTML elements should be displayed
- Controls layout, colors, fonts, spacing, and responsiveness
- Can control multiple web pages at once
- Saved with **.css** extension

### Key Features of CSS:
1. **Separation of concerns** - Content separate from design
2. **Reusability** - Same styles applied to multiple elements
3. **Easy maintenance** - Change style in one place
4. **Consistency** - Uniform look across website
5. **Reduced file size** - Less code, faster loading
6. **Multiple device support** - Responsive design
7. **Better control** - Precise positioning and styling

---

## 2. Need of Design in HTML Pages

### Why CSS is Needed?

**Problems with HTML-only Design:**

1. **Repetitive Code**
   - Same styling attributes repeated on every page
   - Example: `<font color="red" size="5">` on every heading
   - Difficult to maintain large websites

2. **Limited Styling Options**
   - HTML provides basic styling only
   - Cannot create modern, attractive designs
   - No control over spacing, positioning

3. **Mixing Content and Presentation**
   - HTML should define structure, not appearance
   - Makes code messy and hard to read
   - Violates web development best practices

4. **Inconsistency**
   - Hard to maintain consistent look
   - Changes require editing every page
   - Time-consuming and error-prone

5. **Large File Sizes**
   - Inline styles increase page size
   - Slower loading times
   - Wastes bandwidth

**Solutions Provided by CSS:**

1. **Centralized Styling** - One CSS file for entire website
2. **Advanced Design** - Gradients, shadows, animations, transitions
3. **Clean Code** - HTML focuses on structure only
4. **Easy Updates** - Change CSS file to update entire site
5. **Responsive Design** - Adapt to different screen sizes
6. **Better Performance** - Smaller HTML files, cached CSS

**Example Comparison:**

**Without CSS (Old Method):**
```html
<font color="red" size="5" face="Arial">
    <b>Welcome to My Website</b>
</font>
<p>
    <font color="blue" size="3" face="Verdana">
        This is a paragraph with styling.
    </font>
</p>
```

**With CSS (Modern Method):**
```html
<h1>Welcome to My Website</h1>
<p>This is a paragraph with styling.</p>

<style>
    h1 {
        color: red;
        font-size: 24px;
        font-family: Arial;
        font-weight: bold;
    }
    p {
        color: blue;
        font-size: 14px;
        font-family: Verdana;
    }
</style>
```

---

## 3. CSS Syntax and Tag Structure

### Basic CSS Syntax:

```css
selector {
    property: value;
    property: value;
}
```

**Components:**
- **Selector** - Identifies HTML element to style
- **Property** - Aspect to style (color, font-size, etc.)
- **Value** - Setting for the property
- **Declaration** - Property + Value pair
- **Declaration Block** - All declarations within { }

**Example:**
```css
h1 {
    color: blue;           /* Declaration 1 */
    font-size: 24px;       /* Declaration 2 */
    text-align: center;    /* Declaration 3 */
}
```

### CSS Comments:
```css
/* This is a single-line comment */

/*
   This is a
   multi-line comment
*/

p {
    color: red; /* Inline comment */
}
```

---

## 4. Ways to Insert CSS in Web Page

CSS can be added to HTML documents in **three ways**:

### 1. Inline CSS

**Definition:** CSS applied directly to HTML element using `style` attribute.

**Syntax:**
```html
<tagname style="property: value; property: value;">
```

**Example:**
```html
<!DOCTYPE html>
<html>
<head>
    <title>Inline CSS</title>
</head>
<body>
    <h1 style="color: red; text-align: center; font-size: 30px;">
        Welcome to CSS
    </h1>

    <p style="color: blue; font-family: Arial; background-color: yellow;">
        This is a paragraph with inline styling.
    </p>

    <div style="width: 300px; height: 200px; background-color: lightgreen; border: 2px solid black;">
        This is a div with inline CSS.
    </div>
</body>
</html>
```

**Advantages:**
- Quick testing and debugging
- Highest priority (overrides other CSS)
- Useful for single element styling
- No external file needed

**Disadvantages:**
- Not reusable
- Hard to maintain
- Mixes content with presentation
- Increases HTML file size
- Cannot use pseudo-classes/elements

---

### 2. Internal CSS (Embedded CSS)

**Definition:** CSS written within `<style>` tag inside `<head>` section of HTML document.

**Syntax:**
```html
<head>
    <style>
        selector {
            property: value;
        }
    </style>
</head>
```

**Example:**
```html
<!DOCTYPE html>
<html>
<head>
    <title>Internal CSS</title>
    <style>
        body {
            background-color: #f0f0f0;
            font-family: Arial, sans-serif;
        }

        h1 {
            color: darkblue;
            text-align: center;
            font-size: 36px;
            text-decoration: underline;
        }

        p {
            color: #333;
            font-size: 16px;
            line-height: 1.6;
            margin: 20px;
        }

        .highlight {
            background-color: yellow;
            font-weight: bold;
        }

        #special {
            color: red;
            border: 2px dashed blue;
            padding: 10px;
        }
    </style>
</head>
<body>
    <h1>Internal CSS Example</h1>
    <p>This is a regular paragraph.</p>
    <p class="highlight">This paragraph is highlighted.</p>
    <p id="special">This paragraph is special.</p>
</body>
</html>
```

**Advantages:**
- Styles apply to entire page
- Better than inline CSS for organization
- Can use all CSS selectors
- No external file needed
- Good for single-page websites

**Disadvantages:**
- Not reusable across multiple pages
- Increases HTML file size
- Not suitable for large websites
- Must be repeated on each page

---

### 3. External CSS

**Definition:** CSS written in separate .css file and linked to HTML document.

**Syntax:**

**HTML File (index.html):**
```html
<!DOCTYPE html>
<html>
<head>
    <title>External CSS</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
    <h1>External CSS Example</h1>
    <p class="intro">This is an introduction paragraph.</p>
    <div id="content">
        <p>Main content here.</p>
    </div>
</body>
</html>
```

**CSS File (style.css):**
```css
/* style.css */
body {
    background-color: #ffffff;
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
    margin: 0;
    padding: 0;
}

h1 {
    color: #2c3e50;
    text-align: center;
    padding: 20px;
    background-color: #ecf0f1;
}

.intro {
    font-size: 18px;
    font-weight: bold;
    color: #34495e;
    margin: 20px;
}

#content {
    width: 80%;
    margin: 0 auto;
    padding: 20px;
    background-color: #f9f9f9;
    border: 1px solid #ddd;
}

p {
    line-height: 1.8;
    color: #555;
}
```

**Link Tag Attributes:**
- `rel="stylesheet"` - Defines relationship (required)
- `type="text/css"` - Specifies MIME type (optional in HTML5)
- `href="style.css"` - Path to CSS file (required)

**Advantages:**
- **Most recommended method**
- Reusable across multiple pages
- Easy maintenance - change one file
- Reduces HTML file size
- Browser caching improves performance
- Clean separation of content and style
- Suitable for large websites

**Disadvantages:**
- Requires separate file
- Extra HTTP request (minimal impact)
- Page may render before CSS loads

---

### Comparison of Three Methods:

| Feature | Inline CSS | Internal CSS | External CSS |
|---------|-----------|--------------|--------------|
| Location | Inside HTML tag | Inside `<head>` | Separate .css file |
| Reusability | Not reusable | Single page | Multiple pages |
| Maintenance | Very difficult | Moderate | Easy |
| File Size | Increases HTML | Increases HTML | Separate file |
| Priority | Highest | Medium | Lowest |
| Best For | Quick tests | Single page | Large websites |
| Recommended | No | Sometimes | **Yes** |

---

### CSS Priority/Specificity Order:

When multiple CSS rules apply to same element:

1. **Inline CSS** (Highest priority)
2. **Internal CSS**
3. **External CSS**
4. **Browser Default** (Lowest priority)

**Note:** If same priority, the **last defined rule** wins.

**Example:**
```html
<head>
    <link rel="stylesheet" href="style.css">
    <style>
        p { color: blue; }  /* This overrides external CSS */
    </style>
</head>
<body>
    <p style="color: red;">Red text</p>  <!-- Inline wins -->
    <p>Blue text</p>  <!-- Internal CSS applies -->
</body>
```

---

## 5. CSS Selectors

Selectors are patterns used to select and style HTML elements.

### Types of Selectors:

### 1. Universal Selector (*)

Selects **all elements** on the page.

**Syntax:**
```css
* {
    property: value;
}
```

**Example:**
```css
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}
```

**Usage:**
- Reset default browser styles
- Apply global styles
- Use sparingly (performance impact)

---

### 2. Element/Type Selector

Selects all elements of a **specific type**.

**Syntax:**
```css
tagname {
    property: value;
}
```

**Example:**
```css
p {
    color: blue;
    font-size: 16px;
}

h1 {
    color: red;
    text-align: center;
}

div {
    background-color: lightgray;
    padding: 20px;
}
```

**HTML:**
```html
<p>All paragraphs will be blue.</p>
<h1>All h1 headings will be red.</h1>
<div>All divs will have gray background.</div>
```

---

### 3. Class Selector (.)

Selects elements with a **specific class attribute**. Can be used on multiple elements.

**Syntax:**
```css
.classname {
    property: value;
}
```

**Example:**
```css
.highlight {
    background-color: yellow;
    font-weight: bold;
}

.error {
    color: red;
    border: 1px solid red;
}

.container {
    width: 80%;
    margin: 0 auto;
}
```

**HTML:**
```html
<p class="highlight">This is highlighted.</p>
<p class="error">This is an error message.</p>
<div class="container">Content inside container</div>
<span class="highlight">Span can also use same class.</span>
```

**Multiple Classes:**
```html
<p class="highlight error">Multiple classes applied</p>
```

**Important Points:**
- Class names start with dot (.) in CSS
- Multiple elements can have same class
- One element can have multiple classes
- Case-sensitive
- Cannot start with number

---

### 4. ID Selector (#)

Selects a **single element** with specific ID attribute. Should be unique on page.

**Syntax:**
```css
#idname {
    property: value;
}
```

**Example:**
```css
#header {
    background-color: navy;
    color: white;
    padding: 20px;
}

#footer {
    background-color: #333;
    color: white;
    text-align: center;
}

#special-paragraph {
    font-size: 20px;
    color: green;
}
```

**HTML:**
```html
<div id="header">Website Header</div>
<p id="special-paragraph">Special paragraph</p>
<div id="footer">Website Footer</div>
```

**Important Points:**
- ID names start with hash (#) in CSS
- ID must be unique on page
- Higher specificity than classes
- Used for unique elements
- Case-sensitive
- Cannot start with number

---

### 5. Group Selector (,)

Applies **same styles to multiple selectors**.

**Syntax:**
```css
selector1, selector2, selector3 {
    property: value;
}
```

**Example:**
```css
h1, h2, h3 {
    color: darkblue;
    font-family: Arial;
}

p, div, span {
    line-height: 1.6;
}

.header, .footer, #sidebar {
    background-color: #f0f0f0;
}
```

---

### 6. Descendant Selector (space)

Selects elements that are **descendants** (nested inside) of another element.

**Syntax:**
```css
parent descendant {
    property: value;
}
```

**Example:**
```css
div p {
    color: red;  /* Only p inside div */
}

.container h2 {
    text-align: center;  /* h2 inside .container */
}

#menu a {
    text-decoration: none;  /* a inside #menu */
}
```

**HTML:**
```html
<div>
    <p>This p is red (inside div)</p>
    <span>
        <p>This p is also red (nested inside div)</p>
    </span>
</div>
<p>This p is NOT red (outside div)</p>
```

---

### 7. Child Selector (>)

Selects **direct children** only (not all descendants).

**Syntax:**
```css
parent > child {
    property: value;
}
```

**Example:**
```css
div > p {
    color: blue;  /* Only direct p children of div */
}

ul > li {
    list-style-type: square;
}
```

**HTML:**
```html
<div>
    <p>This is blue (direct child)</p>
    <span>
        <p>This is NOT blue (not direct child)</p>
    </span>
</div>
```

---

### 8. Attribute Selector

Selects elements based on **attribute** or attribute value.

**Syntax:**
```css
[attribute] {
    property: value;
}

[attribute="value"] {
    property: value;
}
```

**Example:**
```css
/* Elements with title attribute */
[title] {
    border-bottom: 1px dotted;
}

/* Input with type="text" */
input[type="text"] {
    border: 1px solid blue;
    padding: 5px;
}

/* Links with target="_blank" */
a[target="_blank"] {
    color: red;
}

/* Images with alt attribute */
img[alt] {
    border: 2px solid green;
}
```

---

### 9. Pseudo-class Selectors

Selects elements based on **state** or **position**.

**Common Pseudo-classes:**

**Link States:**
```css
a:link {
    color: blue;  /* Unvisited link */
}

a:visited {
    color: purple;  /* Visited link */
}

a:hover {
    color: red;  /* Mouse over */
    text-decoration: underline;
}

a:active {
    color: green;  /* Being clicked */
}
```

**Form States:**
```css
input:focus {
    background-color: lightyellow;
    border: 2px solid blue;
}

input:disabled {
    background-color: #ccc;
}

input:checked {
    outline: 2px solid green;
}
```

**Position-based:**
```css
li:first-child {
    font-weight: bold;
}

li:last-child {
    border-bottom: none;
}

li:nth-child(2) {
    background-color: yellow;
}

p:nth-child(odd) {
    background-color: #f0f0f0;
}
```

---

### Selector Specificity (Priority):

From **highest to lowest** priority:

1. **Inline styles** - `style="..."`
2. **ID selectors** - `#id`
3. **Class selectors** - `.class`, `[attribute]`, pseudo-classes
4. **Element selectors** - `div`, `p`, `h1`
5. **Universal selector** - `*`

**Example:**
```css
* { color: black; }           /* Specificity: 0 */
p { color: blue; }            /* Specificity: 1 */
.text { color: green; }       /* Specificity: 10 */
#special { color: red; }      /* Specificity: 100 */
```

```html
<p id="special" class="text" style="color: orange;">
    What color? → Orange (inline wins)
</p>
```

---

## 6. CSS Properties

### A. Font Properties

Control text font appearance.

**1. font-family**
```css
p {
    font-family: Arial, Helvetica, sans-serif;
}
```
- Specifies font name
- List multiple fonts (fallback)
- Generic families: serif, sans-serif, monospace, cursive, fantasy

**2. font-size**
```css
h1 {
    font-size: 24px;      /* Pixels */
    font-size: 1.5em;     /* Relative to parent */
    font-size: 150%;      /* Percentage */
    font-size: 2rem;      /* Relative to root */
}
```

**3. font-weight**
```css
p {
    font-weight: normal;   /* 400 */
    font-weight: bold;     /* 700 */
    font-weight: 600;      /* Numeric value */
}
```
- Values: normal, bold, bolder, lighter, 100-900

**4. font-style**
```css
p {
    font-style: normal;
    font-style: italic;
    font-style: oblique;
}
```

**5. font-variant**
```css
p {
    font-variant: normal;
    font-variant: small-caps;
}
```

**6. font (Shorthand)**
```css
p {
    font: italic bold 16px/1.5 Arial, sans-serif;
    /* style weight size/line-height family */
}
```

---

### B. Text Properties

Control text appearance and layout.

**1. color**
```css
p {
    color: red;
    color: #ff0000;
    color: rgb(255, 0, 0);
    color: rgba(255, 0, 0, 0.5);  /* With transparency */
}
```

**2. text-align**
```css
h1 {
    text-align: left;
    text-align: center;
    text-align: right;
    text-align: justify;
}
```

**3. text-decoration**
```css
a {
    text-decoration: none;          /* Remove underline */
    text-decoration: underline;
    text-decoration: overline;
    text-decoration: line-through;
}
```

**4. text-transform**
```css
p {
    text-transform: uppercase;   /* UPPERCASE */
    text-transform: lowercase;   /* lowercase */
    text-transform: capitalize;  /* Capitalize Each Word */
}
```

**5. text-indent**
```css
p {
    text-indent: 50px;  /* First line indent */
}
```

**6. letter-spacing**
```css
h1 {
    letter-spacing: 2px;  /* Space between characters */
}
```

**7. word-spacing**
```css
p {
    word-spacing: 5px;  /* Space between words */
}
```

**8. line-height**
```css
p {
    line-height: 1.6;     /* Relative */
    line-height: 24px;    /* Fixed */
}
```

**9. text-shadow**
```css
h1 {
    text-shadow: 2px 2px 4px rgba(0,0,0,0.5);
    /* horizontal vertical blur color */
}
```

---

### C. Background Properties

Control element backgrounds.

**1. background-color**
```css
div {
    background-color: lightblue;
    background-color: #f0f0f0;
    background-color: rgb(240, 240, 240);
}
```

**2. background-image**
```css
body {
    background-image: url('background.jpg');
}
```

**3. background-repeat**
```css
div {
    background-repeat: repeat;      /* Default */
    background-repeat: no-repeat;
    background-repeat: repeat-x;    /* Horizontal only */
    background-repeat: repeat-y;    /* Vertical only */
}
```

**4. background-position**
```css
div {
    background-position: center;
    background-position: top right;
    background-position: 50% 50%;
    background-position: 100px 200px;
}
```

**5. background-size**
```css
div {
    background-size: cover;      /* Cover entire area */
    background-size: contain;    /* Fit inside area */
    background-size: 100px 200px;
    background-size: 50%;
}
```

**6. background-attachment**
```css
body {
    background-attachment: scroll;  /* Scrolls with page */
    background-attachment: fixed;   /* Stays fixed */
}
```

**7. background (Shorthand)**
```css
div {
    background: #f0f0f0 url('image.jpg') no-repeat center/cover fixed;
    /* color image repeat position/size attachment */
}
```

---

## 7. The `<div>` Tag

### What is `<div>` Tag?

- `<div>` stands for **"division"**
- **Block-level container element**
- Used to group HTML elements
- No semantic meaning (just a container)
- Takes full width available
- Starts on new line

### Purpose of `<div>` Tag:

1. **Grouping Elements**
   - Group related content together
   - Apply styles to multiple elements

2. **Layout Structure**
   - Create page sections (header, footer, sidebar)
   - Build grid systems

3. **CSS Styling**
   - Apply styles to grouped elements
   - Create boxes, containers

4. **JavaScript Manipulation**
   - Select and manipulate groups of elements
   - Dynamic content updates

5. **Responsive Design**
   - Create flexible layouts
   - Organize content for different screens

### `<div>` Tag Properties/Attributes:

**1. id** - Unique identifier
```html
<div id="header">Header content</div>
```

**2. class** - CSS class name
```html
<div class="container">Content</div>
```

**3. style** - Inline CSS
```html
<div style="background-color: blue; padding: 20px;">Styled div</div>
```

**4. align** (deprecated - use CSS)
```html
<div align="center">Centered content</div>
```

---

### CSS Properties for `<div>`:

**Common `<div>` Styling:**

```css
div {
    /* Box Model */
    width: 500px;
    height: 300px;
    padding: 20px;
    margin: 10px;
    border: 1px solid black;

    /* Background */
    background-color: lightblue;
    background-image: url('image.jpg');

    /* Text */
    color: #333;
    text-align: center;
    font-size: 16px;

    /* Display */
    display: block;        /* Default */
    display: inline-block;
    display: flex;
    display: grid;

    /* Position */
    position: relative;
    position: absolute;
    position: fixed;

    /* Float */
    float: left;
    float: right;

    /* Overflow */
    overflow: hidden;
    overflow: scroll;
    overflow: auto;

    /* Box Shadow */
    box-shadow: 2px 2px 5px rgba(0,0,0,0.3);

    /* Border Radius */
    border-radius: 10px;

    /* Opacity */
    opacity: 0.8;
}
```

---

### Complete `<div>` Examples:

**Example 1: Simple Container**
```html
<!DOCTYPE html>
<html>
<head>
    <style>
        .container {
            width: 80%;
            margin: 0 auto;
            padding: 20px;
            background-color: #f0f0f0;
            border: 2px solid #333;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Welcome</h1>
        <p>This content is inside a container div.</p>
    </div>
</body>
</html>
```

**Example 2: Page Layout**
```html
<!DOCTYPE html>
<html>
<head>
    <style>
        #header {
            background-color: navy;
            color: white;
            padding: 20px;
            text-align: center;
        }

        #nav {
            background-color: #333;
            padding: 10px;
        }

        #content {
            float: left;
            width: 70%;
            padding: 20px;
            background-color: #f9f9f9;
        }

        #sidebar {
            float: right;
            width: 25%;
            padding: 20px;
            background-color: #e0e0e0;
        }

        #footer {
            clear: both;
            background-color: #333;
            color: white;
            padding: 10px;
            text-align: center;
        }
    </style>
</head>
<body>
    <div id="header">
        <h1>Website Header</h1>
    </div>

    <div id="nav">
        Navigation Menu
    </div>

    <div id="content">
        <h2>Main Content</h2>
        <p>Content goes here...</p>
    </div>

    <div id="sidebar">
        <h3>Sidebar</h3>
        <p>Sidebar content...</p>
    </div>

    <div id="footer">
        <p>Copyright © 2024</p>
    </div>
</body>
</html>
```

**Example 3: Card Design**
```html
<!DOCTYPE html>
<html>
<head>
    <style>
        .card {
            width: 300px;
            border: 1px solid #ddd;
            border-radius: 8px;
            box-shadow: 0 4px 8px rgba(0,0,0,0.1);
            margin: 20px;
            overflow: hidden;
        }

        .card-header {
            background-color: #4CAF50;
            color: white;
            padding: 15px;
            font-size: 20px;
        }

        .card-body {
            padding: 20px;
            background-color: white;
        }

        .card-footer {
            background-color: #f0f0f0;
            padding: 10px;
            text-align: center;
        }
    </style>
</head>
<body>
    <div class="card">
        <div class="card-header">Card Title</div>
        <div class="card-body">
            <p>This is card content with some text.</p>
        </div>
        <div class="card-footer">
            <button>Click Me</button>
        </div>
    </div>
</body>
</html>
```

---

## 8. The `<font>` Tag (Deprecated)

### What is `<font>` Tag?

- Used to specify font properties in old HTML
- **Deprecated in HTML5** (not recommended)
- Use CSS instead for modern websites

### Purpose of `<font>` Tag:

1. Set font face (typeface)
2. Set font size
3. Set font color

### `<font>` Tag Attributes:

**1. face** - Font name
```html
<font face="Arial">Text in Arial</font>
<font face="Verdana, sans-serif">Text with fallback</font>
```

**2. size** - Font size (1-7)
```html
<font size="1">Smallest</font>
<font size="4">Medium</font>
<font size="7">Largest</font>
<font size="+2">Relative size</font>
<font size="-1">Smaller</font>
```

**3. color** - Text color
```html
<font color="red">Red text</font>
<font color="#0000ff">Blue text</font>
<font color="rgb(0,255,0)">Green text</font>
```

### Complete `<font>` Tag Example:

```html
<!DOCTYPE html>
<html>
<head>
    <title>Font Tag Example</title>
</head>
<body>
    <font face="Arial" size="5" color="blue">
        This text uses font tag
    </font>

    <br><br>

    <font face="Courier New" size="3" color="#ff0000">
        Red Courier text
    </font>

    <br><br>

    <font face="Verdana" size="+2" color="green">
        Large green text
    </font>
</body>
</html>
```

### Why `<font>` is Deprecated:

1. **Mixes content with presentation**
2. **Repetitive code** - hard to maintain
3. **Limited styling options**
4. **Not semantic** - no meaning
5. **CSS is better** - more powerful and flexible

### Modern CSS Alternative:

**Instead of:**
```html
<font face="Arial" size="5" color="blue">Text</font>
```

**Use:**
```html
<p style="font-family: Arial; font-size: 24px; color: blue;">Text</p>
```

**Or with CSS class:**
```html
<style>
    .styled-text {
        font-family: Arial;
        font-size: 24px;
        color: blue;
    }
</style>

<p class="styled-text">Text</p>
```

---

## Complete CSS Example (All Concepts)

```html
<!DOCTYPE html>
<html>
<head>
    <title>CSS Complete Example</title>

    <!-- External CSS -->
    <link rel="stylesheet" href="external.css">
    <!-- Internal CSS -->
    <style>
        /* Universal Selector */
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        /* Element Selector */
        body {
            font-family: Arial, sans-serif;
            background-color: #f5f5f5;
            line-height: 1.6;
        }

        /* ID Selector */
        #header {
            background-color: #2c3e50;
            color: white;
            padding: 20px;
            text-align: center;
        }

        /* Class Selector */
        .container {
            width: 80%;
            margin: 20px auto;
            background-color: white;
            padding: 30px;
            border-radius: 8px;
            box-shadow: 0 2px 10px rgba(0,0,0,0.1);
        }

        .highlight {
            background-color: yellow;
            font-weight: bold;
            padding: 5px;
        }

        /* Group Selector */
        h1, h2, h3 {
            color: #2c3e50;
            margin-bottom: 15px;
        }

        /* Descendant Selector */
        .container p {
            color: #555;
            font-size: 16px;
            margin-bottom: 10px;
        }

        /* Child Selector */
        .menu > li {
            display: inline-block;
            margin-right: 20px;
        }

        /* Pseudo-class */
        a:hover {
            color: red;
            text-decoration: underline;
        }

        /* Attribute Selector */
        input[type="text"] {
            padding: 8px;
            border: 1px solid #ddd;
            border-radius: 4px;
        }

        /* Div styling */
        .box {
            width: 200px;
            height: 200px;
            background-color: #3498db;
            color: white;
            padding: 20px;
            margin: 10px;
            border-radius: 10px;
            float: left;
        }

        #footer {
            clear: both;
            background-color: #34495e;
            color: white;
            text-align: center;
            padding: 15px;
            margin-top: 20px;
        }
    </style>
</head>
<body>
    <!-- Inline CSS -->
    <div id="header" style="font-size: 28px;">
        CSS Complete Example
    </div>

    <div class="container">
        <h1>All CSS Concepts</h1>

        <p>This is a regular paragraph.</p>
        <p class="highlight">This paragraph is highlighted.</p>

        <h2>Font Properties</h2>
        <p style="font-family: Georgia; font-size: 18px; font-weight: bold;">
            Custom font styling
        </p>

        <h2>Text Properties</h2>
        <p style="text-align: center; text-transform: uppercase; letter-spacing: 2px;">
            Centered uppercase text
        </p>

        <h2>Background Properties</h2>
        <div style="background-color: #ecf0f1; padding: 20px; border-radius: 5px;">
            Div with background color
        </div>

        <h2>Selectors Demo</h2>
        <ul class="menu">
            <li><a href="#">Home</a></li>
            <li><a href="#">About</a></li>
            <li><a href="#">Contact</a></li>
        </ul>

        <br style="clear: both;">

        <h2>Form with CSS</h2>
        <input type="text" placeholder="Enter your name">

        <h2>Div Boxes</h2>
        <div class="box">Box 1</div>
        <div class="box">Box 2</div>
        <div class="box">Box 3</div>
    </div>

    <div id="footer">
        Copyright © 2024 | All Rights Reserved
    </div>
</body>
</html>
```

---

## Key Points to Remember for Exams:

1. **CSS** = Cascading Style Sheets, used for styling HTML
2. **Three ways to insert CSS**: Inline, Internal, External (External is best)
3. **Selectors**: Element, Class (.), ID (#), Universal (*), Group, Descendant
4. **Class** vs **ID**: Class for multiple elements, ID for unique element
5. **`<div>` tag** - Block-level container for grouping elements
6. **`<font>` tag** - Deprecated, use CSS instead
7. **Priority**: Inline > Internal > External > Browser default
8. **Font properties**: font-family, font-size, font-weight, font-style
9. **Text properties**: color, text-align, text-decoration, text-transform
10. **Background properties**: background-color, background-image, background-repeat

---

**This covers all topics from Unit 3 needed for both 10-mark and 3-mark questions!**
