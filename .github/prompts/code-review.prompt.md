---
name: code-review
description: Verify the current file for bugs, run against all test cases, and print space and time complexity.
parameters:
  - name: file
    description: The file to analyze (defaults to the active file if not specified)
---

# Code Review and Analysis

Please perform the following tasks on the specified file (or the current active file if none provided):

1. **Bug Verification**: Carefully review the code for any syntax errors, logical bugs, potential runtime issues, or best practice violations. Provide a detailed list of any issues found, including line numbers and suggested fixes.

2. **Test Case Execution**: Identify all relevant test cases for this file. Run the code against each test case and report the results, including pass/fail status, expected vs actual outputs, and any errors encountered.

3. **Complexity Analysis**: Analyze and print the time complexity (Big O notation) and space complexity of the main algorithms or functions in the file. Explain your reasoning based on the code structure.

Ensure your response is structured clearly with headings for each section. If the file requires compilation or execution, use appropriate tools to build and run it. If tests are not available, note that and suggest how to create them.