# Studio 20
1. Nicole Dai, Sandro Xiao

2. It is necessary to delete the pointer to the protected file in the PasswordProxy
destructor because PasswordProxy is now responsible for the original file when it is created.
If we don't delete it, we would end up with a memory leak since the dynamically allocated file
would never get freed. By deleting it in the destructor, we make sure the memory is properly
cleaned up when the proxy object is destroyed.

3. We implemented the PasswordProxy class by creating a wrapper around an AbstractFile.
It checks the password before allowing any operations like read, write, append, or accept.
If the password entered is correct, it forwards the request to the actual file. Otherwise, it
either returns an error code or an empty vector.

4. We tested the PasswordProxy by:
Creating a TextFile and wrapping it in a PasswordProxy with a password.
Trying to read from the file (and checking if the password was correctly required).
Trying to write new contents into the file.
Trying to append new contents to the file.
Using the visitor pattern to display the file through the proxy.

Results observed:
When the correct password was entered, the operations (read, write, append, and accept) worked as expected.
When a wrong password was entered, the proxy blocked access (returning an empty vector or an error code).
Everything behaved correctly once the final fixes were made.

5. Failed tests: A few test cases were not passing because write() was not working with expected value of 0 but returned value of 1. 
Essentially, it was always returning 1. These were resolved by investigating the implementation and discovering that
'protectedFile->write(contents)' did not contain return in front of it. This was also true for append and read. After
adding the correct return statements, the code ran as expected and passed all the test cases.
