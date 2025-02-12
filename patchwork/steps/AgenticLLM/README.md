# Documentation for AgenticLLM Module

The `AgenticLLM` module within the `patchwork` Python package is designed to define and execute a conversation strategy using a language model with agent-like capabilities. This module is likely used in scenarios where automated communication needs to be handled in a multi-turn dialogue, leveraging large language model capabilities to adapt to user inputs and system prompts.

## Overview

This module consists of three core files:
1. **`__init__.py`**: As typical of such files, it initializes the module but currently contains no code.
2. **`typed.py`**: Defines the strict input and output types for the `AgenticLLM` classes using Python's typing system.
3. **`AgenticLLM.py`**: Contains the main implementation of the `AgenticLLM` class, which defines and executes a conversation strategy.

---

## File: `typed.py`

### Inputs

The `AgenticLLMInputs` class in this file defines the structure expected as input for the `AgenticLLM` class:
- `base_path` (str): Base directory for the tools used by agents.
- `prompt_value` (Dict[str, Any]): Key-value pairs for prompt template data.
- `system_prompt` (str): Template string for system prompts.
- `user_prompt` (str): Template string for user prompts.
- `max_llm_calls` (int): Maximum number of language model calls allowed.
- `anthropic_api_key` (str): API key used for authenticating with the language model provider.
- `agent_system_prompt` (str): The prompt used by the agent within its own scope.
- `example_json` (str): JSON string containing example data.

### Outputs

The `AgenticLLMOutputs` class is defined but currently doesn't contain any specific fields.

---

## File: `AgenticLLM.py`

### Class: `AgenticLLM`

#### Description

The `AgenticLLM` class orchestrates running a conversational strategy. It is initialized with the provided inputs:

- Utilizes a strategy pattern (`AgenticStrategy`) for handling agent interactions.
- Leverages the `AgentConfig` to define agent behavior and tool usage.
- Executes a sequence of language model calls within specified limits.

#### Constructor: `__init__(self, inputs)`

- Initializes the base path for tools, max call limits, and various prompt configurations.
- Sets up an `AgenticStrategy` instance using the provided API key and template data.

#### Method: `run(self) -> dict`

- Executes the agent strategy and returns the outcome as a dictionary.
  
### Likely Use Case

Given its structure, a user would employ `AgenticLLM` in an application aimed at managing complex, back-and-forth dialogue sessions, such as chat interfaces or automated customer service systems.

---
