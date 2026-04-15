# Studio 18
1. Nicole Dai, Sandro Xiao

2. The file system object (like SimpleFileSystem) is responsible for creating files through its createFile method, which
makes it depend on the fact that we need to know the specific file types (ex: TextFile, ImageFile) in order to create it.
By moving the responsibility of creating files outside of the file system (using a factory system), the file system becomes
completely unaware of the concrete file types it is managing. This makes it much easier to add new file types without having
to touch existing file system code, making our code more scalable and maintainable.

3. The abstract factory pattern helps separate file creation from file management, making the code easier to extend.
One advantage is that we can add new file types without changing the file system itself (only the factory needs to be updated).
A downside is that it can add complexity, since introducing a new file type means modifying all existing factories.
If two file systems manage the same types of files, they can use the same factory. If they manage different types, they
would need different factories or modifications to an existing one. We would create a new concrete factory whenever we need
to produce a specific set of related file types.

4. We tested our code by creating a pointer to an AbstractFileSystem (pointing to a SimpleFileSystem) and a pointer to
an AbstractFileFactory (pointing to a SimpleFileFactory). Using the factory, we created two text files: "yup.txt" and
"yippee.txt", and then added them to the file system using addFile(). Then, we opened both files using openFile(),
wrote content into them ("yup" for "yup.txt" and "yippee" for "yippee.txt"), and then read and printed the contents
to the console.
   AbstractFileSystem* fileSystemPtr = new SimpleFileSystem();
   AbstractFileFactory* factoryPtr = new SimpleFileFactory();
   AbstractFile * yupFile = factoryPtr->createFile("yup.txt");
   AbstractFile * yippeeFile = factoryPtr->createFile("yippee.txt");
   fileSystemPtr->addFile("yup.txt", yupFile);
   fileSystemPtr->addFile("yippee.txt", yippeeFile);

   fileSystemPtr->openFile("yup.txt");
   fileSystemPtr->openFile("yippee.txt");

   vector<char> writingYup = {'y','u','p'};
   yupFile->write(writingYup);
   vector<char> writingYippee = {'y','i','p','p','e','e'};
   yippeeFile->write(writingYippee);
   yupFile->read();
   cout << endl;
   yippeeFile->read();
The resulting output was (which is what we were expecting):
   yup
   yippee

5. After removing createFile from the AbstractFileSystem interface and the SimpleFileSystem class,
the SimpleFileSystem no longer depends on any concrete file types. Instead, it only relies on the
AbstractFile interface. This means that SimpleFileSystem can now manage any type of file as long as
that file follows the AbstractFile interface, making the system more flexible and easier to maintain
in the future.