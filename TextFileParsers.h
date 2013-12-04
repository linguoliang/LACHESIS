/**************************************************************************************************************************************************************
 *
 * TextFileParsers
 *
 * This module contains the following functions to parse input text files:
 *
 * TokenizeFile
 * ParseTabDelimFile
 * GetFastaNames
 *
 * and one function to create an output text file:
 *
 * MakeFastaNamesFile
 *
 *
 * Josh Burton
 * July 2013
 *
 *************************************************************************************************************************************************************/

#ifndef _TEXT_FILE_PARSERS__H
#define _TEXT_FILE_PARSERS__H



#include <vector>
#include <string>
using namespace std;



// Here are some useful "#define" pre-processor directives, copied from the file system/System.h in the ALLPATHS source code.
#define PRCORE(X) #X " = " << X
#define PRINT(X) cout << PRCORE(X) << endl;
#define PRINT2(X, Y) cout << PRCORE(X) << ", " << PRCORE(Y) << endl;
#define PRINT3(X, Y, Z) cout << PRCORE(X) << ", " << PRCORE(Y) << ", " << PRCORE(Z) << endl;
#define PRINT4(X, Y, Z, W) cout << PRCORE(X) << ", " << PRCORE(Y) << ", " << PRCORE(Z) << ", " << PRCORE(W) << endl;
#define PRINT5(X, Y, Z, W, T) cout << PRCORE(X) << ", " << PRCORE(Y) << ", "  << PRCORE(Z) << ", " << PRCORE(W) << ", " << PRCORE(T) << endl;
#define PRINT6(X, Y, Z, W, T, U) cout << PRCORE(X) << ", " << PRCORE(Y) << ", "  << PRCORE(Z) << ", " << PRCORE(W) << ", " << PRCORE(T) << ", " << PRCORE(U) << endl;
#define PRINT7(X, Y, Z, W, T, U, V) cout << PRCORE(X) << ", " << PRCORE(Y) << ", "  << PRCORE(Z) << ", " << PRCORE(W) << ", " << PRCORE(T) << ", " << PRCORE(U) << ", " << PRCORE(V) << endl;



// TokenizeFile: Split up a file into lines, and split each line into tokens using whitespace (spaces or tabs) as delimiters.
// Return all tokens as strings, in the output variable tokens.
// If compress = true, use the token_compress_on flag to compress multiple consecutive whitespace delimiters into one.
void
TokenizeFile( const string & infile, vector< vector<string> > & tokens, const bool & compress = false );




// ParseTabDelimFile: Parse a tab-delimited file.  Return a vector of the <column_ID>'th token (zero-indexed) on each line, recast as objects of class T.
template<class T> vector<T>
ParseTabDelimFile( const string & infile, const size_t column_ID );



// GetFastaNames: Input a FASTA filename and return the set of contig names in that FASTA.
// This function uses ParseTabDelimFile() on <fasta-file>.names, and if necessary it calls MakeFastaNamesFile() first to create <fasta-file>.names.
vector<string>
GetFastaNames( const string & fasta_file );


// MakeFastaNamesFile: Input a FASTA filename.  Create a file at <fasta-file>.names, containing all of the contig names in the FASTA, without the leading '>'.
// This is a wrapper for the Unix command: grep "\>" fasta-file | cut -c2- > fasta-file.names
// After running this, the contig names can be read in via: ParseTabDelimFile<string>( fasta-file.names, 0 )
void
MakeFastaNamesFile( const string & fasta_file );


#endif