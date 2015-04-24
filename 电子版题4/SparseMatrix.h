template<class E>
struct Triple {               //三元组类
     int row, col;	       //非零元素行号/列号
     E value;                   //非零元素的值
     Triple<E>& operator = (Triple<E>& R) //结点赋值  
        { row = R.row;  col = R.col;  value = R.value; }
};			

template <class E>
class SparseMatrix {
public: 
     SparseMatrix (int Rw , int Cl ,int Tm );                   //构造函数
     ~SparseMatrix() {delete []smArray;}  //析构函数
     void Transpose(SparseMatrix<E>& B);    //转置
     void Multiply (SparseMatrix<E>& A); 
private:
     int Rows, Cols, Terms;        //行／列／非零元素数
     Triple<E> *smArray;          //三元组表
};      

template <class E>
SparseMatrix<E>::SparseMatrix (int Rw, int Cl, int Tm) {
    Rows = Rw;   Cols = Cl;   Terms = Tm;
    smArray = new Triple[Terms];          //三元组表
    if (smArray == NULL) {
         cerr << “存储分配失败！” << endl;  exit(1);
    }
};  

template <class E>
void SparseMatrix<E>::Transpose (SparseMatrix<E>& B) {
    int *rowSize = new int[Cols];       //列元素数数组
    int *rowStart = new int[Cols];      //转置位置数组
    B.Rows = Cols;   B.Cols = Rows;
    B.Terms = Terms;
    if (Terms > 0) {
        int i, j;
        for (i = 0; i < Cols; i++) rowSize[i] = 0; 
	 	for (i = 0; i < Terms; i++)
            rowSize[smArray[i].col]++; //原矩阵各列非零元数！
            rowStart[0] = 0;	
            for (i = 1; i < Cols; i++)			
	       	rowStart[i] = rowStart[i-1]+rowSize[i-1];
	  		for (i = 0; i < Terms; i++) {			
	       	j = rowStart [smArray[i].col];
                      //第i个非零元在矩阵B中应放的位置	
	       B.smArray[j].row = smArray[i].col;    //传送
	       B.smArray[j].col = smArray[i].row;
	       B.smArray[j].value = smArray[i].value;
	       rowStart [smArray[i].col]++; //修改该行应放位置
	  }

template <class E>
void SparseMatrix<E>::Multiply (SparseMatrix<E>& B) {
    SparseMatrix<E> result(Rows,b.Cols);
    int rowsize = new int[b.Rows];
    int rowstart = new int[b.Rows+1];
    E *temp = new E[b.Cols];
    int i,current,lastinresult,rowA,colA,colB;
    for (i=0;i<b.Rows;i++) rowsize[i]=0;
    for (i=0;i<b.Rows;i++) rowsize[b.smArray[i].row]++;
        rowstart[0]=0;
    for (i=0;i<b.Rows;i++)
        rowstart[i]=rowstart[i-1]+rowsize[i-1];
    current=0;lastinresult=-1;
    while(current<Terms){
        rowA=smArray[current].row;
        for (i=0;i<b.Cols;i++) temp[i]=0;
            while(current<Terms&&smArray[current].row==rowA){
                colA=smArray[current].col;
                for(i=rowstart[colA];i<rowstart[colA+1];i++){
                    colB=b.smArray[i].col;
                    temp[colB]+=smArray[current].value*b.smArray[i].value;
                }
                current++;
            }
            for(i=0;i<b.Cols;i++)
                if(temp[i]!=0){
                    lastinresult++;
                    result.smArray[lastinresult].row=rowA;
                    result.smArray[lastinresult].col=i;
                    result.smArray[lastinresult].value=temp[i];
                }
    }
    result.Rows=Rows;result.Cols=b.Cols;
    result.Terms=lastinresult+1;
    delete []rowsize,[]rowstart,[]temp;
    return result;
}


