# Key Logger for Windows

This is a small keylogger code I made back in 2007.

When you double-click the exe file, it will go to the background and write to a file called _svchost.log_. The log will be located where the exe is located.

Add it to Windows startup if you want it to run automatically.

Windows Defender in Windows 10 can detect this. Don't forget to let Window "trust it."

To kill it, go to Task Manager.

## Disclaimer

I am not liable for anything you do with it. This is criminal in many jurisdictions. **This is for educational purposes only.**

## Compiling from source

1. Download GCC compiler
2. Run `gcc logger.c -o svchost.exe`

## Get it

[Download here](https://github.com/shyrwinsia/keylogger/releases)

## License

[MIT](https://github.com/shyrwinsia/keylogger/blob/main/LICENSE)
