# Documentation: SendEmail Step

## Overview

The `SendEmail` component is part of a system called Patchwork. It is implemented to handle sending emails programmatically within the workflow of Patchwork. This component uses Python's in-built `smtplib` and `email` libraries to construct and send emails through an SMTP server, primarily intended for use cases in automated email dispatching as a step in larger workflows or processes.

## Files

### 1. __init__.py

**Path:** `patchwork/steps/SendEmail/__init__.py`

This file is currently empty but serves to mark the `SendEmail` directory as a package within the Patchwork project.

### 2. SendEmail.py

**Path:** `patchwork/steps/SendEmail/SendEmail.py`

#### Description

The core functionality to send an email is implemented in this file. It defines the `SendEmail` class for constructing and sending an email with configurable parameters.

#### Inputs

- **sender_email (str):** The email address from which the email will be sent.
- **recipient_email (str):** The email address where the email will be sent.
- **sender_email_password (str):** Password for the sender's email account; required for authentication.
- **email_template_value (dict):** Optional dictionary to render dynamic content in the email subject or body through a mustache rendering engine.
- **subject (str):** Optional subject for the email, with a default of "Patchwork Execution Email".
- **body (str):** Optional content/body of the email, with a default of "Patchwork Execution Email".
- **smtp_host (str):** Optional SMTP host, with a default set to 'smtp.gmail.com'.
- **smtp_port (int):** Optional SMTP port, with a default set to 465 (SSL).

#### Outputs

Currently, there are no outputs from this step as denoted by an empty dictionary returned at the end of the `run` method.

#### Usage

- Initialize the `SendEmail` class with required inputs.
- Call the `run()` method to send the email using the configured SMTP settings.

### 3. typed.py

**Path:** `patchwork/steps/SendEmail/typed.py`

#### Description

This file defines the typing for inputs and outputs for the `SendEmail` class, ensuring correct data structures and types are used.

#### Defined Types

- **SendEmailInputs:** 
  - **Required:**
    - `sender_email`
    - `recipient_email`
    - `sender_email_password`
  - **Optional:**
    - `email_template_value`
    - `subject`
    - `body`
    - `smtp_host`
    - `smtp_port`

- **SendEmailOutputs:** Currently defined as an empty TypedDict, indicating no output is expected.

## Notes

- The `SendEmail` step is specifically designed to send emails securely using SSL.
- Extending functionality, such as supporting non-SSL connections or adding attachments, would require modification in the current implementation.
- Proper handling of sensitive data like passwords should be considered, especially in production environments.
