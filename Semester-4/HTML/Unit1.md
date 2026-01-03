# UNIT 1: Introduction to HTML & Tags - Complete Notes

## 1. Introduction to HTML

**HTML (HyperText Markup Language)** is the standard markup language used to create web pages. It describes the structure and content of web documents using a system of tags and attributes.

### Key Points:
- HTML is not a programming language; it's a markup language
- Uses tags enclosed in angle brackets (< >)
- Case-insensitive but lowercase is preferred
- Files saved with .html or .htm extension
- Interpreted by web browsers to display web pages

### Advantages of HTML:
1. **Easy to Learn**: Simple syntax, easy for beginners
2. **Platform Independent**: Works on all operating systems
3. **Free and Accessible**: No special software required
4. **Widely Supported**: All browsers support HTML
5. **Lightweight**: Small file sizes, fast loading
6. **Integration**: Works well with CSS, JavaScript, and server-side languages
7. **Search Engine Friendly**: Easy for search engines to index
8. **Cost-effective**: No licensing fees

### Disadvantages of HTML:
1. **Static**: Cannot create dynamic pages alone
2. **Limited Features**: Requires CSS for styling, JavaScript for interactivity
3. **Security**: Cannot protect web pages from unauthorized access
4. **Repetitive**: Same code must be written on every page
5. **Browser Compatibility**: Different browsers may render differently
6. **No Database Connectivity**: Cannot directly connect to databases
7. **Verbose**: Requires many tags for complex structures

---

## 2. HTML Document Structure Tags

Every HTML document follows a basic structure:

```html
<!DOCTYPE html>
<html>
<head>
    <title>Page Title</title>
    <meta charset="UTF-8">
    <meta name="description" content="Page description">
</head>
<body>
    <!-- Content goes here -->
</body>
</html>
```

### Essential Structure Tags:

**1. `<!DOCTYPE html>`**
- Declares the document type and HTML version
- Must be the first line in HTML5
- Tells browser how to render the page

**2. `<html>` Tag**
- Root element of HTML page
- Contains all other HTML elements
- Attributes: `lang="en"` (specifies language)

**3. `<head>` Tag**
- Contains metadata about the document
- Not displayed on the page
- Includes: title, meta tags, links to CSS/JavaScript

**4. `<title>` Tag**
- Defines title shown in browser tab
- Required in all HTML documents
- Important for SEO

**5. `<meta>` Tags**
- Provides metadata: charset, description, keywords, author, viewport
- Example: `<meta name="viewport" content="width=device-width, initial-scale=1.0">`

**6. `<body>` Tag**
- Contains all visible content
- Attributes: bgcolor, background, text, link, alink, vlink

---

## 3. HTML Text Formatting Tags

### Basic Formatting Tags:

| Tag | Purpose | Example |
|-----|---------|---------|
| `<b>` | Bold text (no importance) | `<b>Bold</b>` |
| `<strong>` | Bold text (important) | `<strong>Important</strong>` |
| `<i>` | Italic text | `<i>Italic</i>` |
| `<em>` | Emphasized text (italic) | `<em>Emphasis</em>` |
| `<u>` | Underlined text | `<u>Underline</u>` |
| `<strike>` or `<s>` | Strikethrough | `<s>Deleted</s>` |
| `<small>` | Smaller text | `<small>Small</small>` |
| `<big>` | Bigger text | `<big>Big</big>` |
| `<sub>` | Subscript | `H<sub>2</sub>O` |
| `<sup>` | Superscript | `X<sup>2</sup>` |
| `<mark>` | Highlighted text | `<mark>Highlight</mark>` |
| `<del>` | Deleted text | `<del>Removed</del>` |
| `<ins>` | Inserted text | `<ins>Added</ins>` |

### Heading Tags:
```html
<h1>Heading 1</h1>  <!-- Largest -->
<h2>Heading 2</h2>
<h3>Heading 3</h3>
<h4>Heading 4</h4>
<h5>Heading 5</h5>
<h6>Heading 6</h6>  <!-- Smallest -->
```

### Paragraph and Line Breaks:
- `<p>` - Paragraph tag (adds space before and after)
- `<br>` - Line break (single line break)
- `<hr>` - Horizontal rule (horizontal line)
- `<pre>` - Preformatted text (preserves spaces and line breaks)

### Other Text Tags:
- `<blockquote>` - Block quotation (indented)
- `<q>` - Inline quotation (adds quotes)
- `<code>` - Computer code
- `<kbd>` - Keyboard input
- `<var>` - Variable
- `<abbr>` - Abbreviation

---

## 4. Inserting Special Characters

HTML uses **character entities** to display special characters that are reserved or not on keyboard.

### Syntax:
- `&entity_name;` or `&#entity_number;`

### Common Special Characters:

| Character | Entity Name | Entity Number | Description |
|-----------|-------------|---------------|-------------|
| < | `&lt;` | `&#60;` | Less than |
| > | `&gt;` | `&#62;` | Greater than |
| & | `&amp;` | `&#38;` | Ampersand |
| " | `&quot;` | `&#34;` | Double quote |
| ' | `&apos;` | `&#39;` | Single quote |
|   | `&nbsp;` | `&#160;` | Non-breaking space |
| © | `&copy;` | `&#169;` | Copyright |
| ® | `&reg;` | `&#174;` | Registered |
| ™ | `&trade;` | `&#8482;` | Trademark |
| € | `&euro;` | `&#8364;` | Euro |
| £ | `&pound;` | `&#163;` | Pound |
| ¥ | `&yen;` | `&#165;` | Yen |

**Example:**
```html
<p>Price: &pound;50 &amp; &euro;60</p>
<p>Copyright &copy; 2024</p>
```

---

## 5. Anchor Tag (Hyperlink)

The `<a>` tag creates hyperlinks to other web pages, files, locations within the same page, or email addresses.

### Basic Syntax:
```html
<a href="URL">Link Text</a>
```

### Important Attributes:

**1. `href` (Hypertext Reference)**
- Specifies the destination URL
- **Absolute URL**: `href="https://www.google.com"`
- **Relative URL**: `href="about.html"`
- **Email link**: `href="mailto:email@example.com"`
- **Phone link**: `href="tel:+1234567890"`
- **Same page link**: `href="#section1"`

**2. `target` (Where to Open Link)**
- `target="_self"` - Opens in same window/tab (default)
- `target="_blank"` - Opens in new window/tab
- `target="_parent"` - Opens in parent frame
- `target="_top"` - Opens in full window

**3. `title`**
- Provides tooltip text when hovering over link
- Example: `title="Visit Google"`

**4. `download`**
- Downloads the linked file instead of navigating
- Example: `<a href="file.pdf" download>Download PDF</a>`

**5. `rel` (Relationship)**
- `rel="nofollow"` - Tells search engines not to follow
- `rel="noopener"` - Security for target="_blank"

### Types of Links:

**1. External Link:**
```html
<a href="https://www.google.com" target="_blank">Visit Google</a>
```

**2. Internal Link:**
```html
<a href="about.html">About Us</a>
```

**3. Email Link:**
```html
<a href="mailto:info@example.com">Send Email</a>
```

**4. Bookmark Link (Same Page):**
```html
<!-- Create bookmark -->
<h2 id="section1">Section 1</h2>

<!-- Link to bookmark -->
<a href="#section1">Go to Section 1</a>
```

**5. Image as Link:**
```html
<a href="page.html">
    <img src="button.jpg" alt="Click here">
</a>
```

---

## 6. List Tags

HTML provides three types of lists to organize content.

### A. Ordered List (Numbered List)

Uses `<ol>` tag with `<li>` (list item) tags.

**Syntax:**
```html
<ol>
    <li>First item</li>
    <li>Second item</li>
    <li>Third item</li>
</ol>
```

**Attributes of `<ol>`:**
- `type` - Specifies numbering style:
  - `type="1"` - Numbers (1, 2, 3) [default]
  - `type="A"` - Uppercase letters (A, B, C)
  - `type="a"` - Lowercase letters (a, b, c)
  - `type="I"` - Uppercase Roman (I, II, III)
  - `type="i"` - Lowercase Roman (i, ii, iii)
- `start` - Starting number: `start="5"`
- `reversed` - Reverse order

**Example:**
```html
<ol type="A" start="3">
    <li>Third item (C)</li>
    <li>Fourth item (D)</li>
</ol>
```

### B. Unordered List (Bulleted List)

Uses `<ul>` tag with `<li>` tags.

**Syntax:**
```html
<ul>
    <li>Item one</li>
    <li>Item two</li>
    <li>Item three</li>
</ul>
```

**Attributes of `<ul>`:**
- `type` - Specifies bullet style:
  - `type="disc"` - Filled circle (default)
  - `type="circle"` - Hollow circle
  - `type="square"` - Filled square

**Example:**
```html
<ul type="square">
    <li>Apple</li>
    <li>Banana</li>
</ul>
```

### C. Definition List

Uses `<dl>` (definition list), `<dt>` (definition term), and `<dd>` (definition description).

**Syntax:**
```html
<dl>
    <dt>HTML</dt>
    <dd>HyperText Markup Language</dd>

    <dt>CSS</dt>
    <dd>Cascading Style Sheets</dd>
</dl>
```

### Nested Lists:

```html
<ul>
    <li>Fruits
        <ul>
            <li>Apple</li>
            <li>Banana</li>
        </ul>
    </li>
    <li>Vegetables</li>
</ul>
```

---

## 7. Adding Images

The `<img>` tag is used to embed images in web pages. It's a self-closing tag.

### Basic Syntax:
```html
<img src="image.jpg" alt="Description">
```

### Important Attributes:

**1. `src` (Source)** - Required
- Specifies path to image file
- Absolute: `src="https://example.com/image.jpg"`
- Relative: `src="images/photo.jpg"`

**2. `alt` (Alternative Text)** - Required
- Text displayed if image can't load
- Important for accessibility and SEO
- Example: `alt="Sunset over mountains"`

**3. `width` and `height`**
- Sets image dimensions in pixels or percentage
- `width="300"` or `width="50%"`
- `height="200"`
- Maintains aspect ratio if only one specified

**4. `title`**
- Tooltip text when hovering
- Example: `title="Beautiful sunset"`

**5. `border`**
- Sets border width (deprecated, use CSS)
- Example: `border="2"`

**6. `align`** (deprecated, use CSS)
- `align="left"`, `align="right"`, `align="top"`, `align="bottom"`, `align="middle"`

**7. `loading`**
- `loading="lazy"` - Loads image when visible (performance)
- `loading="eager"` - Loads immediately

### Complete Example:
```html
<img src="sunset.jpg"
     alt="Beautiful sunset over ocean"
     width="500"
     height="300"
     title="Sunset photograph"
     loading="lazy">
```

### Supported Image Formats:
- **JPEG/JPG** - Photos, complex images
- **PNG** - Transparent backgrounds, logos
- **GIF** - Animations, simple graphics
- **SVG** - Scalable vector graphics
- **WebP** - Modern, efficient format

---

## 8. Adding Sound (Audio)

HTML5 provides the `<audio>` tag to embed sound files.

### Basic Syntax:
```html
<audio controls>
    <source src="audio.mp3" type="audio/mpeg">
    <source src="audio.ogg" type="audio/ogg">
    Your browser does not support audio.
</audio>
```

### Attributes of `<audio>`:

**1. `controls`**
- Displays play, pause, volume controls
- Boolean attribute (no value needed)

**2. `autoplay`**
- Starts playing automatically on page load
- `autoplay` or `autoplay="autoplay"`
- Note: Many browsers block autoplay

**3. `loop`**
- Repeats audio continuously
- `loop` or `loop="loop"`

**4. `muted`**
- Starts with sound muted
- Useful with autoplay

**5. `preload`**
- `preload="auto"` - Load entire audio on page load
- `preload="metadata"` - Load only metadata
- `preload="none"` - Don't preload

**6. `src`**
- Direct audio source (if not using `<source>` tags)

### Complete Example:
```html
<audio controls autoplay loop>
    <source src="music.mp3" type="audio/mpeg">
    <source src="music.ogg" type="audio/ogg">
    <source src="music.wav" type="audio/wav">
    Your browser does not support the audio element.
</audio>
```

### Supported Audio Formats:
- **MP3** - Most widely supported
- **OGG** - Open source, good quality
- **WAV** - Uncompressed, large files
- **AAC** - Advanced Audio Coding

### Adding Background Music:
```html
<audio autoplay loop>
    <source src="background.mp3" type="audio/mpeg">
</audio>
```

### Linking to Audio File:
```html
<a href="song.mp3" download>Download Song</a>
```

---

## Practice Examples

### Example 1: Complete Web Page with All Unit 1 Concepts

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <title>Unit 1 - HTML Demo Page</title>
    <meta charset="UTF-8">
</head>
<body>
    <h1>Welcome to HTML Learning</h1>
    <hr>

    <!-- Text Formatting -->
    <p>This is <b>bold</b> and <i>italic</i> text.</p>
    <p>Chemical formula: H<sub>2</sub>O</p>
    <p>Math equation: X<sup>2</sup> + Y<sup>2</sup></p>

    <!-- Special Characters -->
    <p>Price: &pound;100 &amp; &euro;120</p>
    <p>&copy; 2024 My Website. All rights reserved &reg;</p>

    <!-- Links -->
    <a href="https://www.google.com" target="_blank">Visit Google</a>
    <br>
    <a href="mailto:info@example.com">Contact Us</a>

    <!-- Lists -->
    <h2>Programming Languages</h2>
    <ol type="1">
        <li>Python</li>
        <li>Java</li>
        <li>JavaScript</li>
    </ol>

    <h2>Fruits</h2>
    <ul type="disc">
        <li>Apple</li>
        <li>Banana</li>
        <li>Orange</li>
    </ul>

    <!-- Image -->
    <img src="photo.jpg" alt="Sample Photo" width="400" height="300">

    <!-- Audio -->
    <audio controls>
        <source src="music.mp3" type="audio/mpeg">
        Your browser does not support audio.
    </audio>
</body>
</html>
```

---

## Important Points to Remember for Exams:

1. **HTML is a markup language**, not a programming language
2. **All tags should be properly closed** (except self-closing tags)
3. **Case-insensitive** but lowercase preferred
4. **DOCTYPE** declaration is mandatory in HTML5
5. **alt attribute** in img tag is mandatory for accessibility
6. **Anchor tag** uses `href` attribute for linking
7. **Three types of lists**: ordered, unordered, definition
8. **Audio tag** requires controls attribute to show player
9. **Special characters** use entity names or numbers
10. **Structure**: DOCTYPE → html → head → body

---

**This covers all topics from Unit 1 needed for both 10-mark and 3-mark questions!**
