#include <iostream>
#include <vector>

template<class T>
void PrintMatrix(std::vector<std::vector<T>> mat)
{
    int rows = mat.size();
    int cols = mat[0].size();
    for (int rId = 0; rId < rows; rId++)
    {
        for (int cId = 0; cId < cols; cId++)
        {
            std::cout << mat[rId][cId];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<class T>
std::vector<std::vector<T>> TransposeMatrix(std::vector<std::vector<T>> mat)
{
    std::vector<std::vector<T>> result;
    int rows = mat.size();
    int cols = mat[0].size();
    result.resize(cols);
    for (int cId = 0; cId < cols; cId++)
    {
        result[cId].resize(rows);
        for (int rId = 0; rId < rows; rId++)
        {
            result[cId][rId] = mat[rId][cId];
        }
    }
    return result;
}

int main(int argc, char** argv)
{
    std::vector<std::vector<float>> matA = {
        {1,1,1},
        {2,2,2},
        {3,3,3},
    };
    std::vector<std::vector<float>> matB = {
        {5,5},
        {6,7},
        {9,1},
    };
    PrintMatrix(matA);
    matA = TransposeMatrix(matA);
    PrintMatrix(matA);

    PrintMatrix(matB);
    matB = TransposeMatrix(matB);
    PrintMatrix(matB);

    return 0;
}