| Reference                                                              | Pointer                                                    |
| ---------------------------------------------------------------------- | ---------------------------------------------------------- |
| Always needs an initializer                                            | Initializer is optional                                    |
| Initializer should be lvalue(const ref can be initialized with rvalue) | Initializer need not be lvalue                             |
| Cannot be nullptr                                                      | Can be nullptr                                             |
| Bound to its referent                                                  | Can point to other variables                               |
| No storage required. Has the same memory address as its referent.      | Has its own storage, so will have different memory address |
| Dereference is not required to access value.                           | Required                                                   |


| lvalue                                           | rvalue                                       |
| ------------------------------------------------ | -------------------------------------------- |
| has a name                                       | does not have a name                         |
| Can be assigned values                           | cannot be assigned values                    |
| Some expressions return lvalues                  | some return rvalues                          |
| l-value persists beyond expression               | does not persist beyond expression           |
| functions that return by reference return lvalue | functions that return by value return rvalue |
| lvalue reference                                 | rvalue reference                             |
|                                                  |                                              |

| Flag    | Meaning                          | function    |
| ------- | -------------------------------- | ----------- |
| goodbit | no error                         | bool good() |
| badbit  | irrecoverable stream error       | bopol bad() |
| failbit | IO operation failed              | bool fail() |
| eofbit  | end of file reached during input | bool eof()  |