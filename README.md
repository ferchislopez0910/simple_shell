<p align="center"><img src='https://marketing4ecommerce.net/wp-content/uploads/2018/06/GitHub-logo-2-imagen.jpg' alt='Banner' width=40%></p>

# Shell

## System calls
The shell is a command call to the system, even if it is not part of the operating system. It is also the primary interface between a user sitting at his or her terminal and the operating system, unless the user is using a graphical user interface.

When any user logs on, a shell is started. The shell has the terminal as standard input and output. It begins by typing the prompt, a character like a dollar sign *$*, which tells the user that the shell is waiting to accept a command. If the user types date now for example, the shell creates a child process and executes the date program as a child. While the child process is running, the shell waits for it to finish. When the child process terminates, the shell rewrites the prompt and tries to read the next input line.

The user can specify that the standard output be redirected to a file, e.g:
        ** date >archivo 


cambiar el flujo -> <p align="center"><img src='https://github.com/ferchislopez0910/simple_shell/blob/main/flowchart_shell.jpg' alt='Banner' width=50%></p> 

**_shell_("This is how to compile our shell");** 
 - compile our program like this:
        gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
 - After running it, you will see our prompt:
        *-$-*
 - Then, type the command you want to see, example:
        /ls


**/RM** 
and there you go!.

This is an example on how to use _shell_: 



You can also get more information and see some examples by consulting the **man_1_simple_shell** page, using this command:

**man man_1_simple_shell**

### Authors :black_nib:

* __Andres Vasquez__

* __Maria Fernanda Lopez__

#### Software Academy 👨‍💻

<p aling="center">
<a href="https://www.holbertonschool.com" target="_blank">
<img src="http://www.holbertonschool.com/holberton-logo.png" alt="Holberton School"  /></a>
</p>
