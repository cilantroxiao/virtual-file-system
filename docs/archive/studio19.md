# Studio 19
1. Nicole Dai, Sandro Xiao

2. I created two files in main, a TextFile called YUMMY.txt and an ImageFile called DISGUSTING.img. 
After creating and adding the files to the file system, I wrote content into each file using the write function.
Then, I used the read function to retrieve the contents and stored them into a local variable.
I verified that the files updated correctly by calling the accept function with a BasicDisplayVisitor to display the new file contents.
Example test case:
   AbstractFileSystem* fileSystemPtr = new SimpleFileSystem();
   AbstractFileFactory* factoryPtr = new SimpleFileFactory();
   AbstractFile * YUMMYFile = factoryPtr->createFile("YUMMY.txt");
   fileSystemPtr->addFile("YUMMY.txt", YUMMYFile);

   fileSystemPtr->openFile("YUMMY.txt");

   vector<char> writingYUMMY = {'Y','U','M','M','Y'};
   YUMMYFile->write(writingYUMMY);
   YUMMYFile->read();

3. When using the visitor pattern, the object being visited has an accept method that takes the visitor as an argument.
Inside the accept method, the object calls the appropriate visit_<FileType> method on the visitor, passing itself (this)
as the argument. The visitor implements a visit method for each file type it can operate on, containing the logic specific
to that file. This allows new operations to be added without modifying the file classes themselves.

4. The visitor pattern uses the concept of delegation because the AbstractFile image and text files "delegate" or hand off
the behavior of displaying to the AbstractFileVisitor subclass which is BasicDisplayVisitor by calling accept() and having
the visitor do the work with the visit_text/image methods. 

5. If we were to add a new concrete file type, we would need to create a new class that implements the accept method. We would
also have to add a new visit method to the visitor interface and modify every existing concrete visitor to handle the new file type.
This means that adding a new visitable type forces changes to multiple files (the visitor interface and all of its concrete implementations).
This is a negative consequence of the visitor pattern because every time we add a new file type, we have to update a lot of different parts
of the code, which can make things messy and harder to manage.