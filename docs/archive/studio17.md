# Studio 17
1. Nicole Dai, Sandro Xiao

2. We created an ImageFile object and tested all its functionalities by calling multiple methods on it.
We first tested writing to the file using a valid input (a vector of 'X' and ' ' characters followed by the size),
and confirmed that the data was stored correctly and that getSize() returned the expected value. We also tested
writing with invalid inputs, such as incorrect pixel characters or mismatched sizes, and verified that the write method
writes to the file. Additionally, we checked that append() correctly returned an error code since images should not be
appended to. Lastly, we used the read() method to confirm that the image was displayed properly from top to bottom.
Overall, our ImageFile class behaved as expected.

3. The main benefit of programming a client to use an interface rather than a concrete class is the flexibility it provides.
By depending on an abstract interface, we can easily add new types of files or change specific behaviors without having to modify
any existing client code. This separation allows for better code reusability, easier maintenance, and better scalability. 
If new functionality is needed later, it can be added through new classes that implement the interface, rather than making changes
throughout the whole codebase.

4. If we wanted to add a new file type, such as MusicFile, we would need to modify the createFile method inside the SimpleFileSystem class.
In this method, we would check for a new file extension and create a new MusicFile object accordingly. Since all file types inherit from AbstractFile,
the MusicFile would already have access to the general methods (read, write, append, etc.), but would provide its own definitions appropriate for music files.