# simfly_parser
This is a simple parser that generate 3D data points in a CSV file from  logs 
created by Noah Wolfe's slimfly simulation on ROSS.

# Folders
The following folders have data that we are interested in looking at.
- Min-UR-100
- Min-UR-95
- NonMin-UR-100
- min-ur-100  vc-occupancy  routers 
    - Populated with unknown(to me) occupancy data

# Data Format
The data is saved in the following format:

```
<global_time_0> <r0 send> <r0 recv> <r1 send> <r1 recv> .... <rn send> <rn recv>
<global_time_1> <r0 send> <r0 recv> <r1 send> <r1 recv> .... <rn send> <rn recv>
    .
    .
    .
<global_time_N> <r0 send> <r0 recv> <r1 send> <r1 recv> .... <rn send> <rn recv>
```

Where ```global_time_i``` relates to global time for that line of data.
The data is then stored in pairs for each router/terminal. 
With first the send frequency and then receive frequency.

# Parser Format
We convert the file format above into 3D data points (time, router/terminal, freq)
Each line contains a data point and is separated by commas.

# How to use
To use first compile with g++
```
g++ parser.cpp -o parser.o 
```
Then use the following format to run parser
./parser.o -i <input path> -o <output send filename>  <output recv filename>
An example would be
```
./parser.o -i ../data/Min-UR-100/slimfly_terminal_sends_recvs_log.txt -o send_data.log recv_data.log
```

Note there is an already parsed set of data ```send_data.log``` and ```recv_data.log```

# For more information 
For more info consult ```Noah_README.txt```
