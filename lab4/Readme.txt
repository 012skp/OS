# 1: unzip the file
$ unzip 14CS01038.zip

# 2: build the project. Compiles and makes executables.
$ make

# 3: add +x mode to 'run' and run the script. <executables> --> <files in gnuplot format> --> <files in png format>
$ chmod +x run
$ ./run

# open the graph 'time vs no of threads'...
# 1.png is using gettimeofday() and 2.png is using clock().
$ gnome-open 1.png 2.png

# clean the project
$ make clean