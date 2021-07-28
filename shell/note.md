# Note

PC ID: u82z01s01

*Source*

* https://stackoverflow.com/questions/9381463/how-to-create-a-file-in-linux-from-terminal-window
* https://ostechnix.com/create-files-certain-size-linux/
* https://askubuntu.com/questions/62492/how-can-i-change-the-date-modified-created-of-a-file
* https://kb.iu.edu/d/abdb
* https://linuxhandbook.com/ln-command/
* http://www.cs.cornell.edu/courses/cs114/1999fa/Documents/chmod.htm
* https://superuser.com/questions/477858/what-does-the-number-after-unix-linux-file-permissions-like-rw-rw-r-1-mea
* https://unix.stackexchange.com/a/63877
* https://www.pendrivelinux.com/how-to-open-a-tar-file-in-unix-or-linux/

## How to change permission

* ex01

1) dd if=/dev/zero of=testShell00 bs=40 count=1 // Must change size before remove write permission.
2) touch -a -m -t 202106012342 testShell00 // change timestamp of file. 
3) remove all permissions first: chmod -w testShell00, chmod -r testShell00
4) chmod u+r testShell00
5) chmod g+r testShell00
6) chmod g+x testShell00
7) chmod o+r testShell00
8) chmod o+x testShell00

* ex02

1) mkdir test0
2) head -c 4 /dev/zero > test1
3) mkdir test1
4) head -c 1 /dev/zero > test3
5) head -c 2 /dev/zero > test4
6) ln test3 test5
7) ln -s test0 test6
8) chmod g-r test0
9) chmod u+x test1
10) chmod g-r test1
11) chmod g+x test1
12) chmod u-w test2
13) chmod g-r test2
14) chmod g-x test2
15) chmod o-x test2
16) chmod u=r,g=,o=r test3 (no space)
17) chmod u=rw,g=r,o=x test4
18) touch -a -m -t 202106012047 test0
19) touch -a -m -t 202106012146 test1
20) touch -a -m -t 202106012245 test2
21) touch -a -m -t 202106012344 test3
22) touch -a -m -t 202106012343 test4
23) touch -a -m -t 202106012344 test5
24) touch -h -t 202106012220 test6 (https://unix.stackexchange.com/a/63877)

* ex03

1) kinit -l "999d" //https://web.mit.edu/kerberos/krb5-1.12/doc/basic/date_format.html#duration, https://www.ibm.com/docs/en/was-nd/9.0.5?topic=server-creating-kerberos-configuration-file
2) klist > klist.txt

* ex04

1) ls -pmUt

*(Source: MAN LS)*

-p: Write a slash ("/") after each filename if that file is a directory.
-m: Stream output format; list files across the page, separated by commas.
-U: Use time of file creation, instead of last modification for sorting (-t) or long output (-l).
-t: Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.

* ex05

#!/bin/sh
git log -5 --pretty=%H

* ex06

1) git check-ignore * .













---
If you want to use U, you have to use T first. 
U sort by creation time.
