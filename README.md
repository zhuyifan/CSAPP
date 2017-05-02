# CSApp Project Assignment

## Overview

This project assignment will exercise your understanding of network
programming.  You must complete all the exercises below using a text editor of
your choice.  Make sure you follow the instructions exactly.  The actual code
your write is relatively short.  However, the details are quite precise.
Programming errors often result from slight differences that are hard to
detect.  So be careful and understand exactly what the exercises are asking
you to do.

The goal of this project is to implement a TCP client from scratch.  We
provide you two files that include code described in the book (the chapter on
Network Programming):

* `csapp.h`
* `csapp.c`

The `csapp.h` file is a header file that you can include in your client
implementation.  The `csapp.c` file is the implementation of some key
functions described in the book.  In particular, you should read up on the
following function:

```c
int Open_clientfd (char *hostname, int port);
```

This will help you in connecting to our server (described below).

## Part 0: Project Startup

Please download the [project startup tarball].  If you do not know what a
"tarball" is you [should read up on it][tarball-info].  To do this, open a web
browser by clicking on the left-most menu button followed by "Internet".  We
have installed firefox and chromium for you to use.  You should do this within
your virtual machine so you can download the tarball to your virtual machine
disk.  You should download the tarball to your home directory.  By default,
chromium will download to the "Downloads" folder.  You can change this by
clicking on "student" in the save dialog box.  Alternatively, you can download
to the "Downloads" folder and then run the following Unix command from the
terminal inside your home directory:

```bash
$ mv Downloads/assignment-csapp-student-master.zip .
```

Remember, the `.` represents your current working directory, in this case your
home directory.  This command will move the tarball to your home directory.
You can verify this using the `ls` command.  Once you have the tarball in your
home directory you can execute the following command:

```bash
$ unzip assignment-csapp-student-master.zip
```

This will *unarchive* the contents of the tarball and you will see the
`assignmnt-csapp-student-master` directory.  You can then go into that
directory from the terminal using `cd` (change directory):

```bash
$ cd assignment-csapp-student-master
```

## Part 1: Understand The Code

You must review the chapter in the book on Network Programming.  This chapter
describes how to create a TCP client.  You must follow this chapter closely to
understand how to implement your own client.  We do not provide you any
starter code other than the book's `csapp.h` and `csapp.c` source code.  You
are welcome not to use their code; however, we recommend you do.

## Part 2: Compiling the Project

We do not provide a *Makefile* for this project.  Rather, you must write your
own Makefile to compile your project.  You should use the Makefile's from
previous projects and lecture examples to construct a Makefile that is able to
compile your code.  Note that the `csapp` library requires the `-pthread` flag
when compiling (`CFLAGS`) and when linking (`LDFLAGS`).  Note that `csapp.c`
and `csapp.h` are not written to work with `--std=c99` so it is best to omit
`--std=...` flags to `gcc` for this homework.  Also, the built-in rules for
`make` are adequate for this project, so it can work to write dependencies
like this, with no associated build rule:

```bash
client.o: client.c csapp.h
```

This can result in a pretty simple Makefile!

## Part 3: The Server

We have implemented a server that is running on the host `elnux1.cs.umass.edu`
on port `5250`.  The server implements a very simple protocol:

* TCP/IP Connect
* Server receives student 8-digit Spire ID number
* Server responds with *custom problem* or failure (disconnect on failure)
* Server receives student solution
* Server responds with success or failure (disconnect on failure)
* Server receives bonus solution
* Server responds with success or failure
* TCP/IP Disconnect

A *custom problem* has been generated for each student that your client must
solve.  Each problem is an operation followed by a number of operands.  The
operation represents a function that you must implement in your client that
will solve the problem using the given operands.  You will be required to
solve one of the following problems:

* `FIB X`: This represents the *fibonacci* function.  The client must
  implement the fibonacci function.  It will send to the server the Xth
  fibonacci number.
* `FAC X`: This represents the *factorial* function.  The client must
  implement the factorial function.  It will send to the server the
  solution to X!.
* `MAX X Y`: This represents the *max* function.  The client must
  implement the max function.  It will send to the server the solution
  to *max(X,Y)*, that is, the maximum value of X and Y.
* `MIN X Y`: This represents the *min* function.  The client must
  implement the min function.  It will send to the server the solution
  to *min(X,Y)*, that is, the minimum value of X and Y.
* `SUM X Y`: This represents the *+* function.  The client must
  implement the sum operation.  It will send to the server the solution
  to *X + Y*.
* `MUL X Y`: This represents the *&times;* function.  The client must
  implement the multiply operation.  It will send to the server the
  solution to *X &times; Y*.
* `REV X`: This represents the *reverse* function.  The client must
  implement a function that reverses the digits in *X* and send the
  solution to the server.  For example, if *X* is 42854 then *REV X*
  is 45824.
* `INC X`: This represents the *increment* operation.  The client must
  implement the increment operation.  This is a ``funny'' increment: it
  increments each digit individually; '9' turns into '10' (two characters).
  Thus, 8910 becomes 91021.  (If this is your assigned function *read the
  description again* to make sure you understand that this is **not** the same
  as `SUM X 1`!*)
* `ADD X`: This represents the *add digits* operation.  The client must
  implement a function that sums the individual digits in *X* and send
  the solution to the server.  For example, if *X* is 1234 then *ADD X*
  is 10.
* `IDX X Y`: This represents the *index digit* operation.  The client
  must implement a function that sends to the server the digit at
  index *Y* in *X*.  For example, if *X* is 123456 and *Y* is 2 then
  *IDX X Y* is 3.

Note that some functions are easier to implement referring to the character
string representation of the number(s) that come from the server, while other
are more convenient to implement after converting that to an `int`.  The
`scanf` function may be helpful! (use `man` to learn more about the
`scanf` function.

The problem the server sends you will be different for everyone; however, it
will not change for a given student between connections to the server.  For
example, if you send the server an incorrect solution to the problem it will
not randomly generate a new one - it will be the same problem.  Here is an
example of a client interacting with the server:

```bash

$ ./client
Connected to server.
Sending Spire ID 83457771
Received problem: REV 427832
Sending solution: 238724
SUCCESS: you got the correct answer.
Disconnected from server.
```

In the above example we did not send a bonus response.  The bonus response is
a mystery puzzle related to the port number we chose for this assignment
(5250).  You may optionally send a one word (alphanumeric) message to the
server after you send the solution to your problem.  If you guess what that
word is and how it relates to port 5250 you get a bonus on this assignment!
Here is an example of incorrectly guessing the bonus:

```bash

$ ./client
Connected to server.
Sending Spire ID 83457771
Received problem: REV 427832
Sending solution: 238724
SUCCESS: you got the correct answer.
Sending bonus: cs230
FAILURE: you did not get the bonus.
Disconnected from server.
```

The server will record your solution if you get it right.  If you do not get
the bonus you are not penalized.  The server does, however, record the number
of failed attempts you make on solving your assigned problem.  Your final
score will receive a penalty based on the number of failed attempts you make.
So, you should think carefully about your problem implementation and test it
before letting it loose on the server. Lastly, we will give you a
small hint about the port number 5250: *the answer to the ultimate
question of life, the universe, and everything*.

## Task 1: Write a Makefile

You should begin by writing a Makefile to compile your project.  You should
first create a skeleton C file named `client.c` with an empty `main` entry
point and includes the `csapp.h` header file.  Then implement a Makefile that
can compile this into an executable.  You should not move on to the next task
until you are successful.

## Task 2: Implementing the Client

After you have a working Makefile and a skeleton C file you should begin the
implementation of the client.  Here are some guidelines you must
follow in your implementation:

* You must use C.
* You must implement your assigned problem as a C function.  Your
  function must be able to solve the problem generally.  That is, you
  can't submit the solution to the problem by computing it by hand -
  your function must *compute* the solution.  We will check this.
* You must use the sockets API directly or the provided book code.

Other than the above you are free to implement your client in any way you see
fit as long as it is *your own code*.  You do not need to worry about what
output your client generates as long as it interacts with the server properly.

## Hints

You do not know before hand which operation has been generated for you.  You
should implement your client in parts - first, implement enough to discover
what problem has been assigned to you then implement the function to solve
that problem.

We recommend using `fprintf`, `getline`, and `sscanf` for this assignment.
These operate on a `FILE *`, which you can obtain from a plain file descriptor
(such as that returned by a `socket` call) using the `fdopen` library
function.  You give `fdopen` the fd you want to be able to access as a `FILE
*`, and the access mode(s) you want, and it gives you back a `FILE *` suitable
for `fprintf` and/or `fscanf`.  Since in this case you will both read and
write, and will always want to be at the logical end of the file (indeed, with
a network socket, you can't be anywhere else!), a mode string of `"a+"` is
what you need.

You're familiar with `printf` so `fprintf` will be easy to use for writing
things to the server.  The `getline` function can conveniently allocate a
buffer for you, if called this way:

```c
FILE *file = ...
...
char *line = NULL;  // having this be NULL is what asks for allocation
int count;          // in this case the initial value of count is ignored
getline(&line, &count, file);
... use line ...
free(line);
```

Note that if you want to read another line of input, you should first `free`
the current line and set `line` to `NULL` so that the next `getline` call will
allocate a fresh buffer of an appropriate size.

Concerning `sscanf`, once you know your problem, you can use it to parse a
line of input for you into its parts.  For example, if your problem is `MAX`,
you can do something like this:

```c
int arg1, arg2;
int count = sscanf(line, "MAX%d%d", &arg1, &arg2);
```

Note how this does a conversion from decimal for you.  For some of the
operators you may find a string rather than numeric representation
more convenient.  For example, you could do this:

```c
char *str;
int idx;
int count = sscanf(line, "IDX%ms%d", &str, &idx);
... use str and idx ...
free(str);
```

Note the use of the `m` option with `%s` - it asks `sscanf` to allocate a
buffer for you to hold the result in scanning a string.  (Such scanning starts
after any white space and ends at the next white space character; spaces and
newlines both count as white space.)  It is good practice to check the `count`
returned by `sscanf` to see if you were able to parse all the things you
wanted.  Perhaps you can begin to see how figuring out the most convenient API
and functions to use can greatly simplify a programming task!

## Submission Instructions

You must submit your assignment as a *tarball*.  After you complete
the assignment you need to run the following command from the *parent*
directory of the your `assignment-csapp-student-master` directory.
So, assuming you are already in your `assignment-csapp-student-master`
directory you want to execute the following commands from the command
line:

```bash
$ cd ..
$ tar czvf assignment-csapp-student-master-submit.tgz assignment-csapp-student-master
```

This will create the file `assignment-csapp-student-master-submit.tgz`
which you need to upload to the CSApp assignment activity in Moodle.
Please submit your assignment to Moodle by the assigned due date.
Please make sure you have followed all the instructions described in
this assignment.  Failure to follow these instructions precisely will
likely lead to considerable point deductions and possibly failure for
the assignment.  Please make sure you have uploaded the *right*
tarball!

[project startup tarball]: https://github.com/umass-cs-230/assignment-csapp-student/archive/master.zip
[tarball-info]: http://en.wikipedia.org/wiki/Tarball

