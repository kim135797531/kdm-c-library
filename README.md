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
* only with size information
  * `new CKDMArray2D<int>(row, col);`
* exist double ptr
  * `new CKDMArray2D<int>(row, col, doublePtr);`
* exist double-dimension fixed array
  * `new CKDMArray2D<int>(row, col, &arr[0][0]);`
* exist single ptr, single-dimension fixed array
  * `new CKDMArray2D<int>(row, col, singlePtr);`
* exist vector
  * `new CKDMArray2D<int>(row, col, vectorPtr);`

---

###CKDMBitwiseFlag
* C++ bitwise flag control with many flag.
* Can be accessed with bitwise(unsigned char) or flag index.

#### Usage
1. Just write `#include 'bitwise-flag.h`.
2. You can make bitwise flag instance with any size.
  * `CKDMBitwiseFlag awesomeFlags(200);` //200 Flags
3. You can easily access to data.
  * `awesomeFlags.setByBit(0x000000AA);` operation OR 0b10101010
  * `awesomeFlags.setByIndex(3);` operation OR 0b00000100
  * `awesomeFlags.setByBit(0x000000AA, 5);` operation OR 0b10101010 to address of fifth byte.