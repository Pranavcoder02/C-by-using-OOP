#include<iostream>
using namespace std;

class matrix
{
    private:
        int rows, cols;
        int data[100][100];

    public:
        matrix(int r, int c): rows(r), cols(c)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    data[i][j] = 0;
                }
            }
        }

        matrix operator+(matrix const& obj)
        {
            matrix res(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    res.data[i][j] = data[i][j] + obj.data[i][j];
                }
            }
            return res;
        }

        matrix operator-(matrix const& obj)
        {
            matrix res(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    res.data[i][j] = data[i][j] - obj.data[i][j];
                }
            }
            return res;
        }

        matrix operator*(matrix const& obj)
        {
            matrix res(rows, obj.cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    res.data[i][j] = 0;
                    for (int k = 0; k < cols; k++)
                    {
                        res.data[i][j] += data[i][k] * obj.data[k][j];
                    }
                }
            }
            return res;
        }

        void display()
        {
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    cout << data[i][j] << "\t";
                }
                cout << endl;
            }
        }

        void inputMatrix()
        {
            cout << "Enter elements of the matrix:" << endl;
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    cin >> data[i][j];
                }
            }
        }
};

int main()
{
    int rows, cols;
    cout << "Enter the number of rows for matrices: ";
    cin >> rows;
    cout << "Enter the number of columns for matrices: ";
    cin >> cols;

    matrix m1(rows, cols), m2(rows, cols);

    cout << "Enter elements for matrix m1:" << endl;
    m1.inputMatrix();

    cout << "Enter elements for matrix m2:" << endl;
    m2.inputMatrix();

    cout << "Matrix m1:" << endl;
    m1.display();
    cout << endl;

    cout << "Matrix m2:" << endl;
    m2.display();
    cout << endl;

    matrix m3 = m1 + m2;
    cout << "Addition:" << endl;
    m3.display();
    cout << endl;

    matrix m4 = m1 - m2;
    cout << "Subtraction:" << endl;
    m4.display();
    cout << endl;

    matrix m5 = m1 * m2;
    cout << "Multiplication:" << endl;
    m5.display();
    cout << endl;

    return 0;
}
