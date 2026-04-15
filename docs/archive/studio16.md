# Studio 16
1. Nicole Dai, Sandro Xiao

2. You declare the AbstractFile interface in the header file using pure virtual functions, and then
define them individually in each respective subclass (using public inheritance).

3a. Interface Inheritance
3b. Member variables should be private
4. We created a TextFile object directly and tested all the main functions:
We called write to add characters to the file.
We called read to print the file contents to the console.
We called append to add more characters to the existing contents.
We called getSize to verify the file size matched the number of characters.
Everything behaved as expected.

5. Instead of working directly with a TextFile object, we updated the main function to use an AbstractFile* pointer to interact with the file.
This tested polymorphism and ensured that our code doesn't need to know the specific type of file to call write, read, append, and getSize.
Our main function:
   int main(int argc, char *argv[]) {

   AbstractFile* file = new TextFile(argv[1]);
   std::vector<char> writeContent = {'a', 'b', 'c'};
   file->write(writeContent);
   std::cout << "Wrote to " << file->getName() << ": ";
   file->read();
   std::cout << std::endl;
   std::vector<char> appendContent = {'d', 'e', 'f', 'g', 'h'};
   file->write(appendContent);
   std::cout << "File content after appending: ";
   file->read();
   std::cout << std::endl;

   std::cout << "File size is now: " <<  file->getSize() << std::endl;

   return 0;
}