/*
      Modes of Inheritance

 Public mode: If we derive a sub class from a public base class. Then the
 public member of the base class will become public in the derived class and
 protected members of the base class will become protected in derived class.
 
 Protected mode: If we derive a sub class from a Protected base class. Then
 both public member and protected members of the base class will become protected
 in derived class.
 
 Private mode: If we derive a sub class from a Private base class. Then both
 public member and protected members of the base class will become Private in
 derived class.

 ___________________________________________________________________________
| Base class   |              Types of Inheritence                          |
| Member       |------------------------------------------------------------|
| Access       |   Public          |  Protected      |    Private           |
| Specifier    |                   |                 |                      |
| __________________________________________________________________________|
| Pubic        |   Public          |  Protected      |    Private           |
| __________________________________________________________________________|
| Protected    |   Protected       |  Protected      |    Private           |
| __________________________________________________________________________|
| Private      |   Not accessible  |  Not accessible |    Not accessible    |
|              |    (Hidden)       |   (Hidden)      |     (Hidden)         |
| __________________________________________________________________________|

*/
