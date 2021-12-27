# Chips

## Memory Segments

This implementation assigns the following meanings to the virtual memory.

|       Index | Meaning                | Value | Notes                    |
|------------:|:-----------------------|:-----:|:-------------------------|
|           0 | Stack pointer          |  256  |                          |
|           1 | Local segment          |   0   |                          |
|           2 | Argument segment       |   0   |                          |
|           3 | This segment           | 2048  | base address on the heap |
|           4 | That segment           | 2048  |                          |
|        5-12 | Temp general registers |   0   |                          |
|          13 | Working swap 1         |   0   | Used internally          |
|          14 | Working swap 2         |   0   |                          |
|          15 | Working swap 3         |   0   |                          |
|      16-255 | Static address space   |   0   |                          |
|    256-2047 | Working stack          |   0   |                          |
|  2048-16383 | Working heap           |   0   |                          |
| 16384-24575 | Screen memory          |   0   |                          |
| 24576-24577 | Keyboard memory        |   0   |                          |
