Name: Nicole Dai, Sandro Xiao 
Lab #: 5

How we divided up work:
For Studios 16–21, the work was completed collaboratively. Nicole dedicated more time on Studios 16–19,
while Sandro focused primarily on Studios 20–21. However, we both contributed to and collaborated
on all the studios. For lab 5, we met up and worked on the entire lab in person. We split up the work
between the different commands with Sandro completing touch, ls, remove, cat, macro, rename, and additional
macro (touch cat display) and Nicole completing display, copy, and fixed the errors until all
the testlab5 test cases passed. Nicole created the test cases for the base lab and Sandro created the test cases for the
extra credit.

Build/Development Errors:
- We had build errors with our include statements in one of the earlier studios because we added circular include statements.
After receiving help from Professor Shidal, we were able to use forward declarations to fix all our header files that had this
issue.
- When we created password proxy to verify the password initially, we wrapped it in a while true loop, constantly waiting 
to make sure that the password was correct. However, when we were created the test cases, the program got caught in the infinite loop
and never finished running. We removed this while loop and adjusted the code accordingly, and the test cases for that section ran correctly.
- We had an issue in our prompt where it would read an empty line from the stream. To fix this, we added an additional condition 
to our run() function to check if the prompt input equaled an empty string. If it did, we would just ask to reprompt.
- We also initially passed in the factory pointer to all of our commands even though touch was the only one that needed it. We didn't realize this
until we ran our program, and it was causing errors. To fix this, we went back and removed the unnecessary pointers.
- When we were setting up our test cases in lab5, we accidentally added tcd to be associated with the rename macro instead of the tcd macro.
Then when we only provided one file name it would throw an error because copy requires two file names (the original and the new name).
- When we were implementing our remove function, we forgot to pass our remaining input through the stream to get rid of the space in front of the file.
Our code would initially search for the file, but didn't exist, so remove would fail.
- The issue with the empty line from the stream came up again from our PasswordProxy passwordPrompt. After prompting a password entry
in for example cat, (but never touch), it would read in white space from the stream and cause the terminal to prompt "Enter a command..." twice, with the first one essentially not letting
the user input. This was solved by adding a getline() with iss>>ws as opposed to a cin, so it would properly filter out white space.

Testing:

Here are all of our possible return values:
enum ERROR_CODE {
SUCCESS = 0,
FILE_DOES_NOT_EXIST = -1,
FILE_OPEN_FAIL = -2,
FAIL_TO_INSERT_COMMAND = -3,
USER_QUIT = -4,
INVALID_INPUT = -5,
APPEND_NOT_ALLOWED = -6,
INVALID_FILE_CONTENT = -7,
LS_COMMAND_FAILED = -8,
NO_STRATEGY = -9,
COMMANDS_INPUT_MISMATCH = -10,
INVALID_PASSWORD = -11,
REMOVE_FAIL = -12,
DUPLICATE_FILE = -13,
NULL_PTR = -14,
INVALID_FILE_EXTENSION = -15,
FILE_NOT_OPENED = -16,
FILE_ALREADY_OPENED = -17,
FILE_CREATE_FAIL = -18,
FILE_ADD_FAIL = -19,
INVALID_FLAG = -20
};

Here are all of our test cases:
1. create an image file: 'touch file.img'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $touch file.img

    touch command functions as expected and creates an image file called file.img. No error messages were printed as a result.
2. create a text file: 'touch file.txt'
   C:\Users\Nicole\CLionProjects\oop-work-lkmsdalfmklasdmflaksdfmaskldjfnklasdf\cmake-build-debug\src\lab5.exe
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $touch file.txt

   touch command functions as expected and creates an image file called file.img. No error messages were printed as a result.

3. create an image file with a password: 'touch apple.img -p'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $touch apple.img -p

   What is the password for apple.img?
   banana

   touch command with the password proxy flag ran as expected. It asked for a password and create an image file called apple.img.

4. create a text file with a password" 'touch orange.txt -p'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $touch orange.txt -p

   What is the password for orange.txt?
   grape
   touch command with the password proxy flag ran as expected. It asked for a password and create an text file called orange.txt.

5. listing the file directory: 'ls'
   $ls

   apple.img           image.img
   orange.txt

   ls command functions as expected and formats all the files in the directory into two columns.

6. listing the file directory with file metadata: 'ls -m'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $ls -m

   Input your password for file apple.img
   banana

   apple.img           image               0
   image.img           image               0
   Input your password for file orange.txt
   grape

   orange.txt          text                0

   ls command with the metadata flag functions as expected and prints the file name, file type, and file size.
   Since apple.img and orange.txt have passwords, the system prompted the user for a password before printing out the
   corresponding metadata.

7. write to a text file: 'cat file.txt'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $cat file.txt

   Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
   happy birthday
   :wq

   cat command functions as expected by writing the user inputted text to the file.


8. write to an image file: 'cat x.img'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $cat x.img

   Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
   X X X X X3

   :wq
   
   The cat command behaves as expected and is able to write all the X's and ' ' to the image file correctly.

9. append to a text file: 'cat yippee.txt -a'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $cat yippee.txt -a

   yay yay yay
   Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
   new new new

   :wq

   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $ds

   Error: No file name provided.
   COMMAND FAILED TO EXECUTE
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $ds yippee.txt

   yay yay yaynew new new

   The cat command and append flag for a text file works as expected. The program realizes that we are also asking to append
   and it displays the original content before prompting for the additional content to append. After appending the content,
   I displayed the content to the terminal, and we can see the original 'yay yay yay' is still there along with 'new new new'.

10. append to an image file: 'cat x.img -a'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $cat x.img -a

   Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
   XXXXX

   :wq

   Cannot append to an image file.
   COMMAND FAILED TO EXECUTE

   Since appending to a image file is not allowed, the cat command behaves correctly and prints an error message. The additional
   content is not added to the original image file.

11. using general help command: 'help'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $help

   cat
   cp
   ds
   ls
   rm
   rn
   tcd
   touch

   The help command behaves correctly and prints out all the available commands to use.

12. using help for a specific command: 'help touch'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $help touch

   touch creates a file, touch can be invoked with the command: touch <filename> [-p]

   Regardless of which command, help ___ will print out a usage message of how to use the command.

13. invalid help command: 'help draw'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $help draw

   COMMAND DOES NOT EXIST

   Since draw is not a valid commmand, the program prints out an error message saying that this command does not exist.
14. copy a file (with content): 'cp hungry.txt full'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $cp hungry.txt full

   File successfully copied
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $ds full.txt

   food food food
   
   The copy command works as intended by copying a files content into a new file. In this case, I created a file called hungry.txt
   which had "food food food" as its content. When I copied hungry.txt into full.txt, we can see that full displays "food food food"
   as well. Additionally, we had a comment saying that the file was copied successfully.

15. copy a file (with content & password): 'cp soup.txt potato'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $cp soup.txt potato

   File successfully copied
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $cat potato.txt

   Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
   hello

   :wq

   Input your password for file potato.txt
   yummy

   The copy command behaved as expected even when a file has a password. I created a text file called soup.txt with password "yummy".
   When I copied that file and created potato.txt, the original password "yummy" was passed over to the new file.


16. remove a file: 'rm file.txt'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
    $  rm file.txt

    File removed successfully.

    In this test case, I created a text file called file.txt and then removed it. It was able to sucessfully remove the file from our list of
    files and prints a successful message to the user.

17. remove a file that does not exist 'rm fakefile.txt'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $rm fakefile.txt

    FILE REMOVE FAILED
    COMMAND FAILED TO EXECUTE

    The file fakefile.txt was never created, so when the system tried to delete the file, it failed. The system prints out an error message
    alerting the user that the file was unable to be removed, and consequently the command failed to execute. This functions as expected because I
    never created the file in the first place.

18. display nonexistent text file: 'ds fake.txt'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $ds fake.txt

   Error: File a.txt could not be opened.
   COMMAND FAILED TO EXECUTE

   Since fake.txt was never created, the program was unable to locate the file. As expected, it printed an error
   message indicating that the file could not be opened. The display command thus failed to execute, which is the \
   intended behavior.
   
18. display text file: 'ds file.txt'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $ds food.txt

   orange
   lobster
   pancake

   I added content to food.txt and it displayed it 


19. display image file (formatted): 'ds x.img'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $ds x.img

   X X
    X
   X X 
   
20. display image file (unformatted): 'ds file.img -d'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $ds x.img -d

   X X X X X

   Since I asked for the image file to be unformatted, the content just prints as normal text. This prints as expected.

21. rename an image file: 'rn file.img yay'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $rn file.img yay

   File successfully copied
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $ls

   yay.img

   The rename command works as expected and finds the old file makes a copy to with a new name and deletes the original file.
   In this case, file.img got renamed to yay.img and it is show in the file system when I called ls.

22. rename a text file: 'rn file.txt yummy'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $rn yummy.txt ew

   File successfully copied
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $ls

   ew.txt

   The rename command behaved as expected. I created a text file called yummy and renamed it later to ew. Using ls, we can see that
   the file has been renamed successfully.

23. rename a text file (without new name):
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $rn yummy.txt

   Error: Please provide both an original filename and a new name.

   The rename command functions as expected. Since the program did not receive a new name for the original file, the command failed
   and an error message was printed.

24. using cat command but not saving: ':q'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $cat lime.txt

   Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
   sour

   :q

   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $ds lime.txt
   
   
   I tested the functionality of cat by deciding to write content but not save it. Since I requested ':q', the program did not
   save the text that I added. This works as expected.

25. no input:
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $

   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $
   
   When no input is given, the program simply reprompts the user, waiting for a new command. This functions as expected.

26. user quits program: 'q'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $q


   Process finished with exit code 0
   
   When the user wants the quit the program, they can type 'q'. This ends the prompting system and the process exits successfully
   and returns an exit code of 0. This functions as expected.

27. invalid file extension: 'touch happy.jpeg'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $touch happy.jpeg

   COMMAND FAILED TO EXECUTE
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
   hat command.
   $FILE CREATION FAILED

   When the user tries to add an invalid file extension, the program prints an error message showing that firstly, this command failed to execute,
   and also file creation failed. This functions correctly becaues we only accept file extensions img and txt not jpeg.

28. wrong password:
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $touch ilove332.txt -p

    What is the password for ilove332.txt?
    332isamazing

    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $cat ilove332.txt

    Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
    yay :)

    :wq

    Input your password for file ilove332.txt
    332isok

    COMMAND FAILED TO EXECUTE

    I created a text file called ilove332.txt with a password 332isamazing. When I tried to write to the file using the cat command,
    I inputted the wrong password. The information 'yay :)' was never added to the file because of the incorrect password. This is the correct
    functionality for this specific test case.

28. macro command touch cat display: 'tcd happy.txt'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $tcd file.txt

    Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
    332 is the best

    :wq

    332 is the best

    tcd macro command works as expected. It created a text file called file.txt and asked the user what to write to it. Then,
    it displays the content (332 is the best). Touch, cat, and display, are called all at once in this one macro command.

29. macro command touch cat display (w/ no file name provided: 'tcd '
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $tcd

    COMMAND FAILED TO EXECUTE
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about t
    hat command.
    $FILE CREATION FAILED

    The command failed to execute because a file name was not provided. An error message printed to the user saying that the command
    failed to execute and the file was not created. This functions as expected and displays the proper error messages accordingly.


Extra Credit: Running a script

Our goal is to implement a RunCommand and a filetype ScriptFile with a custom extension ".scp". ScriptFiles contain a sequence of commands, one per line. RunCommand reads a ScriptFile and executes each commmand, 
line by line and in sequence. Our idea was approved by Professor Shidal on 5/2/2025. First, we created a RunCommand class that allows the file system to execute the script. We also added a supporting runCommand(commmand)
helper method that functions the same as our run() method in CommandPrompt except it already has the command passed in instead of prompting. In our 
execute for RunCommand, we created a while loop that gets the line of every command until the line is empty.
Then, ScriptFile class was created with similar setup to that of TextFile. We added ScriptFile logic and methods to the MetadataDisplayVisitor, BasicDisplayVisitor, and SimpleFileFactory classes
so that this filetype would be accessible and properly integrated with the rest of our file system.


Test cases:

1.  run correct premade script file:
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
    $  run script_right.scp
    Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
    hello
    :wq
    hello
    File successfully copied
    hooray.txt          text                5                   
    yippee.txt          text                5                   
    File removed successfully.
    hooray.txt

    Our extra credit run command works as expected on a correct file. It receives the input of script_right.scp, a script file with the .scp file extension
    and executes all commands in the file successfully. It functions as expected and displays all of the proper print commands for each of the commands.

2.  run erroneous premade script file:
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
    $  run script_wrong.scp
    Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
    hello
    :wq
    hello
    File successfully copied
    hooray.txt          text                5                   
    yippee.txt          text                5                   
    File removed successfully.
    FILE OPEN ERROR
    COMMAND FAILED TO EXECUTE
    hooray.txt

    Our extra credit run command works as expected on a file that is not correct. It receives the input of script_right.scp, a script file with the .scp file extension
    and executes all the commands in the file successfully. It functions as expected and displays all of the proper print commands for each of the commands. For this example,
    it fails to cat the yippee.txt file in line 7 of the script file because that file has been removed after its contents were copied to hooray.txt.
    This is as expected with the function of our run command and script file.

3. create a script file: 'touch file.scp'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  touch file.scp
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  ls
   file.scp            
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

   touch command functions as expected and creates an script file called file.scp. No error messages were printed as a result.

4. create a script file with password: 'touch file.scp -p'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  touch file.scp -p
   What is the password for file.scp?
   y
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  ls
   file.scp

   touch command with the password proxy flag ran as expected. It asked for a password and create an script file called file.scp.

5. write to a script file: 'cat file.scp'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  cat file.scp
   Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
   hi
   :wq

   The cat command behaves as expected and is able to write to the script file correctly.

6. append to a script file: 'cat file.scp -a'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  cat file.scp -a
   hi
   Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
   hello
   :wq
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  ds file.scp
   hi
   hello

   The cat command and append flag for a script file works as expected. The program realizes that we are also asking to append
   and it displays the original content before prompting for the additional content to append. After appending the content,
   I displayed the content to the terminal, and we can see the original 'hi' is still there along with 'hello'.

7. copy a script file: 'cp file.scp newFile'
   $  cp file.scp newFile
   File successfully copied
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  ls
   file.scp            newFile.scp         
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  ds newFile.scp
   hi

   The copy command works as intended by copying a files content into a new file. In this case, I had a file called 'file.scp'
   which had "hi as its content. Copying file.scp to newFile.scp, we can see that newFile.scp displays "hi"
   as well. Additionally, we had a comment saying that the file was copied successfully.

8. copy a script file with password: 'cp file.scp newFile'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  cp file.scp newFile
   File successfully copied
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  cat newFile
   FILE OPEN ERROR
   COMMAND FAILED TO EXECUTE
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  cat newFile.scp
   Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
   hello
   :wq
   Input your password for file newFile.scp
   y

The copy command behaved as expected even when a file has a password. I created a scp file called file.scp with password "y".
When I copied that file and created newFile.scp, the original password "y" was passed over to the new file.

9. display script file: 'ds file.scp'
   Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
   $  ds file.scp
   hi 
   hello again

Content was added to file.scp and it was displayed.
10. rename script file: 'rn newFile.scp FILE'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
    $  rn newFile.scp FILE
    File successfully copied
    File removed successfully.
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
    $  ls
    FILE.scp            f.txt               
    foods.txt

The rename command works as expected and finds the old file makes a copy to with a new name and deletes the original file.
In this case, newFile.scp got renamed to FILE.scp and it is show in the file system when I called ls.
11. macro tcd script file: 'tcd f.scp'
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
    $  tcd f.scp
    Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
    HELLO
    :wq
    HELLO

tcd macro command works as expected. It created a text file called f.scp and asked the user what to write to it. Then,
it displays the content "HELLO". Touch, cat, and display, are called all at once in this one macro command.

12. remove a file: 'rm file.scp'
    $  rm file.scp
    File removed successfully.
    Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
    $  ls
    newFile.scp
    In this test case, I created a script file called file.scp and then removed it. It was able to sucessfully remove the file from our list of
    files and prints a successful message to the user.