# UNIT 5: HTML Forms, Graphics, Media & Modern HTML Features

## HTML FORMS

### Introduction to Forms
HTML forms are interactive elements that allow users to input data and submit it to a web server for processing. Forms are essential for user registration, login pages, surveys, contact forms, and e-commerce applications.

### Basic Form Structure
```html
<form action="process.php" method="POST">
  <!-- Form elements go here -->
</form>
```

**Key Attributes:**
- **action**: Specifies the URL where form data will be sent
- **method**: Defines how data is sent (GET or POST)
  - GET: Data visible in URL, used for searches
  - POST: Data hidden, used for sensitive information
- **enctype**: Specifies how form data should be encoded (multipart/form-data for file uploads)
- **name**: Identifies the form
- **target**: Specifies where to display response (_blank, _self, _parent, _top)

---

## HTML FORM ELEMENTS

### 1. Input Element
The most versatile form element with various types:

```html
<input type="text" name="username" placeholder="Enter username">
```

### 2. Textarea Element
For multi-line text input:
```html
<textarea name="message" rows="5" cols="40">
Default text here
</textarea>
```

**Attributes:**
- rows: Number of visible text lines
- cols: Width in characters
- maxlength: Maximum character limit

### 3. Select Element (Dropdown)
Creates a dropdown list:
```html
<select name="country">
  <option value="india">India</option>
  <option value="usa" selected>USA</option>
  <option value="uk">UK</option>
</select>
```

**Attributes:**
- multiple: Allows multiple selections
- size: Number of visible options
- selected: Pre-selects an option

### 4. Button Element
```html
<button type="submit">Submit Form</button>
<button type="reset">Reset Form</button>
<button type="button" onclick="alert('Clicked')">Click Me</button>
```

### 5. Label Element
Associates text with form controls for better accessibility:
```html
<label for="email">Email Address:</label>
<input type="email" id="email" name="email">
```

### 6. Fieldset and Legend
Groups related form elements:
```html
<fieldset>
  <legend>Personal Information</legend>
  <input type="text" name="name">
  <input type="email" name="email">
</fieldset>
```

### 7. Datalist Element
Provides autocomplete suggestions:
```html
<input list="browsers" name="browser">
<datalist id="browsers">
  <option value="Chrome">
  <option value="Firefox">
  <option value="Safari">
</datalist>
```

### 8. Output Element
Displays calculation results:
```html
<output name="result" for="a b"></output>
```

---

## HTML INPUT TYPES

### Traditional Input Types:
1. **text**: Single-line text input
2. **password**: Masked text input
3. **radio**: Single selection from multiple options
4. **checkbox**: Multiple selections allowed
5. **submit**: Submits the form
6. **reset**: Resets form to default values
7. **button**: Generic button
8. **file**: File upload
9. **hidden**: Hidden field not visible to users
10. **image**: Submit button as image

### HTML5 New Input Types:

#### 1. Email
Validates email format:
```html
<input type="email" name="email" required>
```

#### 2. URL
Validates web addresses:
```html
<input type="url" name="website">
```

#### 3. Number
Numeric input with validation:
```html
<input type="number" name="age" min="18" max="100" step="1">
```

#### 4. Range
Slider control:
```html
<input type="range" name="volume" min="0" max="100" value="50">
```

#### 5. Date
Date picker:
```html
<input type="date" name="birthday" min="1990-01-01" max="2024-12-31">
```

#### 6. Time
Time selector:
```html
<input type="time" name="appointment">
```

#### 7. Datetime-local
Date and time picker:
```html
<input type="datetime-local" name="meeting">
```

#### 8. Month
Month and year picker:
```html
<input type="month" name="expiry">
```

#### 9. Week
Week selector:
```html
<input type="week" name="week">
```

#### 10. Color
Color picker:
```html
<input type="color" name="favcolor" value="#ff0000">
```

#### 11. Search
Search field with clear button:
```html
<input type="search" name="query">
```

#### 12. Tel
Telephone number input:
```html
<input type="tel" name="phone" pattern="[0-9]{10}">
```

---

## HTML INPUT ATTRIBUTES

### Basic Attributes:
1. **value**: Default value of input
2. **name**: Identifies the input field
3. **id**: Unique identifier for the element
4. **class**: CSS class for styling

### HTML5 New Attributes:

#### 1. required
Makes field mandatory:
```html
<input type="text" name="username" required>
```

#### 2. placeholder
Displays hint text:
```html
<input type="email" placeholder="Enter your email">
```

#### 3. autofocus
Automatically focuses on page load:
```html
<input type="text" autofocus>
```

#### 4. readonly
Makes field non-editable:
```html
<input type="text" value="Cannot edit" readonly>
```

#### 5. disabled
Disables the input field:
```html
<input type="text" disabled>
```

#### 6. pattern
Defines regex validation pattern:
```html
<input type="text" pattern="[A-Za-z]{3,}" title="Min 3 letters">
```

#### 7. min and max
Set minimum and maximum values:
```html
<input type="number" min="1" max="100">
<input type="date" min="2024-01-01" max="2024-12-31">
```

#### 8. maxlength and minlength
Character limits:
```html
<input type="text" maxlength="50" minlength="3">
```

#### 9. multiple
Allows multiple values:
```html
<input type="file" multiple>
<input type="email" multiple>
```

#### 10. step
Defines legal number intervals:
```html
<input type="number" step="5">
<input type="range" step="10">
```

#### 11. autocomplete
Controls browser autocomplete:
```html
<input type="email" autocomplete="on">
<input type="password" autocomplete="off">
```

#### 12. form
Associates input with form:
```html
<form id="myform"></form>
<input type="text" form="myform">
```

#### 13. formaction
Overrides form action for submit buttons:
```html
<input type="submit" formaction="save.php" value="Save">
```

#### 14. formmethod
Overrides form method:
```html
<input type="submit" formmethod="POST">
```

#### 15. list
References datalist element:
```html
<input type="text" list="suggestions">
```

#### 16. accept
Specifies file types for file input:
```html
<input type="file" accept="image/*,.pdf">
```

---

## HTML GRAPHICS

### 1. Canvas Element
The `<canvas>` element is used to draw graphics dynamically using JavaScript.

```html
<canvas id="myCanvas" width="500" height="300">
  Your browser does not support canvas
</canvas>

<script>
var canvas = document.getElementById('myCanvas');
var ctx = canvas.getContext('2d');

// Draw rectangle
ctx.fillStyle = '#FF0000';
ctx.fillRect(20, 20, 150, 100);

// Draw circle
ctx.beginPath();
ctx.arc(250, 75, 50, 0, 2 * Math.PI);
ctx.stroke();

// Draw text
ctx.font = '30px Arial';
ctx.fillText('Hello Canvas', 50, 200);
</script>
```

**Key Features:**
- Resolution-dependent bitmap
- Good for animations and games
- Pixel manipulation
- Can draw shapes, text, images
- Event handling more complex

**Common Methods:**
- fillRect(), strokeRect(): Draw rectangles
- arc(), beginPath(), closePath(): Draw circles and paths
- fillText(), strokeText(): Draw text
- drawImage(): Draw images
- clearRect(): Clear canvas area

### 2. SVG (Scalable Vector Graphics)
SVG defines vector-based graphics in XML format.

```html
<svg width="500" height="300">
  <!-- Rectangle -->
  <rect x="20" y="20" width="150" height="100"
        fill="blue" stroke="black" stroke-width="2"/>

  <!-- Circle -->
  <circle cx="250" cy="75" r="50"
          fill="red" stroke="green" stroke-width="2"/>

  <!-- Line -->
  <line x1="0" y1="0" x2="200" y2="200"
        stroke="purple" stroke-width="3"/>

  <!-- Text -->
  <text x="50" y="200" font-family="Arial"
        font-size="30" fill="black">Hello SVG</text>

  <!-- Polygon (Triangle) -->
  <polygon points="300,200 350,150 400,200"
           fill="yellow" stroke="orange" stroke-width="2"/>
</svg>
```

**SVG vs Canvas:**

| Feature | SVG | Canvas |
|---------|-----|--------|
| Type | Vector | Raster/Bitmap |
| Scalability | Scales without quality loss | Pixelated when scaled |
| File Size | Larger for complex images | Smaller |
| Performance | Slower with many objects | Better for many objects |
| Manipulation | Easy with CSS/JavaScript | Only through JavaScript |
| Accessibility | Better (DOM-based) | Limited |

**When to use SVG:**
- Logos and icons
- Charts and graphs
- Maps
- Images that need to scale

**When to use Canvas:**
- Games
- Real-time animations
- Photo manipulation
- Heavy graphical operations

---

## HTML MEDIA

### 1. Audio Element
Embeds sound content:

```html
<audio controls autoplay loop muted>
  <source src="audio.mp3" type="audio/mpeg">
  <source src="audio.ogg" type="audio/ogg">
  <source src="audio.wav" type="audio/wav">
  Your browser does not support audio element.
</audio>
```

**Attributes:**
- **controls**: Shows play, pause, volume controls
- **autoplay**: Starts playing automatically
- **loop**: Repeats audio continuously
- **muted**: Starts muted
- **preload**: How audio should be loaded
  - none: Don't preload
  - metadata: Load only metadata
  - auto: Load entire audio file

**Supported Formats:**
- MP3 (MPEG Audio Layer 3)
- OGG (Ogg Vorbis)
- WAV (Waveform Audio File)

**JavaScript Control:**
```html
<audio id="myAudio" src="song.mp3"></audio>
<button onclick="document.getElementById('myAudio').play()">Play</button>
<button onclick="document.getElementById('myAudio').pause()">Pause</button>
```

### 2. Video Element
Embeds video content:

```html
<video width="640" height="360" controls poster="thumbnail.jpg">
  <source src="video.mp4" type="video/mp4">
  <source src="video.webm" type="video/webm">
  <source src="video.ogg" type="video/ogg">
  Your browser does not support video element.
</video>
```

**Attributes:**
- **width/height**: Video dimensions
- **controls**: Shows video controls
- **autoplay**: Auto-start video
- **loop**: Loop video
- **muted**: Start muted
- **poster**: Image shown before video plays
- **preload**: Preloading behavior

**Supported Formats:**
- MP4 (H.264)
- WebM (VP8/VP9)
- OGG (Theora)

### 3. Embed Element (Legacy)
Generic container for multimedia:

```html
<embed src="file.swf" width="400" height="300" type="application/x-shockwave-flash">
```

### 4. Object Element
Embeds external resources:

```html
<object data="document.pdf" type="application/pdf" width="600" height="400">
  <p>PDF cannot be displayed. <a href="document.pdf">Download</a></p>
</object>
```

### 5. Track Element
Provides text tracks for video (subtitles, captions):

```html
<video controls>
  <source src="movie.mp4" type="video/mp4">
  <track src="subtitles_en.vtt" kind="subtitles" srclang="en" label="English">
  <track src="subtitles_hi.vtt" kind="subtitles" srclang="hi" label="Hindi">
</video>
```

**Track Kinds:**
- subtitles: Translation of dialogue
- captions: Transcription including sound effects
- descriptions: Text description of video
- chapters: Chapter titles
- metadata: Not visible to user

---

## HTML5 NEW ELEMENTS

### Semantic Elements
HTML5 introduced semantic elements that clearly describe their meaning:

#### 1. `<header>`
Represents introductory content:
```html
<header>
  <h1>Website Title</h1>
  <nav><!-- Navigation --></nav>
</header>
```

#### 2. `<nav>`
Defines navigation links:
```html
<nav>
  <ul>
    <li><a href="#home">Home</a></li>
    <li><a href="#about">About</a></li>
    <li><a href="#contact">Contact</a></li>
  </ul>
</nav>
```

#### 3. `<section>`
Defines a thematic grouping of content:
```html
<section>
  <h2>About Us</h2>
  <p>Company information...</p>
</section>
```

#### 4. `<article>`
Represents independent, self-contained content:
```html
<article>
  <h2>Blog Post Title</h2>
  <p>Published on <time datetime="2024-01-15">January 15, 2024</time></p>
  <p>Article content...</p>
</article>
```

#### 5. `<aside>`
Content indirectly related to main content:
```html
<aside>
  <h3>Related Links</h3>
  <ul>
    <li><a href="#">Link 1</a></li>
  </ul>
</aside>
```

#### 6. `<footer>`
Footer for document or section:
```html
<footer>
  <p>&copy; 2024 Company Name. All rights reserved.</p>
  <p>Contact: info@example.com</p>
</footer>
```

#### 7. `<main>`
Main content of document:
```html
<main>
  <article>
    <!-- Primary content -->
  </article>
</main>
```

#### 8. `<figure>` and `<figcaption>`
Self-contained content with optional caption:
```html
<figure>
  <img src="chart.png" alt="Sales Chart">
  <figcaption>Fig 1: Annual Sales Report 2024</figcaption>
</figure>
```

#### 9. `<mark>`
Highlighted or marked text:
```html
<p>This is <mark>important</mark> text.</p>
```

#### 10. `<time>`
Represents date/time:
```html
<time datetime="2024-01-15T14:30">January 15, 2024 at 2:30 PM</time>
```

#### 11. `<details>` and `<summary>`
Creates collapsible content:
```html
<details>
  <summary>Click to expand</summary>
  <p>Hidden content that can be toggled</p>
</details>
```

#### 12. `<progress>`
Shows completion progress:
```html
<progress value="70" max="100">70%</progress>
```

#### 13. `<meter>`
Displays a scalar measurement:
```html
<meter value="6" min="0" max="10">6 out of 10</meter>
```

---

## HTML SEMANTICS

### What is Semantic HTML?
Semantic HTML uses HTML tags that carry meaning about the content they contain, making code more readable and accessible.

### Benefits of Semantic HTML:
1. **Accessibility**: Screen readers can better interpret page structure
2. **SEO**: Search engines understand content hierarchy better
3. **Maintainability**: Easier to read and maintain code
4. **Consistency**: Standardized structure across developers

### Non-Semantic vs Semantic Examples:

**Non-Semantic (Old approach):**
```html
<div id="header">
  <div id="nav">
    <div class="link">Home</div>
  </div>
</div>
<div id="content">
  <div class="post">Article content</div>
</div>
<div id="footer">Copyright info</div>
```

**Semantic (Modern approach):**
```html
<header>
  <nav>
    <a href="#">Home</a>
  </nav>
</header>
<main>
  <article>Article content</article>
</main>
<footer>Copyright info</footer>
```

### Semantic Document Structure:
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Semantic Page</title>
</head>
<body>
  <header>
    <h1>Site Title</h1>
    <nav>
      <ul>
        <li><a href="#home">Home</a></li>
        <li><a href="#services">Services</a></li>
      </ul>
    </nav>
  </header>

  <main>
    <section>
      <h2>Welcome Section</h2>
      <p>Introduction text...</p>
    </section>

    <article>
      <header>
        <h2>Article Title</h2>
        <time datetime="2024-01-15">January 15, 2024</time>
      </header>
      <p>Article content...</p>
      <footer>
        <p>Author: John Doe</p>
      </footer>
    </article>

    <aside>
      <h3>Sidebar</h3>
      <p>Additional information</p>
    </aside>
  </main>

  <footer>
    <p>&copy; 2024 Company</p>
  </footer>
</body>
</html>
```

---

## HTML MIGRATION

### Migrating from HTML4 to HTML5

#### 1. DOCTYPE Declaration
**HTML4:**
```html
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
"http://www.w3.org/TR/html4/strict.dtd">
```

**HTML5:**
```html
<!DOCTYPE html>
```

#### 2. Character Encoding
**HTML4:**
```html
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
```

**HTML5:**
```html
<meta charset="UTF-8">
```

#### 3. Replacing Deprecated Tags

**Deprecated tags to avoid:**
- `<font>` → Use CSS
- `<center>` → Use CSS (text-align: center)
- `<strike>` → Use `<del>` or CSS
- `<u>` → Use CSS (text-decoration: underline)
- `<big>`, `<small>` (partially deprecated) → Use CSS
- `<frame>`, `<frameset>` → Use CSS layout or iframe
- `<acronym>` → Use `<abbr>`

**Migration Examples:**
```html
<!-- Old HTML4 -->
<font color="red" size="5">Text</font>

<!-- New HTML5 -->
<span style="color: red; font-size: 1.5em;">Text</span>
```

```html
<!-- Old HTML4 -->
<center>Centered content</center>

<!-- New HTML5 -->
<div style="text-align: center;">Centered content</div>
```

#### 4. Using Semantic Elements
Replace generic divs:
```html
<!-- Old HTML4 -->
<div id="header">...</div>
<div id="menu">...</div>
<div id="content">...</div>
<div id="footer">...</div>

<!-- New HTML5 -->
<header>...</header>
<nav>...</nav>
<main>...</main>
<footer>...</footer>
```

#### 5. Multimedia Updates
```html
<!-- Old HTML4 -->
<embed src="video.avi" width="400" height="300">
<object data="audio.mp3"></object>

<!-- New HTML5 -->
<video src="video.mp4" controls></video>
<audio src="audio.mp3" controls></audio>
```

#### 6. Form Enhancements
```html
<!-- Old HTML4 - Basic validation -->
<input type="text" name="email">

<!-- New HTML5 - Built-in validation -->
<input type="email" name="email" required placeholder="Enter email">
```

---

## HTML STYLE GUIDE

### 1. Document Type Declaration
Always declare DOCTYPE as the first line:
```html
<!DOCTYPE html>
```

### 2. Use Lowercase Element Names
```html
<!-- Good -->
<body>
  <p>Content</p>
</body>

<!-- Avoid -->
<BODY>
  <P>Content</P>
</BODY>
```

### 3. Close All HTML Elements
```html
<!-- Good -->
<p>Paragraph</p>
<br>
<img src="image.jpg" alt="Description">

<!-- Avoid (even though valid) -->
<p>Paragraph
<br>
<img src="image.jpg" alt="Description">
```

### 4. Use Lowercase Attribute Names
```html
<!-- Good -->
<input type="text" name="username">

<!-- Avoid -->
<input TYPE="text" NAME="username">
```

### 5. Quote Attribute Values
Always use quotes:
```html
<!-- Good -->
<img src="image.jpg" alt="Image description">

<!-- Avoid -->
<img src=image.jpg alt=Image>
```

### 6. Specify alt, width, and height for Images
```html
<img src="logo.png" alt="Company Logo" width="200" height="100">
```

### 7. Proper Indentation and Spacing
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Page Title</title>
</head>
<body>
  <header>
    <h1>Main Heading</h1>
    <nav>
      <ul>
        <li><a href="#home">Home</a></li>
        <li><a href="#about">About</a></li>
      </ul>
    </nav>
  </header>

  <main>
    <section>
      <h2>Section Title</h2>
      <p>Paragraph content.</p>
    </section>
  </main>

  <footer>
    <p>&copy; 2024 Company Name</p>
  </footer>
</body>
</html>
```

### 8. Avoid Long Code Lines
Keep lines under 80 characters when possible.

### 9. Use Semantic HTML
Use appropriate tags for content meaning:
```html
<!-- Good -->
<nav>
  <ul>
    <li><a href="#home">Home</a></li>
  </ul>
</nav>

<!-- Avoid -->
<div class="navigation">
  <span class="menu-item">Home</span>
</div>
```

### 10. Add Comments for Complex Sections
```html
<!-- Navigation Section -->
<nav>
  <!-- Main menu items -->
</nav>

<!-- Main Content Area -->
<main>
  <!-- Articles and posts -->
</main>
```

### 11. Use Valid HTML
Validate code using W3C HTML Validator.

### 12. Accessibility Best Practices
- Use `alt` attributes for images
- Use `label` elements for form inputs
- Maintain proper heading hierarchy (h1, h2, h3...)
- Use ARIA labels when necessary
- Ensure sufficient color contrast

### 13. Loading External Resources
```html
<!-- Link CSS in head -->
<head>
  <link rel="stylesheet" href="styles.css">
</head>

<!-- Load JavaScript before closing body tag -->
<body>
  <!-- Content -->
  <script src="script.js"></script>
</body>
```

### 14. Use Meta Tags Appropriately
```html
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta name="description" content="Page description for SEO">
  <meta name="keywords" content="html, css, javascript">
  <meta name="author" content="Your Name">
  <title>Page Title - Max 60 Characters</title>
</head>
```

---

## HTML5 BROWSER SUPPORT

### Browser Compatibility
All modern browsers support HTML5 features:
- Chrome 4+
- Firefox 3.5+
- Safari 4+
- Opera 10.5+
- Internet Explorer 9+
- Edge (all versions)

### Handling Older Browsers
For IE8 and older, use HTML5 Shiv:
```html
<!--[if lt IE 9]>
  <script src="https://oss.maxcdn.com/html5shiv/3.7.3/html5shiv.min.js"></script>
<![endif]-->
```

### Feature Detection
Use JavaScript to detect feature support:
```javascript
if (typeof(Storage) !== "undefined") {
  // LocalStorage supported
} else {
  // No support for LocalStorage
}

// Check canvas support
var canvas = document.createElement('canvas');
if (canvas.getContext) {
  // Canvas supported
}

// Check video support
var video = document.createElement('video');
if (video.canPlayType) {
  // Video supported
}
```

### Polyfills
Use polyfills to add HTML5 functionality to older browsers:
- Modernizr: Feature detection library
- Webshims: Polyfill library for HTML5 features
- Picturefill: Responsive images for older browsers

---

## PRACTICAL COMPLETE EXAMPLE

### Complete Registration Form with HTML5 Features

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>User Registration Form</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      max-width: 600px;
      margin: 50px auto;
      padding: 20px;
      background-color: #f4f4f4;
    }
    form {
      background: white;
      padding: 30px;
      border-radius: 8px;
      box-shadow: 0 2px 5px rgba(0,0,0,0.1);
    }
    fieldset {
      border: 2px solid #ddd;
      padding: 15px;
      margin-bottom: 20px;
      border-radius: 5px;
    }
    legend {
      font-weight: bold;
      color: #333;
      padding: 0 10px;
    }
    label {
      display: block;
      margin: 10px 0 5px;
      font-weight: bold;
    }
    input, select, textarea {
      width: 100%;
      padding: 8px;
      margin-bottom: 15px;
      border: 1px solid #ddd;
      border-radius: 4px;
      box-sizing: border-box;
    }
    input:focus {
      border-color: #4CAF50;
      outline: none;
    }
    button {
      background-color: #4CAF50;
      color: white;
      padding: 12px 30px;
      border: none;
      border-radius: 4px;
      cursor: pointer;
      font-size: 16px;
    }
    button:hover {
      background-color: #45a049;
    }
  </style>
</head>
<body>
  <form action="register.php" method="POST" enctype="multipart/form-data">
    <h1>User Registration</h1>

    <fieldset>
      <legend>Personal Information</legend>

      <label for="fullname">Full Name *</label>
      <input type="text" id="fullname" name="fullname"
             required minlength="3" maxlength="50"
             placeholder="Enter your full name">

      <label for="email">Email Address *</label>
      <input type="email" id="email" name="email"
             required placeholder="example@email.com">

      <label for="phone">Phone Number *</label>
      <input type="tel" id="phone" name="phone"
             pattern="[0-9]{10}" required
             placeholder="10 digit mobile number">

      <label for="dob">Date of Birth *</label>
      <input type="date" id="dob" name="dob"
             min="1950-01-01" max="2010-12-31" required>

      <label>Gender *</label>
      <input type="radio" id="male" name="gender" value="male" required>
      <label for="male" style="display:inline; margin-right:20px;">Male</label>
      <input type="radio" id="female" name="gender" value="female">
      <label for="female" style="display:inline; margin-right:20px;">Female</label>
      <input type="radio" id="other" name="gender" value="other">
      <label for="other" style="display:inline;">Other</label>
    </fieldset>

    <fieldset>
      <legend>Account Details</legend>

      <label for="username">Username *</label>
      <input type="text" id="username" name="username"
             required minlength="5" pattern="[A-Za-z0-9]+"
             placeholder="Alphanumeric only">

      <label for="password">Password *</label>
      <input type="password" id="password" name="password"
             required minlength="8"
             placeholder="Minimum 8 characters">

      <label for="confirm">Confirm Password *</label>
      <input type="password" id="confirm" name="confirm"
             required minlength="8">

      <label for="profile">Profile Picture</label>
      <input type="file" id="profile" name="profile"
             accept="image/*">
    </fieldset>

    <fieldset>
      <legend>Additional Information</legend>

      <label for="country">Country *</label>
      <select id="country" name="country" required>
        <option value="">Select Country</option>
        <option value="india">India</option>
        <option value="usa">United States</option>
        <option value="uk">United Kingdom</option>
        <option value="canada">Canada</option>
      </select>

      <label for="website">Website/Portfolio</label>
      <input type="url" id="website" name="website"
             placeholder="https://example.com">

      <label for="age">Age</label>
      <input type="number" id="age" name="age"
             min="18" max="100">

      <label for="bio">Bio</label>
      <textarea id="bio" name="bio" rows="4"
                maxlength="500"
                placeholder="Tell us about yourself (max 500 characters)"></textarea>

      <label>Interests</label>
      <input type="checkbox" id="tech" name="interests[]" value="technology">
      <label for="tech" style="display:inline; margin-right:15px;">Technology</label>
      <input type="checkbox" id="sports" name="interests[]" value="sports">
      <label for="sports" style="display:inline; margin-right:15px;">Sports</label>
      <input type="checkbox" id="music" name="interests[]" value="music">
      <label for="music" style="display:inline;">Music</label>

      <br><br>
      <input type="checkbox" id="terms" name="terms" required>
      <label for="terms" style="display:inline;">
        I agree to the terms and conditions *
      </label>
    </fieldset>

    <button type="submit">Register</button>
    <button type="reset">Clear Form</button>
  </form>
</body>
</html>
```

---

You're absolutely right! Let me add proper definitions for semantic tags before the examples:

---

## HTML SEMANTICS - DETAILED DEFINITIONS

### What is Semantic HTML?
Semantic HTML refers to HTML markup that conveys meaning about the content it contains, rather than just describing how it should look. Semantic elements clearly describe their purpose and content to both the browser and the developer.

### Why Use Semantic HTML?
1. **Better Accessibility**: Screen readers and assistive technologies can better interpret page structure
2. **Improved SEO**: Search engines understand content hierarchy and importance
3. **Code Readability**: Developers can easily understand page structure
4. **Maintainability**: Easier to update and modify code
5. **Consistency**: Standard structure across different projects

---

## HTML5 SEMANTIC ELEMENTS - DETAILED DEFINITIONS

### 1. `<header>` Element
**Definition**: The `<header>` element represents introductory content or a container for navigational links. It typically contains headings, logos, author information, or navigation menus.

**Purpose**:
- Contains the page or section header
- Can be used multiple times in a document
- Usually placed at the top of a page or section

**Usage**:
```html
<header>
  <h1>Website Title</h1>
  <nav>
    <ul>
      <li><a href="#home">Home</a></li>
    </ul>
  </nav>
</header>
```

**Key Points**:
- Can contain multiple heading elements (h1-h6)
- Often contains site logo and main navigation
- Can be used inside `<article>` or `<section>` elements

---

### 2. `<nav>` Element
**Definition**: The `<nav>` element defines a section of navigation links. It is intended for major navigation blocks only, not all groups of links.

**Purpose**:
- Contains primary navigation links
- Helps screen readers identify navigation areas
- Improves page structure and organization

**Usage**:
```html
<nav>
  <ul>
    <li><a href="#home">Home</a></li>
    <li><a href="#about">About</a></li>
    <li><a href="#services">Services</a></li>
    <li><a href="#contact">Contact</a></li>
  </ul>
</nav>
```

**Key Points**:
- Use for main site navigation, not footer links or aside links
- Can have multiple `<nav>` elements (main menu, sidebar menu)
- Not all link groups need to be in `<nav>`

---

### 3. `<main>` Element
**Definition**: The `<main>` element represents the dominant content of the `<body>` of a document. It contains the central topic or main functionality of the page.

**Purpose**:
- Identifies the primary content of the document
- Content should be unique to the document
- Excludes content repeated across pages (sidebars, navigation, footer)

**Usage**:
```html
<main>
  <h1>Welcome to Our Website</h1>
  <article>
    <h2>Main Article</h2>
    <p>This is the primary content of the page.</p>
  </article>
</main>
```

**Key Points**:
- Only ONE `<main>` element per page
- Should not be inside `<article>`, `<aside>`, `<footer>`, `<header>`, or `<nav>`
- Helps accessibility tools skip to main content

---

### 4. `<section>` Element
**Definition**: The `<section>` element represents a thematic grouping of content, typically with a heading. It is used to divide content into distinct sections based on theme or purpose.

**Purpose**:
- Groups related content together
- Each section should have a theme or topic
- Usually includes a heading (h1-h6)

**Usage**:
```html
<section>
  <h2>About Us</h2>
  <p>Information about our company...</p>
</section>

<section>
  <h2>Our Services</h2>
  <p>Details about services we offer...</p>
</section>
```

**Key Points**:
- Should have a heading to identify its purpose
- Use when content is related to a single theme
- Can contain multiple articles or other sections

---

### 5. `<article>` Element
**Definition**: The `<article>` element represents a self-contained, independent piece of content that could be distributed or reused independently. Examples include blog posts, news articles, forum posts, or comments.

**Purpose**:
- Contains complete, standalone content
- Can be distributed separately from the rest of the page
- Makes sense when read in isolation

**Usage**:
```html
<article>
  <h2>Understanding HTML5 Semantics</h2>
  <p>Published on <time datetime="2024-01-15">January 15, 2024</time></p>
  <p>Article content goes here...</p>
  <footer>
    <p>Written by: John Doe</p>
  </footer>
</article>
```

**Key Points**:
- Each article should be independently distributable
- Can contain its own header and footer
- Suitable for blog posts, news articles, user comments
- Can be nested (e.g., comments inside article)

---

### 6. `<aside>` Element
**Definition**: The `<aside>` element represents content that is tangentially related to the main content. It contains information that is separate from but related to the surrounding content.

**Purpose**:
- Contains supplementary information
- Sidebars, pull quotes, advertisements
- Related links or additional information

**Usage**:
```html
<aside>
  <h3>Related Articles</h3>
  <ul>
    <li><a href="#">Article 1</a></li>
    <li><a href="#">Article 2</a></li>
  </ul>
</aside>

<aside>
  <h4>Did You Know?</h4>
  <p>Interesting fact related to main content...</p>
</aside>
```

**Key Points**:
- Content should be indirectly related to main content
- Common for sidebars and callout boxes
- Can be removed without affecting main content understanding

---

### 7. `<footer>` Element
**Definition**: The `<footer>` element represents footer content for its nearest sectioning element or root. It typically contains information about the author, copyright, contact information, or related documents.

**Purpose**:
- Contains closing or supplementary information
- Copyright notices, contact details, sitemap links
- Can be used multiple times in a document

**Usage**:
```html
<footer>
  <p>&copy; 2024 Company Name. All rights reserved.</p>
  <p>Contact us: <a href="mailto:info@example.com">info@example.com</a></p>
  <nav>
    <a href="#privacy">Privacy Policy</a> |
    <a href="#terms">Terms of Service</a>
  </nav>
</footer>
```

**Key Points**:
- Can be used for page footer or section footer
- Multiple footers allowed in a document
- Often contains metadata about the content

---

### 8. `<figure>` and `<figcaption>` Elements
**Definition**: The `<figure>` element represents self-contained content, like illustrations, diagrams, photos, or code listings. The `<figcaption>` element provides a caption or legend for the figure.

**Purpose**:
- Groups media content with its caption
- Makes relationship between image and caption explicit
- Improves accessibility

**Usage**:
```html
<figure>
  <img src="chart.png" alt="Annual Sales Chart">
  <figcaption>
    Figure 1: Annual Sales Report showing 25% growth in 2024
  </figcaption>
</figure>

<figure>
  <pre><code>
    function hello() {
      console.log("Hello World");
    }
  </code></pre>
  <figcaption>Listing 1: Simple JavaScript function</figcaption>
</figure>
```

**Key Points**:
- Caption is optional but recommended
- Can contain images, illustrations, code, or diagrams
- Content can be moved to appendix without affecting flow

---

### 9. `<mark>` Element
**Definition**: The `<mark>` element represents highlighted or marked text for reference or notation purposes. It indicates text that has relevance in a particular context.

**Purpose**:
- Highlights important text
- Search results highlighting
- Emphasizes specific portions of quoted text

**Usage**:
```html
<p>Search results for "HTML5":</p>
<p>Learn <mark>HTML5</mark> semantic elements for better web development.</p>

<p>The meeting is scheduled for <mark>January 15, 2024</mark>.</p>
```

**Key Points**:
- Default browser styling: yellow background
- Different from `<strong>` (importance) and `<em>` (emphasis)
- Used for highlighting, not for emphasis

---

### 10. `<time>` Element
**Definition**: The `<time>` element represents a specific time or date. It provides a machine-readable format for dates and times.

**Purpose**:
- Marks up dates and times
- Provides machine-readable datetime information
- Helps search engines and browsers understand temporal data

**Usage**:
```html
<!-- Date only -->
<time datetime="2024-01-15">January 15, 2024</time>

<!-- Date and time -->
<time datetime="2024-01-15T14:30">January 15, 2024 at 2:30 PM</time>

<!-- Time only -->
<time datetime="14:30">2:30 PM</time>

<!-- Duration -->
<time datetime="PT2H30M">2 hours 30 minutes</time>
```

**Key Points**:
- datetime attribute provides machine-readable format
- Visible text can be in any format
- Helps with event scheduling and calendars

---

### 11. `<details>` and `<summary>` Elements
**Definition**: The `<details>` element creates a disclosure widget that can be toggled open and closed. The `<summary>` element provides a visible heading for the details.

**Purpose**:
- Creates collapsible/expandable sections
- Hides less important information by default
- Improves page organization without JavaScript

**Usage**:
```html
<details>
  <summary>Click to view more information</summary>
  <p>This content is hidden by default and can be toggled.</p>
  <ul>
    <li>Additional detail 1</li>
    <li>Additional detail 2</li>
  </ul>
</details>

<details open>
  <summary>System Requirements</summary>
  <p>Windows 10 or higher, 8GB RAM, 500GB storage</p>
</details>
```

**Key Points**:
- No JavaScript required for functionality
- `open` attribute makes it expanded by default
- Only one `<summary>` per `<details>`

---

### 12. `<progress>` Element
**Definition**: The `<progress>` element represents the completion progress of a task, such as a download, file upload, or installation process.

**Purpose**:
- Shows progress visually
- Indicates task completion percentage
- Provides feedback to users

**Usage**:
```html
<!-- With specific values -->
<label for="file">Download progress:</label>
<progress id="file" value="70" max="100">70%</progress>

<!-- Indeterminate progress (no value) -->
<progress></progress>

<!-- With JavaScript update -->
<progress id="upload" value="0" max="100"></progress>
<script>
  let progress = 0;
  setInterval(() => {
    progress += 10;
    document.getElementById('upload').value = progress;
  }, 1000);
</script>
```

**Key Points**:
- `value` attribute: current progress
- `max` attribute: maximum value (default 100)
- Without `value`: shows indeterminate progress

---

### 13. `<meter>` Element
**Definition**: The `<meter>` element represents a scalar measurement within a known range, such as disk usage, battery level, or voting results.

**Purpose**:
- Displays measurements or gauges
- Shows value within a defined range
- Different from progress (not for tasks)

**Usage**:
```html
<!-- Simple meter -->
<label for="fuel">Fuel level:</label>
<meter id="fuel" value="60" min="0" max="100">60%</meter>

<!-- With optimal range -->
<label for="grade">Test Score:</label>
<meter id="grade" value="85" min="0" max="100"
       low="40" high="80" optimum="90">85/100</meter>

<!-- Disk usage -->
<label for="disk">Disk Usage:</label>
<meter id="disk" value="0.8" min="0" max="1"
       low="0.3" high="0.7" optimum="0.2">80%</meter>
```

**Attributes**:
- `value`: Current value
- `min`, `max`: Range boundaries
- `low`, `high`: Define low and high ranges
- `optimum`: Optimal value position

**Key Points**:
- NOT for progress indication (use `<progress>` instead)
- Colors change based on low/high/optimum values
- Use for measurements, not task completion

---

### 14. `<address>` Element
**Definition**: The `<address>` element represents contact information for a person, people, or organization.

**Purpose**:
- Marks up contact information
- Can include email, phone, physical address
- Provides semantic meaning to contact details

**Usage**:
```html
<address>
  <p>Contact us at:</p>
  <p>
    Email: <a href="mailto:info@example.com">info@example.com</a><br>
    Phone: <a href="tel:+919876543210">+91 9876543210</a><br>
    Address: 123 Main Street, City, State 123456
  </p>
</address>

<article>
  <h2>Article Title</h2>
  <p>Article content...</p>
  <footer>
    <address>
      Written by <a href="mailto:author@example.com">John Doe</a>
    </address>
  </footer>
</article>
```

**Key Points**:
- Usually italicized by default
- Can be nested in `<footer>` for author info
- Should only contain contact information

---

## COMPLETE SEMANTIC HTML5 DOCUMENT STRUCTURE

Now that we've defined all semantic elements, here's how they work together:

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Complete Semantic HTML5 Page</title>
</head>
<body>

  <!-- Page Header -->
  <header>
    <h1>Tech News Portal</h1>
    <p>Your source for latest technology updates</p>

    <!-- Main Navigation -->
    <nav>
      <ul>
        <li><a href="#home">Home</a></li>
        <li><a href="#articles">Articles</a></li>
        <li><a href="#about">About</a></li>
        <li><a href="#contact">Contact</a></li>
      </ul>
    </nav>
  </header>

  <!-- Main Content Area -->
  <main>

    <!-- Introduction Section -->
    <section id="home">
      <h2>Welcome to Tech News</h2>
      <p>Stay updated with the latest in technology.</p>
    </section>

    <!-- Articles Section -->
    <section id="articles">
      <h2>Latest Articles</h2>

      <!-- Individual Article -->
      <article>
        <header>
          <h3>Understanding HTML5 Semantic Elements</h3>
          <p>Published on <time datetime="2024-01-15">January 15, 2024</time></p>
        </header>

        <p>HTML5 introduced many new <mark>semantic elements</mark> that make web development more meaningful and accessible.</p>

        <figure>
          <img src="html5-diagram.png" alt="HTML5 Structure Diagram" width="400">
          <figcaption>Figure 1: HTML5 Document Structure</figcaption>
        </figure>

        <details>
          <summary>Read More</summary>
          <p>Semantic elements include header, nav, main, section, article, aside, footer, and many more. Each element has a specific purpose and meaning.</p>
        </details>

        <footer>
          <address>
            Written by <a href="mailto:john@example.com">John Doe</a>
          </address>
        </footer>
      </article>

      <!-- Another Article -->
      <article>
        <header>
          <h3>Web Accessibility Best Practices</h3>
          <p>Published on <time datetime="2024-01-10">January 10, 2024</time></p>
        </header>

        <p>Making websites accessible ensures everyone can use your content effectively.</p>

        <p>Project completion: <progress value="75" max="100">75%</progress></p>
        <p>User satisfaction: <meter value="8.5" min="0" max="10" optimum="9">8.5/10</meter></p>

        <footer>
          <address>
            Written by <a href="mailto:jane@example.com">Jane Smith</a>
          </address>
        </footer>
      </article>

    </section>

  </main>

  <!-- Sidebar with Related Content -->
  <aside>
    <h2>Related Resources</h2>
    <ul>
      <li><a href="#">HTML5 Documentation</a></li>
      <li><a href="#">CSS3 Guide</a></li>
      <li><a href="#">JavaScript Tutorials</a></li>
    </ul>

    <h3>Quick Tip</h3>
    <p>Always use semantic HTML for better SEO and accessibility!</p>
  </aside>

  <!-- Page Footer -->
  <footer>
    <nav>
      <ul>
        <li><a href="#privacy">Privacy Policy</a></li>
        <li><a href="#terms">Terms of Service</a></li>
        <li><a href="#sitemap">Sitemap</a></li>
      </ul>
    </nav>

    <address>
      <p>Contact us:</p>
      <p>Email: <a href="mailto:info@technews.com">info@technews.com</a></p>
      <p>Phone: <a href="tel:+919876543210">+91 9876543210</a></p>
    </address>

    <p>&copy; 2024 Tech News Portal. All rights reserved.</p>
  </footer>

</body>
</html>
```

---

This comprehensive structure shows how all semantic elements work together to create a meaningful, accessible, and well-organized HTML5 document.
