This project consists of creating a linux terminal using basically system calls. No lexer library was used.

Implemented functions:

1. Wait for a new command.
2. Multiple commands separated by semicolons.
3. Multiline command in double and single quotes.
4. Escape special characters with '\\'.
5. Pipeline.
6. Redirections '<', '>' and '>>'.
7. Builtins functions: echo, cd, pwd, export, unset, env, exit.
8. ctrl-C, ctrl-D and ctrl-\\.
9. Environment variables.

<hr style="border:2px solid gray"> </hr>

The test can be done with the following commands:
```sh
git clone https://github.com/roneyrogerio/minishell.git
cd minishell && make
./minishell
```
