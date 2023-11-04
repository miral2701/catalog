#include <iostream>
using namespace std;



class Digit {
private:
    int dig; //�����
public:
    Digit() {
        dig = 0;
    }
    Digit(int iDig) {
        dig = iDig;
    }
    void Show() {
        cout << dig << "\n";
    }
    //����������� ������ ���������
    //�������� ��������, ��� ��������� 
    //��������, ������� �� �������� �
    //��� ���� �������� - ��� �������,
    //������� ����� ���������� ������
    //�� ��������� � ��������� 
    //����� ������� ���������� � ������� this
    Digit operator+(const Digit& N)
    {
        Digit temp;
        temp.dig = this->dig + N.dig;
        return temp;
    }
    Digit operator-(const Digit& N)
    {
        Digit temp;
        temp.dig = dig - N.dig;
        return temp;
    }
    Digit operator*(const Digit& N)
    {
        Digit temp;
        temp.dig = dig * N.dig;
        return temp;
    }
    Digit operator+=(const Digit& N)
    {
        dig += N.dig;
        return *this;
    }
    Digit operator++()
    {
        dig++;
        return *this;
    }
};
//� ����� �����(Fraction) �������� ���������� ���������* (��������� ������) ��� �������� : int* Fraction.
//����������� ��������� << � >> ��� ������ �� ����� � ����� � ���������� �������� ���� Fraction.
class Fraction {
    int a;
    int b;

public:
    Fraction(int a1, int b1) {
        a = a1;
        b = b1;
    }
    void Set_A(int x) {
        a = x;
   }
    void Set_B(int x) {
        b = x;
    }
    int Get_A() {
        return a;;
    }
    int Get_B() {
        return b;;
    }
    void Output() {
        cout << a << "/" << b;
    }
    friend istream& operator>>(istream& is, Fraction& P);
    friend ostream& operator<<(ostream& os, const Fraction& P);
   
};
Fraction& operator*(int d,Fraction& A) {
    Fraction B(1, 1);
    B.Set_A(d * A.Get_A());
    B.Set_B(A.Get_B());
    return B;
}

istream& operator>>(istream& is, Fraction& p) {
    cout << "set a\t";
    is >> p.a;
    cout << "set b\t";
    is >> p.b;
    return is;
}

ostream& operator<<(ostream& os, const Fraction& p) // point ������ �������� ��� ������
{
    os << "a = " << p.a << '\t';
    os << "b = " << p.b << '\n';
    return os;
}
void main()
{
    //��������� ������ ���������� 
   /* Digit A(8), B(3);
    Digit C;
    cout << "\Digit A:\n";
    A.Show();
    cout << "\Digit B:\n";
    B.Show();
    cout << "\noperator+:\n";
    C = A + B;
    C.Show();*/
    /*cout << "\noperator-:\n";
    C = A - B;
    C.Show();
    cout << "\noperator*:\n";
    C = A * B;
    C.Show();*/

   /* ++B;
    B.Show();*/
    
    Fraction a(1, 2);
    Fraction b = 3*a;
    b.Output();



}