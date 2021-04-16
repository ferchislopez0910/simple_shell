<p align="center"><img src='https://github.com/ferchislopez0910/holbertonschool-zero_day/blob/master/Simp-01-01.png' alt='Banner' width=100%></p>

# Shell

## System calls
The shell is a command call to the system, even if it is not part of the operating system. It is also the primary interface between a user sitting at his or her terminal and the operating system, unless the user is using a graphical user interface.

When any user logs on, a shell is started. The shell has the terminal as standard input and output. It begins by typing the prompt, a character like a dollar sign *$*, which tells the user that the shell is waiting to accept a command. If the user types date now for example, the shell creates a child process and executes the date program as a child. While the child process is running, the shell waits for it to finish. When the child process terminates, the shell rewrites the prompt and tries to read the next input line.

<p align="center"><img src='https://github.com/ferchislopez0910/holbertonschool-zero_day/blob/master/New_Flow_Chart.png' alt='Banner' width=50%></p> 

**_shell_("This is how to compile our shell");** 

 - compile our program like this:
        *gcc -Wall -Werror -Wextra -pedantic *.c -o hsh*
 - run the shell file:
       *-$-./hsh*
 - After running it, you will see our prompt:
        *-$-*
 - Then, type the command you want to see, example:
        */ls*
        
This is an example on how to use _simple_ _shell_: 
Enter the command to be executed:
       
       Mafe simple_shell ±|main|→ ls

       README.md  builtins1.c  concat.c  execute.c  findpath.c  function_strings.c  get_line.c  not_interac.c  prueba.txt  script.sh  shell  shell.c  shell.h  tokenizer.c


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
