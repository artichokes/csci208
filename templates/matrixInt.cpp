#include <iostream>
#include <string>
#include<cstdlib>

using namespace std;

const int MAXROWS = 2;
const int MAXCOLS = 3;

/*************************************************************************  
 * Class: Matrix
 *

 *************************************************************************/
template<typename M_type>
class Matrix {
 private:
  M_type doubleArray[MAXROWS][MAXCOLS];
  int rows;
  int cols;

 public:
  //Constructor
  Matrix();  //Set rows to MAXROWS and cols to MAXCOLS
  //Initialize all the values of doubleArray to zero

  //Getter Functions
  void printMatrix();

  //Setter Functions
  void setMatrix(M_type [][MAXCOLS]); //set the doubleArray to what is sent
  void addMatrix(M_type [][MAXCOLS]); //add an array to doubleArray
  void addMatrix(Matrix<M_type> otherMatrix);

  //No destructor needed
};

/************************************************************************* 
/* Class: Matrix
/* Function: Constructor  - Default
/*************************************************************************/
template<typename M_type>
Matrix<M_type>::Matrix() {
  rows = MAXROWS;
  cols = MAXCOLS;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      doubleArray[i][j] = '\0';
    }
  }
};

/************************************************************************* 
/* Class: Matrix
/* Function: printMatrix 
/*************************************************************************/
template<typename M_type>
void Matrix<M_type>::printMatrix() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << doubleArray[i][j] << "   ";
    }
    cout << endl;
  }
};

/************************************************************************* 
/* Class: Matrix
/* Function: setMatrix 
/*************************************************************************/
template<typename M_type>
void Matrix<M_type>::setMatrix(M_type otherArray[][MAXCOLS]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      doubleArray[i][j] = otherArray[i][j];
    }
  }
};

template<typename M_type>
void Matrix<M_type>::addMatrix(M_type otherArray[][MAXCOLS]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      doubleArray[i][j] += otherArray[i][j];
    }
  }
};

template<typename M_type>
void Matrix<M_type>::addMatrix(Matrix<M_type> otherMatrix) {
  addMatrix(otherMatrix.doubleArray);
};


/************************************************************************* 
/* Test Program
/*************************************************************************/

template<typename M_type>
void demoTemplate(Matrix<M_type> M, M_type array1[][MAXCOLS], M_type array2[][MAXCOLS]);

int main() {
  cout << " TEMPLATE LAB - CLASSES " << endl;

  cout << "\nDemonstrating with string matrix:" << endl;
  string String1[MAXROWS][MAXCOLS] = {
      {"Congra", "y", "ar"},
      {"alm", "don", "La"}
  };
  string String2[MAXROWS][MAXCOLS] = {
      {"gulations", "ou", "e"},
      {"ost", "e\tthe", "b!"}
  };
  Matrix<string> stringMatrix;
  demoTemplate(stringMatrix, String1, String2);

  cout << "\nDemonstrating with int matrix:" << endl;
  int Num1[MAXROWS][MAXCOLS] = {
      {1, 2, 3},
      {4, 5, 6}
  };
  int Num2[MAXROWS][MAXCOLS] = {
      {6, 5, 4},
      {3, 2, 1}
  };
  Matrix<int> intMatrix;
  demoTemplate(intMatrix, Num1, Num2);

  cout << "\nDemonstrating with char matrix:" << endl;
  char Char1[MAXROWS][MAXCOLS] = {
      {'!', '!', '!'},
      {'!', '!', '!'}
  };
  char Char2[MAXROWS][MAXCOLS] = {
      {'!', '"', '#'},
      {'$', '%', '&'}
  };
  Matrix<char> charMatrix;
  demoTemplate(charMatrix, Char1, Char2);

  cout << "\n" << endl;
  return 0;
}

template<typename M_type>
void demoTemplate(Matrix<M_type> M, M_type array1[][MAXCOLS], M_type array2[][MAXCOLS]) {
  M.setMatrix(array1);
  cout << "\nMatrix set to first array" << endl;
  M.printMatrix();

  M.addMatrix(array2);
  cout << "\nMatrix incremented by second array" << endl;
  M.printMatrix();
}
