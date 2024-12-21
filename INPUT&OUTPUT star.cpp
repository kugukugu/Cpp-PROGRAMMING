#include <iostream>

int main()
{
    int i,j,k, N;

    std::cin >> N;

    for(i=1; i<=N; i++)
    {
        for(j=N-1; j>i-1; j--)
        {
            std::cout << " ";
        }

        for(k=0; k<2*i-1; k++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }



    return 0;
}
