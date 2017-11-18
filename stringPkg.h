// stringPkg.h
// A library of ASCIIZ string functions.
// All functions in this library manipulate character arrays
// whose values are sequences of characters (string-values)
// utilizing the ASCIIZ format.

// -------------------------------------------------------------
// Return length of a string, length >= 0.
// Length is a count of the characters in the string-value,
//    not including the null at the end.
// An empty string ("") has length 0.
int stringLength(const char s[]);

// -------------------------------------------------------------
// Copy string src to string dest.
void stringCopy(char dest[], const int destBuffSize, const char src[]);

// -------------------------------------------------------------
// Concatenate string t to end of string dest
void stringConcatenate(char dest[], const int destBuffSize, const char t[]);

// -------------------------------------------------------------
// Retrieve character from string s[position].
// Position must be between 0 and (stringLength-1).
// Return 0 if position is out of range.
char stringGetchar(const char s[], const int position);

// -------------------------------------------------------------
// Find ch in string s starting at the 'startpos' array location.
// startpos must be non-negative and less than the string length.
// Return the 'found' position: 0 - (stringLength-1)
// Return -1 if ch not found in s.
int  stringFindchar(const char s[], const char ch, const int startpos = 0);

// -------------------------------------------------------------
// Set resultString[] to a string value that is a copy of
//    a specified substring of original string s.
// If specified start position is not located within the string s,
//    then set resultString to the empty string ("").
// If specified len < 0, or if (start + len) > the length of s
//    then set resultString to the longest possible substring.
void stringSubstring(
		char resultString[],		// new string buffer
		const int resultBuffSize,	// result array buffer size
		const char s[],				// the original string
		const int start,			// starting position of substring within s
		const int len = -1);		// length of substring within s
 									//   len<0: longest possible substring
// -------------------------------------------------------------
// Alphabetically compare string s to string t, based on ASCII charset.
// Return an integer value < 0 if s <  t
// Return an integer value 0   if s == t
// Return an integer value > 0 if s >  t
int  stringCompare(const char s[], const char t[]);

// -------------------------------------------------------------
// Convert a string s to an int value.
// s must be cstring sequence of digits only.
// -- non-digit characters in the string value are skipped and ignored.
int stringConvertToInt(const char s[]);

// -------------------------------------------------------------

