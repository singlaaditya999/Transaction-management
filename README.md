# Transaction-management

In this question, you have to write a C program to implement time stamp based ordering
protocol. [5 marks]
Let, there are three transactions, T1, T2, and T3. Timestamps for these transactions are in the order,
T1<T2<T3. All the transactions are using the data items A and B in their lifetimes. If the transaction
T1 is rolling back then other transactions will also have to roll back if they have already read or
written the data items written by T1. In this case, T1 will be assigned a new timestamp. If other
dependent transactions are also rolling back then they will also be assigned new timestamps.
Ordering of timestamps in this case will remain same as earlier. However, if only T1 rolls back then

T1 will become now junior most transaction. Initially, read and write timestamps of all data items
will be zero.
(a) In the output terminal if we enter the string as:
“ Read request by T1 for data item A”.
In this case, the program will either grant the request or T1 will have to roll back depending on the
rules of timestamp based protocol. If the request is granted then read timestamp of A will be
updated. The output string should be displaying that, “Read request is granted”. In case of roll back,
the output string should be displaying that, “Request is rejected and T1 will have to roll back. These
transactions are also rolling back.”
(b) In the output terminal if we enter the string as:
“ Write request by T1 for data item A”.
In this case, the program will either grant the request or T1 will have to roll back depending on the
rules of timestamp based protocol. If the request is granted then write timestamp of A will be
updated. The output string should be displaying that, “Request is rejected and T1 will have to roll
back. These transactions are also rolling back.”
Similar to above input strings any number of such relevant input strings can be entered and the
output should be shown accordingly.
