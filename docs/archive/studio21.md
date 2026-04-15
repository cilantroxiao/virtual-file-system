# Studio 21
1. Nicole Dai, Sandro Xiao

2. It is important to declare a virtual destructor in the base class to make sure that when an
object is deleted through a pointer to the base class, the derived class’s destructor is also called.
Without a virtual destructor, only the base class destructor would run, which can lead to memory
leaks and improper cleanup of resources owned by the derived class.

3. Since we are relying on abstract interfaces like AbstractFileSystem, AbstractFileFactory,
and AbstractCommand, the CommandPrompt doesn’t need to know anything about the specific file
systems, factories, or commands it’s working with. By injecting the actual objects into the
CommandPrompt, we can easily swap in different file systems or factories without having to change
any of the CommandPrompt’s code. Instead of hardcoding anything, it just expects things to follow
the right interface. This means we can switch from something like a SimpleFileSystem to a more
advanced one, or change the factory, and everything will still work. We can also add new commands
whenever we want using addCommand, which makes it even more flexible. Overall, this setup makes
the CommandPrompt really easy to reuse and adapt depending on what kind of system we want it to
work with.

4. We tested the TouchCommand by adding it to the CommandPrompt and then running the prompt.
Inside the interactive prompt, we tried the following:
- Entered help to make sure the list of available commands showed up.
- Entered help touch to check if the help description for the touch command displayed properly.
- Used touch testfile.txt to create a new file.
- Typed q to quit out of the command prompt and return to main().

Everything behaved as expected and returned 0 for success.