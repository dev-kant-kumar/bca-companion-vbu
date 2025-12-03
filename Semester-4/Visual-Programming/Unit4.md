# Unit 4: Windows Forms - Detailed Notes

## Introduction to Windows Forms

- **Windows Forms (WinForms)** is a GUI framework included in .NET Framework for building desktop applications
- Provides a rich set of pre-built controls and components for creating interactive user interfaces
- Event-driven programming model where user actions trigger specific code execution
- Forms are the containers that hold various controls and components
- Uses drag-and-drop design in Visual Studio for rapid application development

## Working with Windows Forms

- **Form Class**: Base class for creating windows/forms in an application
- **Properties of Forms**:
  - Text: Sets the title bar text of the form
  - Size: Defines width and height of the form
  - BackColor: Sets background color
  - StartPosition: Determines where form appears on screen (CenterScreen, Manual, etc.)
  - FormBorderStyle: Controls appearance of border (Fixed, Sizable, None, etc.)
  - MaximizeBox/MinimizeBox: Enable/disable maximize and minimize buttons

- **Common Form Events**:
  - Load: Occurs when form is first displayed
  - Click: Triggered when form is clicked
  - FormClosing: Fires before form closes (can cancel closing)
  - FormClosed: Occurs after form has closed

- **Form Methods**:
  - Show(): Displays form non-modally
  - ShowDialog(): Displays form as modal dialog
  - Close(): Closes the form
  - Hide(): Hides form without closing it

## Button Control

- Used to trigger actions when clicked by user
- **Key Properties**:
  - Text: Label displayed on button
  - Enabled: Controls whether button can be clicked
  - BackColor/ForeColor: Sets button colors
  - FlatStyle: Changes visual appearance (Flat, Popup, Standard)
  - Image: Displays an image on button
  - TextAlign: Aligns text position on button

- **Primary Event**: Click event - executes code when button is pressed
- Commonly used for form submission, navigation, executing commands
- Can include keyboard shortcuts using ampersand (&) in Text property

## TextBox Control

- Allows users to enter and edit text input
- **Important Properties**:
  - Text: Gets or sets the text content
  - Multiline: Enables multiple lines of text (true/false)
  - PasswordChar: Masks input characters (for passwords)
  - ReadOnly: Makes textbox non-editable
  - MaxLength: Limits maximum character input
  - ScrollBars: Adds scrollbars for multiline textboxes
  - TextAlign: Aligns text (Left, Right, Center)

- **Common Events**:
  - TextChanged: Fires when text content changes
  - KeyPress: Triggers when key is pressed
  - Enter/Leave: Occurs when textbox gains/loses focus

- Used for data entry forms, search boxes, user input fields

## Label Control

- Displays static text or information to users
- **Key Properties**:
  - Text: Content to display
  - Font: Sets font style, size, and formatting
  - AutoSize: Automatically adjusts size to fit text
  - TextAlign: Alignment of text within label
  - BorderStyle: Adds border around label

- Cannot be directly edited by users during runtime
- Commonly used for form field descriptions, titles, instructions, and displaying dynamic information
- Can be updated programmatically to show calculated results or status messages

## CheckBox Control

- Provides binary choice (checked/unchecked) for users
- **Important Properties**:
  - Checked: Boolean value indicating check state
  - CheckState: Three-state option (Checked, Unchecked, Indeterminate)
  - Text: Label text beside checkbox
  - ThreeState: Enables indeterminate state

- **Main Event**: CheckedChanged - fires when check state changes
- Multiple checkboxes can be selected simultaneously (unlike radio buttons)
- Used for options, preferences, feature toggles, agreement confirmations

## Radio Button Control

- Allows selection of single option from multiple choices
- **Key Properties**:
  - Checked: Indicates if radio button is selected
  - Text: Label displayed next to button
  - AutoCheck: Automatically handles mutual exclusion
  - GroupBox/Panel: Groups related radio buttons together

- **Primary Event**: CheckedChanged - triggered when selection changes
- Only one radio button in a group can be selected at a time
- Different groups can be created using GroupBox or Panel controls
- Used for mutually exclusive choices like gender selection, payment methods

## ListBox Control

- Displays scrollable list of items for user selection
- **Important Properties**:
  - Items: Collection of items in the list
  - SelectedItem: Currently selected item
  - SelectedIndex: Index of selected item
  - SelectionMode: Single or multiple selection mode
  - Sorted: Automatically sorts items alphabetically

- **Common Methods**:
  - Items.Add(): Adds item to list
  - Items.Remove(): Removes specific item
  - Items.Clear(): Removes all items

- **Key Event**: SelectedIndexChanged - fires when selection changes
- Supports multi-selection with SelectionMode.MultiSimple or MultiExtended
- Used for displaying and selecting from lists of options

## ComboBox Control

- Combination of textbox and dropdown list
- **Important Properties**:
  - Items: Collection of dropdown items
  - SelectedItem/SelectedIndex: Current selection
  - DropDownStyle: Controls behavior (DropDown, DropDownList, Simple)
  - Text: Currently displayed text
  - Sorted: Sorts items alphabetically

- **DropDownStyle Options**:
  - DropDown: Editable textbox with dropdown
  - DropDownList: Non-editable, selection only
  - Simple: Shows list without dropdown

- **Key Event**: SelectedIndexChanged - triggered on selection change
- Space-efficient alternative to ListBox
- Used for country selection, category filters, dropdown menus

## DateTimePicker Control

- Allows users to select date and time values
- **Key Properties**:
  - Value: Selected date/time value
  - Format: Display format (Short, Long, Time, Custom)
  - CustomFormat: Custom date/time format string
  - ShowUpDown: Shows spin buttons instead of calendar
  - MinDate/MaxDate: Sets valid date range

- **Main Event**: ValueChanged - fires when date/time selection changes
- Provides built-in calendar interface for date selection
- Prevents invalid date entry automatically
- Used for appointment scheduling, date of birth entry, deadline selection

## Panel Control

- Container control for grouping other controls
- **Important Properties**:
  - BorderStyle: Adds border (None, FixedSingle, Fixed3D)
  - AutoScroll: Enables scrollbars when content exceeds size
  - BackColor: Background color of panel

- Helps organize form layout and logical grouping
- Enables/disables all contained controls together
- Can be used to create scrollable regions within forms
- Useful for creating sections in complex forms

## ImageBox (PictureBox) Control

- Displays images in various formats (JPEG, PNG, GIF, BMP)
- **Key Properties**:
  - Image: The image to display
  - SizeMode: How image fits in control (Normal, StretchImage, AutoSize, CenterImage, Zoom)
  - ImageLocation: Path to image file
  - BackgroundImage: Background image behind main image

- **Loading Images**:
  - Design time: Set through Properties window
  - Runtime: Use Image.FromFile() method

- **Common Methods**:
  - Load(): Loads image from URL or path
  - Refresh(): Redraws the image

- Used for displaying logos, photos, icons, graphics in applications

## ProgressBar Control

- Visual indicator showing progress of lengthy operations
- **Important Properties**:
  - Value: Current progress value
  - Minimum: Starting value (usually 0)
  - Maximum: Ending value (usually 100)
  - Step: Increment value for PerformStep()
  - Style: Blocks, Continuous, or Marquee

- **Common Methods**:
  - PerformStep(): Advances progress by Step value
  - Increment(): Increases progress by specified amount

- Provides visual feedback during file operations, downloads, processing
- Marquee style used for indeterminate progress (unknown duration)
- Improves user experience by indicating application is responsive

## OpenFileDialog Control

- Provides standard Windows file selection dialog
- **Key Properties**:
  - Filter: File type filters (e.g., "Text files|*.txt|All files|*.*")
  - FileName: Selected file path
  - InitialDirectory: Starting directory
  - Multiselect: Allows selecting multiple files
  - Title: Dialog window title

- **Usage Pattern**:
  - Call ShowDialog() method
  - Check DialogResult return value
  - Access FileName property if OK clicked

- Returns full path to selected file(s)
- Used for opening files in applications like text editors, image viewers

## SaveFileDialog Control

- Standard Windows save file dialog
- **Important Properties**:
  - Filter: Specifies file type options
  - FileName: Default/selected filename
  - DefaultExt: Default file extension
  - OverwritePrompt: Warns if file exists
  - CreatePrompt: Asks to create new file

- **Usage**:
  - ShowDialog() displays the dialog
  - Check DialogResult before proceeding
  - Use FileName property to get save location

- Automatically handles file extension addition
- Provides overwrite confirmation to prevent data loss
- Used in applications requiring file save functionality

## Timer Control

- Non-visual control that executes code at regular intervals
- **Key Properties**:
  - Interval: Time between ticks in milliseconds
  - Enabled: Starts/stops the timer

- **Primary Event**: Tick - fires at each interval
- **Methods**:
  - Start(): Begins timer operation
  - Stop(): Halts timer execution

- Used for animations, auto-save functionality, real-time updates
- Clock applications, countdown timers, periodic data refresh
- Minimum interval is 1 millisecond, but accuracy depends on system

## Best Practices

- Use meaningful control names (e.g., btnSubmit instead of button1)
- Handle exceptions when working with file dialogs and user input
- Validate user input in TextBox controls before processing
- Disable controls that shouldn't be accessed during operations
- Provide visual feedback using ProgressBar for long operations
- Use appropriate control for the task (ComboBox vs ListBox vs RadioButtons)
- Group related controls using Panel or GroupBox
- Implement proper event handling and avoid memory leaks with Timer
- Test form responsiveness and layout at different screen sizes
