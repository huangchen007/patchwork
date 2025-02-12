# CallShell Step Documentation

This documentation outlines the components of the `CallShell` step, which is a part of the `patchwork` package, primarily used for executing shell scripts within a defined environment and working directory.

## Overview

The `CallShell` step is designed to execute shell scripts with the capability of using template values for customization. It supports environment variable handling and captures the standard output and error of the executed script.

The step is comprised of three main files as outlined below:

### Files

1. **`CallShell.py`** - Contains the `CallShell` class which handles script execution.
2. **`__init__.py`** - Defines the package but is an empty placeholder file.
3. **`typed.py`** - Defines the input and output data structures for `CallShell`.

## File: CallShell.py

### Functionality

- Executes shell scripts within a specified environment and working directory.
- Uses a `mustache` template rendering engine to substitute variables within the script.
- Parses environment variables from a string.
- Captures both stdout and stderr from the script execution.
  
### Inputs

- **`inputs: dict`** - Dictionary containing:
  - `script`: The shell script to execute.
  - `working_dir`: Path to the working directory (optional, defaults to current directory).
  - `env`: String of environment variable assignments (optional).
  - `script_template_values`: Dictionary of variables for template substitution in the script.

### Outputs

- Returns a dictionary containing:
  - `stdout_output`: The text output from the standard output of the script.
  - `stderr_output`: The text output from the standard error of the script.

### Usage Example

```python
inputs = {
    "script": "echo Hello, {{name}}",
    "script_template_values": {"name": "World"},
    "working_dir": "/home/user/scripts",
    "env": "PATH=/usr/bin;"
}

call_shell_step = CallShell(inputs)
output = call_shell_step.run()
print(output["stdout_output"])
```

## File: typed.py

### Input Definitions

- **`CallShellInputs`** - Defines the required and optional inputs for `CallShell`.
  - `script`: Str (Required)
  - `working_dir`: Str (Path, Optional)
  - `env`: Str (Optional)
  - `script_template_values`: Dict (Optional)

### Output Definitions

- **`CallShellOutputs`** - Defines the structure for script outputs.
  - `stdout_output`: Str

## File: __init__.py

- This file is present to define the `CallShell` package/module and does not contain any executable code.

---

This documentation provides a structured overview of the `CallShell` step's components and functionality. It should serve as a useful reference for users attempting to integrate shell script execution into their `patchwork` workflows.
