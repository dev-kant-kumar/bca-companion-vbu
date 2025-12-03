# Unit 5: ADO.NET - Detailed Notes

## Introduction to ADO.NET

- **ADO.NET** stands for ActiveX Data Objects for .NET Framework
- Data access technology used to communicate between .NET applications and databases
- Provides consistent access to various data sources like SQL Server, Oracle, XML, etc.
- Works in both connected and disconnected architecture models
- Successor to classic ADO (ActiveX Data Objects) with improved performance and scalability

- **Key Features**:
  - Interoperability: Works with various data sources
  - Scalability: Handles large amounts of data efficiently
  - XML support: Native XML integration for data transfer
  - Type safety: Strong typing prevents runtime errors
  - Performance: Optimized for .NET Framework

- **Architecture Models**:
  - **Connected Architecture**: Maintains continuous connection with database (uses DataReader)
  - **Disconnected Architecture**: Works with local copy of data (uses DataSet/DataAdapter)

## ADO.NET Data Providers

- **Data Provider**: Set of components that enable database connectivity and operations
- Acts as a bridge between application and data source
- Each database has its own optimized data provider

- **Main Data Providers**:
  - **SQL Server Provider** (System.Data.SqlClient): For Microsoft SQL Server
  - **OLE DB Provider** (System.Data.OleDb): For older databases using OLE DB
  - **ODBC Provider** (System.Data.Odbc): For ODBC-compatible data sources
  - **Oracle Provider** (System.Data.OracleClient): For Oracle databases

- **Core Components of Data Provider**:
  - **Connection**: Establishes connection to database
  - **Command**: Executes SQL commands/queries
  - **DataReader**: Forward-only, read-only data stream (connected mode)
  - **DataAdapter**: Bridge between DataSet and database (disconnected mode)

- All providers implement similar interfaces (IDbConnection, IDbCommand, etc.)
- Provider selection depends on database type being used

## Connection Object

- Establishes physical connection between application and database
- Must be opened before executing any database operation
- Should be closed after operations to free resources

- **SqlConnection Class** (for SQL Server):
  - Namespace: System.Data.SqlClient
  - Represents connection to SQL Server database

- **Key Properties**:
  - **ConnectionString**: Contains database connection parameters
  - **State**: Current state of connection (Open, Closed, Connecting, etc.)
  - **Database**: Name of current database
  - **DataSource**: Server name or instance
  - **ConnectionTimeout**: Time to wait while establishing connection

- **ConnectionString Components**:
  - **Data Source/Server**: Database server name (e.g., "localhost" or ".")
  - **Initial Catalog/Database**: Database name
  - **Integrated Security**: Windows authentication (true/false)
  - **User ID & Password**: SQL Server authentication credentials
  - Example: `"Data Source=localhost;Initial Catalog=MyDB;Integrated Security=true"`

- **Important Methods**:
  - **Open()**: Opens database connection
  - **Close()**: Closes the connection
  - **Dispose()**: Releases all resources used by connection

- **Best Practices**:
  - Always close connections after use (use try-finally or using statement)
  - Use connection pooling for performance
  - Handle connection exceptions properly
  - Store connection strings in configuration files, not hardcoded

- **Example Usage**:
```
using (SqlConnection conn = new SqlConnection(connectionString))
{
    conn.Open();
    // Perform database operations
} // Automatically closes connection
```

## Command Object

- Executes SQL statements and stored procedures against database
- Requires an active connection to function
- Can execute queries, insert, update, delete operations

- **SqlCommand Class** (for SQL Server):
  - Namespace: System.Data.SqlClient
  - Represents SQL statement or stored procedure

- **Key Properties**:
  - **CommandText**: SQL query or stored procedure name
  - **CommandType**: Type of command (Text, StoredProcedure, TableDirect)
  - **Connection**: Associated connection object
  - **Parameters**: Collection of parameters for parameterized queries
  - **CommandTimeout**: Execution timeout in seconds

- **CommandType Enumeration**:
  - **Text**: SQL statement (default)
  - **StoredProcedure**: Name of stored procedure
  - **TableDirect**: Table name (rarely used)

- **Primary Execution Methods**:
  - **ExecuteNonQuery()**: For INSERT, UPDATE, DELETE operations; returns rows affected
  - **ExecuteScalar()**: Returns single value (first column of first row)
  - **ExecuteReader()**: Returns DataReader object for SELECT queries
  - **ExecuteXmlReader()**: Returns XML data from SQL Server

- **Parameters**:
  - Use SqlParameter objects to prevent SQL injection
  - Parameters start with @ symbol in SQL Server
  - Example: `cmd.Parameters.AddWithValue("@Name", "John")`

- **Example - ExecuteNonQuery**:
```
SqlCommand cmd = new SqlCommand("INSERT INTO Users VALUES(@Name, @Age)", conn);
cmd.Parameters.AddWithValue("@Name", "John");
cmd.Parameters.AddWithValue("@Age", 25);
int rowsAffected = cmd.ExecuteNonQuery();
```

- **Example - ExecuteScalar**:
```
SqlCommand cmd = new SqlCommand("SELECT COUNT(*) FROM Users", conn);
int count = (int)cmd.ExecuteScalar();
```

- Always use parameterized queries to prevent SQL injection attacks
- Dispose Command objects after use to free resources

## DataAdapter Object

- Bridge between DataSet (disconnected data) and database
- Fills DataSet with data and updates database with changes
- Works in disconnected architecture model

- **SqlDataAdapter Class**:
  - Namespace: System.Data.SqlClient
  - Contains set of data commands and connection

- **Key Properties**:
  - **SelectCommand**: Command for retrieving data
  - **InsertCommand**: Command for inserting records
  - **UpdateCommand**: Command for updating records
  - **DeleteCommand**: Command for deleting records

- **Important Methods**:
  - **Fill()**: Populates DataSet/DataTable with query results
  - **Update()**: Executes INSERT, UPDATE, DELETE on database based on DataSet changes
  - **FillSchema()**: Adds DataTable schema to DataSet

- **How Fill() Works**:
  - Opens connection automatically if closed
  - Executes SelectCommand
  - Fills DataSet/DataTable with results
  - Closes connection automatically
  - Data remains in memory for manipulation

- **How Update() Works**:
  - Examines each row's RowState (Added, Modified, Deleted)
  - Executes appropriate command (Insert/Update/Delete)
  - Synchronizes changes back to database
  - Updates RowState after successful operation

- **CommandBuilder**:
  - Automatically generates INSERT, UPDATE, DELETE commands
  - SqlCommandBuilder class simplifies DataAdapter configuration
  - Example: `SqlCommandBuilder builder = new SqlCommandBuilder(adapter)`

- **Example Usage**:
```
SqlDataAdapter adapter = new SqlDataAdapter("SELECT * FROM Users", conn);
DataSet ds = new DataSet();
adapter.Fill(ds, "Users");
// Modify data in DataSet
adapter.Update(ds, "Users"); // Saves changes to database
```

- DataAdapter enables working with data offline without maintaining connection
- More efficient for applications that need to manipulate data before saving

## DataSet Object

- In-memory cache of data retrieved from database
- Completely disconnected from database after data is loaded
- Can contain multiple DataTables and relationships between them

- **DataSet Class**:
  - Namespace: System.Data
  - Represents a complete set of data including tables, relationships, constraints

- **Key Properties**:
  - **Tables**: Collection of DataTable objects
  - **Relations**: Collection of DataRelation objects defining table relationships
  - **DataSetName**: Name of the DataSet
  - **HasErrors**: Indicates if any tables have errors

- **Important Methods**:
  - **AcceptChanges()**: Commits all changes since last AcceptChanges
  - **RejectChanges()**: Rolls back all changes
  - **Clear()**: Removes all data from all tables
  - **GetXml()**: Returns XML representation of data
  - **WriteXml()**: Writes data to XML file
  - **ReadXml()**: Loads data from XML file

- **DataSet Features**:
  - Can work with multiple tables simultaneously
  - Maintains relationships between tables (parent-child)
  - Supports constraints (primary key, foreign key, unique)
  - Built-in XML serialization support
  - Change tracking for each row

- **Accessing Data in DataSet**:
  - Access tables: `ds.Tables[0]` or `ds.Tables["TableName"]`
  - Access rows: `ds.Tables[0].Rows[0]`
  - Access columns: `ds.Tables[0].Rows[0]["ColumnName"]`

- **Working with Multiple Tables**:
```
DataSet ds = new DataSet();
adapter1.Fill(ds, "Customers");
adapter2.Fill(ds, "Orders");
// Create relationship
DataRelation relation = new DataRelation("CustomerOrders",
    ds.Tables["Customers"].Columns["CustomerID"],
    ds.Tables["Orders"].Columns["CustomerID"]);
ds.Relations.Add(relation);
```

- **Advantages**:
  - Works without continuous database connection
  - Reduces database server load
  - Enables complex data manipulation offline
  - Supports undo functionality with RejectChanges

- Ideal for scenarios requiring data manipulation before database updates
- Heavier than DataReader but more flexible

## DataTable Object

- Represents single table of in-memory data
- Can exist independently or as part of DataSet
- Similar to database table structure with rows and columns

- **DataTable Class**:
  - Namespace: System.Data
  - Represents one table of data

- **Key Properties**:
  - **Rows**: Collection of DataRow objects (table records)
  - **Columns**: Collection of DataColumn objects (table structure)
  - **TableName**: Name of the table
  - **PrimaryKey**: Array of columns forming primary key
  - **Constraints**: Collection of constraints on table

- **Important Methods**:
  - **NewRow()**: Creates new DataRow with table schema
  - **Select()**: Filters rows based on criteria
  - **Clear()**: Removes all data rows
  - **AcceptChanges()**: Commits all changes
  - **RejectChanges()**: Rolls back changes
  - **Copy()**: Creates copy of structure and data
  - **Clone()**: Creates copy of structure only

- **DataColumn Properties**:
  - **ColumnName**: Name of column
  - **DataType**: Data type (int, string, DateTime, etc.)
  - **AllowDBNull**: Whether nulls are allowed
  - **Unique**: Whether values must be unique
  - **AutoIncrement**: Auto-incrementing column

- **DataRow Properties**:
  - **RowState**: Current state (Unchanged, Added, Modified, Deleted)
  - **ItemArray**: Array of all column values
  - **HasErrors**: Indicates if row has errors

- **Creating DataTable Programmatically**:
```
DataTable dt = new DataTable("Students");
dt.Columns.Add("ID", typeof(int));
dt.Columns.Add("Name", typeof(string));
dt.Columns.Add("Age", typeof(int));

DataRow row = dt.NewRow();
row["ID"] = 1;
row["Name"] = "John";
row["Age"] = 20;
dt.Rows.Add(row);
```

- **Filtering and Selecting Data**:
  - `DataRow[] results = dt.Select("Age > 18");`
  - `DataRow[] sorted = dt.Select("", "Name ASC");`

- **Row States** (Important for Update operations):
  - **Unchanged**: No changes since last AcceptChanges
  - **Added**: New row added to table
  - **Modified**: Existing row modified
  - **Deleted**: Row marked for deletion
  - **Detached**: Row created but not added to table

- Can be filled directly using DataAdapter without DataSet
- Lighter than DataSet when working with single table
- Supports data binding to controls like DataGridView

## Connecting Database with Windows Application

- Process of integrating database operations into WinForms application
- Involves establishing connection, executing queries, displaying results

- **Steps for Database Connection**:
  1. Add necessary namespace: `using System.Data.SqlClient;`
  2. Create connection string with database details
  3. Create SqlConnection object
  4. Open connection
  5. Create and execute commands
  6. Process results
  7. Close connection

- **Connection String Storage**:
  - Store in App.config file for easy modification
  - Use ConfigurationManager to retrieve
  - Never hardcode sensitive credentials in source code

- **Example App.config**:
```
<connectionStrings>
  <add name="MyDB" connectionString="Data Source=.;Initial Catalog=SchoolDB;Integrated Security=true"/>
</connectionStrings>
```

- **Error Handling**:
  - Always use try-catch blocks for database operations
  - Handle SqlException specifically
  - Display user-friendly error messages
  - Log errors for debugging

- **Basic Connection Example**:
```
try
{
    SqlConnection conn = new SqlConnection(connectionString);
    conn.Open();
    MessageBox.Show("Connected Successfully!");
    conn.Close();
}
catch (SqlException ex)
{
    MessageBox.Show("Error: " + ex.Message);
}
```

## Working with DataGridView Control

- Powerful control for displaying and editing tabular data
- Most common control for database data visualization in WinForms
- Supports sorting, filtering, editing capabilities

- **DataGridView Class**:
  - Located in System.Windows.Forms namespace
  - Displays data in customizable grid format

- **Key Properties**:
  - **DataSource**: Binds data source (DataTable, DataSet, BindingSource)
  - **Columns**: Collection of columns in grid
  - **Rows**: Collection of rows
  - **ReadOnly**: Makes entire grid non-editable
  - **AllowUserToAddRows**: Enables/disables adding new rows
  - **AllowUserToDeleteRows**: Enables/disables row deletion
  - **SelectionMode**: How cells/rows are selected
  - **AutoGenerateColumns**: Auto-creates columns from data source

- **Important Methods**:
  - **Refresh()**: Redraws the control
  - **ClearSelection()**: Deselects all cells
  - **Sort()**: Sorts by specified column

- **Common Events**:
  - **CellClick**: Fires when cell is clicked
  - **CellValueChanged**: Triggers when cell value changes
  - **RowEnter**: Occurs when row gains focus
  - **SelectionChanged**: Fires when selection changes

- **Binding DataTable to DataGridView**:
```
SqlDataAdapter adapter = new SqlDataAdapter("SELECT * FROM Students", conn);
DataTable dt = new DataTable();
adapter.Fill(dt);
dataGridView1.DataSource = dt;
```

- **Binding DataSet to DataGridView**:
```
SqlDataAdapter adapter = new SqlDataAdapter("SELECT * FROM Students", conn);
DataSet ds = new DataSet();
adapter.Fill(ds, "Students");
dataGridView1.DataSource = ds.Tables["Students"];
```

- **Complete CRUD Example with DataGridView**:

**Load Data (Read Operation)**:
```
void LoadData()
{
    SqlConnection conn = new SqlConnection(connectionString);
    SqlDataAdapter adapter = new SqlDataAdapter("SELECT * FROM Students", conn);
    DataTable dt = new DataTable();
    adapter.Fill(dt);
    dataGridView1.DataSource = dt;
}
```

**Insert Operation**:
```
void InsertRecord()
{
    SqlConnection conn = new SqlConnection(connectionString);
    conn.Open();
    SqlCommand cmd = new SqlCommand(
        "INSERT INTO Students VALUES(@Name, @Age, @Class)", conn);
    cmd.Parameters.AddWithValue("@Name", txtName.Text);
    cmd.Parameters.AddWithValue("@Age", txtAge.Text);
    cmd.Parameters.AddWithValue("@Class", txtClass.Text);
    cmd.ExecuteNonQuery();
    conn.Close();
    LoadData(); // Refresh grid
    MessageBox.Show("Record Inserted Successfully!");
}
```

**Update Operation**:
```
void UpdateRecord()
{
    SqlConnection conn = new SqlConnection(connectionString);
    conn.Open();
    SqlCommand cmd = new SqlCommand(
        "UPDATE Students SET Name=@Name, Age=@Age WHERE ID=@ID", conn);
    cmd.Parameters.AddWithValue("@ID", txtID.Text);
    cmd.Parameters.AddWithValue("@Name", txtName.Text);
    cmd.Parameters.AddWithValue("@Age", txtAge.Text);
    cmd.ExecuteNonQuery();
    conn.Close();
    LoadData(); // Refresh grid
    MessageBox.Show("Record Updated Successfully!");
}
```

**Delete Operation**:
```
void DeleteRecord()
{
    SqlConnection conn = new SqlConnection(connectionString);
    conn.Open();
    SqlCommand cmd = new SqlCommand(
        "DELETE FROM Students WHERE ID=@ID", conn);
    cmd.Parameters.AddWithValue("@ID", txtID.Text);
    cmd.ExecuteNonQuery();
    conn.Close();
    LoadData(); // Refresh grid
    MessageBox.Show("Record Deleted Successfully!");
}
```

**Selecting Row from DataGridView**:
```
private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
{
    if (e.RowIndex >= 0)
    {
        DataGridViewRow row = dataGridView1.Rows[e.RowIndex];
        txtID.Text = row.Cells["ID"].Value.ToString();
        txtName.Text = row.Cells["Name"].Value.ToString();
        txtAge.Text = row.Cells["Age"].Value.ToString();
    }
}
```

- **Column Customization**:
  - Hide columns: `dataGridView1.Columns["ID"].Visible = false;`
  - Change header text: `dataGridView1.Columns["Name"].HeaderText = "Student Name";`
  - Set column width: `dataGridView1.Columns["Name"].Width = 150;`
  - Make column read-only: `dataGridView1.Columns["ID"].ReadOnly = true;`

- **Search/Filter Functionality**:
```
void SearchData()
{
    SqlConnection conn = new SqlConnection(connectionString);
    SqlDataAdapter adapter = new SqlDataAdapter(
        "SELECT * FROM Students WHERE Name LIKE @Search", conn);
    adapter.SelectCommand.Parameters.AddWithValue("@Search",
        "%" + txtSearch.Text + "%");
    DataTable dt = new DataTable();
    adapter.Fill(dt);
    dataGridView1.DataSource = dt;
}
```

## Best Practices for ADO.NET

- **Connection Management**:
  - Always close connections after use
  - Use `using` statement for automatic disposal
  - Implement connection pooling for better performance
  - Handle connection timeout exceptions

- **Security**:
  - Always use parameterized queries (never concatenate SQL strings)
  - Store connection strings securely (encrypted in config files)
  - Use integrated security when possible
  - Implement proper exception handling without exposing sensitive information

- **Performance Optimization**:
  - Use DataReader for read-only, forward-only data (faster than DataSet)
  - Use DataSet/DataAdapter when need to manipulate data offline
  - Close connections as soon as possible
  - Use stored procedures for complex operations
  - Retrieve only necessary columns (avoid SELECT *)

- **Data Validation**:
  - Validate user input before database operations
  - Check for null values and empty strings
  - Implement data type checking
  - Use database constraints alongside application validation

- **Error Handling**:
  - Implement try-catch-finally blocks
  - Log exceptions for troubleshooting
  - Provide meaningful error messages to users
  - Roll back transactions on failure

- **Transaction Management**:
  - Use transactions for multiple related operations
  - Ensure all operations succeed or all fail (ACID properties)
  - Always commit or rollback transactions
  - Use transaction scope appropriately

- **Code Organization**:
  - Separate database logic from UI code (use separate data access layer)
  - Create reusable methods for common operations
  - Use meaningful variable and method names
  - Comment complex database operations

---

**Common Interview Questions:**
- Difference between connected and disconnected architecture
- When to use DataReader vs DataSet
- Purpose of DataAdapter
- How to prevent SQL injection attacks
- Difference between ExecuteNonQuery, ExecuteScalar, and ExecuteReader
