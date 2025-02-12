# CallSQL Module Documentation

This documentation provides an overview of the `CallSQL` module, which is designed to interface with SQL databases, execute queries, and return results. The module is implemented in Python using SQLAlchemy for database connection management.

## Overview

The `CallSQL` module consists of three primary Python files:

1. **CallSQL.py:** Core logic for handling SQL operations.
2. **typed.py:** Defines input and output data models.
3. **__init__.py:** An empty file intended for package initializations.

The main functionality is encapsulated in the `CallSQL` class, which inherits from a generic `Step` class. It uses SQLAlchemy to establish connections with a database, execute queries, and handle results.

## Inputs

### CallSQLInputs Class

- **`db_dialect`** *(str, required)*: The database dialect (e.g., `'postgresql'`).
- **`db_query`** *(str, required)*: The SQL query to execute.
- **`db_driver`** *(str, optional)*: Specific database driver.
- **`db_username`** *(str, optional)*: Username for database authentication.
- **`db_password`** *(str, optional)*: Password for database authentication.
- **`db_host`** *(str, optional, default='localhost')*: Hostname of the database.
- **`db_port`** *(int, optional, default=5432)*: Port number for the database connection.
- **`db_database`** *(str, optional)*: Name of the database.
- **`db_params`** *(dict, optional)*: Additional parameters for database connection.
- **`db_driver_args`** *(dict, optional)*: Additional driver-specific arguments.
- **`db_query_template_values`** *(dict, optional)*: Values for template rendering in the SQL query.

## Outputs

### CallSQLOutputs Class

- **`results`** *(list)*: A list of dictionaries, where each dictionary represents a row of query result data.

## Usage

To utilize the `CallSQL` class, one would:

1. Instantiate an object of `CallSQL` with a dictionary of input parameters conforming to `CallSQLInputs`.
2. Call the `run()` method to execute the SQL query and retrieve the results.
3. Handle the output, which is a dictionary containing the query results in the `results` key.

### Example

```python
from patchwork.steps.CallSQL.CallSQL import CallSQL

inputs = {
    "db_dialect": "postgresql",
    "db_query": "SELECT * FROM users WHERE id = :user_id",
    "db_query_template_values": {"user_id": 1},
    # Additional inputs as necessary
}

call_sql = CallSQL(inputs)
output = call_sql.run()
print(output["results"])
```

This module is ideal for integration into larger systems where database interaction is required as a step in a pipeline or workflow. It abstracts the complexities of database connections and query execution, providing a straightforward interface for developers.
