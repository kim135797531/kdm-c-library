# kdm-c-library
The repository to solve dirty problem on C++ programming.

###CKDMArray2D
* C++ 2D array control with any data types.

#### Usage
1. Just write `#include 'array2d.h'`.
2. You can make 2d array instance with any data types.
  * `CKDMArray2D<T> awesomeArray;`
3. You can easily access to data.
  * `awesomeArray(3, 5);`
  * `awesomeArray.getData(3, 5);`

#### Create Example
* Only with size information
  * `new CKDMArray2D<int>(row, col);`
* Exist double ptr
  * `new CKDMArray2D<int>(row, col, doublePtr);`
* Exist double-dimension fixed array
  * `new CKDMArray2D<int>(row, col, &arr[0][0]);`
* Exist single ptr, single-dimension fixed array
  * `new CKDMArray2D<int>(row, col, singlePtr);`
* Exist vector
  * `new CKDMArray2D<int>(row, col, vectorPtr);`

---

###CKDMBitwiseFlag
* C++ bitwise flag control with many flag.
* Can be accessed with bitwise(unsigned char) or flag index.
* **Warning: Performance of this class is currently _pretty bad_. I think it might be run slowly than a normal one.**

#### Usage
1. Just write `#include 'bitwise-flag.h`.
2. You can make bitwise flag instance with any size.
  * `CKDMBitwiseFlag awesomeFlags(200); //200 Flags`
3. You can easily access to data.
  * `awesomeFlags.setByBit(0x000000AA); //operation OR 0b10101010`
  * `awesomeFlags.setByIndex(3); //operation OR 0b00000100`
  * `awesomeFlags.setByBit(0x000000AA, 5); //operation OR 0b10101010 to address of fifth byte.``
  * 

#### TODO
* Improve performance when using a few flag
  * Use simple algorithm instead of using dynamic unsigned char array

---

###CKDMFileRead
* C++ file read control that manages the file data array automatically.

#### Usage
1. Just write `#include 'file-read-write.h'`.
2. You can easily open the file.
  * `CKDMFileRead awesomeFile("input.txt"); //open file`
3. You can easily read the data.
  * `awesomeFile();` //read all

#### Example
* Read all
  * `awesomeFile();`
  * `awesomeFile.getRawData();`
* Read in range
  * `awesomeFile(testDataDest, 13, 5); //read data range of 13 ~ 17 (length is 5)`
  * `awesomeFile.getData(testDataDest, 13, 5);`
* If you annoying to use this class, JUST request stream! (Very coooooooool class =))
  * `awesomeFile.getStream();`

---

###CKDMFileWrite
* C++ file write control that manages the stream, offset, etc.
* **Warning: If you use this class after understanding it wrongly, your output file might be damage _PERMANETLY!_**
  * ex) Open the file to modify with truncate mode will delete your all data in file immediately.

#### Usage
1. Just write `#include 'file-read-write.h'`.
2. You can easily open the file.
  * `CKDMFileWrite awesomeFile("output.txt"); //open file with append mode(default)`
3. You can easily write the data.
  * `awesomeFile("amami-haruka-chan-daisuki!", 27); //write to file`

#### Example
* Open file
  * `awesomeFile("output.txt"); //open file with append mode(default)`
  * `awesomeFile("output.txt", CKDMFileWrite::WRITE_TRUNCATE);`
  * `awesomeFile("output.txt", CKDMFileWrite::WRITE_ATEND);`
* Write
  * `awesomeFile("amami-haruka-chan-daisuki!", 27);`
  * `awesomeFile.writeData("amami-haruka-chan-daisuki!", 27);`
* Modify
  * `awesomeFile.modifyData("chihaya", 6, 7); //modify data range of 6 ~ 13 (length is 7)`
* Change mode
  * `awesomeFile.changeMode(CKDMFileWrite::WRITE_ATEND);`
* If you annoying to use this class, JUST request stream! (Very coooooooool class =))
  * `awesomeFile.getStream();`