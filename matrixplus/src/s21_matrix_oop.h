#ifndef __S21__MATRIX__OOP__
#define __S21__MATRIX__OOP__

#define EPS 10E-9

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

 public:
  // Methods
  S21Matrix();   // Default constructor
  ~S21Matrix();  // Destructor

  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  // Functions
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix Minor(int iRow, int jCol);
  S21Matrix InverseMatrix();

  // Operations
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double& num);
  bool operator==(const S21Matrix& other) const;
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(const double& num);
  double& operator()(int i, int j);

  // Additional Methods:
  void AlocMatrix(double*** matrix, int rows, int cols);
  void DelMatrix(double** matrix);
  void CheckIndexes(int i, int j);
  void SwapMaxRows(double** matrix, int maxRow, int j);
  double GaussDet();
  int CheckZero();

  // Accessor & mutator
  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);
};

#endif  // __S21__MATRIX__OOP__