# include <iostream>
using namespace std;
const int initcap=5;
template <class T>
class sqlist
{
public:
    T* data;
    int capacity;
    int length;
    sqlist()
    {
        data=new T[initcap];
        length=0;
        capacity=initcap;
    }
    sqlist(const sqlist<T> & a)
    {
        this->capacity=a.capacity;
        this->length=a.length;
        this->data=new T[a.capacity];
        for(int i=0;i<length;i++)
            this->data[i]=a.data[i];
    }
    ~ sqlist()
    {
        delete[] data;
    }
    void createlist(T a[],int n)
    {
        length=0;
        for(int i=0;i<n;i++)
        {
            if(length==capacity)
                recap(2*capacity);
            data[i]=a[i];
            length++;
        }
    }
    void recap(int newcap)
    {
        T* oddcap=data;
        data=new T[newcap];
        capacity=newcap;
        for(int i=0;i<length;i++)
            data[i]=oddcap[i];
        delete[] oddcap;
    }
    void add(T a)
    {
        if(length==capacity)
            recap(2*capacity);
        data[length]=a;
        length++;
    }
    int getlength(){return length;}
    //用bool来作为返回值，增强代码健壮性
    bool getelem(int n,T & a)
    {
        if(n<0||n>=length) return false;
        a=data[n];
        return true;
    }
    bool setelem(int n,const T& a)
    {
        if(n<0||n>=length) return false;
        data[i]=a;
        return true;
    }
    int getno(const T & e)
    {
        for(int i=0;i<length;i++)
            if(data[i]==e) return i;
        return -1;
    }
    bool insert(int i,const T& a) 
    {
        if(i<0||i>length) return false;
        if(length==capacity)    recap(2*capacity);
        for(int j=length;j>=i;j--)
        {
            if(j==i) {data[i]=a;break;}
            data[j]=data[j-1];
        }
        length++;
        return true;
    }
    bool deleteelem(int i)
    {
        if(i<0||i>=length) return false;
        length--;
        for(int j=i;j<length;j++)
            data[j]=data[j+1];
        if(length<=capacity/4&&capacity>initcap)
            recap(capacity/2);
        return true;
    }
    void display()
    {
        for(int i=0;i<length;i++)
            cout<<data[i]<<' ';
        cout<<endl;
    }
};
template <class T>
void reserve(sqlist<T> &a)
{
    int left=0,right=a.length-1;
    while(left<right)
    {
        swap(a.data[left],a.data[right]);
        left++,right--;
    }
}
template <class T>
bool deleteelems(int index,int n,sqlist<T> & a)
{
    if(index+n>a.length||i<0||k<1) return false;
    for(int j=i+k;j<a.length;j++)
        a.data[j-k]=a.data[j];
    a.length-=n;
    return true;
}
//删除元素算法一:整体建表法
template <class T>
void deletex1(int goal,sqlist<T> & a)
{
    int k=0;
    for(int i=0;i<a.length;i++)
    {
        if(a.data[i]!=goal)
        {
            a.data[k]=a.data[i];
            k++;
        }
    }
    a.length=k;
}
//删除元素算法二:元素移动法
template <class T>
int deletex2(int goal,sqlist<T> &a)//返回删除的数量
{
    int k=0;
    for(int i=0;i<a.length;i++)
    {
        if(a.data[i]!=goal)
            a.data[i-k]=a.data[i];
        else
            k++;
    }
    a.length-=k;
    for(int i=a.length-1;i<a.length+k;i++)
        a.data[i]=0;
    return k;
} 
//删除元素算法三:区间划分法
template<class T>
void deletex3(int goal,sqlist<T> &a)
{
    int begin=-1;
    for(int i=0;i<a.length;i++)
    {
        if(a.data[i]!=goal)
        {
            begin++;
            if(begin!=i) swap(a.data[begin],a.data[i]);
        }
    }
    a.length=begin+1;
}

//有序表

//有序表的二路归并
template<class T>
void merge_2_list(const sqlist<T>& a,const sqlist<T>& b,sqlist<T>& ans)
{
    int lena=a.length;
    int lenb=b.length;
    int ptra=0,ptrb=0;
    ans.recap(lena+lenb);
    while(ptra<lena&&ptrb<lenb)
    {
        if(a.data[ptra]<=b.data[ptrb])
        {
            ans.add(a.data[ptra]);
            ptra++;
        }
        else
        {
            ans.add(b.data[ptrb]);
            ptrb++;
        }
    }
    while(ptra<lena) {ans.add(a.data[ptra]);ptra++;}
    while(ptrb<lenb) {ans.add(b.data[ptrb]);ptrb++;}
}
int main()
{

    return 0;
}