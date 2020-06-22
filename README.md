# C++ Linked List

## Adding a custom data structure with various features all arranged in a class.
- Runtime data type allocation using template.
- Tracks head and tail nodes aswell as list length to cut down on time cost of some functions.
- Console output for testing and feedback.
- Add, Remove, Pop, Print, TailPrint, Length.

### Update 2
- Added "Pop()" function that returns the last element of the list to store/use and deletes the node. 
- Restructed class code into appropriate header and cpp files.
- Added more error checking.

### Update 1
- Added tracking of last dataNode (tail) for constant time Addition of nodes.
- Added tailPrint function to print the last value in the list.
- Made dataNode and class a template. Any data type can be used and compiled at runtime.
  Class passes type to the datanode when creating new nodes for the list.
- Added a remove function to delete a node by passing an int argument to the funtion.
- Added a length function to return and print the length/size of the list.
- Added cout messages for ease of testing and visual feedback.

### Initial Commit
- Basic implimentation of Data struct
- Class for linked list
- Basic method for Add, Print.