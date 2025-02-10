# File Encryption Program

A simple C program to encrypt and decrypt files using **XOR encryption**. The program allows users to select a file by entering its full path and provides options to **encrypt** or **decrypt** the file using a custom password (key).

## Features
✅ Encrypts any file using a user-defined key
✅ Decrypts the file with the same key
✅ Works with full file paths
✅ Supports Windows file paths with quotes (`"C:\\path\\to\\file.txt"`)
✅ No external libraries required

## How It Works
The program applies **XOR encryption**, meaning:
- Encryption and decryption use the **same function**.
- If you encrypt a file twice with the same key, you get the **original file back**.

## Installation & Compilation
### **Linux & macOS**
```sh
gcc -o file_encryption main.c
```

### **Windows (MinGW)**
```sh
gcc -o file_encryption.exe main.c
```

## Usage
Run the program from the command line:
```sh
./file_encryption
```

### **Encrypt a File**
```sh
1
"C:\Users\YourName\Desktop\secret.txt"
MySecretKey
```
**Output:** `C:\Users\YourName\Desktop\secret.txt.enc`

### **Decrypt a File**
```sh
2
"C:\Users\YourName\Desktop\secret.txt.enc"
MySecretKey
```
**Output:** `C:\Users\YourName\Desktop\secret.txt.enc.dec`

## Notes
- The same **key** must be used for **encryption and decryption**.
- If the key is lost, **decryption is impossible**.
- The program **does not store** the key for security reasons.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing
Feel free to submit pull requests or report issues in the GitHub repository!

