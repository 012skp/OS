Compile: 
$ g++ -o shell shell.cc

# This shell can execute almost anything that a general shell can.
  Some examples are...
$ ls -alh
$ cd /
$ cd ..
$ cp <src_file> <dstn_file>
$ mkdir <dir_name>

$ wget facebook.com  							#fetches the facebook page saves to index.html. 							
$ sudo apt-get install cowsay sl				#can update if you have root permission.
$ sl
$ echo "Hello There..." | cowsay
$ git clone https://github.com/012skp/OS		#cloning repository form github.



# You can execute complicated programs for create a file shaielsh.txt or use some existing file.
$ echo "Hello my name is Shailesh..." > shailesh.txt
$ echo "I am not a good boy..." >> shailesh.txt

# this will create file abc.txt containing the lines containing 'boy' from shailesh.txt
$ cat shailesh.txt | grep boy > abc.txt     




# If can see background processes using 'jobs' command.
  Try to open 3 program in background....

$ gedit &
$ xterm &
$ libreoffice &

# See now background process using 'jobs'
$ jobs

# Background Processes have been shown using 'pstree', because it gives us better info about child process.
  Moreover this has some advantages like you can see the childrens of childrens even.
  It gives info like 'pid' and parent-child relationship of every process that has been created by this shell or by shell's childrens.



# See history of previous commands using 'history' command. max_limit is 20, you can change code if you want to increase.
# Shortcut for running previously used command '!-1'. This will repeat the last command. '!-2' for repeating second last command and so on. 

# You can kill a 'job' or Background Process by command 'kill <pid>'. To see pids of children enter 'jobs'.
# If you want to exit this shell first asks to kill your child processes.

