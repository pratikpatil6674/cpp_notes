#include<iostream>
/*
2D matrix implementation, where all elements are contingous in memory
Shows better cache locality compared to vector of vectors implementation of a matrix.
*/

template <class T>
class matrix{
    class row{
        int c;
        T *d;
        public:
        row(int c, T *d) : c(c), d(d){

        }
        T& operator[](int j) {
            if(j>=c){
                std::cerr<<"Column index out of bound\n";
                exit(0);
            }
            return d[j];
        }  
    };
    int r, c;
    T *d;
    
    public:
    matrix(int r, int c) : r(r),c(c){
        if(r<=0 || c<=0){
            std::cerr<<"Invalid matrix dimensions\n";
            exit(-1);
        }
        d = new T[r*c];
    }
    matrix(int, float) = delete;
    matrix(float, float) = delete;
    matrix(float, int) = delete;
    row operator[](int i) {
            if(i>=r){
                std::cerr<<"Row index out of bound\n";
                exit(0);
            }
            row r(c,d+i*c);
            return r;
    }

    ~matrix(){
        delete[] d;
    }
};
int main(){
    matrix<int> m(2,2);
    for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        m[i][j]=i+j;
        std::cout<<m[i][j]<<std::endl;
    }
    }
}
